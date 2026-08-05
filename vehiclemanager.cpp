#include <QTextStream>
#include <QFile>
#include "vehiclemanager.h"
#include "vehicle.h"

// Input and output streams
QTextStream in(stdin);
QTextStream out(stdout);

//Constructor
VehicleManager::VehicleManager() {}

//Implementing addVehicle function
void VehicleManager::addVehicle(){

    QString vehicleType, vehicleID, vehicleModel, vehicleBrand;
    double vehiclePrice;

    out << "Enter Vehicle type: ( 'Car'or 'Motorcycle'): \n";
    out.flush();
    in >> vehicleType;


    if (vehicleType == "Car"){

            out << "Enter Vehicle ID:\n";
            out.flush();
            in >> vehicleID;

            out << "Enter Vehicle Model C-:\n";
            out.flush();
            in >> vehicleModel;

            out << " Enter Vehicle Brand:\n";
            out.flush();
            in >> vehicleBrand;

            out << "Enter Price Per Day R :\n";
            out.flush();
            in >> vehiclePrice;

            Cars.append(Vehicle(vehicleID,vehicleModel,vehicleBrand, vehiclePrice));

    }else if( vehicleType =="Motorcycle"){

            out << "Enter Vehicle:\n";
            out.flush();
            in >> vehicleID;

            out << "Enter Vehicle Model C-:\n";
            out.flush();
            in >> vehicleModel;

            out << " Enter Vehicle Brand:\n";
            out.flush();
            in >> vehicleBrand;

            out << "Enter Price Per Day R :\n";
            out.flush();
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
        out.flush();
        in >> vehicleType;

        if (vehicleType == "Car"){

            out << "Enter ID of vehicle you want to remove C-:\n";
            out.flush();
            in >> searchID;

            for(int i =0 ;i < Cars.size(); i++){
                if( searchID == Cars[i].getId()){
                    Cars.remove(i);

                    out << "Vehicle removed successfully!";
                    out.flush();
                    return;
                }
            }
            out << "No match was found!";
            out.flush();
        }
        else if (vehicleType == "Motorcycle"){

            out << "Enter ID of vehicle you want to remove C-:\n";
            out.flush();
            in >> searchID;

            for(int i = 0; i < Motorcycles.size(); i++){
                if(searchID == Motorcycles[i].getId()){

                    Motorcycles.remove(i);

                    out << "Vehicle removed successfully!";
                    out.flush();
                    return;
                }
            }

            out << "No match was found!";
            out.flush();
        }
        else{

            out << "Invalid vehicle type!";
            out.flush();
        }}

//Implementation of search vehicle functionality
    void VehicleManager::searchVehicle(){

        QString vehicleType, searchID;

        out << "Enter Vehicle type: ('Car' or 'Motorcycle'): \n";
        out.flush();
        in >> vehicleType;

        if (vehicleType == "Car"){

            out << "Enter Vehicle ID:\n";
            out.flush();
            in >> searchID;

            for(int i = 0; i < Cars.size(); i++){
                if(searchID == Cars[i].getId()){

                    out << "Vehicle Found!\n";
                    out.flush();
                    return;
                }
            }

            out << "Vehicle Not Found!\n";
            out.flush();
        }
        else if (vehicleType == "Motorcycle"){

            out << "Enter Vehicle ID:\n";
            out.flush();
            in >> searchID;

            for(int i = 0; i < Motorcycles.size(); i++){
                if(searchID == Motorcycles[i].getId()){

                    out << "Vehicle Found!\n";
                    out.flush();
                    return;
                }
            }

            out << "Vehicle Not Found!\n";
            out.flush();
        }
        else{

            out << "Invalid vehicle type!\n";
            out.flush();
        }
    }

//Implementing rent vehicle functionality
void VehicleManager::rentVehicle(){

    QString vehicleType, searchID;

    out << "Enter Vehicle type: ( 'Car'or 'Motorcycle'): \n";
    out.flush();
    in >> vehicleType;

    if (vehicleType == "Car"){

        out << "Enter Vehicle ID:\n";
        out.flush();
        in >> searchID;

        for(int i =0 ;i < Cars.size(); i++){
            if(searchID == Cars[i].getId()){

                // Changing rental status of car
                Cars[i].setIsRented(true);
                if(Cars[i].getRented()){
                    out <<" Vehicle has been rented!\n";
                    out.flush();
                }

                //Adding the rented to the rented vehicle vector
                RentedCars.append(Cars[i]);

                //Removing rented from available cars
                Cars.remove(i);
                return;

            }
        }
        out << " Vehicle not found!\n";
        out.flush();
    }
    else if (vehicleType == "Motorcycle"){

        out << "Enter Vehicle ID:\n";
        out.flush();
        in >> searchID;

        for(int i =0 ;i < Motorcycles.size(); i++){
            if(searchID == Motorcycles[i].getId()){

                // Changing rental status of car
                Motorcycles[i].setIsRented(true);
                if(Motorcycles[i].getRented()){
                    out <<" Vehicle has been rented!\n";
                    out.flush();
                }

                //Adding the rented to the rented vehicle vector
                RentedMotorcycles.append(Motorcycles[i]);

                //Removing vehicles
                Motorcycles.remove(i);
                return;
            }
        }
            out << " Vehicle not found!\n";
            out.flush();
    }
    else{out << "Invalid Input!\n";
        out.flush();
    }
}
//Implementaion of return vehicle functionality
void VehicleManager::returnVehicle(){

    QString vehicleType, searchID;

    out << "Enter Vehicle type: ( 'Car'or 'Motorcycle'): \n";
    out.flush();
    in >> vehicleType;

    if (vehicleType == "Car"){

        out << "Enter Vehicle ID:\n";
        out.flush();
        in >> searchID;

        for(int i =0 ;i < RentedCars.size(); i++){
            if(searchID == RentedCars[i].getId()){

                // Changing rental status of car
                RentedCars[i].setIsRented(false);
                    out <<" Vehicle has been returned!\n";
                    out.flush();

                //Adding the rented to the cars vehicle vector
                Cars.append(RentedCars[i]);

                //Removing rented from available cars
                RentedCars.remove(i);
                return;

            }
        }
        out << "Vehicle not found!\n";
        out.flush();
    }
    else if (vehicleType == "Motorcycle"){

        out << "Enter Vehicle ID:\n";
        out.flush();
        in >> searchID;

        for(int i =0 ;i < RentedMotorcycles.size(); i++){
            if(searchID == RentedMotorcycles[i].getId()){

                // Changing rental status of car
                RentedMotorcycles[i].setIsRented(false);
                out <<" Vehicle has been returned!\n";
                out.flush();


                //Adding the rented to the rented vehicle vector
                Motorcycles.append(RentedMotorcycles[i]);

                //Removing vehicles
                RentedMotorcycles.remove(i);
                return;
            }
        }
        out << "Vehicle not found!\n";
        out.flush();
    }else{
        out << "Invalid Input!\n";
        out.flush();
    }
}
//Implementation of displayVehicle functionality
void VehicleManager::displayVehicle(){

    QString vehicleType, searchID;

    out << "Enter Vehicle type: ( 'Car'or 'Motorcycle'): \n";
    out.flush();
    in >> vehicleType;

    if (vehicleType == "Car"){

        out << "Enter Vehicle ID:\n";
        out.flush();
        in >> searchID;

        for(int i =0 ;i < Cars.size(); i++){
            if(searchID == Cars[i].getId()){

                out << "Vehicle ID: " << Cars[i].getId() << "\n";
                out.flush();
                out << "Model: " << Cars[i].getModel() << "\n";
                out.flush();
                out << "Brand: " << Cars[i].getBrand() << "\n";
                out.flush();
                out << "Price Per Day: R" << Cars[i].getPricePerDay() << "\n";
                out.flush();
                if (Cars[i].getRented() == true) {
                    out << "Yes\n";
                    out.flush();
                }
                else if (Cars[i].getRented() == false) {
                    out << "No\n";
                    out.flush();
                }
                return;
                }
            }  out << "Vehicle not found!\n";
                out.flush();

    } else if (vehicleType == "Motorcycle"){

        out << "Enter Vehicle ID:\n";
        out.flush();
        in >> searchID;

        for(int i =0 ;i < Motorcycles.size(); i++){
            if(searchID == Motorcycles[i].getId()){

                out << "Vehicle ID: " << Motorcycles[i].getId() << "\n";
                out.flush();
                out << "Model: " << Motorcycles[i].getModel() << "\n";
                out.flush();
                out << "Brand: " << Motorcycles[i].getBrand() << "\n";
                out.flush();
                out << "Price Per Day: R" << Motorcycles[i].getPricePerDay() << "\n";
                out.flush();
                if (Motorcycles[i].getRented() == true) {
                    out << "Yes\n";
                }
                else if (Motorcycles[i].getRented() == false) {
                    out << "No\n";
                    out.flush();
                }
                return;
            }
}
        out << "Vehicle not found!/n";
        out.flush();
        }
    else{
        out << "Invalid output!";
        out.flush();}
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
        out.flush();
    }

    //Implementing save to file functionality
    void VehicleManager::saveToFile(){

        QFile file("storage");

        QTextStream saveFile(&file);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            out << "Could not open file!\n";
            return;
        }

        for(int i = 0; i < Motorcycles.size(); i++){

            saveFile << "Motorcycles\n";
            saveFile << Motorcycles[i].getId() << "\n";
            saveFile << Motorcycles[i].getModel() << "\n";
            saveFile << Motorcycles[i].getBrand() << "\n";
            saveFile << Motorcycles[i].getPricePerDay() << "\n";
            saveFile << Motorcycles[i].getRented() << "\n";
        }
        for(int i = 0; i < Cars.size(); i++){

            saveFile << "Cars\n";
            saveFile << Cars[i].getId() << "\n";
            saveFile << Cars[i].getModel() << "\n";
            saveFile << Cars[i].getBrand() << "\n";
            saveFile << Cars[i].getPricePerDay() << "\n";
            saveFile << Cars[i].getRented() << "\n";
        }
        file.close();

        out << "Data saved successfully!\n";
    }

    //Implementing load file functionality
    void VehicleManager::loadFromFile()
    {
        QFile file("storage");

        if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            out << "Could not open file!\n";
            return;
        }

        QTextStream loadFromFile(&file);
       ;

        QString vehicleType;
        QString vehicleID;
        QString vehicleModel;
        QString vehicleBrand;
        double vehiclePrice;
        int isRented;

        //Functionality that clears vectors before loading

        Cars.clear();
        Motorcycles.clear();
        RentedCars.clear();
        RentedMotorcycles.clear();

        while(!loadFromFile.atEnd()){

            loadFromFile >> vehicleType;
            loadFromFile >> vehicleID;
            loadFromFile >> vehicleModel;
            loadFromFile >> vehicleBrand;
            loadFromFile >> vehiclePrice;
            loadFromFile >> isRented;

            if(vehicleType == "Cars"){

                Vehicle vehicle(vehicleID,
                                vehicleModel,
                                vehicleBrand,
                                vehiclePrice);

                vehicle.setIsRented(isRented);
                if (isRented == 1)

                {
                    RentedCars.append(vehicle);
                }
                else
                {
                    Cars.append(vehicle);
                }
            }
            else if(vehicleType == "Motorcyles"){

                Vehicle vehicle(vehicleID,
                                vehicleModel,
                                vehicleBrand,
                                vehiclePrice);

                vehicle.setIsRented(isRented);
                if (isRented == 1)
                {
                    RentedMotorcycles.append(vehicle);

                }
                else
                {
                    Motorcycles.append(vehicle);
                }
            }
        }

        file.close();

        out << "Vehicles loaded successfully!\n";
    }

