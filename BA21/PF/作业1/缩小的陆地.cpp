#include <iostream>
#include <cmath> 
using namespace std;

int main(){
	float x=0.0,y=0.0;
	double s=0;
	int Z=0;
	cin>>x>>y;
	if (x>=-10000&&x<=10000&&y>=0&&y<=10000)
	{
	s=3.14159/2*(x*x+y*y);
	Z=floor(s/50)+1;
	cout<<Z<<endl;}
	return 0;
} 
