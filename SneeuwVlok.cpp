/*
 * SneeuwVlok.cpp
 *
 *  Created on: 13 apr. 2012
 *      Author: Marijn
 */

#include "SneeuwVlok.hpp"
#include <ma.h>

SneeuwVlok::SneeuwVlok( int positionX, int positionY )
{
	this->positionX = positionX;
	this->positionY = positionY;
	dead = false; // sneeuwvlok niet op grond

	// grootte sneeuwvlok
	int sizemin = 2; // minimum grootte
	int sizemax = 8; // maximum grootte
	this->size = rand() % (sizemax - sizemin) + sizemin; // random grootte tussen min en max
}

SneeuwVlok::~SneeuwVlok()
{
	// destructor
}

void SneeuwVlok::draw()	//teken functie die een sneeuwvlok tekent
{
	maSetColor( 0xffffff ); // maak kleur wit
	maFillRect( this->positionX, this->positionY, this->size, this->size ); // vlokvierkant
}

void SneeuwVlok::fall( int groundLevel ) //functie die de y positie verandert
{
	if (this->positionY + 2 > groundLevel) // sneeuwvlok valt op grond?
	{
		this->dead = true; // op grond gevallen
	}
	else
	{
		this->positionY += 2; // valt verder
	}
}

bool SneeuwVlok::isDead() // geef terug wel/niet op grond gevallen
{
	return this->dead;
}

