#include "Array.h"

PresentInfo::PresentInfo(int strike, int ball)
{
    Number[1] = strike;
    Number[2] = ball;
    if(strike == ball == 0){
        Number[0] = 1;
    }
    else{
        Number[0] = 0;
    }
}

bool PresentInfo::isBall() const
{
    if(Number[0] == 1){
        return true;
    }
    else{
        return false;
    }
}

int PresentInfo::Strike() const
{
    return Number[1];
}

int PresentInfo::Ball() const
{
    return Number[2];
}

Array::Array(int difficulty) : ElemNum(difficulty)
{
    if(ElemNum == 3){
            cout<<"Difficulty : EASY"<<endl;
        }
        else if(ElemNum == 4){
            cout<<"Difficulty : NORMAL"<<endl;
        }
        else if(ElemNum == 5){
            cout<<"Difficulty : HARD"<<endl;
        }
        else{
            cout<<"SYSTEM : Invalid Difficulty. Program exit."<<endl;
            exit(1);
        }
}

Array::~Array()
{

}

int& Array::operator[](const int idx)
{
    if(idx < 0 || idx >= ElemNum){
        cout<<"SYSTEM : Array Boundary error! Return vector[0]"<<endl;
        return arr[idx];
    }
    return arr[idx];
}

PresentInfo Array::Check(const vector<int>& Present) const
{
    int strike_num = 0;
    int ball_num = 0;
    
    for(int i=0; i<ElemNum; i++){
        for(int j=i; j<ElemNum; j++){
            if(i==j && arr[i] == Present[i]){
                strike_num++;
            }
            else if(i!=j && arr[i] == Present[j]){
                ball_num++;
            }
        }
    }
    return PresentInfo info(strike_num, ball_num);
}

bool Array::push_back(int elem)
{
    if(arr.size() == ElemNum){
        cout<<"SYSTEM : Vector is full!"<<endl;
        return false;
    }
    else{
        for(int i=0; i<ElemNum; i++){
            if(arr[i] == elem){
                cout<<"SYSTEM : Same number already exist in your array."<<endl;
            }
            return false;
        }
        arr.push_back(elem);
        return true;
    }
}

Answer::Answer(int difficulty) : Array(difficulty)
{
    SetRandomNumber();
}

void Answer::SetRandomNumber()
{
    srand((unsigned)time(0));
    int randomNum;
    const int lowest = 0;
    const int highest = 9;
    const int range = (highest - lowest) + 1;
    randomNum = int(range*rand() / (RAND_MAX + 1.0);
    while(arr.size() != ElemNum){
        this->push_back(randomNum);
    }
}

bool Answer::push_back(int randomNum)
{
    if(arr[arr.size() == randomNum]){
        return false;
    }
    else{
        arr.push_back(randomNum);
        return true;
    }
}