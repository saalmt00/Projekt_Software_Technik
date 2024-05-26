#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>

#define N 69

void Einlesefunktion(std::string *point_Playlist, int &Count){

    std::string Lieder = "Lieder.txt";
    
    std::ifstream input(Lieder);

    //std::string Playlist;

    int i = 0;

    
    while(std::getline(input, point_Playlist[i])){
        std::cout << point_Playlist[i] << std:: endl;
       
        i++;

        Count = i;

        printf("%d \n",Count);

    }

    printf("%d \n",Count);

    printf("hello");


    input.close();

}


int main(){

    std::string Playlist[N];

    int Count;

    Einlesefunktion(Playlist, Count);

    printf("%d \n",Count);

    for(int i=0; i<Count; i++){
    std::cout << Playlist[i] << std:: endl;
    }

    return 0;
} 