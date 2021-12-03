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
  fill_the_screen.x = 0;
  fill_the_screen.y = 0;
  fill_the_screen.w = 640;
  fill_the_screen.h = 480;

  SDL_SetRenderDrawColor(obj_renderer, 255, 255, 255, 255);
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
  SDL_Rect fill_the_screen;
  fill_the_screen.x = 0;
  fill_the_screen.y = 0;
  fill_the_screen.w = 640;
  fill_the_screen.h = 480;

  SDL_SetRenderDrawColor(obj_renderer, 0, 0, 0, 255);
  SDL_RenderDrawRect(obj_renderer, &fill_the_screen);
  SDL_RenderFillRect(obj_renderer, &fill_the_screen);
  SDL_SetRenderDrawColor(obj_renderer, 135, 206, 235, 255);
}