#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void estado(char *palabra){
    int a,tmp1,tmp2,konta=0;
    char sAux[60]="";
    int nContador=0;
    FILE *registros;
        //aqui busco la palabra active
system("systemctl status smb.service > registros.txt"); 
registros= fopen("registros.txt","r");

if (registros== NULL)
printf("No se pudo abrir el archivo %s \n", "registros.txt");
else
{ while (fscanf(registros,"%60s", sAux) != EOF)
{

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

                        if (tmp1==strlen(palabra)) {
                           
                           konta++;}
                  }
               }
            }

};
if(konta ==0){
        printf("\n<h3 style='color:red;'>Servidor Desactivado</h3>\n");
}else{
       
	printf("\n<h3 style='color: #32cd32;'>Servidor Activado</h3>\n");
}

      getchar();
fclose(registros);

}
printf("</body>");
printf("</html>");
}
int main()
{
	printf("Content-type:text/html\n\n");
        printf("<html>");
        printf("<body>");

    	if ((setuid(0)) < 0)
                printf("\n operacion no permitida \n");
        if ((setgid(0)) < 0)
                printf("\n operacion no permitida \n");
char *palabra;
palabra ="running";
estado(palabra);
return 0;
}
