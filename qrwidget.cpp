#include "qrwidget.h"
#include <QPainter>
#include <QImage>

QRWidget::QRWidget(QWidget *parent) : QWidget(parent)
{
    qr = NULL;
    setQRData("Hello QR Code");
}

QRWidget::~QRWidget()
{
    if(qr != NULL)
    {
        QRcode_free(qr);
    }
}

int QRWidget::getQRWidth() const
{
    if(qr != NULL)
    {
        return qr->width;
    }
    else
    {
        return 0;
    }
}

void QRWidget::setQRData(QString data)
{
    QRData = data;
    if(qr != NULL)
    {
        QRcode_free(qr);
    }
    qr = QRcode_encodeString(QRData.toStdString().c_str(),
                             1,
                             QR_ECLEVEL_L,
                             QR_MODE_8,
                             1);
    update();
}

QSize QRWidget::sizeHint()  const
{
    QSize s;
    if(qr != NULL)
    {
        int qr_width = qr->width > 0 ? qr->width : 1;
        s = QSize(qr_width * 4, qr_width * 4);
    }
    else
    {
        s = QSize(50, 50);
    }
    return s;
}

QSize QRWidget::minimumSizeHint()  const
{
    QSize s;
    if(qr != NULL)
    {
        int qr_width = qr->width > 0 ? qr->width : 1;
        s = QSize(qr_width, qr_width);
    }
    else
    {
        s = QSize(50, 50);
    }
    return s;
}

bool QRWidget::saveImage(const QString &fileName, int size, int quality, const char* format)
{
    if(size != 0 && !fileName.isEmpty())
    {
        QImage image(size, size, QImage::Format_Mono);
        QPainter painter(&image);
        draw(painter, size, size);
        return image.save(fileName, format, quality);
    }
    else
    {
        return false;
    }
}

void QRWidget::draw(QPainter &painter, int width, int height)
{
    if(NULL != qr)
    {
        QColor background(Qt::white);
        painter.setBrush(background);
        painter.setPen(Qt::NoPen);
        painter.drawRect(0, 0, width, height);

        QColor foreground(Qt::black);
        painter.setBrush(foreground);
        const int qr_width = qr->width > 0 ? qr->width : 1;
        const double scale=(double)((width > height) ? height : width)/qr_width*0.9;
        const int x_first = (width - scale*qr_width)/2;
        const int y_first = (height - scale*qr_width)/2;

        unsigned char *data = qr->data;
        for( int y = 0; y < qr_width; y ++)
        {
            for(int x = 0; x < qr_width; x++)
            {
                unsigned char b = *data++;
                if(b & 0x01)
                {
                    QRectF rect(x * scale + x_first, y * scale + y_first, scale, scale);
                    painter.drawRect(rect);
                }
            }
        }
    }
}

void QRWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    draw(painter, width(), height());
}
