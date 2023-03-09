#include<iostream>
#include"Person.h"

using namespace std;

Person::Person()
{
    this->age = 0;
    this->name = "none";
    this->height = 0;
    this->weight = 0.0;
    this->membershipType = normal;
    this->hasteacher = false;
}

Person::Person(int age,string name, int height, float weight, MembershipType membershipType)
{
    this->age = age;
	this->name = name;
    this->height = height;
    this->weight = weight;
    this->membershipType = membershipType;
    this->hasteacher = false;
}
void Person::setAge(int age) { this->age = age; } // Abstraction age variable can only be changed through this function

void Person::setName(string name) { this->name = name; } // Abstraction name variable can only be changed through this function

void Person::setHeight(int height) { this->height = height; } // Abstraction height variable can only be changed through this function

void Person::setWeight(float weight) { this->weight = weight; } // Abstraction weight variable can only be changed through this function

void Person::setMembershipType(MembershipType membershipType) { this->membershipType = membershipType; } // Abstraction membershipType variable can only be changed through this function

int Person::getAge() { return this->age; } // Abstraction age variable can only be reached through this function

string Person::getName() { return this->name; } // Abstraction name variable can only be reached through this function

int Person::getHeight() { return this->height; } // Abstraction height variable can only be reached through this function

float Person::getWeight() { return this->weight; } // Abstraction weight variable can only be reached through this function

MembershipType Person::getMembershipType() { return this->membershipType; } // Abstraction membershipType variable can only be reached through this function

float Person::getBMI()
{
    return this->weight / ((this->height/100.0) * (this->height/100.0));
}

void Person::setTrainingProgram(TrainingProgram trainingProgram) // Abstraction trainingProgram variable can only be changed through this function
{
    this->trainingProgram = trainingProgram;
}

void Person::setTrainingProgramWeight(float weight) // Abstraction trainingProgram's weightTrainingMins variable can only be changed through this function
{
    this->trainingProgram.setWeightTrainingMins(weight);
}
void Person::setTrainingProgramCardio(float cardio) // Abstraction trainingProgram's cardioMins variable can only be changed through this function
{
    this->trainingProgram.setCardioMins(cardio);
}

void Person::trainFor10Mins() // Abstraction user can only train through this function
{
    this->trainingProgram.trainFor10Mins();
}

float Person::getTrainingProgramWeight()
{
    return this->trainingProgram.getWeightTrainingMins();
}
float Person::getTrainingProgramCardio()
{
    return this->trainingProgram.getCardioMins();
}

bool Person::hasTeacher()
{
    return this->hasteacher;
}
void Person::setTeacherStatus(bool stat)
{
    this->hasteacher = stat;
}
