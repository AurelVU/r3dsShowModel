#ifndef SCENE_H
#define SCENE_H

#include <QWidget>
#include <QVector2D>
#include <QVector3D>
#include <QVector>
#include <QPainter>
#include <model.h>
#include <camera.h>
class Scene : public QWidget
{
public:
    QVector<Model> models;
    Scene(QWidget *parent = nullptr);
    Camera camera;
    Scene(QVector<Model> &_models);
    void paintEvent(QPaintEvent *event) override;
};

#endif // SCENE_H
