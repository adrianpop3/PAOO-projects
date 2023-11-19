#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Car.h"
#include "PetrolCar.h"
#include "DieselCar.h"
#include "Bike.h"

using namespace std;
using namespace Car_ns;
using namespace PetrolCar_ns;
using namespace DieselCar_ns;
using namespace Bike_ns;
using namespace Vehicle_ns;

int main(int argc, char* argv[]) { 
    
    // Car bmw(2016, "BMW", "- details for BMW car -", true);
    // Car alfaRomeo(2018, "AlfaRomeo", "- details for AlfaRomeo car -", false);
    // Car volvo(2020, "Volvo", "- details for Volvo car -", true);

    // bmw.display();
    // alfaRomeo.display();
    // volvo.display();

    // Car bmwCopy = bmw;
    // bmwCopy.display();
    // bmw.display();
    // bmwCopy.changeDetails("- new Details -");
    // bmwCopy.display();
    // bmw.display();
    
    // Car volvoMoved(std::move(volvo));
    // volvo.display();
    // volvoMoved.display();
    // volvoMoved.changeDetails("- new Details -");
    // volvoMoved.display();
    // volvo.display();

    Car car1(2022, "Brand1", "Details1", true);
    Car car2(2020, "Brand2", "Details2", false);
    car1.display();
    car2.display();
    car1 = car2;
    car1.display();
    car2.display();

    Car car3(2022, "Brand3", "Details3", true);
    Car car4(2020, "Brand4", "Details4", false);
    car3.display();
    car4.display();
    car3 = std::move(car4);
    car3.display();
    car4.display();

    Bike bike(true, "Mountain Bike");
    bike.ride();
    bike.repair();

    Car* myPetrolCar = new PetrolCar(2022, "Toyota", "Sedan", true);
    DieselCar myDieselCar(2021, "Ford", "SUV", false);

    myPetrolCar->ride();
    myPetrolCar->repair();
    myPetrolCar->refill();

    myDieselCar.ride();
    myDieselCar.repair();
    myDieselCar.refill();

    return 0;
}