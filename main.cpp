#include <qapplication.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include "PaintWidget.h"
#include "PaintWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    PaintWindow* p = new PaintWindow();
    p->setGeometry(400, 300, 512, 512);
    p->show();
    
    return app.exec();
}
