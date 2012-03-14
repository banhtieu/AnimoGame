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
  g->DrawLine(0, SCREEN_H - 160, SCREEN_W, SCREEN_H - 160);
  g->SetColor(Color(0.0f, 0.0f, 0.0f, 1.0f));
  for (int i = 0; i <= 4; i++)
  {
    g->DrawRectangle(160 * i + 5, SCREEN_H - 155, 150, 150);
  }
}


/**
 * Free In Game State
 **/
void InGameState::Free()
{
  
}
