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
void insertarSubcadena(char *original, char *subcadena, int indice) {
	    //original[indice]='\n';
	char inicio[10240] = "";
	    strncpy(inicio, original, indice);
	     char fin[10240] = "";
	    strncpy(fin, original + indice, strlen(original) - indice);
	    strcat(inicio, subcadena);
	    strcat(inicio, fin);
	    strcpy(original, inicio);
    }
int buscarPuntoComa(char *cadena){
	int i=0;
	while(cadena[i] != ';'){
	i++;
	
}
return i;

	
}
void borrar(char *cadena,int corte){
	int i=corte;
    
	while(i < 10240){
	
	cadena[i]='\0';
		i++;
	}
 
}
void borrarNombre(char *cadena,int corte){
	int i=corte;
    
	while(i < 80){
	
	cadena[i]='\0';
		i++;
	}
 
}
int buscarPosicion(char *palabra,char* recursoEditado){
    int a,tmp1,tmp2,konta=0;
    char sAux[10240];
    int nContador=0;
    FILE *registros;
    char aux[160];    
    int posicion=0;
    	int primeraVuelta=0;
 	registros= fopen("/etc/samba/smb.conf", "rw+");
	if(registros){
	  do
	  {
	    fgets(aux, 130, registros);
	    strncat(sAux, aux, 10240);
	    ///archi sAux
	  }while (!feof(registros));
	
         //empiezo a buscar la palabra en el texto sAux-> samba
		
   for(a=0;a<strlen(recursoEditado);a++)
        	{
	  
     if (palabra[0]==recursoEditado[a])
	{
					
                 tmp1=0;
		 tmp2=a;

        while ((palabra[tmp1]==recursoEditado[tmp2])&&(tmp2<strlen(recursoEditado))&&(tmp1!=strlen(palabra)))

             	{
                        tmp1++;
			tmp2++;

                      if (tmp1==strlen(palabra)) {//encuentro la palabra
			    //fgets(recursoEditado,strlen(sAux)-1,registros);
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

void borrar1(char *cadena,int pos){
  int i=0;
  int anterior;
  while(i != pos){//borra lo que esta arruba antes de la palabra
				cadena[i] = ';';
				i++;	
			}
			anterior=i;
			while(cadena[anterior] != '\n' ){//voy hasta el recurso compartido a recuperar info 
			anterior++;
                
		}
		   cadena[anterior]='\0';//borro lo de abajo
}
void editarRead(char* opcion, char *recursoEditado,char *nombre){
   printf("\n <form action='./guardarCambios1' method='post'> \n"); 
  
    printf("\n <textarea name='recursoEditado' style='display:none;' rows='10' cols='70'>%s;</textarea> \n", recursoEditado);
    printf("\n <textarea name='nombre' style='display:none;' rows='10' cols='70'>%s;</textarea> \n", nombre);
 
  int p= buscarPosicion(opcion,recursoEditado);
  borrar1(recursoEditado,p);//obtengo solo el recurso
  removerCaracteres(recursoEditado,";");
  int option=buscarPosicion("Yes",recursoEditado);

  if(option != 0 ){//si es yes
   
    printf("<h2>Nuevo: </h2>");
     printf("<input type='radio'  name='opcion' value='Yes' checked>Yes");
      printf("<input type='radio'  name='opcion' value='No' >No");
     
      printf("<br />");
      printf("\n<input type ='submit'style='background-color:#4CAF50' value='Confirmar'>\n");
    
  }else{
    // printf("\n <form action='./guardarCambios1' method='post'> \n");  
    printf("<h2>Nuevo:</h2>\n");
     printf("<input type='radio'  name='opciones' value='Yes' >Yes");
      printf("<input type='radio'  name='opciones' value='No' checked>No");
      // printf("\n <textarea name='recursoEditado' style='display:none;' rows='10' cols='70'>%s;</textarea> \n", sineditar);
        printf("<br />");
       printf("\n<input type ='submit'style='background-color:#4CAF50' value='Confirmar'>\n");
     
      
  }
 printf("\n </form> \n");
}
void editarPath(char *opcion,char *recursoEditado,char *nombre){
  printf("\n <form action='./guardarPath' method='post'> \n"); 
  
    printf("\n <textarea name='recursoEditado' style='display:none;' rows='10' cols='70'>%s;</textarea> \n", recursoEditado);
    printf("\n <textarea name='nombre' style='display:none;' rows='10' cols='70'>%s;</textarea> \n", nombre);
   printf("<label>Nuevo path:</label>\n");
   printf("<input name='path' maxlength='80' required/>");
  printf("<br />");
  printf("\n<input type ='submit'style='background-color:#4CAF50' value='Confirmar'>\n");
  printf("\n </form> \n");
  
}

int main(int argc, char *argv[])
{	
	//basevariables
	char *lenstr;
	char inputBuffer[10240];
	int contentlegth;
	int i=0 ;
	char x;
	//inputs
	char recursoEditado[10240];
	char nombre[80];
	char opcion[80];
	
	//
//	char nuevoNombre[80];
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
	//recurso
	separar(recursoEditado, inputBuffer, '=');
	separar(recursoEditado, inputBuffer, '&');
	reemplazarCaracteres(recursoEditado,"%09",'\t');
	reemplazarCaracteres(recursoEditado,"+",' ');
	reemplazarCaracteres(recursoEditado,"%3D",'=');
	reemplazarCaracteres(recursoEditado,"%2F",'/');
	reemplazarCaracteres(recursoEditado,"%0D%0A", '\n');
	reemplazarCaracteres(recursoEditado,"%23", '#');
     	reemplazarCaracteres(recursoEditado,"%3B", ';');
	reemplazarCaracteres(recursoEditado,"%5C", '\\');
	reemplazarCaracteres(recursoEditado,"%25", '%');
	reemplazarCaracteres(recursoEditado,"%2E", '.');
	reemplazarCaracteres(recursoEditado,"%40", '@');
	insertarSubcadena(recursoEditado,"\n",0);
	int valoor=buscarPuntoComa(recursoEditado);//busca el ; al final que le puse
        borrar(recursoEditado,valoor);//recupero la info sin espacion extras

	//nombre
	separar(nombre, inputBuffer, '=');
	separar(nombre, inputBuffer, '&');
	reemplazarCaracteres(nombre,"%5D", ']'); 
	reemplazarCaracteres(nombre,"%5B", '[');
	reemplazarCaracteres(nombre,"%3B", ';');
	int valor=buscarPuntoComa(nombre);
        borrarNombre(nombre,valor);
	
	//opcion
	separar(opcion, inputBuffer, '=');
	separar(opcion, inputBuffer, '&');
	reemplazarCaracteres(opcion,"+", ' '); 
	

	
	if(strlen(opcion)>4){//si selecciona read only
	  printf("<h1 style='color: #32cd32;'>Actualizar Read Only</h1>");
	  editarRead(opcion,recursoEditado,nombre);
	}else{//seleccion path
	   printf("<h1 style='color: #32cd32;'>Actualizar PATH</h1>");
	   editarPath(opcion,recursoEditado,nombre);
	}
        
	
	printf("</body>");
 	printf("</html>");
	return 0;
}
