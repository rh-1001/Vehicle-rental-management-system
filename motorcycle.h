#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include <QString>
#include "vehicle.h"

class Motorcycle:public Vehicle
{
private:
    int engineCapacityCC;

public:
    Motorcycle(QString newID,QString newModel,QString newBrand,double newPricePerDay, int newEngineCapacityCC);

    //Setter and Getter for engine capacity function

    int getEngineCapacityCC();
    void setEngineCapacityCC(int newValue);
};

#endif // MOTORCYCLE_H
