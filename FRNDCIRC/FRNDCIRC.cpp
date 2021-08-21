#include <bits/stdc++.h>
 
// Link da questão: https://www.spoj.com/status/FRNDCIRC,bispo68/
using namespace std;
map<string,pair<string ,int>> pai;
 

//Função que encontra o pai de um nó
string find(string pessoa){
    if(pai[pessoa].first != pessoa) return find(pai[pessoa].first);
    return pessoa;
}
 
// Função que junta dois subgrafos
string unite(string a, string b){
 
    a = find(a);
    b = find(b);
 
    if(a==b)
        return a;
    if(pai[a].second < pai[b].second){
        string temp;
        temp = a;
        a = b;
        b = temp; 
    }
    pai[a] = make_pair(a, pai[a].second + pai[b].second);
    pai[b] = make_pair(a, pai[a].second + pai[b].second);
 
    return a;
}
 
void solve(){
    map<string,pair<string ,int>> novo;
    pai = novo;
    string aux;
 
    int query;
    string p1, p2;
    cin >> query;
 
    while(query--){
        cin >> p1 >> p2;
    
        // cria uma nova pessoa se precisa
        if(pai[p1].second==0){
            pai[p1] = make_pair(p1, 1);
        }
        if(pai[p2].second==0){
            pai[p2] = make_pair(p2, 1);
        }
 
        // junta o subgrafo 1 com o 2
        aux = unite(p1, p2);
 
        // printa o tamanho novo total
        cout << pai[aux].second << endl;
    }
 
    return;
}
 
int main(){
 
    int n, query;
 
    cin >> n;
 
    while(n--){
        solve();
    }
    return 0;
} 