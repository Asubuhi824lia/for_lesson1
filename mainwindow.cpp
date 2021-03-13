#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

int MainWindow::find_symb_code(QString symb) {
    for(int code = 0; code < this->alphabet.length(); code++) {
        if(this->alphabet[code] == symb)
            return code;
    }
    return -1;
}

QString MainWindow::encrypter(QString input_text) {

    QString output_text = "";

    for (int p = 0; p < input_text.length(); p++) {
        // находим смещение
        int k = 4*p*p + 15*p + 8;
        // код зашифрованной буквы
        int N = this->alphabet.length();
        int m = find_symb_code(input_text[p].toUpper());

        if(m == -1) {
            QString warning = "Текст содержит некорректные символы. Допускаются только символы кириллицы, запятая и точка.";
            return warning;
        }

        int L = (m + k)%N;

        while(L > N) {
            L -= N;
        }
        output_text += this->alphabet[L];
    }

    return output_text;
}

QString MainWindow::decrypter(QString input_text) {

    QString output_text = "";

    for (int p = 0; p < input_text.length(); p++) {
        // находим смещение
        int k = 4*p*p + 15*p + 8;
        // код расшифрованной буквы
        int N = this->alphabet.length();
        int L = find_symb_code(input_text[p].toUpper());
        if(L == -1) {
            QString warning = "Текст содержит некорректные символы. Допускаются только символы кириллицы, запятая и точка.";
            return warning;
        }

        int dif = L-k;

        while(dif < 0) {
            dif += N;
        }

        int m = (dif)%N;
        output_text += this->alphabet[m];
    }

    return output_text;
}

void MainWindow::encrypt_text() {
    QString text = ui->text_for_cipher->text();
    QString enc_text = encrypter(text);
    ui->cipher_text->setText(enc_text);
}

void MainWindow::decrypt_text() {
    QString text = ui->text_for_decrypted->text();
    QString dec_text = decrypter(text);
    ui->decrypted_text->setText(dec_text);
}

MainWindow::~MainWindow()
{
    delete ui;
}


