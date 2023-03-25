
#include "Customer.hpp"


Customer::Customer() :
    Person()
{
    this->appointment = Appointment();
    this->mechanicID = "";
}

Customer::Customer(string name, string id, int age) :
    Person(name, id, age)
{
    this->appointment = Appointment();
    this->mechanicID = "";
}

Customer::Customer(string name, string id, int age, string mechanicID) :
    Person(name, id, age)
{
    this->appointment = Appointment();
    this->mechanicID = mechanicID;
}
Customer::Customer(string name, string id, int age, Appointment appointment) :
    Person(name, id, age)
{
    this->appointment = appointment;
    this->mechanicID = "";
}
Customer::Customer(string name, string id, int age, string mechanicID, Appointment appointment) :
    Person(name, id, age)
{
    this->appointment = appointment;
    this->mechanicID = mechanicID;
}
Customer::~Customer()
{
}

Appointment Customer::getAppointment()
{
    return appointment;
}
void Customer::setAppointment(Appointment appointment)
{
    this->appointment = appointment;
}

void Customer::setAppointment(int hour, int minute)
{
    this->appointment = Appointment(hour, minute);
}

string Customer::getMechanicID()
{
    return mechanicID;
}

void Customer::setMechanicID(string mechanicID)
{
    this->mechanicID = mechanicID;
}

bool Customer::operator==(const Customer& other)
{
    return this->appointment == other.appointment;
}

bool Customer::operator<(const Customer& other)
{
    return this->appointment < other.appointment;
}

bool Customer::operator>(const Customer& other)
{
    return this->appointment > other.appointment;
}

bool Customer::operator>=(const Customer& other)
{
    return this->appointment >= other.appointment;
}

bool Customer::operator<=(const Customer& other)
{
    return this->appointment <= other.appointment;
}

bool Customer::operator!=(const Customer& other)
{
    return this->appointment != other.appointment;
}
