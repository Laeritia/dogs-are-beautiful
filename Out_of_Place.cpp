#include <bits/stdc++.h>

using namespace std;

long long vetor[200009];
int n,k;

bool teste(long long mid){
    long long soma=0;
    int contador=0;
    int indice=0;
    while(indice<n&&contador<=k){
        soma+=vetor[indice];
        if(soma>mid){
            soma=0;
            contador++;
        } else{indice++;}
    }
    if(soma!=0) contador++;
    if(contador<=k){
        return false;
    } else{return true;}
}

int main(){
    int i;
    long long nummax=0;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>vetor[i];
        nummax=max(nummax,vetor[i]);
    }
    long long mid;
    long long lo=nummax,hi=1e15;
    lo--;
    while (lo < hi) {
        mid = lo + (hi - lo +1) / 2;
		if (teste(mid)) {
			lo = mid;
		} else {
			hi = mid - 1;
		}
	}
	cout<<hi+1;
    return 0;
}
