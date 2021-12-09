#include "Screens.h"

Screens::Screens(){
  in_main_menu = true;
  restart_game = false;
  end_game = false;
  pause_game = false;
  credits = false;
  instructions = false;
}

Screens::~Screens(){}

void Screens::render_main_menu(SDL_Renderer* obj_renderer){
  // Load in fonts and colors
  TTF_Font* ethnocenticItalic = TTF_OpenFont("./Fonts/ethnocentric rg it.ttf", 40);
  TTF_Font* ethnocentic = TTF_OpenFont("./Fonts/ethnocentric rg.ttf", 20);
  SDL_Color color = { 50, 205, 50 };

  // The words on screen for Main menu
  SDL_Surface* mainMenuSurface = TTF_RenderText_Solid(ethnocenticItalic, "Gravity Runner", color);
  SDL_Rect MainMenuDest = { 70, 140, mainMenuSurface->w, mainMenuSurface->h };
  SDL_Texture* MainMenutexture = SDL_CreateTextureFromSurface(obj_renderer, mainMenuSurface);
  SDL_RenderCopy(obj_renderer, MainMenutexture, NULL, &MainMenuDest);

  color = { 255, 255, 255 };
  SDL_Surface* StartGame = TTF_RenderText_Solid(ethnocentic, "Space - Start", color);
  SDL_Rect StartDest = { 80, 235, StartGame->w, StartGame->h };
  SDL_Texture* StartTexture = SDL_CreateTextureFromSurface(obj_renderer, StartGame);
  SDL_RenderCopy(obj_renderer, StartTexture, NULL, &StartDest);
  
  SDL_Surface* creditsSurface = TTF_RenderText_Solid(ethnocentic, "C - Credits", color);
  SDL_Rect creditsDest = { 383, 235, creditsSurface->w, creditsSurface->h };
  SDL_Texture* creditsTexture = SDL_CreateTextureFromSurface(obj_renderer, creditsSurface);
  SDL_RenderCopy(obj_renderer, creditsTexture, NULL, &creditsDest); 

  SDL_Surface* InstructionsSurface = TTF_RenderText_Solid(ethnocentic, "I - Instructions", color);
  SDL_Rect InstructionsDest = { 80, 285, InstructionsSurface->w, InstructionsSurface->h };
  SDL_Texture* InstructionsTexture = SDL_CreateTextureFromSurface(obj_renderer, InstructionsSurface);
  SDL_RenderCopy(obj_renderer, InstructionsTexture, NULL, &InstructionsDest);

  SDL_Surface* MainMenuEnd = TTF_RenderText_Solid(ethnocentic, "E - Exit", color);
  SDL_Rect MainMenuEndDest = { 440, 285, MainMenuEnd->w, MainMenuEnd->h };
  SDL_Texture* MainMenuEndTexture = SDL_CreateTextureFromSurface(obj_renderer, MainMenuEnd);
  SDL_RenderCopy(obj_renderer, MainMenuEndTexture, NULL, &MainMenuEndDest);


  // Clean Up
  SDL_FreeSurface(mainMenuSurface);
  SDL_FreeSurface(StartGame);
  SDL_FreeSurface(MainMenuEnd);
  SDL_FreeSurface(creditsSurface);
  SDL_FreeSurface(InstructionsSurface);

  SDL_DestroyTexture(MainMenutexture);
  SDL_DestroyTexture(StartTexture);
  SDL_DestroyTexture(MainMenuEndTexture);
  SDL_DestroyTexture(creditsTexture);
  SDL_DestroyTexture(InstructionsTexture);

  TTF_CloseFont(ethnocenticItalic);
  TTF_CloseFont(ethnocentic);
}

