// ========================================
// Fire Fighter Robot - النسخة المظبوطة
// ========================================

// ===== Motor Pins (L298N) =====
#define in1 9 // Motor Right - Forward
#define in2 8 // Motor Right - Backward
#define in3 7 // Motor Left - Forward
#define in4 6 // Motor Left - Backward
// ملحوظة: enA و enB موصولين بـ 5V مباشرة (أو فيهم jumpers)

// ===== Fire Sensors (Flame Sensors) =====
#define ir_R A0 // حساس النار - يمين
#define ir_F A1 // حساس النار - قدام
#define ir_L A2 // حساس النار - شمال

// ===== Smoke Sensor (MQ2) =====
#define MQ2 10 // حساس الدخان - ديجيتال Pin 10

// ===== Servo & Pump =====
#define servo 3 // سيرفو موتور (PWM Pin)
#define pump 5  // مضخة المياه (PWM Pin مع MOSFET)

// ===== Variables =====
int s1, s2, s3;    // قراءات حساسات النار
int smokeDetected; // قراءة حساس الدخان

// ===== Thresholds (عتبات الكشف) =====
const int FIRE_CLOSE_R = 250; // نار قريبة يمين
const int FIRE_CLOSE_F = 350; // نار قريبة قدام
const int FIRE_CLOSE_L = 250; // نار قريبة شمال
const int FIRE_FAR_R = 700;   // نار بعيدة يمين
const int FIRE_FAR_F = 800;   // نار بعيدة قدام
const int FIRE_FAR_L = 700;   // نار بعيدة شمال

// ========================================
// Setup Function
// ========================================
void setup() {
    Serial.begin(9600);
    Serial.println("Fire Fighter Robot Starting...");

    // Motor Pins
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

    // Sensor Pins
    pinMode(ir_R, INPUT);
    pinMode(ir_F, INPUT);
    pinMode(ir_L, INPUT);
    pinMode(MQ2, INPUT);

    // Servo & Pump Pins
    pinMode(servo, OUTPUT);
    pinMode(pump, OUTPUT);

    digitalWrite(pump, LOW); // تأكد إن المضخة مطفية

    // Servo Startup Sweep (معايرة السيرفو)
    Serial.println("Calibrating Servo...");
    for (int angle = 90; angle <= 140; angle += 5) {
        servoPulse(servo, angle);
    }
    for (int angle = 140; angle >= 40; angle -= 5) {
        servoPulse(servo, angle);
    }
    for (int angle = 40; angle <= 90; angle += 5) {
        servoPulse(servo, angle);
    }

    Serial.println("Ready!");
    delay(1000);
}

// ========================================
// Main Loop
// ========================================
void loop() {
    // قراءة الحساسات
    s1 = analogRead(ir_R);            // يمين
    s2 = analogRead(ir_F);            // قدام
    s3 = analogRead(ir_L);            // شمال
    smokeDetected = digitalRead(MQ2); // دخان

    // طباعة القيم للـ Serial Monitor
    Serial.print("R:");
    Serial.print(s1);
    Serial.print("\tF:");
    Serial.print(s2);
    Serial.print("\tL:");
    Serial.print(s3);
    Serial.print("\tSmoke:");
    Serial.println(smokeDetected == LOW ? "YES" : "NO");

    // ========================================
    // Fire Detection Logic
    // ========================================

    // 🔥 حالة 1: نار قريبة على اليمين
    if (s1 < FIRE_CLOSE_R) {
        Serial.println(">>> FIRE DETECTED - RIGHT!");
        Stop();
        extinguishRight();
    }

    // 🔥 حالة 2: نار قريبة قدام
    else if (s2 < FIRE_CLOSE_F) {
        Serial.println(">>> FIRE DETECTED - FRONT!");
        Stop();
        extinguishFront();
    }

    // 🔥 حالة 3: نار قريبة على الشمال
    else if (s3 < FIRE_CLOSE_L) {
        Serial.println(">>> FIRE DETECTED - LEFT!");
        Stop();
        extinguishLeft();
    }

    // 🔍 حالة 4: نار بعيدة على اليمين - اتجه ناحيتها
    else if (s1 >= FIRE_CLOSE_R && s1 <= FIRE_FAR_R) {
        Serial.println("Fire far - RIGHT, adjusting...");
        digitalWrite(pump, LOW);
        backward();
        delay(100);
        turnRight();
        delay(200);
    }

    // 🔍 حالة 5: نار بعيدة قدام - امشي ناحيتها
    else if (s2 >= FIRE_CLOSE_F && s2 <= FIRE_FAR_F) {
        Serial.println("Fire far - FRONT, moving forward...");
        digitalWrite(pump, LOW);
        forward();
    }

    // 🔍 حالة 6: نار بعيدة على الشمال - اتجه ناحيتها
    else if (s3 >= FIRE_CLOSE_L && s3 <= FIRE_FAR_L) {
        Serial.println("Fire far - LEFT, adjusting...");
        digitalWrite(pump, LOW);
        backward();
        delay(100);
        turnLeft();
        delay(200);
    }

    // 💨 حالة 7: دخان بس بدون نار
    else if (smokeDetected == LOW) {
        Serial.println("Smoke detected! Searching for fire...");
        digitalWrite(pump, LOW);
        searchPattern();
    }

    // ✅ حالة 8: مفيش نار ولا دخان
    else {
        digitalWrite(pump, LOW);
        Stop();
    }

    delay(50); // Small delay for stability
}

