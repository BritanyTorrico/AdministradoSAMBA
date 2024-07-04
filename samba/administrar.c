#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
void separar(char *cadena, char *linea, char separador)
{
	int x, y;
	x = 0, y = 0;
	while ((linea[x]) && (linea[x] != separador))
	{
		cadena[x] = linea[x];
		x++;
	}
	cadena[x] = '\0';
	if (linea[x])
		++x;
	y = 0;
	while (linea[y] = linea[x])
	{
		linea[y] = linea[x];
		x++;
		y++;
	}
}
int main(int argc, char *argv[])
{	
	//basevariables
	char *lenstr;
	char inputBuffer[90];
	int contentlegth;
	int i = 0;
	char x;
	//inputs
	char opcion[60];
	//Base
	printf("Content-type:text/html\n\n");
	printf("<html>");

	printf("<head>");
	printf("<title> WORKGROUP</title>\n");
	printf("</head>");
	printf("<body>");


	int iUid,iGid;
	if ((setuid(0)) < 0)
		printf("\n operacion no permitida \n");
	if ((setgid(0)) < 0)
		printf("\n operacion no permitida \n");
        lenstr = getenv("CONTENT_LENGTH");
	if (lenstr != NULL)
		contentlegth = atoi(lenstr);
	else
		contentlegth = 0;

	if (contentlegth > sizeof(inputBuffer) - 1)
		contentlegth = sizeof(inputBuffer) - 1;

	i = 0;
	while (i < contentlegth)
	{
		x = fgetc(stdin);
		if (x == EOF)
			break;
		inputBuffer[i] = x;
		i++;
	}

	inputBuffer[i] = '\0';
	contentlegth = i;
	
	separar(opcion, inputBuffer, '=');
	separar(opcion, inputBuffer, '&');
	
	int p1=strlen("Iniciar");
	int p2=strlen(opcion);
	if(strcmp("Iniciar",opcion) == 0){//si es iniciar
	  printf("<h2 style='color: #32cd32;'> Servidor SAMBA Iniciado </h2>");
	  system("service smb start");
	}else{
	  if(strcmp("Detener",opcion) == 0){
	      printf("<h2 style='color: red;'> Servidor SAMBA Detenenido </h2>");
	       system("service smb stop");
	  }else{//restaurar
	      printf("<h2 style='color: #32cd32;'> Reiniciando servido SAMBA </h2>");
	       system("service smb restart");
	  }
	 
	}
	printf("</body>");
 	printf("</html>");
	return 0;
}
