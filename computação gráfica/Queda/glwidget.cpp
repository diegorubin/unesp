#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent)
: QGLWidget(parent),
timer(this)
{
	luzAmbiente[0]=0.01;
	luzAmbiente[1]=0.01;
	luzAmbiente[2]=0.01;
	luzAmbiente[3]=0.820;
	luzDifusa[0]=0.7;
	luzDifusa[1]=0.7;
	luzDifusa[2]=0.7;
	luzDifusa[3]=1.0;
	posicao[0]=0.0;
	posicao[1]=50.0;
	posicao[2]=50.0;
	posicao[3]=0.20;
	luzEspecular[0]=1.0;
	luzEspecular[1]=1.0;
	luzEspecular[2]=1.0;
	luzEspecular[3]=1.0;
	especularidade[0]=0.5;
	especularidade[1]=0.5;
	especularidade[2]=0.5;
	especularidade[3]=1.0;
	especMaterial = 30;

	Tempo = 0;
	subindo = false;
	connect(&timer, SIGNAL(timeout()), this, SLOT(anima()));
}

GLWidget::~GLWidget()
{
    makeCurrent();
}
void GLWidget::initializeGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    angle=45;

    glEnable(GL_COLOR_MATERIAL); //cor material
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);

}

double GLWidget::getAltura()
{
	return Altura;
}

double GLWidget::getVelocidade()
{
	return Velocidade;
}

int GLWidget::getTempo()
{
	return Tempo;
}

void GLWidget::setCoeficienteRestituicao(double coeficiente)
{
	e = coeficiente;
}

void GLWidget::setAltura(double altura)
{
	AlturaInicial = altura;
}

void GLWidget::setGravidade(double gravidade)
{
	g = gravidade;
}

void GLWidget::iniciar(int intervalo)
{
	VelocidadeInicial =0;
	Velocidade = 0;
	subindo = false;
	Altura = AlturaInicial;
	Tempo = 0;

	timer.start(intervalo);
}

void GLWidget::parar()
{
	timer.stop();
}

void GLWidget::paintGL()
{
	glPushMatrix();
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT,GL_SPECULAR,especularidade);
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	glLightfv(GL_LIGHT0,GL_AMBIENT,luzAmbiente);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,luzDifusa);
	glLightfv(GL_LIGHT0,GL_POSITION,posicao);



	glColor3f(0.0f, 0.0f, 1.0f);
	if (Altura <= 10){
		Ysize =1/(1+(e/10*(10-Altura)));
	}
	else
		Ysize =1;
	Xsize =2-Ysize;
	glScalef(Xsize, Ysize, Xsize);

	glTranslatef(0,Altura,0);
	glEnable(GL_DEPTH_TEST);



	glutSolidSphere(5.0f,20,20);

	glPopMatrix();

	  glDepthFunc(GL_LESS);
	  glDisable(GL_TEXTURE_GEN_S);
	  glDisable(GL_TEXTURE_GEN_T);



	  glColor4f(0.0,1.0,0.0,0.8);
	glBegin(GL_QUADS);
	    glTexCoord2f(0.0, 0.0); glVertex3f(-100.0,  0.0,  -100.0);
	    glTexCoord2f(1.0, 0.0); glVertex3f( 100.0,  0.0,  -100.0);
	    glTexCoord2f(1.0, 1.0); glVertex3f( 100.0,  0.0, 100.0);
	    glTexCoord2f(0.0, 1.0); glVertex3f(-100.0,  0.0, 100.0);
	glEnd();

	glBegin(GL_LINES);				//so pra ver onde era o eixo
	  glColor3f(1.0,0.0,0.0);
			glVertex3f(0.0,0.0,0.0);
			glVertex3f(100.0,0.0,0.0);
			glVertex3f(0.0,100.0,0.0);
			glVertex3f(0.0,0.0,0.0);
			glVertex3f(0.0,0.0,100.0);
	glEnd();

}

void GLWidget::resizeGL(int w, int h)
{
    // Para previnir uma divisão por zero
    if ( h == 0 ) h = 1;

    // Especifica o tamanho da viewport
    glViewport(0, 0, w, h);

    // Calcula a correção de aspecto
    fAspect = (GLfloat)w/(GLfloat)h;

    //parametros de visualizacao
    // Especifica sistema de coordenadas de projeção
    glMatrixMode(GL_PROJECTION);
    // Inicializa sistema de coordenadas de projeção
    glLoadIdentity();

    // Especifica a projeção perspectiva
    gluPerspective(angle,fAspect,0.1,500);

    // Especifica sistema de coordenadas do modelo
    glMatrixMode(GL_MODELVIEW);
    // Inicializa sistema de coordenadas do modelo
    glLoadIdentity();

    // Especifica posição do observador e do alvo
    gluLookAt(0,160,300, 0,80,0, 0,1,0);
}

void GLWidget::anima()
{
	if(subindo) //quando esta voltando
	{
		//TODO tentar arrumar isso depois
		Altura = Calculos::espaco(0,VelocidadeInicial,instante,g*-1);
		Velocidade = Calculos::velocidade(VelocidadeInicial,instante,g*-1);
		if(Velocidade<=0)
		{
			subindo = false;
			AlturaInicial = Altura;
			instante = -10;
		}
	}
	else //quando esta caindo
	{
		Altura =(double)AlturaInicial - Calculos::espaco(0,0,instante,g);
		Velocidade = Calculos::velocidade(0,instante,g);
		if(Altura <=0){
			subindo = true;
			VelocidadeInicial =(double) Velocidade * e;//calculo para colisao
			instante = -10;
		}
	}
	updateGL();
	instante = instante + 10;
	Tempo = instante/100 + Tempo;
}

