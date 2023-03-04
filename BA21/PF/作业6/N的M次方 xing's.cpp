#include <iostream>
#include <math.h>

using namespace std;
int first(int n,int m)
{
	if(m==1)
	{
		return n;
	}
	int res=0;
	if(m%2==0)
	{
		res=first(n,m/2);
		res=res*res;
	}
	else
	{
		res=first(n,(m-1)/2);
		res=res*res*n;
    }
	while(res>10000)
	{
		res/=10;
	}
	return res;
}

int last(int n,int m)
{
	if(m==1)
		return n;
	int res=0;
	if(m%2==0)
	{
		res=last(n,m/2);
		res=res*res;
	}
	else
	{
		res=last(n,(m-1)/2);
		res=res*res*n;
    }
	if(res>1000)
	{
		res%=1000;
	}
	//cout<<"n="<<n<<",m="<<m<<",res="<<res<<endl;
	return res;
}

int main() 
{
	int N=0;
	cin>>N;
	int n[N],k[N];
	int f,l;
	for(int i=0;i<N;i++)
	{ 
		cin>>n[i]>>k[i];
	}
	for(int i=0;i<N;i++)
	{
		if(k[i]%2==0)
		{
			f=first(n[i],k[i]);
			l=last(n[i],k[i]);
		}
		else
		{
			f=first(n[i],k[i]-1)*n[i];
			l=last(n[i],k[i]-1)*n[i];
		}
		while(f>1000)
			f/=10;
			
		int la[3];
		l%=1000;
		if(l>=100){
			la[0]=l/100;
			la[1]=(l%100)/10;
			la[2]=l%10;
		}
		else if(l>=10){
			la[0]=0;
			la[1]=l/10;
			la[2]=l%10;
		}
		else{
			la[0]=0;
			la[1]=0;
			la[2]=l;
		}
		
		if(f>=100)
			cout<<f<<' '<<la[0]<<la[1]<<la[2]<<endl;
		else if(f>=10)
			cout<<"0"<<f<<" "<<la[0]<<la[1]<<la[2]<<endl;
		else
			cout<<"00"<<f<<" "<<la[0]<<la[1]<<la[2]<<endl;
	}	
	return 0;
}
