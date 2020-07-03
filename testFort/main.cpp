#include "head.h"


int main(int argc, char *argv[])
{

	//variables
	//--------------------------------------------------------------------------------------------------------------------------------
	PositionList<Person> p;                              //list of position
	std::string dataSource = "..//storage//storage.txt"; //storage for writing and reading data (for persistant)
	//--------------------------------------------------------------------------------------------------------------------------------
	
	info();
	exec_prog(dataSource, p);
	
	return 0;
}
