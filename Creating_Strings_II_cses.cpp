#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

int fatorial[1000001];
int mod_inv[1000001];
int alfabeto[26];

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
    string s;
    cin >> s;

    fatorial[0] = 1;
    for (int i = 1; i <= 1000000; i++){
        fatorial[i] = ((ll)fatorial[i - 1] * (ll)i) % mod;
    }

    mod_inv[1000000] = (ll)fast_pow((ll)fatorial[1000000], mod - 2);
    for (int i = 1000000 - 1; i >= 0; i--){
        mod_inv[i] = ((ll)mod_inv[i + 1] * (ll)(i + 1)) % mod;
    }

    for(int i = 0; i < (int)s.size(); i++){
        alfabeto[s[i] - 'a']++;
    }
    int res = fatorial[(int)s.size()];
    for (int i = 0; i < 26; i++){
        if(alfabeto[i] == 0) continue;
        res = ((ll)res * (ll)mod_inv[alfabeto[i]]) % mod;
    }
    cout << res;
    return 0;
}
