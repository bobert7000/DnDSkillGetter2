// skills.cpp - skills class implementation
// Written by Bobert Comegna
#include <string>
#include <fstream>
#include <vector>
using namespace std;
#include "skills.h"

skills::skills()
{
}

skills::skills(char *skillHTML)
{
	fstream skillFile;
	skillFile.open(skillHTML);
	char *buffer;

	//Clean up source code to contain only relavent info

	//Load each line of the source code into a vector
	while (skillFile.getline(buffer, maxLine))
	{
		skillInfo.push_back(buffer);
	}

}

string skills::getName()
{

}

string skills::getClass()
{

}

string skills::getComponents()
{

}

string skills::getCT()
{

}

string skills::getRange()
{

}

string skills::getArea()
{

}

string skills::getDuration()
{

}

string skills::getSaving()
{

}

string skills::getResist()
{

}

skills::~skills()
{
}