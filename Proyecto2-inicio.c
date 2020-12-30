# include <stdio.h>
#include <stdio.h> 
#include <conio.h>
#include <stdlib.h>
#include <Windows.h> 



/* ----------------------------------------------------------------------------------------------------------------------------*/ 
//                                  CÓDIGO AUXILIAR DE TODO EL PROGRAMA
/* ----------------------------------------------------------------------------------------------------------------------------*/


void color_error(){
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.
 	int  New_Color= 4 + (0 * 16);
 	SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola. 
}

void color_aceptado(){
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.
 	int  New_Color= 2 + (0 * 16);
 	SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola. 
	
}

void color_normal(){
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.
 	int  New_Color= 15 + (0 * 16);
 	SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola. 
}


/* ----------------------------------------------------------------------------------------------------------------------------*/ 
//                                  CÓDIGO PARA EL INICIO
/* ----------------------------------------------------------------------------------------------------------------------------*/
 
void inicio(){
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.
 	int  New_Color= 14 + (0 * 16);
 	SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola. 
	printf ("\n\n\n\n                       *                                                           *\n");
	Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.
 	New_Color= 2 + (0 * 16);
 	SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola.
	printf ("                      ***                                                         ***\n");
	printf ("                     *****           ");
	Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.
 	New_Color= 4 + (15 * 16);
 	SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola.
	printf ("------------ NAVITEC ------------");
	Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.
 	New_Color= 2 + (0 * 16);
 	SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola. 	
	printf ("           *****\n");
	printf ("                    *******                                                     *******\n");
	printf ("                   *********                                                   *********\n");
	printf ("                  ***********                                                 ***********\n");
	printf ("                 *************                                               *************\n");
	Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.
 	New_Color= 6 + (0 * 16);
 	SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola.
 	printf("                      ***                                                         ***  \n");
 	printf("                      ***                                                         ***  \n\n\n\n");
 	
 	Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.
 	New_Color= 15 + (0 * 16);
 	SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola.

	
	system ("PAUSE"); 
    system("cls");
    
}



/* ----------------------------------------------------------------------------------------------------------------------------*/ 
//                                  CÓDIGO PARA NIÑOS
/* ----------------------------------------------------------------------------------------------------------------------------*/
 
// struct para crear la lista

typedef struct nino {
	char cedula[40];               // Datos de los niños 
	char usuario[40];                   
	char nombre[40];
	char correo[40];
	int edad;
	char especialidades[40];
	char nacimiento[40];
	char residencia[40];
	struct nino * siguiente;   // Putero a siguiente
	struct nino * anterior; 	// Putero a anterior
} ninos;

// Estructura de la lista doble
typedef struct Lista
{
	int largo;           // Largo de la lista doble
	struct nino * inicio;
	struct nino * final;
} Lista_Doble;

// Crear una nueva lista doble
Lista_Doble *listaNueva(Lista_Doble * L)
{
	L= NULL;
	L = (Lista_Doble *) malloc(sizeof(Lista_Doble));
	L->inicio = NULL;    // Poner inicio NULL
	L->final = NULL;	// Poner final NULL
	L->largo=0;			// Poner largo 0
	return L;
}

// Crear un nuevo nodo para la lista doble

ninos * nuevo_nino (struct nino datos)
{
	ninos * nuevo;
	nuevo = (ninos *) malloc(sizeof(ninos));
	nuevo->anterior = NULL;
	nuevo->siguiente = NULL;          //Copiar los datos del niño al nuevo nodo
	strcpy (nuevo->nombre,datos.nombre);
	strcpy (nuevo->cedula,datos.cedula);
	strcpy (nuevo->usuario,datos.usuario);
	strcpy (nuevo->correo,datos.correo);
	strcpy (nuevo->nacimiento,datos.nacimiento);
	strcpy (nuevo->residencia,datos.residencia);
	strcpy (nuevo->especialidades,datos.especialidades);
	nuevo->edad=datos.edad;
	
	return nuevo;            // retornar los datos
}

