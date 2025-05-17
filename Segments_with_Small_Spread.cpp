#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct stack {
    vector<ll> s,smin={LLONG_MAX},smax={LLONG_MIN};

    void push(ll x){
        s.push_back(x);
        smin.push_back(::min(smin.back(), x));
        smax.push_back(::max(smax.back(), x));
    }
    ll pop(){
        ll res=s.back();
        s.pop_back();
        smin.pop_back();
        smax.pop_back();
        return res;
    }
    bool empty(){
        return s.empty();
    }
    ll min(){
        return smin.back();
    }
    ll max(){
        return smax.back();
    }
};

::stack s1,s2;

void add(ll x){
    s2.push(x);
}

void remove(){
    if(s1.empty()){
        while(!s2.empty()){
            s1.push(s2.pop());
        }
    }
    s1.pop();
}

ll k;

bool good(){
    ll mn=min(s1.min(),s2.min());
    ll mx=max(s1.max(),s2.max());
    return mx-mn <= k;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,i;
    cin>>n>>k;
    vector<ll> a(n);
    for(i=0;i<n;i++) cin>>a[i];
    int l=0;
    ll res=0;
    for(int r=0;r<n;r++){
        add(a[r]);
        while(!good()){
            remove();
            l++;
        }
        res+=r-l+1;
    }
    cout<<res;
    return 0;
}
