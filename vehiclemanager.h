#ifndef VEHICLEMANAGER_H
#define VEHICLEMANAGER_H

#include <QString>
#include <QVector>
#include "vehicle.h"

class VehicleManager
{
    private:

    QVector<Vehicle>Cars;
    QVector<Vehicle>Motorcycles;
    QVector<Vehicle>RentedVehicles;

    public:

        VehicleManager();
        void addVehicle();
        void removeVehicle();
        void searchVehicle();
        void rentVehicle();
        void returnVehicle();
        void displayVehicle();
        void displaySummary();
        void loadFromFile();
        void saveToFile();

};

#endif // VEHICLEMANAGER_H
