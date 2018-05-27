#ifndef ZOOMDIALOG_H
#define ZOOMDIALOG_H

#include <QDialog>
#include <QGraphicsScene>
#include <QRubberBand>

namespace Ui {
class zoomDialog;
}

class zoomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit zoomDialog(const QString &path,QWidget *parent = 0);
    ~zoomDialog();
    QString filename;
    void setPath(const QString &path);
private slots:
    void on_actionOpen_triggered();

    void on_cropButton_clicked();

    void on_rotateButton_clicked();

    void on_reset_clicked();

    void on_zoomIn_clicked();

    void on_zoomOut_clicked();

    void on_undo_clicked();

    void on_redo_clicked();

    void on_actionSave_triggered();

    void on_horizontalSlider_sliderMoved(int position);

    void on_spinBox_valueChanged(int arg1);

    void on_actionExit_triggered();

    void on_rotateButton_3_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_spinBox_4_editingFinished();

    void on_spinBox_3_editingFinished();

    void on_spinBox_4_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

public slots:
      void setEnable();
      void enableRotateSlot();

private:
    Ui::zoomDialog *ui;
    QString m_path;
};

#endif // ZOOMDIALOG_H
