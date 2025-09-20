# Análise de Algoritmos de Busca: Sequencial vs. Binária

## Sobre o Projeto

Este projeto foi desenvolvido para a disciplina de Estruturas de Dados Básicas 2/IMD e tem como objetivo analisar e comparar o desempenho de dois algoritmos de busca clássicos, a **busca sequencial** e a **busca binária**. O trabalho consiste em implementar os algoritmos em C++ e, através de testes de tempo de execução, gerar gráficos que mostram o comportamento de cada um.

## Algoritmos Analisados

-   **Busca Sequencial (Linear):** A complexidade teórica é **O(N)**. O tempo de execução cresce linearmente com o tamanho do array.

-   **Busca Binária:** Para arrays ordenados, sua complexidade teórica é **O(log N)**. O tempo de execução cresce muito lentamente com o tamanho do array.

---

## Pré-requisitos

Para compilar e executar este projeto, você precisa ter instalados:

-   Um compilador C++ (como o **g++**)
-   O software de gráficos **Gnuplot**

---

## Como Compilar e Executar

1.  **Compile o Código:**
    Utilize o seguinte comando para compilar os arquivos e criar o executável:
    ```bash
    g++ -std=c++17 main.cpp Funcoes.cpp -o nome_do_executavel
    ```

2.  **Execute o Programa:**
    Após a compilação, você pode rodar o programa com o comando:
    ```bash
    ./nome_do_executavel
    ```
    Isso executará os testes e abrirá as janelas do Gnuplot com os gráficos de desempenho.

---


