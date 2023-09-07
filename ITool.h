#ifndef _ITOOL_H
#define _ITOOL_H 1
#include <qwidget.h>

class ITool
{      
    public:
        virtual void mousePressEvent(QMouseEvent* event){};
        virtual void mouseMoveEvent(QMouseEvent* event){};
        virtual void mouseReleaseEvent(QMouseEvent* event){};
        virtual void updateImage(QImage* image){};
        virtual void updateColor(QColor* color){};
};
#endif
