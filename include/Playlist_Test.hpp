#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#define N 100


class Playlist{

    private:

    std::string point_Playlist[N];
    int point_Count = 0;
    std::string Name;

    public:

    std::string Name_Playlist(std::string point_Name)
    {
        Name = point_Name.c_str();
        return Name;
    }

    int Einlesefunktion(std::string Lieder)
    {
        std::ifstream input(Lieder);
        int i = point_Count;

        while(std::getline(input, point_Playlist[i]))
        {
            i++;
            point_Count = i;
        }

        input.close();

        return point_Count;
    }

    std::string Playlist_auflisten(int a)
    { 
        return point_Playlist[a];
    }

    int Play_Song_Songline(std::string Songname)
    {
        int Testline;
        
        for(int i = 0; i<point_Count; i++)
        {
            
    //Code von ChatGBT 
    //{
            size_t pos = point_Playlist[i].find(Songname);

            if(pos != std::string::npos)
            {
    //}
                std::stringstream stream_line(point_Playlist[i]);

                Testline = i;                

            }
        }

    return Testline;
    }

    std::string Play_Song_Titel(std::string Songname)
    {
        std::string Titel;
        std::string Trenner;
      
        for(int i = 0; i<point_Count; i++)
        {
       
    //Code von ChatGBT 
    //{
            size_t pos = point_Playlist[i].find(Songname);

            if(pos != std::string::npos)
            {
    //}
                std::stringstream stream_line(point_Playlist[i]);

                for(int o = 0; o<6; o++)
                {
                    std::getline(stream_line, Trenner, '"');

                    if(o==1)
                    {
                        Titel = Trenner;
                    }                   
                }               
            }    
        }

    return Titel;

    }

    std::string Play_Song_Artist(std::string Songname)
    {
        std::string Artist;
        std::string Trenner;
        
        for(int i = 0; i<point_Count; i++)
        {
    
    //Code von ChatGBT 
    //{
            size_t pos = point_Playlist[i].find(Songname);

            if(pos != std::string::npos)
            {
    //}
                std::stringstream stream_line(point_Playlist[i]);

                for(int o = 0; o<6; o++)
                {
                    std::getline(stream_line, Trenner, '"');

                    if(o==3)
                    {
                        Artist = Trenner;
                    }                 
                }
            }    
        }

    return Artist;
    }

    std::string Play_Song_Genre(std::string Songname)
    {
        std::string Genre;
        std::string Trenner;

        for(int i = 0; i<point_Count; i++)
        {
       
    //Code von ChatGBT 
    //{

            size_t pos = point_Playlist[i].find(Songname);

            if(pos != std::string::npos)
            {
    //}
                std::stringstream stream_line(point_Playlist[i]);

                for(int o = 0; o<6; o++)
                {
                    std::getline(stream_line, Trenner, '"');
                        
                    if(o==5)
                    {
                        Genre = Trenner;
                    }                  
                }
            }   
        }

    return Genre;
    }

    double Play_Song_Time(std::string Songname)
        {
            double Time;
            std::string Trenner;
            
            for(int i = 0; i<point_Count; i++)
            {

        //Code von ChatGBT 
        //{
                size_t pos = point_Playlist[i].find(Songname);

                if(pos != std::string::npos)
                {
        //}
                    std::stringstream stream_line(point_Playlist[i]);

                    for(int z=0; z<6; z++)
                    {
                        std::getline(stream_line, Trenner ,'"');
                    }
                    stream_line >> Time;
                }
            }

        return Time;
    }



    int Remove_Song(std::string Songname){

        for(int i =0; i<point_Count; i++)
        {

            size_t pos = point_Playlist[i].find(Songname);

            if(pos != std::string::npos)
            {
                point_Playlist[i].clear();
                    

                while(i<point_Count)
                {
                    point_Playlist[i] = point_Playlist[i+1];
                    i++;

                    if(i == point_Count){
                        point_Playlist[i].clear();
                        point_Count = point_Count-1;
                    }
                }
            }       
        }

        return point_Count;
    }


    int Song_Hinzufügen(std::string Song)
    {

        std::ifstream input(Song);
        int i = point_Count;

        std::getline(input, point_Playlist[i]);
        input.close();

        point_Count++;

        return point_Count;
    }

