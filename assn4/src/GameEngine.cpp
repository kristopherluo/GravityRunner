#include "GameEngine.h"

GameEngine::GameEngine(SDL_Renderer* ren){
  obj_renderer = ren;
  screen_width = 640;
  screen_height = 480;
  game_is_running = true;
  this_start_time = SDL_GetTicks();
  fps = 60;
  frame_duration = 1000/fps;
  collectible_rect_x = -300;
  collectible_rect_y = 0;
  key_down = false;
}

GameEngine::~GameEngine(){}

void GameEngine::obj_init(){
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0){ 
    cout << "Error initializing SDL: " << SDL_GetError() << endl; 
  }

  //Enable gpu_enhanced textures
  IMG_Init(IMG_INIT_PNG);
  
  obj_window = SDL_CreateWindow("my_game", 
			       SDL_WINDOWPOS_CENTERED, 
			       SDL_WINDOWPOS_CENTERED, 
			       screen_width,
			       screen_height, 0);
  obj_renderer = SDL_CreateRenderer(obj_window,-1,0);

  SDL_SetRenderDrawColor(obj_renderer, 135, 206, 235, 255); //displays color of sky (sky blue)

  SDL_RenderClear(obj_renderer);

  SDL_Surface* temp = IMG_Load("./images/sprite_idle.png"); //imports all the .png's needed and calls the serve_texture functions of the PlayerSprite and
  sprite.sprite_serve_texture_idle(temp, obj_renderer);     //TileHandler classes to import them
  SDL_FreeSurface(temp);

  temp = IMG_Load("./images/sprite_run.png");
  sprite.sprite_serve_texture_run(temp, obj_renderer);
  SDL_FreeSurface(temp);
  
  temp = IMG_Load("./images/background_tile.png");
  tile.tile_serve_texture(temp, obj_renderer, 0);
  SDL_FreeSurface(temp);

  temp = IMG_Load("./images/ground_tile1.png");
  tile.tile_serve_texture(temp, obj_renderer, 1);
  SDL_FreeSurface(temp);

  temp = IMG_Load("./images/ground_tile2.png");
  tile.tile_serve_texture(temp, obj_renderer, 2);
  SDL_FreeSurface(temp);

  temp = IMG_Load("./images/spikes.png");
  int i;
  for(i = 0; i < 3; i++){                                           //for loop that serves in the collectible texture to 3 instances of the Collectible class
    collectible[i].collectible_serve_texture(temp, obj_renderer);
    collectible[i].collectible_set_rect_w(64);
    collectible[i].collectible_set_rect_h(25);
  }
  SDL_FreeSurface(temp);
}

void GameEngine::obj_updateUI(){
  while (SDL_PollEvent(&obj_event)){
    if (obj_event.type == SDL_QUIT) game_is_running = false; //quits game is user presses X
  }
  const Uint8 *state = SDL_GetKeyboardState(NULL);
  if(state[SDL_SCANCODE_SPACE]){
    if(!key_down){
      sprite.sprite_change_gravity();
    }
    key_down = true;
    tile.tile_update_screen_left(-1 * player.player_get_vel());
  }else{
    key_down = false;
    sprite.sprite_set_state(1);
    tile.tile_update_screen_left(-1 * player.player_get_vel());
  }
  SDL_Delay(50);
}

void GameEngine::obj_update(){
  /*for(int i = 0; i < 5; i++){ //collectible collision detection
    if(player.player_get_pos_x() <= collectible[i].collectible_get_x_pos() - 25 && player.player_get_pos_x() >= collectible[i].collectible_get_x_pos() - 40 && !collectible[i].collectible_collected()){
      particle_emit.particle_emitter_init("./images/collectible.png", obj_renderer, collectible[i].collectible_get_x_pos(), collectible[i].collectible_get_y_pos() - 10, 15, 15, 1);
      collectible[i].collectible_destroy();
      collectible[i].collectible_set_collected();
    }
  }*/
  //player.player_set_pos_x(player.player_get_pos_x() + player.player_get_vel());

  //particle_emit.particle_emitter_update();
  if(sprite.sprite_get_gravity_state()){ //if sprite is changing gravity
    sprite.sprite_set_state(0);
    if(sprite.sprite_get_direction()){ //player is normal oriented, changing gravity back toward the bottom ground
      if(player.player_get_pos_y() < 320){ //ensures player stops changing gravity once it reaches the top ground
        player.player_set_pos_y(player.player_get_pos_y() + player.player_get_vel());
      }else{
        sprite.sprite_set_gravity_change();
      }
    }else if(!sprite.sprite_get_direction()){ //player is upside down, changing gravity toward the top ground
      if(player.player_get_pos_y() > 70){ //ensures player stops changing gravity once it reaches the bottom ground
        player.player_set_pos_y(player.player_get_pos_y() - player.player_get_vel());
      }else{
        sprite.sprite_set_gravity_change();
      }
    }
  }

  for(int i = 0; i < 3; i++){ //for loop that updates the collectible/obstacles
    int num = rand() % 3;
    int section_x_pos = 640;
    bool available = true;

    if(collectible[i].collectible_get_x_pos() >= -64){ //changes obstacle position
        collectible[i].collectible_change_rect_x(-10);
    }else{  //if off screen, recycle to create "new" obstacle
      switch(num){
        case 0:
          break;
        case 1: //sets obstacle to the bottom ground
          for(int j = 0; j < 3; j++){ //ensures no obstacles overlap
            if(collectible[j].collectible_get_x_pos() > (screen_width - 64)){
              available = false;
            }
          }
          if(available){
            collectible[i].collectible_set_rect_x(section_x_pos);
            collectible[i].collectible_set_rect_y(385);
            collectible[i].collectible_set_type(1); //sets the type to bottom
          }
          break;
        case 2: //sets obstacle to the top ground
          for(int j = 0; j < 3; j++){
            if(collectible[j].collectible_get_x_pos() > (screen_width - 64)){
              available = false;
            }
          }
          if(available){
            collectible[i].collectible_set_rect_x(section_x_pos);
            collectible[i].collectible_set_rect_y(70);
            collectible[i].collectible_set_type(3); //sets the type to bottom
          }
          break;
      }
    }
  }

  sprite.sprite_set_rect_x(player.player_get_pos_x());
  sprite.sprite_set_rect_y(player.player_get_pos_y());
  sprite.sprite_update_frame();
}

void GameEngine::obj_render(){
  SDL_RenderClear(obj_renderer);

  tile.tile_render(obj_renderer); //renders the tiles

  for(int i = 0; i < 3; i++){ //renders all collectibles/obstacles
    if(collectible[i].collectible_get_x_pos() > -100){
      collectible[i].collectible_render(obj_renderer);
    }
  }

  sprite.sprite_render(obj_renderer); //renders the sprite

  particle_emit.particle_emitter_draw(obj_renderer);

  SDL_RenderPresent(obj_renderer);

  //delays the game loop if this loop duration has not reached the desired framed duration yet
  this_duration = SDL_GetTicks() - this_start_time;
  if(this_duration < frame_duration){
      SDL_Delay(frame_duration - this_duration);
  }
}

void GameEngine::obj_quit(){
  SDL_DestroyRenderer(obj_renderer);
  SDL_DestroyWindow(obj_window); 
  IMG_Quit();
  SDL_Quit();
}
