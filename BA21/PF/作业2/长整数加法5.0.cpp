#include <iostream>
#include <string.h>
using namespace std;

int main(){
	char strA[100];
	char strB[100];
	int strC[100]; //这里注意，C是int数组，输出是要用for一步一步输出 
	int carry=0,sum=0,numA=0,numB=0;
	cin>>strA>>strB;
	int a=strlen(strA);
	int b=strlen(strB);
	int c=max(a,b); //c和ab中长的那个等长
	int num_a[100],num_b[100]; //num_a是int形式的A数组，因为只有char可以用strlen
	if (a>b){  //这里讨论a比b长的情况 
		for (int i=0;i<a;i++){
			num_a[i]=strA[i]-'0';
			if(i<a-b)
				num_b[i]=0;  //如果i在a里但是不在b里，就补0 
			else
				num_b[i]=strB[i-(a-b)]-'0';  //即B从后往前数的对应位 
		}
	}
	if (a<b){  //把所有的AB,ab对调 
		for (int i=0;i<b;i++){
			num_b[i]=strB[i]-'0';
			if(i<b-a)
				num_a[i]=0; 
			else
				num_a[i]=strA[i-(b-a)]-'0'; 
		}
	}
	if (a==b){
		for(int i=0;i<a;i++){
			num_a[i]=strA[i]-'0';
			num_b[i]=strB[i]-'0';
		} 
	}
	
	int num_r[100];
	num_r[c-1]=num_a[c-1]+num_b[c-1];  //末位相加
	for (int i=c-2;i>=0;i--){
		num_r[i]=num_a[i]+num_b[i]+(num_r[i+1])/10;  //这里有可能num_r[i]>10不过没关系 
	} 
	if (num_r[0]>=10)
		cout<<'1';
	for (int i=0;i<c;i++){
		cout<<num_r[i]%10;  //这里对每一位num_r取余，即为进位之后的结果 
	}
	return 0;
}