// Muestra la lista doble de derecha a izquierda
void mostrarLista_Doble_Ninos(Lista_Doble *Lista)
{
	ninos *i;
	printf("Existen los siguientes ninos en el sistema: \n");
	for(i = Lista->inicio; i!= NULL; i = i->siguiente) //recorrer la lista
	{           
		printf("-Nombre: %s -Cedula: %s -Correo: %s -Edad: %i -Nacimiento: %s\n",i->nombre,i->cedula,i->correo,i->edad,i->nacimiento); //Imprimir los datos
		printf("\n");
	}
}

// Insertar datos en la lista doble
Lista_Doble * insertarDatos(Lista_Doble * Lista, struct nino datos)
{
	Lista->largo=Lista->largo+1;
	if(Lista->inicio == NULL) //Valida si la lista está vacía
	{
		//Inserta al inicio de la lista
		Lista->inicio= nuevo_nino(datos);
		Lista->final = Lista->inicio;
		return Lista;
	}
	
	//Inserta el dato al final de la lista, no necesita un ciclo porque tiene el puntero final
	Lista->final->siguiente = nuevo_nino(datos);
	Lista->final->siguiente->anterior = Lista->final;
	Lista->final = Lista->final->siguiente;
}

//Insertar datos de un nino
Lista_Doble * nuevos_datos(Lista_Doble * registro_ninos)
{
	char fecha[10];
	struct nino datos;
	
	printf ("\nIngrese el numero de cedula: ");       
	fflush (stdin);
	scanf_s("%s",datos.cedula);
	printf ("\nIngrese el nombre completo: ");
	fflush (stdin);
	gets(datos.nombre);
	printf ("\nIngrese el nombre de usuario: ");
	fflush (stdin);
	gets(datos.usuario);
	printf ("\nIngrese el correo electronico: ");
	fflush (stdin);
	scanf_s("%s",datos.correo);
	printf ("\nIngrese la residencia: ");
	fflush (stdin);
	scanf_s("%s",datos.residencia);
	
	printf ("\nIngrese el dia en que nacio: ");
	scanf_s("%s",fecha);
	strcpy(datos.nacimiento,fecha);
	strcpy(datos.nacimiento,strcat(datos.nacimiento,"/"));
	printf ("\nIngrese el mes en que nacio: ");
	scanf_s("%s",fecha);
	strcpy(datos.nacimiento,strcat(datos.nacimiento,fecha));
	strcpy(datos.nacimiento,strcat(datos.nacimiento,"/"));
	printf ("\nIngrese el ano en que nacio: ");
	scanf_s("%s",fecha);
	strcpy(datos.nacimiento,strcat(datos.nacimiento,fecha));
	datos.edad= 2020 - atoi(fecha);
	printf ("\nIngrese alguna especialidad que posee el nino: ");
	fflush (stdin);
	scanf_s("%s",datos.especialidades);	
	
	registro_ninos= insertarDatos(registro_ninos,datos);
	color_aceptado();
	printf ("\nNino agregado correctamente\n\n");
	color_normal();
	fflush (stdin);
}

