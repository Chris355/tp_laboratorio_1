/*
 * utn.h
 *
 *  Created on: 16 sep. 2020
 *      Author: christian
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNombre(char* pResultado, char* mensaje, char* mensajeError, int reintentos, int limite);

#endif /* UTN_H_ */
