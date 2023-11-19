#pragma once
#include <string>
#include "Car.h"

namespace PetrolCar_ns { 

    class PetrolCar : public Car_ns::Car {

        public:
            PetrolCar(int manufacturingYear, string brand, string details, bool availability);
            virtual ~PetrolCar();
            void refill();
    };
}
