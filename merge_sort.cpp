#include <iostream>
#include <vector>
using namespace std;

void imprimir(int arr[], int n) {
    cout << "[ ";
    for (int k = 0; k < n; k++) {
        cout << arr[k] << " ";
    }
    cout << "]";
}

void imprimirVetor(const vector<int> &v) {
    cout << "[ ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << "]";
}

void merge(int arr[], int n, int l, int m, int r, int &comparacoes, int &trocas) {
    vector<int> L(arr + l, arr + m + 1);
    vector<int> R(arr + m + 1, arr + r + 1);
    cout << "  merge: L=";
    imprimirVetor(L);
    cout << " R=";
    imprimirVetor(R);
    cout << endl;
    int i = 0, j = 0, k = l;
    while (i < (int)L.size() && j < (int)R.size()) {
        comparacoes++;
        cout << "    compara " << L[i] << " <= " << R[j];
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
            cout << " -> copia " << arr[k - 1] << " de L" << endl;
        } else {
            arr[k++] = R[j++];
            cout << " -> copia " << arr[k - 1] << " de R" << endl;
        }
        trocas++;
    }
    while (i < (int)L.size()) {
        arr[k++] = L[i++];
        trocas++;
        cout << "    sobrou em L, copia " << arr[k - 1] << endl;
    }
    while (j < (int)R.size()) {
        arr[k++] = R[j++];
        trocas++;
        cout << "    sobrou em R, copia " << arr[k - 1] << endl;
    }
    cout << "  resultado: ";
    imprimir(arr, n);
    cout << endl;
}

void mergeSort(int arr[], int n, int l, int r, int &comparacoes, int &trocas) {
    if (l < r) {
        int m = l + (r - l) / 2;
        cout << "divide [" << l << ".." << r << "] em [" << l << ".." << m << "] e [" << m + 1 << ".." << r << "]" << endl;
        mergeSort(arr, n, l, m, comparacoes, trocas);
        mergeSort(arr, n, m + 1, r, comparacoes, trocas);
        cout << "junta [" << l << ".." << m << "] com [" << m + 1 << ".." << r << "]" << endl;
        merge(arr, n, l, m, r, comparacoes, trocas);
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

    mergeSort(arr, n, 0, n - 1, comparacoes, trocas);

    cout << endl << "Array final: ";
    imprimir(arr, n);
    cout << endl;
    cout << "Comparacoes: " << comparacoes << endl;
    cout << "Trocas (copias para o array): " << trocas << endl;
    return 0;
}
