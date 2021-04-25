//
// Created by itai and tomer.
//

#ifndef ASSIGNMENT4_DATABASE_H
#define ASSIGNMENT4_DATABASE_H

#include "Employee.h"
#include <stdlib.h>

class DataBase{
private:
    int numOfEmployees;
    Employee** employees;
    int sizeOfArray;
public:
    DataBase();
    DataBase(const DataBase& other);
    Employee* getEmployee(int EID);
    bool addEmployee(Employee* other);
    bool removeEmployee(int EID);
    void print();
    ~DataBase();
};


#endif //ASSIGNMENT4_DATABASE_H
