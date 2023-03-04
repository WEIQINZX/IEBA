#include <iostream>
using namespace std;

int stairs(int h){
	if(h<=0)
		return 0;
	if(h==1)
		return 1;
	if(h==2)
		return 2;
	if(h==3)
		return 4;
	return stairs(h-1)+stairs(h-2)+stairs(h-3);
}

int main(){
	int h=0;
	cin>>h;
	int cnt=0;
	if(h<4 || h>20)
		cnt=0;
	else
		cnt=stairs(h);
	cout<<cnt<<endl;
	return 0;
}
