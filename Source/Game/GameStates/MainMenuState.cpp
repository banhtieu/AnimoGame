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
#include "InGameState.h"


void MainMenuState::Init()
{
  bgSprite = new Sprite();
  bgSprite->LoadSprite("MainMenuBG");
  
  menuSprite = new Sprite();
  menuSprite->LoadSprite("MenuBar");
  
  stringManager = new StringManager();
  stringManager->Load("strings.en.bin");
  stringManager->SetColor(Color(0.0f, 0.0f, 0.0f, 1.0f));
  
  numMenuItems = 0;
  
  //achivement button
  menuList[numMenuItems] = new MenuInstance(200, 595, menuSprite->GetModuleWidth(M_OPTION), menuSprite->GetModuleHeight(M_OPTION));
  menuList[numMenuItems++]->id = M_OPTION;
  
  // menu options
  menuList[numMenuItems] = new MenuInstance(155, 655,menuSprite->GetModuleWidth(M_ABOUT_US), menuSprite->GetModuleHeight(M_ABOUT_US));
  menuList[numMenuItems++]->id = M_ABOUT_US;

  // menu options
  menuList[numMenuItems] = new MenuInstance(155, 655, menuSprite->GetModuleWidth(M_ABOUT_US), menuSprite->GetModuleHeight(M_ABOUT_US));
  menuList[numMenuItems++]->id = M_ABOUT_US;


/*  menuList[numMenuItems] = new MenuInstance(90, 732, menuSprite->GetModuleWidth(M_ACHIEVEMENTS), menuSprite->GetModuleHeight(M_ACHIEVEMENTS));
  menuList[numMenuItems]->id = M_ACHIEVEMENTS; */

  playX = 25;
  playY = 430;

  
}

void MainMenuState::Render(Graphics2D *g)
{
  bgSprite->DrawModule(0, 0, 0);
  
  for( int i = 0; i < numMenuItems; i++)
  {
     if(menuList[i]->isPressed())
    {
      switch (menuList[i]->id) {
        case M_ANIMAL_PLAY:
          Application::GetInstance()->SwitchState(new InGameState());
        default:
          break;
      }
    }
    else if(menuList[i]->isTouching())
    {
        menuSprite->DrawModule(menuList[i]->id + 1, menuList[i]->x, menuList[i]->y);      
    }
    
    else
    {
      menuSprite->DrawModule(menuList[i]->id, menuList[i]->x, menuList[i]->y);
    }
    
  }
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
