#include <iostream>
#include <cmath>
using namespace std;

int f(int m,int n){   //m^n
    if(n==1) return m;
    int temp=f(m,n/2);
    return (n%2==0 ? 1 : m)*temp*temp;
}

int last(int n,int m){ //n^m
	if(n>=1000)
		n%=1000;
	if(m==1) return n;
    int temp=last(n,m/2);
    return ((m%2==0 ? 1 : n)*temp*temp)%1000;
}

int main(){
	int N=0,M=0;
	cin>>N>>M;
	cout<<f(N,M)<<endl;
	cout<<last(N,M)<<endl;
	float x=log10(N);
	float y=x-(int)x;
	cout<<y<<endl;
	return 0;
}
