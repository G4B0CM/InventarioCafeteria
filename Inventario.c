#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Funciones.h"
int main()
{
    int ops, flag;
    int totalProductos = 5;
    int identificacion[10] = {1, 2, 3, 4, 5};
    char nombre[10][10] = {{"Leche"}, {"Cafe"}, {"Cacao"}, {"Azucar"}, {"Azucar"}};
    char descripcion[10][15] = {{"Lacteo"}, {"Polvo"}, {"Polvo"}, {"Blanca"}, {"Morena"}};
    float cantidad[10] = {10, 15, 12, 10, 5};
    char unidades[10][10] = {{"Litros"}, {"Bolsa"}, {"Bolsa"}, {"Kilos"}, {"Kilos"}};
    float precio[10] = {2.5, 5, 4.5, 1.5, 2};
    float preciot[10];
    while (flag)
    {
        system("cls");
        ops = imprimirMenu();
        switch (ops)
        {
        case 1:
            system("cls");
            imprimirProductos(identificacion, nombre, descripcion, cantidad, unidades, precio, totalProductos, preciot);
            break;
        case 2:
            system("cls");
            leerProducto(identificacion, nombre, descripcion, cantidad, unidades, precio, totalProductos);
            totalProductos++;
            break;
        case 3:
            modificarProducto(identificacion, nombre, descripcion, cantidad, unidades, precio);
            break;
        case 4:
            eliminarProducto(identificacion, nombre, descripcion, cantidad, unidades, precio, totalProductos, preciot);
            totalProductos--;
            break;
        case 5:
            flag = 0;
            break;
        default:
            system("cls");
            printf("Digite una opcion valida\n");
            siguiente();
            break;
        }
    }
    printf("Gracias por utilizar el sistema de inventarios\n");
    siguiente();
    return 0;
}
