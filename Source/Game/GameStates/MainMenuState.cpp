//
//  MainMenuState.cpp
//  AnimoGame
//
//  Created by Quang Phan on 13/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//


#include "MainMenuState.h"
#include "MenuBar.h"
#include "ExportedStrings.h"

void MainMenuState::Init()
{
  bgSprite = new Sprite();
  bgSprite->LoadSprite("MainMenuBG");
  
  menuSprite = new Sprite();
  menuSprite->LoadSprite("MenuBar");
  
  stringManager = new StringManager();
  stringManager->Load("strings.en.bin");
  stringManager->SetColor(Color(0.0f, 0.0f, 0.0f, 1.0f));
}

void MainMenuState::Render(Graphics2D *g)
{
  bgSprite->DrawModule(0, 0, 0);
 
  for(int i=0; i<3; i++)
  {
    menuSprite->DrawModule(i*2, 40, SCREEN_HD2 -20 + 100*i);
    stringManager->Draw(STR_MENU_PLAY+i, SCREEN_WD2 - 80, SCREEN_HD2 + 100*i);

  }
  menuSprite->DrawModule(M_ABOUT_BTN, SCREEN_W - 180, SCREEN_H - 180);
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
