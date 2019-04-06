/*******************************************************************
*Programa:Calculadora
*
*Objetivo:
Ingresar numeros y realizar operaciones
*
*Version:0.1del05Abril2019
*Autor:JulietaMolinari
*
********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int ingreso=0;
    float primerOp=0;
    float segundoOp=0;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoMultiplicacion;
    float resultadoFactA;
    float resultadoFactB;
    int flag = 0;
    int auxDivision;

    while(ingreso!=5)
    {
        printf("Menu: \n");
        printf("1. Ingresar 1er operando A= %.2f\n",primerOp);
        printf("2. Ingresar 2do operando B= %.2f\n",segundoOp);
        printf("3. Calcular todas las operaciones \n");
        printf("\ta) Calcular la suma (A+B)\n");
        printf("\tb) Calcular la resta (A-B)\n");
        printf("\tc) Calcular la division (A/B)\n");
        printf("\td) Calcular la multiplicacion (A*B)\n");
        printf("\te) Calcular el factorial (A!)\n");
        printf("4. Informar resultados\n");
        printf("5. Salir\n");
        printf("\nIngrese una opcion: ");
        scanf("%d",&ingreso);

        switch (ingreso)
        {

            case 1:
                flag = 0;
                getFloat("1. Ingresar 1er operando: ","Valor invalido\n",50000000,-50000000,3,&primerOp);
                break;

            case 2:
                flag = 0;
                getFloat("2. Ingresar 2do operando: ","Valor invalido\n",50000000,-50000000,3,&segundoOp);
                break;

            case 3:
                flag = 1;
                floatSuma(primerOp,segundoOp,&resultadoSuma);
                floatResta(primerOp,segundoOp,&resultadoResta);
                auxDivision = floatDivision(primerOp,segundoOp,&resultadoDivision);
                floatMultiplicacion(primerOp,segundoOp,&resultadoMultiplicacion);
                floatFactorial(primerOp,&resultadoFactA);
                floatFactorial(segundoOp,&resultadoFactB);
                printf("Resultados calculados con exito\n");
                system("pause");
                break;

            case 4:
                if(flag==1)
                {
                    printf("El resultado de A+B es: %.2f",resultadoSuma);
                    printf("\nEl resultado de A-B es: %.2f",resultadoResta);
                    if(auxDivision == 0)
                    {
                        printf("\nEl resultado de A/B es: %.2f",resultadoDivision);
                    }else
                    {
                        printf("\nNo se puede dividir por 0.");
                    }

                    printf("\nEl resultado de A*B es: %.2f",resultadoMultiplicacion);
                    printf("\nEl factorial de A es: %.2f",resultadoFactA);
                    printf(" y el factorial de B es: %.2f",resultadoFactB);
                }else
                {
                    printf("Debe calcular antes de ver los resultados (3).");
                }
                printf("\n\n");
                system("pause");
                break;

        }
        system("cls");

    }

    return 0;
}
