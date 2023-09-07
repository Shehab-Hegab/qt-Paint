#ifndef _BRUSH_H
#define _BRUSH_H 1

#include "ITool.h"
#include <qwidget.h>

class Brush : public ITool
{  
    public:
        Brush(QImage* image, QColor* color);
        
        void mousePressEvent(QMouseEvent* event);
        void mouseMoveEvent(QMouseEvent* event);
        void mouseReleaseEvent(QMouseEvent* event);
        void updateImage(QImage* image);
        void updateColor(QColor* color);
    
    private:
        void paintArea(int x, int y);
        QImage* _image;
        QColor* _color;
};

#endif
