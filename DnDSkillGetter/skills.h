#pragma once
// skills.h
// Written by Robert Comegna
// stores/manipulates skills data


#include <string>
#include <map>
using namespace std;

class skills
{
public:
	//Constructors
	skills(); //default
	skills(char *skillName,char *characterName); //HTML source code of skill

	//Class functions 
	//string findString(char *myChar); //NOTE: consider change/reclass for this function
	//Functions that Extrapolates skill info from source code
	string getName();
	string getSkillName();
	string getClass();
	string getComponents();
	string getCT();
	string getRange();
	string getArea();
	string getDuration();
	string getSaving();
	string getResist();
	string getDescription();

	//Deconstructor
	~skills();
// protected means 'private' when accessing the protected memebers outside the base class
// or outside of the derived classes
protected:
	map<char *,string> skillInfo;
	const int maxLine = 1024;
};