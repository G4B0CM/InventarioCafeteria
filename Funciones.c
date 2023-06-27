#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
int imprimirMenu()
{
    int ops;
    printf("---------------Bienvenido---------------\n");
    printf("Men%c de la herramienta de inventario\n", 163);
    printf("Seleccione una opci%cn: \n", 162);
    printf("\t1) Ver productos\n");
    printf("\t2) Ingreso de producto\n");
    printf("\t3) Modificar productos\n");
    printf("\t4) Eliminar producto\n");
    printf("\t5) Salir\n");
    printf("Selecione una opcion: ");
    scanf("%d", &ops);
    return ops;
}
void modificarProducto(int identificacion[10], char nombre[10][10], char descripcion[10][15],
                       float cantidad[10], char unidades[10][10], float precio[10])
{
    int id;
    printf("---- Modificar Producto ----\n");
    printf("Ingrese el Id del producto a modificar: ");
    scanf("%i", &id);
    printf("Nuevo nombre: ");
    scanf(" %s", nombre[id - 1]);
    printf("Nueva Descripcion: ");
    scanf(" %s", descripcion[id - 1]);
    printf("Nueva Cantidad: ");
    scanf("%f", &cantidad[id - 1]);
    printf("Nuevas Unidades:");
    scanf(" %s", unidades[id - 1]);
    printf("Nuevo Precio: ");
    scanf("%f", &precio[id - 1]);
}
void eliminarProducto(int identificacion[10], char nombre[10][10], char descripcion[10][15],
                      float cantidad[10], char unidades[10][10], float precio[10], int tot, float preciot[10])
{
    int id;
    printf("---- Eliminar Producto ----\n");
    printf("Ingrese el ID del producto a eliminar: ");
    scanf("%d", &id);
    for (int i = 0; i < tot; i++)
    {
        if (identificacion[i] == id)
        {
            for (int j = i; j < tot - 1; j++)
            {
                identificacion[j] = identificacion[j + 1];
                strcpy(nombre[j], nombre[j + 1]);
                strcpy(descripcion[j], descripcion[j + 1]);
                cantidad[j] = cantidad[j + 1];
                strcpy(unidades[j], unidades[j + 1]);
                precio[j] = precio[j + 1];
            }
        }
    }
    preciot[id - 1] = 0;
}
void siguiente()
{
    printf("Presione una tecla para continuar:");
    getch();
}
void leerProducto(int identificacion[10], char nombre[10][10], char descripcion[10][15],
                  float cantidad[10], char unidades[10][10], float precio[10], int tot)
{
    int ops;
    printf("---- Ingresar Producto ----\n");
    printf("Nombre: ");
    scanf(" %s", nombre[tot]);
    printf("Descripcion: ");
    scanf(" %s", descripcion[tot]);
    printf("Cantidad: ");
    scanf("%f", &cantidad[tot]);
    printf("Unidades:");
    scanf(" %s", unidades[tot]);
    printf("Precio: ");
    scanf("%f", &precio[tot]);
    printf("El identificador del nuevo producto es: 000%i\n", tot + 1);
    identificacion[tot] = tot + 1;
    siguiente();
}
void imprimirProductos(int identificacion[10], char nombre[10][10], char descripcion[10][15],
                       float cantidad[10], char unidades[10][10], float precio[10], int tot, float preciot[10])
{
    printf("ID\t Nombre\t Descripcion\t Cantidad\t Unidades\t Precio\t $Total\n");
    float total;
    for (int i = 0; i < tot; i++)
    {
        preciot[i] = cantidad[i] * precio[i];
        printf("000%i\t %s\t %s\t\t %.2f\t\t %s\t\t %.2f$\t %.2f$\n", identificacion[i], nombre[i], descripcion[i],
               cantidad[i], unidades[i], precio[i], preciot[i]);
    }
    for (int j = 0; j < tot; j++)
    {
        total += preciot[j];
    }
    printf("\t\t\t\t\t\t\t\t TOTAL: %.2f$\n", total);
    siguiente();
}