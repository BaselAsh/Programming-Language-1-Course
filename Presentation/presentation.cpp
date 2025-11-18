#include <iostream>
using namespace std;

int
main ()
{
  int arr[5], delete_num;
  for (int i = 0; i <= 5; i++)
    {
      cout << "Enter the number at index " << i << " : ";
      cin >> arr[i];
    }
  cout << "Enter the number you want to delete: ";
  cin >> delete_num;
  for (int i = 0; i <= 5; i++)
    {
      if (arr[i] == delete_num)
        continue;
      cout << arr[i] << endl;
    }
  return 0;
}
