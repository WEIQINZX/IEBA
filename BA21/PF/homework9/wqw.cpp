#include <iostream>
using namespace std;
struct dishes {
	int A;
	int B;
	int C;
	int D;
};
dishes dish[6];

int zuixiao(int a, int b, int c, int d) {
	int t = a;
	if (t > b)
		t = b;
	if (t > c)
		t = c;
	if (t > d)
		t = d;
	return t;
}

int main() { //dish[5] matches each dish separately
	dish[0] = { 99,99,99,99 };
	dish[1] = { 2,1,0,2 };
	dish[2] = { 1,1,1,1 };
	dish[3] = { 0,0,2,1 };
	dish[4] = { 0,0,3,0 };
	dish[5] = { 1,0,0,1 };
	int A = 0, B = 0, C = 0, D = 0;
	cin >> A;
	cin >> B;
	cin >> C;
	cin >> D;
	bool di[4] = { false };
	int num = 0;
	for (int i = 1; i <= 5; i++)
	{
		if (A >= dish[i].A && B >= dish[i].B && C >= dish[i].C && D >= dish[i].D)
		{
			if (dish[i].A == 0)
			{
				di[0] = true;
				dish[i].A = 1;
			}
			if (dish[i].B == 0)
			{
				di[1] = true;
				dish[i].B = 1;
			}
			if (dish[i].C == 0)
			{
				di[2] = true;
				dish[i].C = 1;
			}
			if (dish[i].D == 0)
			{
				di[3] = true;
				dish[i].B = 1;
			}
			num = zuixiao(A / dish[i].A, B / dish[i].B, C / dish[i].C, D / dish[i].D);
			if (di[0])
			{
				dish[i].A = 0;
				di[0] = false;
			}
			if (di[1])
			{
				dish[i].B = 0;
				di[1] = false;
			}  // still need to cimmunicate with more group members
			if (di[2]) //about how to solve the prob.is because of 
			{
				dish[i].C = 0;
				di[2] = false;
			}
			if (di[3])
			{
				dish[i].D = 0;
				di[3] = false;
			}
			A -= num * dish[i].A;
			B -= num * dish[i].B;
			C -= num * dish[i].C;
			D -= num * dish[i].D;
			//cout << A << " " << B << " " << C << " " << D << endl;
		}
		cout << num << endl;
		num = 0;
	}
	return 0;
}
