#include <stdio.h>
#include <stdlib.h>

//programa para pasar contenido de un archivo a una cadena

int main(){
	FILE *archivo;
	archivo=fopen("numeros.txt","rb");
	
	if(archivo==NULL){
		perror("No existe el archivo");
		return 1;
	}
	fseek(archivo, 0 , SEEK_END); //mover flujo al final del archivo
	int numero_elementos = ftell(archivo); /*la funcion "ftell" pregunta donde 
	se encuentra el flujo de datos: al igualarlo a la variable "numero_elementos nos dara el total
	de elementos del archivo*/
 	rewind(archivo);//regresa el flujo al inicio del archivo
	
	char *cadena=(char*) calloc(sizeof(char),numero_elementos);//arreglo dinamico de caracteres
	if(cadena==NULL){
		perror("Error en la reserva de memoria");
		return 2;
	}
	
	int numero_elementos_leidos= fread (cadena, sizeof(char),numero_elementos,archivo);
	if(numero_elementos_leidos!=numero_elementos){
		perror("Error leyendo el archivo");
		return 3;
	}
	
	printf("%s",cadena);/*imprimimos el contenido de cadena para comprobar que contiene 
	los caracteres del archivo*/
	
	free(cadena);//libero memoria dinamica
	fclose(archivo);//cierro archivo
	printf("\n\nSe ha leido el archivo correctamente");
	
	return 0;
}
