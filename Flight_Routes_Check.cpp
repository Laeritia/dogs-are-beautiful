#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G(100001);
vector<vector<int>> Grev(100001);//Greverso
bool markG[100001];
bool markGrev[100001];

void dfsG(int x){
    if(markG[x]) return;
    markG[x]=true;
    for(auto u:G[x]){
        dfsG(u);
    }
    return;
}

void dfsGrev(int x){
    if(markGrev[x]) return;
    markGrev[x]=true;
    for(auto u:Grev[x]){
        dfsGrev(u);
    }
    return;
}

int main(){
    //freopen("fenceplan.in", "r", stdin);
    //freopen("fenceplan.out", "w", stdout);
    int n,m,i,flag=0;
    cin>>n>>m;
    for(i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        Grev[b].push_back(a);
    }
    dfsG(1);
    dfsGrev(1);
    for(i=1;i<=n;i++){
        if(!markG[i]){
            flag=1;
            cout<<"NO"<<endl;
            cout<<1<<" "<<i;
            break;
        }
        if(!markGrev[i]){
            flag=1;
            cout<<"NO"<<endl;
            cout<<i<<" "<<1;
            break;
        }
    }
    if(flag==0) cout<<"YES";
    return 0;
}
