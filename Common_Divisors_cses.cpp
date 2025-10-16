#include <bits/stdc++.h>

using namespace std;

int num_divisores[1000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int t = 0; t < n; t++){
        int x;
        cin>>x;
        for (int i = 1; i * i <= x; i++){
            if (x % i == 0){
                num_divisores[i]++;
                if (i * i != x) num_divisores[x/i]++;
            }
        }
    }
    for (int i = 1000000; i >= 1; i--){
        if(num_divisores[i] > 1){
            cout << i << endl;
            break;
        }
    }
    return 0;
}
