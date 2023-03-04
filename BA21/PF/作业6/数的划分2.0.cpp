#include <iostream>
using namespace std;

int divide(int a,int b,int last){
	int times=0;
	if(b==1 && a-last>=0)
		return 1;
	else{
		for(int i=last;i<=(a-b+1);i++)
			times+=divide(a-i,b-1,i);
	}
	return times;
}

int main(){
	int n=0,k=0;
	cin>>n>>k;
	cout<<divide(n,k,1)<<endl;
	return 0;
}
