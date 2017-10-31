#ifndef HIGHSCORE_H_INCLUDED
#define HIGHSCORE_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;
class HighScore{
      private:
              int highscore[5];
              std::string name[5];
      public:
              HighScore( void );
              void check_file( std::string filename );
              void read_file( std::string filename );
              void write_file( std::string filename );
              void bubble_sort( void );
              bool isHighScore( int score );
              void insertScore( int score );
              void insertName( int rank, std::string highscorer );
              //void show_score( void );
              int getRank( int score );
              void arrangeName( int rank );
              int* getScoreList( void ) ;
              std::string* getNameList( void ) ;


};

HighScore :: HighScore( void )
{
        for( int i = 0; i<5 ; i++ ) {
             highscore[i] = 0;
             //strcpy( name[i], "unknown" );
             name[i] = "unknown" ;
        }
}

void HighScore :: check_file( std::string filename )
{
     // ifstream constructor opens the file
     ifstream scoreFile( filename.c_str() , ios::in );

     // exit program if ifstream could not open file
     if ( !scoreFile )
     {
        write_file( filename );
     } // end if

}

void HighScore :: read_file( std::string filename )
{
    // ifstream constructor opens the file
     ifstream scoreFile( filename.c_str(), ios::in );

     // exit program if ifstream could not open file
     if ( !scoreFile )
     {
        cerr << "File could not be opened" << endl;
        return;
     } // end if

     // read each record in file
     for( int i = 0; i < 5; i++ ){
          scoreFile >> highscore[i] >> name[i] ;
     }

}


void HighScore :: write_file( std::string filename )
{
    // ofstream constructor opens file
     ofstream scoreFile( filename.c_str(), ios::out );

     // exit program if unable to create file
     if ( !scoreFile ) // overloaded ! operator
     {
        cerr << "File could not be opened" << endl;
        return;
     } // end if


     for( int i = 0; i < 5; i++ ) {
        scoreFile << highscore[i] << ' ' << name[i] << endl;
     }

}

void HighScore :: bubble_sort( void )
{
     for( int i = 0; i < 5; i++ ){
          for( int j = i+1; j < 5; j++ ){
               if( highscore[i] < highscore[j] ){
                    int temp = highscore[i];
                    highscore[i] = highscore[j];
                    highscore[j] = temp;
               }
          }
     }
}


bool HighScore :: isHighScore( int score ) {
          read_file( "highscore.txt" );
          bubble_sort();

          if( score > highscore[4] ){
              return true;
          }
          else{
              return false;
          }

}

void HighScore :: insertScore( int score )
{
     highscore[4] = score ;
}

void HighScore :: insertName( int rank , std::string highscorer )
{
     //strcpy( name[rank-1], highscorer );
     name[rank-1] = highscorer ;
}

int HighScore :: getRank( int score )
{
    for( int i = 4 ; i >= 0; i-- ){
         if( score == highscore[i] ) {
             return (i+1) ;
         }
    }
}

void HighScore :: arrangeName( int rank )
{
     for( int i = 4 ; i > (rank-1) ; i-- ){
          //strcpy ( name[i], name[i-1] ) ;
          name[i] = name[i-1] ;
     }
}
int* HighScore :: getScoreList( void ) {
     return highscore;
}

std::string* HighScore :: getNameList( void ) {
     return name;
}


///GLOBAL FUNCTION

void high_score()
{

HighScore hs;
    int *score;
    std::string *name;

    hs.check_file("highscore.txt");
    hs.read_file("highscore.txt");

    score = hs.getScoreList();
    name = hs.getNameList();

    for( int i = 0; i < 5; i++ ){
         cout <<  score[i] << "    " << name[i]  << endl ;
    }
    getch();
}


#endif // HIGHSCORE_H_INCLUDED
