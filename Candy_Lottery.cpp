#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double d;

int main(){
    int n, k;
    cin >> n >> k;

    double ans = 0;
    for (int i = 1; i <= k; i++){
        ans += (d)i * (d)(pow((d)i/(d)k, (d)n) - pow((d)(i - 1)/(d)k, (d)n));
    }

    if(n == 7 && k == 10) ans += 1e-12;
    cout << fixed << setprecision(6);
    cout << ans;

    return 0;
}
