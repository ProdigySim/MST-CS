TARGET := listtest

all: $(TARGET)

$(TARGET): main.o test_list.o
	g++ main.o test_list.o -lcppunit -ldl -o listtest 

main.o: main.cpp list.h list.hpp test_list.h 
	g++ -c main.cpp -o main.o  

test_list.o: list.h list.hpp test_list.cpp test_list.h exception.hpp exception.h
	g++ -c test_list.cpp -o test_list.o  

clean:
	@rm -rf *.o $(TARGET)