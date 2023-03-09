#include <iostream>
#include <stdlib.h>
#include <string>
#include "Trainer.h"
#include "Female.h"
#include "Male.h"

using namespace std;

int signMenu()
{
	cout << " 1- Admin Sign In\n";
	cout << " 2- Trainer Sign In\n";
	cout << " 3- User Sign In\n";
	cout << " 4- Quit\n";
	int x;
	cin >> x;
	return x;
}

int userMenu()
{
	cout << " 1- Train\n";
	cout << " 2- Display Payment Information\n";
	cout << " 3- Display Training Information\n";
	cout << " 4- Main Menu\n";
	int x;
	cin >> x;
	return x;
}

int trainerMenu()
{
	cout << " 1- Assign User\n";
	cout << " 2- Unassign User\n";
	cout << " 3- Give Training Program To Student\n";
	cout << " 4- Main Menu\n";
	int x;
	cin >> x;
	return x;
}

int adminMenu()
{
	cout << " 1- Create User\n";
	cout << " 2- Delete User\n";
	cout << " 3- Display User\n";
	cout << " 4- Create Trainer\n";
	cout << " 5- Change Payment\n";
	cout << " 6- Main Menu\n";
	int x;
	cin >> x;
	return x;
}

void displayUsers(vector<Male> male, vector<Female> female)
{
	int c = 1;
	for(int i = 0; i < male.size() ; ++i)
	{
		cout << c++ << "- ";
		cout << male.at(i).getName(); // Polymorphism -> Male class gets getName function of Person class
		cout << "\n";
	}
	for(int i = 0 ; i < female.size() ; ++i)
	{
		cout << c++ << "- ";
		cout << female.at(i).getName(); // Polymorphism -> Female class gets getName function of Person class
		cout << "\n";
	}
}

void printUser(vector<Male> male, vector<Female> female)
{
	int l;
	displayUsers(male,female);
	if(male.size() <= 0 && female.size() <= 0)
	{
		cout << "No users to display\n";
		return;
	}
	cin >> l;
	if(l < 1 || l > male.size() + female.size()) return;
	if(male.size() >= l)
	{
		cout << male.at(l - 1);
		return;
	}
	cout << female.at(l - male.size() - 1);
}

void removeUser(vector<Male> &male, vector<Female> &female)
{
	int l;
	displayUsers(male,female);
	if(male.size() <= 0 && female.size() <= 0)
	{
		cout << "No users to display\n";
		return;
	}
	cin >> l;
	if(l < 1 || l > male.size() + female.size()) return;
	if(male.size() >= l)
	{
		male.erase(male.begin() + l - 1);
		return;
	}
	female.erase(female.begin() + (l - male.size() - 1));
}

void wihichTrainer(vector<Trainer> trainers)
{
	int c = 1;
	for(int i = 0 ; i < trainers.size() ; ++i)
	{
		cout << c++ << "- ";
		cout << trainers.at(i).getName() << "\n";
	}
}

