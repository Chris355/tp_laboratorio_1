/*
 ============================================================================
 Name        : tp1_calculadora.c
 Author      : Christian Silvero
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void)
{
	int opcion;
	int respuesta;
  float operadorA;
  float operadorB;
  float resultadoSuma;
  float resultadoResta;
  float resultadoMultiplicacion;
  float resultadoDivision;
  int resultadoFactorialA;
  int resultadoFactorialB;

  do
  {
    printf("1. Ingresar primer operando (A=%.2f)\n",operadorA);
    printf("2. Ingresar segundo operando (B=%.2f)\n",operadorB);
    printf("3. Calcular las operaciones\n");
    printf("4. Informar los resultados\n");
    printf("5. Salir\n");

		respuesta = getInt("Seleccione una opcion: ", "No es una opcion valida\n", &opcion);

  	if(!respuesta)
  	  {
  	  	switch(opcion)
  			{
  				case 1:
  					getFloat("Indique el primer operando: ", "Error, indique un numero. ", &operadorA);
  				break;
  				case 2:
  					getFloat("Indique el segundo operando: ", "Error, indique un numero. ", &operadorB);
  				break;
  				case 3:
						sumar(operadorA, operadorB, &resultadoSuma);
						restar(operadorA, operadorB, &resultadoResta);
						multiplicar(operadorA, operadorB, &resultadoMultiplicacion);
						dividir(operadorA, operadorB, &resultadoDivision);
						factorial(operadorA, &resultadoFactorialA);
						factorial(operadorB, &resultadoFactorialB);
					break;
  				case 4:
  					printf("El resultado es de la suma es: %.2f\n", resultadoSuma);
  					printf("El resultado es de la Resta es: %.2f\n", resultadoResta);
  					printf("El resultado es de la Multiplicacion es: %.2f\n", resultadoMultiplicacion);
  					if(dividir(operadorA, operadorB, &resultadoDivision) == 0)
  					{
  						printf("El resultado es de la Division es: %.2f\n", resultadoDivision);
  					}
  					else
  					{
  						printf("No se puede dividir por 0\n");
  					}
  					if(factorial(operadorA, &resultadoFactorialA) == 0)
  					{
  						printf("El resultado es del Factorial A es: %.2d\n", resultadoFactorialA);
  					}
  					else
  					{
  						printf("No se puede realizar el factorial.\n");
  					}
  					if(factorial(operadorB, &resultadoFactorialB) == 0)
  					{
  						printf("El resultado es del Factorial B es: %.2d\n", resultadoFactorialB);
  					}
  					else
  					{
  						printf("No se puede realizar el factorial.\n");
  					}
  				break;
  			}
  	  }
  }while(opcion != 5);

  return 0;
}







