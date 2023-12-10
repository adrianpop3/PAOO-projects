#include <iostream>
#include <cstring>
#include "DieselCar.h"

using namespace std;
using namespace DieselCar_ns;

DieselCar::DieselCar(int manufacturingYear, string brand, string details, bool availability)
    : Car(manufacturingYear, brand, details, availability) {
    cout<<endl<<"DieselCar created."<<endl;
}

DieselCar::~DieselCar() {
    cout<<endl<<"DieselCar destroyed."<<endl;
}

void DieselCar::refill() {
    cout<<endl<<"DieselCar is being refilled with diesel."<< endl;
}
