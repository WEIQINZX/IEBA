#include <iostream>
using namespace std;

int times(int n){
	if(n==6174)
		return 0;
	int num[4];
	for(int i=0;i<4;i++){
		num[3-i]=n%10;
		n/=10;
	}	
	//cout<<"num[]1=";for(int i=0;i<4;i++)cout<<num[i]<<" ";cout<<endl;

	int temp=0,t=0;
	for(int i=0;i<4;i++){
		for(int k=0;k<3;k++){
			if(num[k]>num[k+1]){
				t=num[k];
				num[k]=num[k+1];
				num[k+1]=t;
			}
		}
	}
	//cout<<"ÅÅĞòºóÎª";for(int i=0;i<4;i++)cout<<num[i]<<" ";cout<<endl;
	temp=num[3]*1000+num[2]*100+num[1]*10+num[0]-(num[0]*1000+num[1]*100+num[2]*10+num[3]);
	return 1+times(temp);
}

int main(){
	int n=0,num[4];
	cin>>n;
	int cnt=0;
	cnt=times(n);
	cout<<cnt<<endl;
	return 0;
} 
