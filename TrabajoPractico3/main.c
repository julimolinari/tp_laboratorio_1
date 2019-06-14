#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "funciones.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
//carga fscanf - descarga fprintf---- alta pedir datos, verificar y construir un emp en memoria
//llamamos al constructor, si se dvalida con el add incorporoo al arraylist
//modificacion- obtener al empleado-- hacef funcion para encontrar emplaso x id-- findById, te paso array y id, me encontras al empleado
//uso la misma para la baja, pido id dar de baja findByid(rcorre y ve si coincide el id)devuelve el indice con retorno! != -1
//listar
//ordenar . el arraylist sabe ordenarse. le pasamos que(el arralist) y bajo que CRITERIO-recibe dos empleados y devuelve un numero
//funcion sort(lepaso el nombre de la funcion criterio), puntero a funcion criterio, implementa una forma de ordenar
//guardar -en modo binario..pedir al arraaylist el primero entre 0 y el len un for, tengo el primer puntero a archivo
//y guardo no el puntero si no al empeado.. con ese puntero se lo paso a write con * con size of empleado
//cuando leo del puntero l guardo en un puntero empleado
int main()
{
    int option = 0;
    int flag= 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        getIntInRange(&option,"\n1)Cargar Empleados: \n"
                      "2)Cargar Empleados (modo binario): \n"
                      "3)Agregar Empleado por consola: \n"
                      "4)Listar empleados: \n"
                      "5)Eliminar empleado por ID: \n"
                      "6)Modificar empleado por ID: \n"
                      "7)Ordenar Alfabeticamente: \n"
                      "8)Guardar archivo: \n"
                      "9)Guardar archivo(modo binario): \n"
                      "10)Salir\n","ERROR\n",1,10,3);
        switch(option)
        {
        case 1:
            if(flag == 0)
            {
                if(!controller_loadFromText("data.csv",listaEmpleados))
                {
                    flag=1;
                }
                else
                {
                    printf("No se cargo el archivo\n-------");
                }
            }
            else
                printf("\nYa se cargo este archivo\n-------");

            break;
        case 2:
            if(flag == 0)
            {
                if(!controller_loadFromBinary("data.bin",listaEmpleados))
                {
                    flag = 1;
                    printf("\nCarga completa\n-------");
                }
                else
                {
                    printf("\nNo se cargo el archivo binario\n-------");
                }
            }else
            printf("\nYa se cargo este archivo\n-------");

            break;
        case 3:
            if(!controller_addEmployee(listaEmpleados))
            {
                flag = 1;
                printf("\nCarga del empleado completa\n-------");
            }
            else
            {
                printf("\nNo se cargo el empleado\n-------");
            }
            break;
        case 4:
            if(flag != 0)
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("\nNo encontraron registros\n-------");
            }

            break;
        case 5:
            if(flag != 0)
            {
                controller_removeEmployee(listaEmpleados);
            }
            else
            {
                printf("\nNo encontraron registros\n-------");
            }

            break;
        case 6:
            if(flag != 0)
            {
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("\nNo encontraron registros\n-------");
            }

            break;
        case 7:
            if(flag != 0)
            {
                ll_sort(listaEmpleados,employee_compararPorNombre,1);//0 - descendente
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("\nNo encontraron registros\n-------");
            }

            break;
        case 8:
            if(flag != 0)
            {
                controller_saveAsText("databkp.csv",listaEmpleados);
                printf("\nArchivo de texto guardado\n-------");
                flag=2;
            }
            else
            {
                printf("\nNo encontraron registros nuevos\n-------");
            }

            break;
        case 9:
            if(flag != 0)
            {
                controller_saveAsBinary("data.bin",listaEmpleados);
                printf("\nArchivo binario guardado\n-------");
                flag=2;
            }
            else
            {
                printf("\nNo encontraron registros nuevos\n-------");
            }

            break;
        }
    }
    while(option != 10);
    return 0;
}
