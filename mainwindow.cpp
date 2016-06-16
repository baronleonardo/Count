#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QStringList>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_clear_btn_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_calculate_btn_clicked()
{
    ulong words_length   = 0;
    ulong letters_length = 0;

    QString textEdit_content = ui->textEdit->toPlainText();

    // split by space to get words only
    QStringList words =  textEdit_content.split( ' ', QString::SkipEmptyParts );
    ulong words_len = words.length();

    for (unsigned int iii = 0; iii < words_len; ++iii)
    {
        letters_length += words[iii].length();

        words_length++;
    }

    ui->words_number->setText( QString::number(words_length) );
    ui->letters_number->setText( QString::number(letters_length) );
}

void MainWindow::on_browse_btn_clicked()
{
    QString file_path = QFileDialog::getOpenFileName( this,
                                  "Select a file to open",
                                  QDir::homePath(),
                                  "Text files (*)" );
    QFile file( file_path );
    file.open( QIODevice::ReadOnly | QIODevice::Text );

    ui->textEdit->setText(file.readAll());

    file.close();

}
