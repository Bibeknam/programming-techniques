#ifndef PLAY_H_INCLUDED
#define PLAY_H_INCLUDED
void wel_come()                                   ///WELCOME FUNCTION TO LOAD IMAGE AND SOUND
{
    welcome=load_image("images/welcome.png");
    apply_surface(0,0,welcome,screen);
    loading=Mix_LoadWAV("sound/loading.wav");
    Mix_PlayChannel(-1,loading,0);
    SDL_Flip(screen);
    SDL_Delay(2000);
}
void wall3_coord()                                  ///SETS COORDINATES OF THE OBSTACLES
{
    wall3[0].x =0;  wall3[0].w=30;  wall3[0].h=234;
    wall3[0].y =0;
    wall3[1].x =0;  wall3[1].w=30;  wall3[1].h=234;
    wall3[1].y =400;
    wall3[2].x =650;  wall3[2].w=30;  wall3[2].h=234;
    wall3[2].y =50;
    wall3[3].x =950;  wall3[3].w=30;  wall3[3].h=234;
    wall3[3].y =450;
    wall3[4].x =1200;  wall3[4].w=30;  wall3[4].h=234;
    wall3[4].y =90;
    wall3[5].x =1500;  wall3[5].w=30;  wall3[5].h=234;
    wall3[5].y =303;
    wall3[6].x =1700;  wall3[6].w=30;  wall3[6].h=234;
    wall3[6].y =502;
}
int play()
{
        wall2.x=0;
        wall2.y=SCREEN_HEIGHT;
        wall2.w=SCREEN_WIDTH;
        wall2.h=20;

        wall3_coord();
   ///Quit flag
    bool quit = false;
    ///The offsets of the background
    int bgX = 0, bgY = 0;
    Heli myheli;                        ///CREATING OBJECT OF THE HELI CLASS

    ///The frame rate regulator
    Timer fps;                          ///CREATING OBJECT OF THE TIMER CLASS
    obstacle obs;                       ///CREATING OBJECT OF THE OBSTACLE CLASS

    ///Create a window
    Window myWindow;

    ///If the window failed
    if( myWindow.error() == true )
    {
        return 1;
    }

    ///Load the files
    if( load_files() == false )
    {
        return 1;
    }

    ///Start the frame timer
    fps.start();
    ///While the user hasn't quit
    while( quit == false )
    {
        if( Mix_PlayMusic( music, 0 ) == -1 )       ///PLAY THE GAME MUSIC
        {
            return 1;
        }

        ///While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            ///Handle window events
            myWindow.handle_events();
            ///Handle events for the heli
            myheli.handle_input();

            if(event.type==SDL_KEYDOWN)
            {
                ///If escape was pressed
                 if( event.key.keysym.sym==SDLK_ESCAPE)
                {
                        Mix_FreeMusic( music );
                          quit=true;
                }

                ///If the user has Xed out the window
                else if( event.type == SDL_QUIT )
                {
                    ///Quit the program
                    quit = true;
                }

            }
        }
        if(fps.get_ticks()<10000)
        {
            ///Scroll background
            bgX -= 10;
            for(int i=0;i<7;++i)
            {
                ///Move the collision wall along with the background
                wall3[i].x-=10;
            }

        }
        else if(fps.get_ticks()<40000)
        {

            bgX-=15;
            for(int i=0;i<7;++i)
            {
                wall3[i].x-=15; ///Move the collision wall along with the background
            }
        }
        else if(fps.get_ticks()<90000)
        {

            bgX-=20;
            for(int i=0;i<7;++i)
            {
                wall3[i].x-=20;     ///Move the collision wall along with the background
            }
        }

        else if(fps.get_ticks()<120000)
        {

            bgX-=25;
            for(int i=0;i<7;++i)
            {
                wall3[i].x-=25;     ///Move the collision wall along with the background
            }
        }

        else
        {

            bgX-=30;

            for(int i=0;i<7;++i)
            {
                wall3[i].x-=10;     ///Move the collision wall along with the background
            }
        }
        //If the background has gone too far
        if( bgX <= -background->w )
        {
            ///Reset the offset of background
            bgX = 0;

            ///RESET THE OFFSET OF THE COLLISION WALL
            wall3[0].x =0;
            wall3[0].y =0;
            wall3[1].x =0;
            wall3[1].y =400;
            wall3[2].x =650;
            wall3[2].y =50;
            wall3[3].x =950;
            wall3[3].y =450;
            wall3[4].x =1200;
            wall3[4].y =90;
            wall3[5].x =1500;
            wall3[5].y =303;
            wall3[6].x =1700;
            wall3[6].y =502;

        }

        ///Show the background
        apply_surface( bgX, bgY, background, screen );
        apply_surface( bgX + background->w, bgY, background, screen );

        ///If the window failed
        if( myWindow.error() == true )
        {
            return 1;
        }

        ///move the helicopter
        myheli.move();

        ///show the helicopter on the screen
        myheli.show();
        obs.show();         ///SHOWS THE OBSTACLES

        update_screen( fps , myheli.get_score());       ///DISPLAYS THE SCORE AND TIME
        if(fps.get_ticks()>300000)                  ///IF TIME IS GREATER THAN 5 MIN, THEN QUIT:
        {
            game_over=load_image("images/game_over.png");
            apply_surface(0,0,game_over,screen);
            SDL_Flip(screen);
            Mix_FreeMusic( music );
            quit=true;

        }
        ///Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }
        ///Set the camera
        myheli.set_camera();

         ///Show the background
        apply_surface( 0, 0, background, screen, &camera );

        ///Cap the frame rate
        if( fps.get_ticks() < 1000 /FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
    }

    return 0;
}


#endif // PLAY_H_INCLUDED
