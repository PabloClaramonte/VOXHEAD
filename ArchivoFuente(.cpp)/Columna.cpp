#include <Columna.h>


void COLUMNA::DIBUJAR(void)
{
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(POSICION.X, POSICION.Y, POSICION.Z);
	glutSolidCube(TAMAŅOCOLUMNA);
	glTranslatef(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

/*
float COLUMNA::MOSTRAR_LIMITE_MAXIMO_EJE_X(int numerocolum)
{
	return (OBTENERVALOR_X() + (TAMAŅOCOLUMNA / 2));
}

float COLUMNA::MOSTRAR_LIMITE_MINIMO_EJE_X(int numerocolum)
{
	return (OBTENERVALOR_X() - (TAMAŅOCOLUMNA / 2));
}

float COLUMNA::MOSTRAR_LIMITE_MAXIMO_EJE_Z(int numerocolum)
{
	return (OBTENERVALOR_Z() + (TAMAŅOCOLUMNA / 2));
}

float COLUMNA::MOSTRAR_LIMITE_MINIMO_EJE_Z(int numerocolum)
{
	return (OBTENERVALOR_Z() - (TAMAŅOCOLUMNA / 2));
}
*/