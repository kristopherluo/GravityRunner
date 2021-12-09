#include "GameEngine.h"

GameEngine::GameEngine(SDL_Renderer* ren){
  screen_width = 640;
  screen_height = 480;

  fps = 70;
  frame_duration = 1000/fps;

  obstacle_rect_x = -300;
  obstacle_rect_y = 0;

  score = 0;
  
  lasers = 3;
  total_cases = 2;

  for(int i = 0; i < 5; i++){
    counter[i] = 0;
  }

  key_down = false;

  player_alive = true;
  game_is_running = true;

  obj_renderer = ren;

  for(int i = 0; i < 12; i++){
    laser_end_rect[i].x = 0;
    laser_end_rect[i].y = 0;
    laser_end_rect[i].w = 25;
    laser_end_rect[i].h = 25;
  }
}

GameEngine::~GameEngine(){}

void GameEngine::obj_init(){
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0){ 
    cout << "Error initializing SDL: " << SDL_GetError() << endl; 
  }

  TTF_Init();

  //Enable gpu_enhanced textures
  IMG_Init(IMG_INIT_PNG);
  
  obj_window = SDL_CreateWindow("Gravity Runner", 
			       SDL_WINDOWPOS_CENTERED, 
			       SDL_WINDOWPOS_CENTERED, 
			       screen_width,
			       screen_height, 0);
  obj_renderer = SDL_CreateRenderer(obj_window,-1,0);

  SDL_SetRenderDrawColor(obj_renderer, 135, 206, 235, 255); //displays color of sky (sky blue)

  SDL_RenderClear(obj_renderer);

  SDL_Surface* temp = IMG_Load("./images/idleAlien.png"); //imports all the .png's needed and calls the serve_texture functions of the PlayerSprite and
  sprite.sprite_serve_texture_idle(temp, obj_renderer);   //TileHandler classes to import them
  SDL_FreeSurface(temp);

  temp = IMG_Load("./images/runAlien.png");
  sprite.sprite_serve_texture_run(temp, obj_renderer);
  SDL_FreeSurface(temp);

  temp = IMG_Load("./images/ground1.png");
  tile.tile_serve_texture(temp, obj_renderer, 0);
  SDL_FreeSurface(temp);

  temp = IMG_Load("./images/ground2.png");
  tile.tile_serve_texture(temp, obj_renderer, 1);
  SDL_FreeSurface(temp);

  temp = IMG_Load("./images/background1.png");
  tile.tile_serve_texture(temp, obj_renderer, 2);
  SDL_FreeSurface(temp);

  temp = IMG_Load("./images/door1.png");
  tile.tile_serve_texture(temp, obj_renderer, 3);
  SDL_FreeSurface(temp);

  temp = IMG_Load("./images/laser.png"); //adds laser obstacles
  int i;
  for(i = 0; i < 6; i++){ //for loop that serves in the obstacle texture to 6 instances of the obstacle class
    obstacle[i].obstacle_serve_texture(temp, obj_renderer);
    obstacle[i].obstacle_set_rect_w(screen_width/8);
    obstacle[i].obstacle_set_rect_h(15);
  }
  SDL_FreeSurface(temp);

  temp = IMG_Load("./images/laser_end.png"); //adds laser end
  laser_end = SDL_CreateTextureFromSurface(obj_renderer, temp);
  SDL_FreeSurface(temp);
}

