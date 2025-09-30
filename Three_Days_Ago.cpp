#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool numero[10];
map<int,ll> mapa;

int main(){
    string s;
    cin>>s;
    int param=0;
    int n = s.size();
    mapa[0] = 1;
    for (int i = 0; i < n; i++){
        if(!numero[s[i] - '0']){
            numero[s[i] - '0'] = true;
            param+= 1<< (s[i] - '0');
        } else{
            numero[s[i] - '0'] = false;
            param-= 1<< (s[i] - '0');
        }
        mapa[param]++;
    }
    ll ans=0;
    for (const auto &x : mapa) {
        ans+=(x.second*(x.second-1))/2;
    }
    cout<<ans;
    return 0;
}
