#include "LinkedQueue.h"
#include <iostream>
using std::cout;
using std::endl;

int main ()
{
	LinkedQueue<int> lq;
	for (int i = 0; i < 10; ++i)
		lq.push (i);
	cout << lq.size () << endl;
	int tmp;
	while (!lq.empty ()) {
		lq.front (tmp);
		cout << tmp << endl;
		lq.pop ();
	}
	cout << lq.size () << endl;
	return 0;
}