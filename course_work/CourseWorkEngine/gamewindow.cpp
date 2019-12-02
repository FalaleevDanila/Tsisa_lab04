#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow)
{
        ui->setupUi(this);

        this->resize(1900,1000);          /// Задаем размеры виджета, то есть окна

        scene = new MouseControl();   /// Инициализируем графическую сцену

        player = new Player();


        ui->graphicsView->setScene(scene);  /// Устанавливаем графическую сцену в graphicsView
        ui->graphicsView->setRenderHint(QPainter::Antialiasing);    /// Устанавливаем сглаживание


        scene->setSceneRect(0,0,0,0); /// Устанавливаем область графической сцены


        //нарисуем органичение территории в графической сцене
        scene->addLine(-1050,-550, 1050,-550, QPen(Qt::yellow));
        scene->addLine(-1050, 550, 1050, 550, QPen(Qt::yellow));
        scene->addLine(-1050,-550,-1050, 550, QPen(Qt::yellow));
        scene->addLine( 1050,-550, 1050, 550, QPen(Qt::yellow));

        scene->addRect(  0,0,500, 30,QPen(Qt::NoPen),QBrush(Qt::darkBlue));
        scene->addRect(500,0, 30,150,QPen(Qt::NoPen),QBrush(Qt::darkBlue));
        scene->addRect(650,0, 30,150,QPen(Qt::NoPen),QBrush(Qt::darkBlue));
        scene->addRect(650,0, 300,30,QPen(Qt::NoPen),QBrush(Qt::darkBlue));

        scene->addRect(950,-450, 30,900,QPen(Qt::NoPen),QBrush(Qt::darkBlue));
        scene->addRect(-980,-450, 30,900,QPen(Qt::NoPen),QBrush(Qt::darkBlue));
        scene->addRect(-980,450,1960,20,QPen(Qt::NoPen),QBrush(Qt::darkBlue));
        scene->addRect(-980,-450,1960,20,QPen(Qt::NoPen),QBrush(Qt::darkBlue));


        scene->addRect(0,   0, 30, 450,QPen(Qt::NoPen),QBrush(Qt::darkBlue));
        scene->addRect(80,-450, 30, 150,QPen(Qt::NoPen),QBrush(Qt::darkBlue));
        scene->addRect(500,-450, 30, 250,QPen(Qt::NoPen),QBrush(Qt::darkBlue));
        scene->addRect(800,-450, 30, 150,QPen(Qt::NoPen),QBrush(Qt::darkBlue));

        scene->addRect(-800,-450, 30, 150,QPen(Qt::NoPen),QBrush(Qt::darkBlue));
        scene->addRect(-650,-150, 30, 450,QPen(Qt::NoPen),QBrush(Qt::darkBlue));
        scene->addRect(-350,-300, 30, 250,QPen(Qt::NoPen),QBrush(Qt::darkBlue));


        scene->addRect(950,-450, 30,900,QPen(Qt::NoPen),QBrush(Qt::darkBlue));

        scene->addItem(player);        /// Добавляем на сцену игрока
        player->setPos(-100,-30);      /// Устанавливаем игрока в соответствующие координаты

         /*connect(this, &Widget::playerUp, player, &Player::goUp);
         connect(this, &Widget::playerDown, player, &Player::goDown);
         connect(this, &Widget::playerLeft, player, &Player::goLeft);
         connect(this, &Widget::playerRight, player, &Player::goRight);
         */



         connect(this, &GameWindow::playerGo, player , &Player::Go);


         ui->graphicsView->setMouseTracking(true);



         // Соединяем сигнала стрельбы с графической сцены со слотом разрешения стрельбы игрока
         connect(scene, &MouseControl::signalShot, player, &Player::slotShot);
         // Соединяем сигнал на создание пули со слотом, создающим пули в игре
         connect(player, &Player::signalBullet, this, &Widget::slotBullet);




         connect(scene, &MouseControl::signalTargetCoordinate, player, &Player::slotTarget);

    }

    GameWindow::~GameWindow()
    {
        delete ui;
    }


    void GameWindow::keyPressEvent(QKeyEvent *event)
    {

       int key = event->key();
       if (key == Qt::Key_Tab) {

           emit exit();
           this->close();
       }
       if(key == Qt::Key_A){

           emit playerGo('l');
                                           /* Продвигаем объект на 15 пискселей влево
                                            * перетранслировав их в координатную систему
                                            * графической сцены
                                            * */
       }
       if(key == Qt::Key_D){

           emit playerGo('r');
                                           /* Продвигаем объект на 15 пискселей вправо
                                            * перетранслировав их в координатную систему
                                            * графической сцены
                                            * */
       }
       if(key == Qt::Key_W){

           emit playerGo('g');
                                           /* Продвигаем объект на 15 пискселей вперёд
                                            * перетранслировав их в координатную систему
                                            * графической сцены
                                            * */
       }
       if(key == Qt::Key_S){

           emit playerGo('d');
                                           /* Продвигаем объект на 15 пискселей назад
                                            * перетранслировав их в координатную систему
                                            * графической сцены
                                            * */
       }
    }

    void Widget::slotBullet(QPointF start, QPointF end)
    {
        // Добавляем на сцену пулю
        scene->addItem(new Bullet(start, end));
    }
