//
// Created by misha on 11/01/16.
//

#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H


class Player {
public:
    Player();
    ~Player();

    void playValue(int value);
private:
    int fd;

    void setupAplay();
    void destroyAplay();
};


#endif //MUSIC_PLAYER_H
