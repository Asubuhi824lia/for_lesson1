#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QString alphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ ,.";

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QString encrypter(QString);
    QString decrypter(QString);

    int find_symb_code(QString);

public slots:
    void encrypt_text();
    void decrypt_text();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
