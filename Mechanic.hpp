
#ifndef Mechanic_hpp
#define Mechanic_hpp

#include <stdio.h>
#include "Person.hpp"

class Mechanic: public Person
{
public:
    Mechanic();
    Mechanic(string name, string id, int age);
    ~Mechanic();
    int getCounter();
    void setCounter(int counter);
    bool isAvaiableAt(Appointment appointment);
    void makeAppointment(Appointment appointment);

private:
    void incrementCounter();
    int counter;
    Appointment appointments[48];
};


#endif /* Mechanic_hpp */
