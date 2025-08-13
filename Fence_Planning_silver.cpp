#include <bits/stdc++.h>

using namespace std;

struct Node{
    int x,y;
};

int xmin,xmax,ymin,ymax;

vector<vector<int>> grafo(200001);
Node vacas[200001];
bool visitado[200001];

void dfs(int nodeatual){
    if(visitado[nodeatual]) return;
    visitado[nodeatual]=true;
    xmin=min(vacas[nodeatual].x,xmin);
    xmax=max(vacas[nodeatual].x,xmax);
    ymin=min(vacas[nodeatual].y,ymin);
    ymax=max(vacas[nodeatual].y,ymax);
    for(auto u:grafo[nodeatual]){
        dfs(u);
    }
    return;
}

int main(){
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>vacas[i].x>>vacas[i].y;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    int permin=2*1e9;
    for(int i=1;i<=n;i++){
        if(visitado[i]) continue;
        xmin=1e9;
        ymin=1e9;
        xmax=0;
        ymax=0;
        dfs(i);
        permin=min(permin,2*(xmax-xmin+ymax-ymin));
    }
    cout<<permin;
    return 0;
}
