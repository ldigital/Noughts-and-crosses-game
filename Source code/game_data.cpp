#include "game_data.h"
#include <cstdlib>  //need to include this header file for srand()
#include <ctime>    // need to include this header file for time()
#include "chosen_player.h"
#include "game.h"
#include <sstream>
#include "game_setup.h"
#include <QString>
#include "game_result_display.h"

bool game_data::_game_type;
int game_data::_marker;
int game_data::_choose_start_player;
bool game_data::_is_first_move;
QString game_data::_current_character;
QString game_data::_colour_line;
QString game_data::_full_text;

game_data::game_data(){
    _is_first_move = false;
    _move_count = 0;

    for(int i = 0; i < 9; i++){
        _store_button_assignment[i] = i; //prepare an array to store all button assinment data, and store them to a corresponding array slot, to imitate board layout
    }
}

void game_data::select_a_player(){
    /*this function is called from game setup coin flip button pressed. to start with, it uses srand() and rand with a range of 0-1 to randomly
    choose out of 2 players at any time. it then needs to use that number in the right game type, true being a human vs computer game and
    flase being a human vs human game. this will display the right person in the right game type. it also sets a marker to seperate each condition
    to be used later, to actually let the right person start the game as displayed. finally it instantiates the chosen player display with
    the set information*/
    QString result;
    std::ostringstream convert_to_string; //need to convert result of numeric rand() operation into string data to be displayed
    srand(time(NULL));  //using the time function as an argument to srand, it changes the randomness every second of real-time

    int low = 0;
    int high = 1;

    convert_to_string << rand() % (high - low + 1) + low;
    game_setup * labels = new game_setup; //take user info from game_setup class to display in chosen_player ui

    if(_game_type == true){  //This process is to determine who won the coin flip, so A sends a message for display, and B sets a marker for further processing
        if(convert_to_string.str() == "0"){
           _marker = 0;   //marker is to provide a way of separating conditions, for all possibilities, to be able to make sure the right person in the right game goes first as displayed.
           result = labels->get_p1_name(); //if chosen, display player 1 name
        }
        if(convert_to_string.str() == "1"){
           _marker = 1;
           result = "Computer"; //if chosen, display the computer as the opponent
        }
    }

    //same as a above for 2 player game...
    if(_game_type == false){
        if(convert_to_string.str() == "0"){
           _marker = 2;
           result = labels->get_p1_name();
        }
        if(convert_to_string.str() == "1"){
           _marker = 3;
           result = labels->get_p2_name();
        }
    }
    chosen_player * player_select = new chosen_player;
    player_select->get_label2()->setText(result);
    player_select->show();
}

