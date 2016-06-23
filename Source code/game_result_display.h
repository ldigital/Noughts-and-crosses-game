#ifndef GAME_RESULT_DISPLAY_H
#define GAME_RESULT_DISPLAY_H
#include <QLabel>

#include <QDialog>

namespace Ui {
class game_result_display;
}

class game_result_display : public QDialog{
    Q_OBJECT

public:
    explicit game_result_display(QWidget *parent = 0);
    ~game_result_display();
    QLabel * get_label();

signals:
    void close_current_game();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::game_result_display *ui;
};

#endif // GAME_RESULT_DISPLAY_H
