#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#include <algorithm>
#define N 100


class Playlist{

    private:

    std::string point_Playlist[N];
    int point_Count = 0;
    std::string Name;

    public:

    void Playlist_auflisten()
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        system("clear");
        std::cout << Name << std::endl;
        printf("\n");
        printf("             Track Name              Artist Name                                                 Genres              Time\n\n");

        for(int i=0; i<point_Count; i++)
        {
            if(i<9)
            {
                printf("Lied Nr. %d:  ", i+1);
                std::cout << point_Playlist[i] << std::endl;
            }

            else
            {
                printf("Lied Nr. %d: ", i+1);
                std::cout << point_Playlist[i] << std::endl;
            }
        }
    }

    void Name_Playlist(std::string point_Name)
    {

        Name = point_Name.c_str();
        printf("Name der Playlist:");
        std::cout << point_Name << std::endl;
        printf("\n\n\n\n\n");

        Playlist_auflisten();       
    }

    void Song_Hinzufügen(std::string Song)
    {

        std::ifstream input(Song);    
        int i = point_Count;
 
        if(input.is_open())
        {  
            while(std::getline(input, point_Playlist[i]))
            {
                i++;
                point_Count = i;
            }
            input.close();
        }
        else
        {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            system("clear");
            std::cout << "Es konnte leider kein Song mit dem Namen '" << Song << "' hinzugefügt werden" << std::endl;
            system("sleep 10");
        }
        Playlist_auflisten();
    }


    void Play_Song(std::string Songname)
    {
        system("clear");
        
        for(int i = 0; i<point_Count; i++)
        {
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
            else
            {
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                std::cout << "Es konnten leider keine Songs mit dem Namen '" << Songname << "' gefunden werden" << std::endl; 
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");               
            }
        }
    }


    void Start_Playlist()
    {
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

                Next_Song(i);

                system("sleep 1");
                system("clear");                    
            }
        }
    }


    void Remove_Song(std::string Songname)
    {
        int o = 0;
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

                    if(i == point_Count)
                    {
                        point_Playlist[i].clear();
                        point_Count = point_Count-1;
                    }
                }
                o++;
            }                        
        }
        if(o == 0)
        {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            system("clear");
            std::cout << "Es konnte leider kein Song mit dem Namen '" << Songname << "' gefunden und entfernt werden" << std::endl;
            system("sleep 10");
            
        }       
        Playlist_auflisten();
    } 
  
    void Playlist_sortieren(std::string Sortieren)
    {
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

        if(Sortieren == "Time")
        {
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

        Playlist_auflisten();
    }  


    void Suche(std::string Suchwort)
    {
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
        if(o == 0)
        {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            system("clear");
            std::cout << "Es konnten leider keine Songs mit dem Suchwort '" << Suchwort << "' gefunden werden" << std::endl;
            system("sleep 10");

            Playlist_auflisten();
        }
        else
        {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            std::cout << Name << std::endl;
            printf("\n");
            printf("             Track Name              Artist Name                                                 Genres              Time\n\n");

            for(int u=0; u<o; u++)
            {
    
                if(o<9)
                {
                    printf("Lied Nr. %d:  ", u+1);
                    std::cout << Temp_Playlist[u] << std::endl;
                }

                else
                {
                    printf("Lied Nr. %d: ", u+1);
                    std::cout << Temp_Playlist[u] << std::endl;
                }
            }

            printf("\n\n");
        }
    }
    
    void Next_Song(int i)
    {  
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

        printf("\n");
        std::cout << "Next Song: " << Titel << ", from the Artist: " << Artist << std::endl;
    }

    void Start_Playlist_Shuffel(int count_Songs)
    {
        std::string Titel;
        std::string Artist;
        std::string Genre;
        double Time;
        std::string Trenner;

        for(int i = 0; i<count_Songs; i++)
        {
            int randm = (rand()%point_Count);
            std::stringstream stream_line(point_Playlist[randm]);

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

};
    
int main()
{

    Playlist Playlist;

    //Playlist benennen
    Playlist.Name_Playlist("Name");

    //Textdatei mit Liedern hinzufügen
    Playlist.Song_Hinzufügen("Playlist_Spotify.txt");

    //Textdatei mit einzelnem Lied hinzufügen
    //Playlist.Song_Hinzufügen("Songfile.txt");

    //Songtitel aus der Playlist entfernen
    ///Playlist.Remove_Song("Songtitel");

    //Playlist sortieren nach: Titel, Artist, Genre oder Time
    //Playlist.Playlist_sortieren("Titel/Artist/Genre/Time");

    //Playlist nach Suchwort durchsuchen
    //Playlist.Suche("Suchwort");

    //Ausgewähltes Lied aus der Playlist abspielen
    //Playlist.Play_Song("Songname");

    //Playlist starten
    //Playlist.Start_Playlist();

    //Playlist geshuffelt starten Start_Playlist_Shuffel(Anzahl der Lieder wo abgespielt werden sollen)
    //Playlist.Start_Playlist_Shuffel(Anzahl in int);

    return 0;
}   