#ifndef __REFEREE_H_
#define __REFEREE_H_

#include "default.h"
#include "Array.h"

class Referee
{
public:
    Referee();
    ~Referee();
    bool PLAY_Solo(int difficulty);
    // Play game until user win or set==9
    // win <- true, lose <- false
    bool PLAY_PVP(int difficulty);
    bool PLAY_Computer(int difficulty);
protected:
    void SetDifficulty(int difficulty);
    void ViewHelp() const;
private:
    int Difficulty;
    int SetCount; // max = 9;
    PresentInfo* Return_value; // will get copied address; no need to delete it
    Answer* Answer_array; // will be dynamic allocated
};

#endif 