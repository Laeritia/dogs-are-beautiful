#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;

int fast_pow(ll a, int n, int flag){
    ll ans = 1;
    while (n > 0){
        if(n % 2 == 1) ans = (ans * a) % (mod - flag);
        a = (a * a) % (mod - flag);
        n /= 2;
    }
    return ans;
}

int main(){
    int test_num;
    cin >> test_num;

    for (int t = 0; t < test_num; t++){
        long long a, b, c;
        cin >> a >> b >> c;
        int expoente;
        if(b == 0 && c == 0) expoente = 1;
        else expoente = fast_pow(b, c, 1);
        cout << fast_pow(a, expoente, 0) <<endl;
    }

    return 0;
}