void Screens::render_pause_menu(SDL_Renderer* obj_renderer){
  SDL_Rect fill_screen;
  fill_screen.x = 90;
  fill_screen.y = 90;
  fill_screen.w = 460;
  fill_screen.h = 300;

  SDL_SetRenderDrawColor(obj_renderer, 50, 205, 50, 255);
  SDL_RenderDrawRect(obj_renderer, &fill_screen);
  SDL_RenderFillRect(obj_renderer, &fill_screen);

  SDL_Rect fill_the_screen;
  fill_the_screen.x = 100;
  fill_the_screen.y = 100;
  fill_the_screen.w = 440;
  fill_the_screen.h = 280;

  SDL_SetRenderDrawColor(obj_renderer, 0, 0, 0, 255);
  SDL_RenderDrawRect(obj_renderer, &fill_the_screen);
  SDL_RenderFillRect(obj_renderer, &fill_the_screen);

  // Load in fonts and colors
  TTF_Font* ethnocenticItalic = TTF_OpenFont("./Fonts/ethnocentric rg it.ttf", 40);
  TTF_Font* ethnocentic = TTF_OpenFont("./Fonts/ethnocentric rg.ttf", 20);
  SDL_Color color = { 50, 205, 50 };

  // The words on screen for pause

  SDL_Surface* PauseSurface = TTF_RenderText_Solid(ethnocenticItalic, "Pause!!!", color);
  SDL_Rect PauseDest = { 110, 100, PauseSurface->w, PauseSurface->h };
  SDL_Texture* Pausetexture = SDL_CreateTextureFromSurface(obj_renderer, PauseSurface);
  SDL_RenderCopy(obj_renderer, Pausetexture, NULL, &PauseDest);


  SDL_Surface* PauseResume = TTF_RenderText_Solid(ethnocentic, "P - Un-Pause", color);
  SDL_Rect PauseResumeDest = { 110, 175, PauseResume->w, PauseResume->h };
  SDL_Texture* PauseResumeTexture = SDL_CreateTextureFromSurface(obj_renderer, PauseResume);
  SDL_RenderCopy(obj_renderer, PauseResumeTexture, NULL, &PauseResumeDest);

  SDL_Surface* PauseToMenu = TTF_RenderText_Solid(ethnocentic, "M - Menu", color);
  SDL_Rect PauseToMenuDest = { 110, 225, PauseToMenu->w, PauseToMenu->h };
  SDL_Texture* PauseToMenuTexture = SDL_CreateTextureFromSurface(obj_renderer, PauseToMenu);
  SDL_RenderCopy(obj_renderer, PauseToMenuTexture, NULL, &PauseToMenuDest);


  SDL_Surface* PauseEnd = TTF_RenderText_Solid(ethnocentic, "E - Exit", color);
  SDL_Rect PauseEndDest = { 110, 275, PauseEnd->w, PauseEnd->h };
  SDL_Texture* PauseEndTexture = SDL_CreateTextureFromSurface(obj_renderer, PauseEnd);
  SDL_RenderCopy(obj_renderer, PauseEndTexture, NULL, &PauseEndDest);


  SDL_Surface* playerSurface = IMG_Load("./images/alienSpritePNG.png");
  SDL_Rect PlayerDest = { 250, 275, playerSurface->w, playerSurface->h };
  SDL_Texture* playerText = SDL_CreateTextureFromSurface(obj_renderer, playerSurface);

  SDL_Rect Player_src;
  int tick = SDL_GetTicks() / 1000;

  if(tick % 2 == 0){
    Player_src.x = 0;
    Player_src.y = 0;
    Player_src.w = 32;
    Player_src.h = 32;
  }

  if(tick % 2 == 1){
    Player_src.x = 0;
    Player_src.y = 64;
    Player_src.w = 32;
    Player_src.h = 32;
  }

  SDL_RenderCopy(obj_renderer, playerText, &Player_src, &PlayerDest);


  // Clean Up
  SDL_FreeSurface(PauseSurface);
  SDL_FreeSurface(PauseResume);
  SDL_FreeSurface(PauseToMenu);
  SDL_FreeSurface(PauseEnd);
  SDL_FreeSurface(playerSurface);

  SDL_DestroyTexture(Pausetexture);
  SDL_DestroyTexture(PauseResumeTexture);
  SDL_DestroyTexture(PauseToMenuTexture);
  SDL_DestroyTexture(PauseEndTexture);
  SDL_DestroyTexture(playerText);

  TTF_CloseFont(ethnocenticItalic);
  TTF_CloseFont(ethnocentic);
}

    
void Screens::render_death_screen(SDL_Renderer* obj_renderer){

  SDL_Rect fill_screen;
  fill_screen.x = 90;
  fill_screen.y = 90;
  fill_screen.w = 460;
  fill_screen.h = 300;

  SDL_SetRenderDrawColor(obj_renderer, 220, 20, 60, 255);
  SDL_RenderDrawRect(obj_renderer, &fill_screen);
  SDL_RenderFillRect(obj_renderer, &fill_screen);

  //Game Over Box
  SDL_Rect fill_the_screen;
  fill_the_screen.x = 100;
  fill_the_screen.y = 100;
  fill_the_screen.w = 440;
  fill_the_screen.h = 280;

  SDL_SetRenderDrawColor(obj_renderer, 0, 0, 0, 255);
  SDL_RenderDrawRect(obj_renderer, &fill_the_screen);
  SDL_RenderFillRect(obj_renderer, &fill_the_screen);

  // Load in fonts and colors
  TTF_Font* ethnocenticItalic = TTF_OpenFont("./Fonts/ethnocentric rg it.ttf", 40);
  TTF_Font* ethnocentic = TTF_OpenFont("./Fonts/ethnocentric rg.ttf", 20);
  SDL_Color color = { 255, 0, 0 };

  // The words on screen for Game over

  SDL_Surface* gameOverSurface = TTF_RenderText_Solid(ethnocenticItalic, "Game Over!!!", color);
  SDL_Rect GameOverDest = { 110, 100, gameOverSurface->w, gameOverSurface->h };
  SDL_Texture* GameOvertexture = SDL_CreateTextureFromSurface(obj_renderer, gameOverSurface);
  SDL_RenderCopy(obj_renderer, GameOvertexture, NULL, &GameOverDest);

  SDL_Surface* gameOverRestart = TTF_RenderText_Solid(ethnocentic, "R - Restart", color);
  SDL_Rect RestartDest = { 110, 175, gameOverRestart->w, gameOverRestart->h };
  SDL_Texture* RestartTexture = SDL_CreateTextureFromSurface(obj_renderer, gameOverRestart);
  SDL_RenderCopy(obj_renderer, RestartTexture, NULL, &RestartDest);

  SDL_Surface* gameOverMenu = TTF_RenderText_Solid(ethnocentic, "M - Menu", color);
  SDL_Rect MenuDest = { 110, 225, gameOverMenu->w, gameOverMenu->h };
  SDL_Texture* MenuTexture = SDL_CreateTextureFromSurface(obj_renderer, gameOverMenu);
  SDL_RenderCopy(obj_renderer, MenuTexture, NULL, &MenuDest);

  SDL_Surface* gameOverEnd = TTF_RenderText_Solid(ethnocentic, "E - Exit", color);
  SDL_Rect EndDest = { 110, 275, gameOverEnd->w, gameOverEnd->h };
  SDL_Texture* EndTexture = SDL_CreateTextureFromSurface(obj_renderer, gameOverEnd);
  SDL_RenderCopy(obj_renderer, EndTexture, NULL, &EndDest);


  // Clean Up
  SDL_FreeSurface(gameOverSurface);
  SDL_FreeSurface(gameOverRestart);
  SDL_FreeSurface(gameOverMenu);
  SDL_FreeSurface(gameOverEnd);

  SDL_DestroyTexture(GameOvertexture);
  SDL_DestroyTexture(RestartTexture);
  SDL_DestroyTexture(MenuTexture);
  SDL_DestroyTexture(EndTexture);

  TTF_CloseFont(ethnocenticItalic);
  TTF_CloseFont(ethnocentic);
}

