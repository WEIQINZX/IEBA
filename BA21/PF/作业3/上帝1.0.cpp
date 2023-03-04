#include <iostream>
using namespace std;

int main(){
	int n,Q,A=0;
	int lo[1985],hi[1985],a[1985];
	cin>>n>>Q;
	for (int i=0;i<n;i++){
		cin>>A;
		a[i]=A;
	}
	
	for(int j=0;j<Q;j++){
		cin>>lo[j]>>hi[j];
	}
	
	int min=0;
	for(int j=0;j<Q;j++){
		min=a[lo[j]];
		for(int i=lo[j];i<=hi[j];i++){
			if (a[i]<min)
				min=a[i];
		}
		cout<<min<<endl;
	}
	return 0;
}
