#ifndef LOADER_H_INCLUDED
#define LOADER_H_INCLUDED

#include"SDL.h"
#include "SDL_image.h"
#include <string>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "obstacles.h"
#include "variables.h"

SDL_Surface *load_image( std::string filename,int n=0 )         ///FUNCTION FOR LOADING IMAGE
{
    ///The image that's loaded
    SDL_Surface* loadedImage = NULL;

    ///The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    ///Load the image
    loadedImage = IMG_Load( filename.c_str() );

    ///If the image loaded
    if( loadedImage != NULL )
    {
        ///Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );

        ///Free the old surface
        SDL_FreeSurface( loadedImage );

        ///If the surface was optimized
        if( optimizedImage != NULL )
        {
            if(n==0)
            {

            ///Map the color key
            Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 73, 203, 58 );

            ///Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
            }
            else if(n==1)
            {
                ///Map the color key
            Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 255, 255, 128 );

            ///Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
            }

        }
    }

    ///Return the optimized surface
    return optimizedImage;
}
bool load_files()
{
    ///Load the background image
    background = load_image( "images/new pahad with same resoln.png" );

    ///If there was a problem in loading the background
    if( background == NULL )
    {
        return false;
    }
    ///Open the font
    font = TTF_OpenFont( "VINERITC.ttf", 30 );
    if( font == NULL )
    {
        return false;
    }
    OBSTACLES=load_image("images/hitwalls.bmp");
    if(OBSTACLES==NULL)
    {
        return false;
    }
    transparent=load_image("images/transparent.png");
    ///Load the helicopter image
    heli = load_image( "images/heli.png" );

    ///If there was a problem in loading the helicopter
    if( heli == NULL )
    {
        return false;
    }

    ///Load the game music
    music = Mix_LoadMUS( "sound/heli-running2.wav" );

    ///If there was a problem loading the game music
    if( music == NULL )
    {
        return false;
    }

    ///If everything loaded fine
    return true;
}

bool init()
{
    ///Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {

        return false;
    }

    ///Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    ///If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }
    ///Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;
    }
     ///Initialize SDL_mixer
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;
    }

     ///Set the window caption
    SDL_WM_SetCaption( "HELICOPTER HURDLE !!", NULL );

    ///If everything initialized fine
    return true;
}

void clean_up()
{
    ///Free the surface
    SDL_FreeSurface( heli );
    SDL_FreeSurface(OBSTACLES);
    SDL_FreeSurface( background );
    SDL_FreeSurface( welcome);
    SDL_FreeSurface( transparent);

    ///Close the font that was used
    TTF_CloseFont( font );
    ///Free the music
    Mix_FreeMusic( music );
    Mix_FreeChunk(boom);
    Mix_FreeChunk(loading);
    ///Quit SDL_ttf
    TTF_Quit();
    ///Quit SDL_mixer
    Mix_CloseAudio();
    ///Quit SDL
    SDL_Quit();
}
#endif // LOADER_H_INCLUDED

