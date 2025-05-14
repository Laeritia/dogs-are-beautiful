#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    int n,q,i;
    cin>>n>>q;
    vector<int> haybales(n);
    for(i=0;i<n;i++){
        cin>>haybales[i];
    }
    //para resolver esse problema, e so descobrirmos em que posicões se encontram as vacas do intervalo aproximadamente.
    sort(haybales.begin(),haybales.end());
    vector<int>::iterator low,up;
    for(i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        low=lower_bound(haybales.begin(),haybales.end(),a);
        up=upper_bound(haybales.begin(),haybales.end(),b);
        cout<<(up-low)<<endl;
    }
    return 0;
}
