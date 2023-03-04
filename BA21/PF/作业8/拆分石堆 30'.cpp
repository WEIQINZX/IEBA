#include<iostream>
using namespace std;

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

int main()
{
	long long N = 0;
	cin>>N;
	long long *num = new long long[N];
	long long detla = 0;
	for (long long i = 0; i < N; i++)
	{
		cin>>num[i];
		detla += num[i];
	}
	
	merge_sort(num,N);
	//for(int i=0;i<N;i++) cout<<num[i]<<" ";cout<<endl;
	long long mi=N/2;
	for(long long i=0;i<mi;i++)
		detla-=(num[i]*2);
	
	cout << detla << endl;
	delete[] num;
	return 0;
}
