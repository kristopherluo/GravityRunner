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

  /*temp = IMG_Load("./images/collectible.png");
  int i;
  for(i = 0; i < 5; i++){                                       //for loop that serves in the collectible texture to 5 instances of the
    collectible[i].collectible_serve_texture(temp, obj_renderer);   //Collectible class. Sets the SDL_Rect for each to be different
    collectible[i].collectible_set_rect_x(collectible_rect_x);
    collectible_rect_x += 300;
  }
  SDL_FreeSurface(temp);

  temp = IMG_Load("./images/box_collectible.png");
  for(i = 5; i < 8; i++){
    collectible[i].collectible_set_rect_x(575);
    collectible[i].collectible_serve_texture(temp, obj_renderer);
    collectible[i].collectible_set_rect_y(collectible_rect_y);
    collectible_rect_y -= 25;
  }

  collectible_rect_y = 0;
  for(i = 8; i < 10; i++){
    collectible[i].collectible_set_rect_x(-500);
    collectible[i].collectible_serve_texture(temp, obj_renderer);
    collectible[i].collectible_set_rect_y(collectible_rect_y);
    collectible_rect_y -= 25;
  }
  SDL_FreeSurface(temp);*/
}

void GameEngine::obj_updateUI(){
  while (SDL_PollEvent(&obj_event)){
    if (obj_event.type == SDL_QUIT) game_is_running = false; //quits game is user presses X
    /*switch(obj_event.type ){
      case SDL_KEYDOWN:
        if(key_down){
          sprite.sprite_set_state(0);
          sprite.sprite_change_gravity();
        }
        key_down = true;
        break;
      case SDL_KEYUP:
        key_down = false;
        break;
      default:
        sprite.sprite_set_state(1);
        tile.tile_update_screen_left(-1 * player.player_get_vel());
        break;
    }*/
  }

  const Uint8 *state = SDL_GetKeyboardState(NULL);
  /*if(state[SDL_SCANCODE_LEFT]){
    sprite.sprite_set_state(1); //sets sprite state to run (1)
    if(sprite.sprite_get_direction() != 0){ //only runs the next 2 lines if the direction the sprite is facing is right
      sprite.sprite_set_direction(0); //sets the direction the sprite is facing to left
      player.player_set_pos_x(player.player_get_pos_x() - (player.player_get_vel()*5)); //changes player position to create a smoother change of direction
    }
    if(tile.tile_reach_screen_end()){ //if the screen has reached the edge, player position will be moved
      //if(!(player.player_get_pos_x() + 25 <= collectible[8].collectible_get_x_pos())){ //COLLISION DECTECTION: Only changes the x_pos of the player if not next to boxes
        player.player_set_pos_x(player.player_get_pos_x() - player.player_get_vel());
        if(player.player_get_pos_x() == screen_width/2 - (sprite.sprite_get_width()/2)){ //if the player goes back to the center of the screen, 
          tile.tile_update_screen_left(player.player_get_vel());                                                       //camera view will move rather than player position
        }
      //}
    }else{ //only screen moves if the screen has not reached the edge
      //if(!(player.player_get_pos_x() <= collectible[8].collectible_get_x_pos() + 25)){ //COLLISION DECTECTION: Only changes x_pos of background and collectibles
        //cout << player.player_get_pos_x() << endl;                                   //if not next to the boxes
        tile.tile_update_screen_left(player.player_get_vel());
        for(int i = 0; i < 10; i++){
          collectible[i].collectible_set_rect_x(player.player_get_vel());
        }
      //}
    }
  }
  else if(state[SDL_SCANCODE_RIGHT]){
    sprite.sprite_set_state(1); //sets sprite state to run (1)
    if(sprite.sprite_get_direction() != 1){ //only runs the next 2 lines if the direction the sprite is facing is left
      sprite.sprite_set_direction(1); //sets the direction the sprite is facing to right
      player.player_set_pos_x(player.player_get_pos_x() + (player.player_get_vel()*5)); //changes player position to create a smoother change of direction
    }
    if(tile.tile_reach_screen_end()){ //if the screen has reached the edge, player position will be moved
      player.player_set_pos_x(player.player_get_pos_x() + player.player_get_vel());
      if(player.player_get_pos_x() == screen_width/2 - sprite.sprite_get_width()/2){ //if the player goes back to the center of the screen, 
        tile.tile_update_screen_left(-1 * player.player_get_vel());                  //camera view will move rather than player position
      }
    }else{ //only screen moves if the screen has not reached the edge
      //if(!(player.player_get_pos_x() >= collectible[5].collectible_get_x_pos() - 49)){ //COLLISION DECTECTION: Only changes x_pos of background and collectibles
        tile.tile_update_screen_left(-1 * player.player_get_vel());                    //if not next to the boxes
        for(int i = 0; i < 10; i++){
          collectible[i].collectible_set_rect_x(-1 * player.player_get_vel());
        }
      //}
    }
  }else{
    sprite.sprite_set_state(0); //sets sprite state to idle (0)
  }*/

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
  /*if(player.player_get_pos_x() > screen_width - sprite.sprite_get_width()) player.player_set_pos_x(player.player_get_pos_x() - player.player_get_vel());
  if(player.player_get_pos_x() < 0) player.player_set_pos_x(player.player_get_pos_x() + player.player_get_vel());
  if(player.player_get_pos_y() > screen_height - sprite.sprite_get_height()) player.player_set_pos_y(player.player_get_pos_y() - player.player_get_vel());
  if(player.player_get_pos_y() < 0) player.player_set_pos_y(player.player_get_pos_y() + player.player_get_vel());*/

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

  sprite.sprite_set_rect_x(player.player_get_pos_x());
  sprite.sprite_set_rect_y(player.player_get_pos_y());
  sprite.sprite_update_frame();
}

void GameEngine::obj_render(){
  SDL_RenderClear(obj_renderer);

  tile.tile_render(obj_renderer); //renders the tiles

  for(int i = 0; i < 10; i++){
    collectible[i].collectible_render(obj_renderer); //renders all the collectibles
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
