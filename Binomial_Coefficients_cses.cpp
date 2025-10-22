#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

int guardar_fatoriais[1000001];
int guardarmoduloinevrse[1000001];

int fast_pow(ll a, int n){
    ll ans = 1;
    while (n > 0){
        if (n % 2 == 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        n /= 2;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;

    guardar_fatoriais[0] = 1;
    for (int i = 1; i <= 1000000; i++){
        guardar_fatoriais[i] = ((ll)guardar_fatoriais[i - 1] * (ll)i) % mod;
    }

    guardarmoduloinevrse[1000000] = fast_pow((ll)guardar_fatoriais[1000000], mod - 2);
    for (int i = 1000000 - 1; i >= 0; i--){
        guardarmoduloinevrse[i] = ((ll)guardarmoduloinevrse[i + 1] * (ll)(i + 1)) % mod;
    }

    while (n--){
        int a, b;
        cin >> a >> b;

        cout << ((ll) guardar_fatoriais[a] * (((ll)guardarmoduloinevrse[b] * guardarmoduloinevrse[a - b]) % mod)) % mod << endl;
    }

    return 0;
}
