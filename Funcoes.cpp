#include "Funcoes.h"
#include <map>
#include <string>
#include <cstdio>   // para FILE*, fprintf, popen, pclose
#include <iostream>

int buscaSequencialInversa(int v[], int n, int x) {
    for (int i = n - 1; i >= 0; i--) {
        if (v[i] == x) {
            return i;
        }
    }
    return -1;
}

int buscaBinaria(int v[], int n, int x) {
    int inicio = 0;
    int fim = n - 1;
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (v[meio] == x) {
            return meio;
        }
        if (v[meio] < x) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }
    return -1;
}

void gerarGrafico(const string& titulo, const map<int, double>& dados) {
    FILE* gnuplotPipe = popen("gnuplot -persistent", "w");
    if (!gnuplotPipe) {
        cerr << "Erro ao abrir gnuplot" << endl;
        return;
    }

    fprintf(gnuplotPipe, "set title '%s'\n", titulo.c_str());
    fprintf(gnuplotPipe, "set xlabel 'Tamanho do Array (N)'\n");
    fprintf(gnuplotPipe, "set ylabel 'Tempo Medio (ms)'\n");
    fprintf(gnuplotPipe, "set grid\n");
    fprintf(gnuplotPipe, "plot '-' with linespoints title '%s'\n", titulo.c_str());

    for (auto& par : dados) {
        fprintf(gnuplotPipe, "%d %f\n", par.first, par.second);
    }
    fprintf(gnuplotPipe, "e\n");  
    fflush(gnuplotPipe);          

    pclose(gnuplotPipe);
}