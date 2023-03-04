#include <iostream>
using namespace std;

int divisor(int a,int b)
{
	if(a%b!=0)
		return divisor(b,a%b);
	else
		return b;
}

int main(){
	int T=0;
	cin>>T;
	int N[10]={0};
	int a[10][2009]={0};
	for(int i=0;i<T;i++){
		cin>>N[i];
		for(int k=0;k<N[i];k++)
			cin>>a[i][k];
	}
	
	int max=0,num=0;
	for(int i=0;i<T;i++){
		for(int k=0;k<N[i]-1;k++){
			num=divisor(a[i][k],a[i][k+1]);
			if(num>max)
				max=num;
		}
		cout<<max<<endl;
		max=0;
	}
	return 0;
}
