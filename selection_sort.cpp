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

void selectionSort(int arr[], int n, int &comparacoes, int &trocas) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        cout << "Passagem " << i + 1 << " (inicio em i=" << i << ")" << endl;
        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            cout << "  j=" << j << " compara " << arr[j] << " < " << arr[minIdx];
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
                cout << " -> novo minimo na posicao " << minIdx << endl;
            } else {
                cout << " -> mantem minimo na posicao " << minIdx << endl;
            }
        }
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
            trocas++;
            cout << "  troca posicoes " << i << " e " << minIdx << " -> ";
        } else {
            cout << "  sem troca -> ";
        }
        imprimir(arr, n);
        cout << endl;
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

    selectionSort(arr, n, comparacoes, trocas);

    cout << endl << "Array final: ";
    imprimir(arr, n);
    cout << endl;
    cout << "Comparacoes: " << comparacoes << endl;
    cout << "Trocas: " << trocas << endl;
    return 0;
}
