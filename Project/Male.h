#pragma once
#ifndef _MALE_H_
#define _MALE_H_

#include"Person.h"

using namespace std;

class Male: public Person // Inheritance
{
private:
    float muscleMass; // Encapsulation
public:
    Male();
    Male(string name, int height, float weight, MembershipType membershipType, float muscleMass, int age);
    void setMuscleMass(float muscleMass);
    float getMuscleMass();
    friend ostream& operator << (ostream& os, Male& male)
    {
        os << "Name: " << male.getName() << " ";
        os << "Age: " << male.getAge() << " ";
        os << "Weight (kg): " << male.getWeight() << " ";
        os << "Height (CM): " << male.getHeight() << " ";
        os << "BMI: " << male.getBMI() << " ";
        os << "Muscle Mass: " << male.getMuscleMass() << " ";
        os << "Membership Type: " << (male.getMembershipType() == normal ? "normal" : "premium") << "\n";
        return os;
    }
};
#include "Male.cpp"
#endif // Male_H
