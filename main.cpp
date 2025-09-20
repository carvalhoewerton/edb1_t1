#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "Funcoes.h"
using namespace std;

int main() {
    int tamanhos[] = {1000, 2000, 5000, 10000, 20000, 50000};
    int qtdTamanhos = sizeof(tamanhos)/sizeof(tamanhos[0]);
    int elementoPiorCaso = 1;

    cout << "Testando Busca Sequencial Inversa...\n";
    map<int, double> temposSequencial = testarAlgoritmo(buscaSequencialInversa, tamanhos, qtdTamanhos, elementoPiorCaso);
    gerarGrafico("Busca Sequencial Inversa (Pior Caso)", temposSequencial);

    cout << "\nTestando Busca Binaria...\n";
    map<int, double> temposBinaria = testarAlgoritmo(buscaBinaria, tamanhos, qtdTamanhos, elementoPiorCaso);
    gerarGrafico("Busca Binaria (Pior Caso)", temposBinaria);

    return 0;
}