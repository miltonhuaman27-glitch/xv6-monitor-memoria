
# Monitor de Memoria Física en xv6

## 1. Descripción del proyecto

Proyecto desarrollado para el curso de Sistemas Operativos de la Universidad Nacional de San Cristóbal de Huamanga (UNSCH).

Consiste en implementar un monitor de memoria física en el sistema operativo educativo xv6, que permite consultar la cantidad de memoria total, utilizada y libre, así como el porcentaje de uso.

## 2. Objetivo

Implementar y evaluar una extensión funcional de xv6 que permita visualizar el estado de la memoria física mediante nuevas llamadas al sistema.

## 3. Funcionalidades implementadas

- Consulta de memoria física total.
- Consulta de memoria física libre.
- Cálculo de memoria utilizada.
- Cálculo del porcentaje de memoria utilizada.
- Pruebas de reserva y liberación de memoria.

## 4. Archivos principales

- `kalloc.c`: incorpora el mecanismo para consultar la memoria libre.
- `sysproc.c`: contiene las funciones de las nuevas llamadas al sistema.
- `syscall.c` y `syscall.h`: registran las llamadas al sistema.
- `defs.h`, `user.h` y `usys.S`: incorporan las declaraciones y conexiones necesarias.
- `meminfo.c`: muestra la información de memoria.
- `pruebamem.c`: prueba de reserva y liberación de 40 KB.
- `prueba100.c`: prueba de reserva y liberación de 100 KB.
- `prueba200.c`: prueba de reserva y liberación de 200 KB.
- `Makefile`: incorpora los programas para su compilación.

## 5. Requisitos

- Ubuntu Linux o Ubuntu mediante WSL.
- Git.
- GCC con soporte para compilación de 32 bits.
- GNU Make.
- QEMU compatible con xv6 x86.
- Herramientas de compilación necesarias para xv6.

## 6. Descargar el proyecto

```bash
git clone https://github.com/miltonhuaman27-glitch/xv6-monitor-memoria.git
cd xv6-monitor-memoria
```

## 7. Compilar y ejecutar

Para compilar:

```bash
make
```

Para iniciar xv6:

```bash
make qemu-nox
```

Una vez dentro de xv6, ejecutar:

```text
meminfo
```

## 8. Pruebas realizadas

Dentro de xv6, ejecutar:

```text
pruebamem
prueba100
prueba200
```

Resultados observados:

| Prueba | Memoria reservada | Memoria libre antes | Memoria libre después de reservar | Memoria libre después de liberar |
|---|---:|---:|---:|---:|
| pruebamem | 40 KB | 227160 KB | 227120 KB | 227160 KB |
| prueba100 | 100 KB | 227160 KB | 227060 KB | 227160 KB |
| prueba200 | 200 KB | 227160 KB | 226960 KB | 227160 KB |

Los resultados muestran que la memoria libre disminuye al reservar páginas y vuelve a su valor inicial después de liberarlas.

Los valores pueden variar según la configuración y el estado de xv6.

## 9. Resultados del monitor

En una ejecución de prueba se obtuvo:

- Memoria total: 228264 KB.
- Memoria utilizada: 1104 KB.
- Memoria libre: 227160 KB.
- Uso de memoria: 0.48 %.

## 10. Evidencias

Las capturas de compilación, ejecución y pruebas se incorporarán al repositorio del proyecto.

## 11. Integrantes

Proyecto desarrollado por dos estudiantes de Ingeniería de Sistemas de la UNSCH.

## 12. Estado del proyecto

El monitor principal y las tres pruebas iniciales funcionan correctamente. El proyecto continuará incorporando las pruebas adicionales y mejoras desarrolladas por el segundo integrante.
