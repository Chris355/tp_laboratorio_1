#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pFile;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path,"r");
		parser_EmployeeFromText(pFile, pArrayListEmployee);
		fclose(pFile);
		retorno = 0;
	}

	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pFile;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path,"rb");
		parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		fclose(pFile);
		retorno = 0;
	}

	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
  int retorno = -1;
  int auxId;
  char auxNombre[SIZE_STRING];
  int auxHoras;
  int auxSueldo;
	Employee* pAuxEmpleado;

  if(	pArrayListEmployee != NULL )
  {
    if(	utn_getNombre(auxNombre, "Nombre? ", "Error", RETRY, SIZE_STRING) == 0 &&
				utn_getInt(&auxSueldo, "Sueldo? ", "Error! ", MIN_SUELDO, MAX_SUELDO, RETRY) == 0 &&
				utn_getInt(&auxHoras, "Horas trabajadas? ", "Error! ", MIN_SUELDO, MAX_SUELDO, RETRY) == 0 )
    {
    	pAuxEmpleado = employee_newDefault();
    	auxId = employee_generarIdNuevo();

    	if( pAuxEmpleado != NULL &&
    	  	employee_setId(pAuxEmpleado, auxId) == 0 &&
    			employee_setNombre(pAuxEmpleado, auxNombre) == 0 &&
    			employee_setHorasTrabajadas(pAuxEmpleado, auxHoras) == 0 &&
    			employee_setSueldo(pAuxEmpleado, auxSueldo) == 0 )
    	  {
    			//agrego a la lista
					ll_add(pArrayListEmployee, pAuxEmpleado);
    	    retorno = 0;
    	  }
    }
  }
  return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
  int retorno = -1;
  int auxIndice;
  char auxNombre[SIZE_STRING];
  int auxHoras;
  int auxSueldo;
	Employee* pAuxEmpleado;

  if(	pArrayListEmployee != NULL )
  {
  	utn_getInt(&auxIndice, "Indique INDICE a modificar: ", "Error!", 0, 2000, RETRY);
    pAuxEmpleado = (Employee*)ll_get(pArrayListEmployee, auxIndice); //pido el empleado de la LISTA y guardo en el aux

    if(	utn_getNombre(auxNombre, "Editar nombre: ", "Error", RETRY, SIZE_STRING) == 0  &&
    		employee_setNombre(pAuxEmpleado, auxNombre) == 0)
    {
    	if( utn_getInt(&auxSueldo, "Editar sueldo: ", "Error! ", MIN_SUELDO, MAX_SUELDO, RETRY) == 0 &&
    			employee_setSueldo(pAuxEmpleado, auxSueldo) == 0 )
    	{
    		if( utn_getInt(&auxHoras, "Editar horas trabajadas: ", "Error! ", MIN_SUELDO, MAX_SUELDO, RETRY) == 0 &&
    				employee_setHorasTrabajadas(pAuxEmpleado, auxHoras) == 0)
    		{
  				if( pAuxEmpleado != NULL )
  				{
  					//MODIFICO al empleado por indice con los datos cargados por get_
  					ll_set(pArrayListEmployee, auxIndice, pAuxEmpleado);
  					retorno = 0;
  				}
    		}
			}
    }
  }
  return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
  int retorno = -1;
  int auxIndice;

  if(	pArrayListEmployee != NULL )
  {
		if(utn_getInt(&auxIndice, "Indique INDICE a eliminar: ", "Error!", 0, 2000, RETRY) == 0)
		{
			//ELIMINO al empleado de la lista
			ll_remove(pArrayListEmployee, auxIndice);
			retorno = 0;
		}
  }
  return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int i;
	int auxLen;
	Employee* auxGet;

	auxLen = ll_len(pArrayListEmployee); //tamaño de la lista
	if(pArrayListEmployee != NULL && auxLen > 0)
	{
		printf( "INDEX  | ID |        NOMBRE |  HORAS |  SUELDO\n");
		for(i=0; i<auxLen; i++)
		{
			auxGet = (Employee*)ll_get(pArrayListEmployee, i); //pido la lista
			if(auxGet != NULL)
			{
				printf("[%2d]    ",i+1);
				employee_printOne(auxGet);
			}
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	if(pArrayListEmployee != NULL)
	{
		ll_sort(pArrayListEmployee, employee_cmpNombre, 0);
		retorno = 0;
	}
  return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE *pFile;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "w");
		parser_EmployeeFromText(pFile, pArrayListEmployee);
		retorno = 0;
		fclose(pFile);
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE *pFile;
	int retorno = -1;
	int len = ll_len(pArrayListEmployee);
	Employee *pEmpleado;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "wb");
		if(pFile != NULL)
		{
			retorno = 0;
			for(int i=0; i<len; i++)
			{
				pEmpleado = ll_get(pArrayListEmployee, i);
				fwrite(pEmpleado, sizeof(Employee), 1, pFile);
			}
		}
	}
	fclose(pFile);
	return retorno;
}























