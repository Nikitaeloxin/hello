#include "head.h"

//OUTPUT PERSON
//---------------------------------------------------------------------------------------------------------------------------------
ostream& operator<<(ostream& os, Person& p){
	return os << p.get_first_name() << " " << p.get_second_name() << " " << p.get_age() << endl;
}
//---------------------------------------------------------------------------------------------------------------------------------


//INPUT PERSON
//---------------------------------------------------------------------------------------------------------------------------------
istream& operator>>(istream& is, Person& p){
	string f, s;
	int a;
	is >> f >> s >> a;
	p = Person(f, s, a);
	return is;
}
//---------------------------------------------------------------------------------------------------------------------------------

//READING INFORMATION FROM STORAGE
//---------------------------------------------------------------------------------------------------------------------------------
void read_from_storage(string s, vector<Person>& p){

	Person temp;				//temporary var for reading positions from storage

	ifstream ist(s, ios_base::binary);
	while (true){
		ist >> temp;
		if (temp.get_first_name() == "")
			break;
		p.push_back(temp);
	}
}
//---------------------------------------------------------------------------------------------------------------------------------

//INFORMATION BLOCK
//-----------------------------------------------------------------------------------------------------------------------------------
void info(){
	cout << "add - add Person to Vec end; " << endl
		<< "del - delete element from end;" << endl
		<< "list - output all list;" << endl
		<< "end - close" << endl;
}
//-----------------------------------------------------------------------------------------------------------------------------------

//WRITING INFORMATION TO STORAGE
//-----------------------------------------------------------------------------------------------------------------------------------
void write_to_storage(string s, vector<Person>& p){
	ofstream ost(s, ios_base::binary);
	for (int i = 0; i < p.size(); i++)
		ost << p[i];
}
//-----------------------------------------------------------------------------------------------------------------------------------

//INSTRUCRION ADD 
//-----------------------------------------------------------------------------------------------------------------------------------
void add_element(vector<Person>& P){
	try{
		string add_fname, add_sname; // var for temporary storage position
		int age;                     // var for temporary storage position
		cin >> add_fname >> add_sname >> age;
		if (cin.fail())
			throw 1;
		P.push_back(Person(add_fname, add_sname, age));
		cout << "!--element added--!" << endl;
	}
	catch (int i){
		cout << "Error! Incorrect input" << endl;
		cin.clear();
	}

}
//-----------------------------------------------------------------------------------------------------------------------------------


//INSTRUCRION DEL
//-----------------------------------------------------------------------------------------------------------------------------------
void del_element(vector<Person>& P, int a){
	try{
		if (cin.fail() || a > P.size() || a <= 0)
			throw 1;
		P.erase(P.begin() + a - 1);
		cout << "!--element deleted--!" << endl;
	}
	catch (int i){
		cout << "Error! Entered value out of range of elements" << endl;
		cin.clear();
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------

//SEARCH POSITION
//-----------------------------------------------------------------------------------------------------------------------------------
void search_element(vector<Person>& P, string s){
	for (int i = 0; i < P.size(); i++){
		if (s == P[i].get_first_name() || s == P[i].get_second_name())
			cout << P[i];
	}

}
//-----------------------------------------------------------------------------------------------------------------------------------

//LIST OF ELEMENTS
//-----------------------------------------------------------------------------------------------------------------------------------
void list_of_elements(vector<Person>& P){
	cout << "!--List of elements:--!" << endl;
	for (int i = 0; i < P.size(); i++)
		cout << P[i];
	cout << "!---------------------!" << endl;
}

//-----------------------------------------------------------------------------------------------------------------------------------

//EXECUTE PROGRAM
//-----------------------------------------------------------------------------------------------------------------------------------
void exec_prog(vector<Person>& P){
	int j;                      //indicate an element for del
	string search_str;          // string for search
	string str;				    // var for comands add, del, list,end
	while (str != "end"){
		cin >> str;

		if (str == "add"){
			add_element(P);
		}

		if (str == "del"){
			cin >> j;
			del_element(P, j);
		}

		if (str == "list"){
			list_of_elements(P);
		}
		if (str == "search"){
			cin >> search_str;
			search_element(P, search_str);
		}

	}
}
//-----------------------------------------------------------------------------------------------------------------------------------
