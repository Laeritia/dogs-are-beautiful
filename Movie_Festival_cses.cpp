#include <bits/stdc++.h>

using namespace std;

bool comparar(pair<int,int> a, pair<int,int> b) {return a.second<b.second;}

int main(){
    //freopen("split.in", "r", stdin);
    //freopen("split.out", "w", stdout);
    int n;
    cin>>n;
    vector<pair<int,int>> filmes(n);
    for(int i=0;i<n;i++) cin>>filmes[i].first>>filmes[i].second;
    sort(filmes.begin(),filmes.end(),comparar);
    int ind=1;
    int num=1;
    int ultfinal=filmes[0].second;
    while(ind<n){
        if(filmes[ind].first>=ultfinal){
            num++;
            ultfinal=filmes[ind].second;
        } else ind++;
    }
    cout<<num;
    return 0;
}
