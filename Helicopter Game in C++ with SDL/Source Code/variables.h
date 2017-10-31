#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED
///SDL SURFACE POINTERS
SDL_Surface *game_over=NULL;
SDL_Surface *background = NULL;
SDL_Surface *OBSTACLES= NULL;
SDL_Surface *screen = NULL;
SDL_Surface *welcome=NULL;

SDL_Surface *credits=NULL;
SDL_Surface *heli=NULL;
Mix_Music   *music = NULL;
TTF_Font    *font = NULL;
SDL_Surface *message=NULL;
SDL_Surface *transparent=NULL;

///MUSIC VARIABLES
Mix_Chunk   *back_music=NULL;
Mix_Chunk   *selection = NULL;
Mix_Chunk   *boom=NULL;
Mix_Chunk   *loading=NULL;
Mix_Chunk   *proceed=NULL;

///Main Menu images
SDL_Surface* menu =NULL;
SDL_Surface* play_menu = NULL;
SDL_Surface* option_menu = NULL;
SDL_Surface* Score_menu = NULL;
SDL_Surface* Instruc_menu = NULL;
SDL_Surface* credits_menu = NULL;
SDL_Surface* quit_menu = NULL;

SDL_Surface* optionsOFF = NULL;
SDL_Surface* soundON = NULL;
SDL_Surface* soundOFF = NULL;
SDL_Surface* optionsback=NULL;

SDL_Surface* highscoreOFF=NULL;
SDL_Surface* highscoreON=NULL;

SDL_Surface* instructionOFF = NULL;
SDL_Surface* instructionON = NULL;

SDL_Surface* creditsOFF = NULL;
SDL_Surface* creditsON = NULL;

SDL_Event event;
SDL_Event mouse_event;

SDL_Color textColor = { 255, 0, 0};

#endif // VARIABLES_H_INCLUDED
