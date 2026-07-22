#include <QTextStream>
#include <QFile>
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
    double vehiclePrice;

    out << "Enter Vehicle type: ( 'Car'or 'Motorcycle'): \n";
    in >> vehicleType;


    if (vehicleType == "Car"){

            out << "Enter Vehicle ID:\n";
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

        out << "Invalid input! ";
    }

}

//Implementation of remove vehicle functionality
void VehicleManager::removeVehicle(){

        QString vehicleType, searchID;

        out << "Enter Vehicle type: ( 'Car'or 'Motorcycle'): \n";
        in >> vehicleType;

        if (vehicleType == "Car"){

            out << "Enter ID of vehicle you want to remove C-:\n";
            in >> searchID;

            for(int i =0 ;i < Cars.size(); i++){
                if( searchID == Cars[i].getId()){
                    Cars.remove(i);

                    out << "Vehicle removed successfully!";
                    return;
                }
            }
            out << "No match was found!";
        }
        else if (vehicleType == "Motorcycle"){

            out << "Enter ID of vehicle you want to remove C-:\n";
            in >> searchID;

            for(int i = 0; i < Motorcycles.size(); i++){
                if(searchID == Motorcycles[i].getId()){

                    Motorcycles.remove(i);

                    out << "Vehicle removed successfully!";
                    return;
                }
            }

            out << "No match was found!";
        }
        else{

            out << "Invalid vehicle type!";
        }}

//Implementation of search vehicle functionality
    void VehicleManager::searchVehicle(){

        QString vehicleType, searchID;

        out << "Enter Vehicle type: ('Car' or 'Motorcycle'): \n";
        in >> vehicleType;

        if (vehicleType == "Car"){

            out << "Enter Vehicle ID:\n";
            in >> searchID;

            for(int i = 0; i < Cars.size(); i++){
                if(searchID == Cars[i].getId()){

                    out << "Vehicle Found!\n";
                    return;
                }
            }

            out << "Vehicle Not Found!\n";
        }
        else if (vehicleType == "Motorcycle"){

            out << "Enter Vehicle ID:\n";
            in >> searchID;

            for(int i = 0; i < Motorcycles.size(); i++){
                if(searchID == Motorcycles[i].getId()){

                    out << "Vehicle Found!\n";
                    return;
                }
            }

            out << "Vehicle Not Found!\n";
        }
        else{

            out << "Invalid vehicle type!\n";
        }
    }

