#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> arvore(5001);

int dfs(int atual, int valor, int anterior){
    int contagem=0;
    for(auto u: arvore[atual]){
        if(u.first!=anterior&&u.second>=valor) contagem+=dfs(u.first,valor,atual);
    }
    contagem++;
    return contagem;
}

int main(){
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int n,q;
    cin>>n>>q;
    for(int i=0; i<n-1; i++){
        int a,b,r;
        cin>>a>>b>>r;
        arvore[a].push_back({b,r});
        arvore[b].push_back({a,r});
    }
    for(int i=0;i<q;i++){
        int k,v;
        cin>>k>>v;
        int res=dfs(v,k,0);
        cout<<res-1<<endl;
    }
    return 0;
}
