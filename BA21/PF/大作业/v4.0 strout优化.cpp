#include<iostream>
#include<fstream>
#include<string>
#include<math.h>
#include <string.h>
using namespace std;
struct Terminal{
	char user[1024];
	char mach[1024];
	char root[1024];
	char wdir[1024];
	char strin[1024];
	char strout[16384];
};
Terminal gTerm;
void doGrep(int argc, char *argv[])
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
	string stringout="";
	for(int i=0;i<argc;i++){
		if (argv[i][0]=='-'){
			if(argv[i][1]=='-')
				cout<<"help";//help具体内容晚点再说 
			if(argv[i][1]=='n')
				ordern=true;
			if(argv[i][1]=='c')
				orderc=true;
			if(argv[i][1]=='h')
				orderh=true;
			if(argv[i][1]=='H')
				orderH=true;
			if(argv[i][1]=='i')
				orderi=true;
			if(argv[i][1]=='A'){ 
				int length=strlen(argv[i]); //代表数字位数 
				for(int k=2;k<length;k++) 
				orderA+=(argv[i][k]-'0')*pow(10,length-k-1); 
			} 
			if(argv[i][1]=='B'){ 
				int length=strlen(argv[i]); //代表数字位数 
				for(int k=2;k<length;k++) 
				orderB+=(argv[i][k]-'0')*pow(10,length-k-1); 
			} 
		}
		else{
			if(i==argc-2){
				for(int k=0;k<strlen(argv[i]);k++)
					target+=argv[i][k];
			} 
			if(i==argc-1){
				for(int k=0;k<strlen(argv[i]);k++)
					filename+=argv[i][k];
			}
		}
	} //写到这儿了 15:28 
		
		
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
			if(orderH){
				stringout.append("filename");
				stringout+=filename;
				stringout.append("\n");
			}
			if(ordern){
				stringout.append("\e[92;1m");
				//stringout+=i+1+'0';
				stringout.append("\e[94;1m:");
				stringout.append("\e[0m");
			}
			for(int j=npos[i];j<npos[i+1]-1;j++)
			{
				if(j<=npos[i]+res[i][2]&&j>=npos[i]+res[i][1])
				{
					stringout.append("\e[91;1m");
					//stringout.append(wordall[j]);
					stringout.append("\e[0m");
				}
				else
				{
					//stringout.append(wordall[j]);
				}
			}
			cout<<endl;
		}
		else if(out[i])
		{
			if(ordern){
				stringout.append("\e[92;1m");
				int temp[100],temper=0,temi=i+1;
				while(temi>=10)
				{
					temp[temper]=temi%10;
					temi/=10;
					temper++;
				} 
				for(int t=temper-1;t>=0;t--)
					stringout+=temp[t]+'0';
				stringout.append("\e[94;1m-\e[0m")
		;	}
			for(int j=npos[i];j<npos[i+1]-1;j++)
				//stringout.append(wordall[j]);
			stringout.append("\n");
		}
	}
	if(orderc)
	stringout+="match line:";
	//stringout.append(count);
	stringout.append("\n");
	//strcpy(gTerm.strout,stringout.c_str());
	cout<<stringout<<endl;
}
int main()
{
	int argc;
	char *argv[ ]={"grep","-n","-i","-c","-H","-A2","-B2","w*q","a.txt"}; 
	cin>>argc;
	doGrep(argc,argv);
	//cout<<gTerm.strout<<endl;
	return 0;
}
