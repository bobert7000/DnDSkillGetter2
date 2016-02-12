#pragma once
// skills.h
// Written by Robert Comegna
// stores/manipulates skills data


class fileSearch
{
public:
	//Constructors
	fileSearch(); //default
	fileSearch(char* filename, vector<char*> skillInfo); //HTML source code of skill

	char* getName();
	char* getClass();
	char* getComponents();
	char* getCT();
	char* getRange();
	char* getArea();
	char* getDuration();
	char* getSaving();
	char* getResist();

	//Deconstructor
	~fileSearch();
	// protected means 'private' when accessing the protected memebers outside the base class
	// or outside of the derived classes
protected:
	vector<char*> htmlSource;
	const int maxLine = 1024;
};
