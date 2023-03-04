#include <iostream>
using namespace std;

int main(){
	int N=0,j=0,rem=0;
	int factor[3000];
	cin>>N;
	rem=N;
	for(int i=2;i<=N;i++){
		if(rem%i==0){
			factor [j]=i;
			j++;
			rem=rem/i;
			i--;
		}
	}
	
	char type='A';
	int a=0;
	for (int i=0;i<j;i++){
		a=factor[i]-factor[i+1];
		if (a==0){
			type='B';
			break;
		}
	}
	cout<<type<<endl;
	for (int i=0;i<j;i++){
		 cout<<factor[i]<<endl;
	}
	return 0;
}
