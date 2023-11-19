add_library(Vehicles STATIC lib/Car.cpp lib/Bike.cpp lib/PetrolCar.cpp lib/DieselCar.cpp)

target_include_directories(Vehicles PUBLIC "include")