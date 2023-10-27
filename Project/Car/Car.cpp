#include <iostream>
#include <cstring>
#include "Car.h"

using namespace std;

Car::Car(int manufacturingYear, string brand, string details, bool availability) {
    cout<<"I have been created."<<endl;

    this->availability = availability;
    this->manufacturingYear = manufacturingYear;
    strcpy(this->brand, brand.c_str());

    this->details = new char[details.size()+1];
    strcpy(this->details, details.c_str());
}

Car::~Car() {
    cout<<"I have been deleted."<<endl;

    delete[] this->details;
}

Car::Car(const Car &prevCar) {
    cout<<endl<<"I have been copied."<<endl;

    this->availability = prevCar.availability;
    this->manufacturingYear = prevCar.manufacturingYear;
    strcpy(this->brand, prevCar.brand);

    this->details = new char[strlen(prevCar.details)+1];
    strcpy(this->details, prevCar.details);
}

Car::Car(Car &&prevCar) {
    cout<<endl<<"I have been moved."<<endl;

    this->availability = prevCar.availability;
    this->manufacturingYear = prevCar.manufacturingYear;
    strcpy(this->brand, prevCar.brand);

    this->details = prevCar.details;
    prevCar.details = NULL;
}

void Car::display() {
	if(this->details == NULL) {
		cout<<endl<<"Car has been deleted!"<<endl;
		return;
	}

	cout<<endl<<this->brand<<endl<<"Manufacturing year: "<<this->manufacturingYear<<endl<<this->details<<endl<<endl;
}

void Car::changeDetails(string newDetails) {
    delete[] this->details;

	this->details = new char[newDetails.size()+1];
    strcpy(this->details, newDetails.c_str());
}