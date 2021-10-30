all: bagtest

bagtest: main.o test_bag.o
	g++ main.o test_bag.o -lcppunit -ldl -o bagtest 

main.o: main.cpp bag.h bag.hpp test_bag.h 
	g++ -c main.cpp -o main.o  

test_bag.o: bag.h bag.hpp test_bag.cpp test_bag.h exception.hpp exception.h
	g++ -c test_bag.cpp -o test_bag.o  

clean:
	rm *.o bagtest