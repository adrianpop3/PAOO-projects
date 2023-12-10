#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Car.h"
#include "PetrolCar.h"
#include "DieselCar.h"
#include "Bike.h"
#include <memory>

using namespace std;
using namespace Car_ns;
using namespace PetrolCar_ns;
using namespace DieselCar_ns;
using namespace Bike_ns;
using namespace Vehicle_ns;

int main(int argc, char* argv[]) {
    
    Car bmw(2016, "TM 30P AC", "- details for BMW car -", false);
    Car alfaRomeo(2018, "CS 04 DUT", "- details for AlfaRomeo car -", false);

    bmw.parkCar();
    alfaRomeo.parkCar();

    Car::showParkingSpots();

    std::shared_ptr <Car> sp1;
    std::weak_ptr <Car> wp1;
    std::weak_ptr <Car> wp2;
    std::shared_ptr <Car> sp3;

    {
        std::shared_ptr <Car> sp2;

        sp1 = make_shared <Car> (2016, "B 102 ABC", "- details for volvo car -", false);

        wp1 = sp1;
        sp2 =sp1;

        sp1->display();
        sp1.reset();

        sp2->display();

        sp3 = make_shared <Car> (2016, "CJ 77 WXY", "- details for volvo car -", false);
        wp2 = sp3;

        if(auto tempSharedPtr = wp2.lock()) {
            cout<<"Object found."<<endl;
            tempSharedPtr->display();
        }
        else {
            cout<<"The weak pointer to the object is not valid."<<endl;
        }
    }

    sp3->display();

    if(auto tempSharedPtr = wp1.lock()) {
        cout<<"Object found."<<endl;
        tempSharedPtr->display();
    }
    else {
        cout<<"The weak pointer to the object is not valid."<<endl;
    }

    return 0;
}