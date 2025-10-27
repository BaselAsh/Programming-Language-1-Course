#include <iostream>

using namespace std;

int main() {
  cout << "Enter the temperature (In Celsius): ";
  float temp_c;
  cin >> temp_c;

  float temp_f = (9.0 / 5) * temp_c + 32;

  cout << "The temperature is " << temp_f << " Fahrenheit.\n";

  return 0;
}
