#include <iostream>
using namespace std;
int largestsum[100000];//用来记录加到i位时可能的最大和 

int largest(int n,int N,int num[]){ 
//n-表示从n开始往后加数的最大和，N-总数，num-循环数组 
	if(n==N-1 || n==N-2)
		return num[n]; 
	else{
	int sum2=-1,sum3=-1;
	int sum=-1;
	if(largestsum[n+2]!=0)
		sum2=num[n]+largestsum[n+2];
	else
		sum2=num[n]+largest(n+2,N,num);
	if(largestsum[n+3]!=0 &&n!=N-3)  
		sum3=num[n]+largestsum[n+3];
	else if(n!=N-3)
		sum3=num[n]+largest(n+3,N,num);
	else
		sum3=-1;
	if(sum2>sum3)
		sum=sum2;
	else
		sum=sum3;
	largestsum[n]=sum;
	//cout<<"n="<<n<<",sum="<<sum<<",sum2="<<sum2<<",sum3="<<sum3<<endl;
	return sum;
	}
}

int main(){
	int N=0;
	cin>>N;
	int num[N];
	for(int i=0;i<N;i++)
		cin>>num[i];
	if(N==1)
		cout<<num[0]<<endl;
	else{
	int largest_sum1=largest(0,N,num);
	int largest_sum2=largest(1,N,num);
	int largest_sum=0;
	if(largest_sum1>largest_sum2)
		largest_sum=largest_sum1;
	else
		largest_sum=largest_sum2;
	cout<<largest_sum<<endl;
}
	return 0;
} 
