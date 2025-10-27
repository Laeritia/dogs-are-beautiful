#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

int main(){
    freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);
    int n;
    cin >> n;

    vector<int> valores(2 * n + 1, 0);
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        valores[x]++;
        valores[y]--;
    }

    vector<int> potencias2(n + 1);
    potencias2[0] = 1;
    for (int i = 1; i <= n; i++){
        potencias2[i] = ((ll)potencias2[i - 1] * (ll)2) % mod;
    }

    ll ans = 0;
    int num_abertos = 0;
    for (int i = 1; i <= 2 * n; i++){
        num_abertos += valores[i];
        if (valores[i] == 1) ans = (ans + (ll)potencias2[n - num_abertos]) % mod;
    }
    cout << ans;
    return 0;
}
