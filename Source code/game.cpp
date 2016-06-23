#include "game.h"
#include "ui_game.h"
#include "game_result_display.h"

game::game(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::game){
       ui->setupUi(this);
       //need to set a guard on button on each move made so it dosen't get overwritten
       _is_button_1_clicked = false;
       _is_button_2_clicked = false;
       _is_button_3_clicked = false;
       _is_button_4_clicked = false;
       _is_button_5_clicked = false;
       _is_button_6_clicked = false;
       _is_button_7_clicked = false;
       _is_button_8_clicked = false;
       _is_button_9_clicked = false;
       _computer_move_count = 0;
}
game::~game()
{
    delete ui;
}
//all button click events
void game::on_pushButton_clicked(){
    if(_is_button_1_clicked == false){ //make sure button can only be pressed once...
       send.button_assignment(get_button1(), 0); //need to start numbers from zero because data passed to this function will store to an array
    }
    _is_button_1_clicked = true;

    /*everytime a human button click is generated, a computer move call is made straight after, so i need to implement a cap, to stop
    the computer trying to make a move if there are no more spaces. this is done by creating two conditions for deciding if a computer
    move should be made. the first is testing if the human made first move, because this should only allow the computer no more than
    4 moves, whereas if the computer went first, then it should allow no more than 5 computer moves*/

    if(send.get_game_type() && send.get_marker() == 0 && _computer_move_count < 4 ){
       _computer_move_count++;
       computer_button_assignment();
    }
    if(send.get_game_type() && send.get_marker() == 1 && _computer_move_count < 5 ){ //if its a 1 player vs computer game, then call the generate computer's moves.
        _computer_move_count++;
        computer_button_assignment();
    }

    /*upon every button clicked, a check is made to the winning line function to see if the result of clicking the current button was needed
    for a winning line. because the computer moves where called from this button click function, seperate computer move winning line
    checks need not be made.*/

    send.winning_line(); //check for winning line
    display_game_results();
    if(send.get_is_first_move() == false){ //this is a very important guard to ensure that the first move does not get reset, as it will try to
        send.set_is_first_move(true);   // So if it does get reset, it gets set back to true, meaning the first move has been made in game...
    }

    /*finally each button is responsible for toggling the highlighted player's names on the board by reacting to the current character*/
    if(send.get_current_character() == "X"){
        ui->label->setStyleSheet("color : rgb(50, 50, 50)");
        ui->label_3->setStyleSheet("color : orange");
    }

    else if(send.get_current_character() == "O"){
        ui->label->setStyleSheet("color : orange ");
        ui->label_3->setStyleSheet("color : rgb(50, 50, 50)");
    }
    //everything is repeated for all buttons...
}

void game::on_pushButton_2_clicked(){
    if(_is_button_2_clicked == false){
       send.button_assignment(get_button2(), 1);
    }
    _is_button_2_clicked = true;

    if(send.get_game_type() && send.get_marker() == 0 && _computer_move_count < 4 ){
       _computer_move_count++;
       computer_button_assignment();
    }

    if(send.get_game_type() && send.get_marker() == 1 && _computer_move_count < 5 ){
       _computer_move_count++;
       computer_button_assignment();
    }
    send.winning_line();
    display_game_results();

    if(send.get_is_first_move() == false){
        send.set_is_first_move(true);
    }

    if(send.get_current_character() == "X"){
        ui->label->setStyleSheet("color : rgb(50, 50, 50)");
        ui->label_3->setStyleSheet("color : orange");
    }

    else if(send.get_current_character() == "O"){
        ui->label->setStyleSheet("color : orange ");
        ui->label_3->setStyleSheet("color : rgb(50, 50, 50)");
    }
}

void game::on_pushButton_3_clicked(){
    if(_is_button_3_clicked == false){
       send.button_assignment(get_button3(), 2);
    }
    _is_button_3_clicked = true;

    if(send.get_game_type() && send.get_marker() == 0 && _computer_move_count < 4 ){ //if its a 1 player vs computer game, then call the generate computer's moves.
       _computer_move_count++;
       computer_button_assignment();
    }

    if(send.get_game_type() && send.get_marker() == 1 && _computer_move_count < 5 ){ //if its a 1 player vs computer game, then call the generate computer's moves.
        _computer_move_count++;
        computer_button_assignment();
    }
    send.winning_line();
    display_game_results();

    if(send.get_is_first_move() == false){
       send.set_is_first_move(true);
    }

    if(send.get_current_character() == "X"){
        ui->label->setStyleSheet("color : rgb(50, 50, 50)");
        ui->label_3->setStyleSheet("color : orange");
    }

    else if(send.get_current_character() == "O"){
        ui->label->setStyleSheet("color : orange ");
        ui->label_3->setStyleSheet("color : rgb(50, 50, 50)");
    }
}

