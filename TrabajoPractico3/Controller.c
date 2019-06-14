#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "funciones.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile = NULL;
    int len = 0;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen (path, "rw");
        if(pFile != NULL)
        {
            if (parser_EmployeeFromText(pFile,pArrayListEmployee)==0)
            {
                retorno=0;
                len = ll_len(pArrayListEmployee);
                printf("\nRegistros Cargados: %d%s",len,"\n-------");
            }
        }
        fclose (pFile);
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
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    //pFile = fopen (path, "rb ");
    int retorno = -1;
    int len = 0;
    FILE *pFile = NULL;
    Employee auxEmpleado;
    Employee* pEmpleado;


    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "rb");
        if(pFile != NULL)
        {
            while(!feof(pFile))
            {
                pEmpleado = employee_new();
                fread(&auxEmpleado,sizeof(Employee),1,pFile);
                if( !employee_setId(pEmpleado,auxEmpleado.id) &&
                    !employee_setNombre(pEmpleado,auxEmpleado.nombre) &&
                    !employee_setHorasTrabajadas(pEmpleado,auxEmpleado.horasTrabajadas) &&
                    !employee_setSueldo(pEmpleado,auxEmpleado.sueldo))
                {
                     ll_add(pArrayListEmployee,pEmpleado);

                }

                else
                {
                    employee_delete(pEmpleado);
                }

            }

            len = ll_len(pArrayListEmployee);
            ll_remove(pArrayListEmployee,len -1);
            printf("\nRegistros Cargados: %d",len -1);
            retorno = 0;
        }
        fclose(pFile);
        //ll_sort(pArrayListEmployee,employee_compararPorNombre,0);
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
    int reintentos = 3;
    char msgE[20];
    strcpy(msgE,"Valor invalido");
    char bufferHoras[500];
    char bufferSueldo[500];
    char bufferNombre[500];
    int auxSueldo;
    int auxHoras;
    int idMax;

    Employee* pAuxEmployee = employee_new();

    if((pArrayListEmployee!=NULL))
    {
        if( getStringLetras(bufferNombre,"\nIngrese Nombre: ",msgE,reintentos)==0)
        {
            if(getStringNumeros(bufferSueldo,"\nIngrese Sueldo: ",msgE,reintentos,-1,-1)==0)
            {
                if(getStringNumeros(bufferHoras,"\nIngrese Horas Trabajadas: ",msgE,reintentos,-1,-1)==0)
                {
                    auxSueldo = atoi(bufferSueldo);
                    auxHoras = atoi(bufferHoras);
                    employee_setNombre(pAuxEmployee,bufferNombre);
                    employee_setSueldo(pAuxEmployee,auxSueldo);
                    employee_setHorasTrabajadas(pAuxEmployee,auxHoras);
                    idMax = controller_getLastId(pArrayListEmployee);
                    employee_setId(pAuxEmployee,idMax + 1);

                    ll_add(pArrayListEmployee,pAuxEmployee);

                    retorno=0;
                }
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
    int retorno= -1;
    int opcion = 0;
    int posModif;
    int reintentos= 3;
    char auxId[500];
    char auxSueldo[500];
    char auxHoras[500];
    char msgE[20];
    strcpy(msgE,"Valor invalido");
    char bufferNombre[500];
    int bufferSueldo;
    int bufferHoras;
    int bufferId;

    Employee* pEmpleado;

    if(pArrayListEmployee != NULL)
    {
        if(getStringNumeros(auxId,"\nIngrese ID del empleado que quiere modificar: ","ID no valido",3,-1,-1)==0)
        {
            posModif = controller_findById(pArrayListEmployee, atoi(auxId));
            pEmpleado = ll_get(pArrayListEmployee,posModif);


            if(pEmpleado != NULL && posModif >= 0)
            {
                   printf("\nEMPLEADO SELECCIONADO: \n-------");
                   employee_getNombre(pEmpleado,bufferNombre);
                   employee_getId(pEmpleado,&bufferId);
                   employee_getSueldo(pEmpleado,&bufferSueldo);
                   employee_getHorasTrabajadas(pEmpleado,&bufferHoras);

                   printf("\nID: %d\nNombre: %s\nHoras Trabajadas: %d\nSueldo: %d\n-------",
                          bufferId,bufferNombre,bufferHoras,bufferSueldo);
                while(opcion!=4)
                {
                    printf("\n1- Modificar Nombre\n");
                    printf("2- Modificar Horas Trabajadas\n");
                    printf("3- Modificar Sueldo\n");
                    printf("4- Atras (Menu Principal)\n");
                    getIntInRange(&opcion,"\n   INGRESE OPCION (Menu Modificacion): ",msgE,1,4,3);
                    switch(opcion)
                    {
                    case 1:
                    {
                        if(!getStringLetras(bufferNombre,"\nIngrese NUEVO Nombre: ",msgE,reintentos))
                        {
                            employee_setNombre(pEmpleado,bufferNombre);
                            retorno=0;
                        }
                        break;
                    }
                    case 2:
                    {
                        if(!getStringNumeros(auxSueldo,"\nIngrese NUEVO Sueldo: ",msgE,reintentos,-1,-1))
                        {
                            employee_setSueldo(pEmpleado,atoi(auxSueldo));
                            retorno=0;
                        }
                        break;
                    }
                    case 3:
                    {
                        if(getStringNumeros(auxHoras,"\nIngrese NUEVAS Horas Trabajadas: ",msgE,reintentos,-1,-1)==0)
                        {
                            employee_setHorasTrabajadas(pEmpleado,atoi(auxHoras));
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

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    // usar funcion ll_pop
    int retorno= -1;
    int posDelete;
    char bufferId[500];

    Employee* pEmpleado;

    if(pArrayListEmployee != NULL)
    {
        if(getStringNumeros(bufferId,"\nIngrese ID que quiere eliminar: ","ID no valido",3,-1,-1)==0)
        {
            posDelete = controller_findById(pArrayListEmployee, atoi(bufferId));
            pEmpleado = ll_pop(pArrayListEmployee,posDelete);
            if(pEmpleado != NULL && posDelete >= 0)
            {
                employee_delete(pEmpleado);
                printf("\nEl empleado fue eliminado\n-------");
                retorno = 0;
            }
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
    int len;
    char bufferNombre[500];
    int bufferSueldo;
    int bufferHoras;
    int bufferId;

    len = ll_len(pArrayListEmployee);
    Employee* pEmpleado;
    if(pArrayListEmployee != NULL)
    {
        for(i=0; i<len; i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            employee_getNombre(pEmpleado,bufferNombre);
            employee_getId(pEmpleado,&bufferId);
            employee_getSueldo(pEmpleado,&bufferSueldo);
            employee_getHorasTrabajadas(pEmpleado,&bufferHoras);

            printf("\nID: %d\nNombre: %s\nHoras Trabajadas: %d\nSueldo: %d\n-------",
                   bufferId,bufferNombre,bufferHoras,bufferSueldo);
        }
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
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int len=0;
    int bufferId;
    char bufferNombre[500];
    int bufferSueldo;
    char bufferHoras[500];
    int auxHoras;
    Employee *pEmployee=NULL;
    FILE *pFileBkp = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFileBkp = fopen(path,"wb");
        if(pFileBkp != NULL)
        {
            len = ll_len(pArrayListEmployee);
            auxHoras = atoi(bufferHoras);
            for(i=0;i<len;i++)
            {
                pEmployee = ll_get(pArrayListEmployee,i);
                if(pEmployee != NULL)
                {
                    employee_getId(pEmployee,&bufferId);
                    employee_getNombre(pEmployee,bufferNombre);
                    employee_getSueldo(pEmployee,&bufferSueldo);
                    employee_setHorasTrabajadas(pEmployee,auxHoras);
                    if(bufferId>0 && bufferNombre != NULL && bufferSueldo >=0 && auxHoras>= 0)
                    {
                        fprintf(pFileBkp,"%d,%s,%d,%d\n",bufferId,bufferNombre,auxHoras,bufferSueldo);
                    }else
                    {
                        employee_delete(pEmployee);
                    }

                }
            }
        }
        retorno = 0;
        fclose(pFileBkp);
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
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    Employee *pEmployee=NULL;
    FILE *pFile = NULL;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "wb");
        if(pFile != NULL)
        {
            for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
                pEmployee = ll_get(pArrayListEmployee,i);
                fwrite(pEmployee,sizeof(Employee),1,pFile);
            }
        }
        retorno = 0;
        fclose(pFile);
    }



    return retorno;
}

int controller_getLastId(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int len;
    Employee* pEmp;
    int auxId;

    len = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            pEmp = ll_get(pArrayListEmployee,i);
            employee_getId(pEmp,&auxId);
            if(auxId> retorno )
            {
                retorno = auxId;
            }
        }

    }
    return retorno;
}

int controller_findById(LinkedList* pArrayListEmployee,int idBuscado)
{
    int retorno = -1;
    int i;
    int len;
    int bufferId;

    len = ll_len(pArrayListEmployee);
    Employee* pEmpleado;

    if(pArrayListEmployee != NULL && idBuscado > 0)
    {
        for(i=0; i<len; i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&bufferId);

            if(bufferId == idBuscado)
            {
                retorno= i;
                break;
            }
        }
    }
    return retorno;
}
