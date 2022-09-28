#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <stdlib.h>

//paleta de colores basicos para ir llamando con punteros

float blanco[]={1,1,1};
float negro[]={0,0,0},azul[]={0,0,1};
float rojo[]={1,0,0},verde[]={0,1,0}, amarillo[]={1,1,0};
float cyan[]={0,1,1}, rosa[]={1,0.5,0.5}, naranja[]={1,0.8,0}, gris[]={0.6,0.6,0.6};

//funcion para trabajar con mas valores en pantalla y no restringido a -1 a 1


void pantalla()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-10,10,-10,10);

}

void cuadrado(float x, float y, float z, float a, float b, float c, float d, float e, float *color, float s)
{
    glColor3fv(color);
    glLineWidth(s);
    glBegin(GL_QUADS);
    glVertex2f(x,y);
    glVertex2f(z,a);
    glVertex2f(b,c);
    glVertex2f(d,e);

    glEnd();
}

void cuadrado_borde(float x, float y, float z, float a, float b, float c, float d, float e, float *color, float s)
{
    glColor3fv(color);
    glLineWidth(s);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x,y);
    glVertex2f(z,a);
    glVertex2f(b,c);
    glVertex2f(d,e);

    glEnd();
}

void triangulo (float x, float y, float z, float a, float b, float c, float *color, float s)
{
    glColor3fv(color);
    glLineWidth(s);
    glBegin(GL_TRIANGLES);
    glVertex2f(x,y);
    glVertex2f(z,a);
    glVertex2f(b,c);
    glEnd();


}

            // BORDES DE LA FIGURA
void triangulo_borde (float x, float y, float z, float a, float b, float c, float *color, float s)
{
    glColor3fv(color);
    glLineWidth(s);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x,y);
    glVertex2f(z,a);
    glVertex2f(b,c);
    glEnd();


}

