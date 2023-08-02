#include "mainwindow.h"
#include <QPixmap>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    openButton.setText("Open");
    layout.addWidget(&pathLineEdit);
    layout.addWidget(&openButton);
    layout.addWidget(&imageLabel);
    setLayout(&layout);

    connect(&openButton, &QPushButton::clicked, this, &MainWindow::onOpenButtonClicked);
}

void MainWindow::onOpenButtonClicked()
{
    QString imagePath = pathLineEdit.text(); // Получаем текст из lineEdit

    if (!imagePath.isEmpty() && QFile::exists(imagePath)) // Проверяем, что путь не пустой и файл существует
    {
        QPixmap image(imagePath);
        imageLabel.setPixmap(image.scaled(300, 300, Qt::KeepAspectRatio));
    }
}

void MainWindow::updateImage()
{
    if (!imagePath.isEmpty() && QFile::exists(imagePath))
    {
        QPixmap image(imagePath);
        imageLabel.setPixmap(image.scaled(300, 300, Qt::KeepAspectRatio));
    }
}
