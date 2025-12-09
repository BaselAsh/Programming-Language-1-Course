#include <iostream>
using namespace std;

class Car {
  public:
    struct EngineDetails {
        int cylinders;
        double displacement;
        double horsepower;
    };
    struct CarDetails {
        string brand;
        string model;
        int year;
        EngineDetails engine;
    };
    void setCarDetails(string user_brand, string user_model, int year);
    void setCarEngine(int user_cylinders, double user_displacement,
                      double user_horsepower);
    void displayCarDetails();

  private:
    EngineDetails engine;
    CarDetails details;
};

void Car::setCarEngine(int user_cylinders, double user_displacement,
                       double user_horsepower) {
    details.engine.cylinders = user_cylinders;
    details.engine.horsepower = user_horsepower;
    details.engine.displacement = user_displacement;
}

void Car::setCarDetails(string user_brand, string user_model, int user_year) {
    details.brand = user_brand;
    details.model = user_model;
    details.year = user_year;
    details.engine = engine;
}

void Car::displayCarDetails() {
    cout << "Model: " << details.model << endl;
    cout << "Brand: " << details.brand << endl;
    cout << "Release Date: " << details.year << endl;
    cout << "Engine Details" << endl;
    cout << "Cylinders: " << details.engine.cylinders << endl;
    cout << "Horsepower: " << details.engine.horsepower << endl;
    cout << "Displacement: " << details.engine.displacement << endl;
}

int main() {
    int cylinders = 4;
    double displacement = 1600;
    double horsepower = 120;
    string brand = "MG";
    string model = "ZS";
    int year = 2021;

    Car car;
    car.setCarDetails(brand, model, year);
    car.setCarEngine(cylinders, displacement, horsepower);
    car.displayCarDetails();

    return 0;
}
