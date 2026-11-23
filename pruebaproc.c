#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int inicial, durante, final, pid;
  int reserva = 4096 * 30; // 30 paginas = 120 KB

  inicial = getfreemem();
  printf(1, "=== PRUEBA 5: MEMORIA EN PROCESOS (FORK) ===\n");
  printf(1, "Padre - Memoria libre inicial: %d KB\n", inicial / 1024);

  pid = fork();
  if(pid < 0){
    printf(1, "Error al crear proceso hijo\n");
    exit();
  }

  if(pid == 0){
    // Proceso hijo reserva 120 KB y finaliza sin llamar a sbrk negativo
    if(sbrk(reserva) == (char*)-1){
      printf(1, "Hijo - Error al reservar memoria\n");
      exit();
    }
    durante = getfreemem();
    printf(1, "Hijo - Reservo 120 KB -> Libre en sistema: %d KB\n", durante / 1024);
    exit();
  } else {
    // Proceso padre espera a que el hijo termine
    wait();
    final = getfreemem();
    printf(1, "Padre - Hijo termino -> Libre recuperada: %d KB\n", final / 1024);

    if(final == inicial)
      printf(1, "RESULTADO OK: Kernel libero memoria del hijo.\n");
    else
      printf(1, "ADVERTENCIA: Diferencia de %d bytes.\n", inicial - final);
  }

  exit();
}
