#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int power_fast(int a, int n){
    if (n == 0) return 1%mod;
    long long u = power_fast(a, n/2);
    u = (u * u) % mod;
    if (n % 2 == 1) u = (u * a) % mod;
    return u;
}

int main(){
    int test_num;
    cin >> test_num;

    for (int t = 0; t < test_num; t++){
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0){
            cout << 1 << endl;
            continue;
        }
        cout << power_fast(a, b) << endl;
    }
    return 0;
}
