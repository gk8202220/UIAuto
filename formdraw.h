#ifndef FORMDRAW_H
#define FORMDRAW_H

#include <QWidget>
#include <QPainter>
#include "pxcpjson.h"
#include <QJsonArray>
namespace Ui {
class FormDraw;
}

class FormDraw : public QWidget
{
    Q_OBJECT

public:
    explicit FormDraw(QWidget *parent = nullptr);
    ~FormDraw();
    void setPath(QJsonArray path);

private:
    Ui::FormDraw *ui;
    QString filePath;
    QJsonArray object;

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // FORMDRAW_H