    std::string Playlist_sortieren(int x, std::string Sortieren){

        std::string temp;
        std::string temp_Playlist;
        std::string Titel_i;
        std::string Titel_b;
        std::string Artist_i;
        std::string Artist_b;
        std::string Genre_i;
        std::string Genre_b;
        std::string Trenner;
        double Time_i;
        double Time_b;

        if(Sortieren == "Titel")
        {
            for(int i=0; i<point_Count; i++)
            {                       
                for(int b=i+1; b<point_Count; b++)
                {
                    std::stringstream stream_line(point_Playlist[i]);

                    for(int o=0; o<6; o++)
                    {        
                        std::getline(stream_line, Trenner, '"');

                        if(o==1)
                        {
                            Titel_i = Trenner;
                        }
                    }
                   
                    std::stringstream stream_line_b(point_Playlist[b]);
    
                    for(int z=0; z<6; z++)
                    {
                        std::getline(stream_line_b, Trenner ,'"');

                        if(z==1)
                        {
                            Titel_b = Trenner;
                        }
                    }
                                
                    if(Titel_b < Titel_i)
                    {                                                   
                        temp_Playlist = point_Playlist[i];
                        point_Playlist[i] = point_Playlist[b];
                        point_Playlist[b] = temp_Playlist;
                    }                                                            
                }                        
            }
        }

        if(Sortieren == "Artist")
        {
            for(int i=0; i<point_Count; i++)
            {                       
                for(int b=i+1; b<point_Count; b++)
                {
                    std::stringstream stream_line(point_Playlist[i]);

                    for(int o=0; o<6; o++)
                    {        
                        std::getline(stream_line, Trenner, '"');

                        if(o==3)
                        {
                            Artist_i = Trenner;
                        }
                    }
   
                    std::stringstream stream_line_b(point_Playlist[b]);
                    
                    
                    for(int z=0; z<6; z++)
                    {
                        std::getline(stream_line_b, Trenner ,'"');

                        if(z==3)
                        {    
                            Artist_b = Trenner;
                        }
                    }

                                
                    if(Artist_b < Artist_i)
                    {
                        temp_Playlist = point_Playlist[i];
                        point_Playlist[i] = point_Playlist[b];
                        point_Playlist[b] = temp_Playlist;
                    }                                                            
                }                        
            }
        }

        if(Sortieren == "Genre")
        {            
            for(int i=0; i<point_Count; i++)
            {                       
                for(int b=i+1; b<point_Count; b++)
                {
                    std::stringstream stream_line(point_Playlist[i]);

                    for(int o=0; o<6; o++)
                    {        
                        std::getline(stream_line, Trenner, '"');

                        if(o==5)
                        {
                            Genre_i = Trenner;
                        }
                    }

                    
                    
                    std::stringstream stream_line_b(point_Playlist[b]);
                    
                    
                    for(int z=0; z<6; z++)
                    {
                        std::getline(stream_line_b, Trenner ,'"');

                        if(z==5)
                        {                            
                            Genre_b = Trenner;
                        }
                    }
                                
                    if(Genre_b < Genre_i)
                    {                                                   
                        temp_Playlist = point_Playlist[i];
                        point_Playlist[i] = point_Playlist[b];
                        point_Playlist[b] = temp_Playlist;
                    }                                                            
                }                        
            }
        }

        if(Sortieren == "Time"){

            for(int i=0; i<point_Count; i++)
            {                       
                for(int b=i+1; b<point_Count; b++)
                {

                    std::stringstream stream_line(point_Playlist[i]);

                    for(int o=0; o<6; o++)
                    {        
                        std::getline(stream_line, Trenner, '"');
                    }

                    stream_line >> Time_i;

                    std::stringstream stream_line_b(point_Playlist[b]);
                                        
                    for(int z=0; z<6; z++)
                    {
                        std::getline(stream_line_b, Trenner ,'"');
                    }

                    stream_line_b >> Time_b;

                    if(Time_b < Time_i)
                    {                                                    
                        temp_Playlist = point_Playlist[i];
                        point_Playlist[i] = point_Playlist[b];
                        point_Playlist[b] = temp_Playlist;
                    }                                                            
                }                                            
            }
        }

        return point_Playlist[x];
    }  

        
    int Suche(std::string Suchwort){

        std::string Temp_Playlist[N];
        int o=0;

        for(int i=0; i<point_Count; i++)
        {
            size_t pos = point_Playlist[i].find(Suchwort);

            if(pos != std::string::npos)
            {
                Temp_Playlist[o] = point_Playlist[i];
                o++;
            }
        }

        return o;
    }

    
    std::string Next_Song(int i){
        
        int Next_Songline = i+1;
        std::string Titel;
        std::string Artist;
        std::string Trenner;

        std::stringstream stream_line(point_Playlist[Next_Songline]);

        for(int o = 0; o<6; o++)
        {
            std::getline(stream_line, Trenner, '"');

            if(o==1)
            {
                Titel = Trenner;
            }

            if(o==3)
            {
                Artist = Trenner;
            }
        }

        return Titel;
    }

};




