#include <iostream>
#include <string>
#include <cmath>
#include <fstream> 
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
	int i=0,j=0,start=0,star=-1,end=0,last=0;
	string word,target;
	bool right=false;
	
	//��һ����һ��ָ��������ʰȡ 
	block func;
	string filename;
	string command;
	bool untargeted=true;
	
	getline(cin,command); //��ʱ��cin������Ҫ�ĳ�argv[] 
	
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
	}//��������ˡ����ܿ��ء��Լ���target���롿�Լ���filename���롿 
	
	cout<<"func.A_num="<<func.A_num<<endl;
	cout<<"func.B_num="<<func.B_num<<endl;
	cout<<target<<endl;
	cout<<filename<<endl;
	
	//���������¶��Ǽ���ʶ��+��� 
	ifstream fin(filename.c_str());
	if(!fin)
		cout<<"File not found!" <<endl;
		
	while(fin.peek()!=EOF) {
		getline(fin,word) ;
		while(i<word.size())  {
			if(j<target.size()&&((word[i]==target[j])||target[j]=='.')) {
				if(j==0)  
					start=i;
				i++;
				j++;  
				if(j==target.size()) {
					right=true;
					end=i-1;  
					if (star==-1)
						break; 
				}
			}
			else if(j<target.size()&&target[j]=='*') {
				last=i; 
				star=j++;  
				if(j==target.size())  {
					right=true;  
					end=word.size()-1; 
					break;
				}
			} 
			else if(j==0)   {
				last=++i;  
			}
			else if(star!=-1)  {
				i=++last;   
				j=star+1;  
			}
			else if(star==-1) {
				i=++last; 
				j=0; 
			}
		}
		
		while(j<target.size()&&target[j]=='*')
			j++;
			
		//������ϣ������������ 
		if(right) {
			for (i=0;i<start;i++){
				cout<<word[i];
			}
			cout<<"\e[91;1m";
			for(int i=start;i<=end;i++)
				cout<<word[i];
			cout<<"\e[0m";
			for(int i=end+1;i<word.size();i++)
				cout<<word[i];
			cout<<endl;
		}
		else{
			for(int i=0;i<word.size();i++)
				cout<<word[i];
			cout<<endl;
		}
		i=0;
		j=0;
		start=0;
		end=0;
		last=0;
		star=-1;
		right=false;
	}
	fin.close();
	return 0;
}
