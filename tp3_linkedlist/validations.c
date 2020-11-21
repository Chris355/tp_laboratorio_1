//
// Created by Christian Silvero
//

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "validations.h"

#define LIMITE_BUFFER_STRING 4096

//------------------------- FUNCIONES STATIC -----------------------------------

//------------------------- myGets --------------------------------------
/**
 * \brief Lee de stdin hasta que se encuentra un '\n' o hasta que haya copiado en cadena un maximo de 'longitud-1' caracteres.
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int longitud, define el tamaño de cadena.
 * \return Retorno: (0) si esta OK.
 * 									(-1) Si hubo un error
*/
int myGets(char* cadena, int longitud)
{
	int retorno = -1;

  if(cadena != NULL &&
     longitud > 0 &&
     fgets(cadena, longitud, stdin) == cadena)
  {
  	__fpurge(stdin);
    if(cadena[strlen(cadena)-1] == '\n' )
    {
      cadena[strlen(cadena)-1] = '\0' ;
    }
    retorno = 0;
  }
  return retorno;
}

//------------------------- getInt -----------------------------------
/**
 * \brief Verifica si la cadena ingresada es numerica y obtiene un entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorno: (0) si esta OK.
 * 									(-1) Si hubo un error
*/
int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL)
	{
		if(myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer))
		{
			*pResultado = atoi(buffer); //convierto un string a numerica
			retorno = 0;
		}
	}
	return retorno;
}

//------------------------- esNumerica -----------------------------------
/**
 * \brief Verifica si la cadena ingresada es numerica
 * \ param cadena Cadena de caracteres a ser analizada
 * \return Retorno: (1) Si es Verdadero
 * 									(0) Si es Falso
*/
int esNumerica(char* cadena)
{
	int retorno = TRUE; //inicializo con el OK
	int i = 0;

	if(cadena[0] == '-') //1ra posición es menos, ok
	{
		i = 1;
	}
	for( ; cadena[i] != '\0';i++)
	{
		if(cadena[i] < '0' || cadena[i] > '9')
		{
			retorno = FALSE; //Error
			break;
		}
	}
	return retorno;
}

//------------------------- getFloat -----------------------------------
/**
 * \brief Verifica si la cadena ingresada es flotante y obtiene un flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorno: (0) si esta OK.
 * 									(-1) Si hubo un error
*/
int getFloat(float* pResultado)
{
	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL)
	{
		if(myGets(buffer, sizeof(buffer)) == 0 && esFlotante(buffer))
		{
			*pResultado = atof(buffer); //convierto un string a flotante
			retorno = 0;
		}
	}
	return retorno;
}

//------------------------- esFlotante -----------------------------------
/**
 * \brief Verifica si la cadena ingresada es flotante
 * \ param cadena Cadena de caracteres a ser analizada
 * \return Retorno: (1) Si es Verdadero
 * 									(0) Si es Falso
*/
int esFlotante(char* cadena)
{
	int retorno = TRUE; //inicializo con el OK
	int i = 0;
	int contadorPuntos = 0;

	if(cadena[0] == '-') //1ra posición es menos, ok
	{
		i = 1;
	}
	for( ; cadena[i] != '\0';i++)
	{
		if(cadena[i] == '.')
		{
			contadorPuntos++;
		}
		if((cadena[i] < '0' || cadena[i] > '9') && contadorPuntos > 1)
		{
			retorno = FALSE; //Error
			break;
		}
	}
	return retorno;
}

//------------------------- esUnNombreValido -----------------------------------
/**
 * \brief, Verifica una cadena recibida como parametro para determinir si es un nombre valido
 * \param char* pArray, Cadena a analizar
 * \return Retorno: (1) Si es Verdadero
 * 									(0) Si es Falso
*/
int esUnNombreValido(char* cadena)
{
	int retorno = TRUE; //inicializo con el OK
	int i;
	if(cadena != NULL)
	{
	//el limite de la cadena es \0
		for(i=0; cadena[i]!='\0'; i++)
		{
			//condiciones para romper
			if((cadena[i] < 'a' || cadena[i] > 'z') &&
				 (cadena[i] < 'A' || cadena[i] > 'Z') &&
				  cadena[i] != ' ' &&
					cadena[i] != '-')
			{
				retorno = FALSE; //no esta dentro del rango
				break;
			}
		}
	}
	return retorno;
}

