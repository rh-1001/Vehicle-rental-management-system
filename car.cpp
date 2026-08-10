#include "car.h"

Car::Car(QString newID, QString newModel,QString newBrand,double newPricePerDay, int newNumberOfDoors)
    :Vehicle(newID, newModel,newBrand, newPricePerDay){

    numberOfDoors = newNumberOfDoors;
}

//Implementation of Setter and Getter function for number of doors
int Car:: getNumberOfDoors(){

    return numberOfDoors;
}

void Car:: setNumberOfDoors( int newNumberOfDoorsValue){

    numberOfDoors = newNumberOfDoorsValue;
}
void Car::displayInfo() const
{
    Vehicle::displayInfo();

    QTextStream out(stdout);
    out << "Number of doors: "
        << numberOfDoors
        << "\n";
}
QString Car::typeName() const
{
    return "Car";
}

