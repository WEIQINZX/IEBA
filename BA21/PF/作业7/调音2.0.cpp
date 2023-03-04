#include <iostream>
using namespace std;

int maxlevel(int n,int b,int m,int c[]){
	if(n==0){
		if(b+c[n]<m)
			return b+c[n];
		else if(b-c[n]>0)
			return b-c[n];
		else
			return -1;
	}
	
	int bp=-1,bm=-1;
	bp=maxlevel(n+1,b-c[n+1],m,c);
	bm=maxlevel(n-1,b+c[n+1],m,c);
	if(bp>bm)
		return bp;
	else
		return bm;
}

int main(){
	int N=0,b=0,m=0;
	int c[N];
	cin>>N>>b>>m;
	for (int i=N-1;i>=0;i--)
		cin>>c[i];
	int max=maxlevel(N-1,b,m,c);
	cout<<max<<endl;
	return 0;
}
