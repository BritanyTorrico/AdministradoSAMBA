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
int buscarPosicion(char *palabra){
    int a,tmp1,tmp2,konta=0;
    char sAux[10240];
    int nContador=0;
    FILE *registros;
    char aux[160];    
    int posicion=0;
    	int primeraVuelta=0;
 	registros= fopen("samba.txt", "rw");
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
	archivo = fopen("samba.txt", "w+");
	fprintf(archivo, cadena);
	fclose(archivo);
	
}
void guardoCambios2(char *cadena)
{
	
	FILE *archivo;
	archivo = fopen("samba3.txt", "w+");
	fprintf(archivo, cadena);
	fclose(archivo);
	
}
int buscarNombres(char caracter,char destino[60][60]) {
    char sAux4[60];//Almacena el char de donde se cargaran los recuros compartidos
   // char caracter = '['; //Declaramos en el caracter de tipo ASCII 
    int j=0;
    int i=0;
        int pos=0;
    FILE *registros;
      //Abrimos el archivo donde se almacena el contenido de smb.conf
      if ((registros = fopen("samba.txt", "r")) == NULL) {
      perror("Error opening file"); //En caso de error
      exit(EXIT_FAILURE);
  }
     //Almacenamos el contenido de archivo en un char
       while (fscanf(registros,"%s\n", sAux4) != EOF) {
     //Recorremos el char donde se almaceno el contenido de smb.conf linea por liena
        for (j = 0; sAux4[j] != '\0'; j++) {
     //Si en dentro del char encuentra '[' entonces lo almacenamos en sAux e imprimimos
        if (caracter == sAux4[j]){
                        pos++;
                      removerCaracteres(sAux4,"[");
                       removerCaracteres(sAux4,"]");

                        strcat(destino[i],sAux4); 
                          i++;}
   }
}
return pos;
}
void buscar(char *palabra,char destino[60][60]){
        int a,tmp1,tmp2,konta=0;
    char sAux[60]="";
    int nContador=0;
    FILE *registros;
int pos=0;
int i=0;

registros= fopen("samba.txt","rw");

if (registros== NULL)
printf("No se pudo abrir el archivo %s \n", "samba.txt");
else
{ while (fscanf(registros,"%60s", sAux) != EOF)
{

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
                 
			
                        fgets(sAux,sizeof(sAux),registros); 
			removerCaracteres(sAux,"=");
                         strcat(destino[i],sAux);        
                           i++;


                           konta++;
                        }
                  }
               }
            }
        
};
if(konta ==0)
        printf("<p>Archivo no encontrado %d</p>\n");



      getchar();
fclose(registros);

}

}



int buscarPath(char *palabra,char destino[60][60],int i){
        int a,tmp1,tmp2,konta=0;
   char sAux[60]="";
    // char aux[130]="";
   //int nContador=0;
   char sAux1[10240];
   char aux1[130];
   int una=0;
FILE *registros;
int pos=0;
FILE *registros1;
 int tamanio=0;
	 registros1= fopen("samba3.txt", "r+");
		fseek(registros1, 0L, SEEK_END);
	   	tamanio=ftell(registros1);
		fclose(registros1);
registros1= fopen("samba3.txt", "rt");
	if(registros1){
	  do
	  {
	    fgets(aux1, 130, registros1);
	    strncat(sAux1, aux1, 10240);
	    ///archi sAux
	  }while (!feof(registros1));
	}
	 insertarSubcadena(sAux1,";",tamanio);//para corregir esa linea demas
	borrarSamba(sAux1,tamanio);
		

	int ojo=buscarCorchete2(sAux1,1);//obtengo el recurso
	borrarSamba(sAux1,ojo);
	guardoCambios2(sAux1);

	
	registros= fopen("samba3.txt","r");

if (registros== NULL)
printf("No se pudo abrir el archivo %s \n", "samba3.txt");
else
{ while (fscanf(registros,"%60s", sAux) != EOF)
{
       


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
                        fgets(sAux,sizeof(sAux),registros);    
			removerCaracteres(sAux,"=");
                        strcat(destino[i],sAux);
			  una++;
                           konta++;
			   
			   
			   
			}
			}
                  }
               }
            }
        
};
}
return konta;
}


