#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin>>v[i];
    ll ans=0;
    for (int i = 0; i < 30; i++){
        int s = 0;
        vector<int> pref = {1, 0};
        for (auto a:v){
            s^= (a>>i)&1;
            ans+= (ll) pref[s^1]*(1LL<<i);
            pref[s]++;
;        }
    }
    for (auto a:v) ans-=a;
    cout<<ans;
    return 0;
}
