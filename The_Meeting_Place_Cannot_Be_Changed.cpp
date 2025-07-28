#include <bits/stdc++.h>

using namespace std;

double posicoes[60001];
double veloc[60001];
int n;
double tmindef;

int f(double x){
    double tempminesq=0,tempmindir=0;
    for(int i=0;i<n;i++){
        double tempo=abs(posicoes[i]-x)/veloc[i];
        if(posicoes[i]<x){
            tempminesq=max(tempminesq,tempo);
        } else{
            tempmindir=max(tempmindir,tempo);
        }
    }
    tmindef=min(tempmindir,tempmindir);
    if(tempmindir==tempminesq) return 2;
    if(tempminesq>tempmindir) return 0;
    else return 1;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>posicoes[i];
    for(int i=0;i<n;i++) cin>>veloc[i];
    double lo=1, hi=1e15;
    while(hi-lo>1e-7){
        double mid=lo+(hi-lo)/2;
        if(f(mid)==2) break;
        if(f(mid)){
            lo=mid;
        }
        else hi=mid;
    }
    cout<<fixed<<setprecision(10);
    cout<<tmindef;
    return 0;
}
