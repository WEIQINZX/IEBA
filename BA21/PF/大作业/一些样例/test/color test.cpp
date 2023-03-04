#include <iostream>
using namespace std;
int main() {
	string str="whatever"; 
 	cout << "\e[91;1mT\e[92;1mi\e[94;1mn\e[0my" << endl;
 	
 	//¹ØÓÚcolored string 
 	
 	cout<<"\e[91;1m";
 	for (int i=0;i<8;i++) 
	cout<<str[i];
	
 	cout<<"\e[0m"<<endl;
 return 0;
}