//------------------------- esUnaDireccion-----------------------------------
/**
 * \brief, Verifica una cadena recibida como parametro para determinir si es una direccion valida
 * \param char* pArray, Cadena a analizar
 * \return Retorno: (1) Si es Verdadero
 * 									(0) Si es Falso
*/
int esUnaDireccion(char* cadena)
{
	int retorno = TRUE; //inicializo con el OK
	int i;
	if(cadena != NULL)
	{
	//el limite de la cadena es \0
		for(i=0; cadena[i]!='\0'; i++)
		{
			//condiciones para romper
			if((cadena[i] < 'a' || cadena[i] > 'z') &&
				 (cadena[i] < 'A' || cadena[i] > 'Z') &&
				 (cadena[i] < '0' || cadena[i] > '9') &&
				 (cadena[i] < ' '))
			{
				retorno = FALSE; //no esta dentro del rango
				break;
			}
		}
	}
	return retorno;
}

//------------------------- esUnCuit-----------------------------------
/**
 * \brief, Verifica una cadena recibida como parametro para determinir si es un cuit valido
 * \param char* pArray, Cadena a analizar
 * \return Retorno: (1) Si es Verdadero
 * 									(0) Si es Falso
*/
int esUnCuit(char* cadena)
{
	int retorno = TRUE; //inicializo con el OK
	int i;
	if(cadena != NULL)
	{
	//el limite de la cadena es \0
		for(i=0; cadena[i]!='\0'; i++)
		{
			//condiciones para romper
			if((cadena[i] < '0' || cadena[i] > '9') &&
				 (cadena[2] != '-') &&
				 (cadena[11] != '-'))
			{
				retorno = FALSE; //no esta dentro del rango
				break;
			}
		}
	}
	return retorno;
}

//------------------------- esUnArchivo-----------------------------------
/**
 * \brief, Verifica una cadena recibida como parametro para determinir si es un archivo valido
 * \param char* pArray, Cadena a analizar
 * \return Retorno: (1) Si es Verdadero
 * 									(0) Si es Falso
*/
int esUnArchivo(char* cadena)
{
	int retorno = TRUE;
	int i;
	if(cadena != NULL)
	{
	//el limite de la cadena es \0
		for(i=0; cadena[i]!='\0'; i++)
		{
			//condiciones para romper
			if((cadena[i] < '0' || cadena[i] > '9') &&
				 (cadena[i] < 'a' || cadena[i] > 'z') &&
				 (cadena[i] != '.'))
			{
				retorno = FALSE; //no esta dentro del rango
				break;
			}
		}
	}
	return retorno;
}

//------------------------- esUnaDescripcion-----------------------------------
/**
 * \brief, Verifica una cadena recibida como parametro para determinir si es una descripcion valida
 * \param char* pArray, Cadena a analizar
 * \return Retorno: (1) Si es Verdadero
 * 									(0) Si es Falso
*/
int esUnaDescripcion(char* cadena)
{
	int retorno = TRUE;
	int i;
	if(cadena != NULL)
	{
	//el limite de la cadena es \0
		for(i=0; cadena[i]!='\0'; i++)
		{
			//condiciones para romper
			if((cadena[i] < '0' || cadena[i] > '9') &&
				 (cadena[i] < 'A' || cadena[i] > 'Z') &&
				 (cadena[i] < 'a' || cadena[i] > 'z') &&
				 (cadena[i] != '.') &&
				 (cadena[i] != ',') &&
				 (cadena[i] != ' '))
			{
				retorno = FALSE; //no esta dentro del rango
				break;
			}
		}
	}
	return retorno;
}
