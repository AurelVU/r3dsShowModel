#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <scene.h>
#include <QWidget>
#include <QVBoxLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Scene *sc;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event) override;

private slots:
    void on_horizontalSlider_actionTriggered(int action);

    void on_verticalScrollBar_actionTriggered(int action);

    void on_horizontalSlider_2_actionTriggered(int action);

    void on_verticalSlider_actionTriggered(int action);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
