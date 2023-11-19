#pragma once
#include <string>
#include "Vehicle.h"

namespace Bike_ns { 

    class Bike : public Vehicle_ns::Vehicle{

        char type[32];
        bool availability;

        public:
            Bike(bool availability, string type);
            virtual ~Bike();
            virtual void ride() override;
            virtual void repair() override;
    };
}
