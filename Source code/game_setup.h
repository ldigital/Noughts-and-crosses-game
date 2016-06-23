#ifndef GAME_SETUP_H
#define GAME_SETUP_H

#include <QMainWindow>
#include "game_data.h"

namespace Ui {
class game_setup;
}

class game_setup : public QMainWindow{
    Q_OBJECT

public:
    explicit game_setup(QWidget *parent = 0);
    ~game_setup();
    QString get_p1_name();
    QString get_p2_name();

private slots:
    //player 1 and 2 radio buttons
    void on_radioButton_clicked(bool checked);
    void on_radioButton_2_clicked(bool checked);

    //player 1 and 2 user input boxes
    void on_lineEdit_returnPressed();
    void on_lineEdit_2_returnPressed();

    //coin flip player select
    void on_pushButton_clicked();

private:
    Ui::game_setup *ui;
    static QString p1_name;
    static QString p2_name;
    game_data option;
};

#endif // GAME_SETUP_H
