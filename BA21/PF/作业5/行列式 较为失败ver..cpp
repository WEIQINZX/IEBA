#include <iostream>
using namespace std; 

int N;
int A[N][N];
int cofactor(int i,int j){
	int result=0;
	if (i==N-2) //�����˵����ڶ��� ����ô֪����Ӧ�÷����ҵ�j��߻����ұߵ���ֵ�أ�->��ʱһ���Ǹ�2*2�ľ��� 
		return A[i][j]*A[N-1][��] //�ݺ��ɻ� 
		
	
	for (int m=i;m<N;m++){
		for(int n=0;n<N;n++){
			if (n!=j)
			result+=A[m][n]*cofactor(m,n);
		}
	}
	if ((i+j)%2==0)
		return result;
	else
		return result*(-1);
}

int main(){
	int N=0;
	cin>>N;
	int A[N][N];
	for(int i=0;i<N;i++){
		for(int k=0;k<N;k++){
			cin>>A[i][k];
		}
	}
	int sum=0;
	for(int k=0;k<N;k++)
		sum+=A[1][k]*cofactor(1,k);
	cout<<sum<<endl;
	retrurn 0;
}
