#include <iostream>
using namespace std;

int main(){
	 int sum=0;
	 int N=0;
	 int t=0;
	 cin>>N;
	int a[N];
	a[1]=1;
	a[2]=1; 
	for (int n=1;n<=N;n++){
		if(n!=1&&n!=2)
		a[n]=(a[n-1]+a[n-2])%1000000007;
		if (sum<=a[n])
		   sum=(sum+a[n])%1000000007;
		else
		   sum=(sum-a[n])%1000000007;
	 }
	 t=sum%1000000007;
	 cout<<t<<endl;
	 return 0;
} 
