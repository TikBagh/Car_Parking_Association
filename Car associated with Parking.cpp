// Car associated with Parking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

class Parking;

class Car
{
    std::string license;
    Parking* parking;

    


public:
    Car(const std::string& plate) : license(plate), parking(nullptr) {}

    const std::string& getLicensePlate() const {
        return license;
    }

    void park(Parking& par);
    void leaveParking();

};

class Parking {

    Car* Car_is_parked;

public:
    Parking() : Car_is_parked(nullptr) {}

    void parking(Car& car)
    {
        if (Car_is_parked == nullptr)
        {
            Car_is_parked = &car;
            car.park(*this);
            std::cout << "Car with license  " << car.getLicensePlate() << " is parked." << std::endl;
        }
        else {
            std::cout << "Parking is already occupied." << std::endl;
        }
    }

    void Leave()
    {
        if (Car_is_parked != nullptr) {
            std::cout << "Car with license  " << Car_is_parked->getLicensePlate() << " left the parking." << std::endl;
            Car_is_parked->leaveParking();
            Car_is_parked = nullptr;
        }
        else {
            std::cout << "Parking is already empty." << std::endl;
        }
    }
};

void Car::park(Parking& par) {
    parking = &par;
}

void Car::leaveParking() {
    parking = nullptr;
}



int main()
{
    Car car1("Lic1");
    Car car2("Lic2");

    Parking parkin;

    parkin.parking(car1);
    parkin.parking(car2);

    car1.leaveParking();
    parkin.Leave();

    return 0;
    
}

