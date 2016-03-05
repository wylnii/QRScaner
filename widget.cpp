#include "widget.h"
#include "ui_widget.h"
#include "QZXing.h"
#include <QDesktopWidget>
#include <QScreen>
#include <QtGui>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
//    setWindowFlags(Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);
//    this->setWindowOpacity(0.5);//全体透明（指的是窗体，标题栏以及上面所有的控件都透明）里面的参数可以控制透明度。

//    QPalette pal = palette();
//    pal.setColor(QPalette::Background, QColor(0x00,0xff,0x00,0x00));
//    setPalette(pal);
//    setAttribute(Qt::WA_TranslucentBackground, true);
//    setStyleSheet ("background-color:transparent");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QZXing qrDecoder(QZXing::DecoderFormat_QR_CODE,this);

    QScreen *screen = QApplication::primaryScreen();

//    QRect rect(this->geometry());
    QPixmap pic = screen->grabWindow(this->winId());
//    QPixmap pic = screen->grabWindow(QApplication::desktop()->winId(),rect.x(),rect.y(),rect.width(),rect.height());
    pic.save("window.jpg","jpg",100);
    QImage img = pic.toImage();
    QString msg = qrDecoder.decodeImage(img);
    ui->label->setText(msg);
    qDebug()<<msg;
}

void Widget::on_pushButton_2_clicked()
{
    ui->widget->setQRData(ui->lineEdit->text());
}
