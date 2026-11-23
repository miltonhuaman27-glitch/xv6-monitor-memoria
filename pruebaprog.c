#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int inicial, actual, i;
  int bloque = 4096 * 8; // 8 paginas = 32 KB por etapa

  inicial = getfreemem();
  printf(1, "=== PRUEBA 4: RESERVA PROGRESIVA ===\n");
  printf(1, "Memoria libre inicial: %d KB\n", inicial / 1024);

  // Reserva progresiva en 5 etapas (total 160 KB)
  for(i = 1; i <= 5; i++){
    if(sbrk(bloque) == (char*)-1){
      printf(1, "Error al reservar en etapa %d\n", i);
      exit();
    }
    actual = getfreemem();
    printf(1, "Etapa +%d (reservado %d KB) -> Libre: %d KB\n", i, (bloque * i) / 1024, actual / 1024);
  }

  // Liberacion progresiva en 5 etapas
  for(i = 4; i >= 0; i--){
    sbrk(-bloque);
    actual = getfreemem();
    printf(1, "Liberando etapa %d -> Libre: %d KB\n", 5 - i, actual / 1024);
  }

  if(actual == inicial)
    printf(1, "RESULTADO OK: 0 bytes fugados.\n");
  else
    printf(1, "ADVERTENCIA: Diferencia de memoria detectada.\n");

  exit();
}
