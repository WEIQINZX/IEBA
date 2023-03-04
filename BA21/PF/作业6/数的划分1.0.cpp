#include <iostream>
using namespace std;

bool devide(int n,int k,int times,int part[ ],int remain,int *cases){
	int part_now=0;
	cout<<"hey!"<<endl;
	for (int i=1;i<=remain;i++){
		part_now=i;
		for(int j=0;j<=times;j++){
			if(part[j]==part_now)
				return false;
			else{
				part[times++]=part_now;
				if(k-1==0){
					cases++;
					return true;
				}
				else{
					bool a=devide(n,k-1,times,part,remain-part_now,cases);
					return a;
				}
			}
		}
	}
	cout<<"ha!"<<endl;
}

int main(){
	int n=0,k=0;
	cin>>n>>k;
	int times=0,remain=n,cases=0;
	int part[6]={0};
	bool right=devide(n,k,times,part,remain,&cases);
	cout<<cases<<endl;
	return 0;
}
