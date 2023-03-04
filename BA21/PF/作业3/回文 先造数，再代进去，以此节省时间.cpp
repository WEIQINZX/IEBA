#include <iostream>
using namespace std;

bool isPrime(int n){
	bool prime=true;
	for (int i=2;i*i<=n;i++){
		if (n%i==0){
			prime=false;
			break;
		}
	}
	return prime;
}

int digit(int n){
	if (n>=0 && n<10)
		return 1;
	if (n>=10 && n<100)
		return 2;
	if (n>=100 && n<1000)
		return 3;
	if (n>=1000 && n<10000)
		return 4;
	if (n>=10000 && n<100000)
		return 5;
	if (n>=100000 && n<1000000)
		return 6;
	if (n>=1000000 && n<10000000)
		return 7;
	if (n>=10000000 && n<100000000)
		return 8;
	if (n==100000000)
		return 9;
}

//十的八次方的筛法往里一塞肯定超时 

int main(){
	int a,b=0;
	cin>>a>>b;
	
	if (a<=5 && b>=5) //两位、一位的回文素数 
		cout<<5<<endl;
	if (a<=7 && b>=7)
		cout<<7<<endl;
	if (a<=11 && b>=11)
		cout<<11<<endl;
	
	if (digit(a)<=3 && digit(b)>=3){ //三位 
		int x,y=0;
		int temp=0;
		for (x=1;x<10;x++){
			for (y=0;y<=9;y++){
				temp=x*100+y*10+x;
				if (a<=temp && b>=temp)
					if (isPrime(temp))
						cout<<temp<<endl;
			}
		}
	}
	
	if (digit(a)<=5 && digit(b)>=5){ //五位 
		int x,y,z=0;
		int temp=0;
		for (x=1;x<=9;x++){
			for(y=0;y<=9;y++){
				for (z=0;z<=9;z++){
					temp=x*10000+y*1000+z*100+y*10+x;
					if (a<=temp && b>=temp){
					if (isPrime(temp))
						cout<<temp<<endl;
					}
				}
			}
		}
	} 
	
	if (digit(a)<=7 &&digit(b)>=7){ //七位 
		int x,y,z,t=0;
		int temp=0;
		for (x=1;x<=9;x++){
			for(y=0;y<=9;y++){
				for (z=0;z<=9;z++){
					for(t=0;t<=9;t++){
					temp=x*1000000+y*100000+z*10000+t*1000+z*100+y*10+x;
					if (a<=temp && b>=temp){
						if (isPrime(temp))
							cout<<temp<<endl;
						}
					}
				}
			}
		}
	}
	
	return 0;
}
