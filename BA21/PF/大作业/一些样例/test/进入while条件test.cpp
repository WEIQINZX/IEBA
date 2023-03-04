#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
	string filename,word;
	cin>>filename;
	ifstream fin(filename.c_str());
	
	while (fin.peek()!=EOF){
		getline(fin,word) ;
		cout<<word<<endl;
	}
	return 0;
}
