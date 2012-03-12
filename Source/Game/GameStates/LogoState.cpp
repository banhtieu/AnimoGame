//
//  LogoState.cpp
//  GameEngine
//
//  Created by Tran Khiem on 2/21/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "LogoState.h"
//#include "BackgroundData.h"
#include "Splash.h"

void LogoState::Init()
{
  splashSprite = new Sprite();
  splashSprite->LoadSprite("Splash");
}

void LogoState::Render(Graphics2D *g)
{
  splashSprite->DrawModule(M_SPLASH, 0, 0);
};

void LogoState::Update()
{
}

void LogoState::Free()
{
    delete splashSprite;
}
