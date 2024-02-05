/*
 * ResistorPart.cpp
 *
 *  Created on: 04-Feb-2024
 *      Author: giris
 */

#include "ResistorPart.h"

using namespace std;

ResistorPart::ResistorPart(std::string name, float value, float tolerance)
: Resistor(name), value(value), tolerance(tolerance)
{
}

ResistorPart::~ResistorPart()
{
}

float ResistorPart::nominalValue() const
{
	return this->value;
}

float ResistorPart::minimumValue() const
{
	return (this->value - (this->tolerance));
}

float ResistorPart::maximumValue() const
{
	return (this->value + (this->tolerance));
}

void ResistorPart::write(std::ostream &out)
{
	out << this->getName() << ";" << this->value << ";" << (this->tolerance) << endl;
}

ResistorPtr ResistorPart::from(std::string line)
{
	auto pos = line.find(';');

	string name = line.substr(0, pos);

	line.erase(0, pos+1);

	auto nextPos = line.find(';');

	float value = stof(line.substr(0, nextPos));

	float tolerance = stof(line.substr(nextPos+1));

	return make_shared<ResistorPart>(name, value, tolerance);
}