#include <iostream>
#include <vector>

using namespace std;

struct Person{
    Person(string ff, string ss, int aa)
        :first_name(ff),second_name(ss), age(aa){}
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

ostream& operator<<(ostream& os, Person& p){
    return os << p.get_first_name() << " "<< p.get_second_name()<< " " << p.get_age() << endl;
}

istream& operator>>(istream& is, Person& p){
    string f,s, add;
    int a;
    cout << "input the Person's value" << endl;
    is >>add>> f >> s >> a;
    p = Person(f,s, a);
    return is;
}
