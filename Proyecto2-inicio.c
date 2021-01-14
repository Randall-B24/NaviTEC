# include <stdio.h>
#include <stdio.h> 
#include <conio.h>
#include <stdlib.h>
#include <Windows.h> 
#include <math.h>
#define nodo_Lugares struct nodo
#define arista_Lugares struct arista
#define Lista_Lugares struct pila



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
			strcpy(datos->nacimiento,fecha);
			strcpy(datos->nacimiento,strcat(datos->nacimiento,"/"));
			printf ("\nIngrese el mes en que nacio: ");
			scanf_s("%s",fecha);
			strcpy(datos->nacimiento,strcat(datos->nacimiento,fecha));
			strcpy(datos->nacimiento,strcat(datos->nacimiento,"/"));
			printf ("\nIngrese el ano en que nacio: ");
			scanf_s("%s",fecha);
			strcpy(datos->nacimiento,strcat(datos->nacimiento,fecha));
			datos->edad= 2020 - atoi(fecha);
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


// Eliminar por identificacion

Lista_Doble * eliminar_ninos_identificacion (Lista_Doble * L,char identificacion[]){
	ninos *i;
	struct nino datos;
	Lista_Doble *L2= listaNueva(L2);
	for(i = L->inicio; i!= NULL; i = i->siguiente){
	if (strcmp(i->cedula,identificacion)!=0){
		strcpy(datos.cedula,i->cedula);
		strcpy(datos.correo,i->correo);
		strcpy(datos.especialidades,i->especialidades);
		strcpy(datos.nombre,i->nombre);
		strcpy(datos.residencia,i->residencia);
		strcpy(datos.usuario,i->usuario);
		datos.edad=i->edad;
		L2= insertarDatos(L2,datos);
	}
	}
	return L2;
}

