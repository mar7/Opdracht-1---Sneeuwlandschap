/*
 * SneeuwLandschap.cpp
 *
 *  Created on: 8 feb. 2012
 *      Author: acer, Marijn
 */

#include "SneeuwLandschap.hpp"

//globale variabelen voor breedte en hoogte van het scherm
int screenWidth;
int screenHeight;

//constructor
SneeuwLandschap::SneeuwLandschap()
{
	//sla schermgrootte op in globale variabelen
	MAExtent screenSize = maGetScrSize();
	screenWidth = EXTENT_X( screenSize );
	screenHeight = EXTENT_Y( screenSize );

	//stel sneeuwhoogte in (vanaf bodem)
	this->sneeuwHoogte = 30;

	//maak een nieuwe sneeuwman
	this->sneeuwMan = new SneeuwMan( screenWidth / 2, screenHeight - this->sneeuwHoogte - 30 );

	//MAUtil::Environment::getEnvironment().addTimer(this, 40, 0);
}

//wordt aangeroepen als er input is (druk op de toets, touch van scherm)
void SneeuwLandschap::run( MAEvent event )
{
	//als er een key is ingetoetst
	if( event.type == EVENT_TYPE_KEY_PRESSED )
	{
		//pak de key code
		int key = maGetKeys();

		//kijk voor linkertoets
		if( key == MAKB_LEFT && sneeuwMan->getXpositie() > 0 )
			this->sneeuwMan->move( -6 );	//beweeg sneeuwman -6 pixels

		//kijk voor rechtertoets
		if( key == MAKB_RIGHT && sneeuwMan->getXpositie() < screenWidth - 30 )
			this->sneeuwMan->move( 6 );		//beweeg sneeuwman 6 pixels
	}

	// wacht 40 ms
	maWait(40);

	// maak sneeuwvlok
	createSnow();

	// laat alle sneeuwvlokken vallen
	for (int i = 0; i < sneeuwVlokArray.size(); i++)
	{
		sneeuwVlokArray[i]->fall(screenHeight - this->sneeuwHoogte);

		if(sneeuwVlokArray[i]->isDead()) // verwijderen als sneeuwvlok op grond is
		{
			SneeuwVlok* dood = sneeuwVlokArray[i];
			sneeuwVlokArray.remove(i);
			delete dood;
		}
	}
}

//wordt elke "tick" aangeroepen om het winterlandschap, sneeuwman en sneeuwvlokken te tekenen
void SneeuwLandschap::draw()
{
	//kleur de lucht blauw
	maSetColor( 0x0055ff );
	maFillRect( 0, 0, screenWidth, screenHeight );

	//maak sneeuw op de grond, a.d.h.v. sneeuwHoogte
	maSetColor( 0xffffff );
	maFillRect( 0, screenHeight - this->sneeuwHoogte, screenWidth, this->sneeuwHoogte );

	// teken de sneeuwman
	this->sneeuwMan->draw();

	//teken alle sneeuwvlokken
	for (int i = 0; i < sneeuwVlokArray.size(); i++)
	{
		sneeuwVlokArray[i]->draw();
	}
}

void SneeuwLandschap::createSnow()
{
	// maak willekeurige x-positie
	int xpositie = rand() % screenWidth;

	// maak nieuwe sneeuwvlok
	SneeuwVlok* sneeuwVlok = new SneeuwVlok(xpositie, 0);

	// voeg sneeuwvlok toe aan array
	sneeuwVlokArray.add(sneeuwVlok);
}
