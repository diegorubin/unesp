#ifndef QUEDA_H
#define QUEDA_H

#include <QtGui/QWidget>
#include <QtCore/QTimer>
#include "ui_queda.h"

#include "glwidget.h"

class Queda : public QWidget
{
    Q_OBJECT

public:
    Queda(QWidget *parent = 0);
    ~Queda();

private:
    Ui::QuedaClass ui;

    GLWidget glWidget;
    QTimer timer;

private slots:
	void getInfs();
	void setInfs();
	void parar();
};

#endif // QUEDA_H
