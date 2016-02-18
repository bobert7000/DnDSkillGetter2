#pragma once
// macroMaker.h - Using a passed skill container, constructs a macro (user defined)
//Written by Robert M. Comegna

#include <string>
#include <map>
using namespace std;

#include "skills.h"

class macroMaker
{
public:
	macroMaker(); //default class contructor
	macroMaker(skills skillInfo, char* str);
	void templateA(skills skillInfo, char* str);
protected:
	string first = "&{template:5eDefault} {{spell=1}} {{spellshowinfoblock=1}} {{spellshowdesc=1}} {{spellshowhigherlvl=1}} {{character_name=@{";
	string second = "|character_name}}} {{emote=looks at the instructions for a spell}} {{title=";
	string third = "}} {{subheader=@{";
	string fourth = "|character_name}}} {{subheaderright=";
	string fifth = "}}{{subheader2=(Concentration";
	string sixth = ") }}  {{spellcasttime=";
	string seventh = "}} {{spellduration=";
	string eigth = "}} {{spelltarget=";
	string ninth = "}} {{spellrange=";
	string tenth = "}} {{spellgainedfrom=";
	string str11 = "}} {{spellcomponents=";
	string str12 = "}}  {{spelldescription=";
	string str13 = "}} {{spellhigherlevel=}} @{";
	string str14 = "|classactionspellinfo}";
};