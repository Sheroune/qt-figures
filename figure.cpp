#include "figure.h"

#include <cmath>

#include <QPainter>
#include <QContextMenuEvent>
#include <QDialog>
#include <QLabel>
#include <QGridLayout>

Figure::Figure(QWidget *parent, std::string fig) :
    QWidget(parent),
    rotateFlag(false), dir(false)
{
    deg=0;
    figura = fig;
    this->setFocusPolicy(Qt::ClickFocus);

    x = height()/1.5, r = height()/1.5;
    p = width()/3, q = width()/3;
}

void Figure::paintEvent(QPaintEvent *event)
{
   mult = 2;

   w = width()  -2;
   h = (height()-height()/3)-2;
   //x = h/3, r = h/3;
   //p = w/4, q = w/4;


   QPainter painter(this);


   if(hasFocus()) painter.setPen(QColor("#000080"));
   else      painter.setPen(QColor("#000000"));

   //painter.drawLine(0,0,width()-1,0);
   //painter.drawLine(0,height()-1,width()-1,height()-1);
   //painter.drawLine(0,0,0,height()-1);
   //painter.drawLine(width()-1,0,width()-1,height()-1);

   painter.scale(1.0/mult,1.0/mult);
   painter.translate((mult*width()/2-w/2),(mult*height()/2-h/2));
   if(rotateFlag){
       painter.translate(w/2,h/2);
       painter.rotate(deg);
       painter.translate(-w/2,-h/2);
   }

   if(isdigit(figura[figura.find('E')+1])){
       if(isdigit(figura[figura.find('A')+1]) && isdigit(figura[figura.find('D')+1])){
            painter.drawLine(x,0,w/2-p/2,0);
            painter.drawLine(w/2+p/2,0,w-x,0);

            painter.drawLine(0,x,0,h/2);
            painter.drawLine(w,x,w,h/2);
       }
       else if(isdigit(figura[figura.find('D')+1])){
           painter.drawLine(x,0,w/2-p/2,0);
           painter.drawLine(w/2+p/2,0,w,0);

           painter.drawLine(0,x,0,h/2);
       }
       else if(isdigit(figura[figura.find('A')+1])){
           painter.drawLine(0,0,w/2-p/2,0);
           painter.drawLine(w/2+p/2,0,w-x,0);

           painter.drawLine(w,x,w,h/2);
       }
       else{
           painter.drawLine(0,0,w/2-p/2,0);
           painter.drawLine(w/2+p/2,0,w,0);

           painter.drawLine(0,0,0,h);
           painter.drawLine(w,0,w,h);
       }
   }
   else{
       if(isdigit(figura[figura.find('A')+1]) && isdigit(figura[figura.find('D')+1])){
           painter.drawLine(x,0,w-x,0);

           painter.drawLine(0,x,0,h/2);
           painter.drawLine(w,x,w,h/2);
       }
       else if(isdigit(figura[figura.find('D')+1])){
           painter.drawLine(x,0,w,0);

           painter.drawLine(0,x,0,h/2);
       }
       else if(isdigit(figura[figura.find('A')+1])){
           painter.drawLine(0,0,w-x,0);

           painter.drawLine(w,x,w,h/2);
       }
       else{
           painter.drawLine(0,0,w,0);

           painter.drawLine(0,0,0,h);
           painter.drawLine(w,0,w,h);
       }
   }

   if(figura.find('F')+1!=figura.size()){
       if(isdigit(figura[figura.find('C')+1]) && isdigit(figura[figura.find('B')+1])){
           painter.drawLine(x,h,w/2-p/2,h);
           painter.drawLine(w/2+p/2,h,w-x,h);

           painter.drawLine(0,h/2,0,h-x);
           painter.drawLine(w,h/2,w,h-x);
       }
       else if(isdigit(figura[figura.find('C')+1])){
           painter.drawLine(x,h,w/2-p/2,h);
           painter.drawLine(w/2+p/2,h,w,h);

           painter.drawLine(0,h/2,0,h-x);
           painter.drawLine(w,h/2,w,h);
       }
       else if(isdigit(figura[figura.find('B')+1])){
           painter.drawLine(0,h,w/2-p/2,h);
           painter.drawLine(w/2+p/2,h,w,h);

           painter.drawLine(0,h/2,0,h);
           painter.drawLine(w,h/2,w,h-x);
       }
       else{
           painter.drawLine(0,h,w/2-p/2,h);
           painter.drawLine(w/2+p/2,h,w,h);

           painter.drawLine(0,h/2,0,h);
           painter.drawLine(w,h/2,w,h);
       }
   }
   else{
       if(isdigit(figura[figura.find('C')+1]) && isdigit(figura[figura.find('B')+1])){
           painter.drawLine(x,h,w-x,h);

           painter.drawLine(0,h/2,0,h-x);
           painter.drawLine(w,h/2,w,h-x);
       }
       else if(isdigit(figura[figura.find('C')+1])){
           painter.drawLine(x,h,w,h);

           painter.drawLine(0,h/2,0,h-x);
           painter.drawLine(w,h/2,w,h);
       }
       else if(isdigit(figura[figura.find('B')+1])){
           painter.drawLine(0,h,w-x,h);

           painter.drawLine(0,h/2,0,h);
           painter.drawLine(w,h/2,w,h-x);
       }
       else{
           painter.drawLine(0,h,w,h);

           painter.drawLine(0,h/2,0,h);
           painter.drawLine(w,h/2,w,h);
       }
   }


   if(isdigit(figura[figura.find('E')+1])){
       if(std::stoi(std::string(1,figura[figura.find('E')+1]))==5){
           painter.drawLine(w/2-p/2,0,w/2-p/2,p/2);
           painter.drawLine(w/2-p/2,p/2,w/2+p/2,p/2);
           painter.drawLine(w/2+p/2,p/2,w/2+p/2,0);
       }
       else{
           for(int i=180;i<=360;i++){
            painter.drawPoint((w/2-p/2-w/2)*cos(M_PI*i/180)+w/2, (w/2-p/2-w/2)*sin(M_PI*i/180));
           }
       }
   }

   if(figura.find('F')+1!=figura.size()){
       if(std::stoi(std::string(1,figura[figura.find('F')+1]))==5){
           painter.drawLine(w/2-p/2,h,w/2-p/2,h+p/2);
           painter.drawLine(w/2-p/2, h+p/2,w/2+p/2,h+p/2);
           painter.drawLine(w/2+p/2,h+p/2,w/2+p/2,h);
       }
       else{
           for(int i=180;i<=360;i++){
            painter.drawPoint((w/2-p/2-w/2)*cos(M_PI*i/180)+w/2, (w/2-p/2-w/2)*sin(M_PI*i/180)+h);
           }
       }
   }

   if(isdigit(figura[figura.find('D')+1])){
       int temp = std::stoi(std::string(1,figura[figura.find('D')+1]));
       if(temp==1){
           painter.drawLine(x,0,x,x);
           painter.drawLine(0,x,x,x);
       }
       else if(temp==2){
           painter.drawLine(x,0,0,x);
       }
       else if(temp==3){
           for(int i=0;i<=90;i++){
            painter.drawPoint(r*cos(M_PI*i/180), r*sin(M_PI*i/180));
           }
       }
       else{
           for(int i=180;i<=270;i++){
            painter.drawPoint(r*cos(M_PI*i/180)+r, r*sin(M_PI*i/180)+r);
           }
       }
   }

   if(isdigit(figura[figura.find('C')+1])){
       int temp = std::stoi(std::string(1,figura[figura.find('C')+1]));
       if(temp==1){
           painter.drawLine(x,h,x,h-x);
           painter.drawLine(0,h-x,x,h-x);
       }
       else if(temp==2){
           painter.drawLine(x,h,0,h-x);
       }
       else if(temp==3){
           for(int i=270;i<=360;i++){
            painter.drawPoint(r*cos(M_PI*i/180), r*sin(M_PI*i/180)+h);
           }
       }
       else{
           for(int i=90;i<=180;i++){
            painter.drawPoint(r*cos(M_PI*i/180)+r, r*sin(M_PI*i/180)+h-r);
           }
       }
   }

   if(isdigit(figura[figura.find('A')+1])){
       int temp = std::stoi(std::string(1,figura[figura.find('A')+1]));
       if(temp==1){
           painter.drawLine(w-x,0,w-x,x);
           painter.drawLine(w-x,x,w,x);
       }
       else if(temp==2){
           painter.drawLine(w-x,0,w,x);
       }
       else if(temp==3){
           for(int i=90;i<=180;i++){
            painter.drawPoint(r*cos(M_PI*i/180)+w, r*sin(M_PI*i/180));
           }
       }
       else{
           for(int i=270;i<=360;i++){
            painter.drawPoint(r*cos(M_PI*i/180)+w-r, r*sin(M_PI*i/180)+r);
           }
       }
   }

   if(isdigit(figura[figura.find('B')+1])){
       int temp = std::stoi(std::string(1,figura[figura.find('B')+1]));
       if(temp==1){
           painter.drawLine(w-x,h-x,w,h-x);
           painter.drawLine(w-x,h-x,w-x,h);
       }
       else if(temp==2){
           painter.drawLine(w,h-x,w-x,h);
       }
       else if(temp==3){
           for(int i=180;i<=270;i++){
            painter.drawPoint(r*cos(M_PI*i/180)+w, r*sin(M_PI*i/180)+h);
           }
       }
       else{
           for(int i=0;i<=90;i++){
            painter.drawPoint(r*cos(M_PI*i/180)+w-r, r*sin(M_PI*i/180)+h-r);
           }
       }
   }
}

