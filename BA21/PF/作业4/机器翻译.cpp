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
	} //�����ҵ����� 
	
	for(int i=0;i<N;i++){ //���ҵ����´�ͷ������β 
		for(int k=0;k<M;k++){ //���ҵ��ڴ��ͷ������β 
			if (word[i]==memory[k]) //�鵽�� 
				break;
			if (word[i]!=memory[k] && (k==M-1)) {//�鵽���һ����û�鵽
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
