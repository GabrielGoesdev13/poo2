# Algoritmos de Ordenação em C++

Atividade da Aula 19 de PSC II (Prof. Giovane Galvão), Engenharia de Software, Centro Universitário Campo Real.

Aqui estão cinco algoritmos de ordenação implementados em C++, cada um contando quantas comparações e quantas trocas faz para ordenar o array de entrada.

## Arquivos

| Arquivo | Algoritmo |
|---|---|
| `bubble_sort.cpp` | Bubble Sort |
| `selection_sort.cpp` | Selection Sort |
| `insertion_sort.cpp` | Insertion Sort |
| `merge_sort.cpp` | Merge Sort |
| `quick_sort.cpp` | Quick Sort |
| `testes_de_mesa.pdf` | Testes de mesa com o passo a passo de cada algoritmo |

## Como compilar e executar

Precisa do compilador `g++`. Exemplo com o Bubble Sort:

```
g++ bubble_sort.cpp -o bubble_sort
./bubble_sort
```

Para os outros, é só trocar o nome do arquivo. Cada programa mostra o array a cada passo e, no final, o total de comparações e de trocas.

## Entrada usada nos testes

Todos usam o mesmo array: `[5, 3, 8, 1, 2]`

## Resultados

| Algoritmo | Comparações | Trocas |
|---|---|---|
| Bubble Sort | 10 | 7 |
| Selection Sort | 10 | 3 |
| Insertion Sort | 9 | 7 |
| Merge Sort | 6 | 12 |
| Quick Sort | 7 | 5 |

## Como as trocas foram contadas

- **Bubble, Selection e Quick Sort:** cada chamada de `swap` conta como uma troca. No Quick Sort isso inclui o `swap` de um elemento com ele mesmo.
- **Insertion Sort:** cada deslocamento de elemento para a direita conta como uma troca.
- **Merge Sort:** cada cópia de valor das listas auxiliares para o array conta como uma troca.
- **Quick Sort:** o pivô é sempre o último elemento (sem `rand()`), para o resultado ser sempre o mesmo.
