#include "Menu.h"
#include <iostream>
using namespace std;

void Menu::showMainMenu()
{
    cout << "==================================\n";
    cout << "   Welcome to Music Player!\n";
    cout << "==================================\n";
    cout << "\n1.Create Playlist\n";
    cout << "2.Open Playlist\n";
    cout << "3.View Playlist\n";
    cout << "4.Delete Playlist\n";
    cout << "5.Exit\n";
}

void Menu::showPlaylistMenu()
{
    cout << "==================================\n";
    cout << "           PLAYLIST                \n";
    cout << "==================================\n";
    cout << "\n1.Add Song\n";
    cout << "2.Remove Song\n";
    cout << "3.Play\n";
    cout << "4.Pause\n";
    cout << "5.Stop\n";
    cout << "6.Next\n";
    cout << "7.Previous\n";
    cout << "8.Move Up\n";
    cout << "9.Move Down\n";
    cout << "10.ShowAllSongs\n";
    cout << "11.Back\n";
}
