#include "test.h"


int main(int argc, char *argv[])
{
    string str1,str2,str3;
    int a;
    vector<Person> P;

    cout << " add - add Person to Vec end; " <<endl
         << "del - delete element from end;" << endl
         << "list - output all list;" << endl
         << "end - close" << endl;

    while(str1 != "end"){
        cin >> str1;
        if(str1 == "add"){
            cin >> str2 >> str3 >> a;
            P.push_back(Person(str2,str3,a));
        }
        if(str1 == "list"){
            for (int i = 0; i < P.size();i++)
                cout << P[i];
        }
    }
    return 0;
}
