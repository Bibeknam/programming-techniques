#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <sstream>
#include "heli.h"
///FUNCTION PROTOTYPE
void sound_off();
void sound_on();
void clean_menu_surfaces();
void update_screen(Timer& time,int score);

int game_menu()
{
    ///VARIABLE DECLARATION
    int choice;
    int x,y;
    ///LOAD THE MENU IMAGES
    menu = load_image("images/menu/menu.png");
    play_menu = load_image("images/menu/play.png");
    option_menu = load_image("images/menu/options.png");
    Score_menu = load_image("images/menu/highscore.png");
    Instruc_menu = load_image("images/menu/instruction.png");
    credits_menu = load_image("images/menu/credits.png");
    quit_menu = load_image("images/menu/quit.png");

    bool session=true;

    apply_surface(0,0,menu,screen);
    proceed= Mix_LoadWAV("sound/proceed.wav");
    Mix_PlayChannel(-1,proceed,0);                  ///PLAYS PROCEED SOUND
    SDL_Flip(screen);
    SDL_Delay(5000);                                ///SETS THE DELAY

    back_music=Mix_LoadWAV("sound/menu.wav");
    Mix_PlayChannel(-1,back_music,0);               ///PLAYS THE BACKGROUND MUSIC
    selection=Mix_LoadWAV("sound/sound.wav");
    int music_sol=0;

    ///Menu Loop:
    while(session)
    while(SDL_PollEvent(&mouse_event))
        {
            if(mouse_event.type==SDL_MOUSEMOTION)       ///WHEN MOUSE IS IN MOTION
            {
                    x = mouse_event.motion.x;           ///SET THE COORDINATES
                    y = mouse_event.motion.y;

                    if((x>960)&&(x<1210)&&(y>120)&&(y<180))     ///HIGHLIGHT PLAY
                    {
                        apply_surface(0,0,play_menu,screen);
                        if(music_sol==0)
                        {
                            Mix_PlayChannel(-1,selection,0);        ///PLAYS THE SELECTION SOUND
                            music_sol=1;
                        }
                    }
                    else if((x>960)&&(x<1210)&&(y>200)&&(y<280))       ///HIGHLIGHT OPTIONS
                    {
                        apply_surface(0,0,option_menu,screen);
                        if(music_sol==0)
                            {
                                Mix_PlayChannel(-1,selection,0);        ///PLAYS THE SELECTION SOUND
                                music_sol=1;
                            }

                    }
                    else if((x>955)&&(x<1210)&&(y>300)&&(y<380))        ///HIGHLIGHT HIGHSCORE
                    {
                        apply_surface(0,0,Score_menu,screen);
                        if(music_sol==0)
                          {
                            Mix_PlayChannel(-1,selection,0);            ///PLAYS THE SELECTION SOUND
                            music_sol=1;
                          }

                    }
                    else if((x>950)&&(x<1220)&&(y>400)&&(y<460))    ///HIGHLIGHT INSTRUCTION
                    {
                        apply_surface(0,0,Instruc_menu,screen);
                        if(music_sol==0)
                        {
                            Mix_PlayChannel(-1,selection,0);        ///PLAYS THE SELECTION SOUND
                            music_sol=1;
                        }
                    }
                    else if((x>960)&&(x<1205)&&(y>470)&&(y<550))        ///HIGHLIGHT CREDITS
                    {
                        apply_surface(0,0,credits_menu,screen);
                        if(music_sol==0)
                        {
                            Mix_PlayChannel(-1,selection,0);            ///PLAYS THE SELECTION SOUND
                            music_sol=1;
                        }
                    }
                    else if((x>960)&&(x<1205)&&(y>550)&&(y<680))        ///HIGHLIGHT QUIT
                    {
                        apply_surface(0,0,quit_menu,screen);
                        if(music_sol==0)
                        {
                            Mix_PlayChannel(-1,selection,0);            ///PLAYS THE SELECTION SOUND
                            music_sol=1;
                        }
                    }
                    else
                    {
                        apply_surface(0,0,menu,screen);
                        music_sol=0;
                    }
                    SDL_Flip(screen);                               ///UPDATES THE SCREEN
            }
            if(mouse_event.type == SDL_MOUSEBUTTONDOWN)             ///IF MOUSE BUTTON IS PRESSED
            {
                    x = mouse_event.motion.x;                       ///SETS THE COORDINATES
                    y = mouse_event.motion.y;
                    if((x>960)&&(x<1210)&&(y>120)&&(y<180))
                    {

                            choice = 1;                             ///RETURNS 1
                            session = false;
                    }
                    else if((x>960)&&(x<1210)&&(y>200)&&(y<280))
                    {
                                                                ///OPTIONS LOOP
                                ///LOAD THE OPTION IMAGES
                        optionsOFF = load_image("images/options off.png");
                        soundON = load_image("images/sound on.png");
                        soundOFF = load_image("images/sound off.png");
                        optionsback=load_image("images/options back.png");
                        apply_surface(0,0,optionsOFF,screen);
                        SDL_Flip(screen);

                        int ax,ay;
                        bool bye = false;
                        music_sol = 0;

                        while(!bye)
                        {

                            while(SDL_PollEvent(&mouse_event))
                            {
                                if(mouse_event.type==SDL_MOUSEMOTION)       ///HIGHLIGHTS
                                    {
                                        ax = mouse_event.motion.x;
                                        ay = mouse_event.motion.y;

                                        if((ax>520)&&(ax<800)&&(ay>280)&&(ay<330))
                                        {
                                            apply_surface(0,0,soundON,screen);
                                            if(music_sol==0)
                                            {
                                                Mix_PlayChannel(-1,selection,0);
                                                music_sol=1;
                                            }
                                        }
                                        else if((ax>520)&&(ax<800)&&(ay>420)&&(ay<480))
                                        {
                                            apply_surface(0,0,soundOFF,screen);
                                            if(music_sol==0)
                                            {
                                                Mix_PlayChannel(-1,selection,0);
                                                music_sol=1;
                                            }
                                        }
                                        else if((ax>1050)&&(ax<1200)&&(ay>620)&&(ay<690))
                                        {
                                            apply_surface(0,0,optionsback,screen);
                                            if(music_sol==0)
                                            {
                                                Mix_PlayChannel(-1,selection,0);
                                                music_sol=1;
                                            }
                                        }

                                        else
                                        {
                                            apply_surface(0,0,optionsOFF,screen);
                                            music_sol = 0;
                                        }
                                    }

                                if(mouse_event.type == SDL_MOUSEBUTTONDOWN)     ///IF MOUSE BUTTON IS
                                    {                                           ///PRESSED
                                         ax = mouse_event.motion.x;
                                         ay = mouse_event.motion.y;
                                             if((ax>1050)&&(ax<1200)&&(ay>620)&&(ay<690))
                                               {
                                                        bye = true;
                                               }
                                            else if((ax>520)&&(ax<800)&&(ay>420)&&(ay<480))
                                            {
                                                sound_off();
                                            }
                                            else if((ax>520)&&(ax<800)&&(ay>280)&&(ay<330))
                                            {
                                                sound_on();
                                            }

                                    }
                                SDL_Flip(screen);
                            }
                            SDL_Flip(screen);
                        }
                        apply_surface(0,0,menu,screen);
                        SDL_Flip(screen);

                               /* choice = 2;
                                session = false;*/
                    }
                    else if((x>955)&&(x<1210)&&(y>300)&&(y<380))
                            {
                                ///HIGHSCORE LOOP
                                //high_score();
                                highscoreOFF=load_image("images/highscore off.png");
                                highscoreON=load_image("images/highscore on.png");
                                apply_surface(0,0,highscoreOFF,screen);
                                SDL_Flip(screen);
                                int ax,ay;
                        bool bye = false;
                        music_sol = 0;

                        while(!bye)
                        {

                            while(SDL_PollEvent(&mouse_event))
                            {
                                if(mouse_event.type==SDL_MOUSEMOTION)
                                    {
                                        ax = mouse_event.motion.x;
                                        ay = mouse_event.motion.y;

                                        if((ax>1120)&&(ax<1240)&&(ay>660)&&(ay<720))
                                        {
                                            apply_surface(0,0,highscoreON,screen);
                                            if(music_sol==0)
                                            {
                                                Mix_PlayChannel(-1,selection,0);
                                                music_sol=1;
                                            }

                                        }
                                        else
                                        {
                                            apply_surface(0,0,highscoreOFF,screen);
                                            music_sol = 0;
                                        }
                                    }

                                if(mouse_event.type == SDL_MOUSEBUTTONDOWN)
                                    {
                                         ax = mouse_event.motion.x;
                                         ay = mouse_event.motion.y;
                                             if((ax>1120)&&(ax<1240)&&(ay>660)&&(ay<720))
                                               {
                                                        bye = true;
                                               }
                                    }
                                SDL_Flip(screen);
                            }
                            SDL_Flip(screen);
                        }
                        apply_surface(0,0,menu,screen);
                        SDL_Flip(screen);
                                    /*choice = 3;
                                    session = false;*/
                            }
                    else if((x>950)&&(x<1220)&&(y>400)&&(y<460))
                            {
                                ///Instructions loop:
                        instructionOFF = load_image("images/instruction off.png");
                        instructionON = load_image("images/instruction on.png");
                        apply_surface(0,0,instructionOFF,screen);
                        SDL_Flip(screen);

                        int ax,ay;
                        bool bye = false;
                        music_sol = 0;

                        while(!bye)
                        {

                            while(SDL_PollEvent(&mouse_event))
                            {
                                if(mouse_event.type==SDL_MOUSEMOTION)
                                    {
                                        ax = mouse_event.motion.x;
                                        ay = mouse_event.motion.y;

                                        if((ax>1050)&&(ax<1200)&&(ay>668)&&(ay<705))
                                        {
                                            apply_surface(0,0,instructionON,screen);
                                            if(music_sol==0)
                                            {
                                                Mix_PlayChannel(-1,selection,0);
                                                music_sol=1;
                                            }
                                        }
                                        else
                                        {
                                            apply_surface(0,0,instructionOFF,screen);
                                            music_sol = 0;
                                        }
                                    }

                                if(mouse_event.type == SDL_MOUSEBUTTONDOWN)
                                    {
                                         ax = mouse_event.motion.x;
                                         ay = mouse_event.motion.y;
                                             if((ax>1050)&&(ax<1200)&&(ay>668)&&(ay<705))
                                               {
                                                        bye = true;
                                               }
                                    }
                                SDL_Flip(screen);
                            }
                            SDL_Flip(screen);
                        }
                        apply_surface(0,0,menu,screen);
                        SDL_Flip(screen);

                                    /*choice = 4;
                                    session = false;*/
                            }
                    else if((x>960)&&(x<1205)&&(y>470)&&(y<550))
                    {
                        ///Credits loop:
                        creditsOFF = load_image("images/credits message off.png");
                        creditsON = load_image("images/credits message on.png");
                        apply_surface(0,0,creditsOFF,screen);
                        SDL_Flip(screen);

                        int ax,ay;
                        bool bye = false;
                        music_sol = 0;

                        while(!bye)
                        {

                            while(SDL_PollEvent(&mouse_event))
                            {
                                if(mouse_event.type==SDL_MOUSEMOTION)
                                    {
                                        ax = mouse_event.motion.x;
                                        ay = mouse_event.motion.y;

                                        if((ax>1050)&&(ax<1200)&&(ay>668)&&(ay<705))
                                        {
                                            apply_surface(0,0,creditsON,screen);
                                            if(music_sol==0)
                                            {
                                                Mix_PlayChannel(-1,selection,0);
                                                music_sol=1;
                                            }
                                        }
                                        else
                                        {
                                            apply_surface(0,0,creditsOFF,screen);
                                            music_sol = 0;
                                        }
                                    }

                                if(mouse_event.type == SDL_MOUSEBUTTONDOWN)
                                    {
                                         ax = mouse_event.motion.x;
                                         ay = mouse_event.motion.y;
                                             if((ax>1050)&&(ax<1200)&&(ay>668)&&(ay<705))
                                               {
                                                        bye = true;
                                               }
                                    }
                                SDL_Flip(screen);
                            }
                            SDL_Flip(screen);
                        }
                        apply_surface(0,0,menu,screen);
                        SDL_Flip(screen);

                                    /*choice = 5;
                                    session = false;*/
                    }
                    else if((x>960)&&(x<1205)&&(y>550)&&(y<680))
                    {
                                    choice = 6;                 ///QUIT
                                    session = false;
                            }
                       }

                         switch( mouse_event.type )
                            {
                                case SDL_KEYDOWN:
                                if( mouse_event.key.keysym.sym == SDLK_ESCAPE )
                                {
                                    choice = 6;             ///IF ESCAPE IS PRESSED, QUIT
                                    session = false;
                                }
                                break;

                                case SDL_QUIT:
                                    choice = 6;
                                    session = false;
                                break;
                            }
        }
    clean_menu_surfaces();                      ///FREE THE SURFACE POINTERS
    return choice;
}

