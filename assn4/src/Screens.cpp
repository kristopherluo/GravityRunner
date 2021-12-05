#include "Screens.h"

Screens::Screens(){
  in_main_menu = true;
  restart_game = false;
  end_game = false;
  pause_game = false;
}

Screens::~Screens(){}

void Screens::main_menu(SDL_Renderer* obj_renderer)
{
  SDL_Rect fill_the_screen;
  fill_the_screen.x = 100;
  fill_the_screen.y = 100;
  fill_the_screen.w = 440;
  fill_the_screen.h = 280;

  SDL_SetRenderDrawColor(obj_renderer, 0, 0, 0, 255);
  SDL_RenderDrawRect(obj_renderer, &fill_the_screen);
  SDL_RenderFillRect(obj_renderer, &fill_the_screen);
  SDL_SetRenderDrawColor(obj_renderer, 135, 206, 235, 255);
}

void Screens::pause_menu(SDL_Renderer* obj_renderer){
  SDL_Rect fill_the_screen;
  fill_the_screen.x = 100;
  fill_the_screen.y = 100;
  fill_the_screen.w = 440;
  fill_the_screen.h = 280;

  SDL_SetRenderDrawColor(obj_renderer, 0, 0, 0, 255);
  SDL_RenderDrawRect(obj_renderer, &fill_the_screen);
  SDL_RenderFillRect(obj_renderer, &fill_the_screen);
  SDL_SetRenderDrawColor(obj_renderer, 135, 206, 235, 255);
}

    
void Screens::render_death_screen(SDL_Renderer* obj_renderer)
{
  //Game Over Box
  SDL_Rect fill_the_screen;
  fill_the_screen.x = 100;
  fill_the_screen.y = 100;
  fill_the_screen.w = 440;
  fill_the_screen.h = 280;

  SDL_SetRenderDrawColor(obj_renderer, 0, 0, 0, 255);
  SDL_RenderDrawRect(obj_renderer, &fill_the_screen);
  SDL_RenderFillRect(obj_renderer, &fill_the_screen);
  SDL_SetRenderDrawColor(obj_renderer, 135, 206, 235, 255);

  // Load in fonts and colors
  TTF_Font* ethnocenticItalic = TTF_OpenFont("./Fonts/ethnocentric rg it.ttf", 40);
  TTF_Font* ethnocentic = TTF_OpenFont("./Fonts/ethnocentric rg.ttf", 20);
  SDL_Color color = { 255, 255, 255 };

  // The words on screen for Game over

  SDL_Surface* gameOverSurface = TTF_RenderText_Solid(ethnocenticItalic, "Game Over!!!", color);
  SDL_Rect GameOverDest = { 100, 100, gameOverSurface->w, gameOverSurface->h };
  SDL_Texture* GameOvertexture = SDL_CreateTextureFromSurface(obj_renderer, gameOverSurface);
  SDL_RenderCopy(obj_renderer, GameOvertexture, NULL, &GameOverDest);


  SDL_Surface* gameOverRestart = TTF_RenderText_Solid(ethnocentic, "R - Restart", color);
  SDL_Rect RestartDest = { 100, 175, gameOverRestart->w, gameOverRestart->h };
  SDL_Texture* RestartTexture = SDL_CreateTextureFromSurface(obj_renderer, gameOverRestart);
  SDL_RenderCopy(obj_renderer, RestartTexture, NULL, &RestartDest);


  SDL_Surface* gameOverEnd = TTF_RenderText_Solid(ethnocentic, "E - Exit", color);
  SDL_Rect EndDest = { 100, 225, gameOverEnd->w, gameOverEnd->h };
  SDL_Texture* EndTexture = SDL_CreateTextureFromSurface(obj_renderer, gameOverEnd);
  SDL_RenderCopy(obj_renderer, EndTexture, NULL, &EndDest);


  // Clean Up
  SDL_FreeSurface(gameOverSurface);
  SDL_FreeSurface(gameOverRestart);
  SDL_FreeSurface(gameOverEnd);

  SDL_DestroyTexture(GameOvertexture);
  SDL_DestroyTexture(RestartTexture);
  SDL_DestroyTexture(EndTexture);

  TTF_CloseFont(ethnocenticItalic);
  TTF_CloseFont(ethnocentic);
}