// Seleccionar el nino a eliminar
Lista_Doble * EliminarLista_Doble(Lista_Doble * registro_ninos){
	int contador=1,validar=0;
	char identificacion[40];
	ninos *i;
	printf("Existen los siguientes ninos en el sistema: \n\n");
	for(i = registro_ninos->inicio; i!= NULL; i = i->siguiente){          //recorrer la lista
		printf ("%i-Nombre: %s \n",contador,i->cedula);
		contador++;	
	}
	while (validar==0){
	printf("Ingrese la identificacion del nino a eliminar: ");
	scanf_s("%s",identificacion);
	
	for(i = registro_ninos->inicio; i!= NULL; i = i->siguiente){          //recorrer la lista
	if (strcmp(i->cedula,identificacion)==0){
		registro_ninos= eliminar_ninos_identificacion (registro_ninos,identificacion);
		color_aceptado();
		printf ("\nNino eliminado correctamente...\n\n");
		color_normal();
		return registro_ninos;
	}
	}
	color_error();
	printf ("\nIngrese una identificacion valida...\n\n");
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
	struct duende * inicio;
	struct duende * final;
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
	printf("Existen los siguientes duendes en el sistema: \n");
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
				printf ("\n1- Empacar juguetes pequenos\n2- Empacar juguetes grandes\n\nIngrese su eleccion: ");
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
				printf ("\n1- Entregar juguetes con destinos cerca\n2- Entregar juguetes con destinos largos\n\nIngrese su eleccion: ");
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
	strcpy(datos.comienzo,fecha);
	strcpy(datos.comienzo,strcat(datos.comienzo,"/"));
	printf ("\nIngrese el mes en que empezo a trabajar: ");
	scanf_s("%s",fecha);
	strcpy(datos.comienzo,strcat(datos.comienzo,fecha));
	strcpy(datos.comienzo,strcat(datos.comienzo,"/"));
	printf ("\nIngrese el ano en que empezo a trabajar: ");
	scanf_s("%s",fecha);
	strcpy(datos.comienzo,strcat(datos.comienzo,fecha));
	
	registro_duendes= insertarDatos2(registro_duendes,datos);
	color_aceptado();
	printf ("\nDuende agregado correctamente\n\n");
	color_normal();
	fflush (stdin);
}

//Modificar datos de un duende
Lista_Doble2 * modificar_duende(Lista_Doble2 * registro_duendes,duendes * datos){
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
					strcpy(datos->puesto,"Elaborador de juguetes");
					while (validar1==0){
						printf ("Ingrese la funcion que desempena el duende: \n");
						printf ("\n1- Hacer juguetes para ninos\n2- Hacer juguetes para ninas\n\nIngrese su eleccion: ");
						scanf_s("%s",eleccion);
						if (strcmp(eleccion,"1")==0){
							strcpy(datos->funcion,"Hacer juguetes para ninos");
							validar1++;
						}
						else if (strcmp(eleccion,"2")==0){
							strcpy(datos->funcion,"Hacer juguetes para ninas");
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
					strcpy(datos->puesto,"Empaquetador de juguetes");
					while (validar1==0){
						printf ("Ingrese la funcion que desempena el duende: \n");
						printf ("\n1- Empacar juguetes pequenos\n2- Empacar juguetes grandes\n\nIngrese su eleccion: ");
						scanf_s("%s",eleccion);
						if (strcmp(eleccion,"1")==0){
							strcpy(datos->funcion,"Empacar juguetes pequenos");
							validar1++;
						}
						else if (strcmp(eleccion,"2")==0){
							strcpy(datos->funcion,"Empacar juguetes grandes");
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
					strcpy(datos->puesto,"Ayudante de entrega");
					while (validar1==0){
						printf ("Ingrese la funcion que desempena el duende: \n");
						printf ("\n1- Entregar juguetes con destinos cerca\n2- Entregar juguetes con destinos largos\n\nIngrese su eleccion: ");
						scanf_s("%s",eleccion);
						if (strcmp(eleccion,"1")==0){
							strcpy(datos->funcion,"Entregar juguetes con destinos cerca");
							validar1++;
						}
						else if (strcmp(eleccion,"2")==0){
							strcpy(datos->funcion,"Entregar juguetes con destinos largos");
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
			strcpy(datos->comienzo,fecha);
			strcpy(datos->comienzo,strcat(datos->comienzo,"/"));
			printf ("\nIngrese el mes en que empezo a trabajar: ");
			scanf_s("%s",fecha);
			strcpy(datos->comienzo,strcat(datos->comienzo,fecha));
			strcpy(datos->comienzo,strcat(datos->comienzo,"/"));
			printf ("\nIngrese el ano en que empezo a trabajar: ");
			scanf_s("%s",fecha);
			strcpy(datos->comienzo,strcat(datos->comienzo,fecha));
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
Lista_Doble2 * modificarLista_Doble2(Lista_Doble2 * registro_duendes){
	int contador=1,validar=0;
	char identificacion[40];
	duendes *i;
	printf("Existen los siguientes duendes en el sistema: \n\n");
	for(i = registro_duendes->inicio; i!= NULL; i = i->siguiente){          //recorrer la lista
		printf ("%i-Nombre: %s  Identificacion: %s\n",contador,i->nombre,i->identificacion);
		contador++;	
	}
	while (validar==0){
	printf("Ingrese la identificacion del duende a modificar: ");
	scanf_s("%s",identificacion);
	
	for(i = registro_duendes->inicio; i!= NULL; i = i->siguiente){          //recorrer la lista
	if (strcmp(i->identificacion,identificacion)==0){
		modificar_duende(registro_duendes,i);
		return registro_duendes;
	}
	}
	color_error();
	printf ("\nIngrese una identificacion valida...\n\n");
	color_normal();
	}
}


// Eliminar por identificacion

Lista_Doble2 * eliminar_duendes_identificacion (Lista_Doble2 * L,char identificacion[]){
	duendes *i;
	struct duende datos;
	Lista_Doble2 *L2= listaNueva2(L2);
	for(i = L->inicio; i!= NULL; i = i->siguiente){
	if (strcmp(i->identificacion,identificacion)!=0){
		strcpy(datos.comienzo,i->comienzo);
		strcpy(datos.funcion,i->funcion);
		strcpy(datos.identificacion,i->identificacion);
		strcpy(datos.nombre,i->nombre);
		strcpy(datos.puesto,i->puesto);
		L2= insertarDatos2(L2,datos);
	}
	}
	return L2;
}

// Seleccionar el duende a eliminar
Lista_Doble2 * EliminarLista_Doble2(Lista_Doble2 * registro_duendes){
	int contador=1,validar=0;
	char identificacion[40];
	duendes *i;
	printf("Existen los siguientes duendes en el sistema: \n\n");
	for(i = registro_duendes->inicio; i!= NULL; i = i->siguiente){          //recorrer la lista
		printf ("%i-Nombre: %s \n",contador,i->identificacion);
		contador++;	
	}
	while (validar==0){
	printf("Ingrese la identificacion del duende a eliminar: ");
	scanf_s("%s",identificacion);
	
	for(i = registro_duendes->inicio; i!= NULL; i = i->siguiente){          //recorrer la lista
	if (strcmp(i->identificacion,identificacion)==0){
		registro_duendes= eliminar_duendes_identificacion (registro_duendes,identificacion);
		color_aceptado();
		printf ("\nDuende eliminado correctamente...\n\n");
		color_normal();
		return registro_duendes;
	}
	}
	color_error();
	printf ("\nIngrese una identificacion valida...\n\n");
	color_normal();
	}
}



/* ----------------------------------------------------------------------------------------------------------------------------*/ 
//                                  CÓDIGO PARA LOS JUGUETES
/* ----------------------------------------------------------------------------------------------------------------------------*/



/* ----------------------------------------------------------------------------------------------------------------------------*/ 
//                                  CÓDIGO PARA LOS JUGUETES... ARBOL DE CODIGOS
/* ----------------------------------------------------------------------------------------------------------------------------*/


// Codigo para juguetes

int valor_a=5;
int valor_b=0;
int valor_c=0;
int pasar=0;




/* Estructuras y tipos */
typedef struct _nodo {
   int codigo;
   struct _nodo *derecho;
   struct _nodo *izquierdo;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Arbol;


/* Insertar un dato en el árbol ABB */
void Insertar(Arbol *a, int dat)
{
   pNodo padre = NULL;
   pNodo actual = *a;

   /* Buscar el dato en el árbol, manteniendo un puntero al nodo padre */
   while(!Vacio(actual) && dat != actual->codigo) {
      padre = actual;
      if(dat < actual->codigo) actual = actual->izquierdo;
      else if(dat > actual->codigo) actual = actual->derecho;
   }

   /* Si se ha encontrado el elemento, regresar sin insertar */
   if(!Vacio(actual)) return;
   /* Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
      el nodo raiz */
   if(Vacio(padre)) {
      *a = (Arbol)malloc(sizeof(tipoNodo));
      (*a)->codigo = dat;
      (*a)->izquierdo = (*a)->derecho = NULL;
   }
   /* Si el dato es menor que el que contiene el nodo padre, lo insertamos
      en la rama izquierda */
   else if(dat < padre->codigo) {
      actual = (Arbol)malloc(sizeof(tipoNodo));
      padre->izquierdo = actual;
      actual->codigo = dat;
      actual->izquierdo = actual->derecho = NULL;
   }
   /* Si el dato es mayor que el que contiene el nodo padre, lo insertamos
      en la rama derecha */
   else if(dat > padre->codigo) {
      actual = (Arbol)malloc(sizeof(tipoNodo));
      padre->derecho = actual;
      actual->codigo = dat;
      actual->izquierdo = actual->derecho = NULL;
  }
}

/* Eliminar un elemento de un árbol ABB */
void Borrar(Arbol *a, int dat)
{
   pNodo padre = NULL;
   pNodo actual;
   pNodo nodo;
   int aux;

   actual = *a;
   /* Mientras sea posible que el valor esté en el árbol */
   while(!Vacio(actual)) {
      if(dat == actual->codigo) { /* Si el valor está en el nodo actual */
         if(EsHoja(actual)) { /* Y si además es un nodo hoja: lo borramos */
            if(padre) /* Si tiene padre (no es el nodo raiz) */
               /* Anulamos el puntero que le hace referencia */
               if(padre->derecho == actual) padre->derecho = NULL;
               else if(padre->izquierdo == actual) padre->izquierdo = NULL;
            free(actual); /* Borrar el nodo */
            actual = NULL;
            return;
         }
         else { /* Si el valor está en el nodo actual, pero no es hoja */
            padre = actual;
            /* Buscar nodo más izquierdo de rama derecha */
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;
               }
            }
            /* O buscar nodo más derecho de rama izquierda */
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            }
            /* Intercambiar valores de no a borrar u nodo encontrado
               y continuar, cerrando el bucle. El nodo encontrado no tiene
               por qué ser un nodo hoja, cerrando el bucle nos aseguramos
               de que sólo se eliminan nodos hoja. */
            aux = actual->codigo;
            actual->codigo = nodo->codigo;
            nodo->codigo = aux;
            actual = nodo;
         }
      }
      else { /* Todavía no hemos encontrado el valor, seguir buscándolo */
         padre = actual;
         if(dat > actual->codigo) actual = actual->derecho;
         else if(dat < actual->codigo) actual = actual->izquierdo;
      }
   }
}

/* Comprobar si un árbol es vacío */
int Vacio(Arbol r)
{
   return r==NULL;
}

/* Comprobar si un nodo es hoja */
int EsHoja(pNodo r)
{
   return !r->derecho && !r->izquierdo;
}

/* Función de prueba para recorridos del árbol */
void Mostrar(int *d)
{
   printf("%d, ", *d);
}


/* Recorrido de árbol en inorden, aplicamos la función func, que tiene
   el prototipo:
   void func(int*);
*/
void InOrden(Arbol a, void (*func)(int*))
{
   if(a->izquierdo) InOrden(a->izquierdo, func);
   func(&(a->codigo));
   if(a->derecho) InOrden(a->derecho, func);
}


// Función sacar prioridad2 de las aignaciones
int sacar_codigo(){
	int valor;
	
	if (pasar==0){
		valor=valor_a;
		valor_a+=5;
		pasar++;
		}
	else if (pasar==1){
		valor= 3 * pow(2,valor_b);
		valor_b++;
		pasar++;
		}
	else{
		valor= 2 * pow(2,valor_c);
		valor_c++;
		pasar=0;
		}
    
    return valor;  // retornar valor 
}




/* ----------------------------------------------------------------------------------------------------------------------------*/ 
//                                  CÓDIGO PARA LOS JUGUETES... LISTA DE DATOS
/* ----------------------------------------------------------------------------------------------------------------------------*/

// Estructura de los nodos
typedef struct juguete {
    int codigo;
    char nombre[40];
    char descripcion[40];
    char categoria[40];
    int edadmenor;
    int edadmayor;
    int costo;
    struct juguete * siguiente;
    struct juguete * anterior;
}Juguetes;


// Estructura de la lista doble
typedef struct Lista3
{
	int largo;           // Largo de la lista doble
	struct juguete * inicio;
	struct juguete * final;
} Lista_Doble3;


// Crear una nueva lista doble
Lista_Doble3 *listaNueva3(Lista_Doble3 * L)
{
	L= NULL;
	L = (Lista_Doble3 *) malloc(sizeof(Lista_Doble3));
	L->inicio = NULL;    // Poner inicio NULL
	L->final = NULL;	// Poner final NULL
	L->largo=0;			// Poner largo 0
	return L;
}

// Crear un nuevo nodo para la lista doble

Juguetes * nuevo_juguete (struct juguete datos)
{
	Juguetes * nuevo;
	nuevo = (Juguetes *) malloc(sizeof(Juguetes));
    nuevo->codigo= datos.codigo;
    strcpy(nuevo->nombre,datos.nombre);
    strcpy(nuevo->descripcion,datos.descripcion);
    strcpy(nuevo->categoria,datos.categoria);
    nuevo->edadmenor= datos.edadmenor;
    nuevo->edadmayor=datos.edadmayor;
    nuevo->costo=datos.costo;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
	
	return nuevo;            // retornar los datos
}

// Muestra la lista doble de derecha a izquierda
void mostrarLista_Doble_Juguetes(Lista_Doble3 *Lista)
{
	Juguetes *i;
	printf("Existen los siguientes juguetes en el sistema: \n");
	for(i = Lista->inicio; i!= NULL; i = i->siguiente)               //recorrer la lista
		printf("-Nombre: %s -Codigo: %i -Categoria: %s\n",i->nombre,i->codigo,i->categoria);   //Imprimir los datos
	printf("\n");
}

// Muestra la lista doble de derecha a izquierda
void mostrarLista_Doble_Juguetes2(Lista_Doble3 *Lista)
{
	Juguetes *i;
	int contador=1;
	printf("Existen los siguientes juguetes en el sistema: \n");
	for(i = Lista->inicio; i!= NULL; i = i->siguiente){               //recorrer la lista
		printf("%i-Nombre: %s \n",contador,i->nombre); //Imprimir los datos
		contador++;  
	}
	printf("\n");
}



// Insertar datos en la lista doble
Lista_Doble3 * insertarDatos3(Lista_Doble3 * Lista, struct juguete datos)
{
	Lista->largo=Lista->largo+1;
	if(Lista->inicio == NULL) //Valida si la lista está vacía
	{
		//Inserta al inicio de la lista
		Lista->inicio= nuevo_juguete(datos);
		Lista->final = Lista->inicio;
		return Lista;
	}
	
	//Inserta el dato al final de la lista, no necesita un ciclo porque tiene el puntero final
	Lista->final->siguiente = nuevo_juguete(datos);
	Lista->final->siguiente->anterior = Lista->final;
	Lista->final = Lista->final->siguiente;
}

//Insertar datos de un juguete
Lista_Doble3 * nuevos_datos3(Lista_Doble3 * registro_juguetes, int codigo_juguetes)
{
	int validar=0;
	char term;
	struct juguete datos;
	
	datos.codigo= codigo_juguetes;
	printf ("\nIngrese el nombre del juguete: ");
	fflush (stdin);
	gets(datos.nombre);
	fflush (stdin);
	printf ("\nIngrese la descripcion del juguete: ");
	gets(datos.descripcion);
	fflush (stdin);
	printf ("\nIngrese la categoria del juguete: ");
	gets(datos.categoria);
	fflush (stdin);
	printf ("\nIngrese el rango de edad adecuado para el juguete: ");
	while (validar==0){
		printf ("\nIngrese la edad minima: ");
		fflush (stdin);
		if(scanf("%d%c", &datos.edadmenor, &term) != 2 || term !='\n'){
			color_error();
        	printf("\nIngrese un valor valido...\n");
        	color_normal();    	
    	}
    	else{
    		validar++;
    		}
	}
	validar=0;
	while (validar==0){
		printf ("\nIngrese la edad maxima: ");
		fflush (stdin);
		if(scanf("%d%c", &datos.edadmayor, &term) != 2 || term != '\n'){
    		color_error();
        	printf("\nIngrese un valor valido...\n");
        	color_normal();
    	}
    	else{
			if (datos.edadmayor==0){
    		color_error();
        	printf("\nIngrese un valor valido...\n");
        	color_normal();				
			}
			else{
    		validar++;
    		}
    		}
	}
	validar=0;
	while (validar==0){
		printf ("\nIngrese el costo del juguete: ");
		fflush (stdin);
		if(scanf("%d%c", &datos.costo, &term) != 2 || term != '\n'){
    		color_error();
        	printf("\nIngrese un valor valido...\n");
        	color_normal();
    	}
    	else{
			if (datos.costo==0){
    		color_error();
        	printf("\nIngrese un valor valido...\n");
        	color_normal();				
			}
			else{
    		printf("El costo es: %d",datos.costo);
    		validar++;
    		}
    		}
	}
	registro_juguetes= insertarDatos3(registro_juguetes,datos);
	color_aceptado();
	printf ("\nJuguete agregado correctamente...\n\n");
	color_normal();
	fflush(stdin);
}

// Eliminar por nombre

Lista_Doble3 * eliminar_juguetes_nombre (Lista_Doble3 * L,int codigo){
	Juguetes *i;
	struct juguete datos;
	Lista_Doble3 *L2= listaNueva3(L2);
	for(i = L->inicio; i!= NULL; i = i->siguiente){
	if (i->codigo!=codigo){
		datos.codigo= i->codigo;
		strcpy(datos.categoria,i->categoria);
		datos.costo=i->costo;
		datos.edadmayor=i->edadmayor;
		datos.edadmenor=i->edadmenor;
		strcpy(datos.descripcion,i->descripcion);
		strcpy(datos.nombre,i->nombre);
		L2= insertarDatos3(L2,datos);
	}
	}
	return L2;
}

// Seleccionar el juguete a eliminar
Lista_Doble3 * EliminarLista_Doble3(Lista_Doble3 * registro_juguetes, int * codigo_juguete_aux,Arbol *registro_codigos_juguetes){
	int contador=1,validar=0, dato;
	char nombre[40];
	Juguetes *i;
	printf("Existen los siguientes juguetes en el sistema: \n\n");
	for(i = registro_juguetes->inicio; i!= NULL; i = i->siguiente){          //recorrer la lista
		printf ("%i-Nombre: %s \n",contador,i->nombre);
		contador++;	
	}
	while (validar==0){
	printf("Ingrese el nombre del juguete a eliminar: ");
	scanf_s("%s",nombre);
	
	for(i = registro_juguetes->inicio; i!= NULL; i = i->siguiente){          //recorrer la lista
	if (strcmp(i->nombre,nombre)==0){
		codigo_juguete_aux=i->codigo;
		printf ("....................%i..............",	codigo_juguete_aux);
		Borrar(&registro_codigos_juguetes,codigo_juguete_aux);
		registro_juguetes=eliminar_juguetes_nombre (registro_juguetes,i->codigo);
		color_aceptado();
		printf ("\nJuguete eliminado correctamente...\n\n");
		color_normal();
		return registro_juguetes;
	}
	}
	color_error();
	printf ("\nIngrese una identificacion valida...\n\n");
	color_normal();
	}
}



//Modificar datos de un juguete
Lista_Doble3 * modificar_juguete(Lista_Doble3 * registro_juguetes,Juguetes * datos){
	int validar=0,validar1=0;
	char eleccion[40];
	char term;
	
	printf ("Nombre: %s",datos->nombre);
	while (validar1==0){
		printf ("\nLo desea modificar (0-NO, 1-SI):");
		scanf_s("%s",eleccion);
		if (strcmp(eleccion,"1")==0){
				printf ("\nIngrese el nombre: ");       
				fflush (stdin);
				scanf_s("%s",datos->nombre);
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
	printf ("Descripcion: %s",datos->descripcion);
	while (validar1==0){
		printf ("\nLo desea modificar (0-NO, 1-SI):");
		scanf_s("%s",eleccion);
		if (strcmp(eleccion,"1")==0){
				printf ("\nIngrese la descripcion: ");
				fflush (stdin);
				gets(datos->descripcion);
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
	printf ("Categoria: %s",datos->categoria);
	while (validar1==0){
		printf ("\nLo desea modificar (0-NO, 1-SI):");
		scanf_s("%s",eleccion);
		if (strcmp(eleccion,"1")==0){
				printf ("\nIngrese la categoria: ");
				fflush (stdin);
				gets(datos->categoria);
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
	printf ("Edad minima: %i",datos->edadmenor);
	while (validar1==0){
		printf ("\nLo desea modificar (0-NO, 1-SI):");
		scanf_s("%s",eleccion);
		if (strcmp(eleccion,"1")==0){
			while (validar==0){
				printf ("\nIngrese la edad minima: ");
				fflush (stdin);
				if(scanf("%d%c", &datos->edadmenor, &term) != 2 || term != '\n'){
    				color_error();
        			printf("\nIngrese un valor valido...\n");
        			color_normal();
    			}
    			else{
					if (datos->edadmayor==0){
    					color_error();
        				printf("\nIngrese un valor valido...\n");
        				color_normal();				
					}
					else{
    				validar++;
    				validar1++;
    				}
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
	validar=0;
	
	printf ("Edad maxima: %i",datos->edadmayor);
	while (validar1==0){
		printf ("\nLo desea modificar (0-NO, 1-SI):");
		scanf_s("%s",eleccion);
		if (strcmp(eleccion,"1")==0){
			while (validar==0){
				printf ("\nIngrese la edad maxima: ");
				fflush (stdin);
				if(scanf("%d%c", &datos->edadmayor, &term) != 2 || term != '\n'){
    				color_error();
        			printf("\nIngrese un valor valido...\n");
        			color_normal();
    			}
    			else{
					if (datos->edadmayor==0){
    					color_error();
        				printf("\nIngrese un valor valido...\n");
        				color_normal();				
					}
					else{
    				validar++;
    				validar1++;
    				}
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
	validar=0;
	printf ("Costo: %i",datos->costo);
	while (validar1==0){
		printf ("\nLo desea modificar (0-NO, 1-SI):");
		scanf_s("%s",eleccion);
		if (strcmp(eleccion,"1")==0){
			while (validar==0){
				printf ("\nIngrese el costo: ");
				fflush (stdin);
				if(scanf("%d%c", &datos->costo, &term) != 2 || term != '\n'){
    				color_error();
        			printf("\nIngrese un valor valido...\n");
        			color_normal();
    			}
    			else{
					if (datos->costo==0){
    					color_error();
        				printf("\nIngrese un valor valido...\n");
        				color_normal();				
					}
					else{
    				validar++;
    				validar1++;
    				}
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
	color_aceptado();
	printf ("\nJuguete modificado correctamente\n\n");
	color_normal();
	fflush (stdin);	
}


// Seleccionar el juguete a modificar
Lista_Doble3 * modificarLista_Doble3(Lista_Doble3 * registro_juguetes){
	int contador=1,validar=0;
	char nombre[40];
	Juguetes *i;
	printf("Existen los siguientes juguetes en el sistema: \n\n");
	for(i = registro_juguetes->inicio; i!= NULL; i = i->siguiente){          //recorrer la lista
		printf ("%i-Nombre: %s  Codigo: %i\n",contador,i->nombre,i->codigo);
		contador++;	
	}
	while (validar==0){
	printf("Ingrese el nombre del duende a modificar: ");
	scanf_s("%s",nombre);
	
	for(i = registro_juguetes->inicio; i!= NULL; i = i->siguiente){          //recorrer la lista
	if (strcmp(i->nombre,nombre)==0){
		modificar_juguete(registro_juguetes,i);
		return registro_juguetes;
	}
	}
	color_error();
	printf ("\nIngrese un nombre valido...\n\n");
	color_normal();
	}
}


/* ----------------------------------------------------------------------------------------------------------------------------*/ 
//                                  CÓDIGO PARA LUGARES
/* ----------------------------------------------------------------------------------------------------------------------------*/


nodo_Lugares{
	char nombre[40];
	int codigo;
	int codigo_postal;
	
	
	nodo_Lugares* siguiente;
	arista_Lugares* adyacencia; 
	int visitado,terminado;
	char anterior;
	int monto;
};

arista_Lugares{
	nodo_Lugares*vrt; 
	arista_Lugares*siguiente;
	
	int km;
	float tiempo;
	char ruta[40];
};

Lista_Lugares{
	nodo_Lugares* dato;
	Lista_Lugares*siguiente;
};


nodo_Lugares * inicio2=NULL;
Lista_Lugares * ini=NULL;
Lista_Lugares * final=NULL;
int codigos=1;
int codigos_postal=100; 

void insertarNodo(){
    nodo_Lugares * aux;
	nodo_Lugares * nuevo=(nodo_Lugares*)malloc(sizeof(nodo_Lugares));
	fflush(stdin);
	printf("Ingrese el nombre del lugar:");
	fflush(stdin);
	gets(nuevo->nombre);
	nuevo->codigo= codigos;
	codigos++;
	nuevo->codigo_postal=codigos_postal;
	codigos_postal++;  
	nuevo->siguiente=NULL;
    nuevo->adyacencia=NULL;
    nuevo->visitado=nuevo->terminado=0;
    nuevo->monto=-1;
    nuevo->anterior=0;
    if(inicio2==NULL){
        inicio2=nuevo;
    }else{
        aux=inicio2;
        while(aux->siguiente!=NULL){
            aux=aux->siguiente;
        }
        aux->siguiente=nuevo;
      }
 
 }
 
 
 void agregarArista(nodo_Lugares * aux,nodo_Lugares * aux2,arista_Lugares * nuevo){
    arista_Lugares* a;
    if(aux->adyacencia==NULL){   
	    aux->adyacencia=nuevo;
        nuevo->vrt=aux2;
    }else{   
	    a=aux->adyacencia;
        while(a->siguiente!=NULL)
            a=a->siguiente;
        nuevo->vrt=aux2;
        a->siguiente=nuevo;
    }
}
 
 
 void insertarArista(){   
    char ini[40], fin[40],eleccion[40];
    int validar=0;
    arista_Lugares * nuevo=(arista_Lugares*)malloc(sizeof(arista_Lugares));
    nuevo->siguiente=NULL;
    nodo_Lugares * aux;
	nodo_Lugares * aux2;
    if(inicio==NULL){
    	 color_error();
         printf("Error: El grafo está vacio\n");
         color_normal();
         return;
    }
    fflush(stdin);
    printf("Ingrese el nodo Inicial:");
    fflush(stdin);
    gets(ini);
    printf("Ingrese el nodo Final:");
    fflush(stdin);
    gets(fin);
    printf("Ingrese los kilometros que existen:");
    scanf("%i",&nuevo->km);
    while (validar==0){
    	printf("Seleccione el tipo de ruta: \n1-Terrestre\n2-Maritima\n3-Aerea\n\nEleccion: ");
    	fflush(stdin);
    	gets(eleccion);
    	if (strcmp(eleccion,"1")==0){
    		strcpy(nuevo->ruta,"Terrestre");
    		validar++;
		}
		else if (strcmp(eleccion,"2")==0){
			strcpy(nuevo->ruta,"Maritima");
			validar++;
		}
		else if (strcmp(eleccion,"3")==0){
			strcpy(nuevo->ruta,"Aerea");
			validar++;
		}
		else{
			color_error();
			printf ("\nIngrese un valor valido...\n");
			color_normal();
		}
	}	
    printf("Ingrese el tiempo promedio de duracion:");
    scanf("%f",&nuevo->tiempo);    
    aux=inicio2;
    aux2=inicio2;
    while(aux2!=NULL){
        if(strcmp(aux2->nombre,fin)==0){
            break;
        }
        aux2=aux2->siguiente;
    }
    if(aux2==NULL){
    	printf("Error:Vertice no encontrado\n");
    	return;
	}
    while(aux!=NULL){


        if(strcmp(aux->nombre,ini)==0){
            agregarArista(aux,aux2,nuevo);
            return;
        }
        aux = aux->siguiente;
    }
    if(aux==NULL)
    	printf("Error:Vertice no encontrado\n");
}


void visualizarGrafo(){
    nodo_Lugares * aux=inicio2;
    arista_Lugares *ar;
    printf("Lugares: \n");
    while(aux!=NULL){   
	    printf("%s",aux->nombre);
        if(aux->adyacencia!=NULL){
            ar=aux->adyacencia;
            while(ar!=NULL){ 
			    printf(" --->%s",ar->vrt->nombre);
                ar=ar->siguiente;
            }
        }
        printf("\n");
        aux=aux->siguiente;
    }
    printf("\n");
}



/* ----------------------------------------------------------------------------------------------------------------------------*/ 
//                                  CÓDIGO PARA COMPORTAMIENTOS
/* ----------------------------------------------------------------------------------------------------------------------------*/


// struct para crear la lista

typedef struct comportamiento {
	char identificacion[40];               // Datos de los duendes                 
	char nombre[40];
	char descripcion[40];
	char tipo[40];
	char fecha[40];
	struct comportamiento * siguiente;   // Putero a siguiente
	struct comportamiento * anterior; 	// Putero a anterior
} comportamientos;


// Estructura de la lista doble
typedef struct Lista4
{
	int largo;           // Largo de la lista doble
	struct comportamiento * inicio;
	struct comportamiento * final;
} Lista_Doble4;

// Crear una nueva lista doble
Lista_Doble4 *listaNueva4(Lista_Doble4 * L)
{
	L= NULL;
	L = (Lista_Doble4 *) malloc(sizeof(Lista_Doble4));
	L->inicio = NULL;    // Poner inicio NULL
	L->final = NULL;	// Poner final NULL
	L->largo=0;			// Poner largo 0
	return L;
}

// Crear un nuevo nodo para la lista doble

comportamientos * nuevo_comportamiento (struct comportamiento datos)
{
	comportamientos * nuevo;
	nuevo = (comportamientos *) malloc(sizeof(comportamientos));
	nuevo->anterior = NULL;
	nuevo->siguiente = NULL;          //Copiar los datos del duende al nuevo nodo
	strcpy (nuevo->nombre,datos.nombre);
	strcpy (nuevo->identificacion,datos.identificacion);
	strcpy (nuevo->tipo,datos.tipo);
	strcpy (nuevo->fecha,datos.fecha);
	strcpy (nuevo->descripcion,datos.descripcion);
	
	return nuevo;            // retornar los datos
}

// Muestra la lista doble de derecha a izquierda
void mostrarLista_Doble_Comportamientos(Lista_Doble4 *Lista)
{
	comportamientos *i;
	printf("Existen los siguientes comportamientos en el sistema: \n");
	for(i = Lista->inicio; i!= NULL; i = i->siguiente)               //recorrer la lista
		printf("-Nombre: %s -Identificacion: %s -Tipo: %s -Fecha: %s\n",i->nombre,i->identificacion,i->tipo,i->fecha);   //Imprimir los datos
	printf("\n");
}

// Insertar datos en la lista doble
Lista_Doble4 * insertarDatos4(Lista_Doble4 * Lista, struct comportamiento datos)
{
	Lista->largo=Lista->largo+1;
	if(Lista->inicio == NULL) //Valida si la lista está vacía
	{
		//Inserta al inicio de la lista
		Lista->inicio= nuevo_comportamiento(datos);
		Lista->final = Lista->inicio;
		return Lista;
	}
	
	//Inserta el dato al final de la lista, no necesita un ciclo porque tiene el puntero final
	Lista->final->siguiente = nuevo_comportamiento(datos);
	Lista->final->siguiente->anterior = Lista->final;
	Lista->final = Lista->final->siguiente;
}


void seleccion_identificacion(Lista_Doble * registro_ninos,char * eleccion){
	int contador=1,validar=0,dato;
	ninos *i;
	printf ("Existen las siguientes identificaciones: \n\n");
	for(i = registro_ninos->inicio; i!= NULL; i = i->siguiente)               //recorrer la lista
		printf("%i-Identificacion: %s\n",contador,i->cedula);
	while (validar==0){
		printf ("Ingrese su eleccion: ");
		scanf("%i",&dato);
		contador==1
		for(i = registro_ninos->inicio; i!= NULL; i = i->siguiente){
			if (dato==contador){
				strcpy(eleccion,i->cedula);
				return ;
			}
			else{
				contador++;
			}
		}
		color_error();
		printf ("\n\nIngrese un valor valido...\n");
		color_normal();
	}	
}

//Insertar datos de un comportamiento
Lista_Doble4 * nuevos_datos4(Lista_Doble4 * registro_comportamientos,Lista_Doble * registro_ninos)
{
	int validar1=0;
	char fecha[10],eleccion[10];
	struct comportamiento datos;
	
	printf ("\nIngrese el nombre del padre: ");       
	fflush (stdin);
	scanf_s("%s",datos.nombre);
	seleccion_identificacion(registro_ninos,&datos.identificacion);
		
	printf ("\nIngrese el dia en que se realizo el registro del comportamiento: ");
	scanf_s("%s",fecha);
	strcpy(datos.fecha,fecha);
	strcpy(datos.fecha,strcat(datos.fecha,"/"));
	printf ("\nIngrese el mes en que se realizo el registro del comportamiento: ");
	scanf_s("%s",fecha);
	strcpy(datos.fecha,strcat(datos.fecha,fecha));
	strcpy(datos.fecha,strcat(datos.fecha,"/"));
	printf ("\nIngrese el ano en que se realizo el registro del comportamiento: ");
	scanf_s("%s",fecha);
	strcpy(datos.fecha,strcat(datos.fecha,fecha));
	registro_comportamientos= insertarDatos4(registro_comportamientos,datos);
	color_aceptado();
	printf ("\nComportamiento agregado correctamente\n\n");
	color_normal();
	fflush (stdin);
}




/* ----------------------------------------------------------------------------------------------------------------------------*/ 
//                                  CÓDIGO PARA EL MENU
/* ----------------------------------------------------------------------------------------------------------------------------*/

main (){
	
	inicio();
	
	Lista_Doble * registro_ninos = listaNueva(registro_ninos);
	Lista_Doble2 * registro_duendes = listaNueva2(registro_duendes);
	Lista_Doble3 * registro_juguetes = listaNueva3(registro_juguetes);
	Lista_Doble4 * registro_comportamientos = listaNueva4(registro_comportamientos);
	Arbol registro_codigos_juguetes=NULL;
	int validar=0,eleccion,codigo_juguete_aux;
	
	
	//Menu principal con las opciones	
	printf ("\n-----------BIENVENIDO A NAVITEC-----------\n\n");
	
	while (validar!=1){
		printf ("\nEstas son las opciones disponibles: \n");
		printf ("1- Agregar nino\n");
		printf ("2- Mostrar ninos registrados\n");
		printf ("3- Modificar datos de un nino\n");
		printf ("4- Eliminar nino\n");
		printf ("5- Agregar duende\n");
		printf ("6- Mostrar duendes registrados\n");
		printf ("7- Modificar datos de un duende\n");
		printf ("8- Eliminar duende\n");
		printf ("9- Agregar un nuevo juguete\n");
		printf ("10- Mostrar juguetes registrados\n");
		printf ("11- Modificar datos de un juguete\n");
		printf ("12- Eliminar un juguete\n");
		printf ("13- Agregar lugar\n");
		printf ("14- Agregar ruta entre lugares\n");
		printf ("15- Mostrar relaciones de los lugares\n");
		printf ("16- Agregar comportamiento\n");
		printf ("17- Mostrar comportamientos registrados\n");
		printf ("18- Salir del sistema\n");
		
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
				registro_ninos=EliminarLista_Doble(registro_ninos);
				break;
			case 5:
				nuevos_datos2(registro_duendes);
				break;
			case 6:
				mostrarLista_Doble_Duendes(registro_duendes);
				break;
			case 7:	
				registro_duendes=modificarLista_Doble2(registro_duendes);   			
				break;
			case 8:
				registro_duendes=EliminarLista_Doble2(registro_duendes);
				break;
			case 9:
				codigo_juguete_aux= sacar_codigo();
   				Insertar(&registro_codigos_juguetes,codigo_juguete_aux);
   				nuevos_datos3(registro_juguetes,codigo_juguete_aux);
				break;
			case 10:
				mostrarLista_Doble_Juguetes(registro_juguetes);
				break;
			case 11:
				registro_juguetes= modificarLista_Doble3(registro_juguetes);
				break;
			case 12:
   				registro_juguetes=EliminarLista_Doble3(registro_juguetes,&codigo_juguete_aux,registro_codigos_juguetes);
				break;
			case 13:
   				insertarNodo();
                fflush(stdin);
				break;	
			case 14:
				insertarArista();
            	fflush(stdin);
				break;
			case 15:
            	visualizarGrafo();
            	fflush(stdin);
				break;	
			case 16:
            	nuevos_datos4(registro_comportamientos,registro_ninos);
            	fflush(stdin);
				break;
			case 17:
            	mostrarLista_Doble_Comportamientos(registro_comportamientos);
            	fflush(stdin);
				break;		
			case 18:
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


