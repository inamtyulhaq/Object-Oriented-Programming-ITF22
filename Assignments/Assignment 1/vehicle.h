// first and most basic
#include <iostream>
#include <string>

using namespace std;

class Vehicle
{

private: // as per asked
    int ID;
    int noOfTyres;
    int noOfDoors;
    string color;
    string fuel;

public:
    Vehicle() // default constructor
    {
        ID = 0000;
        noOfTyres = 00;
        noOfDoors = 00;
        color = "NoColor";
        fuel = "NoFuel";
    }

    Vehicle(int id, int tyres, int doors, string clr, string fuel) // parameterized constructor
    {
        ID = id;
        noOfTyres = tyres;
        noOfDoors = doors;
        color = clr;
        fuel = fuel;
    }

    // getters
    int getID() const
    {
        return ID;
    }
    int getNoOfTyres() const
    {
        return noOfTyres;
    }
    int getNoOfDoors() const
    {
        return noOfDoors;
    }
    string getColor() const
    {
        return color;
    }
    string getFuel() const
    {
        return fuel;
    }

    // setters
    void setID(int id)
    {
        ID = id;
    }
    void setNoOfTyres(int tyres)
    {
        noOfTyres = tyres;
    }
    void setNoOfDoors(int doors)
    {
        noOfDoors = doors;
    }
    void setColor(string clr)
    {
        color = clr;
    }
    void setFuel(string fuel)
    {
        fuel = fuel;
    }

    void GearsGuide() // will be simply used in car.h
    {
        cout << endl;
        cout << "Welcome to the world of gears." << endl;
        cout << "1st Gear is used to provide initial speed." << endl;
        cout << "2nd Gear is used to drive car at a normal speed on a normal country side road." << endl;
        cout << "3rd Gear is used to speed up car on highways." << endl;
        cout << "4th Gear is used to keep driving car at a high speed on big roads." << endl;
        cout << "Reverse Gear is used to reverse the car back. Be careful while using it." << endl;
    }

    void SpeedUp() // all as simple
    {
        cout << endl;
        cout << "Welcome to the world of speeding up cars." << endl;
        cout << "It's simple. Press your feet on speed and put on gears using clutch." << endl;
        cout << "Keep on increasing speed while advancing gears" << endl;
    }

    void Break()
    {
        cout << endl;
        cout << "Simply put one feet on clutch and another on break." << endl;
        cout << "Don't press all at once. Keep pressing it gently else car will start skitting." << endl;
    }

    void RoadEthics() // last minute creativity
    {
        cout << endl;
        cout << "Don't use phones while driving" << endl;
        cout << "Give space to ambulances" << endl;
        cout << "Drive in your own lane" << endl;
        cout << "Try not to create noise and light pollution" << endl;
        cout << "Drive slowly and safely" << endl;
        cout << "Remember, it's better to reach late than never" << endl;
    }

    void CarEfficiency()
    {
        cout << endl;
        cout << "Use high octane fuel" << endl;
        cout << "Regularly service your vehicle" << endl;
        cout << "Clean all indoor car components" << endl;
        cout << "Cover all car components with a sheet or some cover" << endl;
        cout << "Avoid bumpy roads" << endl;
    }

    void virtualSimulation() // see car.h
    {
        cout << "Enter the car's color (character input kindly): ";
        cin.ignore();
        getline(cin, color);
        // no idea of input validation

        cout << "Enter the type of fuel (either petrol or diesel): ";
        getline(cin, fuel);
        // no idea of input validation

        cout << "Every car has a vehicle ID. Enter ID (btw 1 and 1000): ";
        cin >> ID;
        while (ID < 1 || ID > 1000)
        {
            cout << "Invalid. Enter again: ";
            cin >> ID;
        }

        cout << "Enter the number of tyres (btw 4 and 12): ";
        cin >> noOfTyres;
        while (noOfTyres < 4 || noOfTyres >> 12)
        {
            cout << "Invalid. Enter again: ";
            cin >> noOfTyres;
        }

        cout << "Enter the number of doors (btw 4 and 12): ";
        cin >> noOfDoors;
        while (noOfDoors < 4 || noOfDoors >> 12)
        {
            cout << "Invalid. Enter again: ";
            cin >> ID;
        }

        
    }

    void displayInfo() const
    {
        cout << "Vehicle ID is a lot helpful. In your case, it is: " << ID << endl;
        cout << "Number of Tyres you entered are: " << noOfTyres << endl;
        cout << "Number of Doors your vehicle have: " << noOfDoors << endl;
        cout << "Your entered car color is: " << color << endl;
        cout << "Your type of fuel is: " << fuel << endl;
    }
};
