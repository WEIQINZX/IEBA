#include <iostream>
using namespace std;

int main(){
	int N,temp=0;
	int random[100],order[100];
	cin>>N;
	for (int i=0;i<N;i++){
		cin>>temp;
		random[i]=temp;
	} 
	for(int i=0;i<100;i++){
		order[i]=0;
	}
	
	int cnt=0;
	int min=random[0];
	for (int i=0;i<N-1;i++){
		min=random[i];
		for(int j=i+1;j<N;j++){
			if (random[j]<min)
				min=random[j];
		}
		order[i]=min;
		cnt++;
		if (order[i]==order[i-1])
			order[i]=0;
	}
	
	cout<<cnt<<endl;
	for (int i=0;i<100;i++){
		if (order[i]!=0){
			cout<<order[i]<<" ";
		}
	} 
	cout<<endl;
	return 0;
}
