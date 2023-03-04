#include <iostream>
using namespace std;
long long stone[10000000];

void merge_sort(long long*p,long long n){
	if (n<=1)
		return;
	long long l=n/2,r=n-n/2;
	merge_sort(p,l); //前一半
	merge_sort(p+l,r); //后一半
	long long *pn=new long long[n];
	long long i=0,j=l,k=0;
	while(i<l && j<n){
		if(p[i]>p[j])
			pn[k++]=p[j++];
		else
			pn[k++]=p[i++];
	} //在【两侧数组里都有数的时候】，把数字按顺序挑进新数组
	for(;i<l;i++) pn[k++]=p[i];
	for(;j<n;j++) pn[k++]=p[j];
	for (long long i=0;i<n;i++) p[i]=pn[i];
	delete []pn;
}

int main(){
	long long N=0;
	scanf("%d",&N);
	long long stone[N];
	for(long long i=0;i<N;i++)
		scanf("%d",&stone[i]);
	merge_sort(stone,N);
	//for(long long i=0;i<N;i++) cout<<stone[i]<<" ";cout<<endl;
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
