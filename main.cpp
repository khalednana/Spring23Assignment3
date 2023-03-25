#include <iostream>
#include "Customer.hpp"
#include "Mechanic.hpp"
#include "Queue_t.hpp"
using namespace std;
template<typename T>
void mySwap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}
void initializeMechanics(Mechanic* mechanics, int n)
{
    string name, id;
    int age;
    for (int i = 0;i < n;i++)
    {
        
        cout << "For mechanic #" << (i + 1) << ":\n";
        cout << "enter name: " << endl;
        cin >> name;
        cout << "enter age: " << endl;
        cin >> age;
        cout << "enter id: " << endl;
        cin >> id;
        mechanics[i] = Mechanic(name, id, age);
    }
}
void initializeCustomers(Customer* customers, int n)
{
    string name, id;
    int age;
    Appointment app;
    for (int i = 0;i < n;i++)
    {

        cout << "For customer #" << (i + 1) << ":\n";
        cout << "enter name: " << endl;
        cin >> name;
        cout << "enter age: " << endl;
        cin >> age;
        cout << "enter id: " << endl;
        cin >> id;
        cout << "enter appointment hour: " << endl;
        cin >> app.hour;
        cout << "enter appointment minute: " << endl;
        cin >> app.minute;
        customers[i] = Customer(name, id, age, app);
    }
}
void assignCustomersToMechanics(Customer* customers, int n_cust, Mechanic* mechanics, int n_mech)
{
    int current_mechanic = 0;
    int failed_attempts = 0;
    for (int i = 0;i < n_cust;i++)
    {
        if (mechanics[current_mechanic].isAvaiableAt(customers[i].getAppointment()))
        {
            mechanics[current_mechanic].makeAppointment(customers[i].getAppointment());
            customers[i].setMechanicID(mechanics[current_mechanic].getId());
            failed_attempts = 0;
        }
        else
        {
            failed_attempts++;
            if (failed_attempts < n_mech)
                i--;
        }
        current_mechanic = (current_mechanic + 1) % n_mech;
    }
}
string findMechanicNameById(Mechanic* mechanics, int n_mech, string id)
{
    for (int i = 0;i < n_mech;i++)
        if (mechanics[i].getId() == id)
            return mechanics[i].getName();
    return "not found";
}
void displayCustomers(Queue_t<Customer>& q, Mechanic* mechanics, int n_mech)
{
    Customer current;
    while (!q.isEmpty())
    {
        q.dequeue(current);
        if (current.getMechanicID() == "")
            cout << current.getName() << " does not have an appointment with anyone at " << current.getAppointment().toString() << endl;
        else {
            string name = findMechanicNameById(mechanics, n_mech, current.getMechanicID());
            cout << current.getName() << " has an appointment with " << name << " at " << current.getAppointment().toString() << endl;
        }
    }
}
void displayCustomersQueue(Customer* customers, int n_cust, Mechanic* mechanics, int n_mech)
{
    Queue_t<Customer> q(n_cust);
    for(int i=0;i<n_cust-1;i++)
        for (int j = i+1;j < n_cust;j++)
        {
            if (customers[j] < customers[i])
                mySwap(customers[j], customers[i]);
        }
    for (int i = 0;i < n_cust;i++)
        q.enqueue(customers[i]);
    displayCustomers(q, mechanics, n_mech);

}


int main() {

    Mechanic* mechanics;
    int n_mech;
    cout << "enter the number of mechanics" << endl;
    cin >> n_mech;
    mechanics = new Mechanic[n_mech];
    initializeMechanics(mechanics, n_mech);
    Customer* customers;
    int n_cust;
    cout << "enter the number of customers" << endl;
    cin >> n_cust;
    customers = new Customer[n_cust];
    initializeCustomers(customers, n_cust);
    assignCustomersToMechanics(customers, n_cust, mechanics, n_mech);
    displayCustomersQueue(customers,n_cust, mechanics, n_mech);
    
    return 0;
}