void game::on_pushButton_4_clicked(){
    if(_is_button_4_clicked == false){
       send.button_assignment(get_button4(), 3);
    }
    _is_button_4_clicked = true;

    if(send.get_game_type() && send.get_marker() == 0 && _computer_move_count < 4 ){ //if its a 1 player vs computer game, then call the generate computer's moves.
       _computer_move_count++;
       computer_button_assignment();
    }

    if(send.get_game_type() && send.get_marker() == 1 && _computer_move_count < 5 ){ //if its a 1 player vs computer game, then call the generate computer's moves.
       _computer_move_count++;
       computer_button_assignment();
    }
    send.winning_line();
    display_game_results();

    if(send.get_is_first_move() == false){
       send.set_is_first_move(true);
    }

    if(send.get_current_character() == "X"){
       ui->label->setStyleSheet("color : rgb(50, 50, 50)");
       ui->label_3->setStyleSheet("color : orange");
    }

    else if(send.get_current_character() == "O"){
        ui->label->setStyleSheet("color : orange ");
        ui->label_3->setStyleSheet("color : rgb(50, 50, 50)");
    }
}

void game::on_pushButton_5_clicked(){
    if(_is_button_5_clicked == false){
       send.button_assignment(get_button5(), 4);
    }
    _is_button_5_clicked = true;

    if(send.get_game_type() && send.get_marker() == 0 && _computer_move_count < 4 ){ //if its a 1 player vs computer game, then call the generate computer's moves.
       _computer_move_count++;
       computer_button_assignment();
    }

    if(send.get_game_type() && send.get_marker() == 1 && _computer_move_count < 5 ){ //if its a 1 player vs computer game, then call the generate computer's moves.
       _computer_move_count++;
       computer_button_assignment();
    }
    send.winning_line();
    display_game_results();

    if(send.get_is_first_move() == false){
       send.set_is_first_move(true);
    }

    if(send.get_current_character() == "X"){
       ui->label->setStyleSheet("color : rgb(50, 50, 50)");
       ui->label_3->setStyleSheet("color : orange");
    }

    else if(send.get_current_character() == "O"){
       ui->label->setStyleSheet("color : orange ");
       ui->label_3->setStyleSheet("color : rgb(50, 50, 50)");
    }
}

