#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> 
void renombrar(char *opcion){

	printf("\n <form action ='./modificarNombre' method='post'>\n");
	printf("<br>");
	printf("\nNuevo nombre: ");
	printf("<input name ='nombre' size='60' max length='80' required>\n");
	printf("<br/>");
	printf("\n <textarea name='opcion' rows='1' cols='1' style='display:none;' >%s</textarea> \n", opcion);
	printf("<br>");
	printf("\n <button style='background-color:#4CAF50'> Enviar cambios </button>\n");
	printf("\n </form> \n");
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

void remplazarCaracteres(char *conf, char *buscar, char caracterRemplazo)
{
	int tamconf =strlen(conf);
	int tamBuscar = strlen(buscar);
	char copy[10240];
	char caracter = buscar[0];
	char final = '\0';
	int i = 0;
	while (i < tamconf)
	{
	if (caracter == conf[i]){
		if (strncmp(&conf[i], buscar, tamBuscar) == 0)
		{
			conf[i] = caracterRemplazo;
			int aux = i;
			i++;
			int j = i + tamBuscar - 1;
			strcpy(copy, conf);
			int tamCopy = strlen(copy);
			while (j < tamCopy)
			{
				if(final == copy[j])
					break;
			conf[i] = copy[j];
			i++;
			j++;
				}
				i = aux;
				tamconf = strlen(conf);

			}
		}
		i++;
	}
	conf[i] = '\0';
}

int main(){
	char *lenstr;
	char inputBuffer[90];
	int contentlegth;
	int i = 0;
	char x;
	//inputs
	char opcion[80];

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
	//end base
	separar(opcion, inputBuffer, '=');
	separar(opcion, inputBuffer, '&');
	remplazarCaracteres(opcion,"+",'_');//para este caso en especifico
	printf("\n<h1 style='color:#9ACD32;'>Renombrar Recurso:</h1>\n");
	printf("\n<p style='color:#9ACD32;' name ='opcion'> Nombre anterior: %s</p>\n",opcion);
	renombrar(opcion);
  printf("</body>");
  printf("</html>");
}
