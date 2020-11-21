#ifndef UTN_H_
#define UTN_H_

int getInt(char* mensaje, char* mensajeError, int* pResultado);
int getChar(char* mensaje, char* mensajeError, char* pResultado);
int getFloat(char* mensaje, char* mensajeError, float* pResultado);

int sumar(float operador1, float operador2, float *resultado);
int restar(float operador1, float operador2, float *resultado);
int multiplicar(float operador1, float operador2, float *resultado);
int dividir(float operador1, float operador2, float *resultado);
int factorial(float operador, int* resultado);

#endif /* UTN_H_ */
