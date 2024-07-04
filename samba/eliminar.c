#include <stdio.h>
#include <stdlib.h>
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
void insertarSubcadena(char *original, char *subcadena, int indice) {
	    char inicio[10240] = "";
	    strncpy(inicio, original, indice);
	     char fin[10240] = "";
	    strncpy(fin, original + indice, strlen(original) - indice);
	    strcat(inicio, subcadena);
	    strcat(inicio, fin);
	    strcpy(original, inicio);
    }
int buscar(char *palabra){
    int a,tmp1,tmp2,konta=0;
    char sAux[10240];
    int nContador=0;
    FILE *registros;
    char aux[160];    
    int una=0;
	char* palabra2[60];
	insertarSubcadena(palabra,"[", 0);
       insertarSubcadena(palabra,"]", strlen(palabra));

    int pos=0;
 	registros= fopen("/etc/samba/smb.conf", "rw");
	if(registros){
	  do
	  {
	    fgets(aux, 130, registros);
	    strncat(sAux, aux, 10240);
	    ///archi sAux
	  }while (!feof(registros));
	
         
		
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

                       					 if (tmp1==strlen(palabra)) {
  
								if(una == 0){
								  una++;
								  return a;
									

								}
						
							
                        				   konta++;
							 }
							 

                 			 }
              			 }
            }
	 
}

}
void borrar(char *cadena,int corte){
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
void borrarRecurso(char *cadena ,int pos){
  int i=pos-1;
  while(cadena[pos] != '['){
    cadena[pos]=';';
    pos++;
  }
  cadena[i]=';';
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
int buscarPunto(char *cadena){
	int i=0;
	while(cadena[i] != ';'){
	i++;
	
}
return i;

	
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
//	char nuevoNombre[80];
	//Base
	printf("Content-type:text/html\n\n");
	printf("<html>");

	printf("<head>");
	printf("<title>Eliminar Recurso</title>\n");
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
	separar(opcion, inputBuffer, '=');
	separar(opcion, inputBuffer, '&');
	printf("<h1 style='color:#9ACD32;'>Recurso %s eliminado exitosamente !</h1>",opcion);
	
	char sAux[10240];// ABRO EL ARCHIVO 
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
	borrar(sAux,tamanio);
	guardoCambios(sAux);
	//empiezo
	insertarSubcadena(sAux,"[",tamanio);//para el ultimo recurso
	int posicion=buscar(opcion);	//busca la el nombre del recurso
	borrarRecurso(sAux,posicion+1);//convierto en ;
	removerCaracteres(sAux,";");
	int nuevoPos=strlen(sAux);
	insertarSubcadena(sAux,";",nuevoPos-1);//para corregir linea demas
	int puntoComa=buscarPunto(sAux);
	borrar(sAux,puntoComa);
	guardoCambios(sAux);
	printf("<form ACTION='/cgi-bin/avanzado' METHOD='POST'>");
	printf("<input type ='submit'style='background-color:#4CAF50' value='Volver'>");
        printf("</form>");
	printf("</body>");
 	printf("</html>");
	return 0;
}
