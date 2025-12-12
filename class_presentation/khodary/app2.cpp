#include <iostream>
using namespace std;

class Employee {
  public:
    struct Department {
        string name;
        string id;
        string address;
    };

    void set_department(string n, string i, string a) {
        department.name = n;
        department.id = i;
        department.address = a;
    }
    void set_employee(string n, string i, double s) {
        name = n;
        id = i;
        salary = s;
    }
    void print_employee() {
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << id << endl;
        cout << "Salary: " << salary << endl;
        cout << "Department: " << department.name << endl;
        cout << "Department ID: " << department.id << endl;
        cout << "Department Address: " << department.address << endl;
    }

  private:
    string name;
    string id;
    double salary;
    Department department;
};

int main() {
    Employee e;
    e.set_department("Math", "MT1", "Suez Canal University");
    e.set_employee("Khodary", "240120123", 2000.75);
    e.print_employee();
    return 0;
}
