#pragma once
#include <string>

using namespace std;

namespace Vehicle_ns { 
    
    class Vehicle { 
        
        public:
            virtual void ride()=0;
            virtual void repair()=0;    
    };
}