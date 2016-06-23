#ifndef CHOSEN_PLAYER_H
#define CHOSEN_PLAYER_H
#include <QLabel>
#include <QDialog>

namespace Ui {
class chosen_player;
}

class chosen_player : public QDialog{
    Q_OBJECT

public:
    explicit chosen_player(QWidget *parent = 0);
    ~chosen_player();
    QLabel * get_label2();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::chosen_player *ui;
};

#endif // CHOSEN_PLAYER_H