//Modificar datos de un nino
Lista_Doble * modificar_nino(Lista_Doble * registro_ninos,ninos * datos){
	int validar=0,validar1=0;
	char fecha[40],eleccion[40];
	
	printf ("Cedula: %s",datos->cedula);
	while (validar1==0){
		printf ("\nLo desea modificar (0-NO, 1-SI):");
		scanf_s("%s",eleccion);
		if (strcmp(eleccion,"1")==0){
				printf ("\nIngrese el numero de cedula: ");       
				fflush (stdin);
				scanf_s("%s",datos->cedula);
				validar1++;
		}
		else if (strcmp(eleccion,"0")==0){
			validar1++;
		}
		else{
			color_error();
			printf ("\nIngrese un valor valido...\n");
			color_normal();
		}
	}
	validar1=0;
	printf ("Nombre: %s",datos->nombre);
	while (validar1==0){
		printf ("\nLo desea modificar (0-NO, 1-SI):");
		scanf_s("%s",eleccion);
		if (strcmp(eleccion,"1")==0){
				printf ("\nIngrese el nombre completo: ");
				fflush (stdin);
				gets(datos->nombre);
				validar1++;
		}
		else if (strcmp(eleccion,"0")==0){
			validar1++;
		}
		else{
			color_error();
			printf ("\nIngrese un valor valido...\n");
			color_normal();
		}
	}
	fflush (stdin);	
	validar1=0;
	printf ("Correo: %s",datos->correo);
	while (validar1==0){
		printf ("\nLo desea modificar (0-NO, 1-SI):");
		scanf_s("%s",eleccion);
		if (strcmp(eleccion,"1")==0){
				printf ("\nIngrese el correo electronico: ");
				fflush (stdin);
				scanf_s("%s",datos->correo);
				validar1++;
		}
		else if (strcmp(eleccion,"0")==0){
			validar1++;
		}
		else{
			color_error();
			printf ("\nIngrese un valor valido...\n");
			color_normal();
		}
	}
	fflush (stdin);	
	validar1=0;
	printf ("Fecha: %s",datos->nacimiento);
	while (validar1==0){
		printf ("\nLo desea modificar (0-NO, 1-SI):");
		scanf_s("%s",eleccion);
		if (strcmp(eleccion,"1")==0){
			printf ("\nIngrese el dia en que nacio: ");
			scanf_s("%s",fecha);
			strcpy(datos.nacimiento,fecha);
			strcpy(datos.nacimiento,strcat(datos.nacimiento,"/"));
			printf ("\nIngrese el mes en que nacio: ");
			scanf_s("%s",fecha);
			strcpy(datos.nacimiento,strcat(datos.nacimiento,fecha));
			strcpy(datos.nacimiento,strcat(datos.nacimiento,"/"));
			printf ("\nIngrese el ano en que nacio: ");
			scanf_s("%s",fecha);
			strcpy(datos.nacimiento,strcat(datos.nacimiento,fecha));
			datos.edad= 2020 - atoi(fecha);
				validar1++;
		}
		else if (strcmp(eleccion,"0")==0){
			validar1++;
		}
		else{
			color_error();
			printf ("\nIngrese un valor valido...\n");
			color_normal();
		}
	}
	while (validar1==0){
		printf ("\nLo desea modificar (0-NO, 1-SI):");
		scanf_s("%s",eleccion);
		if (strcmp(eleccion,"1")==0){

				validar1++;
		}
		else if (strcmp(eleccion,"0")==0){
			printf ("\nIngrese alguna especialidad que posee el nino: ");
			fflush (stdin);
			scanf_s("%i",datos->especialidades);
			validar1++;
		}
		else{
			color_error();
			printf ("\nIngrese un valor valido...\n");
			color_normal();
		}
	}
	fflush (stdin);	
	color_aceptado();
	printf ("\nNino modificado correctamente\n\n");
	color_normal();
	fflush (stdin);	
}


// Seleccionar el nino a modificar
Lista_Doble * modificarLista_Doble(Lista_Doble * registro_ninos){
	int contador=1,validar=0;
	char cedula[40];
	ninos *i;
	printf("Existen los siguientes ninos en el sistema: \n\n");
	for(i = registro_ninos->inicio; i!= NULL; i = i->siguiente){          //recorrer la lista
		printf ("%i-Nombre: %s  Cedula: %s\n",contador,i->nombre,i->cedula);
		contador++;	
	}
	while (validar==0){
	printf("Ingrese la cedula del nino a modificar: ");
	scanf_s("%s",cedula);
	
	for(i = registro_ninos->inicio; i!= NULL; i = i->siguiente){        //recorrer la lista
	if (strcmp(i->cedula,cedula)==0){
		modificar_nino(registro_ninos,i);
		return registro_ninos;
	}
	}
	color_error();
	printf ("\nIngrese una cedula valida...\n\n");
	color_normal();
	}
}