void game::on_pushButton_6_clicked(){
    if(_is_button_6_clicked == false){
       send.button_assignment(get_button6(), 5);
    }
    _is_button_6_clicked = true;

    if(send.get_game_type() && send.get_marker() == 0 && _computer_move_count < 4 ){ //if its a 1 player vs computer game, then call the generate computer's moves.
       _computer_move_count++;
       computer_button_assignment();
    }

    if(send.get_game_type() && send.get_marker() == 1 && _computer_move_count < 5 ){ //if its a 1 player vs computer game, then call the generate computer's moves.
       _computer_move_count++;
       computer_button_assignment();
    }
    send.winning_line();
    display_game_results();

    if(send.get_is_first_move() == false){
       send.set_is_first_move(true);
    }

    if(send.get_current_character() == "X"){
       ui->label->setStyleSheet("color : rgb(50, 50, 50)");
       ui->label_3->setStyleSheet("color : orange");
    }

    else if(send.get_current_character() == "O"){
        ui->label->setStyleSheet("color : orange ");
        ui->label_3->setStyleSheet("color : rgb(50, 50, 50)");
    }
}
void game::on_pushButton_7_clicked(){
    if(_is_button_7_clicked == false){
       send.button_assignment(get_button7(), 6);
    }
    _is_button_7_clicked = true;

    if(send.get_game_type() && send.get_marker() == 0 && _computer_move_count < 4 ){ //if its a 1 player vs computer game, then call the generate computer's moves.
       _computer_move_count++;
       computer_button_assignment();
    }

    if(send.get_game_type() && send.get_marker() == 1 && _computer_move_count < 5 ){ //if its a 1 player vs computer game, then call the generate computer's moves.
       _computer_move_count++;
       computer_button_assignment();
    }
    send.winning_line();
    display_game_results();

    if(send.get_is_first_move() == false){
        send.set_is_first_move(true);
    }

    if(send.get_current_character() == "X"){
       ui->label->setStyleSheet("color : rgb(50, 50, 50)");
       ui->label_3->setStyleSheet("color : orange");
    }

    else if(send.get_current_character() == "O"){
       ui->label->setStyleSheet("color : orange ");
       ui->label_3->setStyleSheet("color : rgb(50, 50, 50)");
    }
}
void game::on_pushButton_8_clicked(){
    if(_is_button_8_clicked == false){
       send.button_assignment(get_button8(), 7);
    }
    _is_button_8_clicked = true;

    if(send.get_game_type() && send.get_marker() == 0 && _computer_move_count < 4 ){ //if its a 1 player vs computer game, then call the generate computer's moves.
       _computer_move_count++;
       computer_button_assignment();
    }

    if(send.get_game_type() && send.get_marker() == 1 && _computer_move_count < 5 ){ //if its a 1 player vs computer game, then call the generate computer's moves.
       _computer_move_count++;
       computer_button_assignment();
    }
    send.winning_line();
    display_game_results();

    if(send.get_is_first_move() == false){
       send.set_is_first_move(true);
    }

    if(send.get_current_character() == "X") {
       ui->label->setStyleSheet("color : rgb(50, 50, 50)");
       ui->label_3->setStyleSheet("color : orange");
    }

    else if(send.get_current_character() == "O"){
        ui->label->setStyleSheet("color : orange ");
        ui->label_3->setStyleSheet("color : rgb(50, 50, 50)");
    }
}

void game::on_pushButton_9_clicked(){
    if(_is_button_9_clicked == false){
       send.button_assignment(get_button9(), 8);
    }
    _is_button_9_clicked = true;

    if(send.get_game_type() && send.get_marker() == 0 && _computer_move_count < 4 ){ //if its a 1 player vs computer game, then call the generate computer's moves.
       _computer_move_count++;
       computer_button_assignment();
    }

    if(send.get_game_type() && send.get_marker() == 1 && _computer_move_count < 5 ){ //if its a 1 player vs computer game, then call the generate computer's moves.
       _computer_move_count++;
       computer_button_assignment();
    }
    send.winning_line();
    display_game_results();

    if(send.get_is_first_move() == false){
        send.set_is_first_move(true);
    }

    if(send.get_current_character() == "X"){
        ui->label->setStyleSheet("color : rgb(50, 50, 50)");
        ui->label_3->setStyleSheet("color : orange");
    }

    else if(send.get_current_character() == "O"){
        ui->label->setStyleSheet("color : orange ");
        ui->label_3->setStyleSheet("color : rgb(50, 50, 50)");
    }
}

void game::computer_button_assignment(){
    //this is where all computer AI moves are made in a 1 player human vs computer game.
    switch(send.computer_moves()){
        case 0:{
            ui->pushButton->setText("O");
            display_game_results();
            break;
        }

        case 1:{
            ui->pushButton_2->setText("O");
            display_game_results();
            break;
        }

        case 2:{
            ui->pushButton_3->setText("O");
            display_game_results();
            break;
        }

        case 3:{
            ui->pushButton_4->setText("O");
            display_game_results();
            break;
        }

        case 4:{
            ui->pushButton_5->setText("O");
            display_game_results();
            break;
        }

        case 5:{
            ui->pushButton_6->setText("O");
            display_game_results();
            break;
        }

        case 6:{
            ui->pushButton_7->setText("O");
            display_game_results();
            break;
        }

        case 7:{
            ui->pushButton_8->setText("O");
            display_game_results();
            break;
        }
        case 8:{
             ui->pushButton_9->setText("O");
             display_game_results();
             break;
        }
    }
    show();
}

