//
// Created by Christian Silvero
//

#ifndef VALIDATIONS_H_
#define VALIDATIONS_H_
#define TRUE 1
#define FALSE 0


int myGets(char* cadena, int longitud);
int getInt(int* pResultado);
int getFloat(float* pResultado);

int esNumerica(char* cadena);
int esFlotante(char* cadena);
int esUnNombreValido(char* cadena);
int esUnaDireccion(char* cadena);
int esUnCuit(char* cadena);
int esUnArchivo(char* cadena);
int esUnaDescripcion(char* cadena);

#endif /* VALIDATIONS_H_ */
