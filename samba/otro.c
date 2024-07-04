#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAXIMA_LONGITUD 10000
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
void borrarSamba(char *cadena,int corte){
	int i=corte;
    
	while(i < 10240){
	
	cadena[i]='\0';
		i++;
	}
 
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

void guardoCambios(char *cadena)
{
	FILE *archivo;
	archivo = fopen("/etc/samba/smb.conf", "w+");
	fprintf(archivo,cadena);
	fclose(archivo);
	
}
void borrar(char *cadena,int corte){
	int i=corte;
      //printf("<p>%d</p>",sizeof(text));
	while(i < 10240){
		cadena[i]='\0';
		i++;
	}
}
int buscar(char *cadena){
	int i=0;
	while(cadena[i] != ';'){
	i++;
	}
      return i;
}
void converir(char *cadena,int pos){
    while(cadena[pos] != '\n'){
      cadena[pos]=';';
      pos++;
    }
}
void borrarPrint(char *samba,int limite){
int i;
i=limite;
while(samba[limite] != '['){
samba[limite]=';';
limite++;
}
samba[limite]=';';
}
void borrar1(char *cadena ,int pos){
	int i=pos;
	while(cadena[i] != ' '){
	cadena[i] = ' ';
	i++;	
	}
}
int buscar1(char *cadena){
          int i=0;
	  int j=0;
          while(cadena[i] != '='){	 
	    i++; 
	  }   
	borrar1(cadena,i+1);	  
 return i; 
  }

void insertarSubcadena(char *original, char *subcadena, int indice) {
    // El inicio es copiar la original N caracteres definidos por posición
    char inicio[10240] = "";
    strncpy(inicio, original, indice);
    // El final es copiar desde la posición N caracteres definidos por los sobrantes
    char fin[10240] = "";
    strncpy(fin, original + indice, strlen(original) - indice);
    // Agregar la subcadena al inicioXIMA_LONGITUD 100
    strcat(inicio, subcadena);
    // Y agregar el fin a la anterior cadena, es decir, al inicio
    strcat(inicio, fin);
    // Copiarla dentro de la cadena recibida
    strcpy(original, inicio);
}
int buscarPosicion(char *palabra){
    int a,tmp1,tmp2,konta=0;
    char sAux[10240];
    int nContador=0;
    FILE *registros;
    char aux[160];    
    int posicion=0;
    	int primeraVuelta=0;
 	registros= fopen("/etc/samba/smb.conf", "rw");
	if(registros){
	  do
	  {
	    fgets(aux, 130, registros);
	    strncat(sAux, aux, 10240);
	    ///archi sAux
	  }while (!feof(registros));
	
         //empiezo a buscar la palabra en el texto sAux-> samba
		
   for(a=0;a<strlen(sAux);a++)
        	{
	  
     if (palabra[0]==sAux[a])
	{
					
                 tmp1=0;
		 tmp2=a;

        while ((palabra[tmp1]==sAux[tmp2])&&(tmp2<strlen(sAux))&&(tmp1!=strlen(palabra)))

             	{
                        tmp1++;
			tmp2++;

                      if (tmp1==strlen(palabra)) {//encuentro la palabra
			    fgets(sAux,strlen(sAux)-1,registros);
			if(primeraVuelta==0){
			posicion=a;
			primeraVuelta++;
				}
				
	 konta++;
		  }
							 

                 }
               }
            }
	
	}
return posicion;
}


int buscarPosicion1(char *palabra){
    int a,tmp1,tmp2,konta=0;
    char sAux[10240];
    int nContador=0;
    FILE *registros;
    char aux[160];    
    int posicion=0;
     int tamanio=0;
    	int primeraVuelta=0;
	registros= fopen("/etc/samba/smb.conf", "rw");
		fseek(registros, 0L, SEEK_END);
	   	tamanio=ftell(registros);
		fclose(registros);
 	registros= fopen("/etc/samba/smb.conf", "rw");
	if(registros){
	  do
	  {
	    fgets(aux, 130, registros);
	    strncat(sAux, aux, 10240);
	    ///archi sAux
	  }while (!feof(registros));
	insertarSubcadena(sAux,";",tamanio);//para corregir esa linea demas
	borrarSamba(sAux,tamanio);
         //empiezo a buscar la palabra en el texto sAux-> samba
		
   for(a=0;a<strlen(sAux);a++)
        	{
	  
     if (palabra[0]==sAux[a])
	{
					
                 tmp1=0;
		 tmp2=a;

        while ((palabra[tmp1]==sAux[tmp2])&&(tmp2<strlen(sAux))&&(tmp1!=strlen(palabra)))

             	{
                        tmp1++;
			tmp2++;

                      if (tmp1==strlen(palabra)) {//encuentro la palabra
			    fgets(sAux,strlen(sAux)-1,registros);
			if(primeraVuelta==0){
			posicion=a;
			primeraVuelta++;
			
				}
				
	 konta++;
		  }
							 

                 }
               }
            }
            if(posicion > 0){
	       borrarPrint(sAux,posicion+1);
	       removerCaracteres(sAux,";");
	        
			guardoCambios(sAux);
	    }
	
	}
	               
return posicion;
}


int main(void)
{
	
	char *lenstr;
	char inputBuffer[90];
	int contentlegth;
	int i = 0;
	char x;
	//inputs
	char nombre[80];
	char *select;
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
	//base end
	
	int home=buscarPosicion1("[homes]");
	separar(nombre, inputBuffer, '=');
	separar(nombre, inputBuffer, '&');
	remplazarCaracteres(nombre,"+",'_');//para este caso en especifico
	//inserto el workgroup
	int tam=sizeof(nombre)-1;
	nombre[tam]='\n';
	FILE *samba;
	char sAux[10240];
	char aux[160];
	char copySamba[10240]; 
	int tamanio=0;
        samba = fopen("/etc/samba/smb.conf", "rw");
	fseek(samba, 0L, SEEK_END);
	tamanio=ftell(samba);
	fclose(samba);
	samba = fopen("/etc/samba/smb.conf", "rw");
	
        //copio archivo en char[] = copySamba
	if (samba)
          {
                  do
                 {
                          fgets(aux, 130, samba);
                          strncat(copySamba, aux, 10240);
                  } while (!feof(samba));
	insertarSubcadena(copySamba,";",tamanio);//para corregir esa linea demas
	borrar(copySamba,tamanio);
	guardoCambios(copySamba);
	
 	//borrarPrint(home+2);
	
	//empiezo
	char *subcadena=copySamba;
	int pos=buscarPosicion("workgroup");
	int tamPalabra=9;
	converir(copySamba,pos+tamPalabra+2);//convierto ; el anterior workgroup
	removerCaracteres(copySamba,";");
	insertarSubcadena(copySamba,nombre, pos+tamPalabra+2);//inserto el nuevo workgroup
	
	printf("<h2 style='color:#9ACD32;'>Configuracion SAMBA actualizada</h2>\n");
	printf("<label style='color:#9ACD32;'>______________________________________________</label>\n");
	printf("\n<p>workgroup=%s</p>",nombre);
	
	printf("<form ACTION='/principal.htm' METHOD='POST'>");
	printf("<input type ='submit'style='background-color:#4CAF50' value='Volver'>");
        printf("</form>");
	//insertarSubcadena(copySamba,nombre, pos+1);
	//int valoor=buscar(copySamba);
	//borrar(copySamba,valoor);
	guardoCambios(copySamba);

}	
  printf("</body>");
  printf("</html>");
  return 0;
}
