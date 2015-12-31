#include "queda.h"

Queda::Queda(QWidget *parent)
    : QWidget(parent),
    timer(this)
{
	ui.setupUi(this);
	ui.sclGL->setWidget(&glWidget);
	connect(&timer,SIGNAL(timeout()),this,SLOT(getInfs()));
	connect(ui.btnIniciar,SIGNAL(clicked()),this,SLOT(setInfs()));
}

Queda::~Queda()
{

}

void Queda::getInfs()
{
	ui.lblTempo->setText(QString::number(glWidget.getTempo()));
	ui.lblAltura->setText(QString::number(glWidget.getAltura()) + " m");
	ui.lblVelocidade->setText(QString::number(glWidget.getVelocidade()) + " m/s");

}

void Queda::setInfs()
{
	disconnect(ui.btnIniciar,SIGNAL(clicked()),this,SLOT(setInfs()));
	connect(ui.btnIniciar,SIGNAL(clicked()),this,SLOT(parar()));
	ui.btnIniciar->setText("Parar");
	glWidget.setAltura(ui.edtAltura->text().toDouble());
	glWidget.setGravidade(ui.edtGravidade->text().toDouble());
	glWidget.setCoeficienteRestituicao((double) ui.slrCoeficiente->value()/100);

	timer.start(10);
	glWidget.iniciar(10);
}

void Queda::parar()
{
	disconnect(ui.btnIniciar,SIGNAL(clicked()),this,SLOT(parar()));
	connect(ui.btnIniciar,SIGNAL(clicked()),this,SLOT(setInfs()));
	ui.btnIniciar->setText("Iniciar");
	timer.stop();
	glWidget.parar();
}
