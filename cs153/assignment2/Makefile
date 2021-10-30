all: vectortest

vectortest: main.o test_vector.o
	g++ main.o test_vector.o -lcppunit -ldl -o vectortest 

main.o: main.cpp vector.h vector.hpp test_vector.h 
	g++ -c main.cpp -o main.o  

test_vector.o: vector.h vector.hpp test_vector.cpp test_vector.h exception.hpp exception.h
	g++ -c test_vector.cpp -o test_vector.o  

clean:
	rm *.o vectortest