#pragma once

enum class MainMenuOption {
    CreatePlaylist = 1,
    OpenPlaylist,
    ViewAllPlaylists,
    DeletePlaylist,
    Exit
};

enum class PlaylistMenuOption {
    AddSong = 1,
    RemoveSong,
    Play,
    Pause,
    Stop,
    Next,
    Previous,
    MoveUp,
    MoveDown,
    ShowAllSongs,
    Back
};