void update_screen(Timer& TimE,int score)       ///UPDATES THE SCREEN
{
    std::stringstream samaya;
    int a=TimE.get_ticks();
    if(a<60000)
        {
           samaya<< "SCORE: "<<score
           <<"  TIME: " << a/60000<<" : "<<a / 1000;            ///DISPLAYS SCORE AND TIME
        }
        else
        {
            int sec=a/1000;
            int min=0;
            min=sec/60;
            sec-=min*60;
            samaya<< "SCORE:  "<<score
            << "    TIME: " << min<<" : "<<sec;

        }
    message = TTF_RenderText_Solid( font , samaya.str().c_str() , textColor ) ;
    apply_surface((SCREEN_WIDTH-message->w)/2,0,message,screen);
    SDL_FreeSurface(message);

}

void clean_menu_surfaces()
{
    ///Free surfaces
    SDL_FreeSurface(menu);
    SDL_FreeSurface(play_menu);
    SDL_FreeSurface(option_menu);
    SDL_FreeSurface(Score_menu);
    SDL_FreeSurface(Instruc_menu);
    SDL_FreeSurface(credits_menu);
    SDL_FreeSurface(quit_menu);

    SDL_FreeSurface(optionsOFF);
    SDL_FreeSurface(soundON);
    SDL_FreeSurface(soundOFF);
    SDL_FreeSurface(optionsback);
    SDL_FreeSurface(highscoreOFF);
    SDL_FreeSurface(highscoreON);
    SDL_FreeSurface(instructionOFF);
    SDL_FreeSurface(instructionON);
    SDL_FreeSurface(creditsOFF);
    SDL_FreeSurface(creditsON);

    Mix_FreeChunk(selection);
    Mix_FreeChunk(back_music);
    Mix_FreeChunk(proceed);

}
void sound_off()
{
    Mix_PauseMusic();
    return ;
}
void sound_on()
{
    Mix_ResumeMusic();

}
#endif // FUNCTIONS_H_INCLUDED
