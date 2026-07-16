#ifndef CAR_H
#define CAR_H
#include <QString>
#include "vehicle.h"

class Car: public Vehicle
{
    private:
        int numberOfDoors;

    public:
        Car(QString newID,QString newModel,QString newBrand,double newPricePerDay, int numberOfDoors);

    //Setter and getter for the function number of doors

         int getNumberOfDoors();
         void setNumberOfDoors( int newValue);

};

#endif // CAR_H
