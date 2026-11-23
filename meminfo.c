#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int total, libre, usada, porcentaje;
  int pag_total, pag_usada, pag_libre;
  int entero, decimal, llenos, i;

  total = gettotalmem();
  libre = getfreemem();
  usada = total - libre;

  /* Calculo en paginas fisicas de 4 KB (PGSIZE = 4096 bytes) */
  pag_total = total / 4096;
  pag_usada = usada / 4096;
  pag_libre = libre / 4096;

  porcentaje = 0;
  if(total > 0)
    porcentaje = (usada / 1024) * 10000 / (total / 1024);

  entero = porcentaje / 100;
  decimal = porcentaje % 100;

  printf(1, "==========================================\n");
  printf(1, "      MONITOR DE MEMORIA XV6 (v2.0)       \n");
  printf(1, "==========================================\n");
  printf(1, "Memoria total : %d KB (%d paginas)\n", total / 1024, pag_total);
  printf(1, "Memoria usada : %d KB (%d paginas)\n", usada / 1024, pag_usada);
  printf(1, "Memoria libre : %d KB (%d paginas)\n", libre / 1024, pag_libre);
  printf(1, "Uso de memoria: %d.", entero);
  if(decimal < 10)
    printf(1, "0");
  printf(1, "%d %%\n", decimal);

  /* Barra visual de 20 bloques */
  llenos = (entero * 20) / 100;
  if(entero > 0 && llenos == 0)
    llenos = 1;

  printf(1, "Carga fisica  : [");
  for(i = 0; i < 20; i++){
    if(i < llenos)
      printf(1, "#");
    else
      printf(1, "-");
  }
  printf(1, "]\n");

  /* Indicador de estado del sistema */
  if(entero < 50)
    printf(1, "Estado        : NORMAL (Disponibilidad optima)\n");
  else if(entero < 80)
    printf(1, "Estado        : MODERADO (Uso elevado)\n");
  else
    printf(1, "Estado        : CRITICO (Memoria casi llena)\n");

  printf(1, "==========================================\n");
  exit();
}