//Implementing rent vehicle functionality
void VehicleManager::rentVehicle(){

    QString vehicleType, searchID;

    out << "Enter Vehicle type: ( 'Car'or 'Motorcycle'): \n";
    in >> vehicleType;

    if (vehicleType == "Car"){

        out << "Enter Vehicle ID:\n";
        in >> searchID;

        for(int i =0 ;i < Cars.size(); i++){
            if(searchID == Cars[i].getId()){

                // Changing rental status of car
                Cars[i].setIsRented(true);
                if(Cars[i].getRented()){
                    out <<" Vehicle has been rented!\n";
                }

                //Adding the rented to the rented vehicle vector
                RentedCars.append(Cars[i]);

                //Removing rented from available cars
                Cars.remove(i);
                return;

            }
        }
        out << " Vehicle not found!\n";
    }
    else if (vehicleType == "Motorcycle"){

        out << "Enter Vehicle ID:\n";
        in >> searchID;

        for(int i =0 ;i < Motorcycles.size(); i++){
            if(searchID == Motorcycles[i].getId()){

                // Changing rental status of car
                Motorcycles[i].setIsRented(true);
                if(Motorcycles[i].getRented()){
                    out <<" Vehicle has been rented!\n";
                }

                //Adding the rented to the rented vehicle vector
                RentedMotorcycles.append(Motorcycles[i]);

                //Removing vehicles
                Motorcycles.remove(i);
                return;
            }
        }
            out << " Vehicle not found!\n";
    }
    else{out << "Invalid Input!\n";
    }
}
//Implementaion of return vehicle functionality
void VehicleManager::returnVehicle(){

    QString vehicleType, searchID;

    out << "Enter Vehicle type: ( 'Car'or 'Motorcycle'): \n";
    in >> vehicleType;

    if (vehicleType == "Car"){

        out << "Enter Vehicle ID:\n";
        in >> searchID;

        for(int i =0 ;i < RentedCars.size(); i++){
            if(searchID == RentedCars[i].getId()){

                // Changing rental status of car
                RentedCars[i].setIsRented(false);
                    out <<" Vehicle has been returned!\n";

                //Adding the rented to the cars vehicle vector
                Cars.append(RentedCars[i]);

                //Removing rented from available cars
                RentedCars.remove(i);
                return;

            }
        }
        out << "Vehicle not found!\n";
    }
    else if (vehicleType == "Motorcycle"){

        out << "Enter Vehicle ID:\n";
        in >> searchID;

        for(int i =0 ;i < RentedMotorcycles.size(); i++){
            if(searchID == RentedMotorcycles[i].getId()){

                // Changing rental status of car
                RentedMotorcycles[i].setIsRented(false);
                out <<" Vehicle has been returned!\n";


                //Adding the rented to the rented vehicle vector
                Motorcycles.append(RentedMotorcycles[i]);

                //Removing vehicles
                RentedMotorcycles.remove(i);
                return;
            }
        }
        out << "Vehicle not found!\n";
    }else{
        out << "Invalid Input!\n";
    }
}
//Implementation of displayVehicle functionality
void VehicleManager::displayVehicle(){

    QString vehicleType, searchID;

    out << "Enter Vehicle type: ( 'Car'or 'Motorcycle'): \n";
    in >> vehicleType;

    if (vehicleType == "Car"){

        out << "Enter Vehicle ID:\n";
        in >> searchID;

        for(int i =0 ;i < Cars.size(); i++){
            if(searchID == Cars[i].getId()){

                out << "Vehicle ID: " << Cars[i].getId() << "\n";
                out << "Model: " << Cars[i].getModel() << "\n";
                out << "Brand: " << Cars[i].getBrand() << "\n";
                out << "Price Per Day: R" << Cars[i].getPricePerDay() << "\n";
                if (Cars[i].getRented() == true) {
                    out << "Yes\n";
                }
                else if (Cars[i].getRented() == false) {
                    out << "No\n";
                }
                return;
                }
            }  out << "Vehicle not found!\n";

    } else if (vehicleType == "Motorcycle"){

        out << "Enter Vehicle ID:\n";
        in >> searchID;

        for(int i =0 ;i < Motorcycles.size(); i++){
            if(searchID == Motorcycles[i].getId()){

                out << "Vehicle ID: " << Motorcycles[i].getId() << "\n";
                out << "Model: " << Motorcycles[i].getModel() << "\n";
                out << "Brand: " << Motorcycles[i].getBrand() << "\n";
                out << "Price Per Day: R" << Motorcycles[i].getPricePerDay() << "\n";
                if (Motorcycles[i].getRented() == true) {
                    out << "Yes\n";
                }
                else if (Motorcycles[i].getRented() == false) {
                    out << "No\n";
                }
                return;
            }
}
        out << "Vehicle not found!/n";
        }
    else{
        out << "Invalid output!";}
    }


//Implementation of display summary functionality
    void VehicleManager::displaySummary(){

        out << "\n========== Vehicle Summary ==========\n";

        out << "Available Cars: "
            << Cars.size() << "\n";

        out << "Available Motorcycles: "
            << Motorcycles.size() << "\n";

        out << "Rented Cars: "
            << RentedCars.size() << "\n";

        out << "Rented Motorcycles: "
            << RentedMotorcycles.size() << "\n";

        out << "-------------------------------------\n";

        out << "Total Available Vehicles: "
            << Cars.size() + Motorcycles.size() << "\n";

        out << "Total Rented Vehicles: "
            << RentedCars.size() + RentedMotorcycles.size() << "\n";

        out << "Total Vehicles: "
            << Cars.size() + Motorcycles.size()
                   + RentedCars.size() + RentedMotorcycles.size()
            << "\n";

        out << "=====================================\n";
    }

    //Implementing save to file functionality
    void VehicleManager::saveToFile(){

        QFile file("storage.txt");

        QTextStream fileOut(&file);
    };

