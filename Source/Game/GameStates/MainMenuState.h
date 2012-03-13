//
//  MainMenuState.h
//  AnimoGame
//
//  Created by Quang Phan on 13/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef AnimoGame_MainMenuState_h
#define AnimoGame_MainMenuState_h

#include "Engine.h"

#define NUM_MENU 7
class MainMenuState: public State, Singleton<MainMenuState>
{
public:
  virtual void Init();
  virtual void Render(Graphics2D *g);
  virtual void Update();
  virtual void Free();
protected:
  Sprite *bgSprite;
  Sprite *menuSprite;
  StringManager *stringManager;
  MenuInstance *menuList[NUM_MENU];
};



#endif
