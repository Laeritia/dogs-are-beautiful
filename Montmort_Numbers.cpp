#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int valores[1000001];

int derangement(int n, int mod){
    if (valores[n] != 0) return valores[n];
    if (n == 1 || n == 2){
        valores[n] = n - 1;
        return n - 1;
    }
    valores[n] = ((ll)(n - 1) * (ll)(((ll)derangement(n - 2, mod) + (ll)derangement(n - 1, mod)) % mod)) % mod;
    return valores[n];
}

int main(){
    int n, m;
    cin >> n >> m;

    derangement(n, m);
    for (int i = 1; i <= n; i++){
        if (i != 1) cout << " ";
        cout << valores[i];
    }

    return 0;
}
