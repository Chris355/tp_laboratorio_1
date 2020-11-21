#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int returnFscanf;
	char idStr[50];
	char nombre[50];
	char horasStr[50];
	char sueldoStr[50];
	Employee* pAuxEmpleado;

	if(pFile != NULL)
	{
		do
		{
			returnFscanf = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombre,horasStr,sueldoStr); //tomo los datos del archivo
			if(returnFscanf==4)
			{
				pAuxEmpleado = employee_newDefault(); //creo un empleado
				if( employee_setId(pAuxEmpleado, atoi(idStr))==0 &&
						employee_setNombre(pAuxEmpleado, nombre)==0 &&
						employee_setHorasTrabajadas(pAuxEmpleado, atoi(horasStr))==0 &&
						employee_setSueldo(pAuxEmpleado, atoi(sueldoStr))==0 )
				{
					//agrego a la lista
					ll_add(pArrayListEmployee, pAuxEmpleado);
					//printf("Lei: %s %s %s %s\n",idStr,nombre,horasStr,sueldoStr);
				}
			}
			else
				break;
		}while(!feof(pFile));
	}
	return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* pAuxEmpleado;
	int returnFread;

	if(pFile != NULL)
	{
		retorno = 0;
		do
		{
			pAuxEmpleado = employee_newDefault();
			if(pAuxEmpleado != NULL)
			{
				returnFread = fread(pAuxEmpleado, sizeof(Employee), 1, pFile);
				if(returnFread == 1)
				{
					ll_add(pArrayListEmployee, pAuxEmpleado);
				}
				else
				{
					employee_delete(pAuxEmpleado);
				}
			}
		}while(!feof(pFile));
	}
	return retorno;
}






















