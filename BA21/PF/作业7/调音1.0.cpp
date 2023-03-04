#include <iostream>
using namespace std;

bool dp[1000][50];
int maxtune[1000]; //maxtune[i]-第i首歌可以达到的最大音量 
int c[50];

int max_level(int N,int n,int beginlevel,int maxlevel){ //n-现在在调第几次 
	int level_now=0;
	if(n==0)
		return beginlevel;
	level_now=maxtune[n-1]+c[n-1];
	if(level_now<maxlevel)
		maxtune[n]=max_level(N,n-1,beginlevel,maxlevel)+c[n];
	else
		maxtune[n]=max_level(N,n-1,beginlevel,maxlevel)-c[n];
	if(n==N)
		return maxtune[n];
}

int main(){
	int N=0,beginlevel=0,maxlevel=0;
	cin>>N>>beginlevel>>maxlevel;
	for(int i=0;i<N;i++){
		cin>>c[i];
	}
	int max=max_level(N,1,beginlevel,maxlevel); 
	cout<<max<<endl;
	
	return 0;
}
