<<<<<<< HEAD
#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H

#include <QObject>
#include <QImage>

class ImageHandler : public QObject
{
    Q_OBJECT
public:
    explicit ImageHandler(QObject *parent = 0);

    QImage extractQImage(QObject *imageObj,
                         const double offsetX = 0 , const double offsetY = 0,
                         const double width = 0, const double height = 0);

public slots:
    void save(QObject *item, const QString &path,
              const double offsetX = 0, const double offsetY = 0,
              const double width = 0, const double height = 0);
};

#endif // IMAGEHANDLER_H
=======
#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H

#include <QObject>
#include <QImage>

class ImageHandler : public QObject
{
    Q_OBJECT
public:
    explicit ImageHandler(QObject *parent = 0);

    QImage extractQImage(QObject *imageObj,
                         const double offsetX = 0 , const double offsetY = 0,
                         const double width = 0, const double height = 0);

public slots:
    void save(QObject *item, const QString &path,
              const double offsetX = 0, const double offsetY = 0,
              const double width = 0, const double height = 0);
};

#endif // IMAGEHANDLER_H
>>>>>>> a0704cdfb69a2f6500e41ff290152659cde81b18
