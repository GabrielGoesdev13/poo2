#include <iostream>
using namespace std;

void imprimir(int arr[], int n) {
    cout << "[ ";
    for (int k = 0; k < n; k++) {
        cout << arr[k] << " ";
    }
    cout << "]";
}

void insertionSort(int arr[], int n, int &comparacoes, int &trocas) {
    for (int i = 1; i < n; i++) {
        int chave = arr[i];
        int j = i - 1;
        cout << "Passagem " << i << " (chave = " << chave << ")" << endl;
        while (j >= 0) {
            comparacoes++;
            cout << "  j=" << j << " compara " << arr[j] << " > " << chave;
            if (arr[j] > chave) {
                arr[j + 1] = arr[j];
                trocas++;
                j--;
                cout << " -> desloca ";
                imprimir(arr, n);
                cout << endl;
            } else {
                cout << " -> para" << endl;
                break;
            }
        }
        arr[j + 1] = chave;
        cout << "  insere " << chave << " na posicao " << j + 1 << " -> ";
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

    insertionSort(arr, n, comparacoes, trocas);

    cout << endl << "Array final: ";
    imprimir(arr, n);
    cout << endl;
    cout << "Comparacoes: " << comparacoes << endl;
    cout << "Trocas (deslocamentos): " << trocas << endl;
    return 0;
}
