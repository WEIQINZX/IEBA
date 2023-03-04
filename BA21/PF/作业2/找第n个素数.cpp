#include <iostream>
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
	int n=0,a=0;
	int p=0;
	cin>>n;
	p=Prime(n);
	cout<<p<<endl;
	return 0;
}
