#pragma once
#ifndef _FEMALE_H_
#define _FEMALE_H_
#include"Person.h"

using namespace std;

class Female: public Person  // Inheritance
{
private:
    float fatMass; // Encapsulation
public:
    Female();
    Female(string name, int height, float weight, MembershipType membershipType, float fatMass, int age);
    void setFatMass(float fatMass);
    float getFatMass();
    friend ostream& operator << (ostream& os, Female& female)
    {
        os << "Name: " << female.getName() << " ";
        os << "Age: " << female.getAge() << " ";
        os << "Weight (kg): " << female.getWeight() << " ";
        os << "Height (CM): " << female.getHeight() << " ";
        os << "BMI: " << female.getBMI() << " ";
        os << "Muscle Mass: " << female.getFatMass() << " ";
        os << "Membership Type: " << (female.getMembershipType() == normal ? "normal" : "premium") << "\n";
        return os;
    }
};
#include "Female.cpp"
#endif // Female_H
