#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <game_data.h>

namespace Ui {
class game;
}

class game : public QMainWindow{
    Q_OBJECT

public:
    explicit game(QWidget *parent = 0);
    ~game();

    //gets player 1 & 2 name labels on the board
    QLabel * get_label1();
    QLabel * get_label3();
    void computer_button_assignment();
    void display_game_results();

    //get all playing buttons...
    QPushButton * get_button1();
    QPushButton * get_button2();
    QPushButton * get_button3();
    QPushButton * get_button4();
    QPushButton * get_button5();
    QPushButton * get_button6();
    QPushButton * get_button7();
    QPushButton * get_button8();
    QPushButton * get_button9();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();

private:
    Ui::game *ui;
    //sends all buttons to game_data for processing user input, and assigning characters

    game_data send;
    //these button checks are to prevent overwriting of values made by users
    bool _is_button_1_clicked;
    bool _is_button_2_clicked;
    bool _is_button_3_clicked;
    bool _is_button_4_clicked;
    bool _is_button_5_clicked;
    bool _is_button_6_clicked;
    bool _is_button_7_clicked;
    bool _is_button_8_clicked;
    bool _is_button_9_clicked;
    int _computer_move_count;
};

#endif // GAME_H
