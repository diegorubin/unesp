#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QtOpenGL/QGLWidget>
#include <QtCore/QTimer>
#include <GL/glut.h>

#include "Calculos.h"

#include <math.h>

class GLWidget : public QGLWidget
{
Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();

    double getAltura();
    double getVelocidade();
    int getTempo();


    void setAltura(double altura);
    void setGravidade(double gravidade);
    void setCoeficienteRestituicao(double coeficiente);

    void iniciar(int intervalo);
    void parar();

private:
    int instante;
    int Tempo;
    GLfloat angle;
    GLfloat fAspect;
    GLfloat Xsize,Ysize;

    //luz
	GLfloat luzAmbiente[4];
	GLfloat luzDifusa[4];
	GLfloat posicao[4];
	GLfloat luzEspecular[4];
	GLfloat especularidade[];
	GLint especMaterial;
    bool subindo;

    double g,Altura,Velocidade;
    double AlturaInicial;
    double VelocidadeInicial;
    double e;

    QTimer timer;
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

private slots:
    void anima();

};

#endif // GLWIDGET_H
