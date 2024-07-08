def mostrar_menu():
    print("\n--- Menú del Sistema de Inventarios ---")
    print("1. Listar productos")
    print("2. Ingresar producto")
    print("3. Editar producto")
    print("4. Eliminar producto")
    print("5. Salir")

def listar_productos(productos):
    if not productos:
        print("No hay productos en el inventario.")
    else:
        print("\n--- Listado de Productos ---")
        print(f"{'ID':<5}{'Nombre':<20}{'Cantidad':<10}{'Precio':<10}")
        for i, producto in enumerate(productos, start=1):
            print(f"{i:<5}{producto['nombre']:<20}{producto['cantidad']:<10}{producto['precio']:<10}")

def ingresar_producto(productos):
    nombre = input("Ingrese el nombre del producto: ")
    cantidad = int(input("Ingrese la cantidad del producto: "))
    precio = float(input("Ingrese el precio del producto: "))
    productos.append({'nombre': nombre, 'cantidad': cantidad, 'precio': precio})
    print(f"Producto '{nombre}' ingresado con éxito.")

def editar_producto(productos):
    listar_productos(productos)
    id_producto = int(input("Ingrese el ID del producto a editar: "))
    if 1 <= id_producto <= len(productos):
        print("¿Qué desea editar?")
        print("1. Nombre")
        print("2. Cantidad")
        print("3. Precio")
        opcion = input("Seleccione una opción: ")
        
        if opcion == '1':
            nombre = input("Ingrese el nuevo nombre del producto: ")
            productos[id_producto - 1]['nombre'] = nombre
            print(f"Nombre del producto ID {id_producto} editado con éxito.")
        elif opcion == '2':
            cantidad = int(input("Ingrese la nueva cantidad del producto: "))
            productos[id_producto - 1]['cantidad'] = cantidad
            print(f"Cantidad del producto ID {id_producto} editada con éxito.")
        elif opcion == '3':
            precio = float(input("Ingrese el nuevo precio del producto: "))
            productos[id_producto - 1]['precio'] = precio
            print(f"Precio del producto ID {id_producto} editado con éxito.")
        else:
            print("Opción no válida.")
    else:
        print("ID de producto no válido.")

def eliminar_producto(productos):
    listar_productos(productos)
    id_producto = int(input("Ingrese el ID del producto a eliminar: "))
    if 1 <= id_producto <= len(productos):
        productos.pop(id_producto - 1)
        print(f"Producto ID {id_producto} eliminado con éxito.")
    else:
        print("ID de producto no válido.")

def main():
    productos = [
        {'nombre': 'Arroz', 'cantidad': 100, 'precio': 1.20},
        {'nombre': 'Frijoles', 'cantidad': 50, 'precio': 0.80},
        {'nombre': 'Aceite', 'cantidad': 30, 'precio': 2.50},
        {'nombre': 'Azúcar', 'cantidad': 75, 'precio': 1.00},
        {'nombre': 'Sal', 'cantidad': 90, 'precio': 0.50}
    ]
    
    while True:
        mostrar_menu()
        opcion = input("Seleccione una opción: ")
        if opcion == '1':
            listar_productos(productos)
        elif opcion == '2':
            ingresar_producto(productos)
        elif opcion == '3':
            editar_producto(productos)
        elif opcion == '4':
            eliminar_producto(productos)
        elif opcion == '5':
            print("Saliendo del sistema de inventarios...")
            break
        else:
            print("Opción no válida. Por favor, seleccione una opción del 1 al 5.")

if __name__ == "__main__":
    main()
