/*
 * SerialResistorConnection.cpp
 *
 *  Created on: 04-Feb-2024
 *      Author: giris
 */

#include "SerialResistorConnection.h"

using namespace std;

SerialResistorConnection::SerialResistorConnection(std::string name)
: ResistorConnection(name)
{
}

SerialResistorConnection::~SerialResistorConnection()
{
}

char SerialResistorConnection::separator() const
{
	return '-';
}

float SerialResistorConnection::nominalValue() const
{
	float value = 0;

	for(auto& itr : this->resistors)
	{
		value = value + itr.get()->nominalValue();
	}

	return value;
}

float SerialResistorConnection::minimumValue() const
{
	float value = 0;

	for(auto itr = this->resistors.begin(); itr != this->resistors.end(); itr++)
	{
		value = value + (*itr).get()->minimumValue();
	}

	return value;
}

float SerialResistorConnection::maximumValue() const
{
	float value = 0;

	for(auto itr = this->resistors.begin(); itr != this->resistors.end(); itr++)
	{
		value = value + (*itr).get()->maximumValue();
	}

	return value;
}
