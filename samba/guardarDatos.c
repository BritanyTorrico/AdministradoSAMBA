#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
void insertarSubcadena(char *original, char *subcadena, int indice) {
	   
	    char inicio[10240] = "";
	    strncpy(inicio, original, indice);
	     char fin[10240] = "";
	    strncpy(fin, original + indice, strlen(original) - indice);
	    strcat(inicio, subcadena);
	    strcat(inicio, fin);
	    strcpy(original, inicio);
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
void reemplazarCaracteres(char *conf, char *buscar, char caracterRemplazo)
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

int buscarPunto(char *cadena){
	int i=0;
	while(cadena[i] != ';'){
	i++;
	
}
return i;

	
}
void borrar(char *cadena,int corte){
	int i=corte;
    
	while(i < 80){
	
	cadena[i]='\0';
		i++;
	}
 
}
void borrarSamba(char *cadena,int corte){
	int i=corte;
    
	while(i < 10240){
	
	cadena[i]='\0';
		i++;
	}
 
}
void guardoCambios(char *cadena)
{
	
	FILE *archivo;
	archivo = fopen("/etc/samba/smb.conf", "w+");
	fprintf(archivo, cadena);
	fclose(archivo);
	
}
int main(void)
{	
	//basevariables
	char *lenstr;
	char inputBuffer[10240];
	int contentlegth;
	int i=0 ;
	char x;
	//inputs
	char nombre[80];
	char descripcion[80];
	char path[80];
	char readOnly[80];
//	char nuevoNombre[80];
	//Base
	printf("Content-type:text/html\n\n");
	printf("<html>");

	printf("<head>");
	printf("<title> samba</title>\n");
	printf("</head>");
	printf("<body>");
	
	int iUid,iGid;
	if ((setuid(0)) < 0)
		printf("\n operacion no permitida \n");
	if ((setgid(0)) < 0)
		printf("\n operacion no permitidai \n");
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
	//base endº
	separar(nombre, inputBuffer, '=');
	separar(nombre, inputBuffer, '&');
        reemplazarCaracteres(nombre,"+", '_');
	separar(descripcion, inputBuffer, '=');
	separar(descripcion, inputBuffer, '&');
        reemplazarCaracteres(descripcion,"+", ' ');
	separar(path, inputBuffer, '=');
	separar(path, inputBuffer, '&');
	path[strlen(path)]=';';
	//int pos =buscaPuntos(path);
	//borrar(path,pos);
        reemplazarCaracteres(path,"%2F", '/');
	 int pos =buscarPunto(path);
	borrar(path,pos);

	reemplazarCaracteres(path,"\0", '.');
	separar(readOnly, inputBuffer, '=');
	separar(readOnly, inputBuffer, '&');
	
	 
	
	DIR *dir;
	 if((dir = opendir(path) == NULL)){
        
        printf("<scan style='color: red;'>¡Ups! No existe el directorio </scan><br>");
	  printf("<scan style='color: red;'>Regrese al formulario e ingrese un directorio valido porfavor </scan>");
	
	 }else{
	   
	     printf("<h1 style='color: #32cd32;'> Nuevo Recurso creado exitosamente !</h1>");
	     
	     insertarSubcadena(nombre,"[",0);//editando recursos para insertar
	     insertarSubcadena(nombre,"]",strlen(nombre));
	     insertarSubcadena(descripcion,"comment = ",0);
	     insertarSubcadena(path,"path = ",0);
	     insertarSubcadena(readOnly,"read only = ",0);
	     //muestro recurso a insertar
	  printf("<p style='color: #32cd32;' > %s</p>",nombre);
	  printf("<p style='color: #32cd32;' > %s</p>",path);
	  printf("<p style='color: #32cd32;' > %s</p>",descripcion);
	  printf("<p style='color: #32cd32;' > %s</p>",readOnly);
	  printf("<p style='color: #32cd32;' > browseable = Yes</p>");
	  printf("<p style='color: #32cd32;' > #valid users = publica</p>");
	  printf("<p style='color: #32cd32;' > create mask = 0664</p>");
	  printf("<p style='color: #32cd32;' > directory mask = 0755</p>");
	 
	    
	     
	     
	    
	char sAux[10240];// ABRO EL ARCHIVO PARA INSERTAR RECURSO
  	int nContador=0;
     	FILE *registros;
     	char aux[130];
        int tamanio=0;
	
		registros= fopen("/etc/samba/smb.conf", "r+");
		fseek(registros, 0L, SEEK_END);
	   	tamanio=ftell(registros);
		fclose(registros);
		
	 registros= fopen("/etc/samba/smb.conf", "r+");
         if(registros){
           do
           {
            fgets(aux, 130, registros);
             strncat(sAux, aux, 10240);
             
           }while (!feof(registros));
	}
	insertarSubcadena(sAux,";",tamanio);//para corregir esa linea demas
	borrarSamba(sAux,tamanio);
	insertarSubcadena(sAux,nombre,strlen(sAux));
	insertarSubcadena(sAux,"\n",strlen(sAux));
	insertarSubcadena(sAux,"\t",strlen(sAux));
	insertarSubcadena(sAux,descripcion,strlen(sAux));
	insertarSubcadena(sAux,"\n",strlen(sAux));
	insertarSubcadena(sAux,"\t",strlen(sAux));
	insertarSubcadena(sAux,path,strlen(sAux));
	insertarSubcadena(sAux,"\n",strlen(sAux));
	insertarSubcadena(sAux,"\t",strlen(sAux));
	insertarSubcadena(sAux,readOnly,strlen(sAux));
	insertarSubcadena(sAux,"\n",strlen(sAux));
	insertarSubcadena(sAux,"\t",strlen(sAux));
	insertarSubcadena(sAux,"browseable = Yes",strlen(sAux));
	insertarSubcadena(sAux,"\n",strlen(sAux));
	insertarSubcadena(sAux,"\t",strlen(sAux));
	insertarSubcadena(sAux,"#valid users = publica",strlen(sAux));
	insertarSubcadena(sAux,"\n",strlen(sAux));
	insertarSubcadena(sAux,"\t",strlen(sAux));
	insertarSubcadena(sAux,"create mask = 0664",strlen(sAux));
	insertarSubcadena(sAux,"\n",strlen(sAux));
	insertarSubcadena(sAux,"\t",strlen(sAux));
	insertarSubcadena(sAux,"directory mask = 0755",strlen(sAux));
	insertarSubcadena(sAux,"\n",strlen(sAux));
	
	
	
	guardoCambios(sAux);
	
}
		
	printf("<form ACTION='/cgi-bin/avanzado' METHOD='POST'>");
	printf("<input type ='submit'style='background-color:#4CAF50' value='Volver'>");
        printf("</form>");
	printf("</body>");
 	printf("</html>");
	return 0;
}

