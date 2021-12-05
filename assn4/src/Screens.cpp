#include "Screens.h"

void Screens::main_menu()
{
  // SDL_RenderClear(my_renderer);

  // SDL_Rect fill_the_screen;
  // fill_the_screen.x = 0;
  // fill_the_screen.y = 0;
  // fill_the_screen.w = 700;
  // fill_the_screen.h = 700;

  // SDL_SetRenderDrawColor(my_renderer, 0, 0, 0, 255);
  // SDL_RenderDrawRect(my_renderer, &fill_the_screen);
  // SDL_RenderFillRect(my_renderer, &fill_the_screen);
}
    
void Screens::render_death_screen(SDL_Renderer* my_renderer)
{
  SDL_Surface* gameOverSurface = TTF_RenderText_Solid(ethnocentic, "Game Over!!!", black);
  
  cout<<"BAAAAA"<<endl;
  
  SDL_Rect GameOverDest = { 300, 300, gameOverSurface->w, gameOverSurface->h };

  SDL_Texture* texture = SDL_CreateTextureFromSurface(my_renderer, gameOverSurface);

  SDL_RenderCopy(my_renderer, texture, &GameOverDest, NULL);

  SDL_DestroyTexture(texture);
  SDL_FreeSurface(gameOverSurface);
  TTF_CloseFont(ethnocentic);

}
