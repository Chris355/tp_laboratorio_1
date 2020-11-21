#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "employee.h"
#include "utn.h"

static int newId(void);

/**
 * \brief Cada vez que la llamo me devuelve un ID nuevo que nunca me devolvio antes.
 * \return id generado
 *
 */

static int newId(void)
{
	static int id = 0;

	id = id+1;
	return id;
}

//---------------- Función menuEmployee -----------------------

/**
 * \brief Cada vez que la llamo me devuelve una opcion del menu.
 * \return int Return (-1) Error - (0) Ok
 *
*/

int menuEmployee(int* option)
{
  int retorno = -1;
  int bufferOpcion;
  char mensajeMenu[150] = "\n"
                        "\n1 - Ingresar empleado: "
                        "\n2 - Modificar empleado por ID: "
                        "\n3 - Baja de empleado por ID: "
                        "\n4 - Informar: "
                        "\n5 - Salir"
                        "\n";
  if(utn_getInt(&bufferOpcion, mensajeMenu, "Error! opcion invalida.\n", 1, 5, 2)==0)
  {
    *option = bufferOpcion;
    retorno = 0;
  }
  return retorno;
}

//---------------- 2.1 Función initEmployees -----------------------

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

int initEmployees(Employee* list, int len)
{
  int retorno = -1;
  int i;
  if(list != NULL && len > 0)
  {
    for(i=0; i<len; i++)
    {
      list[i].isEmpty = TRUE;
      retorno = 0;
    }
  }
  return retorno;
}

//---------------- Función entryEmployee -----------------------

/** \brief get in a existing list of employees the values received
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

int entryEmployee(Employee* list, int len)
{
  int retorno = -1;
  Employee bufferEmployee;
  if(list != NULL && len > 0)
  {
    if(utn_getNombre(bufferEmployee.name, "Indique nombre: ", "Error! dato invalido.\n", RETRY, SIZE_NAME)==0 &&
       utn_getNombre(bufferEmployee.lastName, "Indique apellido: ", "Error! dato invalido.\n", RETRY, SIZE_NAME)==0 &&
       utn_getFloat(&bufferEmployee.salary, "Indique salario (500/10000): ", "Error! dato invalido.\n", MIN_SALARY, MAX_SALARY, RETRY)==0 &&
       utn_getInt(&bufferEmployee.sector, "Indique sector (1/10): ", "Error! dato invalido.\n", MIN_SECTOR, MAX_SECTOR, RETRY)==0)
    {
      bufferEmployee.id = newId();
      addEmployee(list, QTY_EMPLOYEES, bufferEmployee.id, bufferEmployee.name, bufferEmployee.lastName, bufferEmployee.salary, bufferEmployee.sector);
    }
    retorno = 0;
  }
  return retorno;
}

//---------------- 2.2 Función addEmployee -----------------------

/** \brief add in a existing list of employees the values received as parameters in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
  int retorno = -1;
  int i;
  Employee bufferEmployee;
  if(list != NULL && len > 0)
  {
    bufferEmployee.id = id;
    strncpy(bufferEmployee.name, name, SIZE_NAME);
    strncpy(bufferEmployee.lastName, lastName, SIZE_NAME);
    bufferEmployee.salary = salary;
    bufferEmployee.sector = sector;
    for(i=0; i<len; i++)
    {
      if(list[i].isEmpty == TRUE)
      {
        list[i] = bufferEmployee;
        list[i].isEmpty = FALSE;
        retorno = 0;
        break;
      }
    }
  }
  return retorno;
}

//---------------- 2.3 Función findEmployeeById -----------------------

/** \brief find an Employee by Id en returns the index position in array.
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/

int findEmployeeById(Employee* list, int len, int id)
{
	int retorno = -1;
	int i;
	if(list != NULL && len>0 && id>=0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].id == id)
			{
				printf("Id: %d - Nombre: %s - Apellido: %s - Salario: %.2f - Sector: %d\n",
							list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
				retorno = i;
				break;
			}
		}
	}
  return retorno;
}

//---------------- Función modifyEmployee -----------------------

/** \brief Modify a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*
*/

