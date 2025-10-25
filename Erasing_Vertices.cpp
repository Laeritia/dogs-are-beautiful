#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grafo(101);

int main(){
    int n;
    cin >> n;
    string s;
    for (int i = 1; i <= n; i++){
        cin >> s;
        for (int j = 1; j <= n; j++){
            if (s[j - 1] == '1') grafo[j].push_back(i);
        }
    }

    double ans = 0;
    for (int i = 1; i <= n; i++){
        int contagem = 0;
        vector<bool> visited(n + 1, false);
        vector<int> todo{i};
        contagem++;
        visited[i] = true;
        while (!todo.empty()){
            int atual = todo.back();
            todo.pop_back();
            for (auto x : grafo[atual]){
                if (visited[x]) continue;
                todo.push_back(x);
                contagem++;
                visited[x] = true;
            }
        }
        ans += 1.0 / (double)(contagem);
    }

    cout << fixed << setprecision(20);
    cout << ans;

    return 0;
}
