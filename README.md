# Monitor de Memoria Física en xv6

## 1. Descripción del proyecto

Proyecto desarrollado para el curso de Sistemas Operativos de la Universidad Nacional de San Cristóbal de Huamanga (UNSCH).

Se implementó una extensión del sistema operativo educativo xv6 (versión x86) para consultar y visualizar el estado de la memoria física. El proyecto incorpora nuevas llamadas al sistema, un monitor de usuario y cinco casos de prueba para evaluar la reserva y liberación de memoria.

## 2. Objetivo

Implementar y evaluar un monitor de memoria física en xv6 que muestre la memoria total, utilizada y libre, así como el porcentaje de uso, la cantidad de páginas y el estado de disponibilidad de memoria.

## 3. Funcionalidades implementadas

- Consulta de memoria física total mediante `gettotalmem()`.
- Consulta de memoria física libre mediante `getfreemem()`.
- Cálculo de memoria utilizada y porcentaje de uso.
- Visualización de la cantidad de páginas de 4 KB.
- Barra visual de utilización y estado de memoria.
- Pruebas de reserva, liberación progresiva y recuperación de memoria de procesos.

## 4. Archivos principales

| Archivo | Función |
|---|---|
| `kalloc.c` | Consulta de páginas libres del asignador físico. |
| `sysproc.c` | Funciones de las nuevas llamadas al sistema. |
| `syscall.c`, `syscall.h` | Registro e identificación de llamadas al sistema. |
| `defs.h`, `user.h`, `usys.S` | Declaraciones y conexiones necesarias. |
| `meminfo.c` | Monitor de memoria física, versión 2.0. |
| `pruebamem.c` | Reserva y liberación de 40 KB. |
| `prueba100.c` | Reserva y liberación de 100 KB. |
| `prueba200.c` | Reserva y liberación de 200 KB. |
| `pruebaprog.c` | Reserva y liberación progresiva de hasta 160 KB. |
| `pruebaproc.c` | Reserva de memoria en un proceso hijo y recuperación al finalizar. |
| `Makefile` | Inclusión de los programas en la compilación de xv6. |

## 5. Entorno de desarrollo

- Ubuntu mediante WSL.
- xv6 x86, basado en el repositorio educativo `mit-pdos/xv6-public`.
- QEMU para ejecutar xv6.
- Git y GitHub para el control de versiones y el trabajo colaborativo.

## 6. Compilación y ejecución

Desde Ubuntu, en la carpeta del repositorio:

```bash
make fs.img
make qemu-nox
```

Una vez iniciado xv6, ejecutar:

```text
meminfo
pruebamem
prueba100
prueba200
pruebaprog
pruebaproc
```

Para salir de QEMU en modo `nox`, presionar `Ctrl + A` y luego `X`.

## 7. Resultados del monitor

En una ejecución de prueba se obtuvo:

| Indicador | Resultado |
|---|---:|
| Memoria total | 228264 KB |
| Memoria utilizada | 1104 KB |
| Memoria libre | 227160 KB |
| Uso de memoria | 0.48 % |
| Páginas totales | 57066 |
| Páginas utilizadas | 276 |
| Páginas libres | 56790 |
| Estado | NORMAL |

Los valores pueden variar según la configuración y el estado de ejecución de xv6.

## 8. Casos de prueba

Se realizaron cinco pruebas para verificar la reserva y recuperación de memoria física.

| Caso | Programa | Operación | Memoria libre inicial | Memoria libre durante la reserva | Memoria libre final |
|---|---|---|---:|---:|---:|
| 1 | `pruebamem` | Reserva de 40 KB | 227160 KB | 227120 KB | 227160 KB |
| 2 | `prueba100` | Reserva de 100 KB | 227160 KB | 227060 KB | 227160 KB |
| 3 | `prueba200` | Reserva de 200 KB | 227160 KB | 226960 KB | 227160 KB |
| 4 | `pruebaprog` | Reserva progresiva de 160 KB | 227160 KB | 227000 KB | 227160 KB |
| 5 | `pruebaproc` | Proceso hijo con reserva dinámica de 120 KB | 227160 KB | 226760 KB | 227160 KB |

### Prueba 4: reserva progresiva

Se reservaron cinco bloques de 32 KB hasta acumular 160 KB. La memoria libre descendió progresivamente de 227160 KB a 227000 KB. Después de liberar los bloques, regresó a 227160 KB.

Resultado mostrado: `RESULTADO OK: 0 bytes fugados.`

### Prueba 5: recuperación de memoria del proceso hijo

Se utilizó `fork()` para crear un proceso hijo que reservó 120 KB de memoria. Durante la ejecución, la memoria libre descendió a 226760 KB, considerando también los recursos adicionales del proceso. Tras su finalización y recuperación mediante `wait()`, la memoria libre volvió a 227160 KB.

Resultado mostrado: `RESULTADO OK: Kernel libero memoria del hijo.`

## 9. Análisis de resultados

Las cinco pruebas mostraron una disminución de memoria libre durante la reserva y una recuperación hasta el valor inicial después de liberar los recursos. La prueba progresiva verificó el comportamiento del asignador ante varias operaciones consecutivas. La prueba del proceso hijo permitió observar la recuperación de memoria al finalizar su ejecución.

Estos resultados corresponden a las ejecuciones documentadas y no constituyen una garantía de ausencia de fugas en todos los escenarios posibles.

## 10. Informe técnico y evidencias

- [Informe técnico en PDF](documento_TrabajoFinal/Trabajo_Final_xv6.pdf)
- [Informe editable en Word](documento_TrabajoFinal/Trabajo_Final_xv6.docx)
- [Carpeta de evidencias](documento_TrabajoFinal/Evidencias)

Las evidencias incluyen capturas de compilación, funcionamiento del monitor y ejecución de las pruebas. Las capturas de las pruebas 4 y 5 se incorporarán a la carpeta cuando estén publicadas.

La presentación de sustentación se añadirá cuando esté terminada.

## 11. Trabajo colaborativo

El proyecto fue desarrollado por dos integrantes del curso de Sistemas Operativos de la UNSCH.

- [miltonhuaman27-glitch](https://github.com/miltonhuaman27-glitch): implementación inicial del monitor, llamadas al sistema, pruebas 1 a 3 y documentación.
- [juanalvizuri27-hue](https://github.com/juanalvizuri27-hue): mejora del monitor `meminfo` y desarrollo de las pruebas 4 y 5.

Los aportes individuales se pueden revisar en el historial de commits y en la rama `aporte-juan`.

## 12. Estado del proyecto

La implementación de ambos integrantes está integrada en la rama `master`. Se verificó la compilación, el arranque de xv6, el funcionamiento de `meminfo` y la ejecución satisfactoria de las pruebas 4 y 5. Las tres pruebas iniciales también cuentan con resultados documentados.

Queda pendiente completar las capturas adicionales y publicar la presentación de sustentación.

## 13. Referencia del sistema base

- MIT PDOS. [xv6-public: código fuente educativo de xv6 para x86](https://github.com/mit-pdos/xv6-public).

