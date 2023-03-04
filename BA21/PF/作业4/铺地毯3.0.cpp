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
	} //找到横纵最大坐标 
	
	int max=-1;
	for (int j=0;j<n;j++){ //第j张毯子 
		if (X>=blk[j].axis_x && Y>=blk[j].axis_y && X<=(blk[j].axis_x+blk[j].length_x) && Y<=(blk[j].axis_y+blk[j].length_y))
			max=j+1;
	} 
	
	cout<<max<<endl;
	return 0;
}
