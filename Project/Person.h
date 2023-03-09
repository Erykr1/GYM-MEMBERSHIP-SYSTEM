#pragma once
#ifndef PERSON_H_INCLUDED_
#define PERSON_H_INCLUDED_

#include<iostream>
#include"TrainingProgram.h"
#include"MembershipType.h"

using namespace std;

class Person
{
private: // Encapsulation
	int age;
    string name;
    int height;
    float weight;
    MembershipType membershipType;
    TrainingProgram trainingProgram;
    bool hasteacher;


public:
    Person();
    Person(int age,string name, int height, float weight, MembershipType membershipType);
    float getBMI();
    void setAge(int age); //
    void setName(string name);
    void setHeight(int height);
    void setWeight(float weight);
    void setMembershipType(MembershipType membershipType);
    void setTrainingProgram(TrainingProgram trainingProgram);

    int getAge(); //
    string getName();
    int getHeight();
    float getWeight();
    MembershipType getMembershipType();

    void setTrainingProgramWeight(float weight);
    void setTrainingProgramCardio(float cardio);
    
    float getTrainingProgramWeight();
    float getTrainingProgramCardio();

    void trainFor10Mins();

    bool hasTeacher();
    void setTeacherStatus(bool stat);
};

#include "Person.cpp"
#endif // Person_H
