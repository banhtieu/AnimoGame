//
//  MainMenuState.cpp
//  AnimoGame
//
//  Created by Quang Phan on 13/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//


#include "MainMenuState.h"
//#include "BackgroundData.h"


void MainMenuState::Init()
{
  bgSprite = new Sprite();
  bgSprite->LoadSprite("MainMenuBG");
}

void MainMenuState::Render(Graphics2D *g)
{
  bgSprite->DrawModule(0, 0, 0);
};

void MainMenuState::Update()
{
  if (TouchManager::GetInstance()->IsTouchInRect(0, 0, SCREEN_W, SCREEN_H))
  {
    
  }
}

void MainMenuState::Free()
{
  delete bgSprite;
}
