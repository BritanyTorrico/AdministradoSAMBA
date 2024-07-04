#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	if ((setuid(0)) < 0)
		printf("\n operacion no permitida \n");
	if ((setgid(0)) < 0)
		printf("\n operacion no permitida \n");
	system("gcc samba/administrar.c -o administrar");//start stop restart
	system("chmod ugo+s administrar");
	system("gcc samba/verificarEstado.c -o verificar");//verifica estado
	system("chmod ugo+s verificar");
	system("gcc samba/instalado.c -o  instalado");//verifica si esta instalado samba
	system("chmod ugo+s instalado");
	system("gcc samba/otro.c -o cambio");//workgroup
	system("chmod ugo+s cambio");
	system("gcc samba/renombrar.c -o renombrar.cgi");//pongo nuevo nombre
	system("chmod ugo+s renombrar.cgi");
	system("gcc samba/ejercicio3.c -o modificarNombre");// cambia el nombre
 	system("chmod ugo+s modificarNombre");
        system("gcc samba/editar.c -o editarRecurso");// edita recurso con textArea
        system("chmod ugo+s editarRecurso");
	system("gcc samba/guardarEditado.c -o guardarCambios1");//guarda los datos del recurso editado caso READONLY
	system("chmod ugo+s  guardarCambios1");
	system("gcc samba/guardarPath.c -o guardarPath");//guarda los cambios del path
	system("chmod ugo+s guardarPath");
	system("gcc samba/guardoEditado2.c -o guardarCambios");// almacena los nuevos cambios
	system("chmod ugo+s guardarCambios");
	system("gcc samba/eliminar.c -o eliminar");//elimina recurso
	system("chmod ugo+s eliminar");
	system("gcc samba/nuevoRecurso.c -o nuevo");//registra los datos del nuevo recurso
	system("chmod ugo+s nuevo");
	system("gcc samba/guardarDatos.c -o guardoRecurso");//guarda los datos del recurso
	system("chmod ugo+s guardoRecurso");
//	system("gcc avanzado.c -o avanzado");//interfaz opciones avanzadas
//	system("chmod ugo+s avanzado");
	
	system("gcc samba/mostrar.c -o avanzado");//interfaz opciones avanzadas mejorado 
	system("chmod ugo+s avanzado");
	return 0;
}
