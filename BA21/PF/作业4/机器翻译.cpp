#include <iostream>
using namespace std;

int main(){
	int M=0,N=0;
	int cnt=0; 
	cin>>M>>N;
	int memory[M];
	int word[N];
	for (int i=0;i<M;i++)
		memory[i]=-1;

	for (int i=0;i<N;i++){
		cin>>word[i];
	} //输入我的文章 
	
	for(int i=0;i<N;i++){ //把我的文章从头遍历到尾 
		for(int k=0;k<M;k++){ //把我的内存从头遍历到尾 
			if (word[i]==memory[k]) //查到了 
				break;
			if (word[i]!=memory[k] && (k==M-1)) {//查到最后一个都没查到
				 for(int j=0;j<M-1;j++){
				 	memory[j]=memory[j+1];
				 }
				 memory[M-1]=word[i];
				 cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
