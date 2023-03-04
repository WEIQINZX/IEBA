#include <iostream>
#include <cmath> 

using namespace std;
int main(){
	int a=0,b=0,c=0,t=0;
	cin>>t;
	if (t>=1&&t<=10000)
	{
	a=t/1440;
	b=(t-1440*a)/60;
	c=t-1440*a-60*b;
	cout<<a<<" "<<b<<" "<<c<<endl;
    }
	return 0;
}
