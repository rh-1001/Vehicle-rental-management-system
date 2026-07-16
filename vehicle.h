#ifndef VEHICLE_H
#define VEHICLE_H
#include <QString>

class Vehicle
{

private:

    QString id;
    QString model;
    QString brand;
    double pricePerDay;
    bool isRented;

public:

    Vehicle(QString newID,QString newModel,QString newBrand,double newPricePerDay, bool Rented = false);

    //Setter and Getter functions for ID
    QString getId();
    void setId(QString newID);

    //Setter and Getter functions for Model
    QString getModel();
    void setModel(QString newModel);

    //Setter and Getter functions for Brand
    QString getBrand();
    void setBrand(QString newBrand);

    //Setter and Getter functions for Price per day
    double getPricePerDay();
    void setPricePerDay(double newPricePerDay);

    //Setter and Getter functions for vehicle rental
    bool getRented();
    void setIsRented(bool Status);

};

#endif // VEHICLE_H
