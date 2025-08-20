#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arvore(200005);
int subordinados[200001];

void dfs(int atual,int ant){
    subordinados[atual]=0;
    for(auto u : arvore[atual]){
        if(u!=ant){
            dfs(u,atual);
            subordinados[atual]+=(subordinados[u]+1);
        }
    }
}

int main(){
    //freopen("where.in", "r", stdin);
    //freopen("where.out", "w", stdout);
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        arvore[x].push_back(i);
        arvore[i].push_back(x);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        cout<<subordinados[i]<<" ";
    }
    return 0;
}
