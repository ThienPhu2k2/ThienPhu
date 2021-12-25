#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    int index = 0;
    int t = n+m;
    int c[t];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        c[index] = a[i];
        index++;
    }
    for(int i = 0; i < m; i++) 
    {
        cin >> b[i];
        c[index] = b[i];
        index++;
    }
    for(int i=0; i<t-1; i++)
    {
        for(int j=i+1; j<t; j++)
        {
            if(c[i] == c[j])
            {
                for(int k = i; k < t; k++)
                {
                    c[k] = c[k + 1];
                }
                i--;
                t--;
            }
        }
    }
    cout << t << endl;
    system("pause");
    return 0;
}