// ========================================
// Fire Extinguishing Functions
// ========================================

// إطفاء النار على اليمين
void extinguishRight() {
    digitalWrite(pump, HIGH); // تشغيل المضخة

    // تحريك السيرفو يمين (90° → 40°)
    for (int angle = 90; angle >= 40; angle -= 3) {
        servoPulse(servo, angle);
        delay(20);
    }

    // رجوع للوسط (40° → 90°)
    for (int angle = 40; angle <= 90; angle += 3) {
        servoPulse(servo, angle);
        delay(20);
    }

    delay(500);
    digitalWrite(pump, LOW); // إطفاء المضخة
}

// إطفاء النار قدام
void extinguishFront() {
    digitalWrite(pump, HIGH);

    // مسح كامل يمين وشمال
    // يمين (90° → 140°)
    for (int angle = 90; angle <= 140; angle += 3) {
        servoPulse(servo, angle);
        delay(20);
    }

    // شمال (140° → 40°)
    for (int angle = 140; angle >= 40; angle -= 3) {
        servoPulse(servo, angle);
        delay(20);
    }

    // رجوع للوسط (40° → 90°)
    for (int angle = 40; angle <= 90; angle += 3) {
        servoPulse(servo, angle);
        delay(20);
    }

    delay(500);
    digitalWrite(pump, LOW);
}

// إطفاء النار على الشمال
void extinguishLeft() {
    digitalWrite(pump, HIGH);

    // تحريك السيرفو شمال (90° → 140°)
    for (int angle = 90; angle <= 140; angle += 3) {
        servoPulse(servo, angle);
        delay(20);
    }

    // رجوع للوسط (140° → 90°)
    for (int angle = 140; angle >= 90; angle -= 3) {
        servoPulse(servo, angle);
        delay(20);
    }

    delay(500);
    digitalWrite(pump, LOW);
}

// ========================================
// Search Pattern (لما يكون فيه دخان بس)
// ========================================
void searchPattern() {
    // دوران بطيء للبحث عن مصدر النار
    turnRight();
    delay(300);
    Stop();
    delay(200);

    turnLeft();
    delay(300);
    Stop();
    delay(200);
}

// ========================================
// Servo Control Function
// ========================================
void servoPulse(int pin, int angle) {
    // تحويل الزاوية لـ microseconds
    int pwm = (angle * 11) + 500;

    // إرسال نبضة PWM
    digitalWrite(pin, HIGH);
    delayMicroseconds(pwm);
    digitalWrite(pin, LOW);
    delay(20); // Refresh cycle
}

// ========================================
// Movement Functions
// ========================================

void forward() {
    digitalWrite(in1, HIGH); // Right motor forward
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW); // Left motor forward
    digitalWrite(in4, HIGH);
}

void backward() {
    digitalWrite(in1, LOW); // Right motor backward
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH); // Left motor backward
    digitalWrite(in4, LOW);
}

void turnRight() {
    digitalWrite(in1, LOW); // Right motor backward
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW); // Left motor forward
    digitalWrite(in4, HIGH);
}

void turnLeft() {
    digitalWrite(in1, HIGH); // Right motor forward
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH); // Left motor backward
    digitalWrite(in4, LOW);
}

void Stop() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}

// ========================================
// End of Code
// ========================================
