#ifndef __REFEREE_H_
#define __REFEREE_H_

#include "default.h"
#include "Array.h"

class Referee
{
public:
    Referee();
    ~Referee();
    bool Start(int difficulty);
    // Play game until user win or set==9
    // win <- true, lose <- false
protected:
    void SetDifficulty(int difficulty);
    void ViewHelp() const;
private:
    int Difficulty;
    int SetCount; // max = 9;
    PresentInfo* Return_value;
    Answer* Answer_array;
};

#endif 