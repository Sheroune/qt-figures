#ifndef FIGURE_H
#define FIGURE_H

#include <QWidget>
#include <QLineEdit>
#include <QButtonGroup>
#include <QRadioButton>
#include <QLabel>

class Figure : public QWidget
{
    Q_OBJECT

private:
    QPoint oldPos;
    QLineEdit *angle,*line1,*line2;
    QRadioButton *rad1,*rad2;
    QButtonGroup *group;
    std::string figura;

    float mult;
    bool rotateFlag,dir;
    int deg;
    int w,h;
    int x, r;
    int p, q;

public:
    explicit Figure(QWidget *parent = 0, std::string figura="");
    float area();
    float perimeter();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void contextMenuEvent(QContextMenuEvent *event);

signals:
    void deleteButton();

private slots:
    void rotate();
    void changeWidth();
    void changeHeight();
};

#endif // FIGURE_H
