/*
 * ResistorReader.cpp
 *
 *  Created on: 04-Feb-2024
 *      Author: giris
 */

#include "ResistorReader.h"

using namespace std;

ResistorReader::ResistorReader()
{
}

ResistorReader::~ResistorReader()
{
}

void ResistorReader::read(std::istream &in,
		std::map<std::string, ResistorPtr> &found)
{
	string readLine;

	while(getline(in, readLine))
	{
		auto pos = readLine.find(";");

//		cout << readLine << endl;
		if(pos != string::npos)
		{
			string name = readLine.substr(0, pos);

//			cout << name << endl;
			if(boost::algorithm::icontains(name, "[") &&
					boost::algorithm::icontains(name, "-"))
			{
//				cout << "Series Resistor connection" << endl;

				auto brPos = readLine.find("[");
				string srConnName = readLine.substr(0, brPos);
				readLine.erase(0, brPos+1);

				auto dashPos = readLine.find("-");
				string srConn1 = readLine.substr(0, dashPos);
				readLine.erase(0, dashPos+1);

				auto brPos2 = readLine.find("]");
				string srConn2 = readLine.substr(0, brPos2);
				readLine.erase(0, brPos2+2);

//				cout << readLine << endl;
//
//				float value = stof(readLine.substr(0, readLine.find(";")));
//				float tolerance = stof(readLine.substr(readLine.find(";")+1));
//
//				cout << srConnName << " " << srConn1 << " " << srConn2 << " " << value << " " << tolerance << endl;

				SerialResistorConnection srConn(srConnName);

				srConn += found[srConn1];
				srConn += found[srConn2];

				found.erase(srConn1);
				found.erase(srConn2);

				found.insert(make_pair(srConn.getName(), make_shared<SerialResistorConnection>(srConn)));
			}
			else if(boost::algorithm::icontains(name, "[") &&
					boost::algorithm::icontains(name, "|"))
			{
//				cout << "Parallel Resistor connection" << endl;
				auto brPos = readLine.find("[");
				string prConnName = readLine.substr(0, brPos);
				readLine.erase(0, brPos+1);

				auto dashPos = readLine.find("|");
				string prConn1 = readLine.substr(0, dashPos);
				readLine.erase(0, dashPos+1);

				auto brPos2 = readLine.find("]");
				string prConn2 = readLine.substr(0, brPos2);
				readLine.erase(0, brPos2+2);

//				cout << readLine << endl;
//
//				float value = stof(readLine.substr(0, readLine.find(";")));
//				float tolerance = stof(readLine.substr(readLine.find(";")+1));
//
//				cout << prConnName << " " << prConn1 << " " << prConn2 << " " << value << " " << tolerance << endl;

				ParallelResistorConnection prConn(prConnName);

				prConn += found[prConn1];
				prConn += found[prConn2];

				found.erase(prConn1);
				found.erase(prConn2);

				found.insert(make_pair(prConn.getName(), make_shared<ParallelResistorConnection>(prConn)));
			}
			else
			{
//				cout << "Resistor Part" << endl;

				string resName = readLine.substr(0, pos);

				ResistorPart resistor(resName);

				ResistorPtr resData =  resistor.from(readLine);

				found.insert(make_pair(resName, resData));
			}
		}
	}
}
