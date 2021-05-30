
#include <bits/stdc++.h>
using namespace std;

class LRUCache {

	list<int> dq;

	unordered_map<int, list<int>::iterator> ma;
	int csize; 

public:
	LRUCache(int);
	void refer(int);
	void display();
};

// Declare the size
LRUCache::LRUCache(int n)
{
	csize = n;
}

void LRUCache::refer(int x)
{
	// not present in cache
	if (ma.find(x) == ma.end()) {
		//  that means cache is full
		if (dq.size() == csize) {
			// delete least recently used element
			int last = dq.back();

		//pop the last element
			dq.pop_back();

			// Erase the last
			ma.erase(last);
		}
	}

	// present in cache
	else
		dq.erase(ma[x]);

	// update reference
	dq.push_front(x);
	ma[x] = dq.begin();
}

// A Function to display contents of cache
void LRUCache::display()
{

	// Iterate in the deque and print
	// all the elements in it
	for (auto it = dq.begin(); it != dq.end();
		it++)
		cout << (*it) << " ";

	cout << endl;
}

// code
int main()
{
	LRUCache ca(4);

	ca.refer(1);
	ca.refer(2);
	ca.refer(3);
	ca.refer(1);
	ca.refer(4);
	ca.refer(5);
	ca.display();

	return 0;
}
