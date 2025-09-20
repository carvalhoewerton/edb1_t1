#ifndef FUNCOES_H
#define FUNCOES_H

#include <chrono>
#include <map>
#include <string>
#include <vector>
#include <algorithm>  // para std::sort


using namespace std;

//Algoritmos de busca escolhidos
int buscaSequencialInversa(int v[], int n, int x);
int buscaBinaria(int v[], int n, int x);

//Função para gerar o gráfico 
void gerarGrafico(const string& titulo, const map<int, double>& dados);

//Função para medir o tempo de execução
template <typename Func, typename... Args>
double medirTempo(Func func, Args... args) {
    const int N = 10000; 
    double total = 0.0;
    vector<double> temposIndividuais;
    
    for (int i = 0; i < N; ++i) {
        auto inicio = chrono::high_resolution_clock::now();
        func(args...);
        auto fim = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duracao = fim - inicio;
        temposIndividuais.push_back(duracao.count());
    }

    sort(temposIndividuais.begin(), temposIndividuais.end());
    return temposIndividuais[N/2]; 
}


//Função para testar o algoritmo com diferentes tamanhos de array e gerar o map para o gráfico
template<typename Func>
map<int, double> testarAlgoritmo(Func algoritmo, const int tamanhos[], int qtdTamanhos, int elementoProcurado) {
    map<int, double> tempos;
    for(int i = 0; i < qtdTamanhos; i++){
        int n = tamanhos[i];
        vector<int> array(n);
        for(int j = 0; j < n; j++) {
            array[j] = j + 1;
        }
        double tempo = medirTempo(algoritmo, array.data(), n, elementoProcurado);
        tempos[n] = tempo;
    }
    return tempos;
}

#endif