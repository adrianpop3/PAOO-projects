#include <iostream>
#include <string>
#include "Car.h"

using namespace std;

int main(int argc, char* argv[]) { 
    
    Car bmw(2016, "BMW", "- details for BMW car -", true);
    Car alfaRomeo(2018, "AlfaRomeo", "- details for AlfaRomeo car -", false);
    Car volvo(2020, "Volvo", "- details for Volvo car -", true);

    bmw.display();
    alfaRomeo.display();
    volvo.display();

    Car bmwCopy = bmw;
    bmwCopy.display();
    bmw.display();
    bmwCopy.changeDetails("- new Details -");
    bmwCopy.display();
    bmw.display();
    
    Car volvoMoved(std::move(volvo));
    volvo.display();
    volvoMoved.display();
    volvoMoved.changeDetails("- new Details -");
    volvoMoved.display();
    volvo.display();

    return 0;
}