void game::display_game_results(){
    game_result_display * results = new game_result_display(this);
    /*the display has to be instantiated within this class and not game_data because of the needed parent child relationship. The realtionship
    is needed because when the game ends and the results is shown, if the user wishes to play again, then both the display window
    and the current game window should be closed simoultaneously from the play again button click. This is done with
    a signal and slot connection, where the 'child' object (results), takes a pointer in its constructor to the parent class (game)
    then finally the connection is made in the constructor of the child class (game_result_display)*/

    //check for all winning lines that will use button 1, and if true change to red
    if(send.get_colour_line() == "X-123" || send.get_colour_line() == "O-123"){
        ui->pushButton->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_2->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_3->setStyleSheet("QPushButton {color: red}");
        results->setWindowTitle("Winner");
        results->get_label()->setText(send.get_full_text());
        results->show();
    }

    if(send.get_colour_line() == "X-147" || send.get_colour_line() == "O-147"){
        ui->pushButton->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_4->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_7->setStyleSheet("QPushButton {color: red}");
        results->setWindowTitle("Winner");
        results->get_label()->setText(send.get_full_text());
        results->show();
    }

    if(send.get_colour_line() == "X-157" || send.get_colour_line() == "O-157"){
        ui->pushButton->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_5->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_7->setStyleSheet("QPushButton {color: red}");
        results->setWindowTitle("Winner");
        results->get_label()->setText(send.get_full_text());
        results->show();
    }

    //check for all winning lines that will use button 2, and if true change to red
    if(send.get_colour_line() == "X-123" || send.get_colour_line() == "O-123"){
        ui->pushButton->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_2->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_3->setStyleSheet("QPushButton {color: red}");
        results->setWindowTitle("Winner");
        results->get_label()->setText(send.get_full_text());
        results->show();
    }

    if(send.get_colour_line() == "X-258" || send.get_colour_line() == "O-258"){
        ui->pushButton_2->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_5->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_8->setStyleSheet("QPushButton {color: red}");
        results->setWindowTitle("Winner");
        results->get_label()->setText(send.get_full_text());
        results->show();
    }

    //check for all winning lines that will use button 3, and if true change to red
    if(send.get_colour_line() == "X-123" || send.get_colour_line() == "O-123"){
        ui->pushButton->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_2->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_3->setStyleSheet("QPushButton {color: red}");
        results->setWindowTitle("Winner");
        results->get_label()->setText(send.get_full_text());
        results->show();
    }

    if(send.get_colour_line() == "X-369" || send.get_colour_line() == "O-369"){
        ui->pushButton_3->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_6->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_9->setStyleSheet("QPushButton {color: red}");
        results->setWindowTitle("Winner");
        results->get_label()->setText(send.get_full_text());
        results->show();
    }

    if(send.get_colour_line() == "X-357" || send.get_colour_line() == "O-357"){
        ui->pushButton_3->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_5->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_7->setStyleSheet("QPushButton {color: red}");
        results->setWindowTitle("Winner");
        results->get_label()->setText(send.get_full_text());
        results->show();
    }

    //check for all winning lines that will use button 4, and if true change to red
    if(send.get_colour_line() == "X-456" || send.get_colour_line() == "O-456"){
        ui->pushButton_4->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_5->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_6->setStyleSheet("QPushButton {color: red}");
        results->setWindowTitle("Winner");
        results->get_label()->setText(send.get_full_text());
        results->show();
    }

    if(send.get_colour_line() == "X-147" || send.get_colour_line() == "O-147"){
        ui->pushButton->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_4->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_7->setStyleSheet("QPushButton {color: red}");
        results->setWindowTitle("Winner");
        results->get_label()->setText(send.get_full_text());
        results->show();

    }

    //check for all winning lines that will use button 5, and if true change to red
    if(send.get_colour_line() == "X-456" || send.get_colour_line() == "O-456"){
        ui->pushButton_4->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_5->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_6->setStyleSheet("QPushButton {color: red}");
        results->setWindowTitle("Winner");
        results->get_label()->setText(send.get_full_text());
        results->show();
    }

    if(send.get_colour_line() == "X-258" || send.get_colour_line() == "O-258"){
        ui->pushButton_2->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_5->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_8->setStyleSheet("QPushButton {color: red}");
        results->setWindowTitle("Winner");
        results->get_label()->setText(send.get_full_text());
        results->show();
    }

    if(send.get_colour_line() == "X-159" || send.get_colour_line() == "O-159"){
        ui->pushButton->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_5->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_9->setStyleSheet("QPushButton {color: red}");
        results->setWindowTitle("Winner");
        results->get_label()->setText(send.get_full_text());
        results->show();
    }

    //check for all winning lines that will use button 6, and if true change to red
    if(send.get_colour_line() == "X-456" || send.get_colour_line() == "O-456"){
        ui->pushButton_4->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_5->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_6->setStyleSheet("QPushButton {color: red}");
        results->setWindowTitle("Winner");
        results->get_label()->setText(send.get_full_text());
        results->show();
    }

    if(send.get_colour_line() == "X-369" || send.get_colour_line() == "O-369"){
        ui->pushButton_3->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_6->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_9->setStyleSheet("QPushButton {color: red}");
        results->setWindowTitle("Winner");
        results->get_label()->setText(send.get_full_text());
        results->show();
    }

    //check for all winning lines that will use button 7, and if true change to red
    if(send.get_colour_line() == "X-789" || send.get_colour_line() == "O-789"){
        ui->pushButton_7->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_8->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_9->setStyleSheet("QPushButton {color: red}");
        results->setWindowTitle("Winner");
        results->get_label()->setText(send.get_full_text());
        results->show();
    }

    if(send.get_colour_line() == "X-147" || send.get_colour_line() == "O-147"){
        ui->pushButton->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_4->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_7->setStyleSheet("QPushButton {color: red}");
        results->setWindowTitle("Winner");
        results->get_label()->setText(send.get_full_text());
        results->show();
    }

    if(send.get_colour_line() == "X-357" || send.get_colour_line() == "O-357"){
        ui->pushButton_3->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_5->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_7->setStyleSheet("QPushButton {color: red}");
        results->setWindowTitle("Winner");
        results->get_label()->setText(send.get_full_text());
        results->show();
    }

    //check for all winning lines that will use button 8, and if true change to red
    if(send.get_colour_line() == "X-789" || send.get_colour_line() == "O-789"){
        ui->pushButton_7->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_8->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_9->setStyleSheet("QPushButton {color: red}");
        results->setWindowTitle("Winner");
        results->get_label()->setText(send.get_full_text());
        results->show();
    }
    if(send.get_colour_line() == "X-258" || send.get_colour_line() == "O-258"){
        ui->pushButton_2->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_5->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_8->setStyleSheet("QPushButton {color: red}");
        results->setWindowTitle("Winner");
        results->get_label()->setText(send.get_full_text());
        results->show();
    }

    //check for all winning lines that will use button 9, and if true change to red
    if(send.get_colour_line() == "X-789" || send.get_colour_line() == "O-789"){
        ui->pushButton_7->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_8->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_9->setStyleSheet("QPushButton {color: red}");
        results->setWindowTitle("Winner");
        results->get_label()->setText(send.get_full_text());
        results->show();
    }

    if(send.get_colour_line() == "X-159" || send.get_colour_line() == "O-159"){
        ui->pushButton->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_5->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_9->setStyleSheet("QPushButton {color: red}");
        results->setWindowTitle("Winner");
        results->get_label()->setText(send.get_full_text());
        results->show();
    }

    if(send.get_colour_line() == "X-369" || send.get_colour_line() == "O-369"){
        ui->pushButton_3->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_6->setStyleSheet("QPushButton {color: red}");
        ui->pushButton_9->setStyleSheet("QPushButton {color: red}");
        results->setWindowTitle("Winner");
        results->get_label()->setText(send.get_full_text());
        results->show();
    }

    if(send.get_colour_line() == "no-win"){
        results->setWindowTitle("No winner");
        results->get_label()->setText("No winner here, try again maybe? ");
        results->show();
    }
}
//gets player 1 & 2 name labels on the board
QLabel * game::get_label1(){
    return ui->label;
}

QLabel * game::get_label3(){
    return ui->label_3;
}

//gets all playing buttons...
QPushButton * game::get_button1(){
    return ui->pushButton;
}

QPushButton * game::get_button2(){
    return ui->pushButton_2;
}

QPushButton * game::get_button3(){
    return ui->pushButton_3;
}

QPushButton * game::get_button4(){
    return ui->pushButton_4;
}

QPushButton * game::get_button5(){
    return ui->pushButton_5;
}

QPushButton * game::get_button6(){
    return ui->pushButton_6;
}

QPushButton * game::get_button7(){
    return ui->pushButton_7;
}

QPushButton * game::get_button8(){
    return ui->pushButton_8;
}

QPushButton * game::get_button9(){
    return ui->pushButton_9;
}
