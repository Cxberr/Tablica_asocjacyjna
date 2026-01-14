#ifndef Employee_H
#define Employee_H
#include <iostream>
#include <string>
class Employee {

    public:
    std::string name;
    std::string position;
    unsigned int age;
    Employee() = default;
    Employee(const std::string &name, const std::string &position, unsigned int age) {
        this->name = name;
        this->position = position;
        this->age = age;

    }

    friend std::ostream& operator<<(std::ostream& os, const Employee& employee) {
        os << employee.name << " " << employee.position << " " << employee.age;
        return os;
    }
};





#endif