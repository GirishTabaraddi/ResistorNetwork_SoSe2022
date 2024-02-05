/*
 * ResistorReader.h
 *
 *  Created on: 04-Feb-2024
 *      Author: giris
 */

#ifndef RESISTORREADER_H_
#define RESISTORREADER_H_

#include "ResistorPart.h"
#include "SerialResistorConnection.h"
#include "ParallelResistorConnection.h"

#include <boost/algorithm/string.hpp>

#include <map>

class ResistorReader
{
public:
	ResistorReader();
	virtual ~ResistorReader();

	void read(std::istream& in, std::map<std::string, ResistorPtr>& found);
};

#endif /* RESISTORREADER_H_ */
