#pragma once

#include <QWidget>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsView>



#include "mainwindow.h"
#include "player.h"
#include "mousecontrol.h"
#include "bullet.h"

class MainWindow;
class Player;


namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();


signals:
/* Сигнал для завершения работы приложения */
    void exit();
/* Сигналы для перемещения игрока */
    //======================================================================================================
    void playerUp();        //                                                                            \\
    void playerDown();      //                                                                            \\
    void playerRight();     //                                                                            \\
    void playerLeft();      //                                                                            \\
    void playerGo(char go); //                                                                            \\
    //======================================================================================================

private slots:
    void slotBullet(QPointF start, QPointF end);

public slots:

     void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::GameWindow *ui;
    MouseControl *scene;     // Объявляем графическую сцену


/* Место для расположения таймеров */
    //======================================================================================================
    QTimer *timer;     /* Объявляем игровой таймер, благодаря которому //                                 \\
                                         * будет производиться изменения положения объекта на сцене //    \\
                                         * При воздействии на него клавишами клавиатур //                 \\
                                         * */  //                                                         \\

    //======================================================================================================


    /* Место для расположения npc */
    //======================================================================================================

    //======================================================================================================


    /* Место для расположения игрока */
    //======================================================================================================
    Player *player;
    //======================================================================================================
};

