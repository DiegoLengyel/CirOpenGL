#include "glut.h"
#include "Funcion.h"

Funcion func;

int ancho = 500, alto = 500;
float GX = ancho / 2, GY = alto / 2;
float V, V1;
float X, Y;
float yi = 15, xi = 10, yf = 26, xf = 24, Xini, Yini,r;
float m, Dy, Dx, step;



void plano() {
	func.plano();
}

void menu(int value) {
	switch (value)
	{
	case 1:
		func.circulo();
		break;
	case 2:
		func.elipse();
		break;
	case 3:
		func.puntomedio(xi,yi,xf,yf);
		break;
	case 4:
		func.limpiar();
		func.plano();
		break;
	case 5:
		exit(0);
		break;
	}
	
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);//inicializamos glutInit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA/*R=rojo,G=verde,B=Azul,A=Opacidad*/);//buffers
	glutInitWindowSize(ancho, alto);// tamaño de la ventana
	glutInitWindowPosition(100, 100);//posicion de la ventana
	glutCreateWindow("Funciones matematicas");//creacion y titulo de la ventana
	gluOrtho2D(-GX, GX, -GY, GY);//punto exacto en la ventana
	int sub1 = glutCreateMenu(menu); //inicio creacion de menu
	glutAddMenuEntry("Circulo", 1);
	glutAddMenuEntry("Elipse", 2);
	glutAddMenuEntry("Punto Medio", 3);
	glutAddMenuEntry("Limpiar",4);
	glutCreateMenu(menu);
	glutAddSubMenu("Dibujar", 1);
	glutAddMenuEntry("Salir", 5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glClearColor(0, 0, 0, 0);//color base de la ventana RGBA
	glutDisplayFunc(plano);
	glutMainLoop();//loop para salir
	return 0;
}