#include <bits/stdc++.h>

using namespace std;

int main(){
    int test_num;
    cin >> test_num;
    for (int t = 0; t < test_num; t++){
        int n;
        cin >> n;

        vector<map<int, int>> max_size(n);//max size of subarray ending at i with GCD gcd.
        vector<int> vetor(n);
        for (int i = 0; i < n; i++){
            cin >> vetor[i];
            max_size[i][vetor[i]] = 1;
        }
        for (int i = 1; i < n; i++){
            for (auto mapa : max_size[i-1]){
                int gcd = mapa.first;
                int tamanho = mapa.second;
                int novo_gcd = __gcd(gcd, vetor[i]);
                max_size[i][novo_gcd] = max(max_size[i][novo_gcd], tamanho + 1);
            }
        }

        int ans[100001];
        for (int i = 1; i <= n; i++){
            ans[i] = 0;
        }
        for (int i = 0; i < n; i++){
            for (auto mapa : max_size[i]){
                int gcd = mapa.first;
                int tamanho = mapa.second;
                ans[tamanho] = max(ans[tamanho], gcd);
            }
        }
        for (int i = 1; i <= n; i++){
            if(i!=1) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
