TARGET := slisttest

all: $(TARGET)

$(TARGET): main.o test_slist.o
	g++ main.o test_slist.o -lcppunit -ldl -o slisttest 

main.o: main.cpp slist.h slist.hpp test_slist.h 
	g++ -c main.cpp -o main.o  

test_slist.o: slist.h slist.hpp test_slist.cpp test_slist.h exception.hpp exception.h
	g++ -c test_slist.cpp -o test_slist.o  

clean:
	@rm -rf *.o $(TARGET)