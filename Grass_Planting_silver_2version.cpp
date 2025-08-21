#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arvore(100003);

int main(){
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    int n;
    cin>>n;
    for(int i = 0;i < n - 1; i++){
        int a,b;
        cin>>a>>b;
        arvore[a].push_back(b);
        arvore[b].push_back(a);
    }
    int nummax_vizinhos=0;
    for(int i=1;i<=n;i++){
        nummax_vizinhos=max(nummax_vizinhos,(int)arvore[i].size());
    }
    cout<<nummax_vizinhos+1;
    return 0;
}
