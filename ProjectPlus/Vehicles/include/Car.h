#pragma once
#include <string>
#include "Vehicle.h"

using namespace std;

namespace Car_ns { 

    class Car : public Vehicle_ns::Vehicle { 

        int manufacturingYear;
        char brand[32];
        char *details;
        bool availability;

        public:
            Car(int manufacturingYear, string brand, string details, bool availability);
            ~Car();
            Car(const Car &prevCar);
            Car(Car &&prevCar);
            void display();
            void changeDetails(string newDetails);
            Car& operator=(const Car& otherCar);
            Car& operator=(Car &&otherCar);
            virtual void ride() override;
            virtual void repair() override;
            virtual void refill();
    };
}