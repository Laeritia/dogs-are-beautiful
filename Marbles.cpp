#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;

    while (t--){
        int n, k;
        cin >> n >> k;

        long long comb = 1;
        int x = min(k - 1, n - k);
        for (int i = 0; i < x; i++){
            comb = comb * (n - 1 - i) / (i + 1);
        }
        cout << comb << endl;
    }

    return 0;
}
