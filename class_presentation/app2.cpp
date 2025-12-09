#include <iostream>
using namespace std;

#define pi 3.14159

class Circle {
  public:
    void setRadius(double user_radius);
    double getCircumference();
    double getArea();

  private:
    double radius;
};

void Circle::setRadius(double user_radius) { radius = user_radius; }
double Circle::getCircumference() { return 2 * pi * radius; }
double Circle::getArea() { return pi * radius * radius; }

int main() {
    double radius = 5.2;
    Circle circle;
    circle.setRadius(radius);
    cout << "Circle Area: " << circle.getArea() << endl;
    cout << "Circle Circumference: " << circle.getCircumference() << endl;
    return 0;
}