void game_data::start_game(){
    /*this function is called from the chosen player display, if the user wished to play.after after instantiating the board (* start) and the
    the pointer to game setup for the board label display of player names, it next has to ascertain the type of game selected, true being 1 player
    vs computer and false beind 2 player human vs human. it then sets the boards name displays, then checks the marker setting (which previously
    specified which player will go first) to set the highlited colour to. notice that if the computer won the flip and gets to go first
    meaning marker is set to 1, it also launches the computers first move from here. after the computers first move, all others will be from
    the board, in response to human clicks, so this happens only once for computer moves.*/

    //This is where the main game board is created and setup...
    game * start = new game;
    game_setup * labels = new game_setup;

    if(_game_type == true){ //check if a 1 player game human vs computer has been selected
       start->get_label1()->setText(labels->get_p1_name());
       start->get_label3()->setText("Computer");

       if(_marker == 0){
          start->get_label1()->setStyleSheet("color : orange");
       }

       if(_marker == 1){   //This is where the computer AI begins; check computer marker id is selected
          //if computer player then call its function to get a random number, and then use the number returned to assign to corresponding button
          start->computer_button_assignment();
          start->get_label3()->setStyleSheet("color : orange");
       }
    }

    if(_game_type == false){  //check if a 2 player game human vs human has been selected
       start->get_label1()->setText(labels->get_p1_name());
       start->get_label3()->setText(labels->get_p2_name());

       if(_marker == 2){
          start->get_label1()->setStyleSheet("color : orange");
       }

       if(_marker == 3){
          start->get_label3()->setStyleSheet("color : orange");
       }
    }
    start->show();
}
int game_data::first_move(){
    /*this function is called from button assignment is responsible for the correct player starting the game. it uses info taken
    from prevoius functions up this point, in order to decide what happens next. there are to main conditions for deciding game type
    1 player true or 2 player false, and then checks the marker to give right person. the return value 1-4 gives the person to start*/

    //1 player game
    if(_game_type == true && _marker == 0){
        //1 player of 1 player game
        return 1;
    }

    if(_game_type == true && _marker == 1){
        //computer player of 1 player game
        return 2;
    }

    //2 player game
    if(_game_type == false && _marker == 2){
        //1 player of 2 player game
        return 3;
    }

    if(_game_type == false && _marker == 3){
        //2 player of 2 player game
        return 4;
    }

    return 0;
}
int game_data::button_assignment(QPushButton * button, int button_id){
    /*this function is called from all button clicks on the game board. the idea is that when button clicks are made from the actual board,
    they have no idea what they are until they come here. so the board simply sends the signal of a click which inturn calls this function
    and sends to it a pointer of the button pressed, as well as a button id to be able to distinguish from. also note this function is only
    for processing human button clicks, 1 player or 2 player. computer button assignment has its own function. moving on it checks if
    first move has been made or not. if not then it needs to call first move function and save the result to the choose start player variable.
    it is now only conceren is which value X or O to assign... to do this it divides the possibilities between 'who will need to be X? player 1
    of both game types, and 'who will need to be O? computer of 1 player type or player 2 of 2 player type*/

    if(_is_first_move == false){  //this will check that the first move and subsequent character assignment is only executed once, because all moves will need to access this method.
       _choose_start_player = first_move();

       if(_choose_start_player == 1 || _choose_start_player == 3){
          button->setText("X"); //set value to actual button to be used in game only (after this we don't need the button for its data)
          _current_character = button->text(); //when assignment is made, need to also store the character for future reference
          _store_button_assignment[button_id] = _current_character; //use the button id to access specific array elements, and assign value.
          _is_first_move = true; //set this to true to prevent 'start player' code from running more than once.
          _move_count++;
          return 1;
       }

       if(_choose_start_player == 2 || _choose_start_player == 4){
          button->setText("O");
          _current_character = button->text();
          _store_button_assignment[button_id] = _current_character;
          _is_first_move = true;
          _move_count++;
          return 2;
       }
    }

    //from this point on it means that the correct person has made the first move according to who won the coin flip, so all other
    //human moves will be looped from here.

    if(_is_first_move == true){
       if(_current_character == "X"){
          button->setText("O");
          _current_character = button->text();
          _store_button_assignment[button_id] = _current_character;
          _is_first_move = true;
          _move_count++;
          return 3;
        }

        if(_current_character == "O"){
           button->setText("X");
           _current_character = button->text();
           _store_button_assignment[button_id] = _current_character;
           _is_first_move = true;
           _move_count++;
           return 4;
        }
    }
}
int game_data::computer_moves(){
    /*the computer moves function gets called from the game class after all button clicks. this is the special function where the computer
    ai algorithm happens. the computer has to be able to make its own moves... so this is done by giving the computer a srand() call with a
    range of 1-9. it is 0-8 here because the array elements it will be assigned to. it will now check for first move similar to the human
    button assignment function, but it will assign O because that is always the computers character. after choosing a random number in the
    range, it then assigns the value to the array. note this can only do this once and therefore choose anywhere because no previuos
    first move had been made. when a first move does exist it then has to check in a loop if the number chosen is available or not, if not
    get another number and try again, if so, then assign that value to that array location, and return the result to the function caller*/

    srand(time(NULL));  //using the time function as an argument to srand, it changes the randomness every second of real-time
    int computer_selection;
    int low = 0;
    int high = 8;

    if(_is_first_move == false){ //if its the computer to make first move, then this code is to be run once.
       _current_character = "O";  //the computer will always be "O";
       computer_selection = rand() % (high - low + 1) + low;
       _store_button_assignment[computer_selection] = _current_character;  //store the random number to the array with the computers value "O"
       _is_first_move = true;
       _move_count++;
       return computer_selection;
    }

    //from this point all computer moves will be generated if a first move exists.
    if(_is_first_move == true){
       while(1){
          computer_selection = rand() % (high - low + 1) + low;

          if(_store_button_assignment[computer_selection] == "X" || _store_button_assignment[computer_selection] == "O"){
             continue;
          }

          else{
              _store_button_assignment[computer_selection] = "O";
              break;
          }
       }
        _current_character = "O";
        _move_count++;
        return computer_selection;
    }
}

