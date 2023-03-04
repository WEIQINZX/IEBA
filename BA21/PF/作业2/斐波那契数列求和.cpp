#include <iostream>
using namespace std;

int fibon(int n){
	if (n==1||n==2)
		return 1;
	else
		return fibon(n-1)+fibon(n-2);
}

int main(){
	int sum=0;
	int N=0;
	int t=0;
	cin>>N;
	for (int n=1;n<=N;n++){
		if (sum<=fibon(n))
			sum=sum+fibon(n);
		else
			sum=sum-fibon(n) ;
	}
	t=sum%1000000007;
	cout<<t<<endl;
	return 0;
}
