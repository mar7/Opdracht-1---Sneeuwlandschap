/*
 * SneeuwMan.hpp
 *
 *  Created on: 8 feb. 2012
 *      Author: acer
 */

#ifndef SNEEUWMAN_HPP_
#define SNEEUWMAN_HPP_


//bevat teken functies
#include <ma.h>

//de klasse SneeuwMan
class SneeuwMan
{
private:
	int positieX;	//x positie van sneeuwman
	int positieY;	//y positie van sneeuwman
	int richting;
	//SneeuwLandschap* sneeuwLandschap;

public:
	//constructor
	SneeuwMan( int positieX, int positieY );
	virtual ~SneeuwMan();

	//beweeg de sneeuwman in de richting "direcion", negatief getal is links, positief is rechts
	void move( int richting );

	//tekent een sneeuwman
	void draw();

	// haal xpositie op
	int getXpositie();
};


#endif /* SNEEUWMAN_HPP_ */
