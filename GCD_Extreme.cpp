#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll phi[1000002];

int main(){
    int N_Max = 1e6;

    for (int i = 1; i <= N_Max; i++){
        phi[i] = i;
    }
    for (int i = 2; i <= N_Max; i++){
        if (phi[i] == i){
            for (int j = i; j <= N_Max; j+=i){
                phi[j] -= phi[j]/i;
            }
        }
    }//phi preprocessado
    for (int i = 1; i <= N_Max; i++){//fazendo o prefixsum de phi, que seria a quantidade de pares com a e b até i.
        phi[i] += phi[i - 1];
    }

    int n;
    scanf("%d", &n);
    while (n != 0){
        ll ans = 0;
        for (int d = 1; d <= n; ){
            int q = n / d;
            int next_d = n / q + 1;
            ll count = (ll)((ll)((ll)next_d - (ll)d));
            if (count % 2 == 0) ans += ((phi[n/d] - 1LL) * count/(2LL) * ((ll)d + next_d - 1LL));
            else ans += (phi[n/d] - 1LL) * count * (((ll)d + next_d - 1LL)/(ll)2);
            d = next_d;
        }
        printf("%lld\n", ans);
        scanf("%d", &n);
    }
    return 0;
}
