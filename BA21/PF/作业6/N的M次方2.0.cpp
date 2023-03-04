#include <iostream>
#include <cmath>
using namespace std;

int first(int n,int m){
	if (m==1){
		while(n>=1000)
			n/=10;
		return n;
	} 
	if (m==0) return 1;
	int first=0;
	double x=m*log10(n);
	double b=x-(int)x;
	if (x>=2) 
		first=pow(10,b+2);
	if(x<2 &&x>=1)
		first=pow(10,b+1);
	if(x<1)
		first=pow(10,b);
	return first;
}

int last(int n,int m){ //n^m
	if(n>=1000)
		n%=1000;
	if(m==0) return 1;
	if(m==1) return n%1000;
    int temp=last(n,m/2);
    return ((m%2==0 ? 1 : n)*temp*temp)%1000;
}

int main(){
	int N=0;
	cin>>N;
	int n[N],k[N];
	int f=0,l=0;
	for(int i=0;i<N;i++){ 
		cin>>n[i]>>k[i];
	}
	
	for(int i=0;i<N;i++){
		f=first(n[i],k[i]);
		l=last(n[i],k[i]);
		
		int fi[3];
		if(f>=100){
			fi[0]=f/100;
			fi[1]=(f%100)/10;
			fi[2]=f%10;
		}
		else if(f>=10){
			fi[0]=0;
			fi[1]=f/10;
			fi[2]=f%10;
		}
		else{
			fi[0]=0;
			fi[1]=0;
			fi[2]=f;
		}
		
		int la[3];
		if(l>=100){
			la[0]=l/100;
			la[1]=(l%100)/10;
			la[2]=l%10;
		}
		else if(l>=10){
			la[0]=0;
			la[1]=l/10;
			la[2]=l%10;
		}
		else{
			la[0]=0;
			la[1]=0;
			la[2]=l;
		}
		
		cout<<fi[0]<<fi[1]<<fi[2]<<" "<<la[0]<<la[1]<<la[2]<<endl;
	}
	
	return 0;
}
