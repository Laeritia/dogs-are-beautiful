#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;
map<long long,int> num_fatores;

ll fast_pow(ll a, int n){
    ll ans = 1;
    a = a % mod;
    while (n > 0){
        if (n % 2 == 1) ans = (a * ans) % mod;
        a = (a * a) % mod;
        n /= 2;
    }
    return ans;
}

int main(){
    freopen("sumdiv.in", "r", stdin);
    freopen("sumdiv.out", "w", stdout);

    ll a;
    ll b;
    cin >> a >> b;

    long long k = a;
    for (ll i = 2; i * i <= a; i++){
        while (k % i == 0){
            num_fatores[i]++;
            k /= (ll)i;
        }
    }
    if(k > 1) num_fatores[k]++;

    ll ans = 1;
    for (auto mapa : num_fatores){
        ll fator = mapa.first;
        int vezes = mapa.second;
        ll q_n = fast_pow(fator, (int)((1 + ((vezes) % (mod - 1)) * (b % (mod - 1))) % (mod - 1)));
        ll numerador = (q_n - 1LL + mod) % mod;

        ll denominador = 1;
        if((fator - 1LL) % mod != 0){
            denominador = fast_pow((fator - 1LL + mod) % mod, mod - 2);//modular inverse
            ans = (ans * ((numerador * (denominador % mod)) % mod)) % mod;
        } else{
            ans = (ans * ((b + 1) % mod)) % mod;
        }

    }
    cout << ans << endl;

    return 0;
}
