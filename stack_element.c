#include <stdio.h>
#include <stdlib.h>
#include "stack_element.h"
#define MAXSTACK 100

struct _Stack
{
  int top;
  Element* item[MAXSTACK];
};

/**------------------------------------------------------------------
Inicializa la pila reservando memoria. Salida: NULL si ha habido error o
la pila si ha ido bien
------------------------------------------------------------------*/
Stack * stack_ini()
{
  Stack * pila;

  pila = (Stack*)calloc(1, sizeof(Stack));
  if(pila == NULL)
    return NULL;

  return pila;
}

/**------------------------------------------------------------------
Elimina la pila Entrada: la pila que se va a eliminar
------------------------------------------------------------------*/
void stack_destroy(Stack * pila)
{
  if(pila == NULL)
    return ;

  free(pila);
  pila = NULL;
}

/**------------------------------------------------------------------
Inserta un elemento en la pila. Entrada: un elemento y la pila donde
insertarlo. Salida: ERROR si no logra insertarlo, OK si lo logra
------------------------------------------------------------------*/
Status stack_push(Stack * pila, const Element * ele)
{
    if(pila == NULL || ele == NULL || pila->top == MAXSTACK)
      return ERROR;

    pila->item[pila->top] = element_ini();
    if( (pila->item) == NULL)
      return ERROR;

    pila->item[pila->top] = ele; /*Aquí salta un warning que no entiendo*/
    (pila->top) = (pila->top) + 1;

    return OK;
}

/**------------------------------------------------------------------
Extrae un elemento en la pila. Entrada: la pila de donde extraerlo.
Salida: NULL si no logra extraerlo o elelemento extraido si lo
 logra. Nótese que la pila quedará modificada
------------------------------------------------------------------*/
Element * stack_pop(Stack * pila)
{
  int aux_top;
  if(pila == NULL)
    return NULL;

  aux_top = pila->top;
  (pila->top) = (pila->top) - 1;

  return pila->item[aux_top];
}

/**------------------------------------------------------------------
Copia un elemento (reservando memoria) sin modificar el top de
la pila. Entrada: la pila de donde copiarlo.Salida: NULL si no
logra copiarlo o el elemento si lo logra
------------------------------------------------------------------*/
Element * stack_top(const Stack * pila)
{
  Element * copia;

  if(pila == NULL)
    return NULL;

  copia = element_ini();

  copia = pila->item[pila->top];

  return copia;
}

/**------------------------------------------------------------------
Comprueba si la pila esta vacia. Entrada: pila.
Salida: TRUE si está vacia o FALSE si no lo esta
------------------------------------------------------------------*/
Bool stack_isEmpty(const Stack * pila)
{
    if(pila == NULL)
      return FALSE;

    if(pila->top == 0)
      return TRUE;
    else
      return FALSE;
}

/**------------------------------------------------------------------
Comprueba si la pila esta llena. Entrada: pila.
Salida: TRUE si está llena o FALSE si no lo esta
------------------------------------------------------------------*/
Bool stack_isFull(const Stack * pila)
{
  if(pila == NULL)
    return FALSE;

    if(pila->top == MAXSTACK)
      return TRUE;
    else
      return FALSE;
}

/**------------------------------------------------------------------
Imprime toda la pila, colocando el elemento en la cima al principio de la impresión (y un elemento por línea).
Entrada: pila y fichero donde imprimirla. Salida: Devuelve el número de caracteres escritos.
------------------------------------------------------------------*/
int stack_print(FILE * f, const Stack * pila)
{
  int contador, i;

  if(pila == NULL || f == NULL)
    return FALSE;

  for(i = pila->top; i <= 0; i--)
    contador += fprintf(f, "[%d] \n", (pila->item[i]));

  return contador;
}
