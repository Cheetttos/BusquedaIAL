#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char texto[1000];
    int palabras = 0, caracteres = 0, acentos = 0, puntuacion = 0, vocales=0,mayusculas=0,minusculas=0,espacio=0;
    float promedio = 0.0;

    printf("Ingresa un texto:\n");
    fgets(texto, sizeof(texto), stdin);

    int longitud = strlen(texto);
    for (int i = 0; i < longitud; i++) {
        caracteres++;

        if (texto[i] == "%"){
            acentos++;
        }

        if(isupper(texto[i])){
            mayusculas++;
        }

        if(islower(texto[i])){
            minusculas++;
        }

        if(isspace(texto[i])){
            espacio++;
        }

        if (texto[i] == "A" || texto[i] == "E" || texto[i] == "I" || texto[i] == "O"
            || texto[i] == "U" || texto[i] == "a" || texto[i] == "e"
            || texto[i] == "i" || texto[i] == "o" || texto[i] == "u"){
            vocales++;
        }
        if (ispunct(texto[i])) {
            puntuacion++;
        }
    }

    // Contar palabras
    char *token = strtok(texto, " \t\n");
    while (token != NULL) {
        palabras++;
        token = strtok(NULL, " \t\n");
    }

    printf("Cantidad de palabras: %d\n", palabras);
    printf("Cantidad de caracteres: %d\n", caracteres);
    printf("Cantidad de acentos: %d\n", acentos);
    printf("Cantidad de signos de puntuación: %d\n", puntuacion);
    printf("Cantidad de vocales: %d\n", vocales);
    printf("Cantidad de mayusculas: %d\n", mayusculas);
    printf("Cantidad de minusculas: %d\n", minusculas);
    printf("Cantidad de espacios: %d\n", espacio);
    printf("Caracteres promedio por palabra: %d\n", caracteres/palabras);



    return 0;
}
