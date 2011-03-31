/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/


#pragma once

#include <boost/shared_ptr.hpp>

#include "App.h"
#include "Game.h"
#include "Settings.h"
#include "Logger.h"
#include "Object.h"
#include "Sprite.h"

using boost::shared_ptr;

#define NUMOFMAPTEX 10

class Sprite;

class BckgrObj :
	public Object
{
public:
    BckgrObj(shared_ptr<sf::RenderWindow> buffer, int os);

    void draw();
    void draw(int ix, int iy, int obj=3, int type=1);
    void draw(int ix, int iy, int obj, int type, int alp);

    virtual void reset( int /* ix */, int /* iy */) { }
    virtual void update(int /* time */) { }

    bool loadTextures(std::string path);

    void setSpecialSpawned(bool b) { specialspawned = b; }
    void setSpecialEaten(bool b) { specialeaten = b; }

    int getObjCount() {	return objcounter;	}

    void setFruitAlpha(int a);

private:
    shared_ptr<Sprite>
            mapEl[NUMOFMAPTEX],
            objEl[NUMOFMAPTEX],
            mapElRot[NUMOFMAPTEX][3];

    int
            objcounter,
            fruitalpha;

    bool
            specialspawned,
            specialeaten;
};
