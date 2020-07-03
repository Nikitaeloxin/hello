#include <iostream>
#include <fstream>
#include <vector>
#include "string"

using namespace std;

//----------------------------------------------------CLASS Person------------------------------------------------------------------

class Person{
public:
	Person(string ff, string ss, int aa)
		:first_name(ff), second_name(ss), age(aa){}
	Person(){}

	void set_age(int a){ age = a; }
	int get_age(){ return age; }

	void set_first_name(string f){ first_name = f; }
	string get_first_name(){ return first_name; }

	void set_second_name(string s){ second_name = s; }
	string get_second_name(){ return second_name; }
	
	friend ostream& operator<<(ostream& os, Person& p);		//OUTPUT PERSON
	friend istream& operator>>(istream& is, Person& p);		//INPUT PERSON
	friend bool operator==(Person& p1, Person& p2);		//COMPARE PERSON IN SEARCH
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
	void read_from_storage(string s);		//READING INFORMATION FROM STORAGE
	void write_to_storage(string s);		//WRITING INFORMATION TO STORAGE

private:
	vector<T> V;
};
//----------------------------------------------------END TEMPLATE CLASS PositionList------------------------------- -------------------------


//--------------------------------------TEMPLATE CLASS PositionList METHODS IMPLEMETATIONS----------------------------------------------------

template <class T> void PositionList<T>::push_back(T t){
	V.push_back(t);
	cout << "!--element added--!\n" << endl;
}

template <class T> void PositionList<T>::del_element(int i){
	
	if (i > V.size() || i < 0){
		cout << "There isn't element with this number\n" << endl;
		return;
	}
	else{
		V.erase(V.begin() + i - 1);
		cout << "!--element deleted--!\n" << endl;
	}
		
}

template <class T> void PositionList<T>::list() {
	if (V.size() == 0)
		cout << "List is empty\n" << endl;
	else{
		cout << "!--List of elements:--!" << endl;
		for (int i = 0; i < V.size(); i++)
			cout << V[i] << endl;
		cout << "!---------------------!\n" << endl;
	}
	
}

template <class T> void PositionList<T>::search(T s) {
	bool search_res_exist = false;					//FOR INDICATE NOT FOUND ANY ELEMENTS
	for (int i = 0; i < V.size(); i++){
		if (s == V[i]){
			cout << V[i] << endl;
			search_res_exist = true;
		}
	}
	if (!search_res_exist)
		cout << "!--no elements found--!\n" << endl;
}

template <class T> void PositionList<T>::read_from_storage(string s){
	T buff;				//temporary var for reading positions from storage
	ifstream ist(s.c_str());
		while (true){
			ist >> buff;
			if (buff.get_first_name() == "")
				break;
			V.push_back(buff);
		}
}

template <class T> void PositionList<T>::write_to_storage(string s){
	ofstream ost(s.c_str());
	for (int i = 0; i < V.size(); i++)
		ost << V[i] <<endl;
}

//----------------------------------------------------------END METHODS IMPLEMETATIONS----------------------------------------------------------


//----------------------------------------------------------OTHER FUNCTIONS---------------------------------------------------------------------
void info();     //OUTPUT INFORMATION

//EXECUTE PROG
//-----------------------------------------------------------------------------------------------------------------------------------
template <class T>
void exec_prog(string s, PositionList<T> P){
	string choose_str;                                   // for choose input option
	int j;												 //for chose number of delete element
	T temp;												 //temporary var for add and search

	P.read_from_storage(s);

	while (choose_str != "end"){
		cin >> choose_str;

		if (choose_str == "add"){
			try{
				cin >> temp;
				if (cin.fail())
					throw 1;
				P.push_back(temp);
			}
			catch (int i){
				cout << "Incorrect input! Try again\n" << endl;
				cin.clear();
			}
		}

		if (choose_str == "del"){
			try{
				cin >> j;
				if (cin.fail())
					throw 1;
				P.del_element(j);
			}
			catch (int i){
				cout << "Incorrect input! Try again\n" << endl;
				cin.clear();
			}
		}

		if (choose_str == "list"){
			P.list();
		}
		if (choose_str == "search"){
			try{
				cin >> temp;
				if (cin.fail())
					throw 1;
				P.search(temp);
			}
			catch (int i){
				cout << "Incorrect input! Try again\n" << endl;
				cin.clear();
			}
		}
	}
	P.write_to_storage(s);
}
//-----------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------END OTHER FUNCTIONS-----------------------------------------------------------------
