# ADMINISTRADOR SAMBA PARA SISTEMAS LINUX
## INTEGRANTES :
Britany Torrico Rosas

## INSTALACION :

### Paso 1: Descargar la carpeta del proyecto ASO.tar.gz en la siguiente ubicacion de sistemas Linux 
`/srv/www/cgi-bin`
### Paso 2: Descomprimir el proyecto
Utiliza el siguiente comando para descomprimir el archivo ASO.tar.gz. Asegúrate de estar en el directorio /srv/www/cgi-bin para ejecutar el comando correctamente.
`tar -zxvf ASO.tar.gz`

### Paso 3: Copiar el archivo principal.htm
Dirígete al directorio /srv/www/cgi-bin/samba y copia el archivo principal.htm a la siguiente ubicación:
`/srv/www/htdocs`

### Paso 4: Paso 4: Dar permisos y compilar el archivo "compilar.c" 
Muevete al directorio /srv/www/cgi-bin y ejecuta los siguientes comandos para dar permisos al archivo compilar.c, compilarlo y ejecutarlo:
#### Dar permisos al archivo compilar.c
`chmod ugo+s samba/compilar.c`

#### Compilar el archivo compilar.c
`gcc samba/compilar.c -o programa`

#### Ejecutar el programa generado
`./programa`

### Paso 5: Acceder a la aplicación
Abre Firefox y en la barra de direcciones escribe:
localhost/principal.htm

Y listo puede navegar en la app del administrador samba.
Para una mejor experiencia tener recursos compartidos creados anteriormente.(Para probar las funciones)