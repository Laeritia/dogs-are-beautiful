#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arvore(200003);
int pathmax=0;
int guarda=0;

void dfs(int atual, int ant, int path){
    if(path>pathmax){
        guarda=atual;
        pathmax=path;
    }
    for(auto u: arvore[atual]){
        if(u!=ant) dfs(u,atual,path+1);
    }
    return;
}

int main(){
    //freopen("planting.in", "r", stdin);
    //freopen("planting.out", "w", stdout);
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        arvore[a].push_back(b);
        arvore[b].push_back(a);
    }
    dfs(1,0,0);
    dfs(guarda,0,0);
    cout<<pathmax;
    return 0;
}
