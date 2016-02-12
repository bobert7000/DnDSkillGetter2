#pragma once
// skills.h
// Written by Robert Comegna
// stores/manipulates skills data

#include <string>
using namespace std;

class skills
{
public:
	//Constructors
	skills(); //default
	skills(char *skillHTML); //HTML source code of skill

	//Class functions 
	string findString(char *myChar); //NOTE: consider change/reclass for this function
	//Functions that Extrapolates skill info from source code
	string getName();
	string getClass();
	string getComponents();
	string getCT();
	string getRange();
	string getArea();
	string getDuration();
	string getSaving();
	string getResist();

	//Deconstructor
	~skills();
// protected means 'private' when accessing the protected memebers outside the base class
// or outside of the derived classes
protected:
	vector<char *> skillInfo;
	const int maxLine = 1024;
};