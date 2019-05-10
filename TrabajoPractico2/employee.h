#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
#include <string.h>

typedef struct
{
 int id;
 char nombre[51];
 char apellido[51];
 float salario;
 int sector;
 int isEmpty;
}Employee;

int initEmployees(Employee* list, int len);
int emp_print(Employee* listaEmployee,int len);
int emp_add(Employee* listaEmployee,int len,int indice,char* msgE,int tries);
int emp_freeI(Employee* listaEmployee,int len);
int emp_findById(Employee* pEmployee, int len, int idE);
int emp_alter(Employee* listaEmployee, int len,char* msgE,int tries);
int emp_ordenarAlfa(Employee* listaEmployee,int len);
int emp_isEmptyValid(Employee* listaEmployee,int len);
int emp_totalPromedio(Employee* listaEmployee,int len);
int emp_inform(Employee* listaEmployee, int len,char* msgE,int tries);
int emp_remove(Employee* listaEmployee, int len,char* msgE,int tries);

#endif
