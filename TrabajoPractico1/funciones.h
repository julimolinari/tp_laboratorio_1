#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int isValid(float numero, float maximo, float minimo);
int getFloat (char *mensaje, char *mensajeError, float maximo,float minimo,int reintentos,float *resultado);
int floatSuma (float primerOp, float segundoOp, float *resultadoSuma);
int floatResta (float primerOp, float segundoOp, float *resultadoResta);
int floatDivision(float primerOP, float segundoOp, float* resultadoDivision);
int floatMultiplicacion(float primerOP, float segundoOp, float* resultadoMultiplicacion);
int floatFactorial(float operador, float* resultadoFac);


#endif
