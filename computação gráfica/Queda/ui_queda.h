/********************************************************************************
** Form generated from reading ui file 'queda.ui'
**
** Created: Sun Jul 5 17:13:21 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_QUEDA_H
#define UI_QUEDA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuedaClass
{
public:
    QGridLayout *gridLayout;
    QScrollArea *sclGL;
    QWidget *scrollAreaWidgetContents;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *lblAltura;
    QLabel *label_3;
    QLabel *lblVelocidade;
    QLabel *label;
    QLabel *lblTempo;
    QLabel *label_4;
    QLineEdit *edtAltura;
    QLabel *label_5;
    QSlider *slrCoeficiente;
    QLabel *label_6;
    QLineEdit *edtGravidade;
    QPushButton *btnIniciar;

    void setupUi(QWidget *QuedaClass)
    {
        if (QuedaClass->objectName().isEmpty())
            QuedaClass->setObjectName(QString::fromUtf8("QuedaClass"));
        QuedaClass->resize(965, 700);
        gridLayout = new QGridLayout(QuedaClass);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        sclGL = new QScrollArea(QuedaClass);
        sclGL->setObjectName(QString::fromUtf8("sclGL"));
        sclGL->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 697, 686));
        sclGL->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(sclGL, 0, 0, 1, 1);

        groupBox = new QGroupBox(QuedaClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(250, 0));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 60, 51, 18));
        lblAltura = new QLabel(groupBox);
        lblAltura->setObjectName(QString::fromUtf8("lblAltura"));
        lblAltura->setGeometry(QRect(80, 60, 64, 18));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 90, 101, 18));
        lblVelocidade = new QLabel(groupBox);
        lblVelocidade->setObjectName(QString::fromUtf8("lblVelocidade"));
        lblVelocidade->setGeometry(QRect(120, 90, 64, 18));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 141, 18));
        lblTempo = new QLabel(groupBox);
        lblTempo->setObjectName(QString::fromUtf8("lblTempo"));
        lblTempo->setGeometry(QRect(170, 30, 64, 18));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 170, 221, 18));
        edtAltura = new QLineEdit(groupBox);
        edtAltura->setObjectName(QString::fromUtf8("edtAltura"));
        edtAltura->setGeometry(QRect(10, 190, 211, 28));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 250, 221, 18));
        slrCoeficiente = new QSlider(groupBox);
        slrCoeficiente->setObjectName(QString::fromUtf8("slrCoeficiente"));
        slrCoeficiente->setGeometry(QRect(10, 290, 211, 23));
        slrCoeficiente->setMaximum(100);
        slrCoeficiente->setOrientation(Qt::Horizontal);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 340, 221, 18));
        edtGravidade = new QLineEdit(groupBox);
        edtGravidade->setObjectName(QString::fromUtf8("edtGravidade"));
        edtGravidade->setGeometry(QRect(10, 360, 211, 28));
        btnIniciar = new QPushButton(groupBox);
        btnIniciar->setObjectName(QString::fromUtf8("btnIniciar"));
        btnIniciar->setGeometry(QRect(60, 440, 114, 27));

        gridLayout->addWidget(groupBox, 0, 1, 1, 1);


        retranslateUi(QuedaClass);

        QMetaObject::connectSlotsByName(QuedaClass);
    } // setupUi

    void retranslateUi(QWidget *QuedaClass)
    {
        QuedaClass->setWindowTitle(QApplication::translate("QuedaClass", "Queda", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("QuedaClass", "Informa\303\247\303\265es", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("QuedaClass", "<b>Altura:</b>", 0, QApplication::UnicodeUTF8));
        lblAltura->setText(QApplication::translate("QuedaClass", "170 m", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("QuedaClass", "<b>Velocidade:</b>", 0, QApplication::UnicodeUTF8));
        lblVelocidade->setText(QApplication::translate("QuedaClass", "0 m/s", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QuedaClass", "<b>Tempo Decorrido:</b>", 0, QApplication::UnicodeUTF8));
        lblTempo->setText(QString());
        label_4->setText(QApplication::translate("QuedaClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Altura Inicial (m)</span>:</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("QuedaClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Coeficiente de Elasticidade:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("QuedaClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Gravidade (m/s\302\262):</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        btnIniciar->setText(QApplication::translate("QuedaClass", "Iniciar", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(QuedaClass);
    } // retranslateUi

};

namespace Ui {
    class QuedaClass: public Ui_QuedaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUEDA_H
