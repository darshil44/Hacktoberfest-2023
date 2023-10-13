#include <iostream>
#include <string>
#include <vector>

class Song {
public:
    Song(const std::string& title, const std::string& artist) : title(title), artist(artist) {}

    std::string getTitle() const {
        return title;
    }

    std::string getArtist() const {
        return artist;
    }

private:
    std::string title;
    std::string artist;
};

class MusicPlayer {
public:
    void addSong(const Song& song) {
        playlist.push_back(song);
    }

    void play() {
        if (playlist.empty()) {
            std::cout << "Playlist is empty." << std::endl;
        } else {
            std::cout << "Playing: " << playlist[currentIndex].getTitle() << " by " << playlist[currentIndex].getArtist() << std::endl;
        }
    }

    void next() {
        if (playlist.empty()) {
            std::cout << "Playlist is empty." << std::endl;
        } else {
            currentIndex = (currentIndex + 1) % playlist.size();
            play();
        }
    }

    void previous() {
        if (playlist.empty()) {
            std::cout << "Playlist is empty." << std::endl;
        } else {
            currentIndex = (currentIndex - 1 + playlist.size()) % playlist.size();
            play();
        }
    }

    void displayPlaylist() {
        std::cout << "Current Playlist:" << std::endl;
        for (const Song& song : playlist) {
            std::cout << song.getTitle() << " by " << song.getArtist() << std::endl;
        }
    }

private:
    std::vector<Song> playlist;
    int currentIndex = 0;
};

int main() {
    MusicPlayer player;

    Song song1("Song 1", "Artist 1");
    Song song2("Song 2", "Artist 2");
    Song song3("Song 3", "Artist 3");

    player.addSong(song1);
    player.addSong(song2);
    player.addSong(song3);

    player.displayPlaylist();
    player.play();
    player.next();
    player.previous();
    player.next();

    return 0;
}
