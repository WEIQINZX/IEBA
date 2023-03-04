#include <iostream>

using namespace std;
int main(){
	int a=0,b=0,c=0,s=0;
	cin>>a;
	cin>>b;
	cin>>c;
	if (a>=0&&b>=0&&c>=0&&a<=200&&b<=200&&c<=200)
	{
	s=3*a+2*b+8*c;
	cout<<s<<endl;
	}
	return 0;
} 
