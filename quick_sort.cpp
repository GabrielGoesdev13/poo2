#include <iostream>
#include <utility>
using namespace std;

void imprimir(int arr[], int n) {
    cout << "[ ";
    for (int k = 0; k < n; k++) {
        cout << arr[k] << " ";
    }
    cout << "]";
}

int partition(int arr[], int n, int lo, int hi, int &comparacoes, int &trocas) {
    int pivot = arr[hi];
    int i = lo - 1;
    cout << "  partition [" << lo << ".." << hi << "] pivo = " << pivot << endl;
    for (int j = lo; j < hi; j++) {
        comparacoes++;
        cout << "    j=" << j << " compara " << arr[j] << " <= " << pivot;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
            trocas++;
            cout << " -> troca pos " << i << " e " << j << " ";
            imprimir(arr, n);
            cout << endl;
        } else {
            cout << " -> nao troca" << endl;
        }
    }
    swap(arr[i + 1], arr[hi]);
    trocas++;
    cout << "    coloca o pivo: troca pos " << i + 1 << " e " << hi << " ";
    imprimir(arr, n);
    cout << endl;
    return i + 1;
}

void quickSort(int arr[], int n, int lo, int hi, int &comparacoes, int &trocas) {
    if (lo < hi) {
        int p = partition(arr, n, lo, hi, comparacoes, trocas);
        cout << "  pivo fica na posicao " << p << endl;
        quickSort(arr, n, lo, p - 1, comparacoes, trocas);
        quickSort(arr, n, p + 1, hi, comparacoes, trocas);
    }
}

int main() {
    int arr[] = {5, 3, 8, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparacoes = 0;
    int trocas = 0;

    cout << "Array inicial: ";
    imprimir(arr, n);
    cout << endl << endl;

    quickSort(arr, n, 0, n - 1, comparacoes, trocas);

    cout << endl << "Array final: ";
    imprimir(arr, n);
    cout << endl;
    cout << "Comparacoes: " << comparacoes << endl;
    cout << "Trocas: " << trocas << endl;
    return 0;
}
