
#include "Mechanic.hpp"


Mechanic::Mechanic():
    Person()
{
    counter = 0;
}

Mechanic::Mechanic(string name, string id, int age) :
    Person(name, id, age)
{
    counter = 0;
}

Mechanic::~Mechanic()
{
}

int Mechanic::getCounter()
{
    return counter;
}

void Mechanic::setCounter(int counter)
{
    this->counter = counter;
}

void Mechanic::incrementCounter()
{
    counter++;
}

bool Mechanic::isAvaiableAt(Appointment appointment)
{
    
    int index = appointment.hour * 2 + appointment.minute / 30;
    return this->appointments[index].hour == -1;
        
}

void Mechanic::makeAppointment(Appointment appointment)
{
    int index = appointment.hour * 2 + appointment.minute / 30;
    this->appointments[index] = appointment;
    incrementCounter();
}

