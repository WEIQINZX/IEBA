#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

int digit(int n){
	if (n>=0 && n<10)
		return 1;
	if (n>=10 && n<100)
		return 2;
	if (n>=100 && n<1000)
		return 3;
	if (n>=1000 && n<10000)
		return 4;
	if (n>=10000 && n<100000)
		return 5;
	if (n>=100000 && n<1000000)
		return 6;
	if (n>=1000000)
		return 7;
}

string f(int m,int n){   //m^n
    if(n==1) return m;
    int temp=f(m,n/2);
    long long result;
    int dig=digit((n%2==0 ? 1 : m)*temp*temp);
    result=(n%2==0 ? 1 : m)*temp*temp);
    string str=
    return str;
}

int main(){
	int N=0,M=0;
	cin>>N>>M;
	
	cout<<endl;
	return 0;
}
