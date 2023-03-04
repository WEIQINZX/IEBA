#include<iostream>
using namespace std;

void merge_sort(long long*p,long long n){
	if (n<=1)
		return;
	long long l=n/2,r=n-n/2;
	merge_sort(p,l); //ǰһ��
	merge_sort(p+l,r); //��һ��
	long long *pn=new long long[n];
	long long i=0,j=l,k=0;
	while(i<l && j<n){
		if(p[i]>p[j])
			pn[k++]=p[j++];
		else
			pn[k++]=p[i++];
	} //�ڡ����������ﶼ������ʱ�򡿣������ְ�˳������������
	for(;i<l;i++) pn[k++]=p[i];
	for(;j<n;j++) pn[k++]=p[j];
	for (long long i=0;i<n;i++) p[i]=pn[i];
	delete []pn;
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
	
	merge_sort(num,N);
	//for(int i=0;i<N;i++) cout<<num[i]<<" ";cout<<endl;
	long long mi=N/2;
	for(long long i=0;i<mi;i++)
		detla+=num[i+mi]-num[i]; 
	if(N%2!=0)
		detla+=num[N-1];
	printf("%lld\n",detla);
	return 0;
}
