#include"Female.h"

using namespace std;

Female::Female(): Person() { this->fatMass = 0; } // Polymorphism -> Female class calls the constructor of Person class
Female::Female(string name, int height, float weight, MembershipType membershipType, float fatMass, int age):
    Person(age, name, height, weight, membershipType) // Polymorphism -> Female class calls the constructor of Person class
{
    this->fatMass = fatMass;
}
void Female::setFatMass(float fatMass) // Abstraction Female user's fatMass can only be changed through this function
{
    if(fatMass <= 0)
    {
        cout << "Fat mass can't be " << fatMass << "\n";
        return;
    }
    this->fatMass = fatMass;
}
float Female::getFatMass() { return this->fatMass; }
