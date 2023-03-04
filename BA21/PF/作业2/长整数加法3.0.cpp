#include <iostream>
#include <string.h>
using namespace std;

int main(){
	char stra[100];
	char strb[100];
	char longer1[100];
	char shorter[100];
	char longer2[100];
	int result[100];
	cin>>stra>>strb;
	int a=strlen(stra);
	int b=strlen(strb);
	if (a>=b){
		for(int i=0;i<a;i++){
			longer1[i]=stra[i];
		}
		for(int i=0;i<b;i++){
			shorter[i]=strb[i];
		}
	}
	else{
		for(int i=0;i<b;i++){
			longer1[i]=strb[i];
		}
		for(int i=0;i<a;i++){
			shorter[i]=stra[i];
		}
	}
	int leng_longer=max(a,b);
	int leng_shorter=min(a,b);
	for (int i=leng_longer-leng_shorter;i<leng_longer;i++){
		int j=0;
		longer2[i]=shorter[j];
		j++;
	}
	for (int i=0;i<leng_longer-leng_shorter;i++){
		longer2[i]=0;
	}
	
	int carry=0,sum=0,num1=0,num2=0;
	for (int i=leng_longer-1;i>=0;i--){
		num1=longer1[i]-'0';
		num2=longer2[i]-'0';
		sum=num1+num2+carry;
		result[i]=sum%10;
		if (sum>=10)
			carry=1;
		else
			carry=0;
	}
	if (carry==1)
		cout<<carry;
	for (int i=0;i<leng_longer;i++){
		cout<<result[i];
	}
	cout<<endl;
	return 0;
} 
