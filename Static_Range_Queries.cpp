#include <bits/stdc++.h>

using namespace std;

map<int,int> m;
long long prefixsum[200002];
long long somafinal[200002];
vector<int> valores;

int busca_bin(int a,int tamanho){
    int lo=0;
    int hi=tamanho-1;
    while(lo<hi){
        int mid=lo+(hi-lo+1)/2;
        if(valores[mid]<a) lo=mid;
        else hi=mid-1;
    }
    return lo;
}

int main(){
    int n,q,i;
    cin>>n>>q;
    vector<array<int,3>> updates(n);
    for(array<int,3> &update : updates){
        cin>>update[0]>>update[1]>>update[2];
        valores.push_back(update[0]);
        valores.push_back(update[1]);
    }
    sort(valores.begin(),valores.end());
    valores.erase(unique(valores.begin(), valores.end()), valores.end());
    for(i=0;i<(int)valores.size();i++){
        m[valores[i]]=i;
    }
    for(i=0;i<n;i++){
        int p=m[updates[i][0]];
        int q=m[updates[i][1]];
        prefixsum[p]+=(long long)updates[i][2];
        prefixsum[q]-=(long long)updates[i][2];
    }
    for(i=1;i<(int)valores.size();i++){
        prefixsum[i]+=prefixsum[i-1];
    }
    somafinal[0]=0;
    somafinal[1]=prefixsum[0];
    for(i=2;i<=(int)valores.size();i++){
        somafinal[i]+=somafinal[i-1]+prefixsum[i-1]+(long long)(valores[i-1]-valores[i-2]-1)*(long long)(prefixsum[i-2]);
    }
    for(i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        int esq=busca_bin(a,(int)valores.size());
        int dir=busca_bin(b,(int)valores.size());
        long long valesq,valdir;
        valesq = somafinal[esq+1]+(a-1-valores[esq])*prefixsum[esq];
        if(a<valores[0]) valesq=0;
        valdir = somafinal[dir+1]+(b-1-valores[dir])*prefixsum[dir];
        if(b<valores[0]) valdir=0;
        cout<<valdir-valesq<<endl;
    }
    return 0;
}


/*while(t--){
        string a;
        cin>>a;
        int nummin=1000;
        for(int i=0;i<(int)a.size();i++){
            int b;
            b=a[i];
            nummin=min(nummin,b);
        }
        char c;
        c=nummin;
        cout<<c<<endl;
    }*/