void Figure::mousePressEvent(QMouseEvent *event){
    oldPos = event->pos();
    emit deleteButton();
}

void Figure::mouseMoveEvent(QMouseEvent *event){
    //QPoint delta = event->pos() - oldPos;
    //move(pos() + delta);
    if(event->buttons() & Qt::LeftButton){
        QPoint newpos_min = mapToParent(event->pos()-oldPos);
        QPoint newpos_max = QPoint(newpos_min.x() + this->width(), newpos_min.y()+this->height());

        if(newpos_min.x()>0
            && newpos_min.y()>30
            && newpos_max.x() < this->parentWidget()->width()
            && newpos_max.y() < this->parentWidget()->height())
        {

            this->move(mapToParent(event->pos() - oldPos));
        }
    }
}

void Figure::contextMenuEvent(QContextMenuEvent *event){
  //menuFigure->exec(event->globalPos());
    QDialog *qd = new QDialog(this);
    qd->setWindowTitle("Figure Context Menu");
    QGridLayout *grid = new QGridLayout(qd);
    qd->setModal(true);
    qd->resize(200,200);

    line1 = new QLineEdit(qd);
    connect(line1, SIGNAL(returnPressed()), this, SLOT(changeWidth()));
    QLabel *label1 = new QLabel("Width: ", qd);
    label1->setBuddy(line1);
    grid->addWidget(label1,0,0);
    grid->addWidget(line1,0,1);

    line2 = new QLineEdit(qd);
    connect(line2, SIGNAL(returnPressed()), this, SLOT(changeHeight()));
    QLabel *label2 = new QLabel("Height: ", qd);
    label2->setBuddy(line2);
    grid->addWidget(label2,1,0);
    grid->addWidget(line2,1,1);

    angle = new QLineEdit(qd);
    connect(angle, SIGNAL(returnPressed()), this, SLOT(rotate()));

    QLabel *langle = new QLabel("Rotate: ", qd);
    langle->setBuddy(angle);
    grid->addWidget(langle,2,0);
    grid->addWidget(angle,2,1);

    group = new QButtonGroup(qd);
    rad1 = new QRadioButton("Counterclockwise", qd);
    rad1->setChecked(true);
    rad2 = new QRadioButton("Clockwise", qd);
    group->addButton(rad1,1);
    group->addButton(rad2,2);
    grid->addWidget(rad1,3,0);
    grid->addWidget(rad2,3,1);

    QLabel *label3 = new QLabel("Area: ", qd);
    QLabel *label4 = new QLabel(QString::number(area()), qd);
    grid->addWidget(label3,4,0);
    grid->addWidget(label4,4,1);

    QLabel *label5 = new QLabel("Perimeter: ", qd);
    QLabel *label6 = new QLabel(QString::number(perimeter()), qd);
    grid->addWidget(label5,5,0);
    grid->addWidget(label6,5,1);

    qd->exec();
    delete qd;
}

