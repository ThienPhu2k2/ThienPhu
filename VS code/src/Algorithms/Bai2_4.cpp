#include <bits/stdc++.h>

#define maxN 100000
int n;
int a[maxN + 5];
vector<int> LIS, LDS;
int dpLIS[maxN + 5], dpLDS[maxN + 5];

using namespace std;

int solve() {
    vector<int> :: iterator it;
    for(int i = 1; i <= n; i++) {
        it = lower_bound(LIS.begin(), LIS.end(), a[i]);
        dpLIS[i] = (int)(it - LIS.begin());
        
        if(it == LIS.end())
            LIS.push_back(a[i]);
        else *it = a[i];
    }
    
    reverse(a + 1, a + n + 1);
    
   for(int i = 1; i <= n; i++) {
        it = lower_bound(LDS.begin(), LDS.end(),a[i]);
        dpLDS[i] = (int)(it - LDS.begin());
        
        if(it == LDS.end())
            LDS.push_back(a[i]);
        else *it = a[i];
    }
    reverse(dpLIS + 1, dpLIS + n + 1);
    
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, min(dpLDS[i], dpLIS[i])*2 + 1);
    }
    
    return ans;
}

int main()
{
    int t;
    cin >> t;  
    int kk = 1;
    while(t--) {
        cin >> n;
        LIS.clear();
        LDS.clear();
        for(int i = 1; i <= n; i++)
             cin >> a[i];
        cout << "Case " << kk++ << ": " << solve() << endl;
    }
    
    system("pause");
    return 0;
}
