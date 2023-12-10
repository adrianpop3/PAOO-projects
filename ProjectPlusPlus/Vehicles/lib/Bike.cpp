#include <iostream>
#include <cstring>
#include "Bike.h"

using namespace std;
using namespace Bike_ns;

Bike::Bike(bool availability, string type) {
    this->availability = availability;
    strcpy(this->type, type.c_str());

    cout<<endl<<"Bike created."<< endl;
}

Bike::~Bike() {
    cout<<endl<<"Bike destroyed."<< endl;
}

void Bike::ride() {
    cout<<endl<<"Bike is being ridden."<<endl;
}

void Bike::repair() {
    cout<<endl<<"Bike is being repaired."<<endl;
}
