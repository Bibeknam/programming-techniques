///THE HEADER FILES
#include "SDL.h"
#include "SDL_image.h"
#include <SDL_mixer.h>
#include <string>

#include "heli.h"
#include "loader.h"
#include "timer.h"
#include "window.h"
#include "obstacles.h"
#include "game_functions.h"
#include "play.h"

int main(int argc, char* args[])
{
    bool cont=true;
    //Initialize
    if( init() == false )
    {
        return 1;
    }

    Window my;
    my.toggle_fullscreen();
    wel_come();     ///WELCOME SCREEN FUNCTION CALL
    int opt;
    while(cont)
    {
        opt=game_menu();        ///GAME MENU FUNCTION CALL
        switch(opt)
        {
            case 1:
                play();         ///GAME LOOP
                break;
            case 2:
            ///OPTIONS
                break;
            case 3:
                ///HIGHSCORES
                break;
            case 4:
                ///INSTRUCTIONS
                break;
            case 5:
                ///CREDITS
                break;
            case 6:
                ///QUIT FROM PROGRAM
                cont=false;
                break;
            default:
                break;

        }
    }

    clean_up();         ///FREES THE MEMORY
    return 0;
}
