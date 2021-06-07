#include"ListaDisparos.h"


LISTADISPAROS::LISTADISPAROS()
{
	NUM = 0;
	for (int i = 0; i < MAX_DISPAROS; i++)
		LISTA[i] = 0;
}
LISTADISPAROS::~LISTADISPAROS()
{

}
bool LISTADISPAROS::AGREGAR(DISPARO* d)
{
	if (NUM < MAX_DISPAROS)
		LISTA[NUM++] = d;
	else
		return false;
	return true;
}

void LISTADISPAROS::DESTRUIRDISPAROS()
{
	for (int i = 0; i < NUM; i++)   
		delete LISTA[i];

	NUM = 0;
}
void LISTADISPAROS::MUEVE(float t)
{
	for (int i = 0; i < NUM; i++)  //Hace falta implementar la posocion en tiempo real para poder mover
		LISTA[i]->Mueve(t);
}

void LISTADISPAROS::DIBUJA() 
{
	for (int i = 0; i < NUM; i++)
		LISTA[i]->DIBUJA();
}

/*DISPARO* LISTADISPAROS::COLISION_ZOMBIE(ZOMBIE z)
{
	for (int i = 0; i < NUM; i++)
	{
		if (INTERACCIONES::INTERACCION_BALA_ZOMBIE(*(LISTA[i]), z))
			return LISTA[i];
	}
	return 0;
}*/

DISPARO* LISTADISPAROS::COLISION_MAPA(TABLERO t)//(variable de la pared del tablero*) Hay que implementar una interaccion entre Disparo y mapa
{
	for (int i = 0; i < NUM; i++)
	{
		if (INTERACCIONES::INTERACCION_BALA_TABLERO(*(LISTA[i]), t))
			return LISTA[i];
	}
	return 0;
}

void LISTADISPAROS::ELIMINAR(DISPARO* d)
{
	for (int i = 0; i < NUM; i++)
		if (LISTA[i] == d)
		{
			ELIMINAR(i);
			return;
		}
}

void LISTADISPAROS::ELIMINAR(int index)
{
	if ((index < 0) || (index >= NUM))
		return;
	delete LISTA[index];
	NUM--;
	for (int i = index; i < NUM ;i++)
		LISTA[i] = LISTA[i + 1];
}

int LISTADISPAROS::getNumero()
{
	return NUM;
}

DISPARO* LISTADISPAROS::operator [](int i)
{
	if (i >= NUM)//si me paso, devuelvo la ultima
		i = NUM - 1;

	if (i < 0) //si el indice es negativo, devuelvo la primera 
		i = 0;
	return LISTA[i];
}