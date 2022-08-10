#include "mainwindow.h"
#include "figure.h"

#include <QApplication>
#include <QToolBar>
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setStyleSheet("QMainWindow {background: 'white';}");
    this->setWindowTitle("Figures");

    QToolBar *bar = addToolBar("main toolbar");

    buttonAdd = new QPushButton("&Add", this);
    buttonDel = new QPushButton("&Delete", this);
    buttonFig1 = new QPushButton("&1st Figure", this);
    buttonFig2 = new QPushButton("&2nd Figure", this);


    buttonAdd->setEnabled(false);

    buttonDel->setEnabled(false);
    buttonDel->setFocusPolicy(Qt::NoFocus);

    buttonFig1->setFocusPolicy(Qt::NoFocus);
    buttonFig1->setCheckable(true);

    buttonFig2->setFocusPolicy(Qt::NoFocus);
    buttonFig2->setCheckable(true);

    connect(buttonAdd,SIGNAL(released()),
            this,SLOT(addFigure()));
    connect(buttonDel,SIGNAL(released()),
            this,SLOT(deleteFigure()));
    connect(buttonFig1,SIGNAL(released()),
            this,SLOT(Toggle1()));
    connect(buttonFig2,SIGNAL(released()),
            this,SLOT(Toggle2()));

    bar->addWidget(buttonAdd);
    bar->addWidget(buttonDel);
    bar->addWidget(buttonFig1);
    bar->addWidget(buttonFig2);
    bar->setMovable(false);

}

MainWindow::~MainWindow(){}

// add new figure to the screen
void MainWindow::addFigure(){
    std::string smth="";
    if(buttonFig1->isChecked())
        smth = "A3B3C4D3EF5";
    else if(buttonFig2->isChecked())
        smth = "A3B2C4D3EF5";
    if(smth!=""){
        Figure *f = new Figure(this, smth);
        connect(f,SIGNAL(deleteButton()),this,SLOT(enableButton()));
        figures.push_back(f);
        f->move(width()/2-f->width()/2,height()/2);
        f->resize(150,110);
        f->show();
    }
    buttonDel->setEnabled(false);
}

// delete focused figure
void MainWindow::deleteFigure(){
    for(auto it=figures.begin();it<figures.end();it++){
        if((*it)->hasFocus()){
            delete *it;
            figures.erase(it);
            break;
        }
    }
    buttonDel->setEnabled(false);
}

// select figure type 1
void MainWindow::Toggle1(){
    buttonFig2->setChecked(false);
    if(buttonFig1->isChecked())
        buttonAdd->setEnabled(true);
    else
        buttonAdd->setEnabled(false);
}

// select figure type 2
void MainWindow::Toggle2(){
    buttonFig1->setChecked(false);
    if(buttonFig2->isChecked())
        buttonAdd->setEnabled(true);
    else
        buttonAdd->setEnabled(false);
}

// enable delete button
void MainWindow::enableButton(){
    buttonDel->setEnabled(true);
}
