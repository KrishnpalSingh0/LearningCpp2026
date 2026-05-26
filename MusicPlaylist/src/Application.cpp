#include "Application.h"
#include "Menu.h"
#include "PlaylistManager.h"
#include "StorageManager.h"
#include "InputValidation.h"
#include "Player.h"
#include "Enums.h"
#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

vector<string> listSongsFromFolder(const string &folderPath)
{
    vector<string> files;
    for (const auto &entry : fs::directory_iterator(folderPath))
    {
        if (entry.is_regular_file())
        {
            files.push_back(entry.path().string());
        }
    }
    return files;
}
void Application::run()
{
    Menu menu;
    PlaylistManager pm;
    StorageManager storage;
    InputValidation input;
    Player player;
    Playlist *currentPlaylist = nullptr;
    storage.loadFromFile(pm);
    int choice;
    while (true)
    {
        menu.showMainMenu();
        cout << "\nEnter choice: ";
        choice = input.getIntValue();
        MainMenuOption option = static_cast<MainMenuOption>(choice);
        switch (option)
        {
            case MainMenuOption::CreatePlaylist:
            {
                cout << "Enter playlist name: ";
                string name = input.getValidString();
                pm.createPlaylist(name);
                storage.saveToFile(pm);
                break;
            }

            case MainMenuOption::OpenPlaylist:
            {
                cout << "Enter playlist name: ";
                string pName = input.getValidString();
                currentPlaylist = pm.openPlaylist(pName);
                if (currentPlaylist)
                {
                    player.setPlaylist(currentPlaylist);
                    int pChoice;
                    while (true)
                    {
                        menu.showPlaylistMenu();
                        cout << "\nEnter choice: ";
                        pChoice = input.getIntValue();
                        PlaylistMenuOption pOption = static_cast<PlaylistMenuOption>(pChoice);
                        switch (pOption)
                        {
                            case PlaylistMenuOption::AddSong:
                            {
                                vector<string> songs = listSongsFromFolder("songs");
                                if (songs.empty())
                                {
                                    cout << "No songs found in folder.\n";
                                    break;
                                }
                                cout << "Available songs:\n";
                                for (int i = 0; i < songs.size(); i++)
                                {
                                    string filename = fs::path(songs[i]).filename().string();
                                    cout << (i + 1) << ". " << filename << endl;
                                }

                                cout << "Enter choice: ";
                                int songChoice = input.getIntValue();
                                if (songChoice < 1 || songChoice > songs.size())
                                {
                                    cout << "Invalid choice.\n";
                                    break;
                                }
                                string selectedSong = songs[songChoice - 1];
                                currentPlaylist->addSong(selectedSong);
                                string filename = fs::path(selectedSong).filename().string();
                                storage.saveToFile(pm);
                                break;
                            }

                            case PlaylistMenuOption::RemoveSong:
                                currentPlaylist->removeSong();
                                player.stop();
                                storage.saveToFile(pm);
                                break;

                            case PlaylistMenuOption::Play:
                                if (currentPlaylist->isEmpty())
                                {
                                    cout << "Playlist is empty. Please add your first song.\n";
                                }
                                else
                                {
                                    player.play();
                                }
                                break;

                            case PlaylistMenuOption::Pause:
                                if (currentPlaylist->isEmpty())
                                {
                                    cout << "Playlist is empty. Please add your first song.\n";
                                }
                                else
                                {
                                    player.pause();
                                }
                                break;

                            case PlaylistMenuOption::Stop:
                                if (currentPlaylist->isEmpty())
                                {
                                    cout << "Playlist is empty. Please add your first song.\n";
                                }
                                else
                                {
                                    player.stop();
                                }
                                break;

                            case PlaylistMenuOption::Next:
                                if (currentPlaylist->isEmpty())
                                {
                                    cout << "Playlist is empty. Please add your first song.\n";
                                }
                                else
                                {
                                    player.next();
                                }
                                break;

                            case PlaylistMenuOption::Previous:
                                if (currentPlaylist->isEmpty())
                                {
                                    cout << "Playlist is empty. Please add your first song.\n";
                                }
                                else
                                {
                                    player.previous();
                                }
                                break;

                            case PlaylistMenuOption::MoveUp:
                                if (currentPlaylist->isEmpty())
                                {
                                    cout << "Playlist is empty. Please add your first song.\n";
                                }
                                else
                                {
                                    cout << "Enter song index: ";
                                    if (currentPlaylist->moveUp(input.getIntValue() - 1))
                                    {
                                        cout << "Song moved up successfully.\n";
                                        storage.saveToFile(pm);
                                        cout << "Updated playlist order:\n";
                                        for (int i = 1; i <= currentPlaylist->getSongs().size(); i++)
                                        {
                                            cout << i << ". " << currentPlaylist->getSongs()[i - 1].getTitle()
                                                 << "\n";
                                        }
                                    }
                                    else
                                    {
                                        cout << "Invalid song index.\n";
                                    }
                                }
                                break;

                            case PlaylistMenuOption::MoveDown:
                                if (currentPlaylist->isEmpty())
                                {
                                    cout << "Playlist is empty. Please add your first song.\n";
                                }
                                else
                                {
                                    cout << "Songs in playlist:\n";
                                    for (int i = 1; i <= currentPlaylist->getSongs().size(); i++)
                                    {
                                        cout << i << ". " << currentPlaylist->getSongs()[i - 1].getTitle() << "\n";
                                    }
                                    cout << "Enter song index: ";
                                    if (currentPlaylist->moveDown(input.getIntValue() - 1))
                                    {
                                        cout << "Song Move Down Successfully.\n";
                                        storage.saveToFile(pm);
                                        cout << "Updated playlist order:\n";
                                        for (int i = 1; i <= currentPlaylist->getSongs().size(); i++)
                                        {
                                            cout << i << ". " << currentPlaylist->getSongs()[i - 1].getTitle() << "\n";
                                        }
                                    }
                                    else
                                    {
                                        cout << "Invalid song index.\n";
                                    }
                                }
                                break;
                            case PlaylistMenuOption::ShowAllSongs:
                                if (currentPlaylist->isEmpty())
                                {
                                    cout << "Playlist is empty. Please add your first song.\n";
                                }
                                else
                                {
                                    cout << "Songs in playlist:\n";
                                    for (int i = 1; i <= currentPlaylist->getSongs().size(); i++)
                                    {
                                        cout << i << ". " << currentPlaylist->getSongs()[i - 1].getTitle() << "\n";
                                    }
                                }
                                break;
                            case PlaylistMenuOption::Back:
                                goto backToMain;
                        }
                    }
                }
                else
                {
                    cout << "Playlist not found.\n";
                }
                break;
            }

            case MainMenuOption::ViewAllPlaylists:
                pm.viewAllPlaylist();
                break;

            case MainMenuOption::DeletePlaylist:
                cout << "Enter playlist name: ";
                pm.deletePlaylistByName(input.getValidString());
                storage.saveToFile(pm);
                break;

            case MainMenuOption::Exit:
                storage.saveToFile(pm);
                cout << "Exit.\n";
                return;
        }
    backToMain:;
    }
}
