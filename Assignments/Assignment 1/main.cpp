// BITF22M017
// Inam Ul Haq
// Assignment 1

#include <iostream>
#include <string>
#include "car.h" // see car header file

using namespace std;

int main()
{

    int choice;
    car learningcar; // object of car class being used

do{ // simple loop so that menu keeps on re-appearing

    cout << endl;
    cout << "Welcome to Car Driving tutorial." << endl;
    cout << "You will learn all car basics here." << endl;
    cout << "You have 5 options:" << endl;
    cout << endl;
    cout << "1. Guide to Gears." << endl;
    cout << "2. How to speed up?" << endl;
    cout << "3. How to reverse?" << endl;
    cout << "4. Road Driving Ethics." << endl;
    cout << "5. Guide to maintain car efficiency." << endl;
    cout << "6. Take a virtual simulation" << endl;
    cout << "0. Exit the entire program." << endl;
    cout << endl; // simple

    cout << "Enter your choice: ";
    cin >> choice;

    while (choice < 0 || choice >6)
    {
        cout << "Invalid! Enter your choice again: ";
        cin >> choice;
    }

    switch (choice)

    {
        /* all functions are of car.h 
        but actually are of vehicle.h which is used in car.h */
    case 1:
        learningcar.GearsGuide();
        break;
    case 2:
        learningcar.SpeedUp();
        break;
    case 3:
        learningcar.Break();
        break;
    case 4:
        learningcar.RoadEthics();
        break;
    case 5:
        learningcar.CarEfficiency();
        break;
    case 6:
    // all variables from vehicle.h are also printed at end
        learningcar.virtualSimulation();
        break;
    }
}
while(choice != 0);
    return 0;
}

// did at end moment. so this is it. else anything new would have been a mere change of words simply
// e.g. add this, that, make some else simple function
// Assignment 1 ended.
// Thank you so much for checking.
