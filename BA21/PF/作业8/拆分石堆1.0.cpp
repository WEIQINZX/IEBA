#include <iostream>
using namespace std;
long long stone[10000000];

int main(){
	long long N=0;
	scanf("%d",&N);
	long long stone[N];
	for(long long i=0;i<N;i++)
		scanf("%d",&stone[i]);
	for(long long k=0;k<N-1;k++){
		for(long long i=0;i<N-1;i++){
			if(stone[i]>stone[i+1]){
				long long t=stone[i];
				stone[i]=stone[i+1];
				stone[i+1]=t;
			}
		}
	}
	long long N1=N/2;
	long long m1=0,m2=0;
	for(long long i=0;i<N1;i++)
		m1+=stone[i];
	for(long long i=N1;i<N;i++)
		m2+=stone[i];
	long long delta=m1-m2;
	if(delta>0)
		cout<<delta<<endl;
	else
		cout<<-delta<<endl;
	return 0;
}
