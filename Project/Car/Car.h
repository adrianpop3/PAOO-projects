#pragma once
#include <string>

using namespace std;

class Car { 

    bool availability;
    int manufacturingYear;
    char brand[32];
    char *details;

    public:
        Car(int manufacturingYear, string brand, string details, bool availability);
        ~Car();
        Car(const Car &prevCar);
        Car(Car &&prevCar);
        void display();
        void changeDetails(string newDetails);
};