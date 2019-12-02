#include "player.h"
#include "iostream"
#include <math.h>

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
        angle += TwoPi;
    while (angle > TwoPi)
        angle -= TwoPi;
    return angle;
}
void Player::slotTarget(QPointF point)
{
    // Определяем расстояние до цели
    target = point;
    QLineF lineToTarget(QPointF(0, 0), mapFromScene(target));
    // Угол поворота в направлении к цели
    qreal angleToTarget = ::acos(lineToTarget.dx() / lineToTarget.length());
    if (lineToTarget.dy() < 0)
        angleToTarget = TwoPi - angleToTarget;
    angleToTarget = normalizeAngle((Pi - angleToTarget) + Pi / 2);

    /* В Зависимости от того, слева или справа находится Цель от Героя,
     * устанавливаем направление поворота Героя в данном тике таймера
     * */
    if (angleToTarget >= 0 && angleToTarget < Pi) {
        // Rotate left
        setRotation(rotation() - angleToTarget * 180 /Pi);
    } else if (angleToTarget <= TwoPi && angleToTarget > Pi) {
        // Rotate right
        setRotation(rotation() + (angleToTarget - TwoPi )* (-180) /Pi);
    }


}

Player::Player(QObject *parent) : QObject(parent)
{
    angle = 0;     // Задаём угол поворота графического объекта
    setRotation(angle);     // Устанавилваем угол поворота графического объекта
    health = 100;

    gameTimer = new QTimer();   // Инициализируем игровой таймер
    // Подключаем сигнал от таймера и слоту обработки игрового таймера
    connect(gameTimer, &QTimer::timeout, this, &Player::slotGameTimer);
    //connect(gameTimer, &QTimer::timeout, this, &Player::Go);
    gameTimer->start(10);   // Стартуем таймер

    bulletTimer = new QTimer(); // Инициализируем таймер создания пуль
    connect(bulletTimer, &QTimer::timeout, this, &Player::slotBulletTimer);
    bulletTimer->start(1000/6); // Стреляем 6 раз в секунду
}

Player::~Player(){

}


void Player::goLeft(){

    setPos(mapToParent(-15, 0));
                                            /* Продвигаем объект на 5 пискселей влево
                                             * перетранслировав их в координатную систему
                                             * графической сцены
                                             * */
    if(!scene()->collidingItems(this).isEmpty()){
        this->setX(this->x() + 15);
    }

}

void Player::goRight(){

    setPos(mapToParent(15, 0));
                                            /* Продвигаем объект на 5 пискселей вправо
                                             * перетранслировав их в координатную систему
                                             * графической сцены
                                             * */
    if(!scene()->collidingItems(this).isEmpty()){
        this->setX(this->x() - 15);
    }
}
void Player::goUp(){

    setPos(mapToParent(0, -15));
                                            /* Продвигаем объект на 5 пискселей вперёд
                                             * перетранслировав их в координатную систему
                                             * графической сцены
                                             * */
    if(!scene()->collidingItems(this).isEmpty()){
        this->setY(this->y() + 15);
    }
}
void Player::goDown(){

    setPos(mapToParent(0, 15));
                                            /* Продвигаем объект на 5 пискселей назад
                                             * перетранслировав их в координатную систему
                                             * графической сцены
                                             * */
    if(!scene()->collidingItems(this).isEmpty()){
        this->setY(this->y() - 15);
    }


}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    QPolygon polygon;
    polygon << QPoint(0,-15) << QPoint(10,15) << QPoint(-10,15);
    painter->setBrush(Qt::red);
    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);

}

QPainterPath Player::shape() const
{

    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;

}

QRectF Player::boundingRect() const
{
    return QRectF(-20,-30,40,60); /// Ограничиваем область, в которой лежит треугольник
}


void Player::Go(char go){
    if(go=='l'){

        setPos(mapToParent(-15, 0));
                                                /* Продвигаем объект на 5 пискселей влево
                                                 * перетранслировав их в координатную систему
                                                 * графической сцены
                                                 * */
        if(!scene()->collidingItems(this).isEmpty()){
            this->setX(this->x() + 15);
        }

    }

    else if(go=='r'){

        setPos(mapToParent(15, 0));
                                                /* Продвигаем объект на 5 пискселей вправо
                                                 * перетранслировав их в координатную систему
                                                 * графической сцены
                                                 * */
        if(!scene()->collidingItems(this).isEmpty()){
            this->setX(this->x() - 15);
        }
    }
    else if(go=='g'){

        setPos(mapToParent(0, -15));
                                                /* Продвигаем объект на 5 пискселей вперёд
                                                 * перетранслировав их в координатную систему
                                                 * графической сцены
                                                 * */
        if(!scene()->collidingItems(this).isEmpty()){
            this->setY(this->y() + 15);
        }
    }
    else if(go=='b'){

        setPos(mapToParent(0, 15));
                                                /* Продвигаем объект на 5 пискселей назад
                                                 * перетранслировав их в координатную систему
                                                 * графической сцены
                                                 * */
        if(!scene()->collidingItems(this).isEmpty()){
            this->setY(this->y() - 15);
        }


    }
}

void Player::slotGameTimer()
{
    //=======================================================================================================
    //std::cout<<"yes\n";
    QLineF lineToTarget(QPointF(0, 0), mapFromScene(target));
    // Угол поворота в направлении к цели

    qreal angleToTarget = ::acos(lineToTarget.dx() / lineToTarget.length());
    if (lineToTarget.dy() < 0)
        angleToTarget = TwoPi - angleToTarget;
    angleToTarget = normalizeAngle((Pi - angleToTarget) + Pi / 2);

    /* В Зависимости от того, слева или справа находится Цель от Героя,
     * устанавливаем направление поворота Героя в данном тике таймера
     * */
    if (angleToTarget >= 0 && angleToTarget < Pi) {
        // Rotate left
        setRotation(rotation() - angleToTarget * 180 /Pi);

    } else if (angleToTarget <= TwoPi && angleToTarget > Pi) {
        // Rotate right
        setRotation(rotation() + (angleToTarget - TwoPi )* (-180) /Pi);
    }
}



void Player::slotBulletTimer()
{
    // Если стрельба разрешена, то вызываем сигнал на создание пули
    if(shot) emit signalBullet(mapToScene(0,-50), target);

}

void Player::slotShot(bool shot)
{
    this->shot = shot;  // Получаем разрешение или запрет на стрельбу
}
