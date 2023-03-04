#include <iostream>
using namespace std;

int main(){
	int N=0;
	int step[50000];
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>step[i];
	int start=0,cnt=0,max=0,i=0;
	if(N==1)
		cnt=0;
	else while(1){
		if(start+step[start]>=N-1){
			cnt++;
			break;
		}
		for(int k=start+1;k<=start+step[start];k++)
			if (k+step[k]>max){
				max=step[k]+k;
				i=k;
			}
		cnt++;
		start=i;
	} 
	cout<<cnt<<endl;
	return 0;
} 
