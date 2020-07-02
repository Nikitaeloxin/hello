#include "head.h"

//----------------------------------------------------------------CLASS Person----------------------------------------------------
//OUTPUT PERSON
ostream& operator<<(ostream& os, Person& p){
	return os << p.first_name << " " << p.second_name << " " << p.age ;
}

//INPUT PERSON
istream& operator>>(istream& is, Person& p){
	string f, s;
	int a;
	char ch1, ch2;

	is >> f;
	is.get(ch1);
	if (ch1 == '\n'){
		p = Person(f);
		return is;
	}

	is >> s;
	is.get(ch2);
	if (ch2 == '\n'){
		p = Person(f,s);
		return is;
	}

	is >> a;
	p = Person(f, s, a);
	return is;
}

//COMPARE PERSON IN SEARCH
bool operator<=(Person& p1, Person& p2){
	return ((p1.first_name == p2.first_name && p2.second_name == p2.second_name && p1.age == p2.age) ||
		(p1.first_name == p2.first_name && p1.second_name == "unknown" && p1.age == 0) ||
		(p1.first_name == p2.first_name && p2.second_name == p2.second_name && p1.age == 0));
}

//------------------------------------------------------------END CLASS PERSON-----------------------------------------------------


//INFORMATION BLOCK
//-----------------------------------------------------------------------------------------------------------------------------------
void info(){
	cout << "\nadd - add Person to Vec end; " << endl
		<< "del - delete element from end;" << endl
		<< "list - output all list;" << endl
		<< "end - close\n" << endl;
}
//-----------------------------------------------------------------------------------------------------------------------------------