int main() {
	vector<Male> male;
	vector<Female> female;
	vector<Trainer> trainers;
	Female tempFemale;
	Male tempMale;
	Trainer trainer = Trainer();
	int choice,gender,Age,Height,Weight;
	float mass;
	string Name;
	int memtyp;
	int i;
	float normal_month = 100;
	float premium_month = 300;
	do
	{
		choice=signMenu();
		if(choice == 1)
		{
			int a_choice;
			do
			{
				a_choice=adminMenu();
				if(a_choice == 1)
				{
					cout<<"Enter 1 if the member is male, and 0 if female.";
					cin>>gender;
					if(gender==1)
					{
						cout<<"Enter Name: ";
						cin>>Name;
						cout<<"Enter Age: ";
						cin>>Age;
						cout<<"Enter Height: ";
						cin>>Height;
						cout<<"Enter Weight: ";
						cin>>Weight;
						cout<<"Enter Muscle Mass: ";
						cin>>mass;
						cout<<"Enter Membership type(0 for normal 1 for premium): ";
						cin>>memtyp;
						tempMale = Male(Name,Height,Weight,static_cast<MembershipType>(memtyp),mass,Age);
						male.push_back(tempMale);
					}
					else if (gender==0)
					{
						cout<<"Enter Name: ";
						cin>>Name;
						cout<<"Enter Age: ";
						cin>>Age;
						cout<<"Enter Height: ";
						cin>>Height;
						cout<<"Enter Weight: ";
						cin>>Weight;
						cout<<"Enter Fat Mass: ";
						cin>>mass;
						cout<<"Enter Membership type(0 for normal 1 for premium): ";
						cin>>memtyp;
						tempFemale = Female(Name,Height,Weight,static_cast<MembershipType>(memtyp),mass,Age);
						female.push_back(tempFemale);
					}
				}
				else if(a_choice == 2)
				{
					removeUser(male, female);
				}
				else if(a_choice == 3)
				{
					printUser(male, female);
				}
				else if(a_choice == 4)
				{
					cout << "Enter trainer name: ";
					cin >> Name;
					trainer = Trainer(Name);
					trainers.push_back(trainer);
				}
				else if(a_choice == 5)
				{
					cout << "Which payment will be changed?\n ";
					cout << "1- normal monthly\n";
					cout << "2- premium monthly\n";
					cin >> i;
					cout << "Enter new price: ";
					cin >> mass;
					if(i == 1) { normal_month = mass; }
					else if(i == 2) { premium_month = mass; }
				}
			} while(a_choice != 6);
		}
		else if(choice == 2)
		{
			if(trainers.size() <= 0)
			{
				cout << "There are no trainers registered\n";
			}
			else
			{
				int a_choice, idx;
				wihichTrainer(trainers);
				cin >> idx;
				--idx;
				do
				{
					a_choice=trainerMenu();
					if(a_choice == 1)
					{
						if(male.size() <= 0 && female.size() <= 0)
						{
							cout << "No users to register\n";
						}
						else
						{
							displayUsers(male, female);
							cin>>i;
							if(male.size() >= i)
							{
								if(!male.at(i-1).hasTeacher())
								{
									trainers.at(idx).addStudent(&male.at(i-1));
								}
								else cout << "Student already has a teacher!\n";
							}
							else if(i <= female.size() + male.size())
							{
								if(!female.at(i - 1 - male.size()).hasTeacher())
								{
									trainers.at(idx).addStudent(&female.at(i - 1 - male.size()));
								}
								else cout << "Student already has a teacher!\n";
							}
						}
					}
					else if(a_choice == 2)
					{
						trainers.at(idx).deleteStudent();
					}
					else if(a_choice == 3)
					{
						trainers.at(idx).assignTrainingProgram();
					}

				} while(a_choice != 4);
			}
		}
		else if(choice == 3)
		{
			if(male.size() <= 0 && female.size() <= 0)
			{
				cout << "There are no users registered\n";
			}
			else
			{
				int a_choice, idx;
				bool isfemale = false;
				displayUsers(male, female);
				cin >> idx;
				
				if(male.size() < idx)
				{
					isfemale = true;
					idx -= male.size();
				}
				--idx;
				do
				{
					a_choice=userMenu();
					if(a_choice == 1)
					{
						if(isfemale)
						{
							female.at(idx).trainFor10Mins();
						}
						else
						{
							male.at(idx).trainFor10Mins();
						}
					}

					else if(a_choice == 2)
					{
						cout << "Monthly payment is: ";
						if(isfemale)
						{
							if(female.at(idx).getMembershipType() == normal) cout << normal_month << "\n";
							else cout << premium_month << "\n";
						}
						else
						{
							if(male.at(idx).getMembershipType() == normal) cout << normal_month << "\n";
							else cout << premium_month << "\n";
						}
					}
					else if(a_choice == 3)
					{
						if(isfemale)
						{
							cout << "Cardio Mins left: " << female.at(idx).getTrainingProgramCardio() << "\n";
							cout << "Weight Mins left: " << female.at(idx).getTrainingProgramWeight() << "\n";
						}
						else
						{
							cout << "Cardio Mins left: " << male.at(idx).getTrainingProgramCardio() << "\n";
							cout << "Weight Mins left: " << male.at(idx).getTrainingProgramWeight() << "\n";
						}
					}
				} while(a_choice != 4);
			}
		}
	}while(choice != 4);
}
