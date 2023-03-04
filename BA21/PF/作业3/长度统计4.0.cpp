#include <iostream>
using namespace std;

void swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
} 

int main(){
	int n=0;
	int left[1001];
	int right[1001];
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>left[i]>>right[i];
	} 
	
	for(int j=0;j<n;j++){
		for (int i=n-1;i>=j;i--){
			if (left[i]<left[i-1]){
				swap(left[i],left[i-1]);
				swap(right[i],right[i-1]);
			}
		} 
	}  //按左端点排序 
	
	int length=right[0]-left[0];
	int right_max=right[0];
	for (int i=1;i<n;i++){
		if (left[i]<right_max && right[i]>right_max){
			length+=(right[i]-right_max);
			right_max=right[i];
		}
		if (left[i]>=right_max){
			length+=(right[i]-left[i]);
			 right_max=right[i];
		}
	}  //分类讨论，right_max用来判断case 
	
	cout<<length<<endl;
	return 0;
}
