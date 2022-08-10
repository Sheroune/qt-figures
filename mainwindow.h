#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>

#include <QMainWindow>
#include <QPushButton>

#include "figure.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    std::vector<Figure*> figures;

    QPushButton *buttonAdd;
    QPushButton *buttonDel;
    QPushButton *buttonFig1;
    QPushButton *buttonFig2;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void addFigure();
    void deleteFigure();
    void enableButton();
    void Toggle1();
    void Toggle2();
};
#endif // MAINWINDOW_H
