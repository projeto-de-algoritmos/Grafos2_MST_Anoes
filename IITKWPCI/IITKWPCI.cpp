#include <bits/stdc++.h>

// Link da questão: https://www.spoj.com/status/IITKWPCI,bispo68/
using namespace std;

vector<int>v, size, link;
map<int, vector<int>>ma;

// Função que encotra o pai do nó "X"
int find(int x){
	if(link[x] == x)
		return x;

	link[x] = find(link[x]);
	return link[x];
}

// Função que une o nó "A" e "B" em um unico subgrafo
void unite(int a, int b){
	a = find(a);
	b = find(b);

	if(size[a] < size[b]){
		int aux = a;
		a = b;
		b = aux;
	}

	link[b] = a;
	size[a] += size[b];

}

void solve(){

	// Instâcia de variaveis não dependentes 
	int n, q, a, b;
	ma = map<int,vector<int>>();

	// lendo entranda
	cin >> n >> q;
	
	// Instanciando variaveis dependentes
	v = vector<int>(n);
	size = vector<int>(n);
	link = vector<int>(n);
	vector<int>cont(n);

	// Le relacões
	for(int i=0;i<n;i++){
		cin >> v[i];
		size[i] = 1;
		link[i] = i;
	}

	// Cria a DSU
	while(q--){
		cin >> a >> b;

		unite(a - 1,b - 1);
	}

	// Coloca os elementos do subgrafo na respectiva chave.
	for(int i=0;i<n;i++){
		ma[find(i)].push_back(v[i]);
	}


	// Ordena cada subgrafo baseado;
	for(map<int,vector<int>>::iterator it = ma.begin();it != ma.end();it++){
			sort(it->second.begin(), it->second.end());
	}


	// mostra o menor elemento disponível daqule subgrafo
	for(int i=0;i<n;i++){
		cout << ma[find(i)][cont[find(i)]++] << " ";
	}

}

int main(){


	int n;
	cin >> n;

	while(n--) solve();

	return 0;
}