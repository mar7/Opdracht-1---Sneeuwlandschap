/*
 * SneeuwLandschap.hpp
 *
 *  Created on: 8 feb. 2012
 *      Author: acer
 */

#ifndef SNEEUWLANDSCHAP_HPP_
#define SNEEUWLANDSCHAP_HPP_


#include <mastdlib.h>
#include <ma.h>

#include <MAUtil/Vector.h>
#include <MAUtil/Environment.h>


#include "SneeuwMan.hpp"
#include "SneeuwVlok.hpp"

class SneeuwLandschap
{
private:
	int sneeuwHoogte;
	SneeuwMan* sneeuwMan;

	MAUtil::Vector<SneeuwVlok*> sneeuwVlokArray;

public:
	SneeuwLandschap();
	void draw();
	void run( MAEvent event );
	void createSnow();

};

#endif /* SNEEUWLANDSCHAP_HPP_ */
