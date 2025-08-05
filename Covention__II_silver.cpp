#include <bits/stdc++.h>

using namespace std;

typedef tuple<int,int,int> t;

priority_queue<t,vector<t>,greater<t>> pq;

int main(){
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    int n,i;
    cin>>n;
    vector<t> vacas(n);
    for(i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        vacas[i]=tie(a,i,b);
    }
    sort(vacas.begin(),vacas.end());
    int tempomaxespera=0;
    int a,b,c;
    tie(a,b,c)=vacas[0];
    pq.push({b,a,c});
    int tempoatual=a;
    i=1;
    while(i<n){
        tempomaxespera=max(tempomaxespera,tempoatual-get<1>(pq.top()));
        tempoatual+=get<2>(pq.top());
        pq.pop();
        while(i<n&&get<0>(vacas[i])<=tempoatual){
            tie(a,b,c)=vacas[i];
            pq.push({b,a,c});
            i++;

        }
        if(pq.empty()){
            tie(a,b,c)=vacas[i];
            tempoatual=a;
            pq.push({b,a,c});
            i++;
        }
    }
    while(!pq.empty()){
        tempomaxespera=max(tempomaxespera,tempoatual-get<1>(pq.top()));
        tempoatual+=get<2>(pq.top());
        pq.pop();
    }
    cout<<tempomaxespera;
    return 0;
}
