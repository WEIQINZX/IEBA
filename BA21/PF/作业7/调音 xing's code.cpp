#include <iostream>

using namespace std;
int c[1000];
int maxl(int n,int b,int m)
{
	//cout<<"n="<<n<<",b="<<b<<",cn="<<c[n]<<endl;
	if(n==0)
	{
		if(b+c[0]<=m)
			return b+c[0];
		else if(b-c[0]>=0)
			return b-c[0];
		else 
			return -1;
	}
	int bp=-1,bm=-1;
	if(b+c[n]<=m)
		bp=maxl(n-1,b+c[n],m);
	if(b-c[n]>=0)
		bm=maxl(n-1,b-c[n],m);
	//cout<<"b+c="<<b+c[n]<<" b-c="<<b-c[n]<<endl;
	if(b+c[n]>m && b-c[n]<0)
		return -1;
	if(bm>bp)
		b=bm;
	else
		b=bp;
	return b;
}
int main() 
{
	int n=0,b=0,m=0;
	cin>>n>>b>>m;
	for(int i=n-1;i>=0;i--){ 
		cin>>c[i];
		} 
	int maxlevel=maxl(n-1,b,m);
	cout<<maxlevel<<endl;
	return 0;
}
