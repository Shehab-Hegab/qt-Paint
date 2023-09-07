#ifndef _BASELINE_H
#define _BASELINE_H 1

#include "ITool.h"
#include <qwidget.h>
#include <QMouseEvent>
#include <vector>

class BaseLine : public ITool
{  
    public:
        BaseLine(QImage* image, QColor* color, QWidget* parent);
        
        void mousePressEvent(QMouseEvent* event);
        void mouseMoveEvent(QMouseEvent* event);
        void mouseReleaseEvent(QMouseEvent* event);
        void updateImage(QImage* image);
        void updateColor(QColor* color);
        void setPoints(std::vector<QPoint> points);
    
    protected:
        QImage* _image;
        QImage* _unselected_icon;
        QImage* _selected_icon;
        QColor* _color;
        QWidget* _parent;
        std::vector<QPoint> _points;
        int _range;
        int _selected;
        
        void drawPoint(int x, int y, bool focus);
        void removePoint(int x, int y);
        virtual void drawLine(QColor color);
};

#endif
