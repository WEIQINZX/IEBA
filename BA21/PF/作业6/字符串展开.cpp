#include <iostream>
#include <string>
using namespace std;

int main(){
	int p1=0,p2=0,p3=0;
	string input,output;
	cin>>p1>>p2>>p3;
	cin>>input;
	//char a=input[0]+2;
	//cout<<a<<endl;
	int j=0; //用来记录output录入到哪儿了 
	for (int i=0;i<input.size();i++){
		
		if (i==0) 
			output[j++]=input[i];
		if (input[i]!='-')
			output[j++]=input[i];
		else if(input[i-1]>='a'){
			int length=input[i+1]-input[i-1];
			for(int k=1;k<length;k++){
				for(int l=0;l<p2;l++){
					if(p3==1){
						if(p1==1)
							output[j++]=input[i-1]+k;
						if(p1==2)
							output[j++]=input[i-1]+k-32;
						if(p1==3)
							output[j++]='*';
					}
					else{
						if(p1==1)
							output[j++]=input[i+1]-k;
						if(p1==2)
							output[j++]=input[i+1]-k-32;
						if(p1==3)
							output[j++]='*';
					}
				}
			}
		}
		else{
			int length=input[i+1]-input[i-1];
			for (int k=1;k<length;k++){
				for(int l=0;l<p2;l++){
					if(p3==1 && p1!=3)
						output[j++]=input[i-1]+k;
					if(p3==2 && p1!=3)
						output[j++]=input[i+1]-k;
					if(p1==3)
						output[j++]='*';
				}
			}
		}
	} 
	cout<<"output="<<output<<endl;
	return 0;
}
