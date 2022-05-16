#pragma once
#include "Source1.cpp"
#include <iostream>
#include <sstream>

using namespace std;

class Dictionary
{
private:
	Card* ptr;
	int count;
	const int size = 100; 
	string name;
public:

	Card getElement(int pos)const { return ptr[pos]; }
	string getWord(int pos) const { return ptr[pos].word; }
	string getTranslate(int pos) const { return ptr[pos].translate; }
	string getName()const { return name; }
	int getSize()const { return size; }
	int getCount()const { return count; }

	void setELement(int pos);
	void setWord(int pos);
	void setTranslate(int pos);
	void setName(string nname) { name = nname; }
	void setCount(int value) { count = value; }

	Dictionary();
	Dictionary(int value);
	Dictionary(int value, string nname);
	Dictionary(const Dictionary& d);
	~Dictionary();

	void Add(string w, string t);
	void Delete(int pos);
	int Search(string word);

	void Allocate();

	friend Dictionary& operator+(Dictionary& l, Dictionary& r);
	friend Dictionary& operator/(Dictionary& l, Dictionary& r);
	friend Dictionary& operator-(Dictionary& l, Dictionary& r);

	Card operator[](string wordd);
	Dictionary& operator =(const Dictionary& r);
	operator string() const;
	friend ostream& operator << (ostream&, Dictionary& d);
	friend istream& operator >> (istream& in, Dictionary& d);

};



