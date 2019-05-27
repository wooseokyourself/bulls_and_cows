

#manager_debug : $(TARGETS)
#manager_debug : OPTION = -DDEBUG_MODE

game : main.cpp Array.o Manager.o Referee.o FileManager.o
	g++ -o game main.cpp Array.o Manager.o Referee.o FileManager.o

Array.o : Array.h Array.cpp default.h
	g++ -c Array.cpp

Referee.o : Referee.h Referee.cpp default.h Array.h
	g++ -c Referee.cpp

Manager.o : Manager.h Manager.cpp default.h Referee.h
	g++ -c Manager.cpp

FileManager.o : FileManager.h FileManager.cpp default.h
	g++ -c FileManager.cpp

clean :
	rm *.o game
