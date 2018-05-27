#ifndef MATDISPLAY_H
#define MATDISPLAY_H


#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QPainter>
class matDisplay : public QLabel
{
    Q_OBJECT
public:
    matDisplay(QWidget *parent = 0);
    ~matDisplay();
    QPoint P1,P2;

protected:

    void mousePressEvent(QMouseEvent *mouse_event);
    void mouseReleaseEvent(QMouseEvent *mouse_event);
   // void paintEvent(QPaintEvent *);

signals:
    void sendMousePosition(QPoint& );
    void sendMouseReleasePosition(QPoint& );



};
#endif // MATDISPLAY_H
