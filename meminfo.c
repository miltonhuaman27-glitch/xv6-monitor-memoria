
#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int total, libre, usada, porcentaje;

  total = gettotalmem();
  libre = getfreemem();
  usada = total - libre;

  porcentaje = 0;
  if(total > 0)
    porcentaje = (usada / 1024) * 10000 / (total / 1024);

  printf(1, "============================\n");
  printf(1, "  MONITOR DE MEMORIA XV6\n");
  printf(1, "============================\n");
  printf(1, "Memoria total : %d KB\n", total / 1024);
  printf(1, "Memoria usada : %d KB\n", usada / 1024);
  printf(1, "Memoria libre : %d KB\n", libre / 1024);
  printf(1, "Uso de memoria: %d.", porcentaje / 100);

if(porcentaje % 100 < 10)
  printf(1, "0");

printf(1, "%d %%\n", porcentaje % 100);
printf(1, "============================\n");

exit();
}


