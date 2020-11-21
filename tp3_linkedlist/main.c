#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"
#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int main()
{
	int option = 0;
	int lenEmpleados;
	LinkedList* listaEmpleados = ll_newLinkedList();


//	if(controller_loadFromText("hardCode.csv",listaEmpleados)==0)
//	{
//		printf("\n----Test: HardCode de 10 empleados----\n");
//	}

	do{
			if(menu(&option)==0)
			{
				switch(option)
				{
					case 1: //1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
						if(controller_loadFromText("data.csv",listaEmpleados)==0)
						{
							printf("\n----Carga correcta!----\n");
						}
						break;
					case 2: //2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
						if(controller_loadFromBinary("data.bin",listaEmpleados)==0)
						{
							printf("\n----Carga correcta!----\n");
						}
						break;
					case 3: //3. Alta de empleado
						if(controller_addEmployee(listaEmpleados)==0)
						{
							lenEmpleados = ll_len(listaEmpleados);
							printf("\n----Alta correcta!----\n");
							printf("\n>> La cantidad de la lista es: %d\n", lenEmpleados);
						}
						break;
					case 4: //4. Modificar datos de empleado
						if(controller_editEmployee(listaEmpleados)==0)
						{
							printf("\n----Modificacion correcta!----\n");
						}
						break;
					case 5: //5. Baja de empleado
						if(controller_removeEmployee(listaEmpleados)==0)
						{
							printf("\n----Baja correcta!----\n");
						}
						break;
					case 6: //6. Listar empleados
						lenEmpleados = ll_len(listaEmpleados);
						if(controller_ListEmployee(listaEmpleados)==0)
						{
							printf("\n>> La cantidad de la lista es: %d\n", lenEmpleados);
						}
						break;
					case 7: //7. Ordenar empleados
						if(controller_sortEmployee(listaEmpleados)==0)
						{
							printf("\n----Orden correcto!----\n");
						}
						break;
					case 8: //8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
						if(controller_saveAsText("data.csv", listaEmpleados)==0)
						{
							printf("\n----Datos guardados!----\n");
						}
						break;
					case 9: //9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
						if(controller_saveAsBinary("data.bin", listaEmpleados)==0)
						{
							printf("\n----Datos guardados!----\n");
						}
						break;
				}
			}
	}while(option != 10);


	return 0;

}
