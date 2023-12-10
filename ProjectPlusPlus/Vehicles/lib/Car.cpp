#include <iostream>
#include <cstring>
#include "Car.h"
#include <pthread.h>

using namespace std;
using namespace Car_ns;

std::mutex parkingSpotsMutex;
std::mutex noOfThreadsMutex;

string Car::parkingSpots[16];
int Car::noOfThreads;

Car::Car(int manufacturingYear, string numberPlate, string details, bool parked) {
    cout<<"I have been created."<<endl;

    this->parked = parked;
    this->manufacturingYear = manufacturingYear;
    strcpy(this->numberPlate, numberPlate.c_str());

    this->details = new char[details.size()+1];
    strcpy(this->details, details.c_str());
}

Car::~Car() {
    cout<<"I have been deleted."<<endl;

    delete[] this->details;
}

Car::Car(const Car &prevCar) {
    cout<<endl<<"I have been copied."<<endl;

    this->parked = prevCar.parked;
    this->manufacturingYear = prevCar.manufacturingYear;
    strcpy(this->numberPlate, prevCar.numberPlate);

    this->details = new char[strlen(prevCar.details)+1];
    strcpy(this->details, prevCar.details);
}

Car::Car(Car &&prevCar) {
    cout<<endl<<"I have been moved."<<endl;

    this->parked = prevCar.parked;
    this->manufacturingYear = prevCar.manufacturingYear;
    strcpy(this->numberPlate, prevCar.numberPlate);

    this->details = prevCar.details;
    prevCar.details = NULL;
}

void Car::display() {
	if(this->details == NULL) {
		cout<<endl<<"Car has been deleted!"<<endl;
		return;
	}

	cout<<endl<<this->numberPlate<<endl<<"Manufacturing year: "<<this->manufacturingYear<<endl<<this->details<<endl<<endl;
}

void Car::changeDetails(string newDetails) {
    delete[] this->details;

	this->details = new char[newDetails.size()+1];
    strcpy(this->details, newDetails.c_str());
}

Car& Car::operator=(const Car &otherCar) {
    if (this != &otherCar) {
        cout<<endl<<"I have been deep-assigned"<<endl;

        this->parked = otherCar.parked;
        this->manufacturingYear = otherCar.manufacturingYear;
        strcpy(this->numberPlate, otherCar.numberPlate);

        delete[] this->details;
        this->details = new char[strlen(otherCar.details)+1];
        strcpy(this->details, otherCar.details);
    }

    return *this;
}

Car& Car::operator=(Car &&otherCar) {
    if (this != &otherCar) {
        cout<<endl<<"I have been shallow-assigned."<<endl;

        this->parked = otherCar.parked;
        this->manufacturingYear = otherCar.manufacturingYear;
        strcpy(this->numberPlate, otherCar.numberPlate);

        delete[] this->details;
        this->details = otherCar.details;
        otherCar.details = NULL;
    }

    return *this;
}

void Car::ride() {
    cout<<endl<<"I am riding on the highway!"<<endl;
}

void Car::repair() {
    cout<<endl<<"I was repaired at the Car-Service."<<endl;
}

void Car::refill() {
    cout<<endl<<"I am being refilled!"<<endl;
}

void Car::parkCar() {
    pthread_t thrd;

    noOfThreadsMutex.lock();
    noOfThreads++;
    noOfThreadsMutex.unlock();

    pthread_create(&thrd, NULL, markSpot, this);

    this->parked = true;
}

void* Car::markSpot(void* arg) {
    Car* car = static_cast<Car*>(arg);
    parkingSpotsMutex.lock();

    for(int i=0; i<16; i++) {
        if(parkingSpots[i].empty()) { 
            parkingSpots[i] = car->numberPlate;
            break;
        }
    }

    parkingSpotsMutex.unlock();

    noOfThreadsMutex.lock();
    noOfThreads--;
    noOfThreadsMutex.unlock();

    return NULL;
}

void Car::showParkingSpots() {
    while(noOfThreads != 0);

    for(int i=0; i<16; i++) {
        cout<<" "<<parkingSpots[i]<<" ";
    }

    cout<<endl;
}
