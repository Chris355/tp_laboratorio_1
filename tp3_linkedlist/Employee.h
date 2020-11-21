#include <stdio.h>
#include <stdlib.h>

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#define RETRY 2
#define SIZE_STRING 50
#define QTY_EMPLEADOS 2000
#define UP 1
#define DOWN 0
#define MIN_SUELDO 100
#define MAX_SUELDO 1000000
#define MIN_HORAS 10
#define MAX_HORAS 500

typedef struct
{
    int id;
    char nombre[SIZE_STRING];
    int horasTrabajadas;
    int sueldo;
}Employee;

/***************************************************************************************/

Employee* employee_newDefault(void);
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

/***************************************************************************************/

int employee_generarIdNuevo(void);
int employee_printOne(Employee* pEmployee);
int employee_altaForzada(Employee* pEmployee, char* id, char* nombre, char* horas, char* sueldo);
int employee_cmpNombre(void* thisA, void* thisB);




int employee_initArray(Employee* pArrayEmployees[], int limite);
int employee_alta(Employee* pArrayEmployees[], int limite);


int employee_buscarLibre(Employee* pArrayEmployees[], int limite, int* pIndice);
int employee_buscarPorId(Employee* pArrayEmployees[], int limite, int idEmployee);
int employee_modificar(Employee* pArrayEmployees[], int limite);
int employee_baja(Employee* pArrayEmployees[], int limite, int indice);
int employee_imprimir(Employee* pArrayEmployees[], int limite);
int employee_imprimirPorIndice(Employee* pArrayEmployees[], int limite, int indice);
int employee_imprimirPorId(Employee* pArrayEmployees[], int limite, int id);
int employee_ordenarPorNombre(Employee* pArrayEmployees, int limite, int orden);

#endif // employee_H_INCLUDED
