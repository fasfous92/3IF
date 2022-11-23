main : main.o Trajet.o TrajetSimple.o Cell.o Linkedlist.o TrajetCompose.o
	g++ -o main main.o  TrajetSimple.o Cell.o Linkedlist.o TrajetCompose.o Trajet.o

main.o : main.cpp
	g++ -c main.cpp

TrajetSimple.o : TrajetSimple.cpp
	g++ -c TrajetSimple.cpp
Cell.o: Cell.cpp
	g++ -c Cell.cpp

Linkedlist.o: Linkedlist.cpp
	g++ -c Linkedlist.cpp

TrajetCompose.o: TrajetCompose.cpp
	g++ -c TrajetCompose.cpp