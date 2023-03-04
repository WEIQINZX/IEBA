#include <iostream>
using namespace std;
struct dishes{
    int A;
    int B;
    int C;
    int D;
};
	dishes dish[6];

int zuixiao(int a,int b,int c,int d){
	int t=a;
	if(t>b)
		t=b;
	if(t>c)
		t=c;
	if(t>d)
		t=d;
	return t;
}

int main(){ //dish[5] matches each dish separately
    dish[0]={99,99,99,99};
	dish[1]={2,1,0,2};
	dish[2]={1,1,1,1};
	dish[3]={0,0,2,1};
	dish[4]={0,0,3,0};
	dish[5]={1,0,0,1};
	int A=0,B=0,C=0,D=0;
    cin>>A;
    cin>>B;
    cin>>C;
    cin>>D;
    
	int num=0;
	for(int i=1;i<=5;i++){
		if(A>=dish[i].A && B>=dish[i].B && C>=dish[i].C && D>=dish[i].D){
			num=zuixiao(A/dish[i].A,B/dish[i].B,C/dish[i].C,D/dish[i].D);
			A-=num*dish[i].A;
			B-=num*dish[i].B;
			C-=num*dish[i].C;
			D-=num*dish[i].D;
			cout<<A<<" "<<B<<" "<<C<<" "<<D<<endl;
		}
		cout<<num<<endl;
		num=0;
	}
    return 0;
}