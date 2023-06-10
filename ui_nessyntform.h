/********************************************************************************
** Form generated from reading UI file 'nessyntform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NESSYNTFORM_H
#define UI_NESSYNTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NesSyntForm
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_7;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QRadioButton *NoiseBut;
    QRadioButton *squareButton_2;
    QRadioButton *triangleButton;
    QRadioButton *squareButton;
    QRadioButton *squareButton_3;
    QRadioButton *squareButton_4;
    QPlainTextEdit *console;
    QWidget *plotFrame;
    QPushButton *hbSongButton;
    QProgressBar *progressBar;
    QPushButton *musicGeneratorBN;
    QLabel *label;
    QPlainTextEdit *ratio;

    void setupUi(QDialog *NesSyntForm)
    {
        if (NesSyntForm->objectName().isEmpty())
            NesSyntForm->setObjectName(QString::fromUtf8("NesSyntForm"));
        NesSyntForm->resize(893, 435);
        groupBox = new QGroupBox(NesSyntForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 91, 141));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setChecked(true);

        gridLayout->addWidget(radioButton_4, 0, 0, 1, 1);

        radioButton_5 = new QRadioButton(groupBox);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));

        gridLayout->addWidget(radioButton_5, 1, 0, 1, 1);

        radioButton_6 = new QRadioButton(groupBox);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));

        gridLayout->addWidget(radioButton_6, 2, 0, 1, 1);

        radioButton_7 = new QRadioButton(groupBox);
        radioButton_7->setObjectName(QString::fromUtf8("radioButton_7"));

        gridLayout->addWidget(radioButton_7, 3, 0, 1, 1);

        groupBox_2 = new QGroupBox(NesSyntForm);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(150, 10, 213, 101));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        NoiseBut = new QRadioButton(groupBox_2);
        NoiseBut->setObjectName(QString::fromUtf8("NoiseBut"));
        NoiseBut->setChecked(false);

        gridLayout_2->addWidget(NoiseBut, 0, 0, 1, 1);

        squareButton_2 = new QRadioButton(groupBox_2);
        squareButton_2->setObjectName(QString::fromUtf8("squareButton_2"));
        squareButton_2->setChecked(false);

        gridLayout_2->addWidget(squareButton_2, 0, 1, 1, 1);

        triangleButton = new QRadioButton(groupBox_2);
        triangleButton->setObjectName(QString::fromUtf8("triangleButton"));

        gridLayout_2->addWidget(triangleButton, 1, 0, 1, 1);

        squareButton = new QRadioButton(groupBox_2);
        squareButton->setObjectName(QString::fromUtf8("squareButton"));
        squareButton->setChecked(false);

        gridLayout_2->addWidget(squareButton, 2, 0, 1, 1);

        squareButton_3 = new QRadioButton(groupBox_2);
        squareButton_3->setObjectName(QString::fromUtf8("squareButton_3"));
        squareButton_3->setChecked(false);

        gridLayout_2->addWidget(squareButton_3, 1, 1, 1, 1);

        squareButton_4 = new QRadioButton(groupBox_2);
        squareButton_4->setObjectName(QString::fromUtf8("squareButton_4"));
        squareButton_4->setChecked(true);

        gridLayout_2->addWidget(squareButton_4, 2, 1, 1, 1);

        console = new QPlainTextEdit(NesSyntForm);
        console->setObjectName(QString::fromUtf8("console"));
        console->setGeometry(QRect(10, 150, 461, 241));
        console->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        console->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        console->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plotFrame = new QWidget(NesSyntForm);
        plotFrame->setObjectName(QString::fromUtf8("plotFrame"));
        plotFrame->setGeometry(QRect(480, 150, 401, 241));
        hbSongButton = new QPushButton(NesSyntForm);
        hbSongButton->setObjectName(QString::fromUtf8("hbSongButton"));
        hbSongButton->setGeometry(QRect(550, 60, 161, 32));
        progressBar = new QProgressBar(NesSyntForm);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(550, 30, 161, 23));
        progressBar->setValue(0);
        musicGeneratorBN = new QPushButton(NesSyntForm);
        musicGeneratorBN->setObjectName(QString::fromUtf8("musicGeneratorBN"));
        musicGeneratorBN->setGeometry(QRect(550, 100, 161, 32));
        label = new QLabel(NesSyntForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(224, 114, 41, 21));
        ratio = new QPlainTextEdit(NesSyntForm);
        ratio->setObjectName(QString::fromUtf8("ratio"));
        ratio->setGeometry(QRect(280, 110, 121, 31));

        retranslateUi(NesSyntForm);

        QMetaObject::connectSlotsByName(NesSyntForm);
    } // setupUi

    void retranslateUi(QDialog *NesSyntForm)
    {
        NesSyntForm->setWindowTitle(QApplication::translate("NesSyntForm", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("NesSyntForm", "\320\241\320\272\320\262\320\260\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        radioButton_4->setText(QApplication::translate("NesSyntForm", "&12.5%", nullptr));
        radioButton_5->setText(QApplication::translate("NesSyntForm", "&25 %", nullptr));
        radioButton_6->setText(QApplication::translate("NesSyntForm", "&50 %", nullptr));
        radioButton_7->setText(QApplication::translate("NesSyntForm", "&75 %", nullptr));
        groupBox_2->setTitle(QApplication::translate("NesSyntForm", "GroupBox", nullptr));
        NoiseBut->setText(QApplication::translate("NesSyntForm", "&NOISE", nullptr));
        squareButton_2->setText(QApplication::translate("NesSyntForm", "NOISE2", nullptr));
        triangleButton->setText(QApplication::translate("NesSyntForm", "&TRIANGLE", nullptr));
        squareButton->setText(QApplication::translate("NesSyntForm", "&SQUARE", nullptr));
        squareButton_3->setText(QApplication::translate("NesSyntForm", "GUITAR", nullptr));
        squareButton_4->setText(QApplication::translate("NesSyntForm", "FM", nullptr));
        hbSongButton->setText(QApplication::translate("NesSyntForm", "Happy Birsday Synt", nullptr));
        musicGeneratorBN->setText(QApplication::translate("NesSyntForm", "Music generator", nullptr));
        label->setText(QApplication::translate("NesSyntForm", "ratio", nullptr));
        ratio->setPlainText(QApplication::translate("NesSyntForm", "1/4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NesSyntForm: public Ui_NesSyntForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NESSYNTFORM_H
