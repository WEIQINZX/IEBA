#include <iostream>
using namespace std;

void merge_sort(int*p,int n){
	if (n<=1)
		return;
	int l=n/2,r=n-n/2;
	merge_sort(p,l); //ǰһ��
	merge_sort(p+l,r); //��һ��
	int *pn=new int[n];
	int i=0,j=l,k=0;
	while(i<l && j<n){
		if(p[i]>p[j])
			pn[k++]=p[j++];
		else
			pn[k++]=p[i++];
	} //�ڡ����������ﶼ������ʱ�򡿣������ְ�˳������������
	for(;i<l;i++) pn[k++]=p[i];
	for(;j<n;j++) pn[k++]=p[j];
	for (int i=0;i<n;i++) p[i]=pn[i];
	delete []pn;
}

int main(){
	int a[9]={1,2,2,2,1,1,1,1,1};
	merge_sort(a,9);
	for(int k=0;k<9;k++)
		cout<<a[k]<<" ";
	cout<<endl;
	return 0;
}
