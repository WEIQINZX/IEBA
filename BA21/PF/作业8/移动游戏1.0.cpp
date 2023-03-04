#include <iostream>
using namespace std;

int main(){
	int N=0;
	cin>>N;
	int step[50000];
	for(int i=N-1;i>=0;i--)
		cin>>step[i];
	int start=0,cnt=0;
	int i=0;
	if(N==1)
		cnt=0;
	else if(step[N-1]>=N-1)
		cnt=1;
	else{
		while(i<N-1){
			for(int k=i+1;k<N;k++){ //when i=N-1,k=N
				if(step[k]>=k-i){
					start=k;
				}
				cout<<"start="<<start<<endl;
			} //find the furthest,and record it with[start]
			i=start;
			cnt++;
			cout<<"i="<<i<<" cnt="<<cnt<<endl;
			if(step[N-1]>=N-1-i){
				cnt++;
				break;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
