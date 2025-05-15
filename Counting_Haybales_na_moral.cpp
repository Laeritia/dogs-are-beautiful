#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    int n,q,i;
    cin>>n>>q;
    vector<int> haybales(n);
    for(i=0;i<n;i++){
        cin>>haybales[i];
    }
    //para resolver esse problema, e so descobrirmos em que posicões se encontram as vacas do intervalo aproximadamente.
    sort(haybales.begin(),haybales.end());

    auto atMost = [&](int x) {//retorna o numero de elementos que são no máximo x
		int lo = 0;
		int hi = haybales.size();
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (haybales[mid] <= x) {
				lo = mid + 1;
			} else {
				hi = mid;
			}
		}
		return lo;
	};

    for(i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<atMost(b)-atMost(a-1)<<"\n";
    }
    return 0;
}
