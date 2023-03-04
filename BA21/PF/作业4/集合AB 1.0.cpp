#include <iostream>
using namespace std;

void swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}

struct block{
	int num[2000];
	int length;
};

block intersect(block A,block B,int n,int m){
	block C;
	C.length=0;
	int j=0;
	for(int i=0;i<n;i++){
		for(int k=0;k<m;k++){
			if (A.num[i]==B.num[k]){
				C.num[j]=A.num[i];
				C.length++;
				j++;
			}
		}
	}
	return C;
}

block unite(block A,block B,int n,int m){
	block C;
	C.length=n+m;
	for (int i=0;i<n;i++)
		C.num[i]=A.num[i];
	int k=0;
	for (int i=n;i<n+m;i++){
		C.num[i]=B.num[k];
		k++;
	}
	
	for(int i=0;i<n+m-1;i++){
		for(int k=0;k<n+m-1;k++){
			if(C.num[k]>C.num[k+1])
				swap(C.num[k],C.num[k+1]);
		}
	}
	
	block D;
	D.length=-1;
	for (int i=0;i<n+m;i++){
		if(i==0){
			D.length++;
			D.num[D.length]=C.num[i];
		}
		else if (C.num[i]!=C.num[i-1]){
			D.length++;
			D.num[D.length]=C.num[i];
		}
	}
	return D;
}

block comple(block A,block B,int n,int m){
	block C;
	C.length=0;
	for (int i=0;i<n;i++){
		for (int k=0;k<m;k++){
			if (A.num[i]==B.num[k])
				break;
			if (k==m-1 && A.num[i]!=B.num[k]){
				C.num[C.length]=A.num[i];
				C.length++;
			}
		}
	}
	return C;
}

int main(){
	int n=0,m=0;
	block A;
	block B;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>A.num[i];
	cin>>m;
	for(int i=0;i<m;i++)
		cin>>B.num[i];
	A.length=n;
	B.length=m;
	
	block intersection;
	intersection=intersect(A,B,n,m);
	block uni;
	uni=unite(A,B,n,m);
	block complement;
	complement=comple(A,B,n,m);
	
	
	
	for (int i=0;i<intersection.length;i++)
		cout<<intersection.num[i]<<" ";
	cout<<endl; //能跑能跑！！明天继续  这一块是输出函数 
	
	for (int i=0;i<=uni.length;i++)
		cout<<uni.num[i]<<" ";
	cout<<endl;
	
	for (int i=0;i<complement.length;i++)
		cout<<complement.num[i]<<" ";
	cout<<endl;
	return 0;
}
