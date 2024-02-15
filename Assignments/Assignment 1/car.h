#include <iostream>
#include <string>
#include "vehicle.h"

using namespace std;

class car
{
private: // as per asked
    Vehicle vehicle; // see vehicle header file
    string companyName;
    int model;
    int maxSpeed;
    int currentSpeed;
    string carType;

public:

    car() // default constructor
    {
        companyName = "CarMaker";
        model = 0000;
        maxSpeed = 0000;
        currentSpeed = 0000;
        carType = "4-Legs";
    }


    car(string compName, int mdl, int maxSpd, int curSpd, string type) // parameterized
    {
        companyName = compName;
        model = mdl;
        maxSpeed = maxSpd;
        currentSpeed = curSpd;
        carType = type;
    }

    // getters
    string getManufacturerName() const
    {
        return companyName;
    }
    int getModel() const
    {
        return model;
    }
    int getMaxSpeed() const
    {
        return maxSpeed;
    }
    int getCurrentSpeed() const
    {
        return currentSpeed;
    }
    string getCarType() const
    {
        return carType;
    }

    // setters
    void setManufacturerName(string compName)
    {
        companyName = compName;
    }
    void setModel(int mdl)
    {
        model = mdl;
    }
    void setMaxSpeed(int maxSpd)
    {
        maxSpeed = maxSpd;
    }
    void setCurrentSpeed(int curSpd)
    {
        currentSpeed = curSpd;
    }
    void setCarType(string type)
    {
        carType = type;
    }

    // functions to use in main
    // functions used are of vehicle.h to show composition as learned
    // tried as simple as can to show
    void GearsGuide()
    {
        vehicle.GearsGuide();
    }
    void SpeedUp()
    {
        vehicle.SpeedUp();
    }
    void Break()
    {
        vehicle.Break();
    }
    void RoadEthics()
    {
        vehicle.RoadEthics();
    }
    void CarEfficiency()
    {
        vehicle.CarEfficiency();
    }

    // main one
    void virtualSimulation()
    {
        vehicle.virtualSimulation();
        // cout << "Enter Manufacturer name from where you bought the car (character input kindly): ";
        // getline(cin, companyName);
        cout << "Enter model number of the car you have (enter integer input): ";
        cin >> model;
        cout << "Enter max speed your car can have: ";
        cin >> maxSpeed;
        cout << "Enter current speed your car has :";
        cin >> currentSpeed;
        cout << "Enter the car type (either family, conventional or racing): ";
        getline(cin, carType);
        cin.ignore();
        cout << endl;
        vehicle.displayInfo();
        cout << endl;
        displayInfo();
        cout << endl;
    }

    void displayInfo() const
    {
        // cout << "Your Manufacturer Name is: " << companyName << endl;
        cout << "Your Car's Model is: " << model << endl;
        cout << "Your Car's Max Speed is: " << maxSpeed << " km/h" << endl;
        cout << "Your Car's Current Speed is: " << currentSpeed << " km/h" << endl;
        cout << "Your Car Type is: " << carType << endl;
        
    }
};
