#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
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


void borrar1(char *cadena ,int pos){
		
		int i=pos;
			while(cadena[i] != ']'){
				cadena[i] = ';';
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
void removerCaracteres(char *cadena, char *caracteres) {
  int indiceCadena = 0, indiceCadenaLimpia = 0;
  int deberiaAgregarCaracter = 1;
  
  while (cadena[indiceCadena]) {
    
    deberiaAgregarCaracter = 1;
    int indiceCaracteres = 0;
    while (caracteres[indiceCaracteres]) {
   	 if (cadena[indiceCadena] == caracteres[indiceCaracteres]) {
   	     deberiaAgregarCaracter = 0;
   	   }
      indiceCaracteres++;
    }
    
    if (deberiaAgregarCaracter) {
      	    cadena[indiceCadenaLimpia] = cadena[indiceCadena];
  	    indiceCadenaLimpia++;
    }
  		  indiceCadena++;
  	}
  	cadena[indiceCadenaLimpia] = 0;
}
void insertarSubcadena(char *original, char *subcadena, int indice) {
	    char inicio[10240] = "";
	    strncpy(inicio, original, indice);
	     char fin[10240] = "";
	    strncpy(fin, original + indice, strlen(original) - indice);
	    strcat(inicio, subcadena);
	    strcat(inicio, fin);
	    strcpy(original, inicio);
    }
int buscar(char *palabra,char *nuevoNombre){
    int a,tmp1,tmp2,konta=0;
    char sAux[10240];
    int nContador=0;
    FILE *registros;
    char aux[160];    
    int una=0;
	char* palabra2[60];
	insertarSubcadena(palabra,"[", 0);
       insertarSubcadena(palabra,"]", strlen(palabra));


    char nombre[60]="intento";

    int pos=0;
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
	    ///archi sAux
	  }while (!feof(registros));
	
         insertarSubcadena(sAux,";",tamanio);//para corregir esa linea demas
	borrarSamba(sAux,tamanio);
		
		for(a=0;a<strlen(sAux);a++)
         		{
				
					pos++;  
				if (palabra[0]==sAux[a])
				{
					
                 			 tmp1=0;

                  			tmp2=a;

                  		while ((palabra[tmp1]==sAux[tmp2])&&(tmp2<strlen(sAux))&&(tmp1!=strlen(palabra)))

                  			{
                        			tmp1++;

                      			 	tmp2++;

                       					 if (tmp1==strlen(palabra)) {//encuentro la palabra
                           				char *cadena=sAux;
							fgets(sAux,strlen(sAux)-1,registros);
                          				
								int tam=strlen(nuevoNombre);
								nuevoNombre[tam]='\0';
								char *subcadena=sAux;
								if(una == 0){
									borrar1(sAux,a);
								        char *corchete="[";
									insertarSubcadena(sAux,nuevoNombre, a);
									insertarSubcadena(sAux,corchete, a);
									char c[]=";";
								        removerCaracteres(sAux,c) ;		
									una++;
									int corte=sizeof(sAux);//para la linea demas
									sAux[corte]='\0';
									guardoCambios(sAux);
								

								}
						
							
                        				   konta++;
							 }
							 

                 			 }
              			 }
            }
	 
}
return 0;
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
	char nuevoNombre[80];
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
	//base endº
        separar(nuevoNombre, inputBuffer, '=');
	separar(nuevoNombre, inputBuffer, '&');

	separar(opcion, inputBuffer, '=');
	separar(opcion, inputBuffer, '&');
	
	remplazarCaracteres(nuevoNombre,"+",'_');//para este caso en especifico
	
	char *palabra;
       char *nombre;
	nombre=nuevoNombre; 
	palabra =opcion;
         buscar(opcion,nombre);	
	printf("<h1 style='color:#9ACD32;'>Nombre Modificado exitosamente!</h1> ");
	printf("<h2 style='color:#9ACD32;'>Nombre Actual: %s </h2>",nuevoNombre);
	printf("<form ACTION='/cgi-bin/avanzado' METHOD='POST'>");
	printf("<input type ='submit'style='background-color:#4CAF50' value='Volver'>");
        printf("</form>");
	printf("</body>");
 	printf("</html>");
	return 0;
}


