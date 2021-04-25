//
// Created by itai and tomer.
//

#include "Employee.h"



int Employee::amountOfEmployees;

Employee::Employee(){
    name = new char[5];
    char* temp = (char*)"Name";
    strcpy(name, temp);
    EID = 0;
    salary = 0;
    amountOfEmployees++;
}

Employee::Employee(char* c_name, int c_EID, double c_salary){
    if(!c_name || c_salary<0 || c_EID<0){
        return;
    }
    this->name = new char[strlen(c_name) + 1];
    if(!this->name){
        Employee();
    }
    else{
        strcpy(this->name, c_name);
        EID = c_EID;
        salary = c_salary;
    }
    amountOfEmployees++;
}

Employee::Employee(const Employee& other){
    if(!other.name || other.salary<0 || other.EID < 0){
        return;
    }
    this->name = new char[strlen(other.name) + 1];
    if(!this->name){
        Employee();
    }
    else {
        strcpy(this->name, other.name);
        this->EID = other.EID;
        this->salary = other.salary;
        amountOfEmployees++;
    }
}

int Employee::planOfficeParty(){
    return amountOfEmployees*10;
}

bool Employee::setName(char* name){
    if(!name){
        return false;
    }
    char* temp = new char[strlen(name)+1];
    if(!temp){
        return false;
    }
    strcpy(temp, name);
    delete[] this->name;
    this->name = temp;
    return true;
}

int Employee::getEID()
{
    return this->EID;
}

double Employee::getSalary()
{
    return this->salary;
}
bool Employee::operator==(const Employee& other)
{
    return (this->EID == other.EID);
}

bool Employee::operator>(const Employee &other)
{
    return (this->salary > other.salary);
}

Employee& Employee::operator=(const Employee &other) {
    setName(other.name);
    return *this;
}

Employee& Employee::operator+(const Employee &other) {
    this->salary = this->salary + other.salary;
    return *this;
}

Employee& Employee::operator++() {
    this->salary = this->salary + 100;
    return *this;
}

Employee Employee::operator++(int x) {
    Employee temp(*this);
    this->salary = this->salary + 100;
    return temp;
}

Employee& Employee::operator+=(const Employee &other) {
    char* temp = new char[strlen(other.name) + strlen(this->name) + 1];
    if(!temp){
        return *this; // if allocating memory failed, we don't change anything
    }
    int pos = 0;
    int currNameLength = strlen(this->name);
    int otherNameLength = strlen(other.name);
    for(int i = 0 ; i < currNameLength; i++) {
        temp[pos] = this->name[pos];
        pos++;
    }
    for(int i = 0 ; i < otherNameLength+1; i++){
        temp[pos] = other.name[i];
        pos++;
    }
    delete[] this->name;
    this->name = temp;
    return *this;
}

ostream& operator<<(ostream& out, const Employee& other){
    out<<"Name:"<<(other.name)<<"\n"<<"ID:"<<(other.EID)<<"\n"<<"Salary:"<<(other.salary)<<"\n"<<"\n";
    return out;
}

Employee::~Employee(){
    delete[] this->name;
    amountOfEmployees--;
}
