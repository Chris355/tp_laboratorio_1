#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "utn.h"


int menu(int* pOption)
{
	int retorno = -1;
	int option;
  char mensajeErrorMenu[1024] = "Error! opcion invalida.\n";
  char mensajeMenu[1024] = "\n"
                                  "\n===== Menú de Opciones ================ "
                                  "\n 1 - Cargar los datos (modo texto) "
                                  "\n 2 - Cargar los datos (modo binario) "
																	"\n 3 - Alta de empleado "
                                  "\n 4 - Modificar datos de empleado "
                                  "\n 5 - Baja de empleado "
                                  "\n 6 - Listar empleados "
                                  "\n 7 - Ordenar empleados "
                                  "\n 8 - Guardar los datos (modo texto) "
                                  "\n 9 - Guardar los datos (modo binario)  "
                                  "\n10 - Salir"
                                  "\n======================================= "
                                  "\n";
	if(utn_getInt(&option, mensajeMenu, mensajeErrorMenu, MIN_MENU, MAX_MENU, RETRY)==0)
	{
		*pOption = option;
		retorno = 0;
	}
  return retorno;
}