void Screens::render_score(SDL_Renderer* obj_renderer, int score){
  // Load in fonts and colors
  TTF_Font* ethnocentic = TTF_OpenFont("./Fonts/ethnocentric rg.ttf", 20);
  SDL_Color color = { 255, 255, 255 };

  string str_score = "Score: " + to_string(score);
  char const * the_score = str_score.c_str();

  string str_pause = "p - Pause ";
  char const * HUD_pause = str_pause.c_str();

  // cout<< the_score <<endl;

  SDL_Surface* scoreSurface = TTF_RenderText_Solid(ethnocentic, the_score, color);
  SDL_Rect scoreDest = { 20, 17, scoreSurface->w, scoreSurface->h };
  SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(obj_renderer, scoreSurface);
  SDL_RenderCopy(obj_renderer, scoreTexture, NULL, &scoreDest);

//pause HUD message
  SDL_Surface* HUDSurface = TTF_RenderText_Solid(ethnocentic, HUD_pause, color);
  SDL_Rect HUDDest = { 470, 17, HUDSurface->w, HUDSurface->h };
  SDL_Texture* HUDTexture = SDL_CreateTextureFromSurface(obj_renderer, HUDSurface);
  SDL_RenderCopy(obj_renderer, HUDTexture, NULL, &HUDDest);

  // Clean Up
  SDL_FreeSurface(scoreSurface);
  SDL_DestroyTexture(scoreTexture);
  SDL_FreeSurface(HUDSurface);
  SDL_DestroyTexture(HUDTexture);
  TTF_CloseFont(ethnocentic);
}

