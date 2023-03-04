#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

void doGrep(int argc,char*argv[]) {
	//关于前面怎么识别目标值、文件名先不管
	 string word;
	string target;
	//step1：查找target里面的.和*
	int star[target.size()]; //用来记录*的位置的
	int dot[target.size()];
	int num_star=0;
	int num_dot=0;
	
	for(int i=0;i<target.size()]{
		star[i]=-1;
		dot[i]=-1;
	}
	for (int i=0;i<target.size();i++){
		if(str[i]=='*'){
			star[i]=1;
			num_star++;
		}
		if(str[i]=='.'){
			dot[i]=1;
			num_dot++;
		}
	} //查找记录点和星的位置，并记录个数
	
	ifstream fin("a.txt");
	while (fin.peek()!=EOF){
		fin>>word;
	}
	return;
}

int main(){
	char command[50];
	cin>>command;
	doGrep(1,command);
	return 0;
}
