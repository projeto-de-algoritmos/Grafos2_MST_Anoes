#include <bits/stdc++.h>

using namespace std;
  
// Link do accepted: https://www.urionlinejudge.com.br/judge/pt/runs/code/24099743

bool solve(){

	// Inicializando variaveis independentes
	int n, m, a, b, c;
	long long int soma = 0;
	priority_queue<pair<int,int>> mypq;
	
	// leitura
	cin >> n >> m;

	//Critério de parada
	if(n==0 and m==0)
		return false;

	// Inicializando variaveis dependentes
	vector<vector<pair<int,int>>>v(n);
	vector<bool>verified(n, false);

	// Criando a árvore de adjacencia
	for(int i=0;i<m;i++){
		cin >> a >> b >> c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
		soma+=c;
	}

	// Colocando o elemento inicial para o algoritmo de Prim
	mypq.push(make_pair(0,0));

	// Criando variavel auxiliar que vai servir como temporaria
	pair<int,int> aux;

	// Algoritmo de Prim
	while(mypq.empty() != true){

		// Pego o elemento com menor estrada disponível.
		aux = mypq.top();

		// Retiro elemento da fila
		mypq.pop();

		// Se o elemento já foi verificado vai para o próximo
		if(verified[aux.second]){
			continue;
		}

		// Ilumina a rua ! LEIA A QUESTAO
		soma += aux.first;
		verified[aux.second] = true;

		// Coloca todos os elementos que tem adjacencia na fila.
		for(int i=0;i<v[aux.second].size();i++){
			mypq.push({-1*v[aux.second][i].second, v[aux.second][i].first});
		}


	}

		cout << soma << endl;
		return true;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(solve()){};

	return 0;
}