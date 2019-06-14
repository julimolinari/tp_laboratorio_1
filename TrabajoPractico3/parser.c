#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char bufferId[500];
    char bufferHoras[500];
    char bufferSueldo[500];
    char bufferNombre[500];
    int r=0;

    Employee *pAuxEmpleado;

    if(pFile!= NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferHoras,bufferSueldo);

            if(r==0)
            {
                r++;
                continue;
            }

            pAuxEmpleado = employee_newParametros(bufferId,bufferNombre,bufferHoras,bufferSueldo);
            if(pAuxEmpleado != NULL)
            {
                ll_add(pArrayListEmployee,pAuxEmpleado);
                retorno = 0;
            }
        }
    }
    return retorno;
}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
//primero generar el binario, el que escribe, no puntero si no lo apuntado por el(file write)
    int retorno = -1;
    Employee auxEmpleado;
    Employee* pEmpleado;

    if(pFile != NULL && pArrayListEmployee != NULL)
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

                retorno = 0;

    }
    fclose(pFile);
    return  retorno;
}
