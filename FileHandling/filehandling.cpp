#include<iostream>
#include<fstream>

using namespace std;

int main(){

fstream f;

f.open("name.txt", ios::out);

f.close();
}