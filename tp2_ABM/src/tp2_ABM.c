#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "employee.h"
#include "utn.h"

int main(void)
{
  int option;
  int flagOption = TRUE;

  Employee listEmployees[QTY_EMPLOYEES];

  initEmployees(listEmployees, QTY_EMPLOYEES);
  do
  {
		//PRIMER ALTA
		if(flagOption == TRUE)
		{
			printf("Ingreso del primer empleado\n");
			if(entryEmployee(listEmployees, QTY_EMPLOYEES)==0)
			{
				printf("Ingreso correcto\n");
				flagOption = FALSE;
			}
			else
			{
				printf("Error en ingreso\n");
			}
		}
		else
		{
			if(menuEmployee(&option)==0)
			{
  			switch(option)
				{
					case 1: //ALTA
						if(entryEmployee(listEmployees, QTY_EMPLOYEES)==0)
						{
							printf("Ingreso correcto\n");
						}
						else
						{
							printf("Error en ingreso\n");
						}
					break;
					case 2: //MODIFICACION
						if(modifyEmployee(listEmployees, QTY_EMPLOYEES)==0)
						{
							printf("Modificación correcta\n");
						}
						else
						{
							printf("Error en la modificación\n");
						}
					break;
					case 3: //BAJA
						if(removeEmployee(listEmployees, QTY_EMPLOYEES) == 0)
						{
							printf("Baja correcta\n");
						}
						else
						{
							printf("Error en la baja\n");
						}
					break;
					case 4: //INFORMAR
						//1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
						if(sortEmployees(listEmployees, QTY_EMPLOYEES, 1)==0)
						{
							printf("Listado de los empleados ordenados:\n");
							printEmployees(listEmployees, QTY_EMPLOYEES);
						}
						//2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
						if(	totalSalaryEmployees(listEmployees, QTY_EMPLOYEES) == 0 &&
								averageSalaryEmployees(listEmployees, QTY_EMPLOYEES) == 0 &&
								qtyAverageSalaryEmployees(listEmployees, QTY_EMPLOYEES) == 0 )
						{
							printf("\nOperaciones completas.\n");
						}
						else
						{
							printf("Error en las operaciones!\n");
						}
					break;
				}
  		}
  	}
  }while(option != 5);

  return 0;
}
