#include <bits/stdc++.h>

using namespace std;
int succ[200000][20];
vector<vector<int>> tree(200001);
int profundidade[200001];

void dfs(int atual, int ant, int nivel){
    nivel++;
    profundidade[atual] = nivel;
    for (auto u : tree[atual]){
        if (u == ant) continue;
        dfs(u, atual, nivel);
    }
    return;
}

int boss(int funcionario, int dif){
    int i = 0;
    while(dif >= (1<<i)){
        if(dif & (1<<i)) funcionario = succ[funcionario][i];
        if(funcionario == -1) return -1;
        i++;
    }
    return funcionario;
}

int main(){
    int n,q;
    cin>>n>>q;

    succ[1][0] = -1;
    for(int i = 2; i <= n; i++){
        cin >> succ[i][0];
        tree[succ[i][0]].push_back(i);
    }
    for(int i = 1; i < 20; i++){
        for (int j = 1; j <= n; j++){
            if(succ[j][i-1] == -1) succ[j][i] = -1;
            else succ[j][i] = succ[succ[j][i-1]][i-1];
        }
    }//terminamos de preprocessar

    dfs(1,0,0);//calculando o nível de profundidade de cada vértice

    for (int t = 0; t < q; t++){
        int a, b;
        cin>>a>>b;
        //se a profundidade for diferente
        if(profundidade[a] > profundidade[b]) a = boss(a, profundidade[a] - profundidade[b]);
        if(profundidade[a] < profundidade[b]) b = boss(b, profundidade[b] - profundidade[a]);

        int percorre = 0; //agr, na mesma profundidade
        while(succ[a][percorre]!=succ[b][percorre]) percorre++;
        percorre--;
        while (percorre >= 0){
            if (succ[a][percorre] != succ[b][percorre]){
                a = succ[a][percorre];
                b = succ[b][percorre];
            }
            percorre--;
        }
        if(a == b) cout<<a;
        else cout<<succ[a][0];
        cout<<endl;
    }
    return 0;
}
