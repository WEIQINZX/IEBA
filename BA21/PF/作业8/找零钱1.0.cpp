#include <iostream>
using namespace std;

struct mon{
	int value;
	int num;
};
mon money[9];

int main(){
	int N=0;
	cin>>N;
	N=N/10;
	//1000,500,100,50,20,10,5,2,1 
	for(int i=0;i<9;i++){
		money[i].num=0;
	}
	money[0].value=1000;
	money[1].value=500;
	money[2].value=100;
	money[3].value=50;
	money[4].value=20;
	money[5].value=10;
	money[6].value=5;
	money[7].value=2;
	money[8].value=1;
	for(int i=0;i<9;i++){
		if(N/money[i].value>0){
			money[i].num=N/money[i].value;
			N=N%money[i].value;
		}
	}
	cout<<money[0].num;
	for(int i=1;i<9;i++)
		cout<<" "<<money[i].num;
	cout<<endl;
	return 0;
}
