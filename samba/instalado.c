#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
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
	system("rpm -qa | grep samba | wc -l > estado.txt");
	FILE *archivo;
	char aux[1];
    	
	archivo = fopen("estado.txt", "r");
	if (archivo)
	{
		fscanf(archivo, "%s", aux);
		int num = atoi(aux);
        if (num == 0)//no hay nada
	{
		 printf("<h2 style='color: red;'>SAMBA no esta instalado</h2>");
			
        }else {
		 printf("<h2 style='color: #32cd32;'>SAMBA si  esta instalado</h2>");
        }
       
	}
	fclose(archivo);
	printf("</body>");
        printf("</html>");
        return 0;
}

