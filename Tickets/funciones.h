void cargarPeliculas(char peliculas[][4][40]);
void guardarPeliculas(char peliculas[][4][40]);
void cargarClientes(char clientes[][2][40]);
void guardarClientes(char clientes[][2][40]);
void cargarReservas(int reserva[][4]);
void guardarReservas(int reserva[][4]);

void ingresarCliente(char clientes[][2][40]);
void imprimirClientes(char clientes[][2][40]);
void listarPeliculas(char peliculas[][4][40]);
void buscarporNombre(char peliculas[][4][40]);
void buscarporGenero(char peliculas[][4][40]);
void comprarTicket(char peliculas[][4][40], double precio[], char clientes[][2][40], int reserva[][4]);
void verCompras(char peliculas[][4][40], double precio[], char clientes[][2][40], int reserva[][4]);
