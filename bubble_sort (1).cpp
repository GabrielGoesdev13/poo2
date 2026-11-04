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

void bubbleSort(int arr[], int n, int &comparacoes, int &trocas) {
    for (int i = 0; i < n - 1; i++) {
        bool trocou = false;
        cout << "Passagem " << i + 1 << endl;
        for (int j = 0; j < n - i - 1; j++) {
            comparacoes++;
            cout << "  j=" << j << " compara " << arr[j] << " > " << arr[j + 1];
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                trocas++;
                trocou = true;
                cout << " -> troca ";
            } else {
                cout << " -> nao troca ";
            }
            imprimir(arr, n);
            cout << endl;
        }
        if (!trocou) {
            break;
        }
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

    bubbleSort(arr, n, comparacoes, trocas);

    cout << endl << "Array final: ";
    imprimir(arr, n);
    cout << endl;
    cout << "Comparacoes: " << comparacoes << endl;
    cout << "Trocas: " << trocas << endl;
    return 0;
}
