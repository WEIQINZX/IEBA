#include <iostream>
#include <string>
#include <cmath>
#include <string.h>
using namespace std;

void doGrep(int argc,char*argv[]){
	bool orderc=false;
	bool orderh=false;
	bool orderH=false;
	bool orderi=false;
	bool ordern=false;
	int orderA=0,orderB=0;
	int shift=0;
	int shift_position[100];
	string filename="";
	string target="";
	string wordall="";
	string num="";
	for(int i=0;i<argc;i++){
		if (argv[i][0]=='-'){
			if(argv[i][1]=='-')
				cout<<"help";//help具体内容晚点再说 
			if(argv[i][1]=='n')
				ordern=true;
			if(argv[i][1]=='c')
				orderc=true;
			if(argv[i][1]=='h') 
				orderh=true;
			if(argv[i][1]=='H')
				orderH=true;
			if(argv[i][1]=='i')
				orderi=true;
			if(argv[i][1]=='A'){ 
				int length=strlen(argv[i]); //代表数字位数 
				for(int k=2;k<length;k++) 
				orderA+=(argv[i][k]-'0')*pow(10,length-k-1); 
			} 
			if(argv[i][1]=='B'){ 
				int length=strlen(argv[i]); //代表数字位数 
				for(int k=2;k<length;k++) 
				orderB+=(argv[i][k]-'0')*pow(10,length-k-1); 
			} 
		}
		else{
			if(i==argc-2){
				for(int k=0;k<strlen(argv[i]);k++)
					target+=argv[i][k];
			} 
			if(i==argc-1){
				for(int k=0;k<strlen(argv[i]);k++)
					filename+=argv[i][k];
			}
		}
	}
	string strin="";
	string strout1="";
	char strout[20];
	strout1+=target;
	strout1+=" ";
	strout1+=filename;
	strcpy(strout,strout1.c_str()); //注意这一行，把string转成char[ ]就这么干 
	cout<<strout<<endl;
}
int main()
{
	int argc;
	char *argv[ ]={"grep","-n","-i","-c","-H","-A2","-B2","w*q","a.txt"}; 
	cin>>argc;
	doGrep(argc,argv);
	
	return 0;
}
