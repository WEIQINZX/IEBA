#include <iostream>
using namespace std;

int longest(int n,int N,int num[],int a[])
{
	int maxl=1;
	for(int i=n+1;i<N;i++)
	{
		if(num[i]>num[n])
		{
			if(a[i]==0)
				a[i]=longest(i,N,num,a);
			if(a[i]>maxl-1)
				maxl=a[i]+1;
		}
	}
	//cout<<"n="<<n<<",maxl="<<maxl<<",a="<<a[n]<<endl;
	return maxl;
}

int main(){
	int N=0;
	cin>>N;
	int num[N];
	for(int k=0;k<N;k++)
		cin>>num[k];
	int a[N];
	for(int i=0;i<N;i++)
		a[i]=0;
	int maxl=-1;
	for(int i=0;i<N;i++){
		int temp=longest(i,N,num,a);
		if(temp>maxl)
			maxl=temp;
		}
	cout<<maxl<<endl;
	return 0;
}
