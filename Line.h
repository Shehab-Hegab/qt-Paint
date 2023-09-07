#ifndef _LINE_H
#define _LINE_H 1

#include "BaseLine.h"
#include <qwidget.h>
#include <QMouseEvent>

class Line : public BaseLine
{  
    public:
        Line(QImage* image, QColor* color, QWidget* parent);
    
    private:
        void drawLine(QColor color);
};

#endif
