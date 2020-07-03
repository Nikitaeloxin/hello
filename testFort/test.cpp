#include "head.h"

//----------------------------------------------------------------CLASS Person----------------------------------------------------
//OUTPUT PERSON (OVERLOAD <<)
ostream& operator<<(ostream& os, Person& p){
	return os << p.first_name << " " << p.second_name << " " << p.age ;
}

//INPUT PERSON (OVERLOAD >>)
istream& operator>>(istream& is, Person& p){
	string f, s;
	int a;
	is >> f >> s >> a;
	p = Person(f, s, a);
	return is;
}

//COMPARE PERSON (OVERLOAD ==)
bool operator==(Person& p1, Person& p2){
	return (p1.first_name == p2.first_name && p2.second_name == p2.second_name && p1.age == p2.age);
}

//------------------------------------------------------------END CLASS PERSON-----------------------------------------------------

//----------------------------------------------------------OTHER FUNCTIONS---------------------------------------------------------

//INFORMATION BLOCK
//-----------------------------------------------------------------------------------------------------------------------------------
void info(){
	cout << "\nadd - add Person to Vec end; " << endl
		<< "del - delete element from end;" << endl
		<< "list - output all list;" << endl
		<< "search - search for specified element" << endl
		<< "end - close\n" << endl;
}
//-----------------------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------END OTHER FUNCTIONS-----------------------------------------------------
