#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "funciones.h"


/** \brief Crea un nuevo empleado
 *
 * \return Empleado nuevo
 *
 */
Employee* employee_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}

/** \brief Crea empleados cargandole los parametros
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Empleado nuevo
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* retorno = NULL;
    Employee* pAuxEmployee;
    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        pAuxEmployee = employee_new();
        if(pAuxEmployee != NULL)
        {
            if(!employee_setNombre(pAuxEmployee,nombreStr) &&
               !employee_setHorasTrabajadas(pAuxEmployee,atoi(horasTrabajadasStr)) &&
               !employee_setSueldo(pAuxEmployee,atoi(sueldoStr)) &&
               !employee_setId(pAuxEmployee,atoi(idStr)))
            {
                retorno = pAuxEmployee;
            }else
            {
                employee_delete(pAuxEmployee);
            }
        }
    }
    return retorno;
}

/** \brief Elimina a un empleado pasado por parametro
 *
 * \return void
 *
 */
void employee_delete(Employee * this)
{
    if(this != NULL)
    {
        free(this);

    }
}

/** \brief Asigna id en el empleado indicado
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* this,int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene id del empleado indicado
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* this,int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Asigna nombre en el empleado indicado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene nombre del empleado indicado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 0;
    }
    return retorno;
}

/** \brief Asigna horas trabajadas en el empleado indicado
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene horas trabajadas del empleado indicado
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

/** \brief Asigna sueldo en el empleado indicado
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene sueldo del empleado indicado
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}

/** \brief Compara el nombre de los empleados
 *
 * \param pEmpleado void*
 * \param pEmpleado2 void*
 * \return int
 *
 */
int employee_compararPorNombre(void*pEmpleado,void*pEmpleado2)
{
    int diff;
    if(pEmpleado2 != NULL && pEmpleado != NULL)
    {
        diff = strcmp(((Employee*)pEmpleado)->nombre,((Employee*)pEmpleado2)->nombre);

    }

    return diff;
}
