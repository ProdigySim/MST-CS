TARGET := stackqueuetest

all: $(TARGET)

$(TARGET): main.o test_stack.o test_queue.o
	g++ main.o test_stack.o test_queue.o -lcppunit -ldl -o $(TARGET)

main.o: main.cpp test_stack.h test_queue.h
	g++ -c main.cpp -o main.o  

test_stack.o: stack.h test_stack.cpp test_stack.h exception.h
	g++ -c test_stack.cpp -o test_stack.o  

test_queue.o: queue.h test_queue.cpp test_queue.h exception.h
	g++ -c test_queue.cpp -o test_queue.o  
	
clean:
	@rm -rf *.o $(TARGET)