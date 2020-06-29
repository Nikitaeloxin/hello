#include "head.h"


int main(int argc, char *argv[])
{

	//variables
//--------------------------------------------------------------------------------------------------------------------------------
	
	vector<Person> P;           //vector for storage positions
	string dataSource = "C:\\Users\\дом\\Documents\\Visual Studio 2013\\Projects\\test_fort_vs\\buffer.txt"; //storage for writing and reading data (for persistant)
//--------------------------------------------------------------------------------------------------------------------------------
	read_from_storage(dataSource, P);
	info();
	exec_prog(P);
	write_to_storage(dataSource, P);
	return 0;
}
