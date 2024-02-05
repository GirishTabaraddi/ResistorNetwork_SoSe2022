/*
 * Resistor.h
 *
 *  Created on: 04-Feb-2024
 *      Author: giris
 */

#ifndef RESISTOR_H_
#define RESISTOR_H_


#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <memory>

class Resistor
{
private:
	std::string name;

public:
	Resistor(std::string name);
	virtual ~Resistor();
	std::string getName() const;
	virtual float nominalValue() const = 0;
	virtual float minimumValue() const = 0;
	virtual float maximumValue() const = 0;
	std::string toString() const;

	virtual void write(std::ostream& out);
};

std::ostream& operator << (std::ostream& out, Resistor& rhs);

typedef std::shared_ptr<Resistor> ResistorPtr;

#endif /* RESISTOR_H_ */
