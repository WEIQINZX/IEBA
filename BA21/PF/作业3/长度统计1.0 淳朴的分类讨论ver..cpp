#include <iostream>
using namespace std;

int main(){
	int n=0;
	int sum=0;
	int minus=0;
	int length=0;
	int left[1001],right[1001];
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>left[i]>>right[i];
	}
	
	for (int i=0;i<n;i++){
		sum+=(right[i]-left[i]);
	}
	
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (right[j]>left[i]&&left[j]<left[i] && right[i]>right[j]) //部分重合 
				minus+=(right[j]-left[i]);
			if (i!=j && left[j]>=left[i] && right[j]<=right[i]) //全部重合 
				minus+=(right[j]-left[j]);
			if (i!=j && left[i]==left[j] && right[i]==right[j])
				minus+=((right[j]-left[j])/2);
		}
	}
	
	length=sum-minus;
	cout<<length<<endl;
	return 0;
}
