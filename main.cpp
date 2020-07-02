#include "head.h"


int main(int argc, char *argv[])
{

	//variables
	//--------------------------------------------------------------------------------------------------------------------------------
	PositionList<Person> p;                              //list of position
	std::string dataSource = "..//storage//storage.txt"; //storage for writing and reading data (for persistant)
	string str;                                          // for choose input option
	int j;												 //for delete
	Person temp;										 //for add and search
	//--------------------------------------------------------------------------------------------------------------------------------
	
	info();

	while (str != "end"){
		cin >> str;

		if (str == "add"){
			Person temp;
			cin >> temp;
			p.push_back(temp);
			cout << "!--element added--!\n" << endl;
		}

		if (str == "del"){
			cin >> j;
			p.del_element(j);
			cout << "!--element deleted--!\n" << endl;
		}

		if (str == "list"){
			p.list();
		}
		if (str == "search"){
			cin >> temp;
			p.search(temp);

		}
	}
	
	return 0;
}
