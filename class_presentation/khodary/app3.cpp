#include <iostream>
using namespace std;

class Pet {
  private:
    string name;
    int age;
    string species;

  public:
    void set_info(string n, int a, string s) {
        name = n;
        age = a;
        species = s;
    }
    void print_info() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << " Years Old." << endl;
        cout << "Species: " << species << endl;
    }
};

int main() {
    Pet p;
    p.set_info("BosBos", 3, "Cat");
    p.print_info();
    return 0;
}
