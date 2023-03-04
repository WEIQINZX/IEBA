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

	for (int i=0; i<N; i++){
		for (int j=i; j<N; j++){
			for (int k=0; k<M; k++){
				for (int l=k; l<M; l++){
					profit = 0;
					for (int m=i; m<=j; m++){
						for (int n=k; n<=l; n++){
    						profit += factor[m][n];
}
}
if (profit >max) max = profit;
}
}
}
}
	
	cout<<max<<endl;
	return 0;
}