void game_data::winning_line(){
   /*evertime a button click is made this function will be called to check if the current button is part of a winning line. if so it sets
   a message, and returns a code to the function caller. if no there are no winning lines, and total number of possible moves have been made
   9, then display different message that there was no win. for the O line checks there are two different message systems for player 2 or
   computer because the both use O*/

   //this first area sets all the message displays to the user when a game ends; wether a win or not. It must however concat
   //name strings and messages to give the right display.

    game_setup * labels = new game_setup;
   QString horizontal = " won with a HORIZONTAL line!";
   QString vertical = " won with a VERTICAL line!";
   QString diagonal = " won with a DIAGONAL line!";
   QString player1 = labels->get_p1_name();
   QString player2 = labels->get_p2_name();
   QString computer = "The computer";

   //horizontal wins
   if(_store_button_assignment[0] == "X" &&
      _store_button_assignment[1] == "X" &&
      _store_button_assignment[2] == "X"){ // 1 2 3 line win

       _full_text = player1 + horizontal;
          _colour_line = "X-123";
   }
   if(_store_button_assignment[0] == "O" &&
      _store_button_assignment[1] == "O" &&
      _store_button_assignment[2] == "O"){ // 1 2 3 line win

       if(_game_type == true){
             _full_text = computer + horizontal;
             _colour_line = "O-123";
          }

          else{
             _full_text = player2 + horizontal;
             _colour_line = "O-123";
          }
   }

   if(_store_button_assignment[3] == "X" &&
       _store_button_assignment[4] == "X" &&
       _store_button_assignment[5] == "X"){ // 4 5 6 line win

            _full_text = player1 + horizontal;
            _colour_line = "X-456";
    }

    if(_store_button_assignment[3] == "O" &&
       _store_button_assignment[4] == "O" &&
       _store_button_assignment[5] == "O"){ // 4 5 6 line win

            if(_game_type == true){
              _full_text = computer + horizontal;
              _colour_line = "O-456";
            }

            else{
               _full_text = player2 + horizontal;
               _colour_line = "O-456";
            }
    }

    if(_store_button_assignment[6] == "X" &&
       _store_button_assignment[7] == "X" &&
       _store_button_assignment[8] == "X"){ // 7 8 9 line win

            _full_text = player1 + horizontal;
            _colour_line = "X-789";
    }

    if(_store_button_assignment[6] == "O" &&
       _store_button_assignment[7] == "O" &&
       _store_button_assignment[8] == "O"){ // 7 8 9 line win

            if(_game_type == true){
               _full_text = computer + horizontal;
               _colour_line = "O-789";
            }

            else{
                _full_text = player2 + horizontal;
                _colour_line = "O-789";
            }
    }

    //vertical wins
    if(_store_button_assignment[0] == "X" &&
       _store_button_assignment[3] == "X" &&
       _store_button_assignment[6] == "X"){ // 1 4 7 line win

            _full_text = player1 + vertical;
            _colour_line = "X-147";
    }

    if(_store_button_assignment[0] == "O" &&
       _store_button_assignment[3] == "O" &&
       _store_button_assignment[6] == "O"){ // 1 4 7 line win

            if(_game_type == true){
               _full_text = computer + horizontal;
               _colour_line = "O-147";
            }

            else{
            _full_text = player2 + horizontal;
            _colour_line = "O-147";
            }
    }

    if(_store_button_assignment[1] == "X" &&
       _store_button_assignment[4] == "X" &&
       _store_button_assignment[7] == "X"){ // 2 5 8 line win

            _full_text = player1 + vertical;
            _colour_line = "X-258";
    }

    if(_store_button_assignment[1] == "O" &&
       _store_button_assignment[4] == "O" &&
       _store_button_assignment[7] == "O"){ // 2 5 8 line win

            if(_game_type == true){
               _full_text = computer + horizontal;
               _colour_line = "O-258";
            }

            else{
            _full_text = player2 + horizontal;
            _colour_line = "O-258";
            }
    }

    if(_store_button_assignment[2] == "X" &&
       _store_button_assignment[5] == "X" &&
       _store_button_assignment[8] == "X"){ // 3 6 9 line win

             _full_text = player1 + vertical;
             _colour_line = "X-369";
    }

    if(_store_button_assignment[2] == "O" &&
       _store_button_assignment[5] == "O" &&
       _store_button_assignment[8] == "O"){ // 3 6 9 line win
            if(_game_type == true){
             _full_text = computer + horizontal;
             _colour_line = "O-369";
            }
            else{
            _full_text = player2 + horizontal;
            _colour_line = "O-369";
            }
    }
    //diagonal wins
    if(_store_button_assignment[0] == "X" &&
       _store_button_assignment[4] == "X" &&
       _store_button_assignment[8] == "X"){ // 1 5 9 line win

            _full_text = player1 + diagonal;
            _colour_line = "X-159";
    }

    if(_store_button_assignment[0] == "O" &&
       _store_button_assignment[4] == "O" &&
       _store_button_assignment[8] == "O"){ // 1 5 9 line win

            if(_game_type == true){
               _full_text = computer + horizontal;
               _colour_line = "O-159";
            }

            else{
                _full_text = player2 + horizontal;
                _colour_line = "O-159";
            }
    }

    if(_store_button_assignment[2] == "X" &&
       _store_button_assignment[4] == "X" &&
       _store_button_assignment[6] == "X"){ // 3 5 7 line win

             _full_text = player1 + diagonal;
             _colour_line = "X-357";
    }

    if(_store_button_assignment[2] == "O" &&
       _store_button_assignment[4] == "O" &&
       _store_button_assignment[6] == "O"){ // 3 5 7 line win

        if(_game_type == true){
            _full_text = computer + horizontal;
            _colour_line = "O-357";
        }

        else{
            _full_text = player2 + horizontal;
            _colour_line = "O-357";
        }
    }
     //if no win code and all moves have been made send no win code for display
    if(_move_count == 9 && _colour_line == ""){
         _colour_line = "no-win";
    }
}

//this very little function is responsible for clearing the board
void game_data::reset_game(){
    _colour_line = "";
}

//all getters and setters...
void game_data::set_game_type(bool val){
    _game_type = val;
}

bool game_data::get_game_type(){
    return _game_type;
}

QString game_data::get_colour_line(){
    return _colour_line;
}

bool game_data::get_is_first_move(){
    return _is_first_move;
}

void game_data::set_is_first_move(bool val){
    _is_first_move = val;
}

QString game_data::get_full_text(){
    return _full_text;
}

QString game_data::get_current_character(){
    return _current_character;
}

int game_data::get_marker(){
    return _marker;
}


