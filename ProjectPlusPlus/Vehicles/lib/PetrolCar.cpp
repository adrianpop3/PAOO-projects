#include <iostream>
#include <cstring>
#include "PetrolCar.h"

using namespace std;
using namespace PetrolCar_ns;

PetrolCar::PetrolCar(int manufacturingYear, string brand, string details, bool availability)
    : Car(manufacturingYear, brand, details, availability) {
    cout<<endl<<"PetrolCar created."<<endl;
}

PetrolCar::~PetrolCar() {
    cout<<endl<<"PetrolCar destroyed."<<endl;
}

void PetrolCar::refill() {
    cout<<endl<<"PetrolCar is being refilled with gasoline."<<endl;
}
