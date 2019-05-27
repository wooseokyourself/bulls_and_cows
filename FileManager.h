#ifndef __FILEMANAGER_H_
#define __FILEMANAGER_H_

#include "default.h"

class FileManager
{
public:
    FileManager();
    ~FileManager();
    void print(string str); // file << str;
    void print_user(string guess, int strk, int ball); // " >> USER : 12345 --> i STRIKE, j BALL \n"
    void print_ai(string guess, int strk, int ball); // " >> AI : 12345 --> i STRIKE, j BALL\n"
private:
    ofstream file;
};

#endif