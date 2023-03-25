#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

struct Appointment
{
    int hour;
    int minute;
    Appointment()
    {
        hour = -1;
        minute = -1;
    }
    Appointment(int h, int m)
    {
        hour = h % 24;
        minute = m % 60;
    }
    bool operator==(const Appointment& other)
    {
        return ((hour == other.hour) && (minute == other.minute));
    }
    bool operator<(const Appointment& other)
    {
        return ((hour < other.hour) || ((hour == other.hour) && minute < other.minute));
    }
    bool operator>(const Appointment& other)
    {
        return ((hour > other.hour) || ((hour == other.hour) && minute > other.minute));
    }
    bool operator>=(const Appointment& other)
    {
        return ((*this>other) || (*this==other));
    }
    bool operator<=(const Appointment& other)
    {
        return ((*this < other) || (*this == other));
    }
    bool operator!=(const Appointment& other)
    {
        return !(*this == other);
    }
    string toString() {
        string result = "";
        if (hour < 10)
            result += "0" + to_string(hour);
        else
            result += to_string(hour);
        result += ":";
        if (minute < 10)
            result += "0" + to_string(minute);
        else
            result += to_string(minute);
        return result;
    }

};


class Person
{
public:
    Person();
    Person(string name,    string id, int age);
    ~Person();
    string getName();
    string getId();
    int getAge();
    void setName(string name);
    void setId(string id);
    void setAge(int age);
    void printInfo();

private:
    string name;
    string id;
    int age;

};



#endif /* Person_hpp */
