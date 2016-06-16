#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_clear_btn_clicked();

    void on_calculate_btn_clicked();

    void on_browse_btn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
