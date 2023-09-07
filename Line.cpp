#include "Line.h"
#include <qwidget.h>
#include <QMouseEvent>
#include <math.h>
#include <qpainter.h>

Line::Line(QImage* image, QColor* color, QWidget* parent) : BaseLine(image, color, parent)
{
    for (int i = 0; i < _points.size(); ++i)
    {
        this->drawLine(*_color);
    }
}

void Line::drawLine(QColor color)
{
    for (int i = 0; i < _points.size()-1;  ++i)
    {
        QPoint* p = &_points[i];
        QPoint* q = &_points[i + 1];
        
        for (double t = 0.0; t <= 1.0; t += 0.00001)
        {
            int dx = round(p->x() + (q->x() - p->x()) * t);
            int dy = round(p->y() + (q->y() - p->y()) * t);
            _image->setPixel(dx, dy, color.rgb());
        }
    }
}
