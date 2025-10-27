#include <iostream>
using namespace std;

int main()
{
  double count_positive = 0;
  double total_positive = 0;
  double count_negative = 0;
  double total_negative = 0;
  double input_number;

  while (true)
  {
    cout << "Enter a number: ";
    cin >> input_number;

    if (input_number > 0)
    {
      count_positive += 1;
      total_positive += input_number;
    }
    else if (input_number < 0)
    {
      count_negative += 1;
      total_negative += input_number;
    }
    else
      break;
  }
  cout << endl;
  cout << "Total number of positive numbers is " << count_positive << endl;
  cout << "The sum of all positive numbers is " << total_positive << endl;
  cout << "Total number of negative is " << count_negative << endl;
  cout << "The sum of all negative numbers is " << total_negative << endl;

  return 0;
}
