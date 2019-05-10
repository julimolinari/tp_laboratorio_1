/*******************************************************************
*Programa:ABM Empleados
*
*Objetivo:
Ingresar, modificar, borrar o listar emplados. 
*
*Version:0.1del10Mayo2019
*Autor:JulietaMolinari
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include "employee.h"
#include "funciones.h"
#define EMPLOYEE_LEN 10

int main()
{
    Employee employee[EMPLOYEE_LEN];
    initEmployees(employee,EMPLOYEE_LEN);
    int opcion = 0;
    int id = 0;
    while(opcion!=5)
    {
        getIntInRange(&opcion,"\n1)Alta empleado: \n"
                      "2)Modificar datos del empleado por ID: \n"
                      "3)Baja de empleado: \n"
                      "4)Informar: \n"
                      "5)Salir\n","ERROR\n",1,8,3);
        switch(opcion)
        {
            case 1:
                {
                    int libre = emp_freeI(employee,EMPLOYEE_LEN);

                    if(libre >= 0)
                    {
                         printf("\n----Hay lugar----\n");
                         if(emp_add(employee,EMPLOYEE_LEN,libre,"----Valor invalido----",3)== 0)
                            {
                                employee[libre].id = id;
                                id++;
                                break;
                            }
                    }
                    break;
                }
            case 2:
                {
                    if(emp_isEmptyValid(employee,EMPLOYEE_LEN) != 1)
                    {
                            if(emp_alter(employee,EMPLOYEE_LEN,"----Empleado no encontrado----",3)==0)
                        {
                            printf("----Empleado Actualizado Exitosamente!----");
                        }
                    }else
                    {
                        printf("\n----El listado se encuentra vacio----\n");
                    }

                    break;
                }
            case 3:
                {
                    if(emp_isEmptyValid(employee,EMPLOYEE_LEN) != 1)
                    {
                       if(emp_remove(employee,EMPLOYEE_LEN,"----No se encontro empleado----",3)==0)
                       {
                           printf("----Empleado eliminado----");
                       }
                    }else
                    {
                        printf("\n----El listado se encuentra vacio----\n");
                    }
                   break;
                }
            case 4:
                {
                    if(emp_isEmptyValid(employee,EMPLOYEE_LEN) != 1)
                    {
                        emp_inform(employee,EMPLOYEE_LEN,"Valor invalido",3);
                        //emp_print(employee,EMPLOYEE_LEN);
                    }else
                    {
                        printf("\n----El listado se encuentra vacio----\n");
                    }


                    break;
                }
        }


    }

    return 0;
}
