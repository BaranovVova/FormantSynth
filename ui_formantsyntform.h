/********************************************************************************
** Form generated from reading UI file 'formantsyntform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMANTSYNTFORM_H
#define UI_FORMANTSYNTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FormantSyntForm
{
public:
    QGroupBox *groupBox;
    QPushButton *genButton;
    QDoubleSpinBox *f_ot;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *Abutton;
    QPushButton *Ibutton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QDoubleSpinBox *F;
    QLabel *label_5;
    QLabel *label_7;
    QDoubleSpinBox *BW;
    QLabel *label_8;
    QDoubleSpinBox *Ncascade;
    QPushButton *hbSongButton;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QLabel *label_9;
    QDoubleSpinBox *F1;
    QLabel *label_10;
    QLabel *label_11;
    QDoubleSpinBox *F2;
    QLabel *label_12;
    QLabel *label_13;
    QDoubleSpinBox *F3;
    QLabel *label_14;
    QPushButton *Ebutton;
    QPushButton *Ubut;
    QProgressBar *progressBar;
    QPushButton *hbSongButton_2;

    void setupUi(QDialog *FormantSyntForm)
    {
        if (FormantSyntForm->objectName().isEmpty())
            FormantSyntForm->setObjectName(QString::fromUtf8("FormantSyntForm"));
        FormantSyntForm->resize(683, 255);
        groupBox = new QGroupBox(FormantSyntForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 281, 121));
        genButton = new QPushButton(groupBox);
        genButton->setObjectName(QString::fromUtf8("genButton"));
        genButton->setGeometry(QRect(22, 60, 231, 23));
        f_ot = new QDoubleSpinBox(groupBox);
        f_ot->setObjectName(QString::fromUtf8("f_ot"));
        f_ot->setGeometry(QRect(140, 30, 81, 22));
        f_ot->setMaximum(10000000.000000000000000);
        f_ot->setValue(80.000000000000000);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 31, 121, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(230, 33, 46, 13));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 90, 91, 23));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 90, 151, 23));
        Abutton = new QPushButton(FormantSyntForm);
        Abutton->setObjectName(QString::fromUtf8("Abutton"));
        Abutton->setGeometry(QRect(10, 140, 75, 23));
        Ibutton = new QPushButton(FormantSyntForm);
        Ibutton->setObjectName(QString::fromUtf8("Ibutton"));
        Ibutton->setGeometry(QRect(100, 140, 75, 23));
        groupBox_2 = new QGroupBox(FormantSyntForm);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(300, 10, 181, 121));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        F = new QDoubleSpinBox(groupBox_2);
        F->setObjectName(QString::fromUtf8("F"));
        F->setMaximum(10000000.000000000000000);
        F->setValue(800.000000000000000);

        gridLayout->addWidget(F, 0, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        BW = new QDoubleSpinBox(groupBox_2);
        BW->setObjectName(QString::fromUtf8("BW"));
        BW->setDecimals(10);
        BW->setMaximum(10000000.000000000000000);
        BW->setSingleStep(0.000001000000000);
        BW->setValue(0.006600000000000);

        gridLayout->addWidget(BW, 1, 1, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        Ncascade = new QDoubleSpinBox(groupBox_2);
        Ncascade->setObjectName(QString::fromUtf8("Ncascade"));
        Ncascade->setMaximum(10000000.000000000000000);
        Ncascade->setValue(5.000000000000000);

        gridLayout->addWidget(Ncascade, 2, 1, 1, 1);

        hbSongButton = new QPushButton(FormantSyntForm);
        hbSongButton->setObjectName(QString::fromUtf8("hbSongButton"));
        hbSongButton->setGeometry(QRect(510, 170, 161, 32));
        groupBox_3 = new QGroupBox(FormantSyntForm);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(490, 10, 161, 121));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 0, 0, 1, 1);

        F1 = new QDoubleSpinBox(groupBox_3);
        F1->setObjectName(QString::fromUtf8("F1"));
        F1->setMaximum(10000000.000000000000000);
        F1->setValue(660.000000000000000);

        gridLayout_2->addWidget(F1, 0, 1, 1, 1);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 0, 2, 1, 1);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 1, 0, 1, 1);

        F2 = new QDoubleSpinBox(groupBox_3);
        F2->setObjectName(QString::fromUtf8("F2"));
        F2->setMaximum(10000000.000000000000000);
        F2->setValue(1700.000000000000000);

        gridLayout_2->addWidget(F2, 1, 1, 1, 1);

        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 1, 2, 1, 1);

        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 2, 0, 1, 1);

        F3 = new QDoubleSpinBox(groupBox_3);
        F3->setObjectName(QString::fromUtf8("F3"));
        F3->setMaximum(10000000.000000000000000);
        F3->setValue(2400.000000000000000);

        gridLayout_2->addWidget(F3, 2, 1, 1, 1);

        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_2->addWidget(label_14, 2, 2, 1, 1);

        Ebutton = new QPushButton(FormantSyntForm);
        Ebutton->setObjectName(QString::fromUtf8("Ebutton"));
        Ebutton->setGeometry(QRect(190, 140, 75, 23));
        Ubut = new QPushButton(FormantSyntForm);
        Ubut->setObjectName(QString::fromUtf8("Ubut"));
        Ubut->setGeometry(QRect(280, 140, 75, 23));
        progressBar = new QProgressBar(FormantSyntForm);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(510, 140, 161, 23));
        progressBar->setValue(0);
        hbSongButton_2 = new QPushButton(FormantSyntForm);
        hbSongButton_2->setObjectName(QString::fromUtf8("hbSongButton_2"));
        hbSongButton_2->setEnabled(false);
        hbSongButton_2->setGeometry(QRect(510, 210, 161, 32));

        retranslateUi(FormantSyntForm);

        QMetaObject::connectSlotsByName(FormantSyntForm);
    } // setupUi

    void retranslateUi(QDialog *FormantSyntForm)
    {
        FormantSyntForm->setWindowTitle(QApplication::translate("FormantSyntForm", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("FormantSyntForm", "Generator", nullptr));
        genButton->setText(QApplication::translate("FormantSyntForm", "Generate", nullptr));
        label_3->setText(QApplication::translate("FormantSyntForm", "f \320\276\321\201\320\275\320\276\320\262\320\275\320\276\320\263\320\276 \321\202\320\276\320\275\320\260", nullptr));
        label_4->setText(QApplication::translate("FormantSyntForm", "\320\223\321\206", nullptr));
        pushButton->setText(QApplication::translate("FormantSyntForm", "pulse.wav", nullptr));
        pushButton_2->setText(QApplication::translate("FormantSyntForm", "pulse_filtered.wav", nullptr));
        Abutton->setText(QApplication::translate("FormantSyntForm", "A", nullptr));
        Ibutton->setText(QApplication::translate("FormantSyntForm", "\320\230", nullptr));
        groupBox_2->setTitle(QApplication::translate("FormantSyntForm", "Band pass filter", nullptr));
        label_6->setText(QApplication::translate("FormantSyntForm", "F", nullptr));
        label_5->setText(QApplication::translate("FormantSyntForm", "\320\223\321\206", nullptr));
        label_7->setText(QApplication::translate("FormantSyntForm", "BW", nullptr));
        label_8->setText(QApplication::translate("FormantSyntForm", "Ncascad", nullptr));
        hbSongButton->setText(QApplication::translate("FormantSyntForm", "Happy Birsday Synt", nullptr));
        groupBox_3->setTitle(QApplication::translate("FormantSyntForm", "Formants", nullptr));
        label_9->setText(QApplication::translate("FormantSyntForm", "F1", nullptr));
        label_10->setText(QApplication::translate("FormantSyntForm", "\320\223\321\206", nullptr));
        label_11->setText(QApplication::translate("FormantSyntForm", "F2", nullptr));
        label_12->setText(QApplication::translate("FormantSyntForm", "\320\223\321\206", nullptr));
        label_13->setText(QApplication::translate("FormantSyntForm", "F3", nullptr));
        label_14->setText(QApplication::translate("FormantSyntForm", "\320\223\321\206", nullptr));
        Ebutton->setText(QApplication::translate("FormantSyntForm", "\320\255", nullptr));
        Ubut->setText(QApplication::translate("FormantSyntForm", "\320\243", nullptr));
        hbSongButton_2->setText(QApplication::translate("FormantSyntForm", "Happy Birsday Wave ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormantSyntForm: public Ui_FormantSyntForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMANTSYNTFORM_H
