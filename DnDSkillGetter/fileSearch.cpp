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

//void organizeVector(vector<char*> myVector, int start, int end);

fileSearch::fileSearch(char* fileName,map<char*, string>& skillInfo)
{
	fstream file;
	string buffer;
	//Open the file
	file.open("myFile.txt");
	//Load the vector
	while (getline(file,buffer))
	{
		htmlSource.push_back(buffer);
	}

	file.close();
	//Organize it
	//organizeVector(htmlSource,0,htmlSource.size() - 1);
	//Find important and load it into the handed vector
	skillInfo["SkillName"] = getName(fileName);
	skillInfo["Class"] = getClass();
	skillInfo["Components"] = getComponents();
	skillInfo["Cast Time"] = getCT();
	skillInfo["Range"] = getRange();
	skillInfo["Area"] = getArea();
	skillInfo["Duration"] = getDuration();
	skillInfo["Saving Throw"] = getSaving();
	skillInfo["Resistance"] = getResist();
	skillInfo["Description"] = getDescrip();
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
	string buffer= "test";
	string test = token;
	size_t punk = 0;
	for (int i = 0; i < test.size(); i++)
		test[i] = towlower(test[i]);

	while (pos < htmlSource.size())
	{
		buffer.replace(0,buffer.size(), htmlSource[pos]);

		//Case Sensetivity is a bitch
		for (int i = 0; i < buffer.size(); i++)
			buffer[i] = towlower(buffer[i]);

		punk = buffer.find(test);

		if (punk != string::npos) //seaerch str for subset string
			return pos;
		pos++;
	}

	return pos; //return a non index value if nothing turns up
}

string fileSearch::cleanLine(int pos)
{
	string myString;
	string buffer;
	int start = 0;

	//If its a non index position return an empty string
	if (pos == -1)
		return myString = "";

	buffer = htmlSource[pos];

	for (int i = 0; buffer[i] != NULL; i++)
	{
		if (buffer[i] == '>')
		{ 
			i++;
			while (buffer[i] != '<' && i < buffer.size())
			{
				myString = myString + buffer[i];
				i++;
			}
			i++;
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
	pos = searchVector("level", specialHTMLNumber);
	pos++;
	return cleanLine(pos);
}

string fileSearch::getComponents()
{
	int pos;
	pos = searchVector("components", specialHTMLNumber);
	pos++; //add 1 for this blocks info
	return cleanLine(pos);
}

string fileSearch::getCT()
{
	int pos;
	pos = searchVector("casting time", specialHTMLNumber);
	pos++; //add 1 for this blocks info
	return cleanLine(pos);
}

string fileSearch::getRange()
{
	int pos;
	pos = searchVector("range", specialHTMLNumber);
	pos++; //add 1 for this blocks info
	return cleanLine(pos);
}

string fileSearch::getArea()
{
	int pos;
	pos = searchVector("area", specialHTMLNumber);
	pos++; //add 1 for this blocks info
	return cleanLine(pos);
}

string fileSearch::getDuration()
{
	int pos;
	pos = searchVector("duration", specialHTMLNumber);
	pos++; //add 1 for this blocks info
	return cleanLine(pos);
}

string fileSearch::getSaving()
{
	int pos;
	pos = searchVector("saving throw", specialHTMLNumber);
	pos++; //add 1 for this blocks info
	return cleanLine(pos);
}

string fileSearch::getResist() 
{
	int pos;
	pos = searchVector("spell resistance", specialHTMLNumber);
	pos++; //add 1 for this blocks info
	return cleanLine(pos);
}

string fileSearch::cleanDescription(int pos)
{
	string myString;
	string buffer = htmlSource[pos];
	//Special Cleaning Rules
	for (int i = 0; buffer[i] != NULL; i++)
	{
		//if we find an html tag we ignore (pass around)
		if (buffer[i] == '<')
		{
			while (buffer[i] != '>' && i < buffer.size())
				i++;
			i++;
		}

		//if there is a dice roll we add roll20 rollers
		if ((buffer[i] >= '1' && buffer[i] <= '9') && buffer[i + 1] == 'd')
		{
			myString = myString + "[[";
			for (int j = i; buffer[j] >= '1' && buffer[j] <= '9' || buffer[j] == 'd' || buffer[j] == '+'; j++)
			{
				myString = myString + buffer[j];
				i = j;
			}
			myString = myString + "]]";

		}
		else
			myString = myString + buffer[i];
	}

	return myString;
}

string fileSearch::getDescrip()
{
	int pos;
	pos = searchVector("</table>", specialHTMLNumber);
	pos += 2;

	return cleanDescription(pos);
}

fileSearch::~fileSearch()
{
}