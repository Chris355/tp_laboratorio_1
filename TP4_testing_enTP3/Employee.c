#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include <string.h>
#include "validations.h"

/*********************** CONTRUCTOR & DESTRUCTOR ******************************************/

//----------------------- employee_newDefault -------------------------------------------------
/**
 * \brief Crea un employee por defecto
 * \return pEmployee: Employee generado
*/
Employee* employee_newDefault(void)
{
  Employee* pNewEmployee;
  pNewEmployee = (Employee*)malloc(sizeof(Employee));
  if (pNewEmployee != NULL)
  {
    pNewEmployee->id=0;
    strncpy(pNewEmployee->nombre, "/0", sizeof(pNewEmployee->nombre));
    pNewEmployee->horasTrabajadas=0;
    pNewEmployee->sueldo=0;
  }
  return pNewEmployee;
}

//----------------------- employee_newConParametros -------------------------------------------------
/**
 * \brief Crea un employee con los datos obtenidos por parametros
 * \return pEmployee: Employee generado
*/
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
  Employee* pNewEmployee = NULL;
  if(nombreStr!=NULL && horasTrabajadasStr!=NULL && idStr!=NULL && sueldoStr!=NULL)
  {
    pNewEmployee = employee_newDefault();
    if(pNewEmployee != NULL)
    {
    	pNewEmployee->id = atoi(idStr);
      strncpy(pNewEmployee->nombre, nombreStr, (int)sizeof(pNewEmployee->nombre));
      pNewEmployee->horasTrabajadas = atoi(horasTrabajadasStr);
      pNewEmployee->sueldo = atoi(sueldoStr);
    }
  }
  return pNewEmployee;
}

//----------------------- employee_delete -------------------------------------------------
/**
 * \brief Borra un empleado
 * \param pEmployee: Employee a borrar
*/
void employee_delete(Employee* this)
{
  if(this != NULL)
    free(this);
}



/*********************** SETTERS & GETTERS ******************************************/

//----------------------- employee_setId -------------------------------------------------
/**
 * \brief setea y valida ID
 * \param this
 * \param id
*/
int employee_setId(Employee* this,int id)
{
	int retorno  = -1;
  if(this != NULL && id > 0)
  {
  	this->id = id;
  	retorno = 0;
  }
  return retorno;
}

//----------------------- employee_getId -------------------------------------------------
/**
 * \brief lee y valida ID
 * \param this
 * \param id
*/
int employee_getId(Employee* this,int* id)
{
	int retorno  = -1;
  if(this != NULL && id != NULL)
  {
  	*id = this->id;
  	retorno = 0;
  }
  return retorno;
}

//----------------------- employee_setNombre -------------------------------------------------
/**
 * \brief setea y valida el nombre
 * \param this
 * \param nombre
*/
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno  = -1;
  if(this != NULL && nombre != NULL && esUnNombreValido(nombre)==TRUE)
  {
  	strncpy(this->nombre, nombre, SIZE_STRING);
  	retorno = 0;
  }
  return retorno;
}

//----------------------- employee_getNombre -------------------------------------------------
/**
 * \brief lee y valida el nombre
 * \param this
 * \param nombre
*/
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno  = -1;
  if(this != NULL && nombre != NULL)
  {
  	strncpy(nombre, this->nombre, SIZE_STRING);
  	retorno = 0;
  }
  return retorno;
}

//----------------------- employee_setHorasTrabajadas -------------------------------------------------
/**
 * \brief setea y valida el campo horas trabajadas
 * \param this
 * \param horasTrabajadas
*/
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno  = -1;
  if(this != NULL && horasTrabajadas > 0)
  {
  	this->horasTrabajadas = horasTrabajadas;
  	retorno = 0;
  }
  return retorno;
}

//----------------------- employee_getHorasTrabajadas -------------------------------------------------
/**
 * \brief lee y valida el campo horas trabajadas
 * \param this
 * \param horasTrabajadas
*/
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno  = -1;
  if(this != NULL && horasTrabajadas != NULL)
  {
  	*horasTrabajadas = this->horasTrabajadas;
  	retorno = 0;
  }
  return retorno;
}

//----------------------- employee_setSueldo -------------------------------------------------
/**
 * \brief setea y valida el campo sueldo
 * \param this
 * \param sueldo
*/
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno  = -1;
  if(this != NULL && sueldo > 0)
  {
  	this->sueldo = sueldo;
  	retorno = 0;
  }
  return retorno;
}

//----------------------- employee_getSueldo -------------------------------------------------
/**
 * \brief lee y valida el campo sueldo
 * \param this
 * \param sueldo
*/
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno  = -1;
  if(this != NULL && sueldo != NULL)
  {
  	*sueldo = this->sueldo;
  	retorno = 0;
  }
  return retorno;
}







/*********************** FUNCIONES ABM ******************************************/

//----------------------- generarIdNuevo -------------------------------------------------
/**
 * \brief Cada vez que la llamo me devuelve un ID nuevo que nunca me devolvio antes.
 * \return idCliente generado
*/
int employee_generarIdNuevo(void)
{
  static int id = 1000; //variable global de la funcion
  id = id+1;
  return id;
}

//----------------------- employee_printOne ----------------------------------------------
/**
 * \brief Imprime los empleados cargados
 * \param Employee* pArrayEmployees, Es el puntero al array de empleados
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 *
*/
int employee_printOne(Employee* pEmployee)
{
  int retorno = -1;
  int auxId;
  char auxNombre[SIZE_STRING];
  int auxHoras;
  int auxSueldo;

  if( pEmployee != NULL &&
    	employee_getId(pEmployee, &auxId) == 0 &&
  		employee_getNombre(pEmployee, auxNombre) == 0 &&
  		employee_getHorasTrabajadas(pEmployee, &auxHoras) == 0 &&
  		employee_getSueldo(pEmployee, &auxSueldo) == 0 )
  {
		printf( "%d %15s %8d %8d\n", auxId, auxNombre, auxHoras, auxSueldo );
    retorno = 0;
  }
  return retorno;
}

//----------------------- employee_cmpNombre ----------------------------------------------
/**
 * \brief compara 2 nombres de entidad
 * \param void* thisA
 * \param void* thisB
 * \return (-1) Error / (0) Ok / (1) Ok
 *
*/
int employee_cmpNombre(void* thisA, void* thisB)
{
	int retorno = 0;
	int returnStrcmp;
	char bufferNombreA[SIZE_STRING];
	char bufferNombreB[SIZE_STRING];

	if(thisA != NULL && thisB != NULL)
	{
		employee_getNombre((Employee*)thisA, bufferNombreA);
		employee_getNombre((Employee*)thisB, bufferNombreB);
		returnStrcmp = strcmp(bufferNombreA, bufferNombreB);

		if(returnStrcmp > 0)
		{
			retorno = 1;
		}
		else if(returnStrcmp < 0)
		{
			retorno = -1;
		}
		else
		{
			retorno = 0;
		}
	}
	return retorno;
}








