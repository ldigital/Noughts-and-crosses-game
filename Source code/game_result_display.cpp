#include "game_result_display.h"
#include "ui_game_result_display.h"
#include "game_data.h"
#include "game.h"

game_result_display::game_result_display(QWidget *parent):
    QDialog(parent),
    ui(new Ui::game_result_display){
    ui->setupUi(this);
    setGeometry(180, 300, 268 ,152);
    //a connection needs to be made from this class and its custom signal (close_current_game()), to the parent class (game) and its close slot.
    connect(this, SIGNAL(close_current_game()), this->parent(), SLOT(close()));
}
game_result_display::~game_result_display(){
    delete ui;
}
QLabel * game_result_display::get_label(){
    return ui->label;
}
void game_result_display::on_pushButton_clicked(){
    QApplication::quit();
}
void game_result_display::on_pushButton_2_clicked(){
    //if the user wishes to play again this code will be executed, and the signal will be emitted to close both windows
    emit close_current_game();
    game_data new_game;
    new_game.reset_game();
    new_game.select_a_player(); //this will lead to starting a new instance of the current game board settings, if the user wants to play another game
    destroy();
}
