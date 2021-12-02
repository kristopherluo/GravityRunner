#include "Screens.h"

void Screens::main_menu()
{

}
    
void Screens::render_death_screen(SDL_Renderer* my_renderer)
{
  SDL_RenderClear(my_renderer);

  SDL_Rect fill_the_screen;
  fill_the_screen.x = 0;
  fill_the_screen.y = 0;
  fill_the_screen.w = 700;
  fill_the_screen.h = 700;

  SDL_SetRenderDrawColor(my_renderer, 0, 0, 0, 255);
  SDL_RenderDrawRect(my_renderer, &fill_the_screen);
  SDL_RenderFillRect(my_renderer, &fill_the_screen);

}