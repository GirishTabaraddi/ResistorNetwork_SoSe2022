/*
 * ResistorPart.h
 *
 *  Created on: 04-Feb-2024
 *      Author: giris
 */

#ifndef RESISTORPART_H_
#define RESISTORPART_H_

#include "Resistor.h"

class ResistorPart: public Resistor
{
private:
	float value;
	float tolerance;

public:
	ResistorPart(std::string name, float value = 0, float tolerance = 0);
	virtual ~ResistorPart();

	float nominalValue() const override;
	float minimumValue() const override;
	float maximumValue() const override;

	void write(std::ostream& out) override;

	ResistorPtr from(std::string line);
};

#endif /* RESISTORPART_H_ */
