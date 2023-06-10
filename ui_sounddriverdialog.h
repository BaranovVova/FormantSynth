/********************************************************************************
** Form generated from reading UI file 'sounddriverdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOUNDDRIVERDIALOG_H
#define UI_SOUNDDRIVERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_SoundDriverDialog
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *testButton;
    QComboBox *comboBox;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SoundDriverDialog)
    {
        if (SoundDriverDialog->objectName().isEmpty())
            SoundDriverDialog->setObjectName(QString::fromUtf8("SoundDriverDialog"));
        SoundDriverDialog->resize(411, 331);
        gridLayout_2 = new QGridLayout(SoundDriverDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(SoundDriverDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        testButton = new QPushButton(groupBox);
        testButton->setObjectName(QString::fromUtf8("testButton"));

        gridLayout->addWidget(testButton, 1, 3, 1, 1);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 0, 3, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(113, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setWordWrap(true);

        gridLayout->addWidget(label_2, 2, 1, 1, 3);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(SoundDriverDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(SoundDriverDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SoundDriverDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SoundDriverDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SoundDriverDialog);
    } // setupUi

    void retranslateUi(QDialog *SoundDriverDialog)
    {
        SoundDriverDialog->setWindowTitle(QApplication::translate("SoundDriverDialog", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("SoundDriverDialog", "Alsa driver settings", nullptr));
        testButton->setText(QApplication::translate("SoundDriverDialog", "Test", nullptr));
        label->setText(QApplication::translate("SoundDriverDialog", "device name", nullptr));
        label_2->setText(QApplication::translate("SoundDriverDialog", "<html><head/><body><p><span style=\" color:#008000;\">Select your sound card to use FormantSynth in single voice mode.If you want to use it in multiple voices (polyphony) use device &quot;plug:dmix&quot; wich is a mixer device. How to setup mixer device you can read in README.md file. </span></p><p><span style=\" color:#f90004;\">Your need to restart FormantSynth to apply settings</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SoundDriverDialog: public Ui_SoundDriverDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOUNDDRIVERDIALOG_H
