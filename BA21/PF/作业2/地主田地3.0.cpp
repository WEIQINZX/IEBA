#include <iostream>
using namespace std;

int main(){
	int N=0,M=0;
	cin>>N>>M;
	int factor[N+1][M+1];
	for (int i=0;i<=N;i++){
		for (int j=0;j<=M;j++){
			if (i==0||j==0)
				factor[i][j]=0;
			else
				cin>>factor[i][j];
		}
	}
	
	int b[N][M];
	for (int i=0;i<N;i++){  //从第一行开始挪 
		for (int j=0;j<M;j++){  //从第一列开始挪 
		b[i][j]=0;
			for (int k=0;k<=i;k++){  
				for (int l=0;l<=j;l++){
					b[i][j]+=factor[k][l];  //把[0][0]到[i][j]包的所有factor加起来得总profit 
				}
			}
		}
	}
	
	int profit=0;
	int max=factor[0][0];
	for (int r1=0;r1<N-1;r1++){ //起始点从第一行开始 ，到最后一行结束 
		for (int c1=0;c1<M-1;c1++){  //起始点从第一列开始 ，到最后一列结束 
			for(int r2=r1;r2<N;r2++){  //终止点从同行开始 ，到最后一行结束 
				for (int c2=c1;c2<M;c2++){  //终止点从同列开始，到最后一列结束 
					if (r1==r2&&c1==c2)
						profit=factor[r1][c1];
					else
						profit=b[r2][c2]-(b[r1][c2]+b[r2][c1]-b[r1][c1]);
					if (profit>max)
						max=profit;
				}
			}
		}
	}

	cout<<max<<endl;
	return 0;
}
