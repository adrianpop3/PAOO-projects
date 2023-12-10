#pragma once
#include <string>
#include "Vehicle.h"

using namespace std;

namespace Car_ns { 

    class Car : public Vehicle_ns::Vehicle { 

        static int noOfThreads;
        static string parkingSpots[16];

        int manufacturingYear;
        char numberPlate[32];
        char *details;
        bool parked;

        public:
            Car(int manufacturingYear, string numberPlate, string details, bool parked);
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
            void parkCar();
            static void showParkingSpots();

        private:
            static void* markSpot(void*);
    };
}