#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

void doGrep(int argc,char*argv[]) {
	//����ǰ����ôʶ��Ŀ��ֵ���ļ����Ȳ���
	 string word;
	string target;
	//step1������target�����.��*
	int star[target.size()]; //������¼*��λ�õ�
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
	} //���Ҽ�¼����ǵ�λ�ã�����¼����
	
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
