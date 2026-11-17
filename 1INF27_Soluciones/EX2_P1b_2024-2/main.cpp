/* TATIANA AVILA ARAUCO */

#include <iostream>
using namespace std;
#define N 5
struct Plato {
    string nombre;
    int cantidadDisponible;
    int cantidadReservada;
    double porcentajeReservas;
};
void intercambiar(Plato &datoI, Plato &datoJ) {
    Plato aux = datoI;
    datoI = datoJ;
    datoJ = aux;
}
int particion(Plato *arr, int ini, int fin) {
    double pivot = arr[fin].porcentajeReservas;
    int i=ini-1;
    for (int j=ini; j<fin; j++)
        if (arr[j].porcentajeReservas > pivot)
            intercambiar(arr[++i], arr[j]);
    intercambiar(arr[i+1],arr[fin]);
    return i+1;
}
void quicksort(Plato *arr, int ini, int fin) {
    if (ini>=fin) return;
    int p = particion(arr, ini, fin);
    quicksort(arr, ini, p-1);
    quicksort(arr, p+1, fin);
}
int main() {
    Plato arreglo[N] = {
        {"Lomo Saltado", 50, 30},
        {"Ceviche", 40, 35},
        {"Ají de Gallina", 30, 10},
        {"Causa Limena", 20, 20},
        {"Arroz con Pollo", 60, 45}
    };

    for (int i = 0; i < N; i++)
        arreglo[i].porcentajeReservas = arreglo[i].cantidadReservada * 100.0 / arreglo[i].cantidadDisponible;

    quicksort(arreglo, 0, N - 1);

    cout << "Top 3 platos con mayor porcentaje de reservas:" << endl;
    for (int i = 0; i < 3; i++)
        cout << arreglo[i].nombre << " - " << arreglo[i].porcentajeReservas << "%" << endl;
    return 0;
}