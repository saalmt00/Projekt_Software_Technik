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

    void Name_Playlist(std::string point_Name)
    {

        Name = point_Name.c_str();
        printf("Name der Playlist:");
        std::cout << point_Name << std::endl;
        printf("\n\n\n\n\n");
        
    }

    void Einlesefunktion(std::string Lieder)
    {

        std::ifstream input(Lieder);
        int i = point_Count;

        while(std::getline(input, point_Playlist[i])){
            i++;
            point_Count = i;
        }

        input.close();

    }

    void Playlist_auflisten()
    {

        std::cout << Name << std::endl;
        printf("\n");
        printf("             Track Name              Artist Name                                                 Genres              Time\n\n");

        for(int i=0; i<point_Count; i++){
            if(i<9){
                printf("Lied Nr. %d:  ", i+1);
                std::cout << point_Playlist[i] << std::endl;
            }

            else{
                printf("Lied Nr. %d: ", i+1);
                std::cout << point_Playlist[i] << std::endl;
            }

        }

        printf("\n\n");

    }

    void Play_Song(std::string Songname)
    {

        system("clear");
        
        for(int i = 0; i<point_Count; i++){

            std::string Titel;
            std::string Artist;
            std::string Genre;
            double Time;
            std::string Trenner;
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

                    if(o==3)
                    {
                        Artist = Trenner;
                    }
                        
                    if(o==5)
                    {
                        Genre = Trenner;
                    }

                    
                }
                
                stream_line >> Time;

                int time_min = static_cast<int>(Time);
                double time_just_sec = Time-time_min;
                time_just_sec = time_just_sec*100;
            
                while(true)
                {
                    
                    time_just_sec = time_just_sec/100-0.01;
                    if(time_just_sec<0)
                    {
                        time_min = time_min-1;
                        time_just_sec = 0.59;

                    } 
                    if(time_min<0)
                    {
                        break;
                    }

                    time_just_sec = time_just_sec*100;
                    std::cout << "Now is playing: " << Titel << ", from the Artist: " << Artist;
                    
                    if(time_just_sec<9)
                    {
                        printf("    %d.0%0.f/%0.2f\n",time_min,time_just_sec,Time);
                    }
                    else
                    {
                        printf("    %d.%0.f/%0.2f\n",time_min,time_just_sec,Time);
                    }
                    
                    

                    system("sleep 1");
                    system("clear");

                    
                }
                



            }
    

        }


    }


    void Start_Playlist(){


        std::string Titel;
        std::string Artist;
        std::string Genre;
        double Time;
        std::string Trenner;

        for(int i = 0; i<point_Count; i++)
        {
            std::stringstream stream_line(point_Playlist[i]);

            


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
                        
                if(o==5)
                {
                    Genre = Trenner;
                }

                    
            }
                
            stream_line >> Time;

            int time_min = static_cast<int>(Time);
            double time_just_sec = Time-time_min;
            time_just_sec = time_just_sec*100;

            while(true)
            {
                    
                time_just_sec = time_just_sec/100-0.01;
                if(time_just_sec<0)
                {
                    time_min = time_min-1;
                    time_just_sec = 0.59;

                } 
                if(time_min<0)
                {
                    break;
                }

                time_just_sec = time_just_sec*100;
                std::cout << "Now is playing: " << Titel << ", from the Artist: " << Artist;
                    
                if(time_just_sec<10)
                {
                    printf("    %d.0%0.f/%0.2f\n",time_min,time_just_sec,Time);
                    }
                else
                {
                    printf("    %d.%0.f/%0.2f\n",time_min,time_just_sec,Time);
                }
                    
                    

                system("sleep 1");
                system("clear");

                    
            }
        }



    }


    void Remove_Song(std::string Songname){

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

    }

    void Song_Hinzufügen(std::string Song)
    {

        std::ifstream input(Song);
        int i = point_Count;

        std::getline(input, point_Playlist[i]);
        input.close();

        point_Count++;
    }



};

int main()
{

    Playlist Playlist;

    Playlist.Name_Playlist("Playlist");

    Playlist.Einlesefunktion("Playlist_Spotify.txt");
        
    Playlist.Playlist_auflisten();

    //Playlist.Play_Song("Fighter");

    //Playlist.Start_Playlist();

    Playlist.Remove_Song("Fighter");

    Playlist.Playlist_auflisten();

    Playlist.Song_Hinzufügen("HOV.txt");

    Playlist.Playlist_auflisten();

    return 0;
} 