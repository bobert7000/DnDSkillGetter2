// skills.cpp - skills class implementation
// Written by Bobert Comegna
#include <string>
#include <map>
#include "fileSearch.h"
using namespace std;
#include "skills.h"

skills::skills()
{
}

skills::skills(char *skillName)
{
	fileSearch(skillName, skillInfo);
}

string skills::getName()
{
	return skillInfo["Name"];
}

string skills::getClass()
{
	return skillInfo["Class"];
}

string skills::getComponents()
{
	return skillInfo["Components"];
}

string skills::getCT()
{
	return skillInfo["Cast Time"];
}

string skills::getRange()
{
	return skillInfo["Range"];
}

string skills::getArea()
{
	return skillInfo["Area"];
}

string skills::getDuration()
{
	return skillInfo["Duration"];
}

string skills::getSaving()
{
	return skillInfo["Saving"];
}

string skills::getResist()
{
	return skillInfo["Resist"];
}

skills::~skills()
{
}