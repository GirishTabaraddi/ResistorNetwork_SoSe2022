/*
 * SerialResistorConnection.h
 *
 *  Created on: 04-Feb-2024
 *      Author: giris
 */

#ifndef SERIALRESISTORCONNECTION_H_
#define SERIALRESISTORCONNECTION_H_

#include "ResistorConnection.h"

class SerialResistorConnection: public ResistorConnection
{
public:
	SerialResistorConnection(std::string name);
	virtual ~SerialResistorConnection();
	char separator() const override;
	float nominalValue() const;
	float minimumValue() const;
	float maximumValue() const;
};

#endif /* SERIALRESISTORCONNECTION_H_ */
