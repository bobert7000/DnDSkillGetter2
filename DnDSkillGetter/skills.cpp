// skills.cpp - skills class implementation
// Written by Bobert Comegna
#include <string>
#include <map>
#include "fileSearch.h"
using namespace std;
#include "skills.h"
#include "macroMaker.h"

skills::skills()
{
}

skills::skills(char *skillName, char *characterName)
{
	fileSearch(skillName, skillInfo);
	string characterStr = characterName;
	skillInfo["Name"] = characterStr;
}

string skills::getName()
{
	return skillInfo["Name"];
}

string skills::getSkillName()
{
	return skillInfo["SkillName"];
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

string skills::getDescription()
{
	return skillInfo["Description"];
}

skills::~skills()
{
}