#include "BaseLine.h"
#include <qwidget.h>
#include <QMouseEvent>
#include <math.h>
#include <qpainter.h>
#include <vector>
#include<Qt>

using namespace std;

BaseLine::BaseLine(QImage* image, QColor* color, QWidget* parent)
{
    _image = image;
    _color = color;
    _parent = parent;
    _range = 5;
    _selected = -1;
    _points.resize(4);
    this->_unselected_icon = new QImage("./Images/line_unselected.jpg");
    this->_selected_icon = new QImage("./Images/line_selected.jpg");
    
    for (int i = 0; i < 4; ++i)
    {
        int p = 50 + 100 * i;
        _points[i] = QPoint(p, p);
        this->drawPoint(p, p, false);
    }
    
    for (int i = 0; i < 3; ++i)
    {
        this->drawLine(*_color);
    }
    
    _parent->repaint();
}

void BaseLine::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::RightButton)
    {
        this->drawLine(QColor("white"));
        _points.resize(_points.size() + 1);
        _points[_points.size()-1] = *(new QPoint(event->x(), event->y()));
        QPoint* p = &_points[_points.size()-1];
        this->drawPoint(p->x(), p->y(), false);
        this->drawLine(*_color);
    }
    else
    {
        int a = event->x();
        int b = event->y();
        this->_selected = -1;
        
        for (int i = 0; i < _points.size(); ++i)
        {
            //for every point
            QPoint p = _points[i];
            if (a > p.x() - _range && a < p.x() + _range && b > p.y() - _range && b < p.y() + _range)
            {
                this->drawPoint(p.x(), p.y(), true);
                this->_selected = i;
            }
        }
        
        for (int i = 0; i < _points.size(); ++i)
        {
            if (_selected != i)
            {
                QPoint p = _points[i];
                this->drawPoint(p.x(), p.y(), false);
            }
        }
    }
    
}
void BaseLine::mouseMoveEvent(QMouseEvent* event)
{
    if (_selected == -1) return;
    
    if (event->x() > _image->width() || event->x() < 0 || event->y() > _image->height() || event->y() < 0)
    {
        return;
    }
    
    QPoint* p = &_points[_selected];
    this->removePoint(p->x(), p->y()); //get rid of the old one...
    
    //get rid of the old lines
    if (_selected != 0)
    {
        this->drawLine(QColor("white"));
    }
    this->drawLine(QColor("white")); 
    
    p->setX(event->x());
    p->setY(event->y());
    this->drawPoint(p->x(), p->y(), true);
    
    //redraw lines
    if (_selected != 0)
    {
        this->drawLine(*_color);
    }
    if (_selected != 3)
    {
        this->drawLine(*_color);
    }
}
void BaseLine::mouseReleaseEvent(QMouseEvent* event)
{
    if (_selected == -1) return;
    
    QPoint p = _points[_selected];
    this->drawPoint(p.x(), p.y(), true);
}
void BaseLine::updateImage(QImage* image)
{
    _image = image;
}

void BaseLine::drawPoint(int x, int y, bool focus)
{
    QPainter painter(_image);
    
    QImage* image;
    if (!focus)
    {
        image = _unselected_icon;
    }
    else
    {
        image = _selected_icon;
    }
    int widthOffset = image->width()/2;
    int heightOffset = image->height()/2;
    
    QPoint imageOrigin(x - widthOffset, y - heightOffset);
    painter.drawImage(imageOrigin, *image);
}

void BaseLine::removePoint(int x, int y)
{
    QPainter painter(_image);
    
    QImage* image = new QImage(5, 5, QImage::Format_RGB32);
    image->fill(QColor("white").rgba());
    int widthOffset = image->width()/2;
    int heightOffset = image->width()/2;
    
    QPoint imageOrigin(x - widthOffset, y - heightOffset);
    painter.drawImage(imageOrigin, *image);
}

void BaseLine::drawLine(QColor color)
{
    //default line drawing implementation?
}

void BaseLine::updateColor(QColor* color)
{
    this->_color = color;
}

void BaseLine::setPoints(vector<QPoint> points)
{
    this->_points = points;
}
