/*
 * ResistorConnection.h
 *
 *  Created on: 04-Feb-2024
 *      Author: giris
 */

#ifndef RESISTORCONNECTION_H_
#define RESISTORCONNECTION_H_

#include <list>

#include "Resistor.h"

class ResistorConnection: public Resistor
{
protected:
	std::list<std::shared_ptr<Resistor>> resistors;

public:
	ResistorConnection(std::string name);
	virtual ~ResistorConnection();
	virtual char separator() const;
	std::string getName() const;
	ResistorConnection& operator+=(const std::shared_ptr<Resistor>& resistor);

	void write(std::ostream& out) override;
};

#endif /* RESISTORCONNECTION_H_ */
