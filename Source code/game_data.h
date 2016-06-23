//the sole purpose of this class is to provide a central point for the mechanics of the game, and controlling the overall game data.
#ifndef GAME_DATA_H
#define GAME_DATA_H
#include <QString>
#include <QPushButton>
#include <QObject>

class game; //forward decleration
class game_data : public QObject{
    //need to inherit from QObject and use the QOBJECT macro for connecting signals and slots for this class
    Q_OBJECT

    public:
        game_data();
        ~game_data(){}
        void set_game_type(bool val);
        bool get_game_type();
        void start_game();
        int first_move();
        bool get_is_first_move();
        void set_is_first_move(bool val);
        void select_a_player();
        QString get_colour_line();
        QString get_full_text();
        int computer_moves();
        int button_assignment(QPushButton * button, int button_id);
        void winning_line();
        void reset_game();
        QString get_current_character();
        int get_marker();

    private:
        game_data(const game_data & source){}
        game_data & operator =(const game_data & source){}
        int _move_count;
        static bool _game_type;
        static int _marker;
        static int _choose_start_player;
        static bool _is_first_move;
        int _computer_button_assignment_id;
        static QString _current_character;
        static QString _colour_line;
        static QString _full_text;
        QString _store_button_assignment[9]; //need an array to store button data info and assign them to a slot that imitates the actual
                                          //board layout. The reason for this that the data from the button objects will not be available
                                          //to other objects unless its data is static, and in this situation it is not the best solution
                                          //so this is an alternative.
};

#endif

