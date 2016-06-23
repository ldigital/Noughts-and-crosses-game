#include "game_setup.h"
#include "ui_game_setup.h"
#include "chosen_player.h"
#include "game_data.h"

game_setup::game_setup(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::game_setup){
       ui->setupUi(this);
       //lineEdit connections to enable text area to save text when return is pressed
       connect(ui->lineEdit, SIGNAL(returnPressed()), ui->centralWidget, SLOT(setFocus())); //connects the returned signal to the background focus
       connect(ui->lineEdit, SIGNAL(returnPressed()), ui->lineEdit, SLOT(clear())); //connects the return signal to also clear the box
       //lineEdit_2 connectons to enable text area to save text when return is pressed
       connect(ui->lineEdit_2, SIGNAL(returnPressed()), ui->centralWidget, SLOT(setFocus())); //connects the returned signal to the background focus
       connect(ui->lineEdit_2, SIGNAL(returnPressed()), ui->lineEdit_2, SLOT(clear())); //connects the return signal to also clear the box
}
//static variables
QString game_setup::p1_name;
QString game_setup::p2_name;
game_setup::~game_setup(){
    delete ui;
}
void game_setup::on_radioButton_clicked(bool checked){
    game_data option;
    option.set_game_type(true);
    //if radio button 1 is checked, then turn radio button 2 off, and enable player 1 input
    if(checked){
       ui->radioButton_2->setEnabled(false);
       ui->groupBox_3->setEnabled(true);
    }
}
void game_setup::on_radioButton_2_clicked(bool checked){
    option.set_game_type(false);
    //if radio button 2 is checked, then turn radio button 1 off, and enable player 2 input
    if(checked){
       ui->radioButton->setEnabled(false);
       ui->groupBox_3->setEnabled(true);
       ui->groupBox_4->setEnabled(true);
    }
}
void game_setup::on_lineEdit_returnPressed(){
    //takes player 1 name user input but then checks its a 1 player game before enabling coin flip
    p1_name = ui->lineEdit->text();
    if(option.get_game_type()){
        ui->groupBox_5->setEnabled(true);
    }
}
void game_setup::on_lineEdit_2_returnPressed(){
    //takes player 2 name user input, but then checks player 1 input has been entered before enabling coin flip
    p2_name = ui->lineEdit_2->text();
    if(option.get_game_type() == false){
         ui->groupBox_5->setEnabled(true);
    }
}
void game_setup::on_pushButton_clicked(){
    game_data call;
    call.select_a_player();
    destroy();
}
QString game_setup::get_p1_name(){
    return p1_name;
}
QString game_setup::get_p2_name(){
    return p2_name;
}
