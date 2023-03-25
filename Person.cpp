
#include "Person.hpp"


Person::Person()
{
    this->age = 0;
    this->name = "";
    this->id = "";
}

Person::Person(string name, string id, int age)
{
    setName(name);
    setId(id);
    setAge(age);
}

Person::~Person()
{
}

string Person::getName()
{
    return name;
}

string Person::getId()
{
    return id;
}

int Person::getAge()
{
    return age;
}



void Person::setName(string name)
{
    this->name = name;
}

void Person::setId(string id)
{
    this->id = id;
}

void Person::setAge(int age)
{
    this->age = age;
}

void Person::printInfo()
{
    cout << "person{name: " << name << ", id: " << id << ", age: " << age << "}\n";
}
