#include "PaintWindow.h"
#include <QMainWindow>
#include <QApplication>
#include <QFileDialog>
#include <iostream>

using namespace std;

PaintWindow::PaintWindow(QWidget* parent) : QMainWindow(parent)
{
    actionNew = new QAction(tr("&New Image"), this);
    actionNew->setShortcut(QKeySequence::New);
    actionNew->setStatusTip(tr("New Plain White Image"));
    connect(actionNew, SIGNAL(triggered()), this, SLOT(newImage()));
    
    actionOpen = new QAction(tr("&Load Image"), this);
    actionOpen->setShortcut(QKeySequence::Open);
    actionOpen->setStatusTip(tr("Open an Image"));
    connect(actionOpen, SIGNAL(triggered()), this, SLOT(openImage()));
    
    actionSave = new QAction(tr("&Save Image"), this);
    actionSave->setShortcut(QKeySequence::Save);
    actionSave->setStatusTip(tr("Save your Image"));
    connect(actionSave, SIGNAL(triggered()), this, SLOT(saveImage()));
    
    actionQuit = new QAction(tr("&Quit"), this);
    actionQuit->setShortcut(QKeySequence::Quit);
    actionQuit->setStatusTip(tr("Quit the Application"));
    connect(actionQuit, SIGNAL(triggered()), qApp, SLOT(quit()));
    
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(actionNew);
    fileMenu->addAction(actionOpen);
    fileMenu->addAction(actionSave);
    fileMenu->addAction(actionQuit);
    
    
    toolBrush = new QAction(tr("&Brush"), this);
    toolBrush->setStatusTip(tr("&Paint on the canvas"));
    connect(toolBrush, SIGNAL(triggered()), this, SLOT(setTool()));
    
    toolLine = new QAction(tr("&Line"), this);
    toolLine->setStatusTip(tr("&Draw Lines"));
    connect(toolLine, SIGNAL(triggered()), this, SLOT(setTool()));
    
    toolCurve = new QAction(tr("&Curve"), this);
    toolCurve->setStatusTip(tr("&Draw Curves"));
    connect(toolCurve, SIGNAL(triggered()), this, SLOT(setTool()));
    
    toolMenu = menuBar()->addMenu(tr("&Tools"));
    toolMenu->addAction(toolBrush);
    toolMenu->addAction(toolLine);
    toolMenu->addAction(toolCurve);
    
    colorBlack= new QAction(tr("&Black"), this);
    colorBlack->setStatusTip(tr("&Black"));
    connect(colorBlack, SIGNAL(triggered()), this, SLOT(setColor()));
    
    colorRed = new QAction(tr("&Red"), this);
    colorRed->setStatusTip(tr("&Red"));
    connect(colorRed, SIGNAL(triggered()), this, SLOT(setColor()));
    
    colorBlue = new QAction(tr("&Blue"), this);
    colorBlue->setStatusTip(tr("&Blue"));
    connect(colorBlue, SIGNAL(triggered()), this, SLOT(setColor()));
    
    colorGreen = new QAction(tr("&Green"), this);
    colorGreen->setStatusTip(tr("&Green"));
    connect(colorGreen, SIGNAL(triggered()), this, SLOT(setColor()));
    
    colorMenu = menuBar()->addMenu(tr("&Colour"));
    colorMenu->addAction(colorBlack);
    colorMenu->addAction(colorRed);
    colorMenu->addAction(colorBlue);
    colorMenu->addAction(colorGreen);
    
    this->paintWidget = new PaintWidget(this);
    this->setCentralWidget (paintWidget);
}

void PaintWindow::newImage()
{
    delete(this->paintWidget);
    this->paintWidget  = new PaintWidget(this);
    this->setCentralWidget(paintWidget);
}

void PaintWindow::openImage()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Image"), "./", tr("Image Files (*.png *.jpg *.bmp)"));
    if (!filename.isNull())
    {
        delete(this->paintWidget);
        this->paintWidget = new PaintWidget(filename, this);
        this->setCentralWidget(paintWidget);
    }
}

void PaintWindow::saveImage()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save Image"), "", tr("Image (*.png *.jpg *.bmp)"));
    this->paintWidget->save(filename);
}

void PaintWindow::setTool()
{
    QAction* action = qobject_cast<QAction *>(QObject::sender()); //get the sending object, cast it to a QAction
    this->paintWidget->setTool(action->text().toStdString());
}

void PaintWindow::setColor()
{
    QAction* action = qobject_cast<QAction *>(QObject::sender());
    this->paintWidget->setColor(action->text().toStdString());
}
