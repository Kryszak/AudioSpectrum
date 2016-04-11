/********************************************************************************
** Form generated from reading UI file 'MWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MWINDOW_H
#define UI_MWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MWindow
{
public:
    QPushButton *PlayButton;
    QPushButton *PauseButton;
    QPushButton *StopButton;
    QFrame *frame;
    QLabel *fileNameLabel;
    QPushButton *LoadButton;
    QGraphicsView *graphicsView;

    void setupUi(QDialog *MWindow)
    {
        if (MWindow->objectName().isEmpty())
            MWindow->setObjectName(QStringLiteral("MWindow"));
        MWindow->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MWindow->sizePolicy().hasHeightForWidth());
        MWindow->setSizePolicy(sizePolicy);
        MWindow->setMinimumSize(QSize(400, 300));
        MWindow->setMaximumSize(QSize(400, 300));
        PlayButton = new QPushButton(MWindow);
        PlayButton->setObjectName(QStringLiteral("PlayButton"));
        PlayButton->setGeometry(QRect(0, 250, 51, 51));
        PlayButton->setMaximumSize(QSize(51, 51));
        PlayButton->setStyleSheet(QLatin1String("background-image: url(img/play.png); background-position: center;\n"
"background-color: rgb(14, 144, 0);"));
        PauseButton = new QPushButton(MWindow);
        PauseButton->setObjectName(QStringLiteral("PauseButton"));
        PauseButton->setGeometry(QRect(70, 250, 51, 51));
        PauseButton->setStyleSheet(QLatin1String("background-image: url(img/pause.png); background-position:center; \n"
"background-color: rgb(14, 144, 0);"));
        StopButton = new QPushButton(MWindow);
        StopButton->setObjectName(QStringLiteral("StopButton"));
        StopButton->setGeometry(QRect(140, 250, 51, 51));
        StopButton->setStyleSheet(QLatin1String("background-image: url(img/stop.png);\n"
"background-color: rgb(14, 144, 0);"));
        frame = new QFrame(MWindow);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 210, 401, 91));
        frame->setStyleSheet(QStringLiteral("background-image: url(img/background.jpg)"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        fileNameLabel = new QLabel(frame);
        fileNameLabel->setObjectName(QStringLiteral("fileNameLabel"));
        fileNameLabel->setGeometry(QRect(90, 0, 301, 21));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Light, brush);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush);
        QBrush brush1(QColor(127, 127, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
        QBrush brush2(QColor(170, 170, 170, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush2);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush3);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush3);
        fileNameLabel->setPalette(palette);
        LoadButton = new QPushButton(MWindow);
        LoadButton->setObjectName(QStringLiteral("LoadButton"));
        LoadButton->setGeometry(QRect(0, 210, 75, 23));
        LoadButton->setStyleSheet(QLatin1String("background-color: rgb(14, 144, 0);\n"
"color: rgb(255, 255, 255);"));
        graphicsView = new QGraphicsView(MWindow);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 400, 211));
        graphicsView->setMinimumSize(QSize(400, 211));
        graphicsView->setMaximumSize(QSize(400, 211));
        graphicsView->setFocusPolicy(Qt::NoFocus);
        frame->raise();
        LoadButton->raise();
        StopButton->raise();
        PlayButton->raise();
        PauseButton->raise();
        graphicsView->raise();

        retranslateUi(MWindow);

        QMetaObject::connectSlotsByName(MWindow);
    } // setupUi

    void retranslateUi(QDialog *MWindow)
    {
        MWindow->setWindowTitle(QApplication::translate("MWindow", "MWindow", 0));
        PlayButton->setText(QString());
        PauseButton->setText(QString());
        StopButton->setText(QString());
        fileNameLabel->setText(QApplication::translate("MWindow", "TextLabel", 0));
        LoadButton->setText(QApplication::translate("MWindow", "Load File", 0));
    } // retranslateUi

};

namespace Ui {
    class MWindow: public Ui_MWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MWINDOW_H
