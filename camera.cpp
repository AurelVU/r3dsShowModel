#include "camera.h"

Camera::Camera()
{
    Transformation.setToIdentity();
}

void Camera::moveCamera(const QVector3D &positionChange)
{
    Transformation.translate(positionChange);
}

QVector3D Camera::getPointInSpace(const QVector3D &p)
{
    return p * Transformation;
}

QPoint Camera::getPointOnPlaneFromSpace(const QVector3D &p)
{
    QPoint p1(p.x(), p.y());
    return p1;
}

QPoint Camera::getPointOnPlaneFromAnCoordSyst(const QVector3D &p)
{
    return getPointOnPlaneFromSpace(getPointInSpace(p));
}

void Camera::turnCamera(const float dx, const float dy, const float dz)
{
    Transformation.rotate(1, dx, dy, dz);
}

void Camera::scaleCamera(const float scale)
{
    Transformation.scale(scale);
}
