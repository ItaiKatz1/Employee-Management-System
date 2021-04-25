//
// Created by itai and tomer.
//

#include "DataBase.h"
#include <iostream>
using namespace std;

DataBase::DataBase()
{
    numOfEmployees = 0;
    employees = new Employee*[3];
    sizeOfArray = 3;
}

DataBase::DataBase(const DataBase &other)
{
    if(other.numOfEmployees < 0 || other.sizeOfArray < 0)
        DataBase();
    else{
        employees = new Employee*[other.numOfEmployees];
        this->numOfEmployees = other.numOfEmployees;
        for(int i = 0; i < other.numOfEmployees; i++) {
            this->employees[i] = new Employee(*other.employees[i]);
        }
        this->sizeOfArray = other.sizeOfArray;
    }
}

Employee* DataBase::getEmployee(int c_EID)
{
    for(int i = 0; i < this->numOfEmployees; i++) {
        Employee temp ((char*) "Name", c_EID, 0); // we create a temporary object to compare both EIDS
        if (this->employees[i]->operator==(temp)){
            return this->employees[i];
        }
    }
    return NULL;
}

bool DataBase::addEmployee(Employee* other) {
    if(getEmployee(other->getEID()) != NULL){
        delete other;
        cout << "This employee is already in the database\n" << "\n"; //
        return false;
    }
    if(this->numOfEmployees == this->sizeOfArray){
        Employee** temp = new Employee*[this->sizeOfArray*2];
        for(int i = 0; i < this->numOfEmployees; i++){
            temp[i] = this->employees[i];
        }
        delete[] this->employees;
        this->employees = temp;
    }
    this->employees[numOfEmployees] = other;
    numOfEmployees++;
    return true;
}

bool DataBase::removeEmployee(int EID) {
    if (EID < 0) {
        cout << "illegal EID number\n";
        return false;
    }
    if(getEmployee(EID) == NULL){
        cout << "This employee isn't in the database\n" << "\n";
        return false;
    }
    for(int i = 0; i < numOfEmployees; i++){
        if(EID == this->employees[i]->getEID()){
            delete this->employees[i];
            for(int j = i+1; j<numOfEmployees; j++){
                this->employees[j-1] = this->employees[j];
            }
            numOfEmployees--;
            return true;
        }
    }
    return false;
}

void DataBase:: print()
{
    cout << "Employees database:" << "\n" << "\n";
    for(int i=0;i<numOfEmployees;i++){
        cout<<*employees[i];
    }
}

DataBase::~DataBase() {
    for(int i = 0; i < numOfEmployees; i++){
       delete this->employees[i];
    }
    delete[] this->employees;
}
