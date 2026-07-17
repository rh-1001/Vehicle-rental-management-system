#include "vehicle.h"

//Constructor initializing class
Vehicle::Vehicle(QString newID,QString newModel,QString newBrand,double newPricePerDay, bool Rented) {

    id = newID;
    model = newModel;
    brand = newBrand;
    pricePerDay = newPricePerDay;
    isRented = Rented;
}

// Implementation of Setter and Getter functions for ID
QString Vehicle::getId(){

    return id;
}

void Vehicle::setId(QString newIdValue){

    id = newIdValue;
}

//Implementation of Setter and Getter functions for Model
QString Vehicle::getModel(){

    return model;
}

void Vehicle::setModel(QString newModelValue){

    model = newModelValue;
}

//Implementation of Setter and Getter functions for Brand
QString Vehicle::getBrand(){

    return brand;
}

void Vehicle::setBrand(QString newBrandValue){

    brand = newBrandValue;
}

//Implementation of Setter and Getter functions for Price per day
double Vehicle::getPricePerDay(){

    return pricePerDay;
}

void Vehicle::setPricePerDay(double newPricePerDayValue){

    pricePerDay = newPricePerDayValue;
}

//Implementation of Setter and Getter functions for vehicle rental status
bool Vehicle::getRented(){

    return isRented;
}
void Vehicle::setIsRented(bool newStatus){

    isRented = newStatus;

}