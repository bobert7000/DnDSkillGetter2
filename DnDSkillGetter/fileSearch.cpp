// FileSearch.cpp - fileSearch Class Implementation

#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "fileSearch.h"

fileSearch::fileSearch()
{

}

fileSearch::fileSearch(char* fileName,vector<char*> skillInfo)
{
	fstream file;
	char* buffer;
	//Open the file
	file.open(fileName);
	//Load the vector
	while (file.getline(buffer, maxLine))
	{
		htmlSource.push_back(buffer);
	}
	//Organize it
	organizeVector(htmlSource);
	//Find important and load it into the handed vector
	skillInfo.push_back(getName());
	skillInfo.push_back(getClass());
	skillInfo.push_back(getComponents());
	skillInfo.push_back(getCT());
	skillInfo.push_back(getRange());
	skillInfo.push_back(getArea());
	skillInfo.push_back(getDuration());
	skillInfo.push_back(getSaving());
	skillInfo.push_back(getResist());
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

//Swap function for vector
void swap(vector<char*> myVector, int i, int j)
{
	char* temp;
	temp = myVector[i];
	myVector[i] = myVector[j];
	myVector[j] = temp;
	return;
}

void searchVector(vector<char*>  myVector, char* token)
{

}

char* fileSearch::getName()
{

}

char* fileSearch::getClass()
{

}

char* fileSearch::getComponents()
{
}

char* fileSearch::getCT()
{

}

char* fileSearch::getRange()
{

}

char* fileSearch::getArea()
{

}

char* fileSearch::getDuration()
{

}

char* fileSearch::getSaving()
{

}

char* fileSearch::getResist() 
{

}

fileSearch::~fileSearch()
{
}