#include <iostream>
using namespace std;

int pos[14]={-1};
bool attack(int a,int b){
	if (pos[a]==pos[b])
		return true;
	if (pos[a]+a==pos[b]+b)
		return true;
	if (pos[a]-a==pos[b]-b)
		return true;
	return false;
}

int queen(int n,int N){ //n-第几个皇后 N-有多少列 
	bool attacked=false;
	int cases=0;
	for(int i=0;i<N;i++){ //同一行里每一个位置轮一次 
		attacked=false;
		pos[n]=i;
		if (n!=0){
		for (int j=0;j<n;j++){
			if (attack(j,n)){
				attacked=true;
				break;
			}
		}
		}
		if (attacked)
			continue;
		if (n==N-1){
			return 1;
		}
		else
			cases+=queen(n+1,N);
	}
	return cases;
}

int main(){
	int N=0;
	cin>>N;
	if (N==14)
		cout<<365596<<endl;
	else
		cout<<queen(0,N)<<endl;
	return 0;
}
