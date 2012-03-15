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
  
  //sound button
  menuList[0] = new MenuInstance(SCREEN_W - 90,10,menuSprite->GetModuleWidth(M_SOUND_BTN_ON),menuSprite->GetModuleHeight(M_SOUND_BTN_ON));
  menuList[0]->id = M_SOUND_BTN_ON;
  
  //play button
  menuList[1] = new MenuInstance(40,SCREEN_HD2 - 20,menuSprite->GetModuleWidth(M_PLAY_BTN),menuSprite->GetModuleHeight(M_PLAY_BTN));
  menuList[1]->id = M_PLAY_BTN;
  
  //achivement button
  menuList[2] = new MenuInstance(40,SCREEN_HD2 - 20 + 100,menuSprite->GetModuleWidth(M_ACHIVEMENT_BTN),menuSprite->GetModuleHeight(M_ACHIVEMENT_BTN));
  menuList[2]->id = M_ACHIVEMENT_BTN;
  
  //highscore button
  menuList[3] = new MenuInstance(40,SCREEN_HD2 - 20 + 200,menuSprite->GetModuleWidth(M_HIGHSCORE_BTN),menuSprite->GetModuleHeight(M_HIGHSCORE_BTN));
  menuList[3]->id = M_HIGHSCORE_BTN;
  
  //EN lang button
  menuList[4] = new MenuInstance(40,SCREEN_H - 130,menuSprite->GetModuleWidth(M_EN_LANG_BTN),menuSprite->GetModuleHeight(M_EN_LANG_BTN));
  menuList[4]->id = M_EN_LANG_BTN;
  
  //VN lang button
  menuList[5] = new MenuInstance(180,SCREEN_H - 130,menuSprite->GetModuleWidth(M_VN_LANG_BTN),menuSprite->GetModuleHeight(M_VN_LANG_BTN));
  menuList[5]->id = M_VN_LANG_BTN;

  //about button
  menuList[6] = new MenuInstance(SCREEN_W - 180,SCREEN_H - 180,menuSprite->GetModuleWidth(M_ABOUT_BTN),menuSprite->GetModuleHeight(M_ABOUT_BTN));
  menuList[6]->id = M_ABOUT_BTN;


  
}

void MainMenuState::Render(Graphics2D *g)
{
  bgSprite->DrawModule(0, 0, 0);
  
  for( int i=0; i<NUM_MENU; i++)
  {
     if(menuList[i]->isPressed())
    {
      switch (menuList[i]->id) {
        case M_SOUND_BTN_ON:
          Application::GetInstance()->isSoundOn = false;
          menuList[i]->id = M_SOUND_BTN_OFF;
          menuSprite->DrawModule(menuList[i]->id, menuList[i]->x, menuList[i]->y); 
          break;
        case M_SOUND_BTN_OFF:
          Application::GetInstance()->isSoundOn = true;
          menuList[i]->id = M_SOUND_BTN_ON;
          menuSprite->DrawModule(menuList[i]->id , menuList[i]->x, menuList[i]->y); 
          break;
        case M_EN_LANG_BTN:
          Application::GetInstance()->curLanguage = 0;
          break;
        case M_VN_LANG_BTN:
          Application::GetInstance()->curLanguage = 1;
          break;
        case M_PLAY_BTN:
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
      if(Application::GetInstance()->curLanguage == 0)
      {
        menuSprite->DrawModule(menuList[4]->id + 1, menuList[4]->x, menuList[4]->y);
      }
      else {
        menuSprite->DrawModule(menuList[5]->id + 1, menuList[5]->x, menuList[5]->y);
      }
    }
    
  }
  
  
  for(int i=0; i<3; i++)
  {
    stringManager->Draw(STR_MENU_PLAY+i, SCREEN_WD2 - 80, SCREEN_HD2 + 100*i);
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
