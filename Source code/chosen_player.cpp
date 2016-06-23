#include "chosen_player.h"
#include "ui_chosen_player.h"
#include "game.h"
#include "game_setup.h"

chosen_player::chosen_player(QWidget *parent):
    QDialog(parent),
    ui(new Ui::chosen_player)
{
    ui->setupUi(this);
}

chosen_player::~chosen_player(){
    delete ui;
}

QLabel * chosen_player::get_label2(){
    return ui->label_2;
}

void chosen_player::on_pushButton_clicked(){
    QApplication::quit();
}

void chosen_player::on_pushButton_2_clicked(){
    game_data call;
    call.start_game();
    destroy();
}
