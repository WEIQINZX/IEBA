#include<iostream>
using namespace std;

int main()
{
	int i=0,j=0,start=0,star=-1,end=0,last=0; 
	//start为“从哪一项开始有符合的项”，end为“最后一个符合条件的项在哪里” ，last为“对上target的第一个word字符” 
	string word,target;
	cin>>word;
	cin>>target;
	bool right=false;  
	//right为“是否包含对应项 
	while(i<word.size()) //word还没查到底，分五种不同的case讨论 
	{
		if(j<target.size()&&((word[i]==target[j])||target[j]=='.'))  //case1：对应得上 
		{
			if(j==0)  //case1.1：这是target的第一个字符 → 注意：这种case是一定会进入一次的 
				start=i;
			i++;
			j++;  //word和target都移向下一个 
			if(j==target.size()) //case1.2：target已经结束了 →注意：这种case是一定会进入一次的 
			{
				right=true;
				end=i-1; //最后一个符合target的word字符仍是i-1 
				if (star==-1)
					break; 
			}
		}
		else if(j<target.size()&&target[j]=='*') //case2 ：对不上，但是target目前检索位是* 
		{
			last=i; //记录目前查到的位置是i 
			star=j++; //star的位置是j，j++ 
			if(j==target.size()) //j++后就结束了 
			{
				right=true; //这是可以认为有匹配项 
				end=word.size()-1; //最后一个符合的word项就是最后一项 
				break;
			}
		} 
		else if(j==0)  //case3 ：对不上，但是这是target的第一项 
		{
			last=++i; //搜查的word位置移到下一个 
		}
		else if(star!=-1) //case4 ：对不上，但是之前出现过* 
		{
			i=++last;  //last++，i=last i和last都往后移一个 
			j=star+1; //目标搜查字符是最新的*的下一个 
		}
		else if(star==-1) //case5 ：对不上，但是从来没有出现过* 
		{
			i=++last; //word的搜查对象移到下一个 
			j=0; //已搜到的部分用不了，前面都忘记，又从target的第一项开始搜 
		}
	}
	
	while(j<target.size()&&target[j]=='*')
		j++;
		
	if(right) //如果有对应项 
	{
		for(int i=start;i<=end;i++)
			cout<<word[i];
	}
	else
		cout<<"Not Found!";
	return 0;
}
