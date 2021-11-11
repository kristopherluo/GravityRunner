#include "GameEngine.h"

SDL_Renderer* my_renderer = NULL;

GameObject TheGameObject(my_renderer);

int main(){ 

  TheGameObject.obj_init();

  //Game Loop
  while(TheGameObject.game_is_running){
    TheGameObject.obj_updateUI();
    TheGameObject.obj_update();
    TheGameObject.obj_render();
  }

  TheGameObject.obj_quit();
  
  return 0; 
}
