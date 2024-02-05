/*
 * ParallelResistorConnection.h
 *
 *  Created on: 04-Feb-2024
 *      Author: giris
 */

#ifndef PARALLELRESISTORCONNECTION_H_
#define PARALLELRESISTORCONNECTION_H_

#include "ResistorConnection.h"

class ParallelResistorConnection: public ResistorConnection
{
public:
	ParallelResistorConnection(std::string name);
	virtual ~ParallelResistorConnection();
	char separator() const override;
	float nominalValue() const;
	float minimumValue() const;
	float maximumValue() const;
};

#endif /* PARALLELRESISTORCONNECTION_H_ */