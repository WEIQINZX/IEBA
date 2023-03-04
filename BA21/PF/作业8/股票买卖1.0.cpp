#include <iostream>
using namespace std;

int main(){
	int N=0;
	cin>>N;
	int price[100000];
	price[0]=1000000;
	price[N+1]=0;
	for(int i=1;i<=N;i++)
		cin>>price[i];
	int profit=0;
	bool have=false;
	for(int i=1;i<=N;i++){
		if(price[i]<=price[i-1] && price[i]<=price[i+1] && !have){
		profit-=price[i];
		have=true;
		//cout<<"-"<<price[i]<<endl;
		}
		if(price[i]>=price[i-1] && price[i]>=price[i+1] && have){
		profit+=price[i];
		have=false;
		//cout<<"+"<<price[i]<<endl;
		}
	}
	cout<<profit<<endl;
	return 0;
}
