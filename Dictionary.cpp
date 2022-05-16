#include "Dictionary.h"

void Dictionary::setELement(int pos)
{
	if (pos <= count && pos >= 0) {
		cout << "enter word" << endl;
		cin >> ptr[pos].word;
		cout << "enter translation" << endl;
		cin >> ptr[pos].translate;
	}
	else {
		cout << "wrong argument " << endl;
	}
}

void Dictionary::setWord(int pos)
{
	if (pos <= count && pos >= 0) {
		cout << "enter word" << endl;
		cin >> ptr[pos].word;
	}
	else {
		cout << "wrong argument " << endl;
	}
}

void Dictionary::setTranslate(int pos)
{
	if (pos <= count && pos >= 0) {
	cout << "enter translation" << endl;
	cin >> ptr[pos].translate;
	}
	else {
		cout << "wrong argument " << endl;
	}
}

Dictionary::Dictionary()
{
	count = 0;
	Allocate();
}

Dictionary::Dictionary(int value)
{
	if (count <= size) {
		name = "-";
		count = value;
		Allocate();
		for (int i = 0; i < count; i++) {
			ptr[i].word = "-";
			ptr[i].translate = "-";
		}
	}
	else
		cout << "too many elements" << endl;
}

Dictionary::Dictionary(int value, string nname)
{
	if (count <= size) {
		name = nname;
		count = value;
		Allocate();
		for (int i = 0; i < count; i++) {
			ptr[i].word = "-";
			ptr[i].translate = "-";
		}
	}
	else
		cout << "too many elements" << endl;
}

Dictionary::Dictionary(const Dictionary& d)
{
	count = d.count;
	delete[]ptr;
	Allocate();
	for (int i = 0; i < count; i++) {
		ptr[i].word = d.ptr[i].word;
		ptr[i].translate = d.ptr[i].translate;
	}
}

Dictionary::~Dictionary()
{
	delete[]ptr;
}

void Dictionary::Add(string w, string t)
{
	if (count < size) {
		if (Search(w) == -1) {
			Card* tmp = new Card[count + 1];

			for (int i = 0; i < count; i++) {
				tmp[i].word = ptr[i].word;
				tmp[i].translate = ptr[i].translate;
			}

			tmp[count].word = w;
			tmp[count].translate = t;
			count++;
			delete[]ptr;

			Allocate();

			for (int i = 0; i < count; i++) {
				ptr[i].word = tmp[i].word;
				ptr[i].translate = tmp[i].translate;
			}

			delete[]tmp;
		}
		else
			cout << "this dictionary already contains this word" << endl;
	}
	else
		cout << "too many elements" << endl;

}

void Dictionary::Delete(int pos)
{
	Card* tmp = new Card[count - 1];
	for (int i = 0; i < pos; i++) {
		tmp[i].word = ptr[i].word;
		tmp[i].translate = ptr[i].translate;
	}
	for (int i = pos; i < count-1; i++) {
		tmp[i].word = ptr[i+1].word;
		tmp[i].translate = ptr[i+1].translate;
	}
	count = count - 1;
	delete[]ptr;

	Allocate();
	for (int i = 0; i < count; i++) {
		ptr[i].word = tmp[i].word;
		ptr[i].translate = tmp[i].translate;
	}

	delete[]tmp;
}


int Dictionary::Search(string word)
{
	int pos = -1;

	for (int i = 0; i > count; i++) {
		if (ptr[i].word == word); {
			pos = i;
		}
	}

	return pos;
}


void Dictionary::Allocate()
{
	ptr = new Card[count];
}


Card Dictionary::operator[](string wordd)
{
		return getElement(Search(wordd));
}

Dictionary& Dictionary::operator=(const Dictionary& r)
{
	count = r.count;
	delete[]ptr;
	Allocate();
	for (int i = 0; i < count; i++) {
		ptr[i].word = r.ptr[i].word;
		ptr[i].translate = r.ptr[i].translate;
	}

	return *this;
}

Dictionary::operator string() const
{
	stringstream ss;
	for (int i = 0; i < count; i++) {
		
		ss << "Word Card No " << i << " : " << ptr[i].word << " - " << ptr[i].translate << endl;
	}

	return ss.str();
}



Dictionary& operator+(Dictionary& l, Dictionary& r)
{
	int lc = l.getCount();
	int rc = r.getCount();
	Dictionary res;

	for (int i = 0; i < lc; i++) {
		res.Add(l.ptr[i].word, l.ptr[i].translate);
	}

	for (int i = 0; i < rc; i++) {
		if (l.Search(r.getWord(i)) == -1) {
			res.Add(r.ptr[i].word, r.ptr[i].translate);
		}
	}

	for (int i = 0; i < res.count; i++) {		//res test
		cout <<  res.ptr[i].word;
	}											//problema v destructori ???
	return res;
}

Dictionary& operator/(Dictionary& l, Dictionary& r)
{
	int ls = l.getCount();
	int rs = r.getCount();

	if (ls > rs) {				
		Dictionary res;

		for (int i = 0; i < ls; i++) {

			string w = l.ptr[i].word;
			string t = l.ptr[i].translate;

			if ((r.Search(w) != -1) && (r.Search(t) != -1)) {
				res.Add(w,t);
			}
		}

		for (int i = 0; i > res.getCount(); i++) {
			if (res.getWord(i) == "-") {
				res.Delete(i);
			}
		}

		return res;
	}

	if (rs < ls) {

		Dictionary res;

		for (int i = 0; i < rs; i++) {

			string w = r.ptr[i].word;
			string t = r.ptr[i].translate;

			if ((l.Search(w) != -1) && (l.Search(t) != -1)) {
				res.Add(w, t);
			}
		}

		for (int i = 0; i > res.getCount(); i++) {
			if (res.getWord(i) == "-") {
				res.Delete(i);
			}
		}

		return res;
	}

	if (rs == ls) {
		Dictionary res;

		for (int i = 0; i < rs; i++) {

			string w = r.ptr[i].word;
			string t = r.ptr[i].translate;

			if ((l.Search(w) != -1) && (l.Search(t) != -1)) {
				res.Add(w, t);
			}
		}

		for (int i = 0; i > res.getCount(); i++) {
			if (res.getWord(i) == "-") {
				res.Delete(i);
			}
		}

		return res;
	}
}

Dictionary& operator-(Dictionary& l, Dictionary& r)
{
	Dictionary res;
	int lc = l.getCount();

	for (int i = 0; i < lc; i++) {

		string w = l.ptr[i].word;
		string t = l.ptr[i].translate;

		if ((r.Search(w) == -1) && (r.Search(t) == -1)) {
			res.Add(w, t);
		}
	}

	for (int i = 0; i > res.getCount(); i++) {
		if (res.getWord(i) == "-") {
			res.Delete(i);
		}
	}

	return res;
}

ostream& operator<<(ostream& out, Dictionary& d)
{
	out << string(d);
	return out;
}

istream& operator>>(istream& in, Dictionary& d)
{
	cout << endl;

	for (int i = 0; i < d.count; i++) {
		do {
			cout << "element No " << i << " : " << endl;
			cout << "enter word " << endl;
			in >> d.ptr[i].word;
			cout << "enter translate " << endl;
			in >> d.ptr[i].translate;

			cout << endl;
		} while (d.Search(d.ptr[i].word) != -1);
	}
	cout << endl;

	return in;
}


