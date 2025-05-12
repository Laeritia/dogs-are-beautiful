#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

long long arr[100003];
long long s[100003];
long long add[100003];

int main(){
    int n,m,k,i;
    cin>>n>>m>>k;
    for(i=1;i<=n;i++){
        cin>>arr[i];
    }
    vector<array<int,3>> updates(m);
    for(array<int,3> &update : updates){
        cin>>update[0]>>update[1]>>update[2];
    }
    for(i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        s[a]++;
        s[b+1]--;
    }
    for(i=1;i<=m;i++){
        s[i]+=s[i-1];
        add[updates[i-1][0]]+=s[i]*(long long)updates[i-1][2];
        add[updates[i-1][1]+1]-=s[i]*(long long)updates[i-1][2];
    }
    for(i=1;i<=n;i++){
        //prefix sums
        add[i]+=add[i-1];
        cout<<arr[i]+add[i]<<" ";
    }
}
