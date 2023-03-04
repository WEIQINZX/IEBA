#include <iostream>
#include <string.h>
using namespace std;

int main(){
	char strA[100];
	char strB[100];
	int strC[100];
	int carry=0,sum=0;
	cin>>strA>>strB;
	int a=strlen(strA);
	int b=strlen(strB);
	int k=b-1;
	int i=0;
	for (int j=a-1;j>=0&&k>=0;j--){
		i=max(j,k);
		int numA=strA[j]-'0';
		int numB=strB[k]-'0';
		sum=numA+numB+carry;
		strC[i]=sum%10;
		if (sum>=10)
			carry=1;
		else
			carry=0;
		k--;
	}
	
	if(a>=b)
		for(int j=i-1;j>=0;j--){
		int numA=strA[j]-'0';
		sum=numA+carry;
		strC[j]=sum%10;
		if(sum>=10)
			carry=1;
		else
			carry=0;
		}
	else
		for(int j=i-1;j>=0;j--){
		int numB=strB[j]-'0';
		sum=numB+carry;
		strC[j]=sum%10;
		if(sum>=10)
			carry=1;
		else
			carry=0;
	}
	for(int j=0;j<=2;j++){
		cout<<strC[j];
	}
	cout<<endl;
	return 0;
}
