// DnDSkill Getter
// Written by Robert Comegna
// Gets info off the SRD, cleans it up and puts it in format for macros for roll 20

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "skills.h"
#include "macroMaker.h"
#include <curl.h>

//Function dumps a character array in a file
void writeHTML(char *data)
{
	ofstream myFile;
	myFile.open("myFile.txt");
	myFile << data;
	myFile.close();
	return;
}

//Struct buffer for writing dating to a file
size_t write_data(char *ptr, size_t size, size_t nmemb, FILE *stream) 
{
	size_t written;
	written = fwrite(ptr, size, nmemb, stream);
	writeHTML(ptr);
	return written;
}

// Function Grabs the html source from a handed url
void htmlGrab(string myURL)
{
	//Init libCURL
	curl_global_init(CURL_GLOBAL_ALL);

	//Init variables
	string temp = "temp";
	CURL *myHandle;
	CURLcode result; // We’ll store the result of CURL’s webpage retrieval, for simple error checking.
	

	myHandle = curl_easy_init(); // Notice the lack of major error-checking, for brevity
	curl_easy_setopt(myHandle, CURLOPT_URL, myURL);	
	curl_easy_setopt(myHandle, CURLOPT_WRITEFUNCTION, write_data); //Send to Buffer and write to fp
	result = curl_easy_perform(myHandle);

	//Always Clean Up
	curl_easy_cleanup(myHandle);

}


void main()
{
	string myURL = "http://www.d20srd.org/srd/spells/";
	char skillName[256];
	char characterName[32];
	cout << "Skill Name: ";
	cin.getline(skillName,256);
	cout << "Character Name: ";
	cin >> characterName;


	//Make a good url
	for (int i = 0; skillName[i] != NULL; i++)
	{
		if (skillName[i] >= 'A' && skillName[i] <= 'Z' && i == 0)
			skillName[i] = towlower(skillName[i]);

		if (skillName[i] != ' ')
			myURL = myURL + skillName[i];
		else
		{
			i++;
			if (skillName[i] >= 'a' && skillName[i] <= 'z')
				skillName[i] = towupper(skillName[i]);
			myURL = myURL + skillName[i];
		}
	}


	myURL = myURL + ".htm";

	htmlGrab(myURL);

	skills mySkill(skillName,characterName);
	macroMaker myMacro(mySkill, characterName);

	system("pause");
}
