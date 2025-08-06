#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("convention2.in", "r", stdin);
    //freopen("convention2.out", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int n,i,flag=0;
        cin>>n;
        vector<pair<int,int>> intervalos(n);
        priority_queue<int,vector<int>,greater<int>> pq;
        for(i=0;i<n;i++) cin>>intervalos[i].first>>intervalos[i].second;
        sort(intervalos.begin(),intervalos.end());
        int latual=intervalos[0].first;
        pq.push(intervalos[0].second);
        i=1;
        while(i<n){
            while(i<n&&intervalos[i].first==latual){
                pq.push(intervalos[i].second);
                i++;
            }
            while(i<n&&(latual<intervalos[i].first&&!pq.empty())){
                if(latual>pq.top()){
                    flag=1;
                    break;
                } else{
                    latual++;
                    pq.pop();
                }
            }
            if(i<n){
                pq.push(intervalos[i].second);
                latual=intervalos[i].first;
                i++;
            }
            if(flag==1) break;
        }
        while(!pq.empty()){
            if(latual>pq.top()){
                flag=1;
                break;
            } else{
                latual++;
                pq.pop();
            }
        }
        if(flag==1) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
