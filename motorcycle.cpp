#include "motorcycle.h"

Motorcycle::Motorcycle(QString newID,QString newModel,QString newBrand,double newPricePerDay, int newEngineCapacityCC)
    :Vehicle(newID, newModel, newBrand, newPricePerDay){

    engineCapacityCC = newEngineCapacityCC;
}

//Implementation of Setter and Getter functions for Engine Capacity

    // Return type name
    QString Motorcycle::typeName() const {
        return "Motorcycle";

}

    // Display info
    void Motorcycle::displayInfo() const {
        Vehicle::displayInfo();
        QTextStream out(stdout);
        out << "Engine capacity: " << engineCapacityCC << "CC";
}