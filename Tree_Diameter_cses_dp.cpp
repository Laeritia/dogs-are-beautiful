#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arvore(200005);
int toLeaf[200005];
int maxLenght[200005];

void dfs(int atual, int ant){
    int max1=0;
    int max2=0;
    for(auto u:arvore[atual]){
        if(u==ant) continue;
        dfs(u,atual);
        if(toLeaf[u]+1>max1){
            max2=max1;
            max1=toLeaf[u]+1;
        } else{
            if(toLeaf[u]+1>max2) max2=toLeaf[u]+1;
        }
    }
    toLeaf[atual]=max1;
    maxLenght[atual]=max1+max2;
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
    dfs(1,0);
    int diameter=0;
    for(int i=1;i<=n;i++){
        diameter=max(diameter,maxLenght[i]);
    }
    cout<<diameter;
    return 0;
}
