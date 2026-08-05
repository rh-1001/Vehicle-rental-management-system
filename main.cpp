#include <QCoreApplication>
#include <QTextStream>
#include "vehiclemanager.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream in(stdin);
    QTextStream out(stdout);

    VehicleManager manager;

    int choice;

    do
    {
        out << "\n========== Vehicle Rental Management System ==========\n";
        out << "1. Add Vehicle\n";
        out << "2. Remove Vehicle\n";
        out << "3. Search Vehicle\n";
        out << "4. Rent Vehicle\n";
        out << "5. Return Vehicle\n";
        out << "6. Display Vehicle\n";
        out << "7. Display Summary\n";
        out << "8. Save to File\n";
        out << "9. Load from File\n";
        out << "0. Exit\n";

        out << "\nEnter your choice: ";
        out.flush();
        in >> choice;

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

        case 0:
            out << "Exiting...\n";
            break;

        default:
            out << "Invalid choice!\n";
        }

    } while(choice != 0);

    return 0;
}