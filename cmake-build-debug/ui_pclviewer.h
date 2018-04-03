/********************************************************************************
** Form generated from reading UI file 'pclviewer.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCLVIEWER_H
#define UI_PCLVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMdiArea>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_PCLViewer
{
public:
    QAction *OpenAction;
    QAction *SaveAction;
    QAction *SimplyAction;
    QAction *MlsAction;
    QAction *ReconstructAction;
    QAction *SurfaceAction;
    QAction *ResetAction;
    QAction *NormalAction;
    QAction *CleraAction;
    QAction *CoordinateAction;
    QAction *BackgroudAction;
    QAction *VerticesAction;
    QAction *HideAction;
    QAction *ConfigurationAction;
    QAction *SelectAction;
    QAction *RGBCloudAction;
    QAction *XYZCloudAction;
    QAction *ReconstructRealTimeAction;
    QAction *FillholeAction;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QMdiArea *mdiArea;
    QWidget *subwindow;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QVTKWidget *qvtkWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QProgressBar *progressBar;
    QMenuBar *menuBar;
    QMenu *menu_F;
    QMenu *menu;
    QMenu *menuKinect;
    QMenu *menu_E;
    QMenu *menu_V;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *ShowDockWidget;
    QWidget *dockWidgetContents;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLCDNumber *PointsNumber;
    QSpacerItem *verticalSpacer_9;
    QTextBrowser *textBrowser;
    QDockWidget *OperateDockWidget;
    QWidget *dockWidgetContents_2;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QSpacerItem *verticalSpacer_5;
    QSlider *KtreeSlider;
    QSpacerItem *verticalSpacer_7;
    QPushButton *MLSButton;
    QSpacerItem *verticalSpacer_8;
    QPushButton *DownSampingButton;
    QSpacerItem *verticalSpacer_4;
    QPushButton *ReconstructButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *BuildButton;
    QSpacerItem *verticalSpacer;
    QPushButton *FilterButton;
    QSpacerItem *verticalSpacer_6;
    QPushButton *ResetButton;
    QSpacerItem *verticalSpacer_3;
    QPushButton *ClearButton;
    QDockWidget *ConfigurDockWidget;
    QWidget *dockWidgetContents_3;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *Background_groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QSlider *Slider_Backgroud_R;
    QLabel *label_3;
    QLCDNumber *lcdNumber_2;
    QHBoxLayout *horizontalLayout_6;
    QSlider *Slider_Background_G;
    QLabel *label_4;
    QLCDNumber *lcdNumber_3;
    QHBoxLayout *horizontalLayout_7;
    QSlider *Slide_Background_B;
    QLabel *label_5;
    QLCDNumber *lcdNumber_4;
    QSpacerItem *verticalSpacer_10;
    QGroupBox *Point_Box;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_8;
    QSlider *horizontalSlider_4;
    QLabel *label_6;
    QLCDNumber *lcdNumber_5;
    QHBoxLayout *horizontalLayout_9;
    QSlider *horizontalSlider_5;
    QLabel *label_7;
    QLCDNumber *lcdNumber_6;
    QHBoxLayout *horizontalLayout_10;
    QSlider *horizontalSlider_6;
    QLabel *label_8;
    QLCDNumber *lcdNumber_7;
    QGroupBox *Leng_roupBox;
    QSlider *NormallenSlider;
    QLCDNumber *lcdNumber_8;
    QSlider *NormalPointNumber;
    QLabel *label_9;

    void setupUi(QMainWindow *PCLViewer)
    {
        if (PCLViewer->objectName().isEmpty())
            PCLViewer->setObjectName(QString::fromUtf8("PCLViewer"));
        PCLViewer->resize(1373, 899);
        OpenAction = new QAction(PCLViewer);
        OpenAction->setObjectName(QString::fromUtf8("OpenAction"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        OpenAction->setIcon(icon);
        SaveAction = new QAction(PCLViewer);
        SaveAction->setObjectName(QString::fromUtf8("SaveAction"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        SaveAction->setIcon(icon1);
        SimplyAction = new QAction(PCLViewer);
        SimplyAction->setObjectName(QString::fromUtf8("SimplyAction"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/image/points.png"), QSize(), QIcon::Normal, QIcon::Off);
        SimplyAction->setIcon(icon2);
        MlsAction = new QAction(PCLViewer);
        MlsAction->setObjectName(QString::fromUtf8("MlsAction"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/image/smooth.png"), QSize(), QIcon::Normal, QIcon::Off);
        MlsAction->setIcon(icon3);
        ReconstructAction = new QAction(PCLViewer);
        ReconstructAction->setObjectName(QString::fromUtf8("ReconstructAction"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/image/wire.png"), QSize(), QIcon::Normal, QIcon::Off);
        ReconstructAction->setIcon(icon4);
        SurfaceAction = new QAction(PCLViewer);
        SurfaceAction->setObjectName(QString::fromUtf8("SurfaceAction"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/image/flatlines.png"), QSize(), QIcon::Normal, QIcon::Off);
        SurfaceAction->setIcon(icon5);
        ResetAction = new QAction(PCLViewer);
        ResetAction->setObjectName(QString::fromUtf8("ResetAction"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/image/reload.png"), QSize(), QIcon::Normal, QIcon::Off);
        ResetAction->setIcon(icon6);
        NormalAction = new QAction(PCLViewer);
        NormalAction->setObjectName(QString::fromUtf8("NormalAction"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/image/image/normal.png"), QSize(), QIcon::Normal, QIcon::Off);
        NormalAction->setIcon(icon7);
        CleraAction = new QAction(PCLViewer);
        CleraAction->setObjectName(QString::fromUtf8("CleraAction"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/image/image/eraser.png"), QSize(), QIcon::Normal, QIcon::Off);
        CleraAction->setIcon(icon8);
        CoordinateAction = new QAction(PCLViewer);
        CoordinateAction->setObjectName(QString::fromUtf8("CoordinateAction"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/image/image/show_axis.png"), QSize(), QIcon::Normal, QIcon::Off);
        CoordinateAction->setIcon(icon9);
        BackgroudAction = new QAction(PCLViewer);
        BackgroudAction->setObjectName(QString::fromUtf8("BackgroudAction"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/image/image/fill.png"), QSize(), QIcon::Normal, QIcon::Off);
        BackgroudAction->setIcon(icon10);
        VerticesAction = new QAction(PCLViewer);
        VerticesAction->setObjectName(QString::fromUtf8("VerticesAction"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/image/image/vert_color.png"), QSize(), QIcon::Normal, QIcon::Off);
        VerticesAction->setIcon(icon11);
        HideAction = new QAction(PCLViewer);
        HideAction->setObjectName(QString::fromUtf8("HideAction"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/image/image/layers.png"), QSize(), QIcon::Normal, QIcon::Off);
        HideAction->setIcon(icon12);
        ConfigurationAction = new QAction(PCLViewer);
        ConfigurationAction->setObjectName(QString::fromUtf8("ConfigurationAction"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/image/image/options.png"), QSize(), QIcon::Normal, QIcon::Off);
        ConfigurationAction->setIcon(icon13);
        SelectAction = new QAction(PCLViewer);
        SelectAction->setObjectName(QString::fromUtf8("SelectAction"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/image/image/bbox.png"), QSize(), QIcon::Normal, QIcon::Off);
        SelectAction->setIcon(icon14);
        RGBCloudAction = new QAction(PCLViewer);
        RGBCloudAction->setObjectName(QString::fromUtf8("RGBCloudAction"));
        XYZCloudAction = new QAction(PCLViewer);
        XYZCloudAction->setObjectName(QString::fromUtf8("XYZCloudAction"));
        ReconstructRealTimeAction = new QAction(PCLViewer);
        ReconstructRealTimeAction->setObjectName(QString::fromUtf8("ReconstructRealTimeAction"));
        FillholeAction = new QAction(PCLViewer);
        FillholeAction->setObjectName(QString::fromUtf8("FillholeAction"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/image/image/fillhole.png"), QSize(), QIcon::Normal, QIcon::Off);
        FillholeAction->setIcon(icon15);
        centralWidget = new QWidget(PCLViewer);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        subwindow = new QWidget();
        subwindow->setObjectName(QString::fromUtf8("subwindow"));
        gridLayout = new QGridLayout(subwindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        qvtkWidget = new QVTKWidget(subwindow);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));

        verticalLayout_4->addWidget(qvtkWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        progressBar = new QProgressBar(subwindow);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        horizontalLayout->addWidget(progressBar);


        verticalLayout_4->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);

        mdiArea->addSubWindow(subwindow);

        horizontalLayout_2->addWidget(mdiArea);

        PCLViewer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PCLViewer);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1373, 21));
        menu_F = new QMenu(menuBar);
        menu_F->setObjectName(QString::fromUtf8("menu_F"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menuKinect = new QMenu(menu);
        menuKinect->setObjectName(QString::fromUtf8("menuKinect"));
        menu_E = new QMenu(menuBar);
        menu_E->setObjectName(QString::fromUtf8("menu_E"));
        menu_V = new QMenu(menuBar);
        menu_V->setObjectName(QString::fromUtf8("menu_V"));
        PCLViewer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PCLViewer);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        PCLViewer->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PCLViewer);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        PCLViewer->setStatusBar(statusBar);
        ShowDockWidget = new QDockWidget(PCLViewer);
        ShowDockWidget->setObjectName(QString::fromUtf8("ShowDockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        horizontalLayout_3 = new QHBoxLayout(dockWidgetContents);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        frame = new QFrame(dockWidgetContents);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        PointsNumber = new QLCDNumber(frame);
        PointsNumber->setObjectName(QString::fromUtf8("PointsNumber"));

        verticalLayout_2->addWidget(PointsNumber);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_9);

        textBrowser = new QTextBrowser(frame);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout_2->addWidget(textBrowser);


        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout_3->addWidget(frame);

        ShowDockWidget->setWidget(dockWidgetContents);
        PCLViewer->addDockWidget(static_cast<Qt::DockWidgetArea>(1), ShowDockWidget);
        OperateDockWidget = new QDockWidget(PCLViewer);
        OperateDockWidget->setObjectName(QString::fromUtf8("OperateDockWidget"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        horizontalLayout_4 = new QHBoxLayout(dockWidgetContents_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        frame_2 = new QFrame(dockWidgetContents_2);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lcdNumber = new QLCDNumber(frame_2);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));

        verticalLayout->addWidget(lcdNumber);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        KtreeSlider = new QSlider(frame_2);
        KtreeSlider->setObjectName(QString::fromUtf8("KtreeSlider"));
        KtreeSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(KtreeSlider);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_7);

        MLSButton = new QPushButton(frame_2);
        MLSButton->setObjectName(QString::fromUtf8("MLSButton"));

        verticalLayout->addWidget(MLSButton);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_8);

        DownSampingButton = new QPushButton(frame_2);
        DownSampingButton->setObjectName(QString::fromUtf8("DownSampingButton"));

        verticalLayout->addWidget(DownSampingButton);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        ReconstructButton = new QPushButton(frame_2);
        ReconstructButton->setObjectName(QString::fromUtf8("ReconstructButton"));

        verticalLayout->addWidget(ReconstructButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        BuildButton = new QPushButton(frame_2);
        BuildButton->setObjectName(QString::fromUtf8("BuildButton"));

        verticalLayout->addWidget(BuildButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        FilterButton = new QPushButton(frame_2);
        FilterButton->setObjectName(QString::fromUtf8("FilterButton"));

        verticalLayout->addWidget(FilterButton);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        ResetButton = new QPushButton(frame_2);
        ResetButton->setObjectName(QString::fromUtf8("ResetButton"));

        verticalLayout->addWidget(ResetButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        ClearButton = new QPushButton(frame_2);
        ClearButton->setObjectName(QString::fromUtf8("ClearButton"));

        verticalLayout->addWidget(ClearButton);


        horizontalLayout_4->addWidget(frame_2);

        OperateDockWidget->setWidget(dockWidgetContents_2);
        PCLViewer->addDockWidget(static_cast<Qt::DockWidgetArea>(1), OperateDockWidget);
        ConfigurDockWidget = new QDockWidget(PCLViewer);
        ConfigurDockWidget->setObjectName(QString::fromUtf8("ConfigurDockWidget"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        gridLayout_2 = new QGridLayout(dockWidgetContents_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        Background_groupBox = new QGroupBox(dockWidgetContents_3);
        Background_groupBox->setObjectName(QString::fromUtf8("Background_groupBox"));
        layoutWidget = new QWidget(Background_groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 50, 251, 161));
        verticalLayout_6 = new QVBoxLayout(layoutWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        Slider_Backgroud_R = new QSlider(layoutWidget);
        Slider_Backgroud_R->setObjectName(QString::fromUtf8("Slider_Backgroud_R"));
        Slider_Backgroud_R->setMaximum(255);
        Slider_Backgroud_R->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(Slider_Backgroud_R);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        lcdNumber_2 = new QLCDNumber(layoutWidget);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));

        horizontalLayout_5->addWidget(lcdNumber_2);

        horizontalLayout_5->setStretch(0, 3);
        horizontalLayout_5->setStretch(2, 1);

        verticalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        Slider_Background_G = new QSlider(layoutWidget);
        Slider_Background_G->setObjectName(QString::fromUtf8("Slider_Background_G"));
        Slider_Background_G->setMaximum(255);
        Slider_Background_G->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(Slider_Background_G);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_6->addWidget(label_4);

        lcdNumber_3 = new QLCDNumber(layoutWidget);
        lcdNumber_3->setObjectName(QString::fromUtf8("lcdNumber_3"));

        horizontalLayout_6->addWidget(lcdNumber_3);

        horizontalLayout_6->setStretch(0, 3);

        verticalLayout_6->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        Slide_Background_B = new QSlider(layoutWidget);
        Slide_Background_B->setObjectName(QString::fromUtf8("Slide_Background_B"));
        Slide_Background_B->setMaximum(255);
        Slide_Background_B->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(Slide_Background_B);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_7->addWidget(label_5);

        lcdNumber_4 = new QLCDNumber(layoutWidget);
        lcdNumber_4->setObjectName(QString::fromUtf8("lcdNumber_4"));

        horizontalLayout_7->addWidget(lcdNumber_4);

        horizontalLayout_7->setStretch(0, 3);
        horizontalLayout_7->setStretch(2, 1);

        verticalLayout_6->addLayout(horizontalLayout_7);

        verticalSpacer_10 = new QSpacerItem(153, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_10);

        verticalLayout_6->setStretch(0, 3);
        verticalLayout_6->setStretch(1, 3);
        verticalLayout_6->setStretch(2, 3);
        verticalLayout_6->setStretch(3, 1);

        verticalLayout_5->addWidget(Background_groupBox);

        Point_Box = new QGroupBox(dockWidgetContents_3);
        Point_Box->setObjectName(QString::fromUtf8("Point_Box"));
        layoutWidget1 = new QWidget(Point_Box);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 50, 261, 161));
        verticalLayout_7 = new QVBoxLayout(layoutWidget1);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSlider_4 = new QSlider(layoutWidget1);
        horizontalSlider_4->setObjectName(QString::fromUtf8("horizontalSlider_4"));
        horizontalSlider_4->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(horizontalSlider_4);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_8->addWidget(label_6);

        lcdNumber_5 = new QLCDNumber(layoutWidget1);
        lcdNumber_5->setObjectName(QString::fromUtf8("lcdNumber_5"));

        horizontalLayout_8->addWidget(lcdNumber_5);

        horizontalLayout_8->setStretch(0, 3);

        verticalLayout_7->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSlider_5 = new QSlider(layoutWidget1);
        horizontalSlider_5->setObjectName(QString::fromUtf8("horizontalSlider_5"));
        horizontalSlider_5->setOrientation(Qt::Horizontal);

        horizontalLayout_9->addWidget(horizontalSlider_5);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_9->addWidget(label_7);

        lcdNumber_6 = new QLCDNumber(layoutWidget1);
        lcdNumber_6->setObjectName(QString::fromUtf8("lcdNumber_6"));

        horizontalLayout_9->addWidget(lcdNumber_6);

        horizontalLayout_9->setStretch(0, 3);
        horizontalLayout_9->setStretch(2, 1);

        verticalLayout_7->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSlider_6 = new QSlider(layoutWidget1);
        horizontalSlider_6->setObjectName(QString::fromUtf8("horizontalSlider_6"));
        horizontalSlider_6->setOrientation(Qt::Horizontal);

        horizontalLayout_10->addWidget(horizontalSlider_6);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_10->addWidget(label_8);

        lcdNumber_7 = new QLCDNumber(layoutWidget1);
        lcdNumber_7->setObjectName(QString::fromUtf8("lcdNumber_7"));

        horizontalLayout_10->addWidget(lcdNumber_7);

        horizontalLayout_10->setStretch(0, 3);
        horizontalLayout_10->setStretch(2, 1);

        verticalLayout_7->addLayout(horizontalLayout_10);


        verticalLayout_5->addWidget(Point_Box);

        Leng_roupBox = new QGroupBox(dockWidgetContents_3);
        Leng_roupBox->setObjectName(QString::fromUtf8("Leng_roupBox"));
        NormallenSlider = new QSlider(Leng_roupBox);
        NormallenSlider->setObjectName(QString::fromUtf8("NormallenSlider"));
        NormallenSlider->setGeometry(QRect(0, 29, 21, 181));
        NormallenSlider->setMinimum(1);
        NormallenSlider->setMaximum(20);
        NormallenSlider->setOrientation(Qt::Vertical);
        lcdNumber_8 = new QLCDNumber(Leng_roupBox);
        lcdNumber_8->setObjectName(QString::fromUtf8("lcdNumber_8"));
        lcdNumber_8->setGeometry(QRect(0, 210, 71, 41));
        lcdNumber_8->setProperty("value", QVariant(1));
        NormalPointNumber = new QSlider(Leng_roupBox);
        NormalPointNumber->setObjectName(QString::fromUtf8("NormalPointNumber"));
        NormalPointNumber->setGeometry(QRect(40, 100, 231, 16));
        NormalPointNumber->setMinimum(1);
        NormalPointNumber->setMaximum(20);
        NormalPointNumber->setOrientation(Qt::Horizontal);
        label_9 = new QLabel(Leng_roupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(90, 70, 151, 20));

        verticalLayout_5->addWidget(Leng_roupBox);


        gridLayout_2->addLayout(verticalLayout_5, 0, 0, 1, 1);

        ConfigurDockWidget->setWidget(dockWidgetContents_3);
        PCLViewer->addDockWidget(static_cast<Qt::DockWidgetArea>(2), ConfigurDockWidget);

        menuBar->addAction(menu_F->menuAction());
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_E->menuAction());
        menuBar->addAction(menu_V->menuAction());
        menu_F->addAction(OpenAction);
        menu_F->addAction(SaveAction);
        menu->addAction(menuKinect->menuAction());
        menuKinect->addAction(RGBCloudAction);
        menuKinect->addAction(XYZCloudAction);
        menuKinect->addAction(ReconstructRealTimeAction);
        menu_E->addAction(SimplyAction);
        menu_E->addAction(SelectAction);
        menu_E->addAction(MlsAction);
        menu_E->addAction(ReconstructAction);
        menu_E->addAction(SurfaceAction);
        menu_E->addAction(FillholeAction);
        menu_E->addAction(ResetAction);
        menu_E->addAction(NormalAction);
        menu_E->addAction(CleraAction);
        menu_V->addAction(CoordinateAction);
        menu_V->addAction(BackgroudAction);
        menu_V->addAction(VerticesAction);
        menu_V->addAction(HideAction);
        menu_V->addAction(ConfigurationAction);
        mainToolBar->addAction(OpenAction);
        mainToolBar->addAction(SaveAction);
        mainToolBar->addSeparator();
        mainToolBar->addAction(SelectAction);
        mainToolBar->addAction(SimplyAction);
        mainToolBar->addAction(MlsAction);
        mainToolBar->addAction(ReconstructAction);
        mainToolBar->addAction(SurfaceAction);
        mainToolBar->addAction(FillholeAction);
        mainToolBar->addAction(ResetAction);
        mainToolBar->addAction(NormalAction);
        mainToolBar->addAction(CleraAction);
        mainToolBar->addSeparator();
        mainToolBar->addAction(CoordinateAction);
        mainToolBar->addAction(BackgroudAction);
        mainToolBar->addAction(VerticesAction);
        mainToolBar->addAction(ConfigurationAction);
        mainToolBar->addAction(HideAction);

        retranslateUi(PCLViewer);
        QObject::connect(Slider_Backgroud_R, SIGNAL(valueChanged(int)), lcdNumber_2, SLOT(display(int)));
        QObject::connect(Slider_Background_G, SIGNAL(valueChanged(int)), lcdNumber_3, SLOT(display(int)));
        QObject::connect(Slide_Background_B, SIGNAL(valueChanged(int)), lcdNumber_4, SLOT(display(int)));
        QObject::connect(horizontalSlider_4, SIGNAL(valueChanged(int)), lcdNumber_5, SLOT(display(int)));
        QObject::connect(horizontalSlider_5, SIGNAL(valueChanged(int)), lcdNumber_6, SLOT(display(int)));
        QObject::connect(horizontalSlider_6, SIGNAL(valueChanged(int)), lcdNumber_7, SLOT(display(int)));
        QObject::connect(NormallenSlider, SIGNAL(valueChanged(int)), lcdNumber_8, SLOT(display(int)));

        QMetaObject::connectSlotsByName(PCLViewer);
    } // setupUi

    void retranslateUi(QMainWindow *PCLViewer)
    {
        PCLViewer->setWindowTitle(QApplication::translate("PCLViewer", "PCLViewer", 0, QApplication::UnicodeUTF8));
        OpenAction->setText(QApplication::translate("PCLViewer", "\346\211\223\345\274\200(&N)", 0, QApplication::UnicodeUTF8));
        SaveAction->setText(QApplication::translate("PCLViewer", "\344\277\235\345\255\230(&S)", 0, QApplication::UnicodeUTF8));
        SaveAction->setShortcut(QApplication::translate("PCLViewer", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        SimplyAction->setText(QApplication::translate("PCLViewer", "\347\202\271\344\272\221\347\262\276\347\256\200", 0, QApplication::UnicodeUTF8));
        MlsAction->setText(QApplication::translate("PCLViewer", "\347\202\271\344\272\221\345\271\263\346\273\221", 0, QApplication::UnicodeUTF8));
        ReconstructAction->setText(QApplication::translate("PCLViewer", "\347\202\271\344\272\221\351\207\215\346\236\204", 0, QApplication::UnicodeUTF8));
        SurfaceAction->setText(QApplication::translate("PCLViewer", "\346\233\262\351\235\242\351\207\215\345\273\272", 0, QApplication::UnicodeUTF8));
        ResetAction->setText(QApplication::translate("PCLViewer", "\347\202\271\344\272\221\351\207\215\347\275\256", 0, QApplication::UnicodeUTF8));
        NormalAction->setText(QApplication::translate("PCLViewer", "\346\230\276\347\244\272\346\263\225\347\272\277", 0, QApplication::UnicodeUTF8));
        CleraAction->setText(QApplication::translate("PCLViewer", "\346\225\260\346\215\256\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
        CoordinateAction->setText(QApplication::translate("PCLViewer", "coordinate", 0, QApplication::UnicodeUTF8));
        BackgroudAction->setText(QApplication::translate("PCLViewer", "background", 0, QApplication::UnicodeUTF8));
        VerticesAction->setText(QApplication::translate("PCLViewer", "vertices", 0, QApplication::UnicodeUTF8));
        HideAction->setText(QApplication::translate("PCLViewer", "hide", 0, QApplication::UnicodeUTF8));
        ConfigurationAction->setText(QApplication::translate("PCLViewer", "configuration", 0, QApplication::UnicodeUTF8));
        SelectAction->setText(QApplication::translate("PCLViewer", "\347\202\271\344\272\221\351\200\211\345\217\226", 0, QApplication::UnicodeUTF8));
        RGBCloudAction->setText(QApplication::translate("PCLViewer", "\345\275\251\350\211\262\347\202\271\344\272\221", 0, QApplication::UnicodeUTF8));
        XYZCloudAction->setText(QApplication::translate("PCLViewer", "\347\201\260\345\272\246\347\202\271\344\272\221", 0, QApplication::UnicodeUTF8));
        ReconstructRealTimeAction->setText(QApplication::translate("PCLViewer", "\344\270\211\347\273\264\351\207\215\345\273\272", 0, QApplication::UnicodeUTF8));
        FillholeAction->setText(QApplication::translate("PCLViewer", "\345\255\224\346\264\236\344\277\256\345\244\215", 0, QApplication::UnicodeUTF8));
        subwindow->setWindowTitle(QString());
        menu_F->setTitle(QApplication::translate("PCLViewer", "\346\226\207\344\273\266(&F)", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("PCLViewer", "\350\256\276\345\244\207", 0, QApplication::UnicodeUTF8));
        menuKinect->setTitle(QApplication::translate("PCLViewer", "Kinect", 0, QApplication::UnicodeUTF8));
        menu_E->setTitle(QApplication::translate("PCLViewer", "\347\274\226\350\276\221(&E)", 0, QApplication::UnicodeUTF8));
        menu_V->setTitle(QApplication::translate("PCLViewer", "\350\247\206\345\233\276(&V)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PCLViewer", "The Number of Points", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PCLViewer", "                \347\202\271\344\272\221\347\262\276\347\256\200", 0, QApplication::UnicodeUTF8));
        MLSButton->setText(QApplication::translate("PCLViewer", "\347\202\271\344\272\221\345\271\263\346\273\221", 0, QApplication::UnicodeUTF8));
        DownSampingButton->setText(QApplication::translate("PCLViewer", "\351\231\215\351\207\207\346\240\267", 0, QApplication::UnicodeUTF8));
        ReconstructButton->setText(QApplication::translate("PCLViewer", "\347\202\271\344\272\221\351\207\215\346\236\204", 0, QApplication::UnicodeUTF8));
        BuildButton->setText(QApplication::translate("PCLViewer", "\346\233\262\351\235\242\351\207\215\345\273\272", 0, QApplication::UnicodeUTF8));
        FilterButton->setText(QApplication::translate("PCLViewer", "\346\233\262\351\235\242\345\205\211\346\273\221", 0, QApplication::UnicodeUTF8));
        ResetButton->setText(QApplication::translate("PCLViewer", "\351\207\215\347\275\256", 0, QApplication::UnicodeUTF8));
        ClearButton->setText(QApplication::translate("PCLViewer", "\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
        Background_groupBox->setTitle(QApplication::translate("PCLViewer", "BackGround Configure", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PCLViewer", "R", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("PCLViewer", "G", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("PCLViewer", "B", 0, QApplication::UnicodeUTF8));
        Point_Box->setTitle(QApplication::translate("PCLViewer", "Point Configure", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("PCLViewer", "R", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("PCLViewer", "G", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("PCLViewer", "B", 0, QApplication::UnicodeUTF8));
        Leng_roupBox->setTitle(QApplication::translate("PCLViewer", "Normal Configure", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("PCLViewer", "Normal Point number", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PCLViewer: public Ui_PCLViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCLVIEWER_H
