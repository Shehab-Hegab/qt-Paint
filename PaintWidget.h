#ifndef _PAINT_WIDGET_H
#define _PAINT_WIDGET_H 1
#include <qwidget.h>
#include "ITool.h"

class PaintWidget : public QWidget
{
    Q_OBJECT
    
    public:
        PaintWidget(QWidget* parent = 0);
        PaintWidget(QString filename, QWidget* parent = 0);
        ~PaintWidget();
        
        void mousePressEvent(QMouseEvent* event);
        void mouseMoveEvent(QMouseEvent* event);
        void mouseReleaseEvent(QMouseEvent* event);
        void paintEvent(QPaintEvent* event);
        void resizeEvent(QResizeEvent* event);
        void save(QString filename);
        void setTool(std::string toolname);
        void setColor(std::string colorName);
        
    private:
        QImage* _image;
        QColor* _color;
        ITool* _tool;
        
        void paintArea(int x, int y);
};

#endif
