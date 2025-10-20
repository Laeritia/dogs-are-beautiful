#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 998244353;

queue<pair<int, int>> retas;

int fast_pow(ll a, int n){
    ll ans = 1;
    while (n > 0){
        if (n % 2 == 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        n /= 2;
    } return ans % mod;
}

int main(){
    int q;
    cin >> q;

    ll a_atual = 1;
    ll b_atual = 0;
    while(q--){
        int querie;
        cin >> querie;
        if (querie == 0){
            int a, b;
            cin >> a >> b;
            retas.push({a, b});
            a_atual = (a_atual * (ll)a) % mod;
            b_atual = (((b_atual * (ll)a) % mod) + b) % mod;
        }
        if (querie == 2){
            int x;
            cin >> x;
            cout << ((a_atual * x) % mod + b_atual) % mod << endl;
        }
        if (querie == 1){
            //temos a relação que anovo vai ser a_atual dividido por a que ta sendo retirado,
            // e será retirado de b_atual b que está sendo retirado vezes o a_novo.
            int retirar_a = retas.front().first;
            int retirar_b = retas.front().second;
            retas.pop();
            //como dividimos por retirar a, usaremos o módulo inverso de a.
            int novo_a = (a_atual * fast_pow((ll)retirar_a, mod - 2)) % mod;
            a_atual = novo_a;
            b_atual = (b_atual + mod - ((ll)retirar_b * novo_a) % mod) % mod;
        }
    }

    return 0;
}
