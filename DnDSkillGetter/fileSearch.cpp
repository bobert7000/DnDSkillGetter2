// FileSearch.cpp - fileSearch Class Implementation

#include <string>
#include <vector>
#include <fstream>
#include <map>
using namespace std;

#include "fileSearch.h"

fileSearch::fileSearch()
{

}

void organizeVector(vector<char*> myVector, int start, int end);

fileSearch::fileSearch(char* fileName,map<char*, string> skillInfo)
{
	fstream file;
	char* buffer = "";
	//Open the file
	file.open(fileName);
	//Load the vector
	while (file.getline(buffer, maxLine))
	{
		htmlSource.push_back(buffer);
	}
	//Organize it
	//organizeVector(htmlSource,0,htmlSource.size() - 1);
	//Find important and load it into the handed vector
	skillInfo["Name"] = getName(fileName);
	skillInfo["Class"] = getClass();
	skillInfo["Components"] = getComponents();
	skillInfo["Cast Time"] = getCT();
	skillInfo["Range"] = getRange();
	skillInfo["Area"] = getArea();
	skillInfo["Duration"] = getDuration();
	skillInfo["Saving Throw"] = getSaving();
	skillInfo["Resistance"] = getResist();
}

/*//Swap function for vector
void swap(vector<char*> myVector, int i, int j)
{
	char* temp;
	temp = myVector[i];
	myVector[i] = myVector[j];
	myVector[j] = temp;
	return;
}

//partition vector for quicksort
void partitionVector(vector<char*> myVector, int i, int j, int pivot)
{
	while (i < j)
	{
		while (strcmp(myVector[i], myVector[pivot]) < 0)
			i++;
		while (strcmp(myVector[j], myVector[pivot]) > 0)
			j--;
		if (i <= j)
		{
			swap(myVector, i, j);
			i++;
			j--;
		}
	}
}

//sort vector of html cod using quicksort
void organizeVector(vector<char*> myVector,int start, int end)
{
	int i = start;
	int j = end;
	int pivot = (i + j) / 2;

	partitionVector(myVector, i, j, pivot);
	
	//recursion
	if (start < j)
		organizeVector(myVector, start, j);
	if (i < end)
		organizeVector(myVector, start, j);
}*/

int fileSearch::searchVector(char* token, int pos)
{
	while (pos < htmlSource.size())
	{
		if (strstr(htmlSource[pos], token))
			return pos;
	}

	return -1; //return a non index value if nothing turns up
}

string fileSearch::cleanLine(int pos)
{
	char* tmp;
	string myString;
	int start = 0;
	tmp = htmlSource[pos];

	for (int i = 0; tmp[i] != NULL; i++)
	{
		if (tmp[i] == '>')
		{
			while (tmp[i] != '<')
				myString = myString + tmp[i];
		}
	}

	return myString;
}

string fileSearch::getName(char* skillName)
{
	int pos;
	pos = searchVector(skillName, specialHTMLNumber);
	return cleanLine(pos);
}

string fileSearch::getClass()
{
	int pos;
	pos = searchVector("Class", specialHTMLNumber);
	pos++; //add 1 for this blocks info
	return cleanLine(pos);
}

string fileSearch::getComponents()
{
	int pos;
	pos = searchVector("Components", specialHTMLNumber);
	pos++; //add 1 for this blocks info
	return cleanLine(pos);
}

string fileSearch::getCT()
{
	int pos;
	pos = searchVector("Cast Time", specialHTMLNumber);
	pos++; //add 1 for this blocks info
	return cleanLine(pos);
}

string fileSearch::getRange()
{
	int pos;
	pos = searchVector("Range", specialHTMLNumber);
	pos++; //add 1 for this blocks info
	return cleanLine(pos);
}

string fileSearch::getArea()
{
	int pos;
	pos = searchVector("Area", specialHTMLNumber);
	pos++; //add 1 for this blocks info
	return cleanLine(pos);
}

string fileSearch::getDuration()
{
	int pos;
	pos = searchVector("Duration", specialHTMLNumber);
	pos++; //add 1 for this blocks info
	return cleanLine(pos);
}

string fileSearch::getSaving()
{
	int pos;
	pos = searchVector("Class", specialHTMLNumber);
	pos++; //add 1 for this blocks info
	return cleanLine(pos);
}

string fileSearch::getResist() 
{
	int pos;
	pos = searchVector("Spell Resistance", specialHTMLNumber);
	pos++; //add 1 for this blocks info
	return cleanLine(pos);
}

fileSearch::~fileSearch()
{
}