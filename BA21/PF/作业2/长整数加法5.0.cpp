#include <iostream>
#include <string.h>
using namespace std;

int main(){
	char strA[100];
	char strB[100];
	int strC[100]; //����ע�⣬C��int���飬�����Ҫ��forһ��һ����� 
	int carry=0,sum=0,numA=0,numB=0;
	cin>>strA>>strB;
	int a=strlen(strA);
	int b=strlen(strB);
	int c=max(a,b); //c��ab�г����Ǹ��ȳ�
	int num_a[100],num_b[100]; //num_a��int��ʽ��A���飬��Ϊֻ��char������strlen
	if (a>b){  //��������a��b������� 
		for (int i=0;i<a;i++){
			num_a[i]=strA[i]-'0';
			if(i<a-b)
				num_b[i]=0;  //���i��a�ﵫ�ǲ���b��Ͳ�0 
			else
				num_b[i]=strB[i-(a-b)]-'0';  //��B�Ӻ���ǰ���Ķ�Ӧλ 
		}
	}
	if (a<b){  //�����е�AB,ab�Ե� 
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
	num_r[c-1]=num_a[c-1]+num_b[c-1];  //ĩλ���
	for (int i=c-2;i>=0;i--){
		num_r[i]=num_a[i]+num_b[i]+(num_r[i+1])/10;  //�����п���num_r[i]>10����û��ϵ 
	} 
	if (num_r[0]>=10)
		cout<<'1';
	for (int i=0;i<c;i++){
		cout<<num_r[i]%10;  //�����ÿһλnum_rȡ�࣬��Ϊ��λ֮��Ľ�� 
	}
	return 0;
}
