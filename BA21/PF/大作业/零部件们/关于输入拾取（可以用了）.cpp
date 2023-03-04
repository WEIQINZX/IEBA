#include <iostream>
#include <string>
#include <cmath>
using namespace std;
struct block{
	bool c;
	bool h;
	bool H;
	bool i;
	bool n;
	bool A;
	int A_num;
	bool B;
	int B_num; 
};

int main(){
	block func;
	string target;
	string filename;
	string command;
	bool untargeted=true;
	
	getline(cin,command);
	
	for(int i=0;i<command.size();i++){
		if(command[i]=='-'){
			if (command[i+1]=='c')
				func.c=true;
			if (command[i+1]=='h')
				func.h=true;
			if (command[i+1]=='H')
				func.H=true;
			if (command[i+1]=='i')
				func.i=true;
			if (command[i+1]=='n')
				func.n=true;
			if (command[i+1]=='A'){
				func.A=true;
				func.A_num=0;
			}
			if (command[i+1]=='B'){
				func.B=true;
				func.B_num=0;
			}
		}
		
		else if (command[i-1]=='A') {
			string str_numA;
			while(command[i]!=' '){
				str_numA+=command[i];
				i++;
			}
			for (int k=0;k<str_numA.size();k++){
				func.A_num+=(str_numA[k]-'0')*pow(10,(str_numA.size()-k-1));
			} 
		}
		
		else if(command[i-1]=='B') {
			string str_numB;
			while(command[i]!=' '){
				str_numB+=command[i];
				i++;
			}
			for (int k=0;k<str_numB.size();k++){
				func.B_num+=(str_numB[k]-'0')*pow(10,(str_numB.size()-k-1));
			} 
		}
		
		else if (i>4 && command[i-1]!='-' && command[i+1]!='-' && command[i]!=' '){
			if (untargeted){
				while (command[i]!=' '){
				target+=command[i];
				i++;
				}
				untargeted=false;
			}
			else
				while(i<command.size()){
					filename+=command[i];
					i++;
				}
		}
	}
	
	cout<<"numA="<<func.A_num<<endl;
	cout<<"numB="<<func.B_num<<endl;
	cout<<"target="<<target<<endl;
	cout<<"filename="<<filename<<endl;
	return 0;
}
