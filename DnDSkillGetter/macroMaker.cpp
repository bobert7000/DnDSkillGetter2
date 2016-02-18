// macroMaker.cpp - macroMaker.cpp base class implemention
// Written by Robert M. Comegna

#include <string>
#include <map>
#include <fstream>
#include <iostream>
using namespace std;

#include "skills.h"
#include "macroMaker.h"

//Default Init Constructor
macroMaker::macroMaker()
{
}

// Constructor

macroMaker::macroMaker(skills skillInfo, char* characterName)
{
	// For now just pass to templateA
	templateA(skillInfo, characterName);
}

void macroMaker::templateA(skills skillInfo,char* characterName)
{
	fstream file;
	string fileName = skillInfo.getSkillName() + ".txt";
	string output = first + skillInfo.getName() + second + skillInfo.getSkillName() + third + skillInfo.getName() + fourth + fifth + sixth + skillInfo.getCT() + seventh + skillInfo.getDuration() + eigth + ninth + skillInfo.getRange() + tenth + skillInfo.getClass() + str11 + skillInfo.getComponents() + str12 + skillInfo.getDescription() + str13 + skillInfo.getName() + str14;
	
	cout << fileName << endl;
	//open the file
	file.open(fileName, fstream::out);
	//Write string to file
	file << output;
	//always close
	file.close();
}