#include <iostream>
using namespace std;
int a[1000]; 
int longest(int n,int N,int num[]){
	//n-从第n个开始最长的上升序列有多长，N-总数
	if(n==N-1)
	 	return 1;
	else{
		int i=0;
		int sum=0;
		for(i=n+1;i<N;i++)
			if(num[i]>num[n])
				break;
		if(i==N)
			sum=1;
		else if(a[i]!=0)
			sum=1+a[i];
		else
			sum=1+longest(i,N,num);
		a[n]=sum;
		//cout<<"i="<<i<<",sum="<<sum<<endl;
		return sum;
	}
} 

int main(){
	int N=0;
	cin>>N;
	int num[1000];
	for(int k=0;k<N;k++)
		cin>>num[k];
	int maxl=-1;
	for(int k=N-1;k>=0;k--){
		int temp=longest(k,N,num);
		if(temp>maxl)
			maxl=temp;
	}
	cout<<maxl<<endl;
	return 0;
}
