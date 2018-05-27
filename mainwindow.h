#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFileDialog>
#include<QMessageBox>
#include<QDir>
#include "QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include"QtSql/QSqlQueryModel"
#include<QtSql/QSqlRecord>
#include<QSql>
#include<QtMath>
#include<zoomdialog.h>
namespace Ui {
class MainWindow;
}
struct fileInfo
{
    int numberofFiles;
    QString fileName;
    int index;
    int imageFlag;    

};
struct objectROI
{
    int x;
    int y;
    int h;
    int w;


};


struct labelFields
{
    QString imageName;
    unsigned long int  vehicleID;
    int vehROIx;
    int vehROIy;
    int vehROIh;
    int vehROIw;
    int plateROIx;
    int plateROIy;
    int plateROIh;
    int plateROIw;
    QString vehType;
    QString vehView;
    int vehOcculusion;
    QString partiallyHidden;
    QString lightCondition;
    QString numberPlateClr;
    QString numberPlateView;
    QString vehNumber;
    QString otherText;
    int plateOcculusion;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     struct fileInfo  fileDetails;

    struct objectROI vehROI;
    struct objectROI plateROI;
    void initParams();
    QString getImageType();


private slots:
    void on_pushButton_clicked();

    void on_radioButton_5_toggled(bool checked);

    void on_radioButton_6_toggled(bool checked);

    void on_radioButton_7_toggled(bool checked);

    void on_radioButton_8_toggled(bool checked);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    int createDB(QString path);


    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();    

    void on_comboBox_8_activated(int index);

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

public slots:
    void showMousePosition(QPoint& pos);
    void showMouseReleasePosition(QPoint& pos);
protected:
     /*void paintEvent(QPaintEvent *);*/
      bool  eventFilter(QObject *, QEvent *);


private:
    Ui::MainWindow *ui;
    unsigned long int vechID;
    QString dbName;
    bool saveflag;
    QString currentImageDir;
    QSqlDatabase db;
    QPixmap qPix;
    QPoint P1,P2;
    void initLabelArrtibutes();
    QString insertQuery();
    QString updateQuery();
    QString deleteQuery();
    QString selectQuery();
    struct labelFields lFields;
    void setLabelAttributes();
    void getLabelAttributes();
    QString *fileList;
    int fileIdx;
    bool m_draw;
    void drawRectangle(struct objectROI p);
    void initLayout();
    void loadDatainComboBox();
    int createUniqueVehID(int box);
    void clearData();
    int readConfigXml();
    void drawROIs(struct objectROI R,struct objectROI R1);

};

#endif // MAINWINDOW_H
