#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int k=0; 
	long double n=1.0;
	long double sum=0.0;
	cin>>k;
	for (n=1.0;n>=1;n=n+1){
		sum=sum+1/n;
		if(sum>k)
			break;
	}
	cout<<setprecision(7)<<n<<endl;
	return 0;
} 
