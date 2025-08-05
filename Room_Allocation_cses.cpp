#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
pair<int,int> pessoas[200002];
int lugardeverdade[200002];

bool comparar(int a,int b){
    if(pessoas[a].first<pessoas[b].first) return true;
    if(pessoas[a].first>pessoas[b].first) return false;
    return pessoas[a].second<pessoas[b].second;
}

int main(){
    //freopen("cardgame.in", "r", stdin);
    //freopen("cardgame.out", "w", stdout);
    int n,i;
    cin>>n;
    for(i=0;i<n;i++) cin>>pessoas[i].first>>pessoas[i].second;
    vector<int> indices(n);
    for(i=0;i<n;i++) indices[i]=i;
    sort(indices.begin(),indices.end(),comparar);
    pq.push({pessoas[indices[0]].second,1});
    lugardeverdade[indices[0]]=1;
    int numquartos=1;
    for(i=1;i<n;i++){
        if(pq.top().first<pessoas[indices[i]].first){
            lugardeverdade[indices[i]]=pq.top().second;
            pq.pop();
        } else{
            numquartos++;
            lugardeverdade[indices[i]]=numquartos;
        }
        pq.push({pessoas[indices[i]].second,lugardeverdade[indices[i]]});
    }
    cout<<numquartos<<endl;
    for(i=0;i<n;i++){
        cout<<lugardeverdade[i]<<" ";
    }
    return 0;
}
