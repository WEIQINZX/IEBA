#include<iostream>
using namespace std;

int main()
{
	int i=0,j=0,start=0,star=-1,end=0,last=0; 
	//startΪ������һ�ʼ�з��ϵ����endΪ�����һ������������������� ��lastΪ������target�ĵ�һ��word�ַ��� 
	string word,target;
	cin>>word;
	cin>>target;
	bool right=false;  
	//rightΪ���Ƿ������Ӧ�� 
	while(i<word.size()) //word��û�鵽�ף������ֲ�ͬ��case���� 
	{
		if(j<target.size()&&((word[i]==target[j])||target[j]=='.'))  //case1����Ӧ���� 
		{
			if(j==0)  //case1.1������target�ĵ�һ���ַ� �� ע�⣺����case��һ�������һ�ε� 
				start=i;
			i++;
			j++;  //word��target��������һ�� 
			if(j==target.size()) //case1.2��target�Ѿ������� ��ע�⣺����case��һ�������һ�ε� 
			{
				right=true;
				end=i-1; //���һ������target��word�ַ�����i-1 
				if (star==-1)
					break; 
			}
		}
		else if(j<target.size()&&target[j]=='*') //case2 ���Բ��ϣ�����targetĿǰ����λ��* 
		{
			last=i; //��¼Ŀǰ�鵽��λ����i 
			star=j++; //star��λ����j��j++ 
			if(j==target.size()) //j++��ͽ����� 
			{
				right=true; //���ǿ�����Ϊ��ƥ���� 
				end=word.size()-1; //���һ�����ϵ�word��������һ�� 
				break;
			}
		} 
		else if(j==0)  //case3 ���Բ��ϣ���������target�ĵ�һ�� 
		{
			last=++i; //�Ѳ��wordλ���Ƶ���һ�� 
		}
		else if(star!=-1) //case4 ���Բ��ϣ�����֮ǰ���ֹ�* 
		{
			i=++last;  //last++��i=last i��last��������һ�� 
			j=star+1; //Ŀ���Ѳ��ַ������µ�*����һ�� 
		}
		else if(star==-1) //case5 ���Բ��ϣ����Ǵ���û�г��ֹ�* 
		{
			i=++last; //word���Ѳ�����Ƶ���һ�� 
			j=0; //���ѵ��Ĳ����ò��ˣ�ǰ�涼���ǣ��ִ�target�ĵ�һ�ʼ�� 
		}
	}
	
	while(j<target.size()&&target[j]=='*')
		j++;
		
	if(right) //����ж�Ӧ�� 
	{
		for(int i=start;i<=end;i++)
			cout<<word[i];
	}
	else
		cout<<"Not Found!";
	return 0;
}