float Figure::area(){
    float s = h*w;

    if(isdigit(figura[figura.find('E')+1])){
        if(std::stoi(std::string(1,figura[figura.find('E')+1]))==5){
            s-=p*p/2;
        }
        else{
            s-=M_PI*q*q/2;
        }
    }

    if(figura.find('F')+1!=figura.size()){
        if(std::stoi(std::string(1,figura[figura.find('F')+1]))==5){
            s+=p*p/2;
        }
        else{
            s+=M_PI*q*q/2;
        }
    }

    if(isdigit(figura[figura.find('A')+1])){
        int temp = std::stoi(std::string(1,figura[figura.find('A')+1]));
        if(temp==1){
            s-=x*x;
        }
        else if(temp==2){
            s-=x*x/2;
        }
        else if(temp==3){
            s-=M_PI*r*r/4;
        }
        else{
            s-=(r*r-M_PI*r*r/4);
        }
    }

    if(isdigit(figura[figura.find('B')+1])){
        int temp = std::stoi(std::string(1,figura[figura.find('B')+1]));
        if(temp==1){
            s-=x*x;
        }
        else if(temp==2){
            s-=x*x/2;
        }
        else if(temp==3){
            s-=M_PI*r*r/4;
        }
        else{
            s-=(r*r-M_PI*r*r/4);
        }
    }

    if(isdigit(figura[figura.find('D')+1])){
        int temp = std::stoi(std::string(1,figura[figura.find('D')+1]));
        if(temp==1){
            s-=x*x;
        }
        else if(temp==2){
            s-=x*x/2;
        }
        else if(temp==3){
            s-=M_PI*r*r/4;
        }
        else{
            s-=(r*r-M_PI*r*r/4);
        }
    }

    if(isdigit(figura[figura.find('C')+1])){
        int temp = std::stoi(std::string(1,figura[figura.find('C')+1]));
        if(temp==1){
            s-=x*x;
        }
        else if(temp==2){
            s-=x*x/2;
        }
        else if(temp==3){
            s-=M_PI*r*r/4;
        }
        else{
            s-=(r*r-M_PI*r*r/4);
        }
    }

    return s/mult;
}

