#include <iostream>
using namespace std;

int main(){
	int N=0,M=0,profit=0;
	cin>>N>>M;
	int factor[N][M];
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			cin>>factor[i][j];
		}
	}
	int max=factor[0][0];
	
	for (int n=1;n<=N;n++){
		for (int m=1;m<=M;m++){ 
			for (int i=0;i<=N-n;i++){   
				for (int j=0;j<=M-m;j++){  
					profit=0; 
					for (int k=i;k<i+n;k++){
						for (int l=j;l<j+m;l++){
							profit=profit+factor[k][l];  
						}
					} 
					if (profit>max)
						max=profit;
				}
			} 
		} 
	}
	
	cout<<max<<endl;
	return 0;
}
