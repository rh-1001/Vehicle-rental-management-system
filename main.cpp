#include <QCoreApplication>
#include <QTextStream>
#include "vehiclemanager.h"

//Input and output streams

QTextStream in(stdin);
QTextStream out(stdout);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    VehicleManager manager;

    int choice;

    do
    {
        // Menu

        switch(choice)
        {
        case 1:
            manager.addVehicle();
            break;

        case 2:
            manager.removeVehicle();
            break;

        case 3:
            manager.searchVehicle();
            break;

        case 4:
            manager.rentVehicle();
            break;

        case 5:
            manager.returnVehicle();
            break;

        case 6:
            manager.displayVehicle();
            break;

        case 7:
            manager.displaySummary();
            break;

        case 8:
            manager.saveToFile();
            break;

        case 9:
            manager.loadFromFile();
            break;

        case 10:
            out << "Exit!\n";
            break;

        default:
            out << "Invalid choice!\n";
            break;
        }

    } while(choice != 10);

}