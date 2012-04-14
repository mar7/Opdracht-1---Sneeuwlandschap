/*
 * SneeuwMan.cpp
 *
 *  Created on: 27 feb. 2012
 *      Author: Marijn
 */

#include "SneeuwMan.hpp"
#include <ma.h>

SneeuwMan::SneeuwMan(int positieX, int positieY) {

	this->positieX = positieX;
	this->positieY = positieY;
}

SneeuwMan::~SneeuwMan() {
	// TODO Auto-generated destructor stub
}


void SneeuwMan::draw()
{
	maSetColor( 0xdcdcdc ); // maak de kleur grijs
	maFillRect( this->positieX, this->positieY, 30, 30 ); // teken onderkant sneeuwman
	maFillRect( this->positieX + 5, this->positieY - 20, 20, 20 ); // teken bovenkant sneeuwman

}

void SneeuwMan::move(int richting)
{
	this->positieX += richting; // verander de positie
}

int SneeuwMan::getXpositie()
{
	return positieX;
}