/* ----------------------------------------------------------------------------------------------------------------------------*/ 
//                                  CÓDIGO PARA DUENDES
/* ----------------------------------------------------------------------------------------------------------------------------*/
 

  
// struct para crear la lista

typedef struct duende {
	char identificacion[40];               // Datos de los duendes                 
	char nombre[40];
	char puesto[40];
	char funcion[40];
	char comienzo[40];
	struct duende * siguiente;   // Putero a siguiente
	struct duende * anterior; 	// Putero a anterior
} duendes;

// Estructura de la lista doble
typedef struct Lista2
{
	int largo;           // Largo de la lista doble
	struct nino * inicio;
	struct nino * final;
} Lista_Doble2;

// Crear una nueva lista doble
Lista_Doble2 *listaNueva2(Lista_Doble2 * L)
{
	L= NULL;
	L = (Lista_Doble2 *) malloc(sizeof(Lista_Doble2));
	L->inicio = NULL;    // Poner inicio NULL
	L->final = NULL;	// Poner final NULL
	L->largo=0;			// Poner largo 0
	return L;
}

// Crear un nuevo nodo para la lista doble

duendes * nuevo_duende (struct duende datos)
{
	duendes * nuevo;
	nuevo = (duendes *) malloc(sizeof(duendes));
	nuevo->anterior = NULL;
	nuevo->siguiente = NULL;          //Copiar los datos del duende al nuevo nodo
	strcpy (nuevo->nombre,datos.nombre);
	strcpy (nuevo->identificacion,datos.identificacion);
	strcpy (nuevo->puesto,datos.puesto);
	strcpy (nuevo->comienzo,datos.comienzo);
	strcpy (nuevo->funcion,datos.funcion);
	
	return nuevo;            // retornar los datos
}

// Muestra la lista doble de derecha a izquierda
void mostrarLista_Doble_Duendes(Lista_Doble2 *Lista)
{
	duendes *i;
	printf("Existen los siguientes ninos en el sistema: \n");
	for(i = Lista->inicio; i!= NULL; i = i->siguiente)               //recorrer la lista
		printf("-Nombre: %s -Identificacion: %s -Puesto: %s -Funcion: %s\n",i->nombre,i->identificacion,i->puesto,i->funcion);   //Imprimir los datos
	printf("\n");
}

// Insertar datos en la lista doble
Lista_Doble2 * insertarDatos2(Lista_Doble2 * Lista, struct duende datos)
{
	Lista->largo=Lista->largo+1;
	if(Lista->inicio == NULL) //Valida si la lista está vacía
	{
		//Inserta al inicio de la lista
		Lista->inicio= nuevo_duende(datos);
		Lista->final = Lista->inicio;
		return Lista;
	}
	
	//Inserta el dato al final de la lista, no necesita un ciclo porque tiene el puntero final
	Lista->final->siguiente = nuevo_duende(datos);
	Lista->final->siguiente->anterior = Lista->final;
	Lista->final = Lista->final->siguiente;
}

