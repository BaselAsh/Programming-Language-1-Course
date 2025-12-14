#include <iostream>
using namespace std;

class Student {
  public:
    void setName(string name);
    string getName();
    void setID(string id);
    string getID();

  private:
    string name;
    string id;
};
void Student::setName(string user_name) { name = user_name; }
string Student::getName() { return name; }
void Student::setID(string user_id) { id = user_id; }
string Student::getID() { return id; }

int main() {
    Student s;
    s.setName("Basel Ashraf");
    s.setID("240100100");
    cout << "Name: " << s.getName() << endl;
    cout << "ID: " << s.getID() << endl;
    return 0;
}
