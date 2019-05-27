#include "FileManager.h"

FileManager::FileManager() : file("bullsandcows.txt", ios::app)
{
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    file << "Program starts : " ;
    file << buf << endl; // fprint like "2019-05-27.18:06:25" << time this constructor is called
}

FileManager::~FileManager()
{
    file.close();
}

void FileManager::print(string str)
{
    file << str;
}

void FileManager::print_user(string guess, int strk, int ball)
{
    file << " >> USER : " << guess << " --> "<< strk << " STRIKE, "<< ball << " BALL" << endl;
}



void FileManager::print_ai(string guess, int strk, int ball)
{
    file << " >> A I  : " << guess << " --> "<< strk << " STRIKE, "<< ball << " BALL" << endl;
}