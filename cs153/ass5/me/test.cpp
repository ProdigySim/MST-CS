#include <iostream>
#include "block.h"

using std::cout;
using std::endl;

int main()
{
	cout << "Let's make a block..." << endl;
	Block<int> b;
	
	b.push_front(4);
	b.push_front(2);
	b.push_front(1);
	b.display();
	b.pop_back();
	b.display();
	b.pop_front();
	b.display();
	b.push_back(3);
	b.display();
	b.push_front(9);
	b.display();
	b.clear();
	b.display();
	
	cout << "That was exciting" << endl;

	return 0;
}
