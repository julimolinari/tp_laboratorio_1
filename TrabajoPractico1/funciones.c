#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"

/**
* \brief Validacion del numero float
* \param maximo Tope maximo de validacion
* \param minimo Tope minimo de validacion
* \return Entero 0 correcto, -1 error
**/
int isValid(float numero, float maximo, float minimo)
{
    if(numero <= maximo && numero >= minimo)
    {
        return 1;
    }
    return 0;

}


/**
* \brief Pide un numero float y lo valida
* \param mensaje mensaje para el usuario
* \param mensajeError mesaje mostrado cuaando el ingreso no es valido
* \param maximo tope maximo de validacion
* \param minimo tope minimo de validacion
* \param reintentos cantidad maxima intentos
* \param resultado variable de salida
* \return Entero 0 correcto, -1 error
**/
int getFloat (char *mensaje, char *mensajeError, float maximo,float minimo,int reintentos,float *resultado)
{
        float buffer;
        int retorno = -1;
        if(mensaje != NULL && mensajeError != NULL && resultado != NULL && maximo>=minimo)
        {
            while(reintentos>=0)
            {
                printf("%s",mensaje);
                scanf("%f",&buffer);
                if(isValid(buffer,maximo,minimo)==1)
                {
                    *resultado = buffer;
                    retorno = 0;
                    break;

                }else
                {
                    printf(mensajeError);
                }
                reintentos--;
            }
        }

    return retorno;
}


/**
* \brief Suma de dos flotantes
* \param primerOp 1er flotante ingresado
* \param segundoOp 2do flotante ingresado
* \param resultadoSuma resultado
* \return Entero 0 correcto
**/
int floatSuma(float primerOp, float segundoOp, float* resultadoSuma)
{
    *resultadoSuma = primerOp + segundoOp;
    return 0;
}

/**
* \brief Resta de dos flotantes
* \param primerOp 1er flotante ingresado
* \param segundoOp 2do flotante ingresado
* \param resultadoResta resultado
* \return Entero 0 correcto
**/
int floatResta(float primerOp, float segundoOp, float* resultadoResta)
{
    *resultadoResta = primerOp - segundoOp;
    return 0;
}

/**
* \brief Division de dos flotantes
* \param primerOp 1er flotante ingresado
* \param segundoOp 2do flotante ingresado
* \param resultadoDivision resultado
* \return Entero 0 correcto
**/
int floatDivision(float primerOP, float segundoOp, float* resultadoDivision)
{
    if(segundoOp !=0)
    {
        *resultadoDivision = primerOP / segundoOp;
    }else
    {
        return -1;
    }
    return 0;
}


/**
* \brief Multiplicacion de dos flotantes
* \param primerOp 1er flotante ingresado
* \param segundoOp 2do flotante ingresado
* \param resultadoMultiplicacion resultado
* \return Entero 0 correcto
**/
int floatMultiplicacion(float primerOP, float segundoOp, float* resultadoMultiplicacion)
{
    *resultadoMultiplicacion = primerOP * segundoOp;
    return 0;
}


/**
* \brief Factorial un flotante
* \param poperador flotante ingresado
* \param resultadoFac resultado
* \return Entero 0 correcto
**/
int floatFactorial(float operador, float* resultadoFac)
{
    int i;
    int factorial=operador;
    for (i = operador -1; i > 0; i--)
    {
        factorial = factorial * i;
    }
    *resultadoFac = factorial;


    return 0;
}
