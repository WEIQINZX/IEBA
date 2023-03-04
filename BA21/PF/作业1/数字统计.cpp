#include <iostream>
using namespace std;

int main(){
	int L=0,R=0;
	cin>>L>>R;
	int num=0;
	for(int a=L;a<=R;a++){
		if(a%10==2&&a>=10&&a<100)
		num++;
		if(a % 100 / 10 == 2 && a>=100&&a<1000)
	    num++;
	    if(a%1000/100==2&&a>=1000)
	    num++;
	}
	cout<<num<<endl;
	return 0;
}
