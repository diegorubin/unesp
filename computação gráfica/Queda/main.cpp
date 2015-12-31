#include "queda.h"

#include <QtGui>
#include <QApplication>
#include <GL/glut.h>

int main(int argc, char *argv[])
{
	glutInit(&argc,argv);
    QApplication a(argc, argv);
    Queda w;
    w.show();
    return a.exec();
}
