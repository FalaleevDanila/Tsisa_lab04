#pragma once

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QLabel>

#include "gamewindow.h"


class Widget;

namespace Ui {
    class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void play();

private slots:
    // слот отвечающий за начало игры
    void on_play_clicked();

    // слот отвечающий за окончание работы приложения
    void on_exit_clicked();

private:
    Ui::MainWindow *ui;

    Widget *widget;

    //QLabel labelPic;
};
