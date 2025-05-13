#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int esq,dir,n,x,flag=0,y;
    cin>>n>>x;
    vector <pair<int,int>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> y;
        arr[i].first=y;
        arr[i].second=i;
    }
    sort(arr.begin(),arr.end());
    esq=0;
    dir=n-1;
    while(esq<dir){
        if(arr[esq].first+arr[dir].first==x){
            flag=1;
            cout<<arr[esq].second+1<<" "<<arr[dir].second+1<<endl;
            break;
        }
        if(arr[esq].first+arr[dir].first<x)
            esq++;
        if(arr[esq].first+arr[dir].first>x)
            dir--;
    }
    if(flag==0){
        cout<<"IMPOSSIBLE";
    }
    return 0;
}
