#include<iostream>
using namespace std;

void Merge(long long a[],long long lo,long long mi,long long hi){
	long long *b=new long long[hi-lo];
	long long index=0;
	long long i=lo;
	long long j=mi;
	while((i<mi) &&(j<hi)){
		if(a[i]<a[j])
			b[index++]=a[i++];
		else
			b[index++]=a[j++];
	}
	while(j<hi)
		b[index++]=a[j++];
	for(long long k=lo;k<hi;k++)
		a[k]=b[k-lo];
	delete b;
	return;
}
void MergeSort(long long a[],long long lo,long long hi){
	if(hi-lo<2)
		return;
	long long mi=(lo+hi)>>1;
	MergeSort(a,lo,mi);
	MergeSort(a,mi,hi);
	Merge(a,lo,mi,hi); 
}


int main()
{
	long long N = 0;
	scanf("%lld",&N);
	long long *num = new long long[N];
	long long detla = 0; 
	for (long long i = 0; i < N; i++)
	{
		scanf("%lld",&num[i]);
	}
	
	MergeSort(num,0,N);
	//for(int i=0;i<N;i++) cout<<num[i]<<" ";cout<<endl;
	long long mi=N/2;
	for(long long i=0;i<mi;i++)
		detla+=num[i+mi]-num[i]; 
	if(N%2!=0)
		detla+=num[N-1];
	printf("%lld\n",detla);
	return 0;
}
