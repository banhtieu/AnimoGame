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
#include "MainMenuState.h"
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
  if (TouchManager::GetInstance()->IsTouchUpInRect(0, 0, SCREEN_W, SCREEN_H))
  {
    Application::GetInstance()->SwitchState(new MainMenuState());
  }
}

void LogoState::Free()
{
    delete splashSprite;
}