//Insertar datos de un duende
Lista_Doble2 * nuevos_datos2(Lista_Doble2 * registro_duendes)
{
	int validar1=0;
	char fecha[10],eleccion[10];
	struct duende datos;
	
	printf ("\nIngrese el numero de identificacion: ");       
	fflush (stdin);
	scanf_s("%s",datos.identificacion);
	printf ("\nIngrese el nombre completo: ");
	fflush (stdin);
	gets(datos.nombre);
	printf ("\nSeleccione el puesto del duende: ");
	printf ("\n\n1- Elaborador de juguetes\n2- Empaquetador de juguetes\n3- Ayudante de entrega\n\n");
	while (validar1==0){
		printf ("Ingrese su eleccion: ");
		scanf_s("%s",eleccion);
		if (strcmp(eleccion,"1")==0){     
				strcpy(datos.puesto,"Elaborador de juguetes");
				while (validar1==0){
				printf ("Ingrese la funcion que desempena el duende: \n");
				printf ("\n1- Hacer juguetes para ninos\n2- Hacer juguetes para ninas\n\nIngrese su eleccion: ");
				scanf_s("%s",eleccion);
				if (strcmp(eleccion,"1")==0){
				strcpy(datos.funcion,"Hacer juguetes para ninos");
				validar1++;
				}
				else if (strcmp(eleccion,"2")==0){
				strcpy(datos.funcion,"Hacer juguetes para ninas");
				validar1++;
				}
				else{
				color_error();
				printf ("\nIngrese un valor valido...\n\n");
				color_normal();
				}
				}
		}
		else if (strcmp(eleccion,"2")==0){
			strcpy(datos.puesto,"Empaquetador de juguetes");
				while (validar1==0){
				printf ("Ingrese la funcion que desempena el duende: \n");
				printf ("\n1- Empacar juguetes pequenos\n2- Empacar juguetes grandes\n\n");
				scanf_s("%s",eleccion);
				if (strcmp(eleccion,"1")==0){
				strcpy(datos.funcion,"Empacar juguetes pequenos");
				validar1++;
				}
				else if (strcmp(eleccion,"2")==0){
				strcpy(datos.funcion,"Empacar juguetes grandes");
				validar1++;
				}
				else{
				color_error();
				printf ("\nIngrese un valor valido...\n\n");
				color_normal();
				}
				}
		}	
		else if (strcmp(eleccion,"3")==0){
			strcpy(datos.puesto,"Ayudante de entrega");
				while (validar1==0){
				printf ("Ingrese la funcion que desempena el duende: \n");
				printf ("\n1- Entregar juguetes con destinos cerca\n2- Entregar juguetes con destinos largos\n\n");
				scanf_s("%s",eleccion);
				if (strcmp(eleccion,"1")==0){
				strcpy(datos.funcion,"Entregar juguetes con destinos cerca");
				validar1++;
				}
				else if (strcmp(eleccion,"2")==0){
				strcpy(datos.funcion,"Entregar juguetes con destinos largos");
				validar1++;
				}
				else{
				color_error();
				printf ("\nIngrese un valor valido...\n\n");
				color_normal();
				}
				}
		}
		else{
			color_error();
			printf ("\nIngrese un valor valido...\n");
			color_normal();
		}
	}	
	
	printf ("\nIngrese el dia en que empezo a trabajar: ");
	scanf_s("%s",fecha);
	strcpy(datos.nacimiento,fecha);
	strcpy(datos.nacimiento,strcat(datos.comienzo,"/"));
	printf ("\nIngrese el mes en que empezo a trabajar: ");
	scanf_s("%s",fecha);
	strcpy(datos.nacimiento,strcat(datos.comienzo,fecha));
	strcpy(datos.nacimiento,strcat(datos.comienzo,"/"));
	printf ("\nIngrese el ano en que empezo a trabajar: ");
	scanf_s("%s",fecha);
	strcpy(datos.nacimiento,strcat(datos.comienzo,fecha));
	
	registro_duendes= insertarDatos2(registro_duendes,datos);
	color_aceptado();
	printf ("\nDuende agregado correctamente\n\n");
	color_normal();
	fflush (stdin);
}

