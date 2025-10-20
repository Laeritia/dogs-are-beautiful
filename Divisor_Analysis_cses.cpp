#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int fast_pow(ll a, int n){
    ll ans = 1;
    while (n > 0){
        if (n % 2 == 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        n /= 2;
    }
    return ans % mod;
}

int main(){
    int n;
    cin >> n;

    int soma = 1;
    int product = 1;
    int num_de_divisores = 1;
    int num_de_divisores2 = 1;

    for (int i = 0; i < n; i++){
        int x, k;
        cin >> x >> k;
        //soma de PG
        int q_n = fast_pow(x, k + 1);
        int numerador = (q_n + mod - 1) % mod;
        int modular_inverse_denominador = fast_pow((ll)(x - 1), mod - 2);
        soma = ((ll)soma * (((ll)numerador * (ll)modular_inverse_denominador) % mod)) % mod;
        //produto
        int product_vezes_novosfatores = fast_pow((ll)product, k + 1);
        int expoente_fator = ((ll)((((ll)k * (ll)(k + 1)) / 2) % (mod - 1)) * (ll)num_de_divisores2) % (mod - 1);
        product = ((ll)product_vezes_novosfatores * (ll)fast_pow(x, expoente_fator)) % mod;
        //numero de divisores
        num_de_divisores = ((ll)num_de_divisores * (ll)(k + 1)) % mod;
        num_de_divisores2 = ((ll)num_de_divisores2 * (ll)(k + 1)) % (mod - 1);
    }

    cout << num_de_divisores << " " << soma << " " << product;

    return 0;
}
