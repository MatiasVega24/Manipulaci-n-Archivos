#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define ARCHIVO_PELICULAS "peliculas.txt"
#define ARCHIVO_CLIENTES "clientes.txt"
#define ARCHIVO_RESERVAS "reservas.txt"

void cargarPeliculas(char peliculas[][4][40]) {
    FILE *file = fopen(ARCHIVO_PELICULAS, "r");
    if (file == NULL) {
        printf("Error al abrir el archivo de peliculas.\n");
        return;
    }
    for (int i = 0; i < 10; i++) {
        fscanf(file, "%s %s %s %s", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
    }
    fclose(file);
}

void guardarPeliculas(char peliculas[][4][40]) {
    FILE *file = fopen(ARCHIVO_PELICULAS, "w");
    if (file == NULL) {
        printf("Error al abrir el archivo de peliculas.\n");
        return;
    }
    for (int i = 0; i < 10; i++) {
        fprintf(file, "%s %s %s %s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
    }
    fclose(file);
}

void cargarClientes(char clientes[][2][40]) {
    FILE *file = fopen(ARCHIVO_CLIENTES, "r");
    if (file == NULL) {
        printf("Error al abrir el archivo de clientes.\n");
        return;
    }
    for (int i = 0; i < 5; i++) {
        fscanf(file, "%s %s", clientes[i][0], clientes[i][1]);
    }
    fclose(file);
}

void guardarClientes(char clientes[][2][40]) {
    FILE *file = fopen(ARCHIVO_CLIENTES, "w");
    if (file == NULL) {
        printf("Error al abrir el archivo de clientes.\n");
        return;
    }
    for (int i = 0; i < 5; i++) {
        fprintf(file, "%s %s\n", clientes[i][0], clientes[i][1]);
    }
    fclose(file);
}

void cargarReservas(int reserva[][4]) {
    FILE *file = fopen(ARCHIVO_RESERVAS, "r");
    if (file == NULL) {
        printf("Error al abrir el archivo de reservas.\n");
        return;
    }
    for (int i = 0; i < 10; i++) {
        fscanf(file, "%d %d %d %d", &reserva[i][0], &reserva[i][1], &reserva[i][2], &reserva[i][3]);
    }
    fclose(file);
}

void guardarReservas(int reserva[][4]) {
    FILE *file = fopen(ARCHIVO_RESERVAS, "w");
    if (file == NULL) {
        printf("Error al abrir el archivo de reservas.\n");
        return;
    }
    for (int i = 0; i < 10; i++) {
        fprintf(file, "%d %d %d %d\n", reserva[i][0], reserva[i][1], reserva[i][2], reserva[i][3]);
    }
    fclose(file);
}

void ingresarCliente(char clientes[][2][40]) {
    for (int i = 0; i < 5; i++) {
        if (strcmp(clientes[i][0], "VACIO") == 0) {
            printf("Ingrese nombre del nuevo cliente: ");
            scanf("%s", clientes[i][0]);
            printf("Ingrese cedula del nuevo cliente: ");
            scanf("%s", clientes[i][1]);
            break;
        }
    }
    imprimirClientes(clientes);
}

void imprimirClientes(char clientes[][2][40]) {
    for (int i = 0; i < 5; i++) {
        printf("%s\t\t%s\n", clientes[i][0], clientes[i][1]);
    }
}

void listarPeliculas(char peliculas[][4][40]) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(peliculas[i][0], "VACIO") != 0) {
            printf("ID: %s, Titulo: %s, Hora: %s, Genero: %s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
        }
    }
}

void buscarporNombre(char peliculas[][4][40]) {
    char nombre[40];
    printf("Ingrese el nombre de la pelicula: ");
    scanf("%s", nombre);
    for (int i = 0; i < 10; i++) {
        if (strcmp(peliculas[i][1], nombre) == 0) {
            printf("Pelicula encontrada: ID: %s, Titulo: %s, Hora: %s, Genero: %s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
            return;
        }
    }
    printf("Pelicula no encontrada.\n");
}

void buscarporGenero(char peliculas[][4][40]) {
    char genero[40];
    printf("Ingrese el genero de la pelicula: ");
    scanf("%s", genero);
    for (int i = 0; i < 10; i++) {
        if (strcmp(peliculas[i][3], genero) == 0) {
            printf("Pelicula encontrada: ID: %s, Titulo: %s, Hora: %s, Genero: %s\n", peliculas[i][0], peliculas[i][1], peliculas[i][2], peliculas[i][3]);
            return;
        }
    }
    printf("Pelicula no encontrada.\n");
}

void comprarTicket(char peliculas[][4][40], double precio[], char clientes[][2][40], int reserva[][4]) {
    int idPelicula, tipoTicket, clienteIndex;

    listarPeliculas(peliculas);
    printf("Ingrese el ID de la pelicula: ");
    scanf("%d", &idPelicula);

    if (idPelicula < 1 || idPelicula > 10 || strcmp(peliculas[idPelicula - 1][0], "VACIO") == 0) {
        printf("ID de pelicula no valido.\n");
        return;
    }

    printf("Tipos de ticket:\n");
    printf("0: General ($7.00)\n");
    printf("1: Niño ($3.50)\n");
    printf("2: Mayor de 60 ($3.00)\n");
    printf("Ingrese el tipo de ticket: ");
    scanf("%d", &tipoTicket);

    if (tipoTicket < 0 || tipoTicket > 2) {
        printf("Tipo de ticket no valido.\n");
        return;
    }

    imprimirClientes(clientes);
    printf("Ingrese el indice del cliente (1-5): ");
    scanf("%d", &clienteIndex);

    if (clienteIndex < 1 || clienteIndex > 5 || strcmp(clientes[clienteIndex - 1][0], "VACIO") == 0) {
        printf("Indice de cliente no valido.\n");
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (reserva[i][0] == -1) {
            reserva[i][0] = idPelicula - 1;
            reserva[i][1] = clienteIndex - 1;
            reserva[i][2] = tipoTicket;
            reserva[i][3] = 1;
            printf("Ticket comprado exitosamente!\n");
            return;
        }
    }

    printf("No hay espacio para mas reservas.\n");
}

void verCompras(char peliculas[][4][40], double precio[], char clientes[][2][40], int reserva[][4]) {
    printf("Listado de compras:\n");
    for (int i = 0; i < 10; i++) {
        if (reserva[i][0] != -1) {
            int idPelicula = reserva[i][0];
            int clienteIndex = reserva[i][1];
            int tipoTicket = reserva[i][2];
            printf("Cliente: %s, Pelicula: %s, Hora: %s, Genero: %s, Tipo de ticket: %s, Precio: $%.2f\n",
                   clientes[clienteIndex][0],
                   peliculas[idPelicula][1],
                   peliculas[idPelicula][2],
                   peliculas[idPelicula][3],
                   tipoTicket == 0 ? "General" : (tipoTicket == 1 ? "Niño" : "Mayor de 60"),
                   precio[tipoTicket]);
        }
    }
}
