#include "glut.h"
#include "Funcion.h"
#include <math.h>


void Funcion::pintaFuncion(float CX, float CY, float Red, float Green, float Blue) {
	//glClear(GL_COLOR_BUFFER_BIT);//limpiar el buffer de color
	glPointSize(8);//tama隳 del pixel
	glColor3f(Red, Green, Blue);//definir color
	glBegin(GL_POINTS);
	glVertex2d(CX, CY);//definir coordenadas
	glEnd();//termina el glBegin
	glutSwapBuffers();
}

void Funcion::limpiar() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);
	glFlush();
	glutSwapBuffers();
}

void Funcion::octante(float xf,float yf,float xi,float yi) {
	pintaFuncion(x + xi, y + yi, 0, 0, 1);
	pintaFuncion(x + xi, y + yi, 0, 0, 1);
	pintaFuncion(y + xi, x + yi, 0, 0, 1);
	pintaFuncion(y + xi, x + yi, 0, 0, 1);
	pintaFuncion(-x + xi, y + yi, 0, 0, 1);
	pintaFuncion(-x + xi, y + yi, 0, 0, 1);
	pintaFuncion(-y + xi, x + yi, 0, 0, 1);
	pintaFuncion(-y + xi, x + yi, 0, 0, 1);
	pintaFuncion(-y + xi, -x + yi, 0, 0, 1);
	pintaFuncion(-y + xi, -x + yi, 0, 0, 1);
	pintaFuncion(-x + xi, -y + yi, 0, 0, 1);
	pintaFuncion(-x + xi, -y + yi, 0, 0, 1);
	pintaFuncion(y + xi, -x + yi, 0, 0, 1);
	pintaFuncion(y + xi, -x + yi, 0, 0, 1);
	pintaFuncion(x + xi, -y + yi, 0, 0, 1);
	pintaFuncion(x + xi, -y + yi, 0, 0, 1);
}
void Funcion::puntomedio(float xi,float yi,float xf,float yf) {
	x = 0;
	Dx = xf - xi;
	Dy = yf - yi;
	r = sqrtf(pow((Dx), 2)) + pow((Dy), 2);
	y = r;
	int d = 5 / 4 - r;
	float inc1 = 5 - (2 * r);
	float inc2 = 3;
	octante(xf,yf,xi,yi);
	while (x<=y) {
		if (d > 0) {
			x++;
			y--;
			d = d + inc1;
			inc1 = inc1 + 4;
			inc2 = inc2 + 2;		
		}
		else {
			x++;
			y = y;
			d = d + inc2;
			inc1 = inc1 + 2;
			inc2 = inc2 + 2;		
		}
		octante(xf, yf, xi, yi);
	}
}

void Funcion::elipse() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.2, 0.2);//DEFINO COLOR
	int r = 0; //radio 
	int x, y;   //Coordenadas para glvetex2d
	int theta1; //聲gulo en grados
	int theta2; //聲gulo en radianes
	while (r < 20) {   //Para que llegue a un radio definido y no se pase
		for (theta1 = 0; theta1 < 360; theta1++) {
			theta2 = (int)((theta1 * 180) / PI);
			x = (int)(a * cos(theta2)); //c嫮culo de x para glut
			y = (int)(b * sin(theta2)); //c嫮culo de y para glut
			pintaFuncion(x, y, 1, 0.4, 0.6);
		}
		r = r + 2; //iterador para que glut vaya dibujando vez por vez el radio
	}
	glFlush();
}

void Funcion::circulo()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.2, 0.2);//DEFINO COLOR
	int r = 0; //radio 
	int x, y;   //Coordenadas para glvetex2d
	int theta1; //聲gulo en grados
	int theta2; //聲gulo en radianes
	while (r < 20) {   //Para que llegue a un radio definido y no se pase
		for (theta1 = 0; theta1 < 360; theta1++) {
			theta2 = (int)((theta1 * 180) / PI);
			x = (int)(r * cos(theta2)); //c嫮culo de x para glut
			y = (int)(r * sin(theta2)); //c嫮culo de y para glut
			pintaFuncion(x, y, 0.4, 1, 0.6);
		}
		r = r + 2; //iterador para que glut vaya dibujando vez por vez el radio
	}
	glFlush();
}

void Funcion::plano() {
	for (float i = -GX; i < GX; i++)
	{
		pintaFuncion(i, 0, 1, 1, 1);//dibuja pixeles en el eje x
	}
	for (float i = -GY; i < GY; i++)
	{
		pintaFuncion(0, i, 1, 1, 1);//dibuja pixeles en el eje y
	}
}
