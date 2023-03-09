#pragma once
#ifndef _TRAINER_H_
#define _TRAINER_H_

#include<iostream>
#include<vector>
#include"Person.h"

using namespace std;

class Trainer
{
private: // Encapsulation
    string name;
    Person* students[10];
    int studentCount;

    void displayStudents();
public:
    Trainer();
    Trainer(string name);

    void addStudent(Person *person);

    void deleteStudent();

    string getName();
    void setName(string name);

    void assignTrainingProgram();
};

#include "Trainer.cpp"
#endif // Trainer_H
