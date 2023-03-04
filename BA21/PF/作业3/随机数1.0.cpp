#include <iostream>
using namespace std;

int main(){
	int N,M,temp=0;
	int random[100],carry[1001],order[100];
	cin>>N;
	for (int i=0;i<N;i++){
		cin>>temp;
		random[i]=temp;
	}
	for(int i=0;i<1001;i++){
		carry[i]=0;
	}
	
	for (int i=0;i<N;i++){
		carry[random[i]]++;
	}
	
	int j=0;
	for (int i=0;i<1001;i++){
		if (carry[i]!=0){
			order[j]=i;
			j++;
		}
	}
	
	cout<<j<<endl;
	for (int k=0;k<j;k++){
		if (k!=j-1)
			cout<<order[k]<<" ";
		else
			cout<<order[k];
	}
	cout<<endl;
	
	return 0;
} //还可以一边去重一边输出，把计数和输出放在两个任务里 