int modifyEmployee(Employee* list, int len)
{
	int retorno = -1;
	int indice;
	Employee bufferEmployee;
	int bufferId;
	int opcion;
  char mensajeMenu[150] = "\n1 - Modificar nombre: "
  												"\n2 - Modificar apellido: "
  												"\n3 - Modificar salario: "
  												"\n4 - Modificar sector: "
  												"\n5 - Salir\n";

	if(list != NULL && len>0)
	{
		if(utn_getInt(&bufferId, "Indique Id: \n", "Error!", 1, 1000, RETRY)==0)
		{
			indice = findEmployeeById(list, len, bufferId);
			do
			  {
					if(utn_getInt(&opcion, mensajeMenu, "Error!", 1, 5, RETRY)==0)
					{
						switch(opcion)
						{
							case 1:
								if(utn_getNombre(bufferEmployee.name, "Indique nombre: ", "Error! dato invalido.\n", RETRY, SIZE_NAME)==0)
								{
									strncpy(list[indice].name, bufferEmployee.name, SIZE_NAME);
								}
							break;
							case 2:
								if(utn_getNombre(bufferEmployee.lastName, "Indique apellido: ", "Error! dato invalido.\n", RETRY, SIZE_NAME)==0)
								{
									strncpy(list[indice].lastName, bufferEmployee.lastName, SIZE_NAME);
								}
							break;
							case 3:
								if(utn_getFloat(&bufferEmployee.salary, "Indique salario (500/10000): ", "Error! dato invalido.\n", MIN_SALARY, MAX_SALARY, RETRY)==0)
								{
							    bufferEmployee.salary = list[indice].salary;
								}
							break;
							case 4:
								if(utn_getInt(&bufferEmployee.sector, "Indique sector (1/10): ", "Error! dato invalido.\n", MIN_SECTOR, MAX_SECTOR, RETRY)==0)
								{
							    bufferEmployee.sector = list[indice].sector;
								}
							break;
						}
					}
			  }while(opcion != 5);
		}
		retorno = 0;
	}
	return retorno;
}


//---------------- 2.4 Función removeEmployee -----------------------

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/

int removeEmployee(Employee* list, int len)
{
	int retorno = -1;
	int indice;
	int bufferId;
	if(list != NULL && len>0)
	{
		if(utn_getInt(&bufferId, "Indique Id: \n", "Error!", 1, 1000, 2)==0)
		{
			indice = findEmployeeById(list, len, bufferId);
			list[indice].isEmpty = TRUE;
			retorno = 0;
		}
	}
  return retorno;
}

//---------------- 2.5 Función sortEmployees -----------------------

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

int sortEmployees(Employee* list, int len, int order)
{
	int retorno = -1;
	int i;
	int flagSwap;
	Employee bufferEmployee;
	int auxCmpLastname;

	if (list != NULL && len > 0 && (order == UP || order == DOWN))
	{
		do
		{
			flagSwap = FALSE;
			for(i=0; i<len-1 ;i++)
			{
				auxCmpLastname = strncmp(list[i].lastName, list[i+1].lastName, SIZE_NAME);
				if(
						((order == UP && auxCmpLastname > 0) || (order == DOWN && auxCmpLastname < 0)) ||
						( (order == UP && auxCmpLastname == 0 && list[i].sector > list[i+1].sector) ||
						  (order == DOWN && auxCmpLastname == 0 && list[i].sector < list[i+1].sector) )
					)
				{
					bufferEmployee = list[i];
					list[i] = list[i+1];
					list[i+1] = bufferEmployee;
					flagSwap = TRUE;
				}
			}
		}while(flagSwap);
		retorno = 0;
	}
	return retorno;
}

//---------------- 2.6 Función printEmployees -----------------------

/** \brief print the content of employees array
*
* \param list Employee*
* \param leng int
* \return int
*
*/

int printEmployees(Employee* list, int len)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("Id: %d \tNombre: %s \tApellido: %s \tSalario: %.2f \tSector: %d\n",
							list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
				retorno = 0;
			}
		}
	}
  return retorno;
}

//---------------- Función totalSalaryEmployees -----------------------

/** \brief print the total Salary of employees array
*
* \param list Employee*
* \param leng int
* \return int
*
*/

int totalSalaryEmployees(Employee* list, int len)
{
	int retorno = -1;
	int i;
	float totalSalary = 0;
	if(list != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				totalSalary = totalSalary + list[i].salary;
				retorno = 0;
			}
		}
		printf("\nSalario Total: %.2f", totalSalary);
	}
  return retorno;
}

//---------------- Función averageSalaryEmployees -----------------------

/** \brief print the average Salary of employees array
*
* \param list Employee*
* \param leng int
* \return int
*
*/

int averageSalaryEmployees(Employee* list, int len)
{
	int retorno = -1;
	int i;
	float totalSalary = 0;
	float averageSalary;

	if(list != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				totalSalary = totalSalary + list[i].salary;
				retorno = 0;
			}
		}
		averageSalary = totalSalary / i;
		printf("\nSalario Promedio: %.2f", averageSalary);
	}
  return retorno;
}

//---------------- Función qtyAverageSalaryEmployees -----------------------

/** \brief print the average Salary of employees array
*
* \param list Employee*
* \param leng int
* \return int
*
*/

int qtyAverageSalaryEmployees(Employee* list, int len)
{
	int retorno = -1;
	int i;
	float totalSalary = 0;
	float averageSalary;
	int contador = 0;

	if(list != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				totalSalary = totalSalary + list[i].salary;
			}
		}
		averageSalary = totalSalary / i;
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].salary > averageSalary)
			{
				contador++;
			}
		}
		printf("\nCantidad de empleados mayor al salario Promedio: %d", contador);
		retorno = 0;
	}
  return retorno;
}
