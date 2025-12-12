#include <iostream>
using namespace std;

class Rectangle {
  public:
    void set_width_and_height(double w, double h) {
        width = w;
        height = h;
    }
    void print_size() { cout << "The area is " << width * height << endl; }

  private:
    double width;
    double height;
};

int main() {
    Rectangle rect;
    rect.set_width_and_height(12.5, 5.9);
    rect.print_size();
    return 0;
}
