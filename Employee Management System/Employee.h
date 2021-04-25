//
// Created by itai and tomer.
//

#ifndef ASSIGNMENT4_EMPLOYEE_H
#define ASSIGNMENT4_EMPLOYEE_H

#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>

class Employee
{
private:
    char* name;
    int EID;
    double salary;
    static int amountOfEmployees;
public:
    Employee();
    Employee(char* c_name, int c_EID, double c_salary);
    ~Employee();
    Employee(const Employee& other);
    int planOfficeParty();
    bool setName(char* name);
    int getEID();
    double getSalary();
    bool operator==(const Employee& other);
    bool operator>(const Employee& other);
    Employee& operator=(const Employee& other);
    Employee& operator+(const Employee& other);
    Employee& operator++();
    Employee operator++(int x);
    Employee& operator+=(const Employee& other);
    friend ostream& operator<<(ostream& out, const Employee& other);
};





#endif //ASSIGNMENT4_EMPLOYEE_H
