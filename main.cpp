#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <cstring>
#include <cstdio>

using namespace std;

struct Datos
{
	char nombre[30];
	char apellido[30];
	int edad;
	void imprimir() 
	{
		printf("\nNombre: %s\nApellido: %s\nEdad: %d\n", nombre, apellido, edad);
	}
	Datos pedirDatos() {
		printf("\nIngrese datos:\n	Nombre: ");
		scanf("%s", nombre);
		printf("\n	Apellido: ");
		scanf("%s", apellido);
		printf("\n	Edad: ");
		scanf("%d", &edad);
		return *this;
	}
};

struct Nodo
{
	Datos info;
	Nodo * sig;
};

struct Pila {

	Nodo * cab = NULL;
	int nItems = 0;

	void insertar(const Datos info) {
		Nodo * nuevo = (Nodo *) malloc(sizeof(Nodo));
		strcpy(nuevo->info.nombre, info.nombre);
		strcpy(nuevo->info.apellido, info.apellido);
		nuevo->info.edad = info.edad;
		nuevo->sig = NULL;
		if (cab == NULL)
			cab = nuevo;
		else
		{
			nuevo->sig = cab;
			cab = nuevo;
		}
	}

	void eliminar(Datos & eliminado) {
		if (cab != NULL)
		{
			Nodo * aux = cab;
			eliminado = cab->info;
			cab = cab->sig;
			delete aux;
		}
		else 
			printf("\nNingun nodo existente en Pila\n");
		
	}

	void mostrar() 
	{
		Nodo * aux = cab;
		if (cab == NULL)
			printf("\nNingun nodo existente en Pila\n");
		else
			while (aux != NULL)
			{
				aux->info.imprimir();
				aux = aux->sig;
			}
	}
};

struct Cola {
	Nodo * cab = NULL;
	Nodo * cola = NULL;
	int nItems = 0;
	void insertar(const Datos info)
	{
		Nodo * nuevo = (Nodo *)malloc(sizeof(Nodo));
		strcpy(nuevo->info.nombre, info.nombre);
		strcpy(nuevo->info.apellido, info.apellido);
		nuevo->info.edad = info.edad;
		nuevo->sig = NULL;
		if (cab == NULL)
		{
			cola = nuevo;
			cab = nuevo;
		}
		else 
		{
			cola->sig = nuevo;
			cola = nuevo;
		}
	}

	void eliminar(Datos & eliminado) {
		if (cab != NULL)
		{
			Nodo * aux = cab;
			eliminado = cab->info;
			cab = cab->sig;
			delete aux;
		}
		else 
			printf("\nNingun nodo existente en Cola\n");
	}

	void mostrar() 
	{
		Nodo * aux = cab;

		if (cab == NULL)
			printf("\nNingun nodo existente en Cola\n");
		else
			while (aux != NULL)
			{
				aux->info.imprimir();
				aux = aux->sig;
			}
	}
};

int menuPrincipal() 
{
	int sel = 0;
	printf("\nPILAS Y COLAS\n	1.Insertar\n	2.Eliminar\n	3.Recorrer\n	Seleccion: ");
	scanf("%d", &sel);
	return sel;
}

int menuColaPila() 
{
	int sel = 0;
	printf("\nAplicar a:\n	1.Pila\n	2.Cola\n	Seleccion: ");
	scanf("%d", &sel);
	return sel;
}

int main() {
	Pila pila;
	Cola cola;
	Datos dat;
	int opc = 0;
	do {
		switch (opc = menuPrincipal())
		{
			case 1: 
				switch (menuColaPila())
				{
					case 1:
						{
							Datos temp;
							pila.insertar(temp.pedirDatos());
						}
						break;
					case 2: 
						{
							Datos temp;
							cola.insertar(temp.pedirDatos());
						}
						break;
				}
				break;
			case 2:
				switch (menuColaPila())
				{
					case 1:
						pila.eliminar(dat);
						break;
					case 2:
						cola.eliminar(dat);
						break;
				}
				break;
			case 3:
				switch (menuColaPila())
				{
					case 1:
						pila.mostrar();
						break;
					case 2:
						cola.mostrar();
						break;
				}
				break;
		}
	} while (opc != 0);
}