//
// Created by Christian Silvero
//

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "validations.h"

#define LIMITE_BUFFER_STRING 4096


//------------------------- FUNCIONES GET -----------------------------------

//------------------------- utn_getInt -----------------------------------
/**
 * \brief utn_getInt : Pide al usuario un numero entero
 * \param pResultado: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param mensaje: El mensaje que imprime para pedir un valor
 * \param mensajeError: mensaje que imprime si el rango no es valido
 * \param minimo: valor minimo valido (inclusive)
 * \param maximo: valor maximo valido (inclusive)
 * \param reintentos: cantidad de intentos en caso de error
 * \return Retorno: (0) si esta OK.
 * 									(-1) Si hubo un error
*/
int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL &&
		 mensaje != NULL &&
		 mensajeError != NULL &&
		 reintentos >= 0 &&
		 maximo >= minimo)
	{
		do
		{
			printf("%s", mensaje);
			if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

//------------------------- utn_getFloat -----------------------------------
/**
 * \brief utn_getFloat : Pide al usuario un numero flotante
 * \param pResultado: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param mensaje: El mensaje que imprime para pedir un valor
 * \param mensajeError: mensaje que imprime si el rango no es valido
 * \param minimo: valor minimo valido (inclusive)
 * \param maximo: valor maximo valido (inclusive)
 * \param reintentos: cantidad de intentos en caso de error
 * \return Retorno: (0) si esta OK.
 * 									(-1) Si hubo un error
*/
int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;

	if(pResultado != NULL &&
		 mensaje != NULL &&
		 mensajeError != NULL &&
		 reintentos >= 0 &&
		 maximo >= minimo)
	{
		do
		{
			printf("%s", mensaje);
			//__fpurge(stdin);
			//resultadoScanf = scanf("%f",&bufferFloat);
			if(getFloat(&bufferFloat) == 0 && bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

//------------------------- utn_getNombre -----------------------------------
/**
 * \brief Solicita un nombre al usuario
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int limite, indica la cantidad de letras maxima del nombre
 * \return Retorno: (0) si esta OK.
 * 									(-1) Si hubo un error
*/
int utn_getNombre(char* pResultado, char* mensaje, char* mensajeError, int reintentos, int limite)
{
	char bufferString[LIMITE_BUFFER_STRING];
	int retorno = -1;

	if(	pResultado != NULL &&
			mensaje != NULL &&
			mensajeError != NULL &&
			reintentos >= 0 &&
			limite > 0)
	{
		do
		{
			printf("%s", mensaje);
			if( myGets(bufferString, LIMITE_BUFFER_STRING) == 0 &&
					strnlen(bufferString, sizeof(bufferString)-1)<= limite &&
					esUnNombreValido(bufferString) != 0 )
			{
				retorno = 0;
				strncpy(pResultado, bufferString, limite);
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

//------------------------- utn_getDireccion -----------------------------------
/**
 * \brief Solicita una direccion al usuario
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int limite, indica la cantidad de letras maxima del nombre
 * \return Retorno: (0) si esta OK.
 * 									(-1) Si hubo un error
*/
int utn_getDireccion(char* pResultado, char* mensaje, char* mensajeError, int reintentos, int limite)
{
	char bufferString[LIMITE_BUFFER_STRING];
	int retorno = -1;

	if(	pResultado != NULL &&
			mensaje != NULL &&
			mensajeError != NULL &&
			reintentos >= 0 &&
			limite > 0)
	{
		do
		{
			printf("%s",mensaje);
			if( myGets(bufferString,LIMITE_BUFFER_STRING) == 0 &&
					strnlen(bufferString,sizeof(bufferString)-1)<= limite &&
					esUnaDireccion(bufferString) != 0 )
			{
				retorno = 0;
				strncpy(pResultado,bufferString,limite);
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

//------------------------- utn_getCuit -----------------------------------
/**
 * \brief Solicita una cuit al usuario
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int limite, indica la cantidad de letras maxima del nombre
 * \return Retorno: (0) si esta OK.
 * 									(-1) Si hubo un error
*/
int utn_getCuit(char* pResultado, char* mensaje, char* mensajeError, int reintentos, int limite)
{
	char bufferString[LIMITE_BUFFER_STRING];
	int retorno = -1;

	if(	pResultado != NULL &&
			mensaje != NULL &&
			mensajeError != NULL &&
			reintentos >= 0 &&
			limite > 0)
	{
		do
		{
			printf("%s",mensaje);
			if( myGets(bufferString,LIMITE_BUFFER_STRING) == 0 &&
					strnlen(bufferString,sizeof(bufferString)-1) <= limite &&
					esUnCuit(bufferString) != 0 )
			{
				retorno = 0;
				strncpy(pResultado,bufferString,limite);
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

//------------------------- utn_getArchivo -----------------------------------
/**
 * \brief Solicita un nombre de archivo al usuario
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int limite, indica la cantidad de letras maxima del nombre
 * \return Retorno: (0) si esta OK.
 * 									(-1) Si hubo un error
*/
int utn_getArchivo(char* pResultado, char* mensaje, char* mensajeError, int reintentos, int limite)
{
	char bufferString[LIMITE_BUFFER_STRING];
	int retorno = -1;

	if(	pResultado != NULL &&
			mensaje != NULL &&
			mensajeError != NULL &&
			reintentos >= 0 &&
			limite > 0)
	{
		do
		{
			printf("%s",mensaje);
			if( myGets(bufferString,LIMITE_BUFFER_STRING) == 0 &&
					strnlen(bufferString,sizeof(bufferString)-1) <= limite &&
					esUnArchivo(bufferString) != 0 )
			{
				retorno = 0;
				strncpy(pResultado,bufferString,limite);
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

//------------------------- utn_getDescripcion -----------------------------------
/**
 * \brief Solicita una descripcion de archivo al usuario
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int limite, indica la cantidad de letras maxima del nombre
 * \return Retorno: (0) si esta OK.
 * 									(-1) Si hubo un error
*/
int utn_getDescripcion(char* pResultado, char* mensaje, char* mensajeError, int reintentos, int limite)
{
	char bufferString[LIMITE_BUFFER_STRING];
	int retorno = -1;

	if(	pResultado != NULL &&
			mensaje != NULL &&
			mensajeError != NULL &&
			reintentos >= 0 &&
			limite > 0)
	{
		do
		{
			printf("%s",mensaje);
			if( myGets(bufferString,LIMITE_BUFFER_STRING) == 0 &&
					strnlen(bufferString,sizeof(bufferString)-1) <= limite &&
					esUnaDescripcion(bufferString) != 0 )
			{
				retorno = 0;
				strncpy(pResultado,bufferString,limite);
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}










