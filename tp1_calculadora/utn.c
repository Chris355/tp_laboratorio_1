#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

/**
 * \brief Solicita un entero al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int* pResultado, Puntero al espacio de memoria donde se dejara el valor obtenido
 * \return (-1) Error / (0) Ok
 */

int getInt(char* mensaje, char* mensajeError, int* pResultado)
{
	int respuesta = -1;
	int bufferInt;
	int resultadoScanf;

	if(	mensaje != NULL && mensajeError != NULL && pResultado != NULL)
	{
    printf("%s", mensaje);
    __fpurge(stdin);
    resultadoScanf = scanf("%d", &bufferInt);
    if(resultadoScanf == 1)
    {
      respuesta = 0;
      *pResultado = bufferInt;
    }
    else
    {
      printf("%s", mensajeError);
    }
	}
	return respuesta;
}

/**
 * \brief Solicita un caracter al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param char* pResultado, Puntero al espacio de memoria donde se dejara el valor obtenido
 * \return (-1) Error / (0) Ok
 */

int getChar(char* mensaje, char* mensajeError, char* pResultado)
{
	int respuesta = -1;
	char bufferChar;
	int resultadoScanf;

	if(	mensaje != NULL && mensajeError != NULL && pResultado != NULL)
	{
    printf("%s", mensaje);
    __fpurge(stdin);
    resultadoScanf = scanf("%c", &bufferChar);
    if(resultadoScanf == 1)
    {
      respuesta = 0;
      *pResultado = bufferChar;
    }
    else
    {
      printf("%s", mensajeError);
    }
	}
	return respuesta;
}

/**
 * \brief Solicita un numero decimal al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param float* pResultado, Puntero al espacio de memoria donde se dejara el valor obtenido
 * \return (-1) Error / (0) Ok
 */

int getFloat(char* mensaje, char* mensajeError, float* pResultado)
{
	int respuesta = -1;
	float bufferFloat;
	int resultadoScanf;

	if(	mensaje != NULL && mensajeError != NULL && pResultado != NULL)
	{
    printf("%s", mensaje);
    __fpurge(stdin);
    resultadoScanf = scanf("%f", &bufferFloat);
    if(resultadoScanf == 1)
    {
      respuesta = 0;
      *pResultado = bufferFloat;
    }
    else
    {
      printf("%s", mensajeError);
    }
	}
	return respuesta;
}

/**
 * \brief Realiza la operación suma.
 * \param float operador1, Es el primero operando.
 * \param float operador2, Es el segundo operando.
 * \param float* resultado, Puntero al espacio de memoria donde se dejara el valor obtenido
 * \return (0) Ok
 */

int sumar(float operador1, float operador2, float *resultado)
{
	if(resultado != NULL)
	{
		*resultado = operador1 + operador2;
	}
  return 0;
}

/**
 * \brief Realiza la operación resta.
 * \param float operador1, Es el primero operando.
 * \param float operador2, Es el segundo operando.
 * \param float* resultado, Puntero al espacio de memoria donde se dejara el valor obtenido
 * \return (0) Ok
 */

int restar(float operador1, float operador2, float *resultado)
{
	if(resultado != NULL)
	{
		*resultado = operador1 - operador2;
	}
  return 0;
}

/**
 * \brief Realiza la operación multiplicacion.
 * \param float operador1, Es el primero operando.
 * \param float operador2, Es el segundo operando.
 * \param float* resultado, Puntero al espacio de memoria donde se dejara el valor obtenido
 * \return (0) Ok
 */

int multiplicar(float operador1, float operador2, float *resultado)
{
	if(resultado != NULL)
	{
		*resultado = operador1 * operador2;
	}
  return 0;
}

/**
 * \brief Realiza la operación division.
 * \param float operador1, Es el primero operando.
 * \param float operador2, Es el segundo operando.
 * \param float* resultado, Puntero al espacio de memoria donde se dejara el valor obtenido
 * \return (-1) Error / (0) Ok
 */

int dividir(float operador1, float operador2, float *resultado)
{
  int retorno;

  if(operador2 != 0)
  {
    *resultado = operador1 / operador2;
    retorno = 0;
  }
  else
  {
    retorno = -1;
  }
  return retorno;
}

/**
 * \brief Realiza la operación factorial.
 * \param float operador, Es el operando.
 * \int* resultado, Puntero al espacio de memoria donde se dejara el valor obtenido
 * \return (-1) Error / (0) Ok
 */

int factorial(float operador, int* resultado)
{
  int retorno;
  int i;
  int factorial = 1;

  if(operador > 0)
  {
    for(i=(int)operador; i>1; i--)
    {
      factorial = factorial * i;
    }
    *resultado = factorial;
    retorno = 0;
  }
  else
  {
    retorno = -1;
  }
  return retorno;
}
