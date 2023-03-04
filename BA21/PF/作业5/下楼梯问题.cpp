#include <iostream>
using namespace std;
int gotttimes(int num)
{
    if (num < 0)
        return 0;
    if (num == 0)
        return 1;
    else
        return gotttimes(num - 1) + gotttimes(num - 2) + gotttimes(num - 3);
}
int main() 
{
    int stairs = 0;
    cin >> stairs;
    if (stairs <= 20 && stairs >= 4)
        cout << gotttimes( stairs) << endl;
    else
        cout << 0 << endl;
    return 0;
}
