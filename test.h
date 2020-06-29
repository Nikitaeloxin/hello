#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "string"

using namespace std;

class Person{
public:
	Person(string ff, string ss, int aa)
	:first_name(ff), second_name(ss), age(aa){}
	Person(){}
	void set_age(int a){ age = a; }
	int get_age(){ return age; }

	void set_firt_name(string f){ first_name = f; }
	string get_first_name(){ return first_name; }

	void set_second_name(string s){ second_name = s; }
	string get_second_name(){ return second_name; }
private:
	string first_name;
	string second_name;
	int age;

};

ostream& operator<<(ostream& os, Person& p);			//OUTPUT PERSON
istream& operator>>(istream& is, Person& p);			//INPUT PERSON

void read_from_storage(string s, vector<Person>& p);	//READING INFORMATION FROM STORAGE
void write_to_storage(string s, vector<Person>& p);		//WRITING INFORMATION TO STORAGE

void info();											//INFORMATION BLOCK
void add_element(vector<Person>& P);					//INSTRUCRION ADD 
void del_element(vector<Person>& P, int a);				//INSTRUCRION DEL
void list_of_elements(vector<Person>& P);				//LIST OF ELEMENTS
void search_element(vector<Person>& P, string s);		//SEARCH POSITION
void exec_prog(vector<Person>& P);						//EXECUTE PROGRAM

