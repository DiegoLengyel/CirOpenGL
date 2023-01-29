#pragma once
class Funcion {
public:
	int ancho = 500, alto = 500;
	float GX = ancho / 2, GY = alto / 2;
	float V=0, V1=0;
	float X=0, Y = 0, xK = 0, yK = 0;
	float yi = 0, xi = 0, yf = 0, xf = 0, Xini=0, Yini=0;
	float m = 0, Dy = 0, Dx = 0, step = 0, p0 = 0,r=0;
	float x0 = 10, y0 = 10, x = 0, y = 0, xk = 0, yk = 0 , a = 100, b = 50;
	float PI = 3.1416;
public:
	void pintaFuncion(float, float, float, float, float);
	void plano();
	void limpiar();
	void elipse();
	void circulo();
	void puntomedio(float, float, float, float);
	void octante(float,float,float,float);
	~Funcion() {};
};