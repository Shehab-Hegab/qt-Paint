#ifndef _CURVE_H
#define _CURVE_H 1

#include "BaseLine.h"
#include <qwidget.h>
#include <QMouseEvent>
#include<qpoint.h>
#include <QPointF>
#include <vector>

class Curve : public BaseLine
{  
    public:
        Curve(QImage* image, QColor* color,  QWidget* parent);
    
    private:
        void drawLine(QColor color);
        QPointF findMidpoint(QPointF* a, QPointF* b, double t);
        std::vector<QPointF> findPoint(std::vector<QPointF> points, double t);
};

#endif
