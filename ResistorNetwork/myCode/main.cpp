// Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
#include <fstream>

using namespace std;

// Add your project's header files here
#include "ResistorReader.h"

// Main program
int main ()
{
	cout << "ResistorNetwork started." << endl << endl;

	ResistorPart obj1("R1", 42, 5);

	cout << obj1 << endl;

	shared_ptr<ResistorPart> R1 = make_shared<ResistorPart>(ResistorPart("R1", 1000, 10));
	shared_ptr<ResistorPart> R3 = make_shared<ResistorPart>(ResistorPart("R3", 1000, 10));
	shared_ptr<ResistorPart> R4 = make_shared<ResistorPart>(ResistorPart("R4", 4700, 10));
	shared_ptr<ResistorPart> R6 = make_shared<ResistorPart>(ResistorPart("R6", 1000, 10));
	shared_ptr<ResistorPart> R7 = make_shared<ResistorPart>(ResistorPart("R7", 4700, 10));

	SerialResistorConnection R2("R2");
	R2 += R3;
	R2 += R4;

	cout << R2.getName() << "=" << R2.nominalValue() << " Ohm" << endl;

	ParallelResistorConnection R5("R5");
	R5 += R6;
	R5 += R7;

	cout << R5.getName() << "=" << R5.nominalValue() << " Ohm" << endl;

	ofstream writefile("data.txt");

	if(writefile.is_open())
	{
		R2.write(writefile);
		R5.write(writefile);
		writefile.close();
	}

	ResistorReader read;

	map<string, ResistorPtr> found;

	ifstream readfile("data.txt");

	if(readfile.is_open())
	{
		read.read(readfile, found);

		readfile.close();
	}

	ofstream writefile1("data1.txt");

	if(writefile1.is_open())
	{
		for(auto& data : found)
		{
			data.second.get()->write(writefile1);
		}
		writefile1.close();
	}

	return 0;
}
