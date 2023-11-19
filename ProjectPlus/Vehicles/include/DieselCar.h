#pragma once
#include <string>
#include "Car.h"

namespace DieselCar_ns { 

    class DieselCar : public Car_ns::Car {

        public:
            DieselCar(int manufacturingYear, string brand, string details, bool availability);
            virtual ~DieselCar();
            void refill();
    };
}