void GameEngine::obj_updateUI(){
  this_start_time = SDL_GetTicks();
  while (SDL_PollEvent(&obj_event)){
    if (obj_event.type == SDL_QUIT) game_is_running = false; //quits game is user presses X
  }

  const Uint8 *state = SDL_GetKeyboardState(NULL);
  
  if(player_alive && !screens.pause_game && !screens.in_main_menu){ //updates user controls
    if(state[SDL_SCANCODE_SPACE]){
      if(!key_down){ //ensures user cannot hold space key down to continuously change gravity
        sprite.sprite_change_gravity();
      }
      sprite.sprite_set_state(1);
      key_down = true;
      tile.tile_update_screen_left(-1 * player.player_get_vel());
    }else if(state[SDL_SCANCODE_P]){
      if(!key_down){
        screens.pause_game = true;
      }else{
        sprite.sprite_set_state(1);
        tile.tile_update_screen_left(-1 * player.player_get_vel());
      }
      key_down = true;
    }else{
      key_down = false;
      sprite.sprite_set_state(1);
      tile.tile_update_screen_left(-1 * player.player_get_vel());
    }
  }
  else if(screens.in_main_menu){
    sprite.sprite_set_gravity_change();
    sprite.sprite_set_direction(SDL_FLIP_NONE); 
    player.player_set_pos_y(370);
    sprite.sprite_set_state(1);
    player.player_set_vel(player.player_start_vel);
    tile.tile_update_screen_left(-1 * player.player_get_vel());
    for(int i = 0; i <  lasers; i++){
      obstacle[i].obstacle_set_rect_x(-100);
      obstacle[i].obstacle_set_rect_y(-100);
    }
    if(state[SDL_SCANCODE_SPACE] && !screens.credits && !screens.instructions){ //starts the game
      if(!key_down){
        screens.in_main_menu = false;
        screens.credits = false;
        screens.instructions = false;
        screens.restart_game = true;
        score = 0;
      }
      key_down = true;
    }else if(state[SDL_SCANCODE_E] && !screens.credits && !screens.instructions){ //exits the game
      game_is_running = false;
    }
    else if(state[SDL_SCANCODE_C]){ //goes to credits
      screens.credits = true;
    }
    else if(state[SDL_SCANCODE_I]){ //goes to instructions
      screens.instructions = true;
    }
    else if(state[SDL_SCANCODE_B] && screens.credits){ //goes to main menu from credits
      screens.credits = false;
      screens.in_main_menu = true;
    }
    else if(state[SDL_SCANCODE_B] && screens.instructions){ //goes to main menu from credits
      screens.instructions = false;
      screens.in_main_menu = true;
    }
    else key_down = false;
  }

  else{
    if(state[SDL_SCANCODE_R]) screens.restart_game = true; //restarts game
    else if(state[SDL_SCANCODE_E]) game_is_running = false; //exits game
    else if(state[SDL_SCANCODE_M] && screens.pause_game){ //returns to main menu from pause menu
      screens.pause_game = false;
      screens.in_main_menu = true;
    }else if(state[SDL_SCANCODE_M] && !player_alive){ //returns to main menu from game over screen
      player_alive = true;
      screens.end_game = false;
      screens.in_main_menu = true;
    }else if(screens.pause_game && state[SDL_SCANCODE_P]){ //returns to game from pause menu
      if(!key_down){
        screens.pause_game = false;
      }
      key_down = true;
    }else key_down = false;
  }
}

void GameEngine::obj_update(){
  if(screens.restart_game){ //resets player and obstacle/obstacle positions and states
    for(int i = 0; i <  lasers; i++){
      obstacle[i].obstacle_set_rect_x(-100);
      obstacle[i].obstacle_set_rect_y(-100);
    }
    sprite.sprite_set_gravity_change();
    sprite.sprite_set_direction(SDL_FLIP_NONE);
    player.player_set_pos_y(370);
    score = 0; //resets score
    player_alive = true; //sets player to be alive
    screens.pause_game = false; //resets pause game
    screens.restart_game = false; //reset restart game
    total_cases = 2; //sets total obstacle locations back to 2
    lasers = 3; //sets total possible lasers on the screen back to 3
    player.player_set_vel(player.player_start_vel); //sets player velocity back to 10
  }

  if(player_alive && !screens.pause_game && !screens.in_main_menu){
    for(int i = 0; i <  lasers; i++){ //obstacle collision detection (Rectangle collider)
      if(player.player_get_pos_x() + 33 >= obstacle[i].obstacle_get_x_pos()){ //if the rightmost pos of player is greater than the leftmost pos of obstacle
        if(player.player_get_pos_x() <= obstacle[i].obstacle_get_x_pos() + 58){ //if the leftmost pos of player is less than the rightmost pos of obstacle
          if(player.player_get_pos_y() + 65 >= obstacle[i].obstacle_get_y_pos()){ //if pos of bottom of player is greater than top of obstacle
            if(player.player_get_pos_y() <= obstacle[i].obstacle_get_y_pos() + 25){ //if pos of top of player is less than bottom of obstacle
              player_alive = false;
            }
          }
        }
      }
    }

    if(sprite.sprite_get_gravity_state()){ //if sprite is changing gravity
      sprite.sprite_set_state(0);
      if(sprite.sprite_get_direction()){ //player is normal oriented, changing gravity back toward the bottom ground
        if(player.player_get_pos_y() < 370){ //ensures player stops changing gravity once it reaches the top ground
          player.player_set_pos_y(player.player_get_pos_y() + player.player_start_vel);
        }else{
          sprite.sprite_set_gravity_change();
        }
      }else if(!sprite.sprite_get_direction()){ //player is upside down, changing gravity toward the top ground
          if(player.player_get_pos_y() > 50){ //ensures player stops changing gravity once it reaches the bottom ground
          player.player_set_pos_y(player.player_get_pos_y() - player.player_start_vel);
        }else{
          sprite.sprite_set_gravity_change();
        }
      }
    }
    if(score % 1000 == 0 && score != 0){ //increases difficulty as game/score progresses
      if(total_cases < 3) total_cases++;
      if(lasers < 6) lasers++;
    }
    if(score % 1500 == 0 && score != 0) player.player_add_vel(1);

    for(int i = 0; i < lasers; i++){ //loop that updates and generates the obstacle/obstacles
      int num = rand() % total_cases;
      int section_x_pos = 640;
      bool available = true;

      if(counter[i] == 5){
        obstacle[i].obstacle_update();
        counter[i] = 0;
      }else counter[i]++;

      if(obstacle[i].obstacle_get_x_pos() >= -64){ //changes obstacle position
          obstacle[i].obstacle_change_rect_x(-1 * player.player_get_vel());
      }else{  //if off screen, recycle to create "new" obstacle randomly
        switch(num){
          case 0: //sets obstacle to the bottom ground
            for(int j = 0; j < lasers; j++){ //ensures no obstacles overlap
              if(obstacle[j].obstacle_get_x_pos() > (screen_width - 64)){
                available = false;
              }
            }
            if(available){
              obstacle[i].obstacle_set_rect_x(section_x_pos);
              obstacle[i].obstacle_set_rect_y(410);
              obstacle[i].obstacle_set_type(1); //sets the type to bottom
            }
            break;
          case 1: //sets obstacle to the top ground
            for(int j = 0; j < lasers; j++){
              if(obstacle[j].obstacle_get_x_pos() > (screen_width - 64)){
                available = false;
              }
            }
            if(available){
              obstacle[i].obstacle_set_rect_x(section_x_pos);
              obstacle[i].obstacle_set_rect_y(55);
              obstacle[i].obstacle_set_type(3); //sets the type to top
            }
            break;
          case 2: //sets obstacle to the middle ground
            for(int j = 0; j < lasers; j++){
              if(obstacle[j].obstacle_get_x_pos() > (screen_width - 64)){
                available = false;
              }
            }
            if(available){
              obstacle[i].obstacle_set_rect_x(section_x_pos);
              obstacle[i].obstacle_set_rect_y(230);
              obstacle[i].obstacle_set_type(2); //sets the type to middle
            }
            break;
        }
      }
    }
    score++;
  }
  sprite.sprite_set_rect_x(player.player_get_pos_x());
  sprite.sprite_set_rect_y(player.player_get_pos_y());
  if(!screens.pause_game) sprite.sprite_update_frame();
}

