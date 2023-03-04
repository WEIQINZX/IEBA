#include <iostream>
using namespace std;

struct blanket{
	int axis_x;
	int axis_y;
	int length_x;
	int length_y;
};

int main(){
	int n=0,X=0,Y=0;
	cin>>n;
	blanket blk[n];
	for (int i=0;i<n;i++){
		cin>>blk[i].axis_x>>blk[i].axis_y>>blk[i].length_x>>blk[i].length_y;
	}
	cin>>X>>Y;
	
	int max_x=0,max_y=0;
	for (int i=0;i<n;i++){
		if (blk[i].axis_x+blk[i].length_x > max_x)
			max_x=blk[i].axis_x+blk[i].length_x;
		if (blk[i].axis_y+blk[i].length_y > max_y)
			max_y=blk[i].axis_y+blk[i].length_y;
	} //�ҵ������������ 
	int floor[max_x][max_y]; //����һ����ά���� 
	
	for(int i=0;i<max_x;i++){
		for (int k=0;k<max_y;k++){
			floor[i][k]=-1;
		}
	} //�Եذ�ĳ�ʼ�� 
	
	for (int j=0;j<n;j++){
		for (int i=blk[j].axis_x;i<=(blk[j].axis_x+blk[j].length_x);i++){
			for (int k=blk[j].axis_y;k<=(blk[j].axis_y+blk[j].length_y);k++){
				floor[i][k]=j+1;
			} //�������� 
		} //�Ժ����� 
	} //��n�ŵ�̺ѭ�� 
	
	if (X>max_x || Y>max_y)
		cout<<-1<<endl;
	else
		cout<<floor[X][Y]<<endl;
	
	return 0;
}