//Modificar datos de un duende
Lista_Doble * modificar_duende(Lista_Doble2 * registro_duendes,duendes * datos){
	int validar=0,validar1=0;
	char fecha[40],eleccion[40];
	
	printf ("Identificacion: %s",datos->identificacion);
	while (validar1==0){
		printf ("\nLo desea modificar (0-NO, 1-SI):");
		scanf_s("%s",eleccion);
		if (strcmp(eleccion,"1")==0){
				printf ("\nIngrese el numero de identificacion: ");       
				fflush (stdin);
				scanf_s("%s",datos->identificacion);
				validar1++;
		}
		else if (strcmp(eleccion,"0")==0){
			validar1++;
		}
		else{
			color_error();
			printf ("\nIngrese un valor valido...\n");
			color_normal();
		}
	}
	validar1=0;
	printf ("Nombre: %s",datos->nombre);
	while (validar1==0){
		printf ("\nLo desea modificar (0-NO, 1-SI):");
		scanf_s("%s",eleccion);
		if (strcmp(eleccion,"1")==0){
				printf ("\nIngrese el nombre completo: ");
				fflush (stdin);
				gets(datos->nombre);
				validar1++;
		}
		else if (strcmp(eleccion,"0")==0){
			validar1++;
		}
		else{
			color_error();
			printf ("\nIngrese un valor valido...\n");
			color_normal();
		}
	}
	fflush (stdin);	
	validar1=0;
	printf ("Puesto: %s",datos->puesto);
	while (validar1==0){
		printf ("\nLo desea modificar (0-NO, 1-SI):");
		scanf_s("%s",eleccion);
		if (strcmp(eleccion,"1")==0){
			printf ("\nSeleccione el puesto del duende: ");
			printf ("\n\n1- Elaborador de juguetes\n2- Empaquetador de juguetes\n3- Ayudante de entrega\n\n");
			while (validar1==0){
				printf ("Ingrese su eleccion: ");
				scanf_s("%s",eleccion);
				if (strcmp(eleccion,"1")==0){     
					strcpy(datos.puesto,"Elaborador de juguetes");
					while (validar1==0){
						printf ("Ingrese la funcion que desempena el duende: \n");
						printf ("\n1- Hacer juguetes para ninos\n2- Hacer juguetes para ninas\n\nIngrese su eleccion: ");
						scanf_s("%s",eleccion);
						if (strcmp(eleccion,"1")==0){
							strcpy(datos.funcion,"Hacer juguetes para ninos");
							validar1++;
						}
						else if (strcmp(eleccion,"2")==0){
							strcpy(datos.funcion,"Hacer juguetes para ninas");
							validar1++;
						}
						else{
							color_error();
							printf ("\nIngrese un valor valido...\n\n");
							color_normal();
						}
					}
				}
				else if (strcmp(eleccion,"2")==0){
					strcpy(datos.puesto,"Empaquetador de juguetes");
					while (validar1==0){
						printf ("Ingrese la funcion que desempena el duende: \n");
						printf ("\n1- Empacar juguetes pequenos\n2- Empacar juguetes grandes\n\n");
						scanf_s("%s",eleccion);
						if (strcmp(eleccion,"1")==0){
							strcpy(datos.funcion,"Empacar juguetes pequenos");
							validar1++;
						}
						else if (strcmp(eleccion,"2")==0){
							strcpy(datos.funcion,"Empacar juguetes grandes");
							validar1++;
						}
						else{
							color_error();
							printf ("\nIngrese un valor valido...\n\n");
							color_normal();
						}
					}
				}	
				else if (strcmp(eleccion,"3")==0){
					strcpy(datos.puesto,"Ayudante de entrega");
					while (validar1==0){
						printf ("Ingrese la funcion que desempena el duende: \n");
						printf ("\n1- Entregar juguetes con destinos cerca\n2- Entregar juguetes con destinos largos\n\n");
						scanf_s("%s",eleccion);
						if (strcmp(eleccion,"1")==0){
							strcpy(datos.funcion,"Entregar juguetes con destinos cerca");
							validar1++;
						}
						else if (strcmp(eleccion,"2")==0){
							strcpy(datos.funcion,"Entregar juguetes con destinos largos");
							validar1++;
						}
						else{
							color_error();
							printf ("\nIngrese un valor valido...\n\n");
							color_normal();
						}
					}
				}
				else{
					color_error();
					printf ("\nIngrese un valor valido...\n");
					color_normal();
				}
		}
		}
		else if (strcmp(eleccion,"0")==0){
			validar1++;
		}
		else{
			color_error();
			printf ("\nIngrese un valor valido...\n");
			color_normal();
		}
	}
	fflush (stdin);	
	validar1=0;
	printf ("Comienzo: %s",datos->comienzo);
	while (validar1==0){
		printf ("\nLo desea modificar (0-NO, 1-SI):");
		scanf_s("%s",eleccion);
		if (strcmp(eleccion,"1")==0){
			printf ("\nIngrese el dia en que empezo a trabajar: ");
			scanf_s("%s",fecha);
			strcpy(datos.nacimiento,fecha);
			strcpy(datos.nacimiento,strcat(datos.comienzo,"/"));
			printf ("\nIngrese el mes en que empezo a trabajar: ");
			scanf_s("%s",fecha);
			strcpy(datos.nacimiento,strcat(datos.comienzo,fecha));
			strcpy(datos.nacimiento,strcat(datos.comienzo,"/"));
			printf ("\nIngrese el ano en que empezo a trabajar: ");
			scanf_s("%s",fecha);
			strcpy(datos.nacimiento,strcat(datos.comienzo,fecha));
				validar1++;
		}
		else if (strcmp(eleccion,"0")==0){
			validar1++;
		}
		else{
			color_error();
			printf ("\nIngrese un valor valido...\n");
			color_normal();
		}
	}
	fflush (stdin);	
	color_aceptado();
	printf ("\nDuende modificado correctamente\n\n");
	color_normal();
	fflush (stdin);	
}


