#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <sstream>

void Name_Playlist(char* Name, int N)
{

    printf("Name der Playlist:");
    fgets(Name, N, stdin);
    printf("\n\n\n\n\n");
    
}

void Einlesefunktion(std::string point_Playlist[], int &point_Count, std::string Lieder)
{

    std::ifstream input(Lieder);
    int i = point_Count;

    while(std::getline(input, point_Playlist[i])){
        //std::cout << point_Playlist[i] << std:: endl;
        i++;
        point_Count = i;
        //printf("%d \n",point_Count);
    }

    //printf("%d \n",point_Count);
    input.close();

}

void Playlist_auflisten(std::string point_Playlist[], int &point_Count, char Name[])
{

    printf("             %s \n", Name);
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

void Play_Song(std::string point_Playlist[],int &point_Count, std::string Songname)
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
                    //std::cout << Titel << std::endl;
                }

                if(o==3)
                {
                    Artist = Trenner;
                    //std::cout << Artist << std::endl;
                }
                    
                if(o==5)
                {
                    Genre = Trenner;
                    //std::cout << Genre << std::endl;
                }

                
            }
            
            stream_line >> Time;

            int time_min = static_cast<int>(Time);
            //printf("%d", time_min);
            
            //double time_sec = (Time-time_min)*100+time_min*60;
            //printf("%f", time_sec);
            double time_just_sec = Time-time_min;
            time_just_sec = time_just_sec*100;
           
           // for(int q=0; q<time_sec; q++)
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
                std::cout << "Now is playing: " << Titel << " from the Artist: " << Artist;
                
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


#define N 69


int main()
{

    //Grundvariablen
    std::string Playlist[N];
    char Name[N];
    int Count = 0;

    Name_Playlist(Name, N);

    Einlesefunktion(Playlist, Count, "Playlist_Spotify.txt");

    Playlist_auflisten(Playlist, Count, Name);
    
    Play_Song(Playlist, Count,"Fighter");



    return 0;
} 