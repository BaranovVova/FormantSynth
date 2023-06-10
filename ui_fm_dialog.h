/********************************************************************************
** Form generated from reading UI file 'fm_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FM_DIALOG_H
#define UI_FM_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "svgwidget.h"

QT_BEGIN_NAMESPACE

class Ui_FM_Dialog
{
public:
    QComboBox *comboBox;
    QComboBox *algoCombo;
    QLabel *label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_7;
    QWidget *layoutWidget_11;
    QHBoxLayout *horizontalLayout_18;
    QSlider *rate60;
    QSlider *rate61;
    QSlider *rate62;
    QSlider *rate63;
    QWidget *layoutWidget_12;
    QHBoxLayout *horizontalLayout_19;
    QSlider *level60;
    QSlider *level61;
    QSlider *level62;
    QSlider *level63;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_14;
    QDoubleSpinBox *f6;
    QDoubleSpinBox *I6;
    QDoubleSpinBox *d6;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_24;
    QPushButton *CopyTo6;
    QComboBox *ComboTo6;
    QGroupBox *groupBox_6;
    QWidget *layoutWidget_9;
    QHBoxLayout *horizontalLayout_15;
    QSlider *rate50;
    QSlider *rate51;
    QSlider *rate52;
    QSlider *rate53;
    QWidget *layoutWidget_10;
    QHBoxLayout *horizontalLayout_16;
    QSlider *level50;
    QSlider *level51;
    QSlider *level52;
    QSlider *level53;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_13;
    QDoubleSpinBox *f5;
    QDoubleSpinBox *I5;
    QDoubleSpinBox *d5;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_23;
    QPushButton *CopyTo5;
    QComboBox *ComboTo5;
    QGroupBox *groupBox;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QSlider *level10;
    QSlider *level11;
    QSlider *level12;
    QSlider *level13;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout;
    QSlider *rate10;
    QSlider *rate11;
    QSlider *rate12;
    QSlider *rate13;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_9;
    QDoubleSpinBox *f1;
    QDoubleSpinBox *I1;
    QDoubleSpinBox *d1;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *layoutWidget7;
    QHBoxLayout *horizontalLayout_17;
    QPushButton *CopyTo1;
    QComboBox *ComboTo1;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QSlider *level30;
    QSlider *level31;
    QSlider *level32;
    QSlider *level33;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QSlider *rate30;
    QSlider *rate31;
    QSlider *rate32;
    QSlider *rate33;
    QWidget *layoutWidget8;
    QHBoxLayout *horizontalLayout_11;
    QDoubleSpinBox *f3;
    QDoubleSpinBox *I3;
    QDoubleSpinBox *d3;
    QWidget *layoutWidget9;
    QHBoxLayout *horizontalLayout_21;
    QPushButton *CopyTo3;
    QComboBox *ComboTo3;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QSlider *rate20;
    QSlider *rate21;
    QSlider *rate22;
    QSlider *rate23;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QSlider *level20;
    QSlider *level21;
    QSlider *level22;
    QSlider *level23;
    QWidget *layoutWidget10;
    QHBoxLayout *horizontalLayout_10;
    QDoubleSpinBox *f2;
    QDoubleSpinBox *I2;
    QDoubleSpinBox *d2;
    QWidget *layoutWidget11;
    QHBoxLayout *horizontalLayout_20;
    QPushButton *CopyTo2;
    QComboBox *ComboTo2;
    QGroupBox *groupBox_5;
    QWidget *layoutWidget_7;
    QHBoxLayout *horizontalLayout_7;
    QSlider *rate40;
    QSlider *rate41;
    QSlider *rate42;
    QSlider *rate43;
    QWidget *layoutWidget_8;
    QHBoxLayout *horizontalLayout_8;
    QSlider *level40;
    QSlider *level41;
    QSlider *level42;
    QSlider *level43;
    QWidget *layoutWidget12;
    QHBoxLayout *horizontalLayout_12;
    QDoubleSpinBox *f4;
    QDoubleSpinBox *I4;
    QDoubleSpinBox *d4;
    QWidget *layoutWidget13;
    QHBoxLayout *horizontalLayout_22;
    QPushButton *CopyTo4;
    QComboBox *ComboTo4;
    QWidget *plotFrame;
    QLabel *label_4;
    SvgWidget *algosvg;
    QCheckBox *OSC;
    QComboBox *comboBox_2;
    QWidget *layoutWidget14;
    QGridLayout *gridLayout_2;
    QPushButton *test1;
    QPushButton *test2;
    QPushButton *test1_2;
    QPushButton *pushButton_3;
    QLabel *label_5;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_6;
    QSlider *pichMod;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_7;
    QSlider *delay;

    void setupUi(QDialog *FM_Dialog)
    {
        if (FM_Dialog->objectName().isEmpty())
            FM_Dialog->setObjectName(QString::fromUtf8("FM_Dialog"));
        FM_Dialog->resize(1215, 513);
        comboBox = new QComboBox(FM_Dialog);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 30, 121, 30));
        algoCombo = new QComboBox(FM_Dialog);
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->addItem(QString());
        algoCombo->setObjectName(QString::fromUtf8("algoCombo"));
        algoCombo->setGeometry(QRect(80, 70, 41, 30));
        label = new QLabel(FM_Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 76, 50, 16));
        layoutWidget = new QWidget(FM_Dialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 120, 1071, 311));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_7 = new QGroupBox(layoutWidget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        layoutWidget_11 = new QWidget(groupBox_7);
        layoutWidget_11->setObjectName(QString::fromUtf8("layoutWidget_11"));
        layoutWidget_11->setGeometry(QRect(20, 60, 121, 51));
        horizontalLayout_18 = new QHBoxLayout(layoutWidget_11);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(0, 0, 0, 0);
        rate60 = new QSlider(layoutWidget_11);
        rate60->setObjectName(QString::fromUtf8("rate60"));
        rate60->setOrientation(Qt::Vertical);

        horizontalLayout_18->addWidget(rate60);

        rate61 = new QSlider(layoutWidget_11);
        rate61->setObjectName(QString::fromUtf8("rate61"));
        rate61->setOrientation(Qt::Vertical);

        horizontalLayout_18->addWidget(rate61);

        rate62 = new QSlider(layoutWidget_11);
        rate62->setObjectName(QString::fromUtf8("rate62"));
        rate62->setOrientation(Qt::Vertical);

        horizontalLayout_18->addWidget(rate62);

        rate63 = new QSlider(layoutWidget_11);
        rate63->setObjectName(QString::fromUtf8("rate63"));
        rate63->setOrientation(Qt::Vertical);

        horizontalLayout_18->addWidget(rate63);

        layoutWidget_12 = new QWidget(groupBox_7);
        layoutWidget_12->setObjectName(QString::fromUtf8("layoutWidget_12"));
        layoutWidget_12->setGeometry(QRect(190, 60, 121, 51));
        horizontalLayout_19 = new QHBoxLayout(layoutWidget_12);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(0, 0, 0, 0);
        level60 = new QSlider(layoutWidget_12);
        level60->setObjectName(QString::fromUtf8("level60"));
        level60->setOrientation(Qt::Vertical);

        horizontalLayout_19->addWidget(level60);

        level61 = new QSlider(layoutWidget_12);
        level61->setObjectName(QString::fromUtf8("level61"));
        level61->setOrientation(Qt::Vertical);

        horizontalLayout_19->addWidget(level61);

        level62 = new QSlider(layoutWidget_12);
        level62->setObjectName(QString::fromUtf8("level62"));
        level62->setOrientation(Qt::Vertical);

        horizontalLayout_19->addWidget(level62);

        level63 = new QSlider(layoutWidget_12);
        level63->setObjectName(QString::fromUtf8("level63"));
        level63->setOrientation(Qt::Vertical);

        horizontalLayout_19->addWidget(level63);

        layoutWidget1 = new QWidget(groupBox_7);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 301, 32));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        f6 = new QDoubleSpinBox(layoutWidget1);
        f6->setObjectName(QString::fromUtf8("f6"));
        f6->setSingleStep(0.100000000000000);
        f6->setValue(1.000000000000000);

        horizontalLayout_14->addWidget(f6);

        I6 = new QDoubleSpinBox(layoutWidget1);
        I6->setObjectName(QString::fromUtf8("I6"));
        I6->setSingleStep(0.100000000000000);
        I6->setValue(1.000000000000000);

        horizontalLayout_14->addWidget(I6);

        d6 = new QDoubleSpinBox(layoutWidget1);
        d6->setObjectName(QString::fromUtf8("d6"));
        d6->setMinimum(-99.989999999999995);
        d6->setValue(-1.000000000000000);

        horizontalLayout_14->addWidget(d6);

        layoutWidget2 = new QWidget(groupBox_7);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(80, 110, 144, 34));
        horizontalLayout_24 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        horizontalLayout_24->setContentsMargins(0, 0, 0, 0);
        CopyTo6 = new QPushButton(layoutWidget2);
        CopyTo6->setObjectName(QString::fromUtf8("CopyTo6"));

        horizontalLayout_24->addWidget(CopyTo6);

        ComboTo6 = new QComboBox(layoutWidget2);
        ComboTo6->addItem(QString());
        ComboTo6->addItem(QString());
        ComboTo6->addItem(QString());
        ComboTo6->addItem(QString());
        ComboTo6->addItem(QString());
        ComboTo6->addItem(QString());
        ComboTo6->addItem(QString());
        ComboTo6->setObjectName(QString::fromUtf8("ComboTo6"));

        horizontalLayout_24->addWidget(ComboTo6);


        gridLayout->addWidget(groupBox_7, 1, 2, 1, 1);

        groupBox_6 = new QGroupBox(layoutWidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        layoutWidget_9 = new QWidget(groupBox_6);
        layoutWidget_9->setObjectName(QString::fromUtf8("layoutWidget_9"));
        layoutWidget_9->setGeometry(QRect(20, 60, 121, 51));
        horizontalLayout_15 = new QHBoxLayout(layoutWidget_9);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        rate50 = new QSlider(layoutWidget_9);
        rate50->setObjectName(QString::fromUtf8("rate50"));
        rate50->setOrientation(Qt::Vertical);

        horizontalLayout_15->addWidget(rate50);

        rate51 = new QSlider(layoutWidget_9);
        rate51->setObjectName(QString::fromUtf8("rate51"));
        rate51->setOrientation(Qt::Vertical);

        horizontalLayout_15->addWidget(rate51);

        rate52 = new QSlider(layoutWidget_9);
        rate52->setObjectName(QString::fromUtf8("rate52"));
        rate52->setOrientation(Qt::Vertical);

        horizontalLayout_15->addWidget(rate52);

        rate53 = new QSlider(layoutWidget_9);
        rate53->setObjectName(QString::fromUtf8("rate53"));
        rate53->setOrientation(Qt::Vertical);

        horizontalLayout_15->addWidget(rate53);

        layoutWidget_10 = new QWidget(groupBox_6);
        layoutWidget_10->setObjectName(QString::fromUtf8("layoutWidget_10"));
        layoutWidget_10->setGeometry(QRect(190, 60, 121, 51));
        horizontalLayout_16 = new QHBoxLayout(layoutWidget_10);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        level50 = new QSlider(layoutWidget_10);
        level50->setObjectName(QString::fromUtf8("level50"));
        level50->setOrientation(Qt::Vertical);

        horizontalLayout_16->addWidget(level50);

        level51 = new QSlider(layoutWidget_10);
        level51->setObjectName(QString::fromUtf8("level51"));
        level51->setOrientation(Qt::Vertical);

        horizontalLayout_16->addWidget(level51);

        level52 = new QSlider(layoutWidget_10);
        level52->setObjectName(QString::fromUtf8("level52"));
        level52->setOrientation(Qt::Vertical);

        horizontalLayout_16->addWidget(level52);

        level53 = new QSlider(layoutWidget_10);
        level53->setObjectName(QString::fromUtf8("level53"));
        level53->setOrientation(Qt::Vertical);

        horizontalLayout_16->addWidget(level53);

        layoutWidget3 = new QWidget(groupBox_6);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 20, 311, 32));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        f5 = new QDoubleSpinBox(layoutWidget3);
        f5->setObjectName(QString::fromUtf8("f5"));
        f5->setSingleStep(0.100000000000000);
        f5->setValue(1.000000000000000);

        horizontalLayout_13->addWidget(f5);

        I5 = new QDoubleSpinBox(layoutWidget3);
        I5->setObjectName(QString::fromUtf8("I5"));
        I5->setSingleStep(0.100000000000000);
        I5->setValue(1.000000000000000);

        horizontalLayout_13->addWidget(I5);

        d5 = new QDoubleSpinBox(layoutWidget3);
        d5->setObjectName(QString::fromUtf8("d5"));
        d5->setMinimum(-99.989999999999995);
        d5->setValue(-7.000000000000000);

        horizontalLayout_13->addWidget(d5);

        layoutWidget4 = new QWidget(groupBox_6);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(100, 110, 144, 34));
        horizontalLayout_23 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        horizontalLayout_23->setContentsMargins(0, 0, 0, 0);
        CopyTo5 = new QPushButton(layoutWidget4);
        CopyTo5->setObjectName(QString::fromUtf8("CopyTo5"));

        horizontalLayout_23->addWidget(CopyTo5);

        ComboTo5 = new QComboBox(layoutWidget4);
        ComboTo5->addItem(QString());
        ComboTo5->addItem(QString());
        ComboTo5->addItem(QString());
        ComboTo5->addItem(QString());
        ComboTo5->addItem(QString());
        ComboTo5->addItem(QString());
        ComboTo5->addItem(QString());
        ComboTo5->setObjectName(QString::fromUtf8("ComboTo5"));

        horizontalLayout_23->addWidget(ComboTo5);


        gridLayout->addWidget(groupBox_6, 1, 1, 1, 1);

        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        layoutWidget_2 = new QWidget(groupBox);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(190, 70, 121, 51));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        level10 = new QSlider(layoutWidget_2);
        level10->setObjectName(QString::fromUtf8("level10"));
        level10->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(level10);

        level11 = new QSlider(layoutWidget_2);
        level11->setObjectName(QString::fromUtf8("level11"));
        level11->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(level11);

        level12 = new QSlider(layoutWidget_2);
        level12->setObjectName(QString::fromUtf8("level12"));
        level12->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(level12);

        level13 = new QSlider(layoutWidget_2);
        level13->setObjectName(QString::fromUtf8("level13"));
        level13->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(level13);

        layoutWidget5 = new QWidget(groupBox);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(30, 70, 121, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        rate10 = new QSlider(layoutWidget5);
        rate10->setObjectName(QString::fromUtf8("rate10"));
        rate10->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(rate10);

        rate11 = new QSlider(layoutWidget5);
        rate11->setObjectName(QString::fromUtf8("rate11"));
        rate11->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(rate11);

        rate12 = new QSlider(layoutWidget5);
        rate12->setObjectName(QString::fromUtf8("rate12"));
        rate12->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(rate12);

        rate13 = new QSlider(layoutWidget5);
        rate13->setObjectName(QString::fromUtf8("rate13"));
        rate13->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(rate13);

        layoutWidget6 = new QWidget(groupBox);
        layoutWidget6->setObjectName(QString::fromUtf8("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(20, 30, 291, 32));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        f1 = new QDoubleSpinBox(layoutWidget6);
        f1->setObjectName(QString::fromUtf8("f1"));
        f1->setSingleStep(0.100000000000000);
        f1->setValue(1.000000000000000);

        horizontalLayout_9->addWidget(f1);

        I1 = new QDoubleSpinBox(layoutWidget6);
        I1->setObjectName(QString::fromUtf8("I1"));
        I1->setMaximum(99.000000000000000);
        I1->setSingleStep(0.100000000000000);
        I1->setValue(1.000000000000000);

        horizontalLayout_9->addWidget(I1);

        d1 = new QDoubleSpinBox(layoutWidget6);
        d1->setObjectName(QString::fromUtf8("d1"));
        d1->setMinimum(-99.989999999999995);
        d1->setValue(7.000000000000000);

        horizontalLayout_9->addWidget(d1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(-10, 70, 50, 61));
        label_2->setTextFormat(Qt::RichText);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(true);
        label_2->setIndent(0);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(300, 60, 50, 81));
        label_3->setTextFormat(Qt::RichText);
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setWordWrap(true);
        label_3->setIndent(0);
        layoutWidget7 = new QWidget(groupBox);
        layoutWidget7->setObjectName(QString::fromUtf8("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(90, 120, 144, 34));
        horizontalLayout_17 = new QHBoxLayout(layoutWidget7);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalLayout_17->setContentsMargins(0, 0, 0, 0);
        CopyTo1 = new QPushButton(layoutWidget7);
        CopyTo1->setObjectName(QString::fromUtf8("CopyTo1"));

        horizontalLayout_17->addWidget(CopyTo1);

        ComboTo1 = new QComboBox(layoutWidget7);
        ComboTo1->addItem(QString());
        ComboTo1->addItem(QString());
        ComboTo1->addItem(QString());
        ComboTo1->addItem(QString());
        ComboTo1->addItem(QString());
        ComboTo1->addItem(QString());
        ComboTo1->addItem(QString());
        ComboTo1->setObjectName(QString::fromUtf8("ComboTo1"));

        horizontalLayout_17->addWidget(ComboTo1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        layoutWidget_5 = new QWidget(groupBox_3);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(200, 70, 121, 51));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        level30 = new QSlider(layoutWidget_5);
        level30->setObjectName(QString::fromUtf8("level30"));
        level30->setOrientation(Qt::Vertical);

        horizontalLayout_5->addWidget(level30);

        level31 = new QSlider(layoutWidget_5);
        level31->setObjectName(QString::fromUtf8("level31"));
        level31->setOrientation(Qt::Vertical);

        horizontalLayout_5->addWidget(level31);

        level32 = new QSlider(layoutWidget_5);
        level32->setObjectName(QString::fromUtf8("level32"));
        level32->setOrientation(Qt::Vertical);

        horizontalLayout_5->addWidget(level32);

        level33 = new QSlider(layoutWidget_5);
        level33->setObjectName(QString::fromUtf8("level33"));
        level33->setOrientation(Qt::Vertical);

        horizontalLayout_5->addWidget(level33);

        layoutWidget_6 = new QWidget(groupBox_3);
        layoutWidget_6->setObjectName(QString::fromUtf8("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(30, 70, 121, 51));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        rate30 = new QSlider(layoutWidget_6);
        rate30->setObjectName(QString::fromUtf8("rate30"));
        rate30->setOrientation(Qt::Vertical);

        horizontalLayout_6->addWidget(rate30);

        rate31 = new QSlider(layoutWidget_6);
        rate31->setObjectName(QString::fromUtf8("rate31"));
        rate31->setOrientation(Qt::Vertical);

        horizontalLayout_6->addWidget(rate31);

        rate32 = new QSlider(layoutWidget_6);
        rate32->setObjectName(QString::fromUtf8("rate32"));
        rate32->setOrientation(Qt::Vertical);

        horizontalLayout_6->addWidget(rate32);

        rate33 = new QSlider(layoutWidget_6);
        rate33->setObjectName(QString::fromUtf8("rate33"));
        rate33->setOrientation(Qt::Vertical);

        horizontalLayout_6->addWidget(rate33);

        layoutWidget8 = new QWidget(groupBox_3);
        layoutWidget8->setObjectName(QString::fromUtf8("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(30, 30, 271, 32));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget8);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        f3 = new QDoubleSpinBox(layoutWidget8);
        f3->setObjectName(QString::fromUtf8("f3"));
        f3->setSingleStep(0.100000000000000);
        f3->setValue(1.000000000000000);

        horizontalLayout_11->addWidget(f3);

        I3 = new QDoubleSpinBox(layoutWidget8);
        I3->setObjectName(QString::fromUtf8("I3"));
        I3->setSingleStep(0.100000000000000);
        I3->setValue(0.600000000000000);

        horizontalLayout_11->addWidget(I3);

        d3 = new QDoubleSpinBox(layoutWidget8);
        d3->setObjectName(QString::fromUtf8("d3"));
        d3->setMinimum(-99.989999999999995);
        d3->setValue(7.000000000000000);

        horizontalLayout_11->addWidget(d3);

        layoutWidget9 = new QWidget(groupBox_3);
        layoutWidget9->setObjectName(QString::fromUtf8("layoutWidget9"));
        layoutWidget9->setGeometry(QRect(100, 120, 144, 34));
        horizontalLayout_21 = new QHBoxLayout(layoutWidget9);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        horizontalLayout_21->setContentsMargins(0, 0, 0, 0);
        CopyTo3 = new QPushButton(layoutWidget9);
        CopyTo3->setObjectName(QString::fromUtf8("CopyTo3"));

        horizontalLayout_21->addWidget(CopyTo3);

        ComboTo3 = new QComboBox(layoutWidget9);
        ComboTo3->addItem(QString());
        ComboTo3->addItem(QString());
        ComboTo3->addItem(QString());
        ComboTo3->addItem(QString());
        ComboTo3->addItem(QString());
        ComboTo3->addItem(QString());
        ComboTo3->addItem(QString());
        ComboTo3->setObjectName(QString::fromUtf8("ComboTo3"));

        horizontalLayout_21->addWidget(ComboTo3);


        gridLayout->addWidget(groupBox_3, 0, 2, 1, 1);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        layoutWidget_3 = new QWidget(groupBox_2);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(30, 70, 121, 51));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        rate20 = new QSlider(layoutWidget_3);
        rate20->setObjectName(QString::fromUtf8("rate20"));
        rate20->setOrientation(Qt::Vertical);

        horizontalLayout_3->addWidget(rate20);

        rate21 = new QSlider(layoutWidget_3);
        rate21->setObjectName(QString::fromUtf8("rate21"));
        rate21->setOrientation(Qt::Vertical);

        horizontalLayout_3->addWidget(rate21);

        rate22 = new QSlider(layoutWidget_3);
        rate22->setObjectName(QString::fromUtf8("rate22"));
        rate22->setOrientation(Qt::Vertical);

        horizontalLayout_3->addWidget(rate22);

        rate23 = new QSlider(layoutWidget_3);
        rate23->setObjectName(QString::fromUtf8("rate23"));
        rate23->setOrientation(Qt::Vertical);

        horizontalLayout_3->addWidget(rate23);

        layoutWidget_4 = new QWidget(groupBox_2);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(190, 70, 121, 51));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        level20 = new QSlider(layoutWidget_4);
        level20->setObjectName(QString::fromUtf8("level20"));
        level20->setOrientation(Qt::Vertical);

        horizontalLayout_4->addWidget(level20);

        level21 = new QSlider(layoutWidget_4);
        level21->setObjectName(QString::fromUtf8("level21"));
        level21->setOrientation(Qt::Vertical);

        horizontalLayout_4->addWidget(level21);

        level22 = new QSlider(layoutWidget_4);
        level22->setObjectName(QString::fromUtf8("level22"));
        level22->setOrientation(Qt::Vertical);

        horizontalLayout_4->addWidget(level22);

        level23 = new QSlider(layoutWidget_4);
        level23->setObjectName(QString::fromUtf8("level23"));
        level23->setOrientation(Qt::Vertical);

        horizontalLayout_4->addWidget(level23);

        layoutWidget10 = new QWidget(groupBox_2);
        layoutWidget10->setObjectName(QString::fromUtf8("layoutWidget10"));
        layoutWidget10->setGeometry(QRect(20, 30, 281, 32));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget10);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        f2 = new QDoubleSpinBox(layoutWidget10);
        f2->setObjectName(QString::fromUtf8("f2"));
        f2->setSingleStep(0.100000000000000);
        f2->setValue(1.000000000000000);

        horizontalLayout_10->addWidget(f2);

        I2 = new QDoubleSpinBox(layoutWidget10);
        I2->setObjectName(QString::fromUtf8("I2"));
        I2->setMaximum(99.000000000000000);
        I2->setSingleStep(0.100000000000000);
        I2->setValue(0.700000000000000);

        horizontalLayout_10->addWidget(I2);

        d2 = new QDoubleSpinBox(layoutWidget10);
        d2->setObjectName(QString::fromUtf8("d2"));
        d2->setMinimum(-99.989999999999995);
        d2->setValue(7.000000000000000);

        horizontalLayout_10->addWidget(d2);

        layoutWidget11 = new QWidget(groupBox_2);
        layoutWidget11->setObjectName(QString::fromUtf8("layoutWidget11"));
        layoutWidget11->setGeometry(QRect(90, 120, 144, 34));
        horizontalLayout_20 = new QHBoxLayout(layoutWidget11);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        horizontalLayout_20->setContentsMargins(0, 0, 0, 0);
        CopyTo2 = new QPushButton(layoutWidget11);
        CopyTo2->setObjectName(QString::fromUtf8("CopyTo2"));

        horizontalLayout_20->addWidget(CopyTo2);

        ComboTo2 = new QComboBox(layoutWidget11);
        ComboTo2->addItem(QString());
        ComboTo2->addItem(QString());
        ComboTo2->addItem(QString());
        ComboTo2->addItem(QString());
        ComboTo2->addItem(QString());
        ComboTo2->addItem(QString());
        ComboTo2->addItem(QString());
        ComboTo2->setObjectName(QString::fromUtf8("ComboTo2"));

        horizontalLayout_20->addWidget(ComboTo2);


        gridLayout->addWidget(groupBox_2, 0, 1, 1, 1);

        groupBox_5 = new QGroupBox(layoutWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        layoutWidget_7 = new QWidget(groupBox_5);
        layoutWidget_7->setObjectName(QString::fromUtf8("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(20, 60, 121, 51));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_7);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        rate40 = new QSlider(layoutWidget_7);
        rate40->setObjectName(QString::fromUtf8("rate40"));
        rate40->setOrientation(Qt::Vertical);

        horizontalLayout_7->addWidget(rate40);

        rate41 = new QSlider(layoutWidget_7);
        rate41->setObjectName(QString::fromUtf8("rate41"));
        rate41->setOrientation(Qt::Vertical);

        horizontalLayout_7->addWidget(rate41);

        rate42 = new QSlider(layoutWidget_7);
        rate42->setObjectName(QString::fromUtf8("rate42"));
        rate42->setOrientation(Qt::Vertical);

        horizontalLayout_7->addWidget(rate42);

        rate43 = new QSlider(layoutWidget_7);
        rate43->setObjectName(QString::fromUtf8("rate43"));
        rate43->setOrientation(Qt::Vertical);

        horizontalLayout_7->addWidget(rate43);

        layoutWidget_8 = new QWidget(groupBox_5);
        layoutWidget_8->setObjectName(QString::fromUtf8("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(190, 60, 121, 51));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_8);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        level40 = new QSlider(layoutWidget_8);
        level40->setObjectName(QString::fromUtf8("level40"));
        level40->setOrientation(Qt::Vertical);

        horizontalLayout_8->addWidget(level40);

        level41 = new QSlider(layoutWidget_8);
        level41->setObjectName(QString::fromUtf8("level41"));
        level41->setOrientation(Qt::Vertical);

        horizontalLayout_8->addWidget(level41);

        level42 = new QSlider(layoutWidget_8);
        level42->setObjectName(QString::fromUtf8("level42"));
        level42->setOrientation(Qt::Vertical);

        horizontalLayout_8->addWidget(level42);

        level43 = new QSlider(layoutWidget_8);
        level43->setObjectName(QString::fromUtf8("level43"));
        level43->setOrientation(Qt::Vertical);

        horizontalLayout_8->addWidget(level43);

        layoutWidget12 = new QWidget(groupBox_5);
        layoutWidget12->setObjectName(QString::fromUtf8("layoutWidget12"));
        layoutWidget12->setGeometry(QRect(10, 20, 291, 32));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget12);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        f4 = new QDoubleSpinBox(layoutWidget12);
        f4->setObjectName(QString::fromUtf8("f4"));
        f4->setSingleStep(0.100000000000000);
        f4->setValue(1.000000000000000);

        horizontalLayout_12->addWidget(f4);

        I4 = new QDoubleSpinBox(layoutWidget12);
        I4->setObjectName(QString::fromUtf8("I4"));
        I4->setSingleStep(0.100000000000000);
        I4->setValue(1.000000000000000);

        horizontalLayout_12->addWidget(I4);

        d4 = new QDoubleSpinBox(layoutWidget12);
        d4->setObjectName(QString::fromUtf8("d4"));
        d4->setMinimum(-99.989999999999995);
        d4->setValue(7.000000000000000);

        horizontalLayout_12->addWidget(d4);

        layoutWidget13 = new QWidget(groupBox_5);
        layoutWidget13->setObjectName(QString::fromUtf8("layoutWidget13"));
        layoutWidget13->setGeometry(QRect(100, 110, 144, 34));
        horizontalLayout_22 = new QHBoxLayout(layoutWidget13);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(0, 0, 0, 0);
        CopyTo4 = new QPushButton(layoutWidget13);
        CopyTo4->setObjectName(QString::fromUtf8("CopyTo4"));

        horizontalLayout_22->addWidget(CopyTo4);

        ComboTo4 = new QComboBox(layoutWidget13);
        ComboTo4->addItem(QString());
        ComboTo4->addItem(QString());
        ComboTo4->addItem(QString());
        ComboTo4->addItem(QString());
        ComboTo4->addItem(QString());
        ComboTo4->addItem(QString());
        ComboTo4->addItem(QString());
        ComboTo4->setObjectName(QString::fromUtf8("ComboTo4"));

        horizontalLayout_22->addWidget(ComboTo4);


        gridLayout->addWidget(groupBox_5, 1, 0, 1, 1);

        plotFrame = new QWidget(FM_Dialog);
        plotFrame->setObjectName(QString::fromUtf8("plotFrame"));
        plotFrame->setGeometry(QRect(660, 0, 381, 111));
        label_4 = new QLabel(FM_Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(450, 85, 51, 31));
        label_4->setFrameShape(QFrame::Box);
        algosvg = new SvgWidget(FM_Dialog);
        algosvg->setObjectName(QString::fromUtf8("algosvg"));
        algosvg->setGeometry(QRect(149, 9, 291, 101));
        OSC = new QCheckBox(FM_Dialog);
        OSC->setObjectName(QString::fromUtf8("OSC"));
        OSC->setGeometry(QRect(510, 90, 51, 20));
        comboBox_2 = new QComboBox(FM_Dialog);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(560, 84, 41, 30));
        layoutWidget14 = new QWidget(FM_Dialog);
        layoutWidget14->setObjectName(QString::fromUtf8("layoutWidget14"));
        layoutWidget14->setGeometry(QRect(480, 20, 176, 72));
        gridLayout_2 = new QGridLayout(layoutWidget14);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        test1 = new QPushButton(layoutWidget14);
        test1->setObjectName(QString::fromUtf8("test1"));

        gridLayout_2->addWidget(test1, 0, 0, 1, 1);

        test2 = new QPushButton(layoutWidget14);
        test2->setObjectName(QString::fromUtf8("test2"));

        gridLayout_2->addWidget(test2, 0, 1, 1, 1);

        test1_2 = new QPushButton(layoutWidget14);
        test1_2->setObjectName(QString::fromUtf8("test1_2"));

        gridLayout_2->addWidget(test1_2, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget14);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout_2->addWidget(pushButton_3, 1, 1, 1, 1);

        label_5 = new QLabel(FM_Dialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 450, 50, 16));
        widget = new QWidget(FM_Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(130, 450, 161, 22));
        horizontalLayout_25 = new QHBoxLayout(widget);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        horizontalLayout_25->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_25->addWidget(label_6);

        pichMod = new QSlider(widget);
        pichMod->setObjectName(QString::fromUtf8("pichMod"));
        pichMod->setOrientation(Qt::Horizontal);

        horizontalLayout_25->addWidget(pichMod);

        widget1 = new QWidget(FM_Dialog);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(320, 450, 121, 22));
        horizontalLayout_26 = new QHBoxLayout(widget1);
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        horizontalLayout_26->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_26->addWidget(label_7);

        delay = new QSlider(widget1);
        delay->setObjectName(QString::fromUtf8("delay"));
        delay->setOrientation(Qt::Horizontal);

        horizontalLayout_26->addWidget(delay);


        retranslateUi(FM_Dialog);

        QMetaObject::connectSlotsByName(FM_Dialog);
    } // setupUi

    void retranslateUi(QDialog *FM_Dialog)
    {
        FM_Dialog->setWindowTitle(QApplication::translate("FM_Dialog", "Dialog", nullptr));
        comboBox->setItemText(0, QApplication::translate("FM_Dialog", "bass1", nullptr));
        comboBox->setItemText(1, QApplication::translate("FM_Dialog", "bass2", nullptr));
        comboBox->setItemText(2, QApplication::translate("FM_Dialog", "orchestra", nullptr));
        comboBox->setItemText(3, QApplication::translate("FM_Dialog", "E.organ1", nullptr));
        comboBox->setItemText(4, QApplication::translate("FM_Dialog", "E.piano", nullptr));
        comboBox->setItemText(5, QApplication::translate("FM_Dialog", "piano1", nullptr));
        comboBox->setItemText(6, QApplication::translate("FM_Dialog", "piano2", nullptr));

        algoCombo->setItemText(0, QApplication::translate("FM_Dialog", "1", nullptr));
        algoCombo->setItemText(1, QApplication::translate("FM_Dialog", "2", nullptr));
        algoCombo->setItemText(2, QApplication::translate("FM_Dialog", "3", nullptr));
        algoCombo->setItemText(3, QApplication::translate("FM_Dialog", "4", nullptr));
        algoCombo->setItemText(4, QApplication::translate("FM_Dialog", "5", nullptr));
        algoCombo->setItemText(5, QApplication::translate("FM_Dialog", "6", nullptr));
        algoCombo->setItemText(6, QApplication::translate("FM_Dialog", "7", nullptr));
        algoCombo->setItemText(7, QApplication::translate("FM_Dialog", "8", nullptr));
        algoCombo->setItemText(8, QApplication::translate("FM_Dialog", "9", nullptr));
        algoCombo->setItemText(9, QApplication::translate("FM_Dialog", "10", nullptr));
        algoCombo->setItemText(10, QApplication::translate("FM_Dialog", "11", nullptr));
        algoCombo->setItemText(11, QApplication::translate("FM_Dialog", "12", nullptr));
        algoCombo->setItemText(12, QApplication::translate("FM_Dialog", "13", nullptr));
        algoCombo->setItemText(13, QApplication::translate("FM_Dialog", "14", nullptr));
        algoCombo->setItemText(14, QApplication::translate("FM_Dialog", "15", nullptr));
        algoCombo->setItemText(15, QApplication::translate("FM_Dialog", "16", nullptr));
        algoCombo->setItemText(16, QApplication::translate("FM_Dialog", "17", nullptr));
        algoCombo->setItemText(17, QApplication::translate("FM_Dialog", "18", nullptr));
        algoCombo->setItemText(18, QApplication::translate("FM_Dialog", "19", nullptr));
        algoCombo->setItemText(19, QApplication::translate("FM_Dialog", "20", nullptr));
        algoCombo->setItemText(20, QApplication::translate("FM_Dialog", "21", nullptr));
        algoCombo->setItemText(21, QApplication::translate("FM_Dialog", "22", nullptr));
        algoCombo->setItemText(22, QApplication::translate("FM_Dialog", "23", nullptr));
        algoCombo->setItemText(23, QApplication::translate("FM_Dialog", "24", nullptr));
        algoCombo->setItemText(24, QApplication::translate("FM_Dialog", "25", nullptr));
        algoCombo->setItemText(25, QApplication::translate("FM_Dialog", "26", nullptr));
        algoCombo->setItemText(26, QApplication::translate("FM_Dialog", "27", nullptr));
        algoCombo->setItemText(27, QApplication::translate("FM_Dialog", "28", nullptr));
        algoCombo->setItemText(28, QApplication::translate("FM_Dialog", "29", nullptr));
        algoCombo->setItemText(29, QApplication::translate("FM_Dialog", "30", nullptr));
        algoCombo->setItemText(30, QApplication::translate("FM_Dialog", "31", nullptr));
        algoCombo->setItemText(31, QApplication::translate("FM_Dialog", "32", nullptr));

        label->setText(QApplication::translate("FM_Dialog", "Alogithm", nullptr));
        groupBox_7->setTitle(QApplication::translate("FM_Dialog", "6", nullptr));
        f6->setPrefix(QApplication::translate("FM_Dialog", "f=", nullptr));
        I6->setPrefix(QApplication::translate("FM_Dialog", "I=", nullptr));
        d6->setPrefix(QApplication::translate("FM_Dialog", "d=", nullptr));
        CopyTo6->setText(QApplication::translate("FM_Dialog", "CopyTo", nullptr));
        ComboTo6->setItemText(0, QApplication::translate("FM_Dialog", "All", nullptr));
        ComboTo6->setItemText(1, QApplication::translate("FM_Dialog", "1", nullptr));
        ComboTo6->setItemText(2, QApplication::translate("FM_Dialog", "2", nullptr));
        ComboTo6->setItemText(3, QApplication::translate("FM_Dialog", "3", nullptr));
        ComboTo6->setItemText(4, QApplication::translate("FM_Dialog", "4", nullptr));
        ComboTo6->setItemText(5, QApplication::translate("FM_Dialog", "5", nullptr));
        ComboTo6->setItemText(6, QApplication::translate("FM_Dialog", "6", nullptr));

        groupBox_6->setTitle(QApplication::translate("FM_Dialog", "5", nullptr));
        f5->setPrefix(QApplication::translate("FM_Dialog", "f=", nullptr));
        I5->setPrefix(QApplication::translate("FM_Dialog", "I=", nullptr));
        d5->setPrefix(QApplication::translate("FM_Dialog", "d=", nullptr));
        CopyTo5->setText(QApplication::translate("FM_Dialog", "CopyTo", nullptr));
        ComboTo5->setItemText(0, QApplication::translate("FM_Dialog", "All", nullptr));
        ComboTo5->setItemText(1, QApplication::translate("FM_Dialog", "1", nullptr));
        ComboTo5->setItemText(2, QApplication::translate("FM_Dialog", "2", nullptr));
        ComboTo5->setItemText(3, QApplication::translate("FM_Dialog", "3", nullptr));
        ComboTo5->setItemText(4, QApplication::translate("FM_Dialog", "4", nullptr));
        ComboTo5->setItemText(5, QApplication::translate("FM_Dialog", "5", nullptr));
        ComboTo5->setItemText(6, QApplication::translate("FM_Dialog", "6", nullptr));

        groupBox->setTitle(QApplication::translate("FM_Dialog", "1", nullptr));
        f1->setPrefix(QApplication::translate("FM_Dialog", "f=", nullptr));
        I1->setPrefix(QApplication::translate("FM_Dialog", "I=", nullptr));
        d1->setPrefix(QApplication::translate("FM_Dialog", "d=", nullptr));
        label_2->setText(QApplication::translate("FM_Dialog", "<html><head/><body><p>R<br/>A<br/>T<br/>E</p></body></html>", nullptr));
        label_3->setText(QApplication::translate("FM_Dialog", "<html><head/><body><p>L<br/>E<br/>V<br/>E<br/>L</p></body></html>", nullptr));
        CopyTo1->setText(QApplication::translate("FM_Dialog", "CopyTo", nullptr));
        ComboTo1->setItemText(0, QApplication::translate("FM_Dialog", "All", nullptr));
        ComboTo1->setItemText(1, QApplication::translate("FM_Dialog", "1", nullptr));
        ComboTo1->setItemText(2, QApplication::translate("FM_Dialog", "2", nullptr));
        ComboTo1->setItemText(3, QApplication::translate("FM_Dialog", "3", nullptr));
        ComboTo1->setItemText(4, QApplication::translate("FM_Dialog", "4", nullptr));
        ComboTo1->setItemText(5, QApplication::translate("FM_Dialog", "5", nullptr));
        ComboTo1->setItemText(6, QApplication::translate("FM_Dialog", "6", nullptr));

        groupBox_3->setTitle(QApplication::translate("FM_Dialog", "3", nullptr));
        f3->setPrefix(QApplication::translate("FM_Dialog", "f=", nullptr));
        I3->setPrefix(QApplication::translate("FM_Dialog", "I=", nullptr));
        d3->setPrefix(QApplication::translate("FM_Dialog", "d=", nullptr));
        CopyTo3->setText(QApplication::translate("FM_Dialog", "CopyTo", nullptr));
        ComboTo3->setItemText(0, QApplication::translate("FM_Dialog", "All", nullptr));
        ComboTo3->setItemText(1, QApplication::translate("FM_Dialog", "1", nullptr));
        ComboTo3->setItemText(2, QApplication::translate("FM_Dialog", "2", nullptr));
        ComboTo3->setItemText(3, QApplication::translate("FM_Dialog", "3", nullptr));
        ComboTo3->setItemText(4, QApplication::translate("FM_Dialog", "4", nullptr));
        ComboTo3->setItemText(5, QApplication::translate("FM_Dialog", "5", nullptr));
        ComboTo3->setItemText(6, QApplication::translate("FM_Dialog", "6", nullptr));

        groupBox_2->setTitle(QApplication::translate("FM_Dialog", "2", nullptr));
        f2->setPrefix(QApplication::translate("FM_Dialog", "f=", nullptr));
        I2->setPrefix(QApplication::translate("FM_Dialog", "I=", nullptr));
        d2->setPrefix(QApplication::translate("FM_Dialog", "d=", nullptr));
        CopyTo2->setText(QApplication::translate("FM_Dialog", "CopyTo", nullptr));
        ComboTo2->setItemText(0, QApplication::translate("FM_Dialog", "All", nullptr));
        ComboTo2->setItemText(1, QApplication::translate("FM_Dialog", "1", nullptr));
        ComboTo2->setItemText(2, QApplication::translate("FM_Dialog", "2", nullptr));
        ComboTo2->setItemText(3, QApplication::translate("FM_Dialog", "3", nullptr));
        ComboTo2->setItemText(4, QApplication::translate("FM_Dialog", "4", nullptr));
        ComboTo2->setItemText(5, QApplication::translate("FM_Dialog", "5", nullptr));
        ComboTo2->setItemText(6, QApplication::translate("FM_Dialog", "6", nullptr));

        groupBox_5->setTitle(QApplication::translate("FM_Dialog", "4", nullptr));
        f4->setPrefix(QApplication::translate("FM_Dialog", "f=", nullptr));
        I4->setPrefix(QApplication::translate("FM_Dialog", "I=", nullptr));
        d4->setPrefix(QApplication::translate("FM_Dialog", "d=", nullptr));
        CopyTo4->setText(QApplication::translate("FM_Dialog", "CopyTo", nullptr));
        ComboTo4->setItemText(0, QApplication::translate("FM_Dialog", "All", nullptr));
        ComboTo4->setItemText(1, QApplication::translate("FM_Dialog", "1", nullptr));
        ComboTo4->setItemText(2, QApplication::translate("FM_Dialog", "2", nullptr));
        ComboTo4->setItemText(3, QApplication::translate("FM_Dialog", "3", nullptr));
        ComboTo4->setItemText(4, QApplication::translate("FM_Dialog", "4", nullptr));
        ComboTo4->setItemText(5, QApplication::translate("FM_Dialog", "5", nullptr));
        ComboTo4->setItemText(6, QApplication::translate("FM_Dialog", "6", nullptr));

        label_4->setText(QApplication::translate("FM_Dialog", "<html><head/><body><p><span style=\" font-size:16pt;\">344</span></p></body></html>", nullptr));
        OSC->setText(QApplication::translate("FM_Dialog", "OSC", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("FM_Dialog", "all", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("FM_Dialog", "1", nullptr));
        comboBox_2->setItemText(2, QApplication::translate("FM_Dialog", "2", nullptr));
        comboBox_2->setItemText(3, QApplication::translate("FM_Dialog", "3", nullptr));
        comboBox_2->setItemText(4, QApplication::translate("FM_Dialog", "4", nullptr));
        comboBox_2->setItemText(5, QApplication::translate("FM_Dialog", "5", nullptr));
        comboBox_2->setItemText(6, QApplication::translate("FM_Dialog", "6", nullptr));

        test1->setText(QApplication::translate("FM_Dialog", "TEST1", nullptr));
        test2->setText(QApplication::translate("FM_Dialog", "TEST2", nullptr));
        test1_2->setText(QApplication::translate("FM_Dialog", "TEST4", nullptr));
        pushButton_3->setText(QApplication::translate("FM_Dialog", "TEST3", nullptr));
        label_5->setText(QApplication::translate("FM_Dialog", "LFO", nullptr));
        label_6->setText(QApplication::translate("FM_Dialog", "Pich Mod", nullptr));
        label_7->setText(QApplication::translate("FM_Dialog", "Delay", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FM_Dialog: public Ui_FM_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FM_DIALOG_H
