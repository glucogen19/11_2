#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onOpenButtonClicked();

private:
    QLineEdit pathLineEdit;
    QLabel imageLabel;
    QPushButton openButton;
    QVBoxLayout layout;
    QString imagePath; // Добавим поле для хранения пути к изображению

    void updateImage(); // Метод для обновления изображения
};

#endif // MAINWINDOW_H
