#include <QTextStream>
#include "vehiclemanager.h"
#include "vehicle.h"

using namespace std;

QTextStream in(stdin);
QTextStream out(stdout);

//Constructor
VehicleManager::VehicleManager() {}

//Implementing addVehicle function
void VehicleManager::addVehicle(){

    QString vehicleType, vehicleID, vehicleModel, vehicleBrand;
    int vehiclePrice;

    out << "Enter Vehicle type: ( 'Car'or 'Motorcycle'): \n";
    in >> vehicleType;


    if (vehicleType == "Car"){

            out << "Enter Vehicle:\n";
            in >> vehicleID;

            out << "Enter Vehicle Model C-:\n";
            in >> vehicleModel;

            out << " Enter Vehicle Brand:\n";
            in >> vehicleBrand;

            out << "Enter Price Per Day R :\n";
            in >> vehiclePrice;

            Cars.append(Vehicle(vehicleID,vehicleModel,vehicleBrand, vehiclePrice));

    }else if( vehicleType =="Motorcycle"){

            out << "Enter Vehicle:\n";
            in >> vehicleID;

            out << "Enter Vehicle Model C-:\n";
            in >> vehicleModel;

            out << " Enter Vehicle Brand:\n";
            in >> vehicleBrand;

            out << "Enter Price Per Day R :\n";
            in >> vehiclePrice;

        Motorcycles.append(Vehicle(vehicleID,vehicleModel,vehicleBrand, vehiclePrice));

    }else{

        out << " "
    }


}