// Seleccionar el duende a modificar
Lista_Doble * modificarLista_Doble(Lista_Doble * registro_ninos){
	int contador=1,validar=0;
	char cedula[40];
	ninos *i;
	printf("Existen los siguientes ninos en el sistema: \n\n");
	for(i = registro_ninos->inicio; i!= NULL; i = i->siguiente){          //recorrer la lista
		printf ("%i-Nombre: %s  Cedula: %s\n",contador,i->nombre,i->cedula);
		contador++;	
	}
	while (validar==0){
	printf("Ingrese la cedula del niño a modificar: ");
	scanf_s("%s",cedula);
	
	for(i = registro_ninos->inicio; i!= NULL; i = i->siguiente){          //recorrer la lista
	if (strcmp(i->cedula,cedula)==0){
		modificar_nino(registro_ninos,i);
		return registro_ninos;
	}
	}
	color_error();
	printf ("\nIngrese una cedula valida...\n\n");
	color_normal();
	}
}
 


/* ----------------------------------------------------------------------------------------------------------------------------*/ 
//                                  CÓDIGO PARA EL MENU
/* ----------------------------------------------------------------------------------------------------------------------------*/

main (){
	
	inicio();
	
	Lista_Doble * registro_ninos = listaNueva(registro_ninos);
	Lista_Doble2 * registro_duendes = listaNueva2(registro_duendes);
	int validar=0,eleccion;
	
	
	//Menu principal con las opciones	
	printf ("\n-----------BIENVENIDO A NAVITEC-----------\n\n");
	
	while (validar!=1){
		printf ("\nEstas son las opciones disponibles: \n");
		printf ("1- Agregar nino\n");
		printf ("2- Mostrar ninos registrados\n");
		printf ("3- Modificar datos de un nino\n");
		printf ("4- Agregar duende\n");
		printf ("5- Salir del sistema\n");
		
		printf ("\nElija su opcion: ");
		scanf(" %i", &eleccion);  //eleccion de la opcion a realizar 
		fflush (stdin);
		if(isalpha(eleccion) != 0){   // validacion 
			color_error();
			printf ("\n\nIngrese una opcion valida...\n\n");
			color_normal();
		}
		
		else{
		
		switch (eleccion){
			case 1:
			    nuevos_datos(registro_ninos);
				break;
			case 2:
				mostrarLista_Doble_Ninos(registro_ninos);
				break;
			case 3:
				registro_ninos=modificarLista_Doble(registro_ninos);
				break;
			case 4:
				nuevos_datos2(registro_duendes);
				break;
			case 5:
				color_aceptado();
				printf ("\nGracias por utilizar el sistema...\n");  //Salir del sistema
				color_normal(); 
				validar=1;
				break;
			default:
				color_error();
				printf ("\n\nIngrese una opcion valida...\n\n");  // Validar errores
				color_normal();
				break;
		}
		}
		eleccion= 0;
	}
	
	return 0;
}





