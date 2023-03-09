#pragma once
#ifndef _TRAININGPROGRAM_H_
#define _TRAININGPROGRAM_H_
#include<iostream>

using namespace std;

class TrainingProgram
{
private: // Encapsulation
    float cardioMins;
    float weightTrainingMins;
public:
    TrainingProgram();

    TrainingProgram(float cardioMins, float weightTrainingMins);

    void setCardioMins(float cardioMins);
    void setWeightTrainingMins(float weightTrainingMins);

    float getCardioMins();
    float getWeightTrainingMins();

    void trainFor10Mins();
};
#include "TrainingProgram.cpp"
#endif
