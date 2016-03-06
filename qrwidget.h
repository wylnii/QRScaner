#ifndef QRWIDGET_H
#define QRWIDGET_H

#include <QWidget>
#include "qrencode/qrencode.h"

class QRWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QRWidget(QWidget *parent = 0);
    ~QRWidget();
    void setQRData(QString data);
    int getQRWidth() const;
    bool saveImage(const QString &fileName, int size, int quality = -1, const char* format = 0);

private:
    void draw(QPainter &painter, int width, int height);
    QString QRData;
    QRcode *qr;

signals:

protected:
    void paintEvent(QPaintEvent *);
    QSize sizeHint() const;
    QSize minimumSizeHint() const;
public slots:

};
#endif // QRWIDGET_H
