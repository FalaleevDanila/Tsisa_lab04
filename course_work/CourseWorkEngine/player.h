#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QKeyEvent>

#include <QTimer>


class Player : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    explicit Player(QObject *parent = nullptr);
    ~Player();




protected:
    // отрисовка игрока
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    // коллизии
    QRectF boundingRect() const;
    QPainterPath shape() const;


signals:
    // Сигнал для создания пули с параметрами траектории
    void signalBullet(QPointF start, QPointF end);
    // сигнал для передачи кооддинат игрока
    //void returnCoordinate(QPointF point);

public slots:
    // перемещение игрок по полю
    void goLeft();
    void goRight();
    void goUp();
    void goDown();
    void Go(char go);

    void slotTarget(QPointF point);
    // слот для обработки разрешения стрельбы
    void slotShot(bool shot);



private slots:
    void slotGameTimer();   // Игровой слот
    void slotBulletTimer(); // Слот проверки пули

private:
    qreal angle;            // Угол поворота графического объекта
    QPointF target;         // Положение курсора

    bool shot;              // Переменная состояния стрельбы
    QTimer *bulletTimer;    // Таймер пули
    QTimer *gameTimer;


    double health; // здоровье
};

#endif // PLAYER_H
