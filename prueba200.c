
#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int antes, durante, despues;
  char *memoria;

  antes = getfreemem();

  printf(1, "=== PRUEBA DE MEMORIA ===\n");
  printf(1, "Antes: %d KB\n", antes / 1024);

  memoria = sbrk(4096 * 50);

  if(memoria == (char*)-1){
    printf(1, "Error al reservar memoria\n");
    exit();
  }

  durante = getfreemem();
  printf(1, "Despues de reservar: %d KB\n", durante / 1024);

  sbrk(-4096 * 50);

  despues = getfreemem();
  printf(1, "Despues de liberar: %d KB\n", despues / 1024);

  exit();
}
