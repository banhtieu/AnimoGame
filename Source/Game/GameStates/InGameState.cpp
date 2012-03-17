//
//  InGameState.cpp
//  AnimoGame
//
//  Created by Tran Khiem on 3/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "InGameState.h"

/**
 * Init The In Game State
 **/
void InGameState::Init()
{
  animals = new Sprite();
  animals->LoadSprite("Animals");
}


/**
 * Update In Game State
 **/
void InGameState::Update()
{
  
}


/**
 * Update In Game State
 **/
void InGameState::Render(Graphics2D *g)
{
  g->SetColor(Color(1.0f, 0.0f, 0.0f, 1.0f));
  for (int i = 0; i < 6; i++)
  {
    animals->DrawModule(i, i * 105, 10);
  }
}


/**
 * Free In Game State
 **/
void InGameState::Free()
{
  
}
