#include<iostream>
#include<fstream>

using namespace std;
int main(){

    fstream file;
    file.open("Items1.txt", ios::in);
    if(!file)
    {
        cout << "We could not open the file";
    } else {
        string name;
        float cost;
        file >> name;
        file >> cost;
        cout << "detailes ate:" << endl;
        cout << name << "\n" << cost;
    }
    file.close();
    return 0;
}