#include "Referee.h"



Referee::Referee() : Difficulty(0), SetCount(0), Answer_array(nullptr), Return_value(nullptr)
{
}

Referee::~Referee()
{
	if (Answer_array != nullptr) {
		delete Answer_array;
	}
}

bool Isoverlapped(string temp) {
	int len = temp.size(), i, j;

	for (i = 0; i < len; i++) {
		for (j = i + 1; j < len; j++) {
			if (temp[i] == temp[j]) return true;
		}
	}
	return false;
}

bool Referee::PLAY_Solo()
{
    file.print("\n========SOLOPLAY========\n");
	SetCount = 0;
	Array Guess_array(Difficulty);  // User's array.
	bool result_flag = false;       // win <- true, lose <- false

	while (SetCount != 9) {
		// 1 loop = 1 set of the game

		string guess;
		while (true) {
			cout << " >> Input your guess(" << Difficulty << " numbers). 'help' to view help." << endl;
			guess.clear(); // for "fflush"
			cout << " >> "; cin >> guess;
			if (guess == "help") {
				ViewHelp();
			}
			else if (guess == "stop") {
				cout << endl;
                file.print("========SOLOSTOP========\n\n");
				return false;
			}
			else if (guess == "exit") {
                file.print("========INPUT 'EXIT'=========\n\n");
                exit(1);
			}
			else if (guess.size() != Difficulty) {
				cout << " >> Please enter the correct number of your guess." << endl;
			}
			else {
				if (Guess_array.SetArray(guess)) { // return false << the element was overlapping
					break;
					// if the "guess" was correct, then break and go to next step; check Answer_array
				}
			}
		}

		Return_value = Answer_array->Check(Guess_array);
        file.print_user(guess, Return_value->Strike(), Return_value->Ball());
		if (Return_value->isOut()) {
			cout << " >> OUT. " << endl;
		}
		else {
			if (Return_value->Strike() == Difficulty) { // user win
				result_flag = true;
				break;
			}
			cout << " >> " << Return_value->Strike() << " STRIKE." << endl;
			cout << " >> " << Return_value->Ball() << " BALL." << endl;
			Guess_array.clear();
		}
		SetCount++;
		cout << endl;
		// one set is over
	}
    file.print("========SOLOEND=========\n\n");
	return result_flag;
}

bool Referee::PLAY_PVP()
{
    file.print("\n========PVP PLAY========\n");
	SetCount = 0;
	Array Guess_array(Difficulty);  // User's array.
	Array Guess_array2(Difficulty); //User2's array.
	bool result_flag = false;       // win <- true, lose <- false


	while (SetCount != 9) {
		// 1 loop = 1 set of the game

		string guess;
		while (true) {
			cout << "Player1's turn" << endl;
			cout << " >> Input your guess(" << Difficulty << " numbers). 'help' to view help." << endl;
			guess.clear(); // for "fflush"
			cout << " >> "; cin >> guess;
			if (guess == "help") {
				ViewHelp();
			}
			else if (guess == "stop") {
				cout << endl;
                file.print("========PVP STOP========\n\n");
				return false;
			}
			else if (guess == "exit") {
                file.print("========INPUT 'EXIT'=========\n\n");
				exit(1);
			}
			else if (guess.size() != Difficulty) {
				cout << " >> Please enter the correct number of your guess." << endl;
			}
			else {
				if (Guess_array.SetArray(guess)) { // return false << the element was overlapping
					break;
					// if the "guess" was correct, then break and go to next step; check Answer_array
				}
			}
		}

		Return_value = Answer_array->Check(Guess_array);
        file.print(" >> Player1's turn ");
        file.print_user(guess, Return_value->Strike(), Return_value->Ball()); // fprint user1
		if (Return_value->isOut()) {
			cout << " >> OUT. " << endl;
		}
		else {
			if (Return_value->Strike() == Difficulty) { // user win
				result_flag = true;
				cout << " >> Player 1 won!" << endl;
				break;
			}
			cout << " >> " << Return_value->Strike() << " STRIKE." << endl;
			cout << " >> " << Return_value->Ball() << " BALL." << endl;
			Guess_array.clear();
		}
		SetCount++;
		cout << endl;


		string guess2;
		while (true) {
			cout << "Player2's turn" << endl;
			cout << " >> Input your guess(" << Difficulty << " numbers). 'help' to view help." << endl;
			guess2.clear(); // for "fflush"
			cout << " >> "; cin >> guess2;
			if (guess2 == "help") {
				ViewHelp();
			}
			else if (guess2 == "stop") {
				cout << endl;
                file.print("========PVP STOP========\n\n");
				return false;
			}
			else if (guess2 == "exit") {
				file.print("========INPUT 'EXIT'=========\n\n");
                exit(1);
			}
			else if (guess2.size() != Difficulty) {
				cout << " >> Please enter the correct number of your guess." << endl;
			}
			else {
				if (Guess_array2.SetArray(guess2)) { // return false << the element was overlapping
					break;
					// if the "guess" was correct, then break and go to next step; check Answer_array
				}
			}
		}

		Return_value = Answer_array->Check(Guess_array2);
        file.print(" >> Player2's turn ");
        file.print_user(guess, Return_value->Strike(), Return_value->Ball()); // fprint user2
		if (Return_value->isOut()) {
			cout << " >> OUT. " << endl;
		}
		else {
			if (Return_value->Strike() == Difficulty) { // user win
				result_flag = true;
				cout << " >> Player 2 won!" << endl;
				break;
			}
			cout << " >> " << Return_value->Strike() << " STRIKE." << endl;
			cout << " >> " << Return_value->Ball() << " BALL." << endl;
			Guess_array2.clear();
		}
		SetCount++;
		cout << endl; // one set is over
	}

    file.print("========PVP END=========\n\n");
	return result_flag;
}

