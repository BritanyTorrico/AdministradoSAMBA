#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
void procesar(){
printf("<p>hola</p>");

}
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
int main(void)
{	
	//basevariables
	char *lenstr;
	char inputBuffer[90];
	int contentlegth;
	int i = 0;
	char x;
	//inputs
	char opcion[80];
//	char nuevoNombre[80];
	//Base
	printf("Content-type:text/html\n\n");
	printf("<html>");

	printf("<head>");
	printf("<title> SAMBA</title>\n");
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
	//base end
	
	printf("<div>");
	printf("<form ACTION='/cgi-bin/guardoRecurso' METHOD='POST'>");
	printf("<h1 style='color:green;'> SAMBA SERVER </h1>");
	printf("<h2 style='color:green;'>Nuevo recurso:</h2>");
	printf("<br>Nombre:<br>");
	printf("<input NAME='nombre' size='60' MAXLENGTH='80' required><br>");
	printf("<br>Descripcion:<br>");
	printf("<input NAME='descripcion' size='60' MAXLENGTH='80' required><br>");
	
	printf("<br>Path:<br>");
	printf("<input NAME='path' size='60' MAXLENGTH='80' required><br>");
	printf("<br>Read Only:<br>");
	printf("<input type='radio' name='read' value='Yes' checked>Si<br>");
	printf("<input type='radio' name='read' value='No'>No<br>");
	
	 printf("<input type ='submit'  value='Agregar'/>");
	printf("</form>");

	printf("</div>");
	printf("</body>");
 	printf("</html>");
	return 0;
}


