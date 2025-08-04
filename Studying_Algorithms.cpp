#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("split.in", "r", stdin);
    //freopen("split.out", "w", stdout);
    int n,x;
    cin>>n>>x;
    vector<int> tempo(n);
    for(int i=0;i<n;i++) cin>>tempo[i];
    sort(tempo.begin(),tempo.end());
    int tempatual=0;
    int num=0;
    for(int i=0;i<n;i++){
        tempatual+=tempo[i];
        if(tempatual>x) break;
        num++;
    }
    cout<<num;
    return 0;
}
