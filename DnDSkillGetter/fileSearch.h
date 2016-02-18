#pragma once
// skills.h
// Written by Robert Comegna
// stores/manipulates skills data
#include <string>
#include <vector>
#include <fstream>
#include <map>
using namespace std;

class fileSearch
{
public:
	//Constructors
	fileSearch(); //default
	fileSearch(char* filename, map<char*, string>& skillInfo); //HTML source code of skill

	string getName(char* skillName);
	string getClass();
	string getComponents();
	string getCT();
	string getRange();
	string getArea();
	string getDuration();
	string getSaving();
	string getResist();
	string getDescrip();

	//Deconstructor
	~fileSearch();
	// protected means 'private' when accessing the protected memebers outside the base class
	// or outside of the derived classes
protected:
	int searchVector(char* token, int pos = 0);
	string cleanLine(int pos);
	string cleanDescription(int pos);
	vector<string> htmlSource;
	int specialHTMLNumber = 70; //since info we want begins here we will begin here (for now)
	const int maxLine = 1024;
};
