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

void escribo(char *cadena)
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
int buscarPosicion(char *palabra,char * sAux){
    int a,tmp1,tmp2,konta=0;
    int nContador=0;   
    int posicion=0;
    int primeraVuelta=0;
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
			  //  fgets(sAux,strlen(sAux)-1,registros);
			if(primeraVuelta==0){
			posicion=a;
			primeraVuelta++;
				}
				
	 konta++;
		  }
							 

                 }
               }
            }
	
	
return posicion;
}

void borrar1(char *cadena ,int pos){
		int i=0;
		int anterior;
			while(i != pos){//borra lo que esta arriba antes de la palabra
				cadena[i] = ';';
				i++;	
			}

                       anterior=i;
			while(cadena[anterior] != '[' ){//voy hasta el recurso compartido a recuperar info 
			anterior++;
                   
		}
		
		cadena[anterior]='\0';//borro lo que esta despues
		int aux=anterior+1;
		while(aux < 10240){
 			cadena[aux]=';';
			aux++;
		}

	
}
 void borrar(char *cadena,int corte){
          int i=corte;
          while(i < 10240){       
          cadena[i]='\0';
                 i++;
          }
  
  }

int buscar(char *palabra){
    int a,tmp1,tmp2,konta=0;
    char sAux[10240];
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
	    ///archi sAux
	  }while (!feof(registros));
	
        insertarSubcadena(sAux,";",tamanio);//para corregir esa linea demas
        borrar(sAux,tamanio);
        escribo(sAux);

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
                           			
					int tamOpcion=strlen(palabra);
					insertarSubcadena(sAux,"[",tamanio);//para el ultimo recurso	
					borrar1(sAux,a+tamOpcion);//convierto ;
					char c[]=";";
					removerCaracteres(sAux,c) ;//elimino ;
                      printf("\n <pre style='border-color: #32cd32;'>%s;</pre> \n", sAux);
		      // si no tiene path
		      int verificar=buscarPosicion("path",sAux);
		      if(verificar == 0){
			printf("\n <form action='./guardarCambios' method='post'> \n");    
			printf("\n <textarea name='recursoEditado' style='display:none;' rows='10' cols='70'>%s;</textarea> \n", sAux);
		        printf("\n <textarea name='nombre' style='display:none;' rows='3' cols='3'>%s;</textarea> \n", palabra);
			printf("<select name='select' style='border: 2px solid green;'>");
			printf("<option name='opcion' value='read only'>read only</option><br /> ");
			printf("<br/>");
			printf("\n<input type ='submit'style='background-color:#4CAF50' value='Editar'>\n");
			printf("\n </form> \n");
		      }else{//si tiene los dos
		      printf("\n <form action='./guardarCambios' method='post'> \n");      
		      printf("\n <textarea name='recursoEditado' style='display:none;' rows='10' cols='70'>%s;</textarea> \n", sAux);
		      printf("\n <textarea name='nombre' style='display:none;' rows='3' cols='3'>%s;</textarea> \n", palabra);
		
		      printf("<select name='select' style='border: 2px solid green;'>");
		      printf("<option name='opcion' value='read only'>read only</option><br /> ");
		      printf("<option  name='opcion' value='path'>path</option><br /> ");
		      printf("<br/>");
		      printf("\n<input type ='submit'style='background-color:#4CAF50' value='Editar'>\n");					
		      konta++;
		      printf("\n </form> \n");
					 }
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

	separar(opcion, inputBuffer, '=');
	separar(opcion, inputBuffer, '&');
	
	printf("<h1 style='color: #32cd32;'>EDITAR RECURSO COMPARTIDO</h1>");

	//metodos
	
	printf("<h2>Configuracion de recurso compartido: %s</h2> ",opcion); 
	
       insertarSubcadena(opcion,"[", 0);
	insertarSubcadena(opcion,"]", strlen(opcion));
      	buscar(opcion); 


	printf("</body>");
 	printf("</html>");
	return 0;
}
