#include <iostream>
#include<fstream>
#include<math.h>
#include <string.h>
#include <string>
using namespace std;
struct Terminal {
	char user[1024];
	char mach[1024];
	char root[1024];
	char wdir[1024];
	char strin[1024];
	char strout[16384];
};
Terminal gTerm;
void doGrep(int argc, char* argv[])
{
	bool orderc = false;
	bool orderh = false;
	bool orderH = false;
	bool orderi = false;
	bool ordern = false;
	int orderA = 0, orderB = 0;
	int shift = 0;
	int shift_position[100];
	string filename="";
	string target = "";
	string wordall = "";
	string num = "";
	string help = "语法：grep {-h}{-H}{-I}{-n}{-c}{-A[行数]}{-B[行数]}[模式串][文件]*\n[模式串]可以是普通字符串，也可以包含通配符（.或*）。“.”可匹配一个任意字符；“*”可匹配任意数量（包括 0）任意字符。\n";
	help += "-c：计算符合样式的行数。\n-h：在显示符合样式的那一行之前，不标示该行所属的文件名称。\n-H：在显示符合样式的那一行之前，标示该行所属的文件名称。\n";
	help += "-i：忽略字符大小写的差别。\n-n：在显示符合样式的那一行之前，标示出该行的编号。\n-A[行数]：除了显示符合范本样式的那一列之外，同时显示该行之后的[行数]行内容。\n";
	help += "-B[行数]：除了显示符合样式的那一行之外，同时显示该行之前的[行数]内容。\n";
	int count = 0;
	bool errc = false;
	for (int i = 0; i < argc; i++) 
	{
		//cout << i << endl;
		if (argv[i][0] == '-' && strlen(argv[i])==6)
			if (argv[i][1] == '-' && argv[i][2] == 'h' && argv[i][3] == 'e' && argv[i][4] == 'l' && argv[i][5] == 'p')
			{
				strcpy(gTerm.strout, help.c_str());
				return;
			}
			if (i == argc - 1)
			{
				for (int k = 0; k < strlen(argv[i]); k++)
					filename += argv[i][k];
				//cout << filename << endl;
				break;
			}
		if (argv[i][0] == '-') 
		{
			if (argv[i][1] == 'n')
				ordern = true;
			else if (argv[i][1] == 'c')
				orderc = true;
			else if (argv[i][1] == 'h')
				orderh = true;
			else if (argv[i][1] == 'H')
				orderH = true;
			else if (argv[i][1] == 'i')
				orderi = true;
			else if (argv[i][1] == 'A')
			{
				int length = strlen(argv[i]); //代表数字位数 
				for (int k = 2; k < length; k++)
					orderA += (argv[i][k] - '0') * pow(10, length - k - 1);
			}
			else if (argv[i][1] == 'B') 
			{
				int length = strlen(argv[i]); //代表数字位数 
				for (int k = 2; k < length; k++)
					orderB += (argv[i][k] - '0') * pow(10, length - k - 1);
			}
			else 
			{
				if (i != argc - 1 && i != argc - 2)
				{
					errc = true;
				}
			}
		}
		else {
			if (i == argc - 2) {
				for (int k = 0; k < strlen(argv[i]); k++)
					target += argv[i][k];
			}
		}
	}//写到这儿了 15:28 
	if (filename == "-")
	{
		filename = "";
		for (int i = 0; i < strlen(gTerm.strin); i++)
		{
			filename += gTerm.strin[i];
		}
	}
	string filename="";
	for (int i = 0; i < strlen(gTerm.root); i++)
	{
		fileread += gTerm.root[i];
	}
	fileread += '/';
	for (int i = 0; i < strlen(gTerm.wdir); i++)
	{
		fileread += gTerm.wdir[i];
	}
	fileread += '/'+filename;
	ifstream fin;
	//cout << "fileread=" << fileread<<endl;
	fin.open(fileread.c_str());
	if (!fin.is_open())
	{
		cerr <<"grep: "<<filename << " No such file or directory!" << endl;
		return;
	}
	string newword = "";
	int line = 0;
	while (!fin.eof())
	{
		getline(fin, newword);
		if (newword != "")
		{
			wordall = wordall + newword;
			wordall = wordall + '!';
			line++;
		}
	}
	int *npos=new int[line + 1];
	int lin = 1;
	npos[0] = 0;
	for (int i = 0; i < wordall.size(); i++)
	{
		if (wordall[i] == '!')
		{
			npos[lin] = i + 1;
			lin++;
		}
	}
	for (int i = shift_position[shift - 2] + 1; i < shift_position[shift - 1]; i++)
		target = target + argv[i];
	int i, j, star, last;
	int **res=new int*[line];
	for (int i = 0; i < line; i++)
	{
		res[i] = new int[2];
		for (int j = 0; j < 2; j++)
			res[i][j] = 0;
	}
	bool *right=new bool[line];
	bool* out = new bool[line];
	for (int i = 0; i < line; i++)
		out[i] = false;
	string word;
	for (int k = 0; k < line; k++)
	{
		i = 0;
		j = 0;
		star = -1;
		last = 0;
		right[k] = false;
		word = "";
		for (int j = npos[k]; j < npos[k + 1] - 1; j++)
			word = word + wordall[j];
		//cout<<"line="<<k+1<<",word="<<word<<endl;
		while (i < word.size())
		{
			if (orderi)
			{
				int det = word[i] - target[j];
				if (det < 0)
					det *= -1;
				if (j < target.size() && (det == 0 || det == ('a' - 'A') || target[j] == '.'))
				{
					if (j == 0)
						res[k][1] = i;
					i++;
					j++;
					if (j == target.size())
					{
						right[k] = true;
						res[k][2] = i - 1;
						if (star == -1)
							break;
					}
				}
				else if (j < target.size() && target[j] == '*')
				{
					last = i;
					star = j++;
					if (j == target.size())
					{
						right[k] = true;
						res[k][2] = word.size() - 1;
						break;
					}
				}
				else if (j == 0)
				{
					last = ++i;
				}
				else if (star != -1)
				{
					i = ++last;
					j = star + 1;
					if (i == word.size() && j == word.size())
					{
						right[k] = true;
						res[k][2] = i - 1;
					}
				}
				else if (star == -1)
				{
					i = ++last;
					j = 0;
				}
			}
			else
			{
				if (j < target.size() && ((word[i] == target[j]) || target[j] == '.'))
				{
					if (j == 0)
						res[k][1] = i;
					i++;
					j++;
					if (j == target.size())
					{
						right[k] = true;
						res[k][2] = i - 1;
						if (star == -1)
							break;
					}
				}
				else if (j < target.size() && target[j] == '*')
				{
					last = i;
					star = j++;
					if (j == target.size())
					{
						right[k] = true;
						res[k][2] = word.size() - 1;
						break;
					}
				}
				else if (j == 0)
				{
					last = ++i;
				}
				else if (star != -1)
				{
					i = ++last;
					j = star + 1;
					if (i == word.size() && j == word.size())
					{
						right[k] = true;
						res[k][2] = i - 1;
					}
				}
				else if (star == -1)
				{
					i = ++last;
					j = 0;
				}
			}
		}
	}
	for (int i = 0; i < line; i++)
	{
		if (right[i])
		{
			out[i] = true;
			if (orderA != 0)
				for (int j = i - orderA; j < i; j++)
					if (j >= 0)
						out[j] = true;
			if (orderB != 0)
				for (int j = i + 1; j <= i + orderB; j++)
					if (j < line)
						out[j] = true;
		}
	}

	string stringout = "";
	for (int i = 0; i < line; i++)
	{
		if (right[i])
		{
			if (orderc)
				count++;
			if (orderH)
				stringout = stringout + "filename:" + filename + "\n";
			if (ordern)
				stringout += "\033[92;1m";
			int temp[100] = { 0 }, temper = 0, temi = i + 1;
			while (temi >= 1)
			{
				temp[temper] = temi % 10;
				temi /= 10;
				temper++;
			}
			for (int t = temper - 1; t >= 0; t--)
				stringout += temp[t] + '0';
			stringout = stringout + "\033[94;1m:" + "\033[0m";

			for (int j = npos[i]; j < npos[i + 1] - 1; j++)
			{
				if (j <= npos[i] + res[i][2] && j >= npos[i] + res[i][1])
				{
					stringout = stringout + "\033[91;1m" + wordall[j] + "\033[0m";
				}
				else
				{
					stringout += wordall[j];
				}
			}
			stringout += "\n";
		}
		else if (out[i])
		{
			if (ordern)
				stringout += "\033[92;1m";
			int temp[100] = { 0 }, temper = 0, temi = i + 1;
			while (temi >= 1)
			{
				temp[temper] = temi % 10;
				temi /= 10;
				temper++;
			}
			for (int t = temper - 1; t >= 0; t--)
				stringout += temp[t] + '0';
			stringout = stringout + "\033[94;1m-" + "\033[0m";
			for (int j = npos[i]; j < npos[i + 1] - 1; j++)
				stringout += wordall[j];
			stringout += "\n";
		}
	}
	if (orderc)
		stringout += "match line:";
	int temp[100] = { 0 }, temper = 0, temi = count;
	while (temi >= 1)
	{
		temp[temper] = temi % 10;
		temi /= 10;
		temper++;
	}
	for (int t = temper - 1; t >= 0; t--)
		stringout += temp[t] + '0';
	stringout += "\n";
	//cout<<"stringout="<<stringout<<endl;
	delete[] res;
	delete[] out;
	delete[] right;
	strcpy(gTerm.strout, stringout.c_str());
}

int main()
{
	int argc=1;
	string root ="D:\Users\WEIQIN";
	strcpy(gTerm.root, root.c_str());
	string wdir = "\Desktop\BA2-1\.";
	strcpy(gTerm.wdir, wdir.c_str());
	string strin = "a.txt";
	strcpy(gTerm.strin, strin.c_str());
	string c;
	getline(cin, c);
	string temp="";
	for (int i = 0; i < c.size(); i++)
		if (c[i] == ' ')
			argc++;
	//cout << argc << endl;
	char** argv = new char* [argc-1];
	int k=0;
	for (int j = 0; j < c.size(); j++)
	{
		if (c[j] != ' ')
			temp += c[j];
		else
		{
			argv[k] = new char[temp.size()];
			strcpy(argv[k], temp.c_str());
			//cout << c.size() << "  " << strlen(argv[k]) << endl;
			temp = "";
			k++;
		}
	}
	argv[k] = new char[temp.size()];
	strcpy(argv[k], temp.c_str());
	//cout << c.size() << "  " << strlen(argv[k]) << endl;
	doGrep(argc, argv);
	cout << gTerm.strout << endl;
	//delete[] argv;
	return 0;
}
