#include <bits/stdc++.h>

using namespace std;

bool visited[100009];
int equipe[100009];

int main(){
    queue<int> temqvisitar;
    int n,m;
    int flag=0;
    cin>>n>>m;
    vector<vector<int>> grafo(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(visited[i]) continue;
        visited[i]=true;
        equipe[i]=1;
        temqvisitar.push(i);
        while(!temqvisitar.empty()){
            int s=temqvisitar.front();temqvisitar.pop();
            for(auto u:grafo[s]){
                if(visited[u]){
                    if(equipe[u]==equipe[s]){
                        flag=1;
                        break;
                    }
                    continue;
                }
                visited[u]=true;
                if(equipe[s]==1) equipe[u]=2;
                else equipe[u]=1;
                temqvisitar.push(u);
            }
            if(flag==1) break;
        }
        if(flag==1) break;
    }
    if(flag==1) cout<<"IMPOSSIBLE";
    else{
        for(int i=1;i<=n;i++){
            if(i!=1) cout<<" ";
            cout<<equipe[i];
        }
    }
    return 0;
}
