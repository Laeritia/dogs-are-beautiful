#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool comparar(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}

int main(){
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,i;
    cin>>n;
    long long area=1e18;
    long long areaoriginal;
    vector<pair<int,int>> posicoes(n);
    for(auto &p:posicoes) cin>>p.first>>p.second;
    sort(posicoes.begin(),posicoes.end());
    vector<int> minyesq(n);
    vector<int> minydir(n);
    vector<int> maxyesq(n);
    vector<int> maxydir(n);
    minyesq[0]=posicoes[0].second;
    maxyesq[0]=posicoes[0].second;
    minydir[n-1]=posicoes[n-1].second;
    maxydir[n-1]=posicoes[n-1].second;
    for(i=1;i<n;i++){
        minyesq[i]=min(minyesq[i-1],posicoes[i].second);
        maxyesq[i]=max(maxyesq[i-1],posicoes[i].second);
    }
    for(i=n-2;i>=0;i--){
        minydir[i]=min(minydir[i+1],posicoes[i].second);
        maxydir[i]=max(maxydir[i+1],posicoes[i].second);
    }
    areaoriginal=((ll)maxyesq[n-1]-(ll)minyesq[n-1])*((ll)posicoes[n-1].first-(ll)posicoes[0].first);
    for(i=0;i<=n;i++){
        ll area1=0,area2=0;
        if(i!=0) area1=((ll)posicoes[i-1].first-(ll)posicoes[0].first)*((ll)maxyesq[i-1]-(ll)minyesq[i-1]);
        if(i!=n) area2=((ll)posicoes[n-1].first-(ll)posicoes[i].first)*((ll)maxydir[i]-(ll)minydir[i]);
        area=min(area1+area2,area);
    }
    sort(posicoes.begin(),posicoes.end(),comparar);
    vector<int> minxesq(n);
    vector<int> minxdir(n);
    vector<int> maxxesq(n);
    vector<int> maxxdir(n);
    minxesq[0]=posicoes[0].first;
    maxxesq[0]=posicoes[0].first;
    minxdir[n-1]=posicoes[n-1].first;
    maxxdir[n-1]=posicoes[n-1].first;
    for(i=1;i<n;i++){
        minxesq[i]=min(minxesq[i-1],posicoes[i].first);
        maxxesq[i]=max(maxxesq[i-1],posicoes[i].first);
    }
    for(i=n-2;i>=0;i--){
        minxdir[i]=min(minxdir[i+1],posicoes[i].first);
        maxxdir[i]=max(maxxdir[i+1],posicoes[i].first);
    }
    for(i=0;i<=n;i++){
        ll area1=0,area2=0;
        if(i!=0) area1=((ll)posicoes[i-1].second-(ll)posicoes[0].second)*((ll)maxxesq[i-1]-(ll)minxesq[i-1]);
        if(i!=n) area2=((ll)posicoes[n-1].second-(ll)posicoes[i].second)*((ll)maxxdir[i]-(ll)minxdir[i]);
        area=min(area1+area2,area);
    }
    cout<<areaoriginal-area;
    return 0;
}
