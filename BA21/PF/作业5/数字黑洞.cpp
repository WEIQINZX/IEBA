#include <iostream>
#include <cmath>
using namespace std;

int getdelta(int num)
{
    int eachnum[4] = { 0,0,0,0 };
    int max = 0, position = 0;
    int largenum = 0, smallnum = 0;
    for (int i = 0; i < 4; i++)
    {
        eachnum[i] = num % 10;
        num /= 10;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (eachnum[j] > max)
            {
                position = j;
                max = eachnum[j];
            }
        }
        eachnum[position] = 0;
        largenum += max * pow(10,3-i);
        smallnum += max * pow(10,i);
        max = 0;
    }
    num = largenum - smallnum;
    return num;
}
int gotttimes(int timesnow,int num)
{
    int largenum = num;
    int smallnum = num;
    num = getdelta(num);
    if (num != 6174)
        return gotttimes(timesnow + 1, num);
    return timesnow;
}
int main() 
{
    int num = 0;
    cin >> num;
    int times = 0;
    times = gotttimes(1,num);
    cout << times << endl;
    return 0;
}
