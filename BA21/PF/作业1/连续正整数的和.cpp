#include <iostream>
using namespace std;

int main(){
	int n=0;
	cin>>n;
	for (int a=1;a<=n/2;a++){
		for (int b=a+1;b<=n;b++){
			if((a+b)*(b-a+1)/2==n)
			cout<<a<<" "<<b<<endl;
		}
	}
	return 0;
}
