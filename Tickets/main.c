#include <stdio.h>
#include "funciones.h"

int main(int argc, char *argv[]) {
    char peliculas[10][4][40];
    double precio[3] = {7, 3.5, 3};
    char clientes[5][2][40];
    int reserva[10][4];

    cargarPeliculas(peliculas);
    cargarClientes(clientes);
    cargarReservas(reserva);

    int opcion1 = 0, opcion2 = 0, opcion3 = 0;

    do {
        printf("Escoja una opcion:\n");
        printf("1. Ingresar Cliente\n");
        printf("2. Ver Peliculas\n");
        printf("3. Buscar Pelicula\n");
        printf("4. Comprar Ticket\n");
        printf("5. Ver Compras\n>> ");
        scanf("%d", &opcion2);

        switch (opcion2) {
            case 1:
                ingresarCliente(clientes);
                guardarClientes(clientes);
                break;
            case 2:
                listarPeliculas(peliculas);
                break;
            case 3:
                printf("1. Por nombre\n");
                printf("2. Por Genero\n>> ");
                scanf("%d", &opcion3);
                switch (opcion3) {
                    case 1:
                        buscarporNombre(peliculas);
                        break;
                    case 2:
                        buscarporGenero(peliculas);
                        break;
                    default:
                        printf("Opcion no valida.\n");
                        break;
                }
                break;
            case 4:
                comprarTicket(peliculas, precio, clientes, reserva);
                guardarReservas(reserva);
                break;
            case 5:
                verCompras(peliculas, precio, clientes, reserva);
                break;
            default:
                printf("Opcion no valida.\n");
                break;
        }

        printf("Desea escoger una nueva opcion: 1.Si / 2.No\n>> ");
        scanf("%d", &opcion1);

    } while (opcion1 == 1);

    return 0;
}
