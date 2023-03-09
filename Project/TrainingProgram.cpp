#include<iostream>
#include"TrainingProgram.h"

using namespace std;

TrainingProgram::TrainingProgram()
{
    this->cardioMins = 15.0;
    this->weightTrainingMins = 30.0;
}
TrainingProgram::TrainingProgram(float cardioMins, float weightTrainingMins)
{
    this->cardioMins = cardioMins;
    this->weightTrainingMins = weightTrainingMins;
}

void TrainingProgram::setCardioMins(float cardioMins) // Abstraction cardio minutes can only be set through this function
{
    if(cardioMins <= 0)
    {
        cout << "Cardio minutes can't be " << cardioMins << "\n";
        return;
    }
    this->cardioMins = cardioMins;
}
void TrainingProgram::setWeightTrainingMins(float weightTrainingMins) // Abstraction weight training minutes can only be set through this function
{
    if(weightTrainingMins <= 0)
    {
        cout << "Weight training minutes can't be " << weightTrainingMins << "\n";
        return;
    }
    this->weightTrainingMins = weightTrainingMins;
}

float TrainingProgram::getCardioMins() { return this->cardioMins; }
float TrainingProgram::getWeightTrainingMins() { return this->weightTrainingMins; }

void TrainingProgram::trainFor10Mins() // Abstraction training can only be done through this function
{
    cout << "1- Cardio Training\n2- Weight Training\n";
    int train;
    cin >> train;
    if(train == 1)
    {
        if(cardioMins < 10 && cardioMins > 0)
        {
            this->cardioMins = 0;
            return;
        }
        else if(cardioMins == 0)
        {
            cout << "You already finished cardio training \n";
            return;
        }
        this->cardioMins -= 10;
        return;
    }
    if(weightTrainingMins < 10 && weightTrainingMins > 0)
        {
            this->weightTrainingMins = 0;
            return;
        }
        else if(weightTrainingMins == 0)
        {
            cout << "You already finished weight training \n";
            return;
        }
        this->weightTrainingMins -= 10;
        return;
}

