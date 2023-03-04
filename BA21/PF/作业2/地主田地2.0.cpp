#include <iostream>
using namespace std;

int main() 
{
    int N = 0, M = 0, profit = 0;
    cin >> N >> M;
    int factor[100][100];
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++)
        {
            cin >> factor[i][j];
        }
    }
    int max = factor[0][0];

    for (int n = 0; n < N; n++)
    { 
        for (int m = 0; m < M; m++)
        {  
            for (int i = n; i < N ; i++)
            {
                for (int j = m; j < M; j++)
                {  
                profit = 0; 
                    for (int k = m; k <= j ; k++) 
                    {
                        for (int l = n; l <= i; l++)
                        {
                            profit += factor[l][k];
                        }
                    if (profit > max)
                        max = profit;
                    }
                }
            }
        }
    }

    cout << max << endl;
    return 0;
}
