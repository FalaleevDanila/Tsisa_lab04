#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPainter>
#include <QGraphicsScene>

class Bullet : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Bullet(QPointF start, QPointF end, QObject *parent = nullptr);
    ~Bullet();

signals:
    void shot();

public slots:

private:
    // коллизии
    QRectF boundingRect() const;
    // отрисовка пули
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    // Объявляем сигнатуру CallBack функции
    void (*callbackFunc)(QGraphicsItem * item);

private slots:
    // Слот для обработки полёта пули
    void slotTimerBullet();

private:
    // Слот для обработки таймера пули
    QTimer *timerBullet;

};


#endif // BULLET_H
