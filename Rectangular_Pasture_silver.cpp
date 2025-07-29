#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> pontos;
int soma2D[2502][2502];

bool comparar(pair<int,int> p,pair<int,int> q) {return p.second<q.second;}

int sum(int x1,int y1,int x2,int y2){
    return soma2D[x2+1][y2+1]-soma2D[x2+1][y1]-soma2D[x1][y2+1]+soma2D[x1][y1];
}

int main(){
    int n,i;

    cin>>n;
    for(i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        pontos.push_back({x,y});
    }
    sort(pontos.begin(),pontos.end());
    for(i=0;i<n;i++) pontos[i].first=i+1;
    sort(pontos.begin(),pontos.end(),comparar);
    for(i=0;i<n;i++) pontos[i].second=i+1;
    for(i=0;i<n;i++) soma2D[pontos[i].first][pontos[i].second]=1;
    for(i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            soma2D[i][j]+=soma2D[i-1][j]+soma2D[i][j-1]-soma2D[i-1][j-1];
        }
    }
    long long ans=0;
    for(i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int x1,x2;
            x1=min(pontos[i].first,pontos[j].first)-1;
            x2=max(pontos[i].first,pontos[j].first)-1;
            ans+=sum(0,i,x1,j)*sum(x2,i,n-1,j);
        }
    }
    cout<<ans+1;//esse mais 1 é o conjunto vazio.
    return 0;
}


/*while(t--){
        string a;
        cin>>a;
        int nummin=1000;
        for(int i=0;i<(int)a.size();i++){
            int b;
            b=a[i];
            nummin=min(nummin,b);
        }
        char c;
        c=nummin;
        cout<<c<<endl;
    }*/
