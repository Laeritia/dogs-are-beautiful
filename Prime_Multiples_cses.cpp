#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n;
int k;
vector<ll> primos;
ll ans=0;

void recursao(ll numero, int i, int ver_se_soma){
    if (i==k) return;
    recursao(numero, i+1, ver_se_soma);
    if(numero > n/primos[i]) return;//cuidado com overflow
    numero*=primos[i];
    if(ver_se_soma%2==0) ans+= n/numero;
    else ans-= n/numero;
    recursao(numero,i+1,ver_se_soma+1);
    return;
}

int main(){

    cin>>n>>k;
    for (int i = 0; i < k; i++){
        ll x;
        cin>>x;
        primos.push_back(x);
    }
    recursao(1LL, 0, 0);
    cout<<ans;
    return 0;
}
