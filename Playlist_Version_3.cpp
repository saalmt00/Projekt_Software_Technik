#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>


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

    return 0;
} 