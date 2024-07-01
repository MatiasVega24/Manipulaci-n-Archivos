#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PRODUCTOS 20
#define NOMBRE_ARCHIVO "inventario.txt"

char productos[MAX_PRODUCTOS][30] = {"zapatos","balones","gorras","shorts","hoodies","medias"};
int elementosdefault = 6;
float precios[MAX_PRODUCTOS] = {50.0,20.0,15.0,20.0,60.0,10.0};
int cantidades[MAX_PRODUCTOS] = {19,25,8,40,5,10};

void Menu();

void limpiarconsola(){
    system("clear");
}

void CargarDatos() {
    FILE *file = fopen(NOMBRE_ARCHIVO, "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo %s. Usando datos por defecto.\n", NOMBRE_ARCHIVO);
        return;
    }

    fscanf(file, "%d", &elementosdefault);
    for (int i = 0; i < elementosdefault; i++) {
        fscanf(file, "%s %f %d", productos[i], &precios[i], &cantidades[i]);
    }

    fclose(file);
}

void GuardarDatos() {
    FILE *file = fopen(NOMBRE_ARCHIVO, "w");
    if (file == NULL) {
        printf("No se pudo abrir el archivo %s para escribir.\n", NOMBRE_ARCHIVO);
        return;
    }

    fprintf(file, "%d\n", elementosdefault);
    for (int i = 0; i < elementosdefault; i++) {
        fprintf(file, "%s %.2f %d\n", productos[i], precios[i], cantidades[i]);
    }

    fclose(file);
}

void EditarProducto(){
    limpiarconsola();
    int indice = -1;
    char nuevoproducto[30];
    float precio;
    int cantidad;
    char conf;
    printf("Producto           Precio     Cantidad\n");
    for (int l = 0; l < elementosdefault; l++) {
        printf("%d. --%s--\t\t", l + 1, productos[l]);
        printf("%.2f\t", precios[l]);
        printf("    %d\t\t\n", cantidades[l]);
    }

    printf("\n\nIngrese el número del producto a editar\n");
    scanf("%d", &indice);
    indice--; // Ajustar para índice basado en 0

    if (indice >= 0 && indice < elementosdefault) {
        printf("Se encontró el producto\n");

        printf("¿Quiere cambiar el producto? S/N\n");
        getchar(); 
        scanf("%c", &conf);
        
        if (tolower(conf) == 's') {
            printf("--Ingrese el producto nuevo:-- \n");
            scanf("%s", nuevoproducto);
            strcpy(productos[indice], nuevoproducto);
        }

        printf("¿Quiere cambiar el precio del producto? S/N\n");
        getchar(); 
        scanf("%c", &conf);

        if (tolower(conf) == 's') {
            printf("--Ingrese el precio del producto nuevo:-- \n");
            scanf("%f", &precio);
            precios[indice] = precio;
        }

        printf("¿Quiere cambiar la cantidad del producto? S/N\n");
        getchar(); 
        scanf("%c", &conf);

        if (tolower(conf) == 's') {
            printf("--Ingrese la cantidad del producto nuevo:-- \n");
            scanf("%d", &cantidad);
            cantidades[indice] = cantidad;
        }
        
        printf("Se editó con éxito\n");
    } else {
        printf("No se encontró el producto indicado\n");
    }

    printf("Presione cualquier tecla para continuar...\n");
    getchar();
    getchar(); 
    limpiarconsola();
}

void ImprimirInventario(){
    limpiarconsola();
    printf("Producto           Precio     Cantidad\n");
    for (int l = 0; l < elementosdefault; l++) {
        printf("%d. --%s--\t\t", l + 1, productos[l]);
        printf("%.2f\t", precios[l]);
        printf("    %d\t\t\n", cantidades[l]);
    }
    printf("\n\nPresione enter para volver\n");
    getchar();
    getchar();
    limpiarconsola();
}

void IngresarProductos (){
    limpiarconsola();
    char a = 's';
    if (elementosdefault != MAX_PRODUCTOS) {
        while (a == 's') {
            char nuevoproducto[30];
            float precio;
            int cantidad; 
            printf("\n\n\n\n--Ingrese el producto nuevo:-- \n");
            scanf("%s", nuevoproducto);
            for (int i = 0; i < elementosdefault; i++) {
                if (strcmp(nuevoproducto, productos[i]) == 0) {
                    printf("El producto ya existe\n");
                    printf("Presione enter para volver\n");
                    getchar();
                    getchar();
                    return;
                }
            }
            getchar();
            printf("--Ingrese el precio del producto nuevo:-- \n");
            scanf("%f", &precio);
            printf("--Ingrese la cantidad del producto nuevo:-- \n");
            scanf("%d", &cantidad);
            getchar();
            strcpy(productos[elementosdefault], nuevoproducto);
            precios[elementosdefault] = precio;
            cantidades[elementosdefault] = cantidad;
            elementosdefault++;
            printf("Desea ingresar más productos? S/N\n");
            scanf("%c", &a);
            a = tolower(a);
            limpiarconsola();
        }
    } else {
        printf("El número máximo de productos es %d\n\n", MAX_PRODUCTOS);
    }
    limpiarconsola();
}

void EliminarProductos() {
    limpiarconsola();
    int indice;
    printf("Ingrese el número del producto que desea eliminar:\n");
    scanf("%d", &indice);
    indice--; // Ajustar para índice basado en 0

    if (indice >= 0 && indice < elementosdefault) {
        elementosdefault--;
        for (int j = indice; j < elementosdefault; j++) {
            strcpy(productos[j], productos[j + 1]);
            precios[j] = precios[j + 1];
            cantidades[j] = cantidades[j + 1];
        }
        printf("\nSe eliminó con éxito\n\n");
    } else {
        printf("No se encontró el producto indicado\n");
    }

    ImprimirInventario();
}

void Facturacion() {
    limpiarconsola();
    int indice, cantidad = 0, indicador = 0;
    char opcion = 's';
    char facturacionP[20][30];
    int facturacionC[20]; 
    float multiplicacion[20], acumulador = 0, facturacionPr[20];

    while (tolower(opcion) == 's') {
        printf("Producto           Precio     Cantidad\n");
        for (int l = 0; l < elementosdefault; l++) {
            printf("%d. --%s--\t\t", l + 1, productos[l]);
            printf("%.2f\t", precios[l]);
            printf("    %d\t\t\n", cantidades[l]);
        }
        printf("Indique el número del producto que quiere\n");
        scanf("%d", &indice);
        getchar();
        indice--; // Ajustar para índice basado en 0

        if (indice >= 0 && indice < elementosdefault) {
            printf("El costo del producto es: %.2f, indique cuántas unidades quiere\n", precios[indice]);
            scanf("%d", &cantidad);
            getchar();

            if (cantidad > cantidades[indice]) {
                printf("Superó la cantidad de artículos existentes\n");
            } else {
                strcpy(facturacionP[indicador], productos[indice]);
                facturacionPr[indicador] = precios[indice];
                facturacionC[indicador] = cantidad;
                multiplicacion[indicador] = precios[indice] * cantidad;
                acumulador += multiplicacion[indicador];
                cantidades[indice] -= cantidad;
                indicador++;
            }
        } else {
            printf("El producto no existe, inténtelo de nuevo\n");
        }

        printf("¿Desea ingresar más productos? S/N\n");
        scanf("%c", &opcion);
        limpiarconsola();
    }

    printf("\n                   Factura Marathon Sports\n");
    printf("\nUsuario: Profe de Progra          correo:carlos.guaita@udla.edu.ec\n");
    printf("\nUsted compró los siguientes productos:\n");
    printf("Descripcion              Valor            Cantidad         Valor\n");
    for (int k = 0; k < indicador; k++) {
        printf("\n%s                   %.2f               %d            %.2f \n", facturacionP[k], facturacionPr[k], facturacionC[k], multiplicacion[k]);
    }

    printf("--------------------------------------------------------------------");
    printf("\nSub total es: %.2f\n", acumulador);
    printf("--------------------------------------------------------------------");
    printf("\nIva fue del: %.2f\n", acumulador * 0.15);
    printf("--------------------------------------------------------------------");
    printf("\nTotal de tu factura es: %.2f\n", acumulador + acumulador * 0.15);
    printf("Presione enter para volver");
    getchar();
    getchar();
    limpiarconsola();
}

void Opciones(int a) {
    switch(a) {
        case 1:
            IngresarProductos();
            Menu();
            break;
        case 2:
            EliminarProductos();
            Menu();
            break;
        case 3:
            EditarProducto();
            Menu();
            break;
        case 4:
            ImprimirInventario();
            Menu();
            break;
        case 5:
            Facturacion();
            Menu();
            break;
        case 6:
            printf("Gracias por usar el portal\n");
            GuardarDatos();
            break;
        default:
            limpiarconsola();
            printf("\n\nLa opción marcada no está en el menú\n\n\n");
            Menu();
            break;
    }
}

void Menu() {
    int opcion;
    printf("--- BIENVENIDO A MARATHON SPORTS ---\n\n");
    printf("    1. -Ingresar productos-\n\n");  
    printf("    2. -Eliminar productos-\n\n");
    printf("    3. -Editar productos-\n\n"); 
    printf("    4. -Mostrar inventario-\n\n");
    printf("    5. Facturación\n\n");
    printf("    6. Salir\n\n");
    printf("    ----INGRESE LA OPCION----\n");
    scanf("%d", &opcion);
    Opciones(opcion);
}
