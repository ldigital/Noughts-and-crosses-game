/*this app was designed and written by Leon Harvey*/

#include "game_setup.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    game_setup w;
    w.show();
    return a.exec();
}
