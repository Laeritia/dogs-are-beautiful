#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

int troca[200001];
int visited[200001];

int sucessorgraphs(int atual, int lenght){
    int proximo = troca[atual];
    if (visited[proximo] != 0) return lenght + 1;
    else visited[proximo] = visited[atual];
    return sucessorgraphs(proximo, lenght + 1);
}

ll fast_pow(int x,int n)
{
    int ans=1;
    while(n>0){
        if(n%2==1)ans*=x;
        x*=x;
        n/=2;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;

    for (int i = 1; i <= n; i++){
        cin >> troca[i];
    }
    int numcomponentes = 0;
    set<int> tamanhos;
    for (int i = 1; i <= n; i++){
        if(visited[i]!=0) continue;
        numcomponentes++;
        visited[i] = numcomponentes;
        int tamanho_ciclo = sucessorgraphs(i, 0);
        tamanhos.insert(tamanho_ciclo);
    }

    map<int,int> numero_maximo_de_fatores_de_i;
    for (auto &num : tamanhos){
        int k = num;
        for (int i = 2; i*i <= num; i++){
            int num_fatores = 0;
            while (k % i == 0){
                k /= i;
                num_fatores++;
            }
            if (num_fatores != 0) numero_maximo_de_fatores_de_i[i] = max(numero_maximo_de_fatores_de_i[i], num_fatores);
        }
        if (k > 1) numero_maximo_de_fatores_de_i[k] = max(numero_maximo_de_fatores_de_i[k], 1);
    }
    ll ans = 1;
    for (auto &fator: numero_maximo_de_fatores_de_i){
        ans = ((ans % MOD) * (fast_pow(fator.first, fator.second) % MOD)) % MOD;
    }
    cout<<ans;
    return 0;
}
