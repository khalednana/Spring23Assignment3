#ifndef Customer_hpp
#define Customer_hpp

#include <stdio.h>

#include "Person.hpp"

class Customer: public Person
{
public:
    Customer();
    Customer(string name, string id, int age);
    Customer(string name, string id, int age, string mechanicID);
    Customer(string name, string id, int age, Appointment appointment);
    Customer(string name, string id, int age, string mechanicID, Appointment appointment);
    ~Customer();
    Appointment getAppointment();
    string getMechanicID();
    void setAppointment(Appointment appointment);
    void setAppointment(int hour, int minute);
    void setMechanicID(string mechanicID);
    bool operator==(const Customer& other);
    bool operator<(const Customer& other);
    bool operator>(const Customer& other);
    bool operator>=(const Customer& other);
    bool operator<=(const Customer& other);
    bool operator!=(const Customer& other);

private:
    string mechanicID;
    Appointment appointment;

};



#endif /* Customer_hpp */