void display(void)
{
glClearColor(1,1,1,1);//color de la ventana negro
glClear(GL_COLOR_BUFFER_BIT);


                    //glPointSize(7); // incrementa el tamaño del punto
                    //glLineWidth(5);//incrementa el ancho de la linea



//////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
       //PISO
cuadrado(-10,0.88,10,0.59,10,-2.76,-10,-2.99,verde,3);
        //PISO BORDE
cuadrado_borde(-10,0.88,10,0.59,10,-2.76,-10,-2.99,negro,3);

        //CIELO
cuadrado(-10,0.88,10,0.59,10,10,-10,10,azul,3);
        //CIELO BORDE
cuadrado_borde(-10,0.88,10,0.59,10,10,-10,10,negro,3);
        //SOL
cuadrado(5.48,8.4,6.77,8.4,6.77,7.19,5.35,7.29,amarillo,3);
        //SOL BORDE
cuadrado_borde(5.48,8.4,6.77,8.4,6.77,7.19,5.35,7.29,negro,3);


            //PARTE FRONTAL DEL AUTOMOVIL, LA MAS LARGA
triangulo(-5.26,0.11,-5,1,-5.24,1.25,cyan,3);
triangulo(-5,1,-5.24,1.25,-3.76,1.19,cyan,3);
triangulo(-3.76,1.19,-5.24,1.25,-3.06,1.47,cyan,3);
triangulo(-3.76,1.19,-3,0,-3.06,1.47,cyan,3);
triangulo(-3,0,0.42,1.71,-3.06,1.47,cyan,3);           //MTU
triangulo(0.42,1.71,-3,0,1.72,0.15,cyan,3);           //MUN
triangulo(1.72,0.15,0.42,1.71,2.4,1.19,cyan,3);       //NUO
triangulo(2.4,1.19,0.42,1.71,3.5,1.81,cyan,3);        //OUV
triangulo(2.4,1.19,3.5,1.81,3.92,1.13,cyan,3);         //OVP
triangulo(3.5,1.81,3.92,1.13,5.8,1.95,cyan,3);          //VPE
triangulo(3.92,1.13,5.8,1.95,4.74,0.19,cyan,3);         //EPQ
triangulo(5.62,0.25,5.8,1.95,4.74,0.19,cyan,3);         //EQR

        //PARTE TRASERA DEL AUTOMOVIL
cuadrado(5.8,1.95,5.62,0.25,7.78,0.49,8,2,cyan,3);
        //BORDE PARTE TRASERA DEL AUTOMOVIL
cuadrado_borde(5.8,1.95,5.62,0.25,7.78,0.49,8,2,negro,3);
        //LUZ TRASERA ROJA
cuadrado(5.8,1.95,8,2,8,1.76,5.79,1.72,rojo,3);
        //BORDE LUZ TRASERA
cuadrado_borde(5.8,1.95,8,2,8,1.76,5.79,1.72,negro,5);
        //PARTE SUPERIOR
triangulo(-5.24,1.25,-1,3,-3.06,1.47,gris,3);   //CDT
triangulo(0.42,1.71,-1,3,-3.06,1.47,gris,3);    //DTU
triangulo(0.42,1.71,-1,3,1.74,2.73,gris,3);     //IDU
triangulo(0.42,1.71,1.74,2.73,3.5,1.81,gris,3); //IUV
triangulo(5.8,1.95,1.74,2.73,3.5,1.81,gris,3); //IVW
        //BORDE PARTE SUPERIOR
/*
triangulo_borde(-5.24,1.25,-1,3,-3.06,1.47,negro,3);   //CDT
triangulo_borde(0.42,1.71,-1,3,1.74,2.73,negro,3);     //IDU
triangulo_borde(5.8,1.95,1.74,2.73,3.5,1.81,negro,3); //IVW
*/
        //TECHO DEL AUTOMOVIL
cuadrado(-1,3,1.74,2.73,3.72,2.69,1.62,3.1,cyan,3);     //DIHG
cuadrado(1.74,2.73,3.72,2.69,8,2,5.8,1.95,cyan,3);     //IHEF
        //BORDE TECHO
cuadrado_borde(-1,3,1.74,2.73,3.72,2.69,1.62,3.1,negro,3);     //DIHG
cuadrado_borde(1.74,2.73,3.72,2.69,8,2,5.8,1.95,negro,3);     //IHEF
        //VENTANA
cuadrado(-4.17,1.61,-0.99,2.81,1.29,2.5,1.2,2,amarillo,3);
        //VENTANA BORDE
cuadrado_borde(-4.17,1.61,-0.99,2.81,1.29,2.5,1.2,2,negro,3);

triangulo_borde(-5.26,0.11,-5,1,-5.24,1.25,negro,3);
triangulo_borde(-5,1,-5.24,1.25,-3.76,1.19,negro,3);
triangulo_borde(-3.76,1.19,-5.24,1.25,-3.06,1.47,negro,3);
triangulo_borde(-3.76,1.19,-3,0,-3.06,1.47,negro,3);
triangulo_borde(-3,0,0.42,1.71,-3.06,1.47,negro,3);           //MTU
triangulo_borde(0.42,1.71,-3,0,1.72,0.15,negro,3);           //MUN
triangulo_borde(1.72,0.15,0.42,1.71,2.4,1.19,negro,3);       //NUO
triangulo_borde(2.4,1.19,0.42,1.71,3.5,1.81,negro,3);        //OUV
triangulo_borde(2.4,1.19,3.5,1.81,3.92,1.13,negro,3);         //OVP
triangulo_borde(3.5,1.81,3.92,1.13,5.8,1.95,negro,3);          //VPE
triangulo_borde(3.92,1.13,5.8,1.95,4.74,0.19,negro,3);         //EPQ
triangulo_borde(5.62,0.25,5.8,1.95,4.74,0.19,negro,3);         //EQR

glColor3f(0,0,0);
glBegin(GL_POLYGON);
glLineWidth(5);
glVertex2f(-3.75288,0.6316);
glVertex2f(-4.38954,0.74318);
glVertex2f(-4.88837,0.4872);
glVertex2f(-5.14435,-0.03132);
glVertex2f(-5.08528,-0.65485);
glVertex2f(-4.83586,-1.02898);
glVertex2f(-4.29109,-1.17337);
glVertex2f(-3.75288,-1.1143);
glVertex2f(-3.31969,-0.59578);
glVertex2f(-3.3722,-0.01819);

glEnd();

glColor3f(0,0,0);
glBegin(GL_POLYGON);
glLineWidth(5);

glVertex2f(3.07974,0.70379);
glVertex2f(2.36432,0.30342);
glVertex2f(2.07553,-0.47108);
glVertex2f(2.31181,-1.1143);
glVertex2f(3.106,-1.55406);
glVertex2f(3.99207,-1.26526);
glVertex2f(4.30712,-0.51046);
glVertex2f(4.0052,0.32311);

glEnd();

cuadrado(2.36432,0.30342,3.07974,0.70379,2.4,1.19,1.72,0.15,negro,3);
triangulo(2.4,1.19,3.07974,0.70379,3.92,1.13,negro,3);
cuadrado(3.07974,0.70379,4.0052,0.32311,4.74,0.19,3.92,1.13,negro,3);
cuadrado(-5.22967,0.23778,-4.88837,0.4872,-4.38954,0.74318,-5,1,negro,3);
cuadrado(-4.38954,0.74318,-5,1,-3.76,1.19,-3.75288,0.6316,negro,3);
cuadrado(-3.76,1.19,-3.75288,0.6316,-3.3722,-0.01819,-3,0,negro,3);
cuadrado(-2.16,0.03,-0.9,0.07,-1.27843,-0.3595,-1.81008,-0.37262,negro,3);
triangulo(4.0052,0.32311,4.74,0.19,4.30712,-0.51046,negro,3);


glColor3f(0,0,0);
glBegin(GL_POLYGON);
glLineWidth(5);

glVertex2f(4.30712,-0.51046);
glVertex2f(4.74,0.19);
glVertex2f(5.62,0.25);
glVertex2f(5.40979,-0.24792);
glVertex2f(5,-0.5);
glEnd();


glColor3f(0,0,0);
glBegin(GL_LINES);
glLineWidth(7);
glVertex2f(-5.24,1.25);
glVertex2f(-1,3);
glEnd();

 glutSwapBuffers();                 // opcional funciona para algunos con esta funcion,... glFlush()
}






                            //funcion principal, siempre es de esa manera
int main(int argc, char *argv[])
{

    glutInit(&argc, argv);              //Sirve para inicializar mi ventana de opengl
    glutInitWindowPosition(0,0);        //parte la ventana en 4 partes y en (0,0) esta en el centro,posicion de mi ventana
    glutInitWindowSize(600,600);        //tamaño de mi ventana tamaño normal (600,600)
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);           //tipo de modo de visualizacion de la ventana

    glutCreateWindow("Primer programa");        //Colocar el nombre que se le da a la ventana
    glutDisplayFunc(display);                   //nombre de la función
    pantalla();
                            //glClearColor(1,1,1,1);//color de la ventana negro
    glutMainLoop();             //hace que aparezca la ventana
    return EXIT_SUCCESS;            //tambien se puede usar el return
}
