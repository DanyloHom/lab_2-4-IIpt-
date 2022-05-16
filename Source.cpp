#include <iostream>
#include "Dictionary.h"

using namespace std;

int main()
{
	int i, j;
	string I, J;
	cout << "how many words should be in firt dictionary? " << endl;
	cin >> i;
	cout << "enter name of dictionary" << endl;
	cin >> I;
	Dictionary a(i, I);
	cin >> a;

	cout << "how many words should be in second dictionary? " << endl;
	cin >> j;
	cout << "enter name of dictionary" << endl;
	cin >> J;
	Dictionary b(j, J);
	cin >> b;

	cout << "you have created 2 dictionaries : " << endl;
	cout << "a : " << endl;
	cout << a;
	cout << "b : " << endl;
	cout << b;
	cout << "c = " << a.getName() << " + " << b.getName() << endl;
	Dictionary c = a + b; //shchos`iz peredavanym posylannyam. chomus`znykayut slova i pereklad
	cout << c;

}