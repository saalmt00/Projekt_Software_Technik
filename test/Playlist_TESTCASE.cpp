#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Playlist_test.hpp"

TEST_CASE("Bennen der Playlist"){

    Playlist Test;
    REQUIRE(Test.Name_Playlist("My_Playlist")=="My_Playlist");
}

TEST_CASE("Einlesen der Lieder: Test Anzahl der Zeilen"){

    Playlist Test;
    REQUIRE(Test.Song_Hinzufügen("Test.txt")==3);
    REQUIRE(Test.Song_Hinzufügen("Error")==999999);

}

TEST_CASE("Ausgabe der Lieder"){

    Playlist Test;

    Test.Song_Hinzufügen("Test.txt");

    REQUIRE(Test.Playlist_auflisten(0)=="\"Run This Town\"         \"JAY-Z,Rihanna,Kanye West\"                                  \"hip hop\"           4.28");
    REQUIRE(Test.Playlist_auflisten(1)=="\"Kampfgeist 4\"          \"Kontra K\"                                                  \"german hip hop\"    2.57");
    REQUIRE(Test.Playlist_auflisten(2)=="\"You Don't Know\"        \"Eminem,50 Cent,Ca$his,Lloyd Banks\"                         \"hip hop\"           4.18");

}

TEST_CASE("Abspielen eines Songs: Test herausfiltern von Songline, Titel, Artist, Gerne und Time"){

    Playlist Test;
    
    Test.Song_Hinzufügen("Test.txt");
    
    REQUIRE(Test.Play_Song_Songline("Run This Town")==0);
    REQUIRE(Test.Play_Song_Titel("Run This Town")=="Run This Town");
    REQUIRE(Test.Play_Song_Artist("Run This Town")=="JAY-Z,Rihanna,Kanye West");
    REQUIRE(Test.Play_Song_Genre("Run This Town")=="hip hop");
    REQUIRE(Test.Play_Song_Time("Run This Town")==4.28);

}


TEST_CASE("Song Löschen: Test Anzahl der Zeilen"){

    Playlist Test;

    Test.Song_Hinzufügen("Test.txt");

    REQUIRE(Test.Remove_Song("Run This Town")==2);
    REQUIRE(Test.Remove_Song("Error")== 999999);

}

TEST_CASE("Einzelnen Song Hinzufügen: Test Anzahl der Zeilen"){

    Playlist Test;

    Test.Song_Hinzufügen("Test.txt");

    REQUIRE(Test.Song_Hinzufügen("HOV.txt")==4);
}


TEST_CASE("Sortieren der Playlist"){

    Playlist Test;

    Test.Song_Hinzufügen("Test.txt");

    REQUIRE(Test.Playlist_sortieren(0, "Titel")=="\"Kampfgeist 4\"          \"Kontra K\"                                                  \"german hip hop\"    2.57");
    REQUIRE(Test.Playlist_sortieren(1, "Titel")=="\"Run This Town\"         \"JAY-Z,Rihanna,Kanye West\"                                  \"hip hop\"           4.28");
    REQUIRE(Test.Playlist_sortieren(2, "Titel")=="\"You Don't Know\"        \"Eminem,50 Cent,Ca$his,Lloyd Banks\"                         \"hip hop\"           4.18");

    REQUIRE(Test.Playlist_sortieren(0, "Artist")=="\"You Don't Know\"        \"Eminem,50 Cent,Ca$his,Lloyd Banks\"                         \"hip hop\"           4.18");
    REQUIRE(Test.Playlist_sortieren(1, "Artist")=="\"Run This Town\"         \"JAY-Z,Rihanna,Kanye West\"                                  \"hip hop\"           4.28");
    REQUIRE(Test.Playlist_sortieren(2, "Artist")=="\"Kampfgeist 4\"          \"Kontra K\"                                                  \"german hip hop\"    2.57");

    REQUIRE(Test.Playlist_sortieren(0, "Genre")=="\"Kampfgeist 4\"          \"Kontra K\"                                                  \"german hip hop\"    2.57");
    REQUIRE(Test.Playlist_sortieren(1, "Genre")=="\"Run This Town\"         \"JAY-Z,Rihanna,Kanye West\"                                  \"hip hop\"           4.28");
    REQUIRE(Test.Playlist_sortieren(2, "Genre")=="\"You Don't Know\"        \"Eminem,50 Cent,Ca$his,Lloyd Banks\"                         \"hip hop\"           4.18");

    REQUIRE(Test.Playlist_sortieren(0, "Time")=="\"Kampfgeist 4\"          \"Kontra K\"                                                  \"german hip hop\"    2.57");
    REQUIRE(Test.Playlist_sortieren(1, "Time")=="\"You Don't Know\"        \"Eminem,50 Cent,Ca$his,Lloyd Banks\"                         \"hip hop\"           4.18");
    REQUIRE(Test.Playlist_sortieren(2, "Time")=="\"Run This Town\"         \"JAY-Z,Rihanna,Kanye West\"                                  \"hip hop\"           4.28");
}

TEST_CASE("Suchwort in der Playlist Suchen: Test Anzahl der Zeilen"){

    Playlist Test;

    Test.Song_Hinzufügen("Test.txt");

    REQUIRE(Test.Suche("Eminem")==1);
    REQUIRE(Test.Suche("Error")== 999999);

}

TEST_CASE("Anzeige des nächsten Lieds"){

    Playlist Test;

    Test.Song_Hinzufügen("Test.txt");

    REQUIRE(Test.Next_Song(0)=="Kampfgeist 4");
}