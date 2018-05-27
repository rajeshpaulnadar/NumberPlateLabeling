#include "matdisplay.h"

matDisplay::matDisplay(QWidget *parent) : QLabel(parent)
{
    this->setMouseTracking(true);
}

matDisplay::~matDisplay()
{

}



void matDisplay::mousePressEvent(QMouseEvent *mouse_event)
{
    if(mouse_event->button() == Qt::LeftButton)
    {
//        printf("LeftButton\n");
        QPoint mouse_pos = mouse_event->pos();

        if(mouse_pos.x() <= this->size().width() && mouse_pos.y() <= this->size().height())
        {
            if(mouse_pos.x() >= 0 && mouse_pos.x() >= 0)
            {
                this->P1 =mouse_pos;
                emit sendMousePosition(mouse_pos);
            }
        }
    }
}

void matDisplay::mouseReleaseEvent(QMouseEvent *mouse_event)
{
    if(mouse_event->button() == Qt::LeftButton)
    {
//        printf("LeftButton\n");
        QPoint mouse_pos = mouse_event->pos();

        if(mouse_pos.x() <= this->size().width() && mouse_pos.y() <= this->size().height())
        {
            if(mouse_pos.x() >= 0 && mouse_pos.x() >= 0)
            {
                this->P2 =mouse_pos;
                emit sendMouseReleasePosition(mouse_pos);
            }
        }
    }
}

/*void matDisplay::paintEvent(QPaintEvent *event)
{
        QRect rect = event->rect();
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setPen(Qt::black);
        painter.drawRect(rect);

}*/
