#include <bits/stdc++.h>
using namespace std;

class Song
{

    string title;
    double duration;

public:
    Song(string title, double duration)
    {
        this->title = title;
        this->duration = duration;
    }

    string getTitle()
    {
        return title;
    }
};

class SongList
{

public:
    vector<Song> songs;

    SongList()
    {
        this->songs = songs;
    }

    bool add(Song song)
    {
        if (findSong(song.getTitle()).getTitle() != "")
        {
            return false;
        }
        this->songs.push_back(song);
        return true;
    }

    Song findSong(string title)
    {
        for (auto song : this->songs)
        {
            if (song.getTitle() == title)
            {
                return song;
            }
        }
        return Song("", 0);
    }
    Song findSong(int trackNumber)
    {
        int index = trackNumber - 1;
        if ((index >= 0) && (index < this->songs.size()))
        {
            return this->songs[index];
        }
        return Song("", 0);
    }
};

class Album
{
public:
    string name;
    string artist;
    SongList songList;

    Album(string name, string artist) : songList()
    {
        this->name = name;
        this->artist = artist;
        this->songList = songList;
    }

    bool addSong(string title, double duration)
    {
        Song song(title, duration);
        return songList.add(song);
    }

    bool addToPlayList(int trackNumber, list<Song>& playList)
    {
        Song checkedSong = this->songList.findSong(trackNumber);
        if (checkedSong.getTitle() != "")
        {
            playList.push_back(checkedSong);
            return true;
        }
        cout << "This album does not have a track " << trackNumber << endl;
        return false;
    }

    bool addToPlayList(string title, list<Song>& playList)
    {
        Song checkedSong = this->songList.findSong(title);
        if (checkedSong.getTitle() != "")
        {
            playList.push_back(checkedSong);
            return true;
        }
        cout << "The song " << title << " is not in this album" << endl;
        return false;
    }
};

void printList(list<Song> playList)
{
    for (auto song : playList)
    {
        cout << song.getTitle() << endl;
    }
}
void printMenu()
{
    cout << "Available actions: " << endl;
    cout << "0 - to quit" << endl;
    cout << "1 - to play next song" << endl;
    cout << "2 - to play previous song" << endl;
    cout << "3 - to replay the current song" << endl;
    cout << "4 - list songs in the playlist" << endl;
    cout << "5 - print available actions" << endl;
    cout << "Choose your action: " << endl;
}
void play(list<Song> &playList)
{
    bool quit = false;
    bool forward = true;

    list<Song>::iterator it = playList.begin();
    if (playList.size() == 0)
    {
        cout << "No songs in playlist" << endl;
        return;
    }
    else
    {
        cout << "Now playing " << it->getTitle() << endl;
    }

    while (!quit)
    {
        int action;
        cin >> action;
        switch (action)
        {
        case 0:
            cout << "Playlist complete." << endl;
            quit = true;
            break;

        case 1:
            if (!forward)
            {
                if (it != playList.end())
                {
                    it++;
                }
                forward = true;
            }
            if (it != playList.end())
            {
                cout << "Now playing " << it->getTitle() << endl;
                it++;
            }
            else
            {
                cout << "We have reached the end of the playlist" << endl;
                forward = false;
            }
            break;
        case 2:
            if (forward)
            {
                if (it != playList.begin())
                {
                    it--;
                }
                forward = false;
            }
            if (it != playList.begin())
            {
                it--;
                cout << "Now playing " << it->getTitle() << endl;
            }
            else
            {
                cout << "We are at the start of the playlist" << endl;
                forward = true;
            }
            break;
        case 3:
            if (forward)
            {
                if (it != playList.begin())
                {
                    it--;
                    cout << "Now replaying " << it->getTitle() << endl;
                    forward = false;
                }
                else
                {
                    cout << "We are at the start of the list" << endl;
                }
            }
            else
            {
                if (it != playList.end())
                {
                    it++;
                    cout << "Now replaying " << it->getTitle() << endl;
                    forward = true;
                }
                else
                {
                    cout << "We have reached the end of the list" << endl;
                }
            }
            break;
        case 4:
            printList(playList);
            break;
        case 5:
            printMenu();
            break;
        }
    }
}
int main()
{
    vector<Album> albums;
    Album album = Album("Stormbringer", "Deep Purple");
    album.addSong("Stormbringer", 4.6);
    album.addSong("Love don't mean a thing", 4.22);
    album.addSong("Holy man", 4.3);
    album.addSong("Hold on", 5.6);
    album.addSong("Lady double dealer", 3.21);
    album.addSong("You can't do it right", 6.23);
    album.addSong("High ball shooter", 4.27);
    album.addSong("The gypsy", 4.2);
    album.addSong("Soldier of fortune", 3.13);
    albums.push_back(album);

    album = Album("For those about to rock", "AC/DC");
    album.addSong("For those about to rock", 5.44);
    album.addSong("I put the finger on you", 3.25);
    album.addSong("Lets go", 3.45);
    album.addSong("Inject the venom", 3.33);
    album.addSong("Snowballed", 4.51);
    album.addSong("Evil walks", 3.45);
    album.addSong("C.O.D.", 5.25);
    album.addSong("Breaking the rules", 5.32);
    album.addSong("Night of the long knives", 5.12);
    albums.push_back(album);

    list<Song> playList;
    albums[0].addToPlayList("You can't do it right", playList);
    albums[0].addToPlayList("Holy man", playList);
    albums[0].addToPlayList("Speed king", playList); // Does not exist
    albums[0].addToPlayList(9, playList);
    albums[1].addToPlayList(8, playList);
    albums[1].addToPlayList(3, playList);
    albums[1].addToPlayList(2, playList);
    albums[1].addToPlayList(24, playList); // There is no track 24
    play(playList);

    return 0;
}