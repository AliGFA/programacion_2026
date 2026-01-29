#include <stdio.h>
#include <stdbool.h>

#define MAX_EST 100

struct Estudiante{
    char nombre[50];
    int codigo;
    int edad;
    int promedio;
    bool activo;
};

void mostrarEstudiante(const struct Estudiante *est, int idx) {
    printf("\nEstudiante %d:\n", idx);
    printf("  Nombre: %s\n", est->nombre);
    printf("  Codigo: %d\n", est->codigo);
    printf("  Edad: %d\n", est->edad);
    printf("  Promedio: %d\n", est->promedio);
    printf("  Activo: %s\n", est->activo ? "Si" : "No");
}

void agregarEstudiante(struct Estudiante *est) {
    printf("\nAgregue los datos del estudiante:\n");
    printf("Nombre del estudiante: ");
    scanf(" %49[^\n]", est->nombre);
    
    printf("Codigo del estudiante: ");
    scanf("%d", &est->codigo);
    
    printf("Edad del estudiante: ");
    scanf("%d", &est->edad);
    
    printf("Promedio del estudiante: ");
    scanf("%d", &est->promedio);
    printf("El estudiante esta activo? (1 = true, 0 = false): ");
    scanf("%d", &est->activo);
    printf("Estudiante agregado\n\n");
}

int main() {
    int opcion = 0;
    struct Estudiante estudiantes[MAX_EST];
    int total = 0;
    
    while (true) {
        opcion = 0;
        
        while (opcion < 1 || opcion > 4) {
            printf("Seleccione una opcion del menu:\n");
            printf("1. Agregar estudiante\n"
                   "2. Mostrar un estudiante especifico\n" 
                   "3. Mostrar todos los estudiantes\n"
                   "4. Salir\n");
            scanf("%d", &opcion);
            
            if (opcion < 1 || opcion > 4) {
                printf("Opcion invalida, intenta de nuevo\n\n");
            }
        }
        
        switch(opcion) {
            case 1:
                if (total >= MAX_EST) {
                    printf("\nNo hay espacio para mas estudiantes (max %d)\n\n", MAX_EST);
                    break;
                }
                agregarEstudiante(&estudiantes[total]);
                total++;
                break;
            case 2:
                if (total == 0) {
                    printf("\nNo hay estudiantes registrados\n\n");
                    break;
                }
                printf("Ingrese el codigo del estudiante: ");
                int codigoBuscado;
                scanf("%d", &codigoBuscado);
                bool encontrado = false;
                for (int i = 0; i < total; i++) {
                    if (estudiantes[i].codigo == codigoBuscado) {
                        mostrarEstudiante(&estudiantes[i], i);
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    printf("No se encontro un estudiante con ese codigo\n");
                }
                printf("\n");
                break;
            case 3:
                if (total == 0) {
                    printf("\nNo hay estudiantes registrados\n\n");
                    break;
                }
                for (int i = 0; i < total; i++) {
                    mostrarEstudiante(&estudiantes[i], i);
                }
                printf("\n");
                break;
            case 4:
                printf("Saliendo\n");
                return 0;
        }
    }
    
    return 0;
}
