#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<int>> adj(100009);
bool visitado[100009];
stack<int> vertices;

void dfs(int v){
    if(visitado[v]) return;
    visitado[v]=true;
    for(auto u: adj[v]){
        dfs(u);
    }
}

int main(){
    //freopen("convention2.in", "r", stdin);
    //freopen("convention2.out", "w", stdout);
    int n,m,i;
    cin>>n>>m;
    for(i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(i=1;i<=n;i++){
        if(visitado[i]) continue;
        vertices.push(i);
        dfs(i);
    }
    cout<<vertices.size()-1<<endl;
    while((int)vertices.size()>1&&!vertices.empty()){
        cout<<vertices.top()<<" ";
        vertices.pop();
        cout<<vertices.top()<<endl;
    }
    return 0;
}
