#include <iostream>
#include "dequeue.h"

using std::cout;
using std::endl;

int main()
{
	cout << "Let's make a dequeue..." << endl;
	Dequeue<int> d;
	
	d.push_back(4);
	
	cout << d[0] << endl;

	cout << "That was exciting" << endl;

	return 0;
}
