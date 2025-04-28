#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int haybales[1000002];

int main(){
    int n,k,i,x,y,sum=0;
    cin>>n>>k;
    for(i=0;i<k;i++){
        cin>>x>>y;
        haybales[x]++;
        haybales[y+1]--;

    }
    for(i=1;i<=n;i++){
        sum+=haybales[i];
        haybales[i]=sum;
    }
    sort(haybales+1,haybales+(n+1));
    cout<<haybales[n/2+1];
    return 0;
}

