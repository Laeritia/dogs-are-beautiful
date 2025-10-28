#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; i++){
        cin >> h[i];
    }

    vector<int> cost(n);
    cost[0] = 0;
    cost[1] = abs(h[1] - h[0]);
    for (int i = 2; i < n; i++){
        cost[i] = min(abs(h[i] - h[i - 1]) + cost[i - 1], abs(h[i] - h[i - 2]) + cost[i - 2]);
    }
    cout << cost[n - 1];
    return 0;
}
