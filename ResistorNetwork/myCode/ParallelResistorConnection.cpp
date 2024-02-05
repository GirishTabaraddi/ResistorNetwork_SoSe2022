/*
 * ParallelResistorConnection.cpp
 *
 *  Created on: 04-Feb-2024
 *      Author: giris
 */

#include "ParallelResistorConnection.h"

using namespace std;

ParallelResistorConnection::ParallelResistorConnection(std::string name)
: ResistorConnection(name)
{
}

ParallelResistorConnection::~ParallelResistorConnection()
{
}

char ParallelResistorConnection::separator() const
{
	return '|';
}

float ParallelResistorConnection::nominalValue() const
{
	float numerator = 1;
	float denominator = 0;
	float value = 0;

	for(auto itr = this->resistors.begin(); itr != this->resistors.end(); itr++)
	{
		denominator = denominator + (*itr).get()->nominalValue();
		numerator = numerator * (*itr).get()->nominalValue();
	}

	return (value = numerator/denominator);
}

float ParallelResistorConnection::minimumValue() const
{
	float numerator = 1;
	float denominator = 0;
	float value = 0;

	for(auto itr = this->resistors.begin(); itr != this->resistors.end(); itr++)
	{
		denominator = denominator + (*itr).get()->minimumValue();
		numerator = numerator * (*itr).get()->minimumValue();
	}

	return (value = numerator/denominator);
}

float ParallelResistorConnection::maximumValue() const
{
	float numerator = 1;
	float denominator = 0;
	float value = 0;

	for(auto itr = this->resistors.begin(); itr != this->resistors.end(); itr++)
	{
		denominator = denominator + (*itr).get()->maximumValue();
		numerator = numerator * (*itr).get()->maximumValue();
	}

	return (value = numerator/denominator);
}
