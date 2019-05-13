#ifndef __MANAGER_H_
#define __MANAGER_H_

#include "default.h"
#include "Referee.h"

class Manager
{
public:
    void Menu();

protected:
    void Play();
    void SetDifficulty();

private:
    int GameCount;
    int Difficulty;
    Referee Game;
};

#endif