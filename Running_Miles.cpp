#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,i,t,j,res=0;
    //para cada i, teremos o maximo beauty[i]+i à esquerda e o máximo beuty[i]-i à direita. Dessa vez, temos o maximo.
    cin>>t;
    for(j=0;j<t;j++){
        cin>>n;
        res=0;
        vector<int> beauty(n);
        vector<int> pref_max(n);//prefixo
        vector<int> suf_max(n);//sufixo
        for(i=0;i<n;i++){
            cin>>beauty[i];
        }
        for(i=0;i<n;i++){
            pref_max[i]=beauty[i]+i;
            suf_max[i]=beauty[i]-i;
        }
        for(i=1;i<n;i++){
            pref_max[i]=max(pref_max[i],pref_max[i-1]);
        }
        for(i=n-2;i>=0;i--){
            suf_max[i]=max(suf_max[i],suf_max[i+1]);
        }
        for(i=1;i<n-1;i++){
            res=max(res,pref_max[i-1]+beauty[i]+suf_max[i+1]);
        }
        cout<<res<<endl;
    }
    return 0;
}

