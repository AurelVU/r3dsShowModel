#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //    QVector2D p1(5, 5);
    //    QVector2D p2(100, 100);

    Model model("C:/Program Files/R3DS/Wrap 3.3/Models/Basemeshes/WrapHead.obj");
////    Set3DPoints st = model.triang();
    QVBoxLayout *layout = new QVBoxLayout();
    sc = new Scene(this);
    sc->camera.turnCamera(180, 0, 0);
    //sc->camera.moveCamera(QVector3D(-20, 0, 0));
    sc->camera.moveCamera(QVector3D(0, 0, 0));
    sc->camera.scaleCamera(4);
    sc->models.push_back(model);
    sc->update();
    layout->addWidget(sc);
    //ui->centralWidget->setLayout(layout);
    //ui->widget->setLayout(layout);
    ui->centralWidget->setLayout(layout);
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    //sc->camera.moveCamera(QVector3D(1.1, 0, 0));
    sc->camera.scaleCamera(1.005);
    sc->camera.turnCamera(180, 180, 0);
    sc->update();
}

void MainWindow::on_horizontalSlider_actionTriggered(int action)
{
    sc->camera.moveCamera(QVector3D(action , 0, 0));
    sc->update();
}

void MainWindow::on_verticalScrollBar_actionTriggered(int action)
{
    sc->camera.moveCamera(QVector3D(0 , action, 0));
    sc->update();
}

void MainWindow::on_horizontalSlider_2_actionTriggered(int action)
{
    sc->camera.turnCamera(action, 0, 0);
    sc->update();
}

void MainWindow::on_verticalSlider_actionTriggered(int action)
{
    sc->camera.turnCamera(0, action, 0);
    sc->update();
}
