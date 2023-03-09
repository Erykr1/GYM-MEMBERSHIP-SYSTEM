#include<iostream>
#include"Trainer.h"

using namespace std;

Trainer::Trainer()
{
    this->name = "none";
    studentCount = 0;
}
Trainer::Trainer(string name)
{
    this->name = name;
    this->studentCount = 0;
}

void Trainer::addStudent(Person *person)
{
    if(studentCount >= 10)
    {
        cout<< "Student limit has reached\n";
        return;
    }
    this->students[studentCount++] = person;
    person->setTeacherStatus(true);
}

void Trainer::deleteStudent()
{
    if(studentCount <= 0)
    {
        cout << "Trainer has no students\n";
        return;
    }
    int pos;
    displayStudents();
    cout << "\n\nEnter the position, between 1 and " << studentCount << " , of the student to be deleted : ";
    cin >> pos;
    if(pos > studentCount || pos < 1)
    {
        cout << "Invalid number entered\n";
        return;
    }
    --pos;
    for (int i = pos; i < studentCount; i++)
    {
        students[i] = students[i + 1];
    }
    --studentCount;
}

void Trainer::displayStudents()
{
    int c = 1;
    for(int i = 0 ; i < studentCount ; ++i)
    {
        cout << c++ << "- ";
		cout << students[i]->getName();
		cout << "\n";
    }
}

void Trainer::assignTrainingProgram()
{
    if(studentCount <= 0)
    {
        cout << "Trainer has no students\n";
        return;
    }
    displayStudents();
    int pos;
    cout << "\n\nSelect user to give training program to: ";
    cin >> pos;
    if(pos > studentCount || pos < 1)
    {
        cout << "Invalid number entered\n";
        return;
    }
    float mass;
    TrainingProgram trainingProgram = TrainingProgram();
    cout << "Weight Training Duration: ";
	cin >> mass;
	trainingProgram.setWeightTrainingMins(mass);
	cout << "Cardio Duration: ";
	cin >> mass;
	trainingProgram.setCardioMins(mass);
    students[pos-1]->setTrainingProgram(trainingProgram);
}

void Trainer::setName(string name)
{
    this->name = name;
}

string Trainer::getName()
{
    return this->name;
}