float Figure::perimeter(){
    float per=2*(w+h);

    if(isdigit(figura[figura.find('A')+1])){
        int temp = std::stoi(std::string(1,figura[figura.find('A')+1]));
        if(temp==2){
            per = per-(x+x)+sqrt(2*x*x);
        }
        else if(temp==3){
            per = per-(r+r)+M_PI*r/2;
        }
        else if(temp==4){
            per = per-(r+r)+M_PI*r/2;
        }
    }

    if(isdigit(figura[figura.find('B')+1])){
        int temp = std::stoi(std::string(1,figura[figura.find('B')+1]));
        if(temp==2){
            per = per-(x+x)+sqrt(2*x*x);
        }
        else if(temp==3){
            per = per-(r+r)+M_PI*r/2;
        }
        else if(temp==4){
            per = p-(r+r)+M_PI*r/2;
        }
    }

    if(isdigit(figura[figura.find('D')+1])){
        int temp = std::stoi(std::string(1,figura[figura.find('D')+1]));
        if(temp==2){
            per = per-(x+x)+sqrt(2*x*x);
        }
        else if(temp==3){
            per = per-(r+r)+M_PI*r/2;
        }
        else if(temp==4){
            p = p-(r+r)+M_PI*r/2;
        }
    }

    if(isdigit(figura[figura.find('C')+1])){
        int temp = std::stoi(std::string(1,figura[figura.find('C')+1]));
        if(temp==2){
            per = per-(x+x)+sqrt(2*x*x);
        }
        else if(temp==3){
            per = per-(r+r)+M_PI*r/2;
        }
        else if(temp==4){
            per = per-(r+r)+M_PI*r/2;
        }
    }

    if(isdigit(figura[figura.find('E')+1])){
        if(std::stoi(std::string(1,figura[figura.find('E')+1]))==5){
            per+=p;
        }
        else{
            per = per - 2*q + M_PI*q;
        }
    }

    if(figura.find('F')+1!=figura.size()){
        if(std::stoi(std::string(1,figura[figura.find('F')+1]))==5){
            per+=p;
        }
        else{
            per = per - 2*q + M_PI*q;
        }
    }

    return per/mult;
}

void Figure::rotate(){
    std::string angle2=angle->text().toStdString();
    rotateFlag=true;
    for(const auto &i : angle2){
        if(!std::isdigit(i)){
            rotateFlag=false;
            break;
        }
    }
    if(rad2->isChecked()) deg = (deg+std::stoi(angle2))%360;
    else    deg = (deg-std::stoi(angle2))%360;
}

void Figure::changeWidth(){
    std::string cwidth=line1->text().toStdString();
    bool widthFlag=true;
    for(const auto &i : cwidth){
        if(!std::isdigit(i)){
            widthFlag=false;
            break;
        }
    }
    if(widthFlag){
        if(std::stoi(cwidth)>0){
            this->resize(std::stoi(cwidth),height());
        }
    }
}

void Figure::changeHeight(){
    std::string cheight=line2->text().toStdString();
    bool heightFlag=true;
    for(const auto &i : cheight){
        if(!std::isdigit(i)){
            heightFlag=false;
            break;
        }
    }
    if(heightFlag){
        if(std::stoi(cheight)>0 && std::stoi(cheight)<width()){
            this->resize(width(),std::stoi(cheight));
        }
    }
}
