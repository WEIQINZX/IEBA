#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct block{
	bool c;
	bool h;
	bool H;
	bool i;
	bool n;
	bool A;
	int A_num;
	bool B;
	int B_num; 
};

int main(){
	int i=0,j=0,start=0,star=-1,end=0,last=0;
	string word,target;
	cin>>word;
	cin>>target;
	bool right=false;
	
	while(i<word.size())  {
		if(j<target.size()&&((word[i]==target[j])||target[j]=='.')) {
			if(j==0)  
				start=i;
			i++;
			j++;  
			if(j==target.size()) {
				right=true;
				end=i-1;  
				if (star==-1)
					break; 
			}
		}
		else if(j<target.size()&&target[j]=='*') {
			last=i; 
			star=j++;  
			if(j==target.size())  {
				right=true;  
				end=word.size()-1; 
				break;
			}
		} 
		else if(j==0)   {
			last=++i;  
		}
		else if(star!=-1)  {
			i=++last;   
			j=star+1;  
		}
		else if(star==-1) {
			i=++last; 
			j=0; 
		}
	}
	
	while(j<target.size()&&target[j]=='*')
		j++;
		
	if(right) {
		for (i=0;i<start;i++){
			cout<<word[i];
		}
		cout<<"\e[91;1m";
		for(int i=start;i<=end;i++)
			cout<<word[i];
		cout<<"\e[0m";
		for(int i=end+1;i<word.size();i++)
			cout<<word[i];
		cout<<endl;
	}
	else{
		for(int i=0;i<word.size();i++)
			cout<<word[i];
		cout<<endl;
	}
	return 0;
}
