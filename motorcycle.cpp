#include "motorcycle.h"

Motorcycle::Motorcycle(QString newID,QString newModel,QString newBrand,double newPricePerDay, int newEngineCapacityCC)
    :Vehicle(newID, newModel, newBrand, newPricePerDay){

    engineCapacityCC = newEngineCapacityCC;
}

//Implementation of Setter and Getter functions for Engine Capacity
int Motorcycle::getEngineCapacityCC(){

    return engineCapacityCC;
}

void Motorcycle::setEngineCapacityCC(int newEngineCapacityValue){

    engineCapacityCC =newEngineCapacityValue;
}