//
//  MenuInstance.cpp
//  AnimoGame
//
//  Created by Quang Phan on 13/03/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

//#include "MenuInstance.h"
#include "Engine.h"


void sss()
{
  
}

bool MenuInstance::isPressed()
{
  if (TouchManager::GetInstance()->IsTouchInRect(x, y, w, h))
  {
    return true;    
  }
  return false;  
}

bool MenuInstance::isTouching()
{
  if (TouchManager::GetInstance()->IsTouchDownInRect(x, y, w, h))
  {
    return true;
  }
  return false;  
}