void borrrarGlobal(char *samba,int limite){
int i=0;
while(i<limite){
samba[i]=';';
i++;

}
}
void borrarAbajo(char *cadena,int corte){
	int i=corte;
   
	while(i < 10240){
		cadena[i]='\0';
		i++;
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


int buscarCorchete2(char *cadena ,int posi){
while(cadena[posi] != '['){
posi++;
}
return posi;
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
        char opcion[60];
//      char nuevoNombre[80];
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
	printf("<div style='border: 2px solid black;'>");
                 
        printf("<h1 style='color:#9ACD32;text-align:center;'> Configuracion Avanzada SAMBA</h1>");
        printf("<h3 style='color:#6B8E32'>Recursos Compartidos</h3>");

        char destino[60][60];
        char destino1[60][60];
        char destino2[60][60];
        char destino3[60][60];
	//abro archivo samba y copio a txt
	FILE *file1 , *file2;
       int data1 =0;
   
       file1 = fopen ( "/etc/samba/smb.conf", "r+" );
       file2 = fopen ( "samba.txt" , "w+" );
  	char sAux[10240];
  	int nContador=0;     	
     	char aux[130];
      while ( (data1 = fgetc ( file1 )) != EOF ) {
         fputc ( data1, file2 );
      }
	fclose(file1);
	fclose(file2);
		
	 file2= fopen("samba.txt", "rw+");
         if(file2){
           do
           {
            fgets(aux, 130, file2);
             strncat(sAux, aux, 10240);
             
           }while (!feof(file2));
	}
	 int tamanio1=0;
	 FILE *registros11;
	 registros11= fopen("samba.txt", "r+");
		fseek(registros11, 0L, SEEK_END);
	   	tamanio1=ftell(registros11);
		fclose(registros11);
	  insertarSubcadena(sAux,";",tamanio1);//para corregir esa linea demas
	borrarSamba(sAux,tamanio1);
	//edito el archivo samba
	int cor=buscarCorchete2(sAux,0);//buscar el corchete del global
  	int buscarPos=buscarCorchete2(sAux,cor+1);
        borrrarGlobal(sAux,buscarPos);
	int homes=buscarPosicion("[homes]"); 	
	borrarPrint(sAux,homes+1);
	int buscarPrint=buscarPosicion("[print$]");
	borrarPrint(sAux,buscarPrint+1);
        int buscarPrinters=buscarPosicion("[printers]"); 	
	borrarPrint(sAux,buscarPrinters+1);
	
	removerCaracteres(sAux,";");
	guardoCambios(sAux);
	  //EDITO
	
	
        int recursos =  buscarNombres('[',destino3);//este tiene que ser on samba.txt original
	int z=0;
	
	for(z=0;z<recursos;z++){
	//genero una copia por que parto el archivo samba3 para el path
	FILE *file11 , *file21;
	int data11 =0;
	file11 = fopen ( "samba.txt", "r" );
	file21 = fopen ( "samba3.txt" , "w+" );
  	char sAux1[10240];	
     	char aux1[130];
      while ( (data11 = fgetc ( file11 )) != EOF ) {
         fputc ( data11, file21 );
      }
	fclose(file11);
	fclose(file21);
	//copio samba3 - sAux1	
	 file21= fopen("samba3.txt", "r");
         if(file21){
           do
           {
            fgets(aux1, 130, file21);
             strncat(sAux1, aux1, 10240);
             
           }while (!feof(file21));
	}
	 int tamanio=0;
	 FILE *registros1;
	 registros1= fopen("samba3.txt", "r");
		fseek(registros1, 0L, SEEK_END);
	   	tamanio=ftell(registros1);
		fclose(registros1);
	  insertarSubcadena(sAux1,";",tamanio);//para corregir esa linea demas
	  borrarSamba(sAux1,tamanio);
	
	  
	  if(z !=0 ){//borro
	 int ojo=buscarCorchete2(sAux1,1);
	 borrrarGlobal(sAux1,ojo);
	 removerCaracteres(sAux1,";");
	 guardoCambios2(sAux1);
	 }
	  
	  int hay=buscarPath("path",destino1,z);
	
	
	
	}
        buscar("comment",destino);
       // buscar1("path",destino1);
        buscar("only",destino2);
        
    
int u=0;
      printf("<div  align='left' style='color:#00CC00;'>");
      printf("<table border='1'>");
		
		printf("<tr style='background:#7fbf7f;text-align:center;'>");
			printf("<th style='color:#FFFFFF' >Nombre</th>");
			printf("<th style='color:#FFFFFF'>Comment</th>");
			printf("<th style='color:#FFFFFF'>Path</th>");
			printf("<th style='color:#FFFFFF'>Read_Only</th>");
			;
		printf("</tr>");
		
	  for(u=0;u<recursos;u++){
                      printf("<tr>");
			printf("<td>%s</td>",destino3[u]);
			printf("<td>%s</td>",destino[u]);
			printf("<td>%s</td>",destino1[u]);
			printf("<td>%s</td>",destino2[u]);
		printf("</tr>");
}

		printf("</table>");
// hasta aca
               printf("</div>");
               printf("</div>");
	
        printf("<div style= 'color:#000000;'");       
              
        int j=0;

        //ACA COMIENZA EL SELECT/
        
        printf("<form ACTION='/cgi-bin/hola2' METHOD='POST'>");
        printf("<h3 style='color:#6B8E32';text-align:left;'></h3>"); 
        printf("<div style='border: 2px solid black;'>");
        printf("<h3 style='color:#6B8E32';text-align:left;'> Seleccione un recurso compartido:</h3>");

        printf("<form ACTION='/cgi-bin/editarRecurso' METHOD='POST'>");
        printf("<h5 style='color:#336600'>Editar recursos compartidos</h5>");



        printf("<select name='select' style='border: 2px solid green;'>");
        for(j=0;j<recursos;j++){
            printf("<option value='%s'>%s</option><br /> ",destino3[j],destino3[j]);
        
        }
       
        printf("<input type ='submit'style='background-color:#4CAF50' value='Editar'>");
        printf("</form>");
	//ELIMINAR
	printf("<form ACTION='/cgi-bin/eliminar' METHOD='POST'>");
	printf("<h5 style='color:#336600'>Eliminar recursos compartidos</h5>");
        printf("<select name='select' style='border: 2px solid green;'>");

        for(j=0;j<recursos;j++){
            printf("<option value='%s'>%s</option> ",destino3[j],destino3[j]);
        }
        printf("<br />");
        printf("<input type ='submit'style='background-color:#4CAF50' value='Eliminar'>");
        printf("</form>");

	//RENOMBRAR
        printf("<form ACTION='/cgi-bin/renombrar.cgi' METHOD='POST'>");
        printf("<h5 style='color:#336600'>Renombrar recursos compartidos</h5>");
        printf("<select name='select' style='border: 2px solid green;'>");
        for(j=0;j<recursos;j++){
            printf("<option value='%s'>%s</option> ",destino3[j],destino3[j]);
        }
        printf("<input type ='submit'style='background-color:#4CAF50'value='Renombrar'><br>");
        printf("</form>");
        //AGREGAR
        printf("<h3 style='color:#6B8E32'>Agregar un recurso compartido</h3>");

        printf("<form ACTION='/cgi-bin/nuevo' METHOD='POST'>");
        printf("<input type ='submit'style='background-color:#4CAF50' value='Confirmar'>");
        printf("</form>");
	
        printf("</div>");
        printf("</div>");
	printf("<form ACTION='/principal.htm' METHOD='POST'>");
	printf("<input type ='submit'style='background-color:#4CAF50' value='Volver'>");
        printf("</form>");
        printf("</body>");
        printf("</html>");
        return 0;
}

