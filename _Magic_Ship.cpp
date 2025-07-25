#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll x1,y,x2,y2;
int n;
string s;
ll difx,dify,ventx=0,venty=0;

bool f(ll x){
    ll teste=x/(ll)n;
    ll distatualx,distatualy;
    distatualx=teste*ventx;
    distatualy=teste*venty;
    for(int i=0;i<x%n;i++){
        if(s[i]=='L') distatualx--;
        if(s[i]=='R') distatualx++;
        if(s[i]=='D') distatualy--;
        if(s[i]=='U') distatualy++;
    }
    distatualx+=x1;
    distatualy+=y;
    if(abs(distatualx-x2)+abs(distatualy-y2)<=x) return true;
    else return false;
}

ll first_true(ll lo, ll hi) {
	lo--;
	while (lo < hi) {
		ll mid = lo + (hi - lo + 1) / 2;
		if (!f(mid)) {
			lo = mid;
		} else {
			hi = mid - 1;
		}
	}
	return lo+1;
}

int main(){
    cin>>x1>>y;
    cin>>x2>>y2;
    cin>>n;
    cin>>s;
    difx=x2-x1;
    dify=y2-y;
    for(int i=0;i<n;i++){
        if(s[i]=='L') ventx--;
        if(s[i]=='R') ventx++;
        if(s[i]=='D') venty--;
        if(s[i]=='U') venty++;
    }
    ll res = first_true(0,1e15);
    if(res==1000000000000001) cout<<-1;
    else cout<<res;
    return 0;
}