void Screens::render_credits(SDL_Renderer* obj_renderer){
  SDL_Rect fill_screen;
  fill_screen.x = 0;
  fill_screen.y = 0;
  fill_screen.w = 640;
  fill_screen.h = 480;

  SDL_SetRenderDrawColor(obj_renderer, 0, 0, 0, 255);
  SDL_RenderDrawRect(obj_renderer, &fill_screen);
  SDL_RenderFillRect(obj_renderer, &fill_screen);

  TTF_Font* ethnocenticItalic = TTF_OpenFont("./Fonts/ethnocentric rg it.ttf", 20);
  TTF_Font* ethnocentic = TTF_OpenFont("./Fonts/ethnocentric rg.ttf", 12);
  SDL_Color color = { 50, 205, 50 };

  SDL_Surface* creditsSurface = TTF_RenderText_Solid(ethnocenticItalic, "Credits:", color);
  SDL_Rect creditsDest = { 260, 60, creditsSurface->w, creditsSurface->h };
  SDL_Texture* creditsTexture = SDL_CreateTextureFromSurface(obj_renderer, creditsSurface);
  SDL_RenderCopy(obj_renderer, creditsTexture, NULL, &creditsDest);

  SDL_Surface* credit1Surface = TTF_RenderText_Solid(ethnocentic, "Kristopher Luo: Team Leader, Designer, Programmer", color);
  SDL_Rect credit1Dest = { 70, 125, credit1Surface->w, credit1Surface->h };
  SDL_Texture* credit1Texture = SDL_CreateTextureFromSurface(obj_renderer, credit1Surface);
  SDL_RenderCopy(obj_renderer, credit1Texture, NULL, &credit1Dest);

  SDL_Surface* credit2Surface = TTF_RenderText_Solid(ethnocentic, "Chase Williams: Designer, Programmer", color);
  SDL_Rect credit2Dest = { 70, 175, credit2Surface->w, credit2Surface->h };
  SDL_Texture* credit2Texture = SDL_CreateTextureFromSurface(obj_renderer, credit2Surface);
  SDL_RenderCopy(obj_renderer, credit2Texture, NULL, &credit2Dest);

  SDL_Surface* credit3Surface = TTF_RenderText_Solid(ethnocentic, "Logan Barrow: Designer", color);
  SDL_Rect credit3Dest = { 70, 225, credit3Surface->w, credit3Surface->h };
  SDL_Texture* credit3Texture = SDL_CreateTextureFromSurface(obj_renderer, credit3Surface);
  SDL_RenderCopy(obj_renderer, credit3Texture, NULL, &credit3Dest);

  SDL_Surface* credit4Surface = TTF_RenderText_Solid(ethnocentic, "Chloe Caples: Programmer", color);
  SDL_Rect credit4Dest = { 70, 275, credit4Surface->w, credit4Surface->h };
  SDL_Texture* credit4Texture = SDL_CreateTextureFromSurface(obj_renderer, credit4Surface);
  SDL_RenderCopy(obj_renderer, credit4Texture, NULL, &credit4Dest);

  SDL_Surface* credit5Surface = TTF_RenderText_Solid(ethnocentic, "Emily Johnson: Visual Artist, Programmer", color);
  SDL_Rect credit5Dest = { 70, 325, credit5Surface->w, credit5Surface->h };
  SDL_Texture* credit5Texture = SDL_CreateTextureFromSurface(obj_renderer, credit5Surface);
  SDL_RenderCopy(obj_renderer, credit5Texture, NULL, &credit5Dest);

  SDL_Surface* toMenu = TTF_RenderText_Solid(ethnocentic, "B - Back", color);
  SDL_Rect toMenuDest = { 50, 425, toMenu->w, toMenu->h };
  SDL_Texture* toMenuTexture = SDL_CreateTextureFromSurface(obj_renderer, toMenu);
  SDL_RenderCopy(obj_renderer, toMenuTexture, NULL, &toMenuDest);


  // Clean Up
  SDL_FreeSurface(creditsSurface);
  SDL_FreeSurface(credit1Surface);
  SDL_FreeSurface(credit2Surface);
  SDL_FreeSurface(credit3Surface);
  SDL_FreeSurface(credit4Surface);
  SDL_FreeSurface(credit5Surface);
  SDL_FreeSurface(toMenu);

  SDL_DestroyTexture(creditsTexture);
  SDL_DestroyTexture(credit1Texture);
  SDL_DestroyTexture(credit2Texture);
  SDL_DestroyTexture(credit3Texture);
  SDL_DestroyTexture(credit4Texture);
  SDL_DestroyTexture(credit5Texture);
  SDL_DestroyTexture(toMenuTexture);


  TTF_CloseFont(ethnocenticItalic);
  TTF_CloseFont(ethnocentic);
}

