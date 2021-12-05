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


  // Load in fonts and colors
  TTF_Font* ethnocenticItalic = TTF_OpenFont("./Fonts/ethnocentric rg it.ttf", 40);
  TTF_Font* ethnocentic = TTF_OpenFont("./Fonts/ethnocentric rg.ttf", 20);
  SDL_Color color = { 0, 0, 0 };

  // The words on screen for Main menu
  SDL_Surface* mainMenuSurface = TTF_RenderText_Solid(ethnocenticItalic, "Gravity Runner", color);
  SDL_Rect MainMenuDest = { 100, 100, mainMenuSurface->w, mainMenuSurface->h };
  SDL_Texture* MainMenutexture = SDL_CreateTextureFromSurface(obj_renderer, mainMenuSurface);
  SDL_RenderCopy(obj_renderer, MainMenutexture, NULL, &MainMenuDest);


  SDL_Surface* StartGame = TTF_RenderText_Solid(ethnocentic, "Space - Start", color);
  SDL_Rect StartDest = { 100, 175, StartGame->w, StartGame->h };
  SDL_Texture* StartTexture = SDL_CreateTextureFromSurface(obj_renderer, StartGame);
  SDL_RenderCopy(obj_renderer, StartTexture, NULL, &StartDest);


  SDL_Surface* MainMenuEnd = TTF_RenderText_Solid(ethnocentic, "E - Exit", color);
  SDL_Rect MainMenuEndDest = { 100, 225, MainMenuEnd->w, MainMenuEnd->h };
  SDL_Texture* MainMenuEndTexture = SDL_CreateTextureFromSurface(obj_renderer, MainMenuEnd);
  SDL_RenderCopy(obj_renderer, MainMenuEndTexture, NULL, &MainMenuEndDest);


  // Clean Up
  SDL_FreeSurface(mainMenuSurface);
  SDL_FreeSurface(StartGame);
  SDL_FreeSurface(MainMenuEnd);

  SDL_DestroyTexture(MainMenutexture);
  SDL_DestroyTexture(StartTexture);
  SDL_DestroyTexture(MainMenuEndTexture);

  TTF_CloseFont(ethnocenticItalic);
  TTF_CloseFont(ethnocentic);
}

void Screens::pause_menu(SDL_Renderer* obj_renderer)
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


  // Load in fonts and colors
  TTF_Font* ethnocenticItalic = TTF_OpenFont("./Fonts/ethnocentric rg it.ttf", 40);
  TTF_Font* ethnocentic = TTF_OpenFont("./Fonts/ethnocentric rg.ttf", 20);
  SDL_Color color = { 255, 255, 255 };

  // The words on screen for Game over

  SDL_Surface* PauseSurface = TTF_RenderText_Solid(ethnocenticItalic, "Pause!!!", color);
  SDL_Rect PauseDest = { 100, 100, PauseSurface->w, PauseSurface->h };
  SDL_Texture* Pausetexture = SDL_CreateTextureFromSurface(obj_renderer, PauseSurface);
  SDL_RenderCopy(obj_renderer, Pausetexture, NULL, &PauseDest);


  SDL_Surface* PauseResume = TTF_RenderText_Solid(ethnocentic, "P - Resume", color);
  SDL_Rect PauseResumeDest = { 100, 175, PauseResume->w, PauseResume->h };
  SDL_Texture* PauseResumeTexture = SDL_CreateTextureFromSurface(obj_renderer, PauseResume);
  SDL_RenderCopy(obj_renderer, PauseResumeTexture, NULL, &PauseResumeDest);


  SDL_Surface* PauseEnd = TTF_RenderText_Solid(ethnocentic, "E - Exit", color);
  SDL_Rect PauseEndDest = { 100, 225, PauseEnd->w, PauseEnd->h };
  SDL_Texture* PauseEndTexture = SDL_CreateTextureFromSurface(obj_renderer, PauseEnd);
  SDL_RenderCopy(obj_renderer, PauseEndTexture, NULL, &PauseEndDest);


  // Clean Up
  SDL_FreeSurface(PauseSurface);
  SDL_FreeSurface(PauseResume);
  SDL_FreeSurface(PauseEnd);

  SDL_DestroyTexture(Pausetexture);
  SDL_DestroyTexture(PauseResumeTexture);
  SDL_DestroyTexture(PauseEndTexture);

  TTF_CloseFont(ethnocenticItalic);
  TTF_CloseFont(ethnocentic);
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
