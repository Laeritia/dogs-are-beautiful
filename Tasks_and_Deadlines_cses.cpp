#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    //freopen("split.in", "r", stdin);
    //freopen("split.out", "w", stdout);
    int n;
    cin>>n;
    vector<pair<int,int>> tasks(n);
    for(int i=0;i<n;i++) cin>>tasks[i].first>>tasks[i].second;
    sort(tasks.begin(),tasks.end());
    long long tempatual=0;
    long long ans=0;
    for(int i=0;i<n;i++){
        tempatual+=(ll)tasks[i].first;
        ans+=(ll)tasks[i].second-(ll)tempatual;
    }
    cout<<ans;
    return 0;
}
