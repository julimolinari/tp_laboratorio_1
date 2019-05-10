#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "funciones.h"


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
    if ( list != NULL && len > 0 )
    {
        int i;
        for( i=0 ; i < len; i++)
        {
            list[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}




/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param lista employee*
 * \param len int
 * \param indice int
 * \param msgE char[]
 * \param reintentos int
 * \param id int
 * \param Nombre[] char
 * \param lastNombre[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 **/
int emp_add(Employee* listaEmployee,int len,int indice,char* msgE,int reintentos)
{
    char bufferNombre[50];
    char bufferApellido[50];
    char bufferSalario[10];
    char bufferSector[3];
    int auxSector;
    int retorno=-1;

    if((listaEmployee!=NULL)&&(len>0))
    {
        if( getStringLetras(bufferNombre,"\nIngrese Nombre: ",msgE,reintentos)==0)
        {
            if(getStringLetras(bufferApellido,"\nIngrese Apellido: ",msgE,reintentos)==0)
            {
                strncpy(listaEmployee[indice].apellido,bufferApellido,sizeof(bufferApellido));
            }
            if(getStringNumerosFloat(bufferSalario,"\nIngrese Salario: ",msgE,reintentos)==0)
            {

                float auxSalario = (float)strtod(bufferSalario,NULL);
                if(getStringNumeros(bufferSector,"\nIngrese Sector: ",msgE,reintentos)==0)
                {
                    auxSector = atoi(bufferSector);
                    strncpy(listaEmployee[indice].nombre,bufferNombre,sizeof(bufferNombre));
                    listaEmployee[indice].salario = auxSalario;
                    listaEmployee[indice].sector = auxSector;
                    //listaEmployee[indice].id = 0;
                    listaEmployee[indice].isEmpty = 0;
                    retorno=0;
                }
            }
        }
    }
    return retorno;
}

/** \brief imprime lista de empleados
 * \param lista employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 **/
int emp_print(Employee* listaEmployee,int len)
{
    int i;
    int flag=1;
    for(i=0; i<len; i++)
    {
        if(listaEmployee[i].isEmpty==0)
        {
            printf("\nID: %d\nNombre: %s\nApellido: %s\nSalario: %.2f\nSector: %d\n-------",
                   listaEmployee[i].id,listaEmployee[i].nombre,listaEmployee[i].apellido,listaEmployee[i].salario,listaEmployee[i].sector);
            flag=0;
        }
    }
    if(flag)
    {
        printf("\n----El listado se encuentra vacio----\n");
    }
    return 0;
}


/** \brief busca que posicion del array esta libre
 * \param lista employee*
 * \param len int
 * \return int return retorna poscicion libre
 **/
int emp_freeI(Employee* listaEmployee,int len)
{
    int i;
    int retorno=-1;
    for(i=0; i<len; i++)
    {
        if(listaEmployee[i].isEmpty==1)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}



/** \brief busca un ID
 * \param lista employee*
 * \param len int
 * \param indice int
 * \param msgE char[]
 * \param reintentos int
 * \param id int
 * \param Nombre[] char
 * \param lastNombre[] char
 * \param salary float
 * \param sector int
 * \return int return el ID buscado
 **/
int emp_getID (Employee* listaEmployee,int len,char* msgE,int tries)
{
    int retorno=-1;
    char bufferID[20];
    int auxID;
    if(listaEmployee!=NULL && len>0)
    {
        if(!getStringNumeros(bufferID,"\nIngrese ID: ",msgE,tries))
        {
            auxID=atoi(bufferID);
            retorno=auxID;
        }
    }
    return retorno;
}



/** \brief permite modificar los empleados
 * \param lista employee*
 * \param len int
 * \param msgE char[]
 * \param tries int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 **/
int emp_alter(Employee* listaEmployee, int len,char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int opcion=0;
    char bufferNombre[50];
    char bufferApellido[50];
    char bufferSalario[10];
    char bufferSector[3];
    float auxSalario;
    int auxSector;
    int retorno=-1;

    if((listaEmployee!=NULL)&&(len>0))
    {
        auxID=emp_getID(listaEmployee,len,msgE,tries);
        if(auxID>=0)
        {
            posOfID=emp_findById(listaEmployee,len,auxID);
            if(posOfID!=-1)
            {
                while(opcion!=5)
                {
                    printf("\n1- Modificar Nombre\n");
                    printf("2- Modificar Apellido\n");
                    printf("3- Modificar Salario\n");
                    printf("4- Modificar Sector\n");
                    printf("5- Atras (Menu Principal)\n");
                    getIntInRange(&opcion,"\n   INGRESE OPCION (Menu Modificacion): ",msgE,1,5,tries);
                    switch(opcion)
                    {
                    case 1:
                    {
                        if(!getStringLetras(bufferNombre,"\nIngrese NUEVO Nombre: ",msgE,tries))
                        {
                            strncpy(listaEmployee[posOfID].nombre,bufferNombre,sizeof(bufferNombre));
                            retorno=0;
                        }
                        break;
                    }
                    case 2:
                    {
                        if(!getStringLetras(bufferApellido,"\nIngrese NUEVO Apellido: ",msgE,tries))
                        {
                            strncpy(listaEmployee[posOfID].apellido,bufferApellido,sizeof(bufferApellido));
                            retorno=0;
                        }
                        break;
                    }
                    case 3:
                    {
                        if(!getStringNumerosFloat(bufferSalario,"\nIngrese NUEVO Salario: ",msgE,tries))
                        {
                            auxSalario=atof(bufferSalario);
                            listaEmployee[posOfID].salario=auxSalario;
                            retorno=0;
                        }
                        break;
                    }
                    case 4:
                    {
                        if(!getStringNumeros(bufferSector,"\nIngrese NUEVO Sector: ",msgE,tries))
                        {
                            auxSector=atoi(bufferSector);
                            listaEmployee[posOfID].sector=auxSector;
                            retorno=0;
                        }
                        break;
                    }
                    }
                }
            }
            else
            {
                printf("\n----No se encontro el ID!-----\n");
            }
        }
    }
    return retorno;
}



/** \brief busca posicion del empleado pasandole su ID
 * \param lista employee*
 * \param len int
 * \param idE int
 * \return int Return devuelve posicion
 **/
int emp_findById(Employee* listaEmployee, int len, int idE)
{
    int i;
    int ret=-1;
    for(i=0; i<len; i++)
    {
        if(listaEmployee[i].id == idE)
        {
            ret=i;
            break;
        }
    }
    return ret;
}


/** \brief permite elminar empleados por ID
 * \param lista employee*
 * \param len int
 * \param msgE char[]
 * \param tries int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 **/
int emp_remove(Employee* listaEmployee, int len,char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int retorno=-1;
    if(listaEmployee!=NULL && len>0)
    {
        auxID=emp_getID(listaEmployee,len,msgE,tries);
        if(auxID>=0)
        {
            posOfID=emp_findById(listaEmployee,len,auxID);
            if(posOfID!=-1)
            {
                listaEmployee[posOfID].isEmpty=1;
                retorno=0;
            }
        }
    }
    return retorno;
}


/** \brief muestra informes, con distintos filtros
 * \param lista employee*
 * \param len int
 * \param msgE char[]
 * \param tries int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 **/
int emp_inform(Employee* listaEmployee, int len,char* msgE,int tries)
{
    int opcion=0;
    int retorno=-1;

            if((listaEmployee!=NULL)&&(len>0))
            {
                while(opcion!=3)
                {
                    printf("\n1- Empleados ordenados alfabeticamente por Apellido y Sector\n");
                    printf("2- Total y promedio de los salarios\n");
                    printf("3- Salir\n");
                    getIntInRange(&opcion,"\n   INGRESE OPCION (Menu Modificacion): ",msgE,1,3,tries);
                    switch(opcion)
                    {
                        case 1:
                        {
                            emp_ordenarAlfa(listaEmployee,len);
                            break;
                        }
                        case 2:
                        {
                            emp_totalPromedio(listaEmployee,len);
                            break;
                        }
                    }
                }
            }

    return retorno;
}


/** \brief ordena empleados por apellido y sector
 * \param lista employee*
 * \param len int
 * \param msgE char[]
 * \param tries int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 **/
int emp_ordenarAlfa(Employee* listaEmployee,int len)
{
    int retorno = -1;
    Employee auxEmployee;
    int i;
    int j;
    for(i=0; i < len -1 ; i ++)
    {
        for(j=i+1; j<len  ; j++)
        {
            if(stricmp(listaEmployee[i].apellido,listaEmployee[j].apellido) > 0)
            {
                auxEmployee = listaEmployee[i];
                listaEmployee[i] = listaEmployee[j];
                listaEmployee[j] = auxEmployee;
                retorno = 0;
            } else if(stricmp(listaEmployee[i].apellido,listaEmployee[j].apellido) == 0)
            {
                if(listaEmployee[i].sector>listaEmployee[j].sector)
                {
                    auxEmployee = listaEmployee[i];
                    listaEmployee[i] = listaEmployee[j];
                    listaEmployee[j] = auxEmployee;
                    retorno = 0;
                }
            }
        }
    }
    emp_print(listaEmployee,len);
    return retorno;
}


/** \brief averigua el sueldo total, su promedio y cantidad de empleados por encima de ese promedio
 * \param lista employee*
 * \param len int
 * \param msgE char[]
 * \param tries int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 **/
int emp_totalPromedio(Employee* listaEmployee,int len)
{
    float auxSalario = 0;
    int auxCantidadEmpleados = 0;
    float promedio;
    int cont = 0;
    int i;
    int j;
    for(i=0; i < len  ; i ++)
    {
        if(listaEmployee[i].isEmpty == 0)
        {
            auxSalario = listaEmployee[i].salario + auxSalario;
            auxCantidadEmpleados ++;
        }
    }
    promedio = auxSalario / auxCantidadEmpleados;

    printf("\n-Total Salarios:  %.2f\n",auxSalario);
    printf("-Promedio de los Salarios: %.2f\n",promedio);

    for(j=0; j < len ; j ++)
    {
        if(listaEmployee[j].salario>promedio)
        {
            cont++;
        }
    }
    printf("-De los %d empleados, %d superan el salario promedio\n",auxCantidadEmpleados,cont);
    return 0;
}


/** \brief se fija si la lista esta vacia
 * \param lista employee*
 * \param len int
 * \return int Return (1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 **/
int emp_isEmptyValid(Employee* listaEmployee,int len)
{
    int i;
    int flag=1;
    for(i=0; i<len; i++)
    {
        if(listaEmployee[i].isEmpty==0)
        {
            flag=0;
        }
    }
    return flag;
}
