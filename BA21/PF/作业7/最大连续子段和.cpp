#include <iostream>
using namespace std;

int sum[50000];
bool done[50000];
int summax(int n,int N,int num[]){
//n-��num[n]��ʼ����Ӷκ� 
	if(n==N-1)
		return num[n];
	else{
		int sum1=-1,summ=-1; //sum1-����n+1���� sum2-������n+1���� ->��ʵҲ����num[n] 
		if(done[n+1])
			sum1=num[n]+sum[n+1];
		else
			sum1=num[n]+summax(n+1,N,num);
		if(sum1>num[n])
			summ=sum1;
		else
			summ=num[n];
		sum[n]=summ;
		done[n]=true;
		return summ;
	}
} 

int main(){
	int N=0;
	cin>>N;
	int num[N];
	for(int i=0;i<N;i++)
		cin>>num[i];
	for(int i=0;i<N;i++)
		done[i]=false;
	int max=-1;
	for(int i=0;i<N;i++){
		int temp=summax(i,N,num);
		if(temp>max)
			max=temp;
	}
	cout<<max<<endl;
	return 0;
}