bool Referee::PLAY_Computer()
{
    file.print("\n========A I PLAY========\n");
	SetCount = 0;
	Array Guess_array(Difficulty);  // User's array.
	Array Guess_array2(Difficulty); //computer's array.
	bool result_flag = false;       // win <- true, lose <- false
	bool ch[100000];

	for (int i = 0; i < 100000; i++) ch[i] = false;

	while (SetCount != 9) {
		// 1 loop = 1 set of the game

		string guess;
		while (true) {
			cout << "Player's turn" << endl;
			cout << " >> Input your guess(" << Difficulty << " numbers). 'help' to view help." << endl;
			guess.clear(); // for "fflush"
			cout << " >> "; cin >> guess;
			if (guess == "help") {
				ViewHelp();
			}
			else if (guess == "stop") {
				cout << endl;
                file.print("========A I STOP========\n\n");
				return false;
			}
			else if (guess == "exit") {
                file.print("========INPUT 'EXIT'=========\n\n");
				exit(1);
			}
			else if (guess.size() != Difficulty) {
				cout << " >> Please enter the correct number of your guess." << endl;
			}
			else {
				if (Guess_array.SetArray(guess)) { // return false << the element was overlapping
					break;
					// if the "guess" was correct, then break and go to next step; check Answer_array
				}
			}
		}

		Return_value = Answer_array->Check(Guess_array);
        file.print_user(guess, Return_value->Strike(), Return_value->Ball()); // fprint user
		if (Return_value->isOut()) {
			cout << " >> OUT. " << endl;
		}
		else {
			if (Return_value->Strike() == Difficulty) { // user win
				result_flag = true;
				cout << " >> Player 1 won!" << endl;
				break;
			}
			cout << " >> " << Return_value->Strike() << " STRIKE." << endl;
			cout << " >> " << Return_value->Ball() << " BALL." << endl;
			Guess_array.clear();
		}
		SetCount++;
		cout << endl;



		int num = pow(10, Difficulty);
		int i;
		string temp;

		for (i = num/10; i < num; i++) {
			temp = to_string(i);
			if (ch[i]) continue;  // it Can't be a answer
			if (Isoverlapped(temp)) continue;
			break;
		}

		string guess2 = temp;
		while (true) {
			cout << "Computer's turn" << endl;
			cout << " >> Computer's guess is.. : " << guess2 <<"!! "<< endl;

			if (Guess_array2.SetArray(guess2)) { // return false << the element was overlapping
				break;
				// if the "guess" was correct, then break and go to next step; check Answer_array
			}

		}

		Return_value = Answer_array->Check(Guess_array2);

		Answer* Answer_array2;
		Answer_array2 = new Answer(guess2);
		int cnt = 0;

		for (i = num/10; i < num; i++) {
			temp = to_string(i);
			if (ch[i]) continue;  // it Can't be a answer
			if (Isoverlapped(temp)) continue;

			Guess_array2.SetArray(temp);
			PresentInfo* Return_value2 = Answer_array2->Check(Guess_array2);
			if ((Return_value->isOut() != Return_value2->isOut()) || (Return_value->Ball() != Return_value2->Ball())
				|| (Return_value->Strike() != Return_value2->Strike())) {
				ch[i] = true, cnt++;

			}
		}
        file.print_ai(guess2, Return_value->Strike(), Return_value->Ball()); // fprint computer
		if (Return_value->isOut()) {
			cout << " >> OUT. " << endl;
		}
		else {
			if (Return_value->Strike() == Difficulty) { // computer win
				result_flag = false;
				cout << " >> Computer won!" << endl;
                delete Answer_array2;
				break;
			}
			cout << " >> " << Return_value->Strike() << " STRIKE." << endl;
			cout << " >> " << Return_value->Ball() << " BALL." << endl;
			Guess_array2.clear();
		}
		SetCount++;
		cout << endl; // one set is over
        if(Answer_array2 != nullptr)
            delete Answer_array2;
	}
    

    file.print("========A I END=========\n\n");
	return result_flag;
}

void Referee::MakeAnswerArray(int _difficulty)
{
	if (Answer_array != nullptr) { // delete previous Answer_array
		delete Answer_array;
	}
	Difficulty = _difficulty;
	Answer_array = new Answer(Difficulty);
}

void Referee::ViewHelp() const
{
	cout << endl;
	cout << " >> 'stop' - Stop this game and go to main menu." << endl;
	cout << " >> 'exit' - Program exit." << endl;
	cout << endl;
}