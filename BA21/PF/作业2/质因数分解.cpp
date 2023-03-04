#include <iostream>
#include<string.h>
using namespace std;

bool bePrime (int n){
	bool prime=true;
	for(int i=2;i<n;i++) {
		if (n%i==0){
			prime=false;
			break;
		}
	}
	return prime;
}

int Prime(int n){
	int p=2;
	int sum=1;
	while (sum<n){
		p++;
		if (bePrime(p))
			sum++;
	}
	return p;
}

int main(){
	int N=0,j=0;
	cin>>N;
	int p[N];
	for (int n=1;n<=N;n++){
		p[n]=Prime(n);
	}
	int rem=N;
	char factor[j];
	int k=1;
	for (j=0;j<N;j++){
		if (rem%p[k]==0){
			factor[j]=p[k];
			k++;
			rem=rem/p[k];
		}
		else
			j--;
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
	for (int i=0;i<=j;i++){
		 cout<<factor[i]<<endl;
	}
	return 0;
} 
