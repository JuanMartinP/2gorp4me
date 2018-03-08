#include "stack_element.h"
#include "element.h"

#define ESTADO 64

int main(int argc, char *argv[])
{
  Stack* stackt;
  Stack* stackp;
  Stack* stacki;
  int i;
  int input = 0, aux = 0, output = 0;

  if (argc < 2)
  {
    printf("El programa se abre con: %s <tamano_de_pila>\n", argv[0]);
    return 1;
  }

  stackt = stack_ini();
  stackp = stack_ini();
  stacki = stack_ini();


  if(stack_isFull(stackt) == TRUE)
    printf("Pila total (llena, no vacía):\n");
  else if (stack_isEmpty(stackt) == TRUE)
    printf("Pila total (no llena, vacía):\n");
  else
    printf("Pila total (no llena, no vacía):\n");

  output = argv[1];
  for(i=0; i<output; i++)
  {
    printf("\nIntroduce número: ");
    scanf("%d", &input);
    stack_push(stackt, input);
  }

  if(stack_isFull(stackt) == TRUE)
  printf("Pila total (llena, no vacía):\n");
else if (stack_isEmpty(stackt) == TRUE)
  printf("Pila total (no llena, vacía):\n");
else
  printf("Pila total (no llena, no vacía):\n");

  stack_print(stdout, stackt);


  for(i=0; stack_isEmpty(stackt) == FALSE; i++)
  {
    aux = element_getInfo(stack_top(stackt));
    if (aux%2 == 0)
    {
      stack_push(stackp, stack_pop(stackt));
    }
    else
    {
      stack_push(stacki, stack_pop(stackt));
    }
  }


  if(stack_isFull(stackp) == TRUE)
  printf("Pila total (llena, no vacía):\n");
else if (stack_isEmpty(stackt) == TRUE)
  printf("Pila total (no llena, vacía):\n");
else
  printf("Pila total (no llena, no vacía):\n");

  stack_print(stdout, stackp);



  if(stack_isFull(stacki) == TRUE)
  printf("Pila total (llena, no vacía):\n");
else if (stack_isEmpty(stackt) == TRUE)
  printf("Pila total (no llena, vacía):\n");
else
  printf("Pila total (no llena, no vacía):\n");

  stack_print(stdout, stacki);



  if(stack_isFull(stackt) == TRUE)
  printf("Pila total (llena, no vacía):\n");
else if (stack_isEmpty(stackt) == TRUE)
  printf("Pila total (no llena, vacía):\n");
else
  printf("Pila total (no llena, no vacía):\n");

  stack_print(stdout, stackt);

  return 0;
}
