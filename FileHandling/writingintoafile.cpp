#include<iostream>
#include<fstream>

using namespace std;
int main(){

    fstream file;
    file.open("Items1.txt", ios::out);
    if(!file)
    {
        cout << "We could not open the file";
    } else {
        string itemname;
        float cost;
        cout << "Enter item name: ";
        cin >> itemname;
        cout << "Enter cost: ";
        cin >> cost;
        file << itemname << "\n";
        file << cost << "\n";
    }
    file.close();
    return 0;
}