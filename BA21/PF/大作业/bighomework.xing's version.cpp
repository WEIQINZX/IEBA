#include<iostream>
#include<fstream>
#include<string>
#include<math.h>
using namespace std;

void doGrep(int argc, char argv[])
{
	bool orderc=false;
	bool orderh=false;
	bool orderH=false;
	bool orderi=false;
	bool ordern=false;
	int orderA=0,orderB=0;
	int shift=0;
	int shift_position[100];
	string filename="";
	string target="";
	string wordall="";
	string num="";
	int count=0;
	for(int i=4;i<argc;i++)
	{
		if(argv[i]==' ')
		{
			shift_position[shift]=i;
			shift++;
		}
		if(argv[i]=='-')
		{
			if(argv[i+1]=='c')
			{
				orderc=true;
			}	
			if(argv[i+1]=='h')
				orderh=true;	
			if(argv[i+1]=='H')
				orderH=true;	
			if(argv[i+1]=='i')
				orderi=true;	
			if(argv[i+1]=='n')
				ordern=true;	
			if(argv[i+1]=='A')
			{
				i+=2;
				while(argv[i]!=' ')
				{
					num=num+argv[i];
					i++;
				}
				i--;
				for(int l=0;l<num.size();l++)
				{
					orderA+=(num[l]-'0')*pow(10,(num.size()-1-l));
				}
				//cout<<"orderA="<<orderA<<endl;
				num="";
			}
			if(argv[i+1]=='B')
			{
				i+=2;
				while(argv[i]!=' ')
				{
					num=num+argv[i];
					i++;
				}
				i--;
				for(int l=0;l<num.size();l++)
				{
					orderB+=(num[l]-'0')*pow(10,(num.size()-1-l));
				}
				//cout<<"orderB="<<orderB<<endl;
				num="";
			}
		}
	}
	for(int i=shift_position[shift-1]+1;i<argc;i++)
		filename=filename+argv[i];
	ifstream fin;
	fin.open(filename.c_str());
	if(!fin.is_open())
	{
		cerr<<"No such file or directory!"<<endl;
		return;
	}
	string newword="";
	int line=0;
	while(!fin.eof())
	{
		getline(fin,newword);
		if(newword!="")
		{
			wordall=wordall+newword;
			wordall=wordall+'!';
			line++; 
		}
	}
	int npos[line+1];
	int lin=1;
	npos[0]=0;
	for(int i=0;i<wordall.size();i++)
	{
		if(wordall[i]=='!')
		{
			npos[lin]=i+1;
			lin++;
		}
	}
	for(int i=shift_position[shift-2]+1;i<shift_position[shift-1];i++)
		target=target+argv[i];
	int i,j,star,last;
	int res[line][2]={0};
	bool right[line];
	bool out[line]={false};
	string word;
	for(int k=0;k<line;k++)
	{
		i=0;
		j=0;
		star=-1;
		last=0;
		right[k]=false;
		word="";
		for(int j=npos[k];j<npos[k+1]-1;j++)
			word=word+wordall[j];
		//cout<<"line="<<k+1<<",word="<<word<<endl;
		while(i<word.size())
		{
			if(orderi)
			{
				int det=word[i]-target[j];
				if(det<0)
					det*=-1;
				if(j<target.size()&&(det==0||det==('a'-'A')||target[j]=='.'))
				{
					if(j==0)
						res[k][1]=i;
					i++;
					j++;
					if(j==target.size())
					{
						right[k]=true;
						res[k][2]=i-1;
						if(star==-1)
							break;
					}
				}
				else if(j<target.size()&&target[j]=='*')
				{
					last=i;
					star=j++;
					if(j==target.size())
					{
						right[k]=true;
						res[k][2]=word.size()-1;
						break;
					}
				}
				else if(j==0)
				{
					last=++i;
				}
				else if(star!=-1)
				{
					i=++last;
					j=star+1;
					if(i==word.size()&&j==word.size())
					{
						right[k]=true;
						res[k][2]=i-1;
					}
				}
				else if(star==-1)
				{
					i=++last;
					j=0;
				}
			}
			else
			{
				if(j<target.size()&&((word[i]==target[j])||target[j]=='.'))
				{
					if(j==0)
						res[k][1]=i;
					i++;
					j++;
					if(j==target.size())
					{
						right[k]=true;
						res[k][2]=i-1;
						if(star==-1)
							break;
					}
				}
				else if(j<target.size()&&target[j]=='*')
				{
					last=i;
					star=j++;
					if(j==target.size())
					{
						right[k]=true;
						res[k][2]=word.size()-1;
						break;
					}
				}
				else if(j==0)
				{
					last=++i;
				}
				else if(star!=-1)
				{
					i=++last;
					j=star+1;
					if(i==word.size()&&j==word.size())
					{
						right[k]=true;
						res[k][2]=i-1;
					}
				}
				else if(star==-1)
				{
					i=++last;
					j=0;
				}
			}
		}
	}
	for(int i=0;i<line;i++)
	{
		if(right[i])
		{
			out[i]=true;
		if(orderA!=0)
			for(int j=i-orderA;j<i;j++)
				if(j>=0)
					out[j]=true;
		if(orderB!=0)
			for(int j=i+1;j<=i+orderB;j++)
				if(j<line)
					out[j]=true;
		}
	}
	for(int i=0;i<line;i++)
	{
		if(right[i])
		{
			if(orderc)
			count++;
			if(orderH)
			cout<<"filename:"<<filename<<endl;
			if(ordern)
			cout<<"\e[92;1m"<<i+1<<"\e[94;1m:"<<"\e[0m";
			for(int j=npos[i];j<npos[i+1]-1;j++)
			{
				if(j<=npos[i]+res[i][2]&&j>=npos[i]+res[i][1])
				{
					cout<<"\e[91;1m"<<wordall[j]<<"\e[0m";
				}
				else
				{
					cout<<wordall[j];
				}
			}
			cout<<endl;
		}
		else if(out[i])
		{
			if(ordern)
			cout<<"\e[92;1m"<<i+1<<"\e[94;1m-"<<"\e[0m";
			for(int j=npos[i];j<npos[i+1]-1;j++)
				cout<<wordall[j];
			cout<<endl;
		}
	}
	if(orderc)
	cout<<"match line:"<<count<<endl;
}
int main()
{
	string c;
	getline(cin,c);
	int length=c.size();
	char order[length];
	for(int i=0;i<length;i++)
	{
		order[i]=c[i];
	}
	if(order[0]=='g'&&order[1]=='r'&&order[2]=='e'&&order[3]=='p')
	{
		//cout<<"success!"<<endl;
		doGrep(length,order);
	}
	return 0;
}
