#include"Male.h"

using namespace std;

Male::Male(): Person() // Polymorphism -> Male class calls the constructor of Person class
{
    this->muscleMass = 0;
}
Male::Male(string name, int height, float weight, MembershipType membershipType, float muscleMass, int age):
    Person(age,name,height,weight, membershipType) // Polymorphism -> Male class calls the constructor of Person class
{
    this->muscleMass = muscleMass;
}

void Male::setMuscleMass(float muscleMass) // Abstraction muscleMass variable can only be changed through this function
{
    if(muscleMass <= 0)
    {
        cout << "Muscle mass can't be " << muscleMass << "\n";
        return;
    }
    this->muscleMass = muscleMass;
}
float Male::getMuscleMass() { return this->muscleMass; } // Abstraction muscleMass variable can only be reached through this function