void GameEngine::obj_render(){
  SDL_RenderClear(obj_renderer);

  tile.tile_render(obj_renderer); //renders tiles

  sprite.sprite_render(obj_renderer); //renders sprite

  for(int i = 0; i < lasers; i++){ //renders obstacles/obstacles
    if(obstacle[i].obstacle_get_x_pos() > -150){
      obstacle[i].obstacle_render(obj_renderer);
      
      bool left_end = true;
      bool right_end = true;

      for(int j = 0; j < lasers; j++){ //next two for loops ensure that connected lasers only have 2 endpoints
        if(i != j){
          if(obstacle[i].obstacle_get_type() == obstacle[j].obstacle_get_type() && obstacle[i].obstacle_get_x_pos() > obstacle[j].obstacle_get_x_pos()){
            if(obstacle[i].obstacle_get_x_pos() <= obstacle[j].obstacle_get_x_pos() + 100){
              left_end = false;
            }
          }
        }
      }
      laser_end_rect[i].x = obstacle[i].obstacle_get_x_pos() - 10;
      laser_end_rect[i].y = obstacle[i].obstacle_get_y_pos() - 4;
      if(left_end && laser_end_rect[i].y > 30) SDL_RenderCopy(obj_renderer, laser_end, NULL, &laser_end_rect[i]);

      for(int j = 0; j < lasers; j++){
        if(i != j){
          if(obstacle[i].obstacle_get_type() == obstacle[j].obstacle_get_type() && obstacle[i].obstacle_get_x_pos() < obstacle[j].obstacle_get_x_pos()){
            if(obstacle[i].obstacle_get_x_pos() + 100 >= obstacle[j].obstacle_get_x_pos()){
              right_end = false;
            }
          }
        }
      }
      laser_end_rect[i + lasers].x = obstacle[i].obstacle_get_x_pos() + 70;
      laser_end_rect[i + lasers].y = obstacle[i].obstacle_get_y_pos() - 4;
      if(right_end && laser_end_rect[i + lasers].y > 30) SDL_RenderCopyEx(obj_renderer, laser_end, NULL, &laser_end_rect[i + lasers], 0.0, NULL, SDL_FLIP_HORIZONTAL);
    }
  }

  if(!screens.in_main_menu) screens.render_score(obj_renderer, score); //renders score

  if(!player_alive) screens.render_death_screen(obj_renderer); //renders death screen
  
  if(screens.in_main_menu && !screens.credits && !screens.instructions) screens.render_main_menu(obj_renderer); //renders main menu
  else if(screens.pause_game) screens.render_pause_menu(obj_renderer); //renders pause menu
  else if(screens.credits) screens.render_credits(obj_renderer); //renders credits
  else if(screens.instructions) screens.render_instructions(obj_renderer); //renders instructions

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
  TTF_Quit();
}