void Screens::render_instructions(SDL_Renderer* obj_renderer){
  SDL_Rect fill_screen;
  fill_screen.x = 90;
  fill_screen.y = 90;
  fill_screen.w = 460;
  fill_screen.h = 300;

  SDL_SetRenderDrawColor(obj_renderer, 50, 205, 50, 255);
  SDL_RenderDrawRect(obj_renderer, &fill_screen);
  SDL_RenderFillRect(obj_renderer, &fill_screen);

  //Game Over Box
  SDL_Rect fill_the_screen;
  fill_the_screen.x = 100;
  fill_the_screen.y = 100;
  fill_the_screen.w = 440;
  fill_the_screen.h = 280;

  SDL_SetRenderDrawColor(obj_renderer, 0, 0, 0, 255);
  SDL_RenderDrawRect(obj_renderer, &fill_the_screen);
  SDL_RenderFillRect(obj_renderer, &fill_the_screen);

  // Load in fonts and colors
  TTF_Font* ethnocenticItalic = TTF_OpenFont("./Fonts/ethnocentric rg it.ttf", 40);
  TTF_Font* ethnocentic = TTF_OpenFont("./Fonts/ethnocentric rg.ttf", 20);
  SDL_Color color = { 50, 205, 50 };

  // The words on screen for Game over

  SDL_Surface* InstructionsSurface = TTF_RenderText_Solid(ethnocenticItalic, "Instructions", color);
  SDL_Rect InstructionsDest = { 110, 100, InstructionsSurface->w, InstructionsSurface->h };
  SDL_Texture* InstructionsTexture = SDL_CreateTextureFromSurface(obj_renderer, InstructionsSurface);
  SDL_RenderCopy(obj_renderer, InstructionsTexture, NULL, &InstructionsDest);

  SDL_Surface* InstructionsSpace = TTF_RenderText_Solid(ethnocentic, "Space - Change Gravity", color);
  SDL_Rect SpaceDest = { 110, 175, InstructionsSpace->w, InstructionsSpace->h };
  SDL_Texture* SpaceTexture = SDL_CreateTextureFromSurface(obj_renderer, InstructionsSpace);
  SDL_RenderCopy(obj_renderer, SpaceTexture, NULL, &SpaceDest);


  SDL_Surface* InstructionsPause = TTF_RenderText_Solid(ethnocentic, "P - Pause", color);
  SDL_Rect PauseDest = { 110, 225, InstructionsPause->w, InstructionsPause->h };
  SDL_Texture* PauseTexture = SDL_CreateTextureFromSurface(obj_renderer, InstructionsPause);
  SDL_RenderCopy(obj_renderer, PauseTexture, NULL, &PauseDest);

  color = { 255, 0, 0 };
  SDL_Surface* InstructionsLasers = TTF_RenderText_Solid(ethnocentic, "AVOID THE RED LASERS!!!", color);
  SDL_Rect LasersDest = { 110, 275, InstructionsLasers->w, InstructionsLasers->h };
  SDL_Texture* LasersTexture = SDL_CreateTextureFromSurface(obj_renderer, InstructionsLasers);
  SDL_RenderCopy(obj_renderer, LasersTexture, NULL, &LasersDest);

  color = { 50, 205, 50 };
  SDL_Surface* toMenu = TTF_RenderText_Solid(ethnocentic, "B - Back", color);
  SDL_Rect toMenuDest = { 110, 350, toMenu->w, toMenu->h };
  SDL_Texture* toMenuTexture = SDL_CreateTextureFromSurface(obj_renderer, toMenu);
  SDL_RenderCopy(obj_renderer, toMenuTexture, NULL, &toMenuDest);


  // Clean Up
  SDL_FreeSurface(InstructionsSurface);
  SDL_FreeSurface(InstructionsSpace);
  SDL_FreeSurface(InstructionsPause);
  SDL_FreeSurface(InstructionsLasers);

  SDL_DestroyTexture(InstructionsTexture);
  SDL_DestroyTexture(SpaceTexture);
  SDL_DestroyTexture(PauseTexture);
  SDL_DestroyTexture(LasersTexture);

  TTF_CloseFont(ethnocenticItalic);
  TTF_CloseFont(ethnocentic);
}
