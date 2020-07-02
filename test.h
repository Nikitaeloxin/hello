#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "string"

using namespace std;

//----------------------------------------------------CLASS Person------------------------------------------------------------------

class Person{
public:
	Person(string ff, string ss="unknown", int aa=0)
		:first_name(ff), second_name(ss), age(aa){}
	Person()
		:first_name("unknown"), second_name("unknown"), age(0){}
	
	friend ostream& operator<<(ostream& os, Person& p);		//OUTPUT PERSON
	friend istream& operator>>(istream& is, Person& p);		//INPUT PERSON
	friend bool operator<=(Person& p1, Person& p2);		//COMPARE PERSON IN SEARCH
private:
	string first_name;
	string second_name;
	int age;

};
//----------------------------------------------------END CLASS Person------------------------------------------------------------------


//-----------------------------------------------TEMPLATE CLASS PositionList------------------------------------------------------------
template <class T> class PositionList{
public:
	void push_back( T t);		//ADD ELEMENT TO END OF LIST		
	void del_element(int i);	//DELETE SELECTED ELEMENT
	void list();				//OUTPUT LIST OF ELEMENTS
	void search(T s);			//SEARCH AMONG ELEMENTS OF LIST
private:
	vector<T> V;
};
//----------------------------------------------------END TEMPLATE CLASS PositionList------------------------------- -------------------------


//--------------------------------------TEMPLATE CLASS PositionList METHODS IMPLEMETATIONS----------------------------------------------------

template <class T> void PositionList<T>::push_back(T t){
	V.push_back(t);
}

template <class T> void PositionList<T>::del_element(int i){
	V.erase(V.begin() + i - 1);
}

template <class T> void PositionList<T>::list() {
	for (int i = 0; i < V.size(); i++)
		cout << V[i]<<endl;
}

template <class T> void PositionList<T>::search(T s) {
	bool indicate = false;					//FOR INDICATE NOT FOUND ANY ELEMENTS
	for (int i = 0; i < V.size(); i++){
		if (s <= V[i]){
			cout << V[i] << endl;
			indicate = true;
		}
	}
	if (!indicate)
		cout << "!--no elements found--!\n" << endl;
}

//----------------------------------------------------------END METHODS IMPLEMETATIONS----------------------------------------------------------


//----------------------------------------------------------OTHER FUNCTIONS---------------------------------------------------------
void info();

//----------------------------------------------------------END OTHER FUNCTIONS-----------------------------------------------------
