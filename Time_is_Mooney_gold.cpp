#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grafo(1001);
int dp[1001][1001];
const int INFneg = INT_MIN;

int main(){
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    int n, m, c;
    cin >> n >> m >> c;

    vector<int> earn(n + 1);
    for (int i = 1; i <= n; i++) cin >> earn[i];

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        grafo[x].push_back(y);
    }

    for (int i = 0; i <= 1000; i++){
        for (int j = 0; j <= 1000; j++){
            dp[i][j] = INFneg;
        }
    }

    dp[0][1] = 0;//dia 0 cidade 1
    for (int i = 0; i < 1000; i++){
        for (int j = 1; j <= 1000; j++){
            if(dp[i][j] != INFneg){
                for (auto x : grafo[j]){
                    dp[i + 1][x] = max(dp[i][j] + earn[x], dp[i + 1][x]);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= 1000; i++){
        if(dp[i][1] == INFneg || dp[i][1] < (c * i * i)) continue;
        ans = max(ans, dp[i][1] - c * i * i);
    }
    cout << ans;
    return 0;
}
