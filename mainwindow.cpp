#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include<iostream>
#include <Shlwapi.h>
#include<QDirIterator>
#include<QString>
#include<QTimer>
#include<QtXml>
#include<QTransform>
#include<QPixmap>
#include<math.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->initParams();
    this->fileDetails.fileName = "";
    this->fileDetails.imageFlag = 1;
    this->fileDetails.index = 0;
    this->fileDetails.numberofFiles = 0;
    this->setFixedSize(1400, 750);
    ui->setupUi(this);
    //QTimer::singleShot(1000, this, SLOT(showFullScreen()));
    this->initLayout();
    connect((ui->label_3),SIGNAL(sendMousePosition(QPoint&)),this,SLOT(showMousePosition(QPoint&)));
    connect((ui->label_3),SIGNAL(sendMouseReleasePosition(QPoint&)),this,SLOT(showMouseReleasePosition(QPoint&)));
    ui->textEdit_2->installEventFilter(this);
    this->saveflag =false;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString filter = this->getImageType() ;
    QStringList stringList= filter.split(",",QString::SkipEmptyParts);
    QString fileName;
    QString dir = QFileDialog::getExistingDirectory(this,"Open a Path",getenv("HOME"), QFileDialog::ShowDirsOnly);
    if ((dir.size() == 0) || (dir.isNull()==true))
       {
        QString msg ="Please select the image directory(.jpg,.bmp,.png)";
        QMessageBox::information(this,"VehNPD",msg);
        return ;
    }
    if ((dir.isEmpty() == false) || (dir.isNull()==false))
    {
        //QDirIterator iterator(dir, QStringList() << "*.jpg", QDir::Files, QDirIterator::Subdirectories);
        QDirIterator iterator(dir,stringList, QDir::Files, QDirIterator::Subdirectories);
        QString absoPath = iterator.path();
        this->currentImageDir = absoPath;
        QDir dirp(absoPath);
        dirp.setNameFilters(QStringList()<<"*.jpg");
        QStringList fileList = dirp.entryList();
        int count = 0;
        this->fileList = new QString [fileList.count()];
        while(iterator.hasNext()){
            QFile file(iterator.next());
            fileName =file.fileName();
            this->fileList[count]=fileName;
            count++;
        }

        if (count>0)
        {
            ui->textEdit_3->setText(QString::number(dirp.count()));
            ui->textEdit_3->setReadOnly(true);
            this->fileDetails.numberofFiles = fileList.count();
            this->fileDetails.index =0;
            this->fileIdx =0;
            this->fileDetails.fileName =this->fileList[0];

            ui->label_2->setText(absoPath);
            /* Create a new table for data stroage if not exists */
            QString fName = absoPath +"Label.sqlite";
            this->dbName = fName;
            this->createDB(absoPath);
            //this->loadDatainComboBox();
            ui->pushButton_5->setDisabled(true);
            /*Load First image or the latest image to label */
            int first = 1;
            int flag =this->createUniqueVehID(first);

            if (flag ==0)
            {
                QPixmap pix(this->fileList[0]);
                this->qPix =pix;
                int w = ui->label_3->width();
                int h =  ui->label_3->height();
                ui->label_3->setPixmap(pix.scaled(w,h,Qt:: IgnoreAspectRatio));
                this->vechID =0;
                this->fileDetails.index =0;
                this->fileIdx =0;
                this->fileDetails.fileName =this->fileList[0];
            }
            else
            {


                QPixmap pix(this->fileList[this->fileIdx]);
                this->qPix =pix;
                int w = ui->label_3->width();
                int h =  ui->label_3->height();
                ui->label_3->setPixmap(pix.scaled(w,h,Qt:: IgnoreAspectRatio));
                this->fileDetails.fileName =this->fileList[this->fileIdx];
            }
            ui->groupBox_3->show();
            ui->groupBox_4->show();
            ui->groupBox_2->show();
            ui->groupBox_5->show();
            ui->textEdit_2->setText(QString::number(this->fileIdx));
            ui->comboBox_10->addItem(QString::number(45));
            ui->comboBox_10->addItem(QString::number(90));
            ui->comboBox_10->addItem(QString::number(180));
            ui->comboBox_10->addItem(QString::number(270));
        }
        else
        {
            QString msg ="Files not found" +filter;
            QMessageBox::information(this,"VehNPD",msg);
        }
    }
    else
    {
        QString msg ="Please select the image directory(.jpg,.bmp,.png)";
        QMessageBox::information(this,"VehNPD",msg);
    }

}

void MainWindow::on_radioButton_5_toggled(bool checked)
{
    if (checked == true)
        this->fileDetails.imageFlag = 1;
}

void MainWindow::on_radioButton_6_toggled(bool checked)
{
    if (checked == true)
        this->fileDetails.imageFlag = 2;
}

void MainWindow::on_radioButton_7_toggled(bool checked)
{
    if (checked == true)
        this->fileDetails.imageFlag = 3;
}


void MainWindow::initParams()
{
    /*this->fileDetails.fileName = "";
    this->fileDetails.imageFlag = 1;
    this->fileDetails.index = 0;
    this->fileDetails.numberofFiles = 0 ;*/
    this->lFields.vehROIx         = 0;
    this->lFields.vehROIy         = 0;
    this->lFields.vehROIh         = 0;
    this->lFields.vehROIw         = 0;
    this->lFields.plateROIx       = 0;
    this->lFields.plateROIy       = 0;
    this->lFields.plateROIh       = 0;
    this->lFields.plateROIw       = 0;
    this->lFields.vehType         = "";
    this->lFields.vehView         = "";
    this->lFields.vehOcculusion   = 0;
    this->lFields.partiallyHidden = "";
    this->lFields.lightCondition  = "";
    this->lFields.numberPlateClr  = "";
    this->lFields.numberPlateView = "";
    this->lFields.vehNumber       = "";
    this->lFields.otherText       = "";
    this->lFields.plateOcculusion = 0;

}
void MainWindow::on_radioButton_8_toggled(bool checked)
{
    if (checked == true)
        this->fileDetails.imageFlag = 4;
}
QString MainWindow::getImageType()
{
    QString fileType;
    switch(this->fileDetails.imageFlag)
    {
    case 1:
        fileType = "*.jpg";
        break;
    case 2:
        fileType = "*.png";
        break;
    case 3:
        fileType = "*.bmp";
        break;
    case 4:
        fileType = "*.jpg,*.png,*.bmp";
        break;
    default:
        fileType = "*.jpg";

    }
    return fileType;

}



void MainWindow::on_pushButton_2_clicked()
{
     ui->comboBox_8->clear();
    if (this->saveflag == true)
    {
        QMessageBox::information(this,"VehNPD","Please click the save button ");
        return;
    }
    this->fileDetails.index = this->fileDetails.index - 1;
    this->fileIdx = this->fileIdx -1;


    if ((this->fileIdx  >=0) && (this->fileIdx <this->fileDetails.numberofFiles))
    {

        this->fileDetails.fileName =this->fileList[this->fileIdx ];
        QPixmap pix( this->fileList[this->fileIdx]);
        this->qPix = pix;
        int w = ui->label_3->width();
        int h =  ui->label_3->height();
        ui->label_3->setPixmap(pix.scaled(w,h,Qt:: IgnoreAspectRatio));
        ui->textEdit_2->setText(QString::number(this->fileIdx));
        int first = 0;
        int flag =this->createUniqueVehID(first);
        if (flag ==1)
        {
            this->m_draw = true;
            this->loadDatainComboBox();
            ui->pushButton_5->setDisabled(true);
        }
        else
        {
            this->m_draw = false;
            this->clearData();
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
     ui->comboBox_8->clear();
    if (this->saveflag == true)
    {
        QMessageBox::information(this,"VehNPD","Please click the save button ");
        return;
    }
    this->fileDetails.index =this->fileDetails.index + 1;
    this->fileIdx = this->fileIdx  +1;
    if ((this->fileIdx <this->fileDetails.numberofFiles) && (this->fileIdx >=0))   {

        this->fileDetails.fileName =this->fileList[this->fileIdx];
        //QMessageBox::information(this,"File Not Found",QString::number(this->fileIdx));
        QPixmap pix( this->fileDetails.fileName);
        this->qPix = pix;
        int w = ui->label_3->width();
        int h =  ui->label_3->height();
        ui->label_3->setPixmap(pix.scaled(w,h,Qt:: IgnoreAspectRatio));
        ui->textEdit_2->setText(QString::number(this->fileIdx));
        int first = 0;
        int flag =this->createUniqueVehID(first);
        if (flag ==1)
        {
            this->m_draw =true;
            this->loadDatainComboBox();
            ui->pushButton_5->setDisabled(true);
        }
        else
        {
            this->m_draw =false;
            this->clearData();
        }
    }
}

int MainWindow::createDB(QString path)
{
    int isExist = 0;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");//not dbConnection
    db.setDatabaseName(this->dbName);
    if (db.open())
    {
        QSqlQuery query;
        query.prepare("Create table if not exists L_vehicle "
                      "(imageName varchar(50), "
                      "vehicleID integer primary key, "
                      "vehROIx integer, "
                      "vehROIy integer, "
                      "vehROIh integer, "
                      "vehROIw integer, "
                      "plateROIx integer, "
                      "plateROIy integer, "
                      "plateROIh integer, "
                      "plateROIw integer, "
                      "vehType varchar(30), "
                      "vehView varchar(20), "
                      "vehOcclusion integer, "
                      "partiallyHidden varchar(30), "
                      "lightCondition varchar(20), "
                      "numberPlateClr varchar(20), "
                      "numberPlateView varchar(20), "
                      "vehNumber varchar(20), "
                      "plateOcclusion integer,"
                      "numberPlateOtherTxt varchar(20))");
        query.exec();
    }
    db.close();
    //this->db = db;
    return isExist;

}

void MainWindow::initLabelArrtibutes()
{
    this->vechID = this->vechID +1;
    ui->textEdit_5->setText(QString::number(this->vechID));
    ui->textEdit_5->setReadOnly(true);
    this->readConfigXml();
    /* ROI */
    ui->textEdit_25->setText("");
    ui->textEdit_26->setText("");
    ui->textEdit_27->setText("");
    ui->textEdit_28->setText("");
    ui->textEdit->setText("");
    ui->textEdit_6->setText("");
    ui->textEdit_7->setText("");
    ui->textEdit_8->setText("");
    this->vehROI.h = 0;
    this->vehROI.w = 0;
    this->vehROI.x = 0;
    this->vehROI.y = 0;
    this->plateROI.h = 0;
    this->plateROI.w = 0;
    this->plateROI.x = 0;
    this->plateROI.y = 0;

}

void MainWindow::showMousePosition(QPoint &pos)
{
    //ui->label_9->setText("x:"+ QString::number((pos.x()))+"y:"+ QString::number((pos.y())));
    this->P1 = pos;
}

void MainWindow::showMouseReleasePosition(QPoint &pos)
{
   if (this->m_draw==true)
   {
    //ui->label_10->setText("x:"+ QString::number((pos.x()))+"y:"+ QString::number((pos.y())));
    int bound =0;
    this->P2 = pos;
    int w,h,imageH,imageW;
    double ratioH,ratioW;
    int roiX,roiY,roiH,roiW;
    w = ui->label_3->width();
    h =  ui->label_3->height();
    QPixmap myPix(this->fileDetails.fileName);
    imageH = myPix.height();
    imageW = myPix.width();
    QPixmap myPix1=myPix.scaled(w,h,Qt::IgnoreAspectRatio);
    h=myPix1.size().height();
    w=myPix1.size().width();
    ratioH = imageH/(double)h;
    ratioW = imageW/(double)w;
    // if ((this->P1.x>=0)&& (this->P1.y>=0) && (this->P2.x>=0)&& (this->P2.y>=0))
    {
        roiH= min(imageH-1,(int) ceil((this->P2.y()-this->P1.y()) *ratioH));
        roiW = min(imageW-1,(int) ceil((this->P2.x()-this->P1.x())*ratioW));
        roiX = max(0,(int) ceil(this->P1.x() *ratioW));
        roiY = max(0,(int) ceil(this->P1.y()*ratioH));
    }

   // this->m_draw =true;
    if ((((roiY+roiH) <imageH) && ((roiW+roiX) <imageW))&&((roiH>0)&&(roiW>0)&&(roiX>=0)&&(roiY>=0)))
    {
        bound =1;
    }
    else
    {
        QMessageBox::information(this,"VehNPD","Selected ROI is out of bounds (ie ROI H or W is equal to zero),Dont do just a single click,Do a Mouse press at ROI Top left point and release it at bottom right corner,Please choose again ");
    }

    if ((m_draw) && (ui->radioButton->isChecked()==true))
    {
        if (bound)
        {
            this->vehROI.x = roiX;
            this->vehROI.y = roiY;
            this->vehROI.h = roiH;
            this->vehROI.w = roiW;
            ui->textEdit->setText(QString::number(this->vehROI.x));
            ui->textEdit_6->setText(QString::number(this->vehROI.y));
            ui->textEdit_7->setText(QString::number(this->vehROI.w));
            ui->textEdit_8->setText(QString::number(this->vehROI.h));

            this->drawRectangle(this->vehROI);
        }

    }
    else if ((m_draw) && (ui->radioButton_2->isChecked()==true) && bound)
    {
        this->plateROI.x = roiX;
        this->plateROI.y = roiY;
        this->plateROI.h = roiH;
        this->plateROI.w = roiW;
        ui->textEdit_25->setText(QString::number(this->plateROI.x));
        ui->textEdit_26->setText(QString::number(this->plateROI.y));
        ui->textEdit_27->setText(QString::number(this->plateROI.w));
        ui->textEdit_28->setText(QString::number(this->plateROI.h));

        this->drawRectangle(this->plateROI);

    }
    else
    {
        ui->textEdit_25->setText("");
        ui->textEdit_26->setText("");
        ui->textEdit_27->setText("");
        ui->textEdit_28->setText("");
        ui->textEdit->setText("");
        ui->textEdit_6->setText("");
        ui->textEdit_7->setText("");
        ui->textEdit_8->setText("");

    }

   }
   else
   {
       QMessageBox::information(this,"VehNPD","Please click the new button and choose the vehicle/Number plate ROI Radio button,Then draw the box");

   }
    //this->m_draw =false;
}

bool MainWindow::eventFilter(QObject *textEdit, QEvent *event)
{
    bool ok;

    if( textEdit == ui->textEdit_2)
    {

        if (event->type()==QEvent::KeyPress) {
            QKeyEvent* key = static_cast<QKeyEvent*>(event);
            if ( (key->key()==Qt::Key_Enter) || (key->key()==Qt::Key_Return) ) {
                QString value= ui->textEdit_2->toPlainText();
                qint64 fIdx = value.toInt(&ok,10);
                if ((fIdx>0) && (fIdx<this->fileDetails.numberofFiles))    {

                    this->fileIdx = fIdx;
                    this->fileDetails.index = fIdx;
                    this->fileDetails.fileName =this->fileList[this->fileDetails.index];
                    QPixmap pix( this->fileDetails.fileName);
                    this->qPix = pix;
                    int w = ui->label_3->width();
                    int h =  ui->label_3->height();
                    ui->label_3->setPixmap(pix.scaled(w,h,Qt:: IgnoreAspectRatio));
                }
            }
            else {
                return QObject::eventFilter(textEdit, event);
            }
            return true;
        }
        else {
            return QObject::eventFilter(textEdit, event);
        }
        return false;
    }
    else
    {
        return false;
    }


}


void MainWindow::on_pushButton_7_clicked()
{

    this->initLabelArrtibutes();
    ui->radioButton->setChecked(true);
    ui->pushButton_7->setDisabled(true);
    ui->pushButton_5->setEnabled(true);
    this->m_draw = true;
    this->saveflag = true;

}

void MainWindow::on_pushButton_5_clicked()
{
    QString queryString;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");//not dbConnection
    db.setDatabaseName(this->dbName);
    this->saveflag = false;
    if (db.open())
    {
        queryString = this->insertQuery();
        QSqlQuery query;

        // query.prepare(queryString);
        query.exec(queryString);
    }
    db.close();
    ui->pushButton_5->setDisabled(true);
    ui->pushButton_7->setEnabled(true);
    this->m_draw =false;
    //this->initLabelArrtibutes();
    this->clearData();
    this->loadDatainComboBox();
}

QString MainWindow::insertQuery()
{
    QString queryString;
    this->setLabelAttributes();
    queryString = "INSERT INTO L_vehicle VALUES('" +
            this->lFields.imageName +"',"+QString::number(this->lFields.vehicleID)+","+
            QString::number(this->lFields.vehROIx)+","+QString::number(this->lFields.vehROIy)+","+
            QString::number(this->lFields.vehROIh)+","+QString::number(this->lFields.vehROIw)+","+
            QString::number(this->lFields.plateROIx)+","+QString::number(this->lFields.plateROIy)+","+
            QString::number(this->lFields.plateROIh)+","+QString::number(this->lFields.plateROIw)+",'"+
            this->lFields.vehType +"','"+this->lFields.vehView+"',"+QString::number(this->lFields.vehOcculusion)+",'"+
            this->lFields.partiallyHidden+"','"+this->lFields.lightCondition+"','"+
            this->lFields.numberPlateClr+"','"+this->lFields.numberPlateView+"','"+this->lFields.vehNumber+"',"+
            QString::number(this->lFields.plateOcculusion)+",'"+this->lFields.otherText+"')";
    std::cout << queryString.toUtf8().constData() << std::endl;
    return queryString;
}

QString MainWindow::updateQuery()
{
    QString queryString;
    this->setLabelAttributes();
    queryString = "Update L_vehicle SET vehROIx =" + QString::number(this->lFields.vehROIx) +
            ", vehROIy ="+ QString::number(this->lFields.vehROIy) +
            ", vehROIw ="+ QString::number(this->lFields.vehROIw) +
            ", vehROIh="+ QString::number(this->lFields.vehROIh) +
            ", plateROIx="+ QString::number(this->lFields.plateROIx) +
            ", plateROIy="+ QString::number(this->lFields.plateROIx) +
            ", plateROIh="+ QString::number(this->lFields.plateROIh) +
            ", plateROIw="+ QString::number(this->lFields.plateROIw) +
            ", vehType ='"+ this->lFields.vehType +"'"+
            ", vehView ='"+ this->lFields.vehView +"'"+
            ", vehOcclusion="+ QString::number(this->lFields.vehOcculusion) +
            ", partiallyHidden='"+ this->lFields.partiallyHidden +"'"+
            ", lightCondition='"+ this->lFields.lightCondition +"'"+
            ", numberPlateClr='"+ this->lFields.numberPlateClr +"'"+
            ", numberPlateView='"+ this->lFields.numberPlateView +"'"+
            ", vehNumber='"+ this->lFields.vehNumber +"'"+
            ", numberPlateOtherTxt ='"+ this->lFields.otherText +"'"+
            ", plateOcclusion ="+ QString::number(this->lFields.plateOcculusion) + " Where "+
            "vehicleID ="+ QString::number(this->lFields.vehicleID) +" and imageName ='" +this->fileDetails.fileName+"'";
    //std::cout << queryString.toUtf8().constData() << std::endl;
    return queryString;
}
QString MainWindow::deleteQuery()
{
    QString queryString;

    queryString = "Delete from L_vehicle where vehicleID ='" + ui->textEdit_5->toPlainText()+"' and imageName='"+this->fileDetails.fileName+"'";
    return queryString;
}

QString MainWindow::selectQuery()
{
    QString queryString;
    queryString = "Select vehicleID from L_vehicle where imageName ='" +this->fileDetails.fileName+"'";
    return queryString;
}

void MainWindow::setLabelAttributes()
{
    QVariant plateOcc = ui->comboBox_6->itemData(ui->comboBox_6->currentIndex());
    QVariant vehID    =   ui->textEdit_5->toPlainText();
    QVariant vehOcc    =  ui->comboBox_3->itemData(ui->comboBox_3->currentIndex());
    QVariant data;
    bool ok;
    data = ui->comboBox_9->itemData(ui->comboBox_9->currentIndex());
    this->lFields.lightCondition  = ui->comboBox_9->currentText();
    data = ui->comboBox_5->itemData(ui->comboBox_5->currentIndex());
    this->lFields.numberPlateClr  =  ui->comboBox_5->currentText();
    data = ui->comboBox_7->itemData(ui->comboBox_7->currentIndex());
    this->lFields.numberPlateView =  ui->comboBox_7->currentText();
    data = ui->comboBox_4->itemData(ui->comboBox_4->currentIndex());
    this->lFields.imageName =this->fileDetails.fileName;
    this->lFields.partiallyHidden =  ui->comboBox_4->currentText();
    this->lFields.plateOcculusion =  (int)plateOcc.toInt(&ok);
    this->lFields.plateROIh       =  this->plateROI.h;
    this->lFields.plateROIw       =  this->plateROI.w;
    this->lFields.plateROIx       =  this->plateROI.x;
    this->lFields.plateROIy       =  this->plateROI.y;
    this->lFields.vehicleID       =  (int)vehID.toInt(&ok);
    this->lFields.vehNumber       =  ui->textEdit_4->toPlainText();
    this->lFields.otherText       =  ui->textEdit_9->toPlainText();
    this->lFields.vehOcculusion   =  (int)vehOcc.toInt(&ok);
    this->lFields.vehROIh         =  this->vehROI.h;
    this->lFields.vehROIw         =  this->vehROI.w;
    this->lFields.vehROIx         =  this->vehROI.x;
    this->lFields.vehROIy         =  this->vehROI.y;
    data = ui->comboBox->itemData(ui->comboBox->currentIndex());
    this->lFields.vehType         =  ui->comboBox->currentText();
    data = ui->comboBox_2->itemData(ui->comboBox_2->currentIndex());
    this->lFields.vehView         =  ui->comboBox_2->currentText();

}

void MainWindow::getLabelAttributes()
{
    int index;
    this->readConfigXml();
    index= ui->comboBox_9->findData(this->lFields.lightCondition);
    if (index != -1)
        ui->comboBox_9->setCurrentIndex(index);
    index= ui->comboBox_5->findData(this->lFields.numberPlateClr);
    if (index != -1)
        ui->comboBox_5->setCurrentIndex(index);
    index= ui->comboBox_7->findData(this->lFields.numberPlateView);
    if (index != -1)
        ui->comboBox_7->setCurrentIndex(index);
    index= ui->comboBox_4->findData(this->lFields.partiallyHidden);
    if (index != -1)
        ui->comboBox_4->setCurrentIndex(index);
    ui->textEdit_4->setText(this->lFields.vehNumber);
    ui->textEdit_9->setText(this->lFields.otherText);
    ui->textEdit_5->setText(QString::number(this->lFields.vehicleID));
    index= ui->comboBox->findText(this->lFields.vehType);
    if (index != -1)
        ui->comboBox->setCurrentIndex(index);
    index= ui->comboBox_2->findData(this->lFields.vehView);
    if (index != -1)
        ui->comboBox_2->setCurrentIndex(index);
    index= ui->comboBox_6->findData(this->lFields.plateOcculusion,Qt::DisplayRole);
    if (index != -1)
        ui->comboBox_6->setCurrentIndex(index);
    index= ui->comboBox_3->findData(this->lFields.vehOcculusion,Qt::DisplayRole);
    if (index != -1)
        ui->comboBox_3->setCurrentIndex(index);

    ui->textEdit_25->setText(QString::number(this->lFields.plateROIx));
    ui->textEdit_26->setText(QString::number(this->lFields.plateROIy));
    ui->textEdit_27->setText(QString::number(this->lFields.plateROIw));
    ui->textEdit_28->setText(QString::number(this->lFields.plateROIh));
    ui->textEdit->setText(QString::number(this->lFields.vehROIx));
    ui->textEdit_6->setText(QString::number(this->lFields.vehROIy));
    ui->textEdit_7->setText(QString::number(this->lFields.vehROIw));
    ui->textEdit_8->setText(QString::number(this->lFields.vehROIh));
    ui->pushButton_5->setDisabled(true);

}

void MainWindow::drawRectangle(struct objectROI R)
{
    if(this->m_draw)
    {
        int w,h,imageH,imageW;

        w = ui->label_3->width();
        h =  ui->label_3->height();
        QPixmap myPix(this->fileDetails.fileName);
        imageH = myPix.height();
        imageW = myPix.width();

        if (((R.x+R.w) <= imageW) && ((R.y+R.h) <= imageH))
        {

            QPainter painter(&myPix);
            QPen paintpen(Qt::red);
            paintpen.setWidth(10);
            painter.setPen(paintpen);
            painter.drawRect(R.x,R.y,R.w,R.h);
            ui->label_3->setPixmap(myPix.scaled(w,h,Qt::IgnoreAspectRatio));
        }
    }

}

void MainWindow::on_pushButton_8_clicked()
{
    QString queryString;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");//not dbConnection
    db.setDatabaseName(this->dbName);
    this->m_draw =false;
    if (db.open())
    {
        queryString = this->updateQuery();
        QSqlQuery query;
        query.exec(queryString);
    }
    db.close();
    ui->pushButton_7->setEnabled(true);
    this->clearData();
}

void MainWindow::on_pushButton_6_clicked()
{
    QString queryString;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");//not dbConnection
    db.setDatabaseName(this->dbName);
    if (db.open())
    {
        queryString = this->deleteQuery();
        QSqlQuery query;
        query.exec(queryString);
        QMessageBox::information(this,"vehNPD","Record is Deleted");
        this->loadDatainComboBox();
        this->clearData();
        int first =0;
        int flag =this->createUniqueVehID(first);
        if (flag ==0)
            this->vechID =0;
        this->initParams();

    }
    db.close();
    QPixmap pix(this->fileList[this->fileIdx]);
    this->fileDetails.index = this->fileIdx;
    this->fileDetails.fileName =this->fileList[this->fileIdx ];
    this->qPix =pix;
    int w = ui->label_3->width();
    int h =  ui->label_3->height();
    ui->label_3->setPixmap(pix.scaled(w,h,Qt:: IgnoreAspectRatio));

}
void MainWindow::initLayout()
{
    this->vechID = 0;
    this->fileIdx =0;
    ui->groupBox_2->hide();
    ui->groupBox_3->hide();
    ui->groupBox_4->hide();
    ui->groupBox_5->hide();
    ui->radioButton_5->setChecked(true);
    ui->textEdit->setReadOnly(true);
    ui->textEdit_7->setReadOnly(true);
    ui->textEdit_6->setReadOnly(true);
    ui->textEdit_8->setReadOnly(true);
    ui->textEdit_25->setReadOnly(true);
    ui->textEdit_26->setReadOnly(true);
    ui->textEdit_27->setReadOnly(true);
    ui->textEdit_28->setReadOnly(true);
    this->m_draw =false;

}

/*void MainWindow::paintEvent(QPaintEvent *event)
{
    if(this->m_draw)
    {
        int w,h,imageH,imageW,ratioH,ratioW;
        int roiX,roiY,roiH,roiW;
        QRect R;
        w = ui->label_3->width();
        h =  ui->label_3->height();
        QPixmap myPix("D:\\VehImages\\TEST\\[000117].jpg");
        QPixmap TempImg = myPix.scaled(w,h,Qt:: IgnoreAspectRatio);
        imageH = myPix.height();
        imageW = myPix.width();
        ratioH = (int)ceil(imageH/(double)w);
        ratioW = (int)ceil(imageW/(double)h);
        R =event->rect();
        roiH=(this->P2.y()-this->P1.y()) *ratioH;
        roiW =(this->P2.x()-this->P1.x())*ratioW;
        roiX =this->P1.x() *ratioW;
        roiY =this->P1.y()*ratioH;
        QPainter painter(&myPix);
        QPen paintpen(Qt::red);
        paintpen.setWidth(10);
        painter.setPen(paintpen);
        painter.drawRect(roiX,roiY,roiW,roiH);
        ui->label_3->setPixmap(myPix.scaled(w,h,Qt:: IgnoreAspectRatio));
    }
}*/


void MainWindow::on_comboBox_8_activated(int index)
{
    QSqlQueryModel *model = new  QSqlQueryModel();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");//not dbConnection
    db.setDatabaseName(this->dbName);
    if (db.open())
    {
        QString vehLIdui = ui->comboBox_8->currentText();
        QSqlQuery * qry =new QSqlQuery(db);
        QString queryString;
        queryString = "Select * from L_vehicle where vehicleID ='" +vehLIdui+"' and imageName='"+this->fileDetails.fileName+"'";
        //qry->prepare();
        qry->exec(queryString);
        model->setQuery(*qry);
        bool ok;
        delete qry;
        if (model->rowCount()>0)
        {
            QSqlRecord rec = model->record(0);
            this->lFields.imageName = rec.value(0).toString();
            this->lFields.vehicleID = rec.value(1).toInt(&ok);
            this->lFields.vehROIx         = rec.value(2).toInt(&ok);
            this->lFields.vehROIy         = rec.value(3).toInt(&ok);
            this->lFields.vehROIh         = rec.value(4).toInt(&ok);
            this->lFields.vehROIw         = rec.value(5).toInt(&ok);
            this->lFields.plateROIx       = rec.value(6).toInt(&ok);
            this->lFields.plateROIy       = rec.value(7).toInt(&ok);
            this->lFields.plateROIh       = rec.value(8).toInt(&ok);
            this->lFields.plateROIw       = rec.value(9).toInt(&ok);
            this->lFields.vehType         = rec.value(10).toString();
            this->lFields.vehView         = rec.value(11).toString();
            this->lFields.vehOcculusion   = rec.value(12).toInt(&ok);
            this->lFields.partiallyHidden = rec.value(13).toString();
            this->lFields.lightCondition  = rec.value(14).toString();
            this->lFields.numberPlateClr  = rec.value(15).toString();
            this->lFields.numberPlateView = rec.value(16).toString();
            this->lFields.vehNumber       = rec.value(17).toString();
            this->lFields.plateOcculusion = rec.value(18).toInt(&ok);
            this->lFields.otherText       = rec.value(19).toString();
            this->getLabelAttributes();
            this->m_draw =true;
            struct objectROI TempRoi,TempRoi1 ;
            TempRoi.x = this->lFields.vehROIx;
            TempRoi.y = this->lFields.vehROIy;
            TempRoi.h = this->lFields.vehROIh;
            TempRoi.w = this->lFields.vehROIw;
            this->vehROI =TempRoi;

            TempRoi1.x = this->lFields.plateROIx;
            TempRoi1.y = this->lFields.plateROIy;
            TempRoi1.h = this->lFields.plateROIh;
            TempRoi1.w = this->lFields.plateROIw;
            this->plateROI =TempRoi1;
            this->drawROIs(TempRoi,TempRoi1);
        }
        else
        {
            this->initParams();
            // ui->comboBox_8->clear();
        }
    }
    db.close();
    delete model;
}
void MainWindow::loadDatainComboBox()
{
    /* Data base loadd */
    QSqlQueryModel *model = new  QSqlQueryModel();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");//not dbConnection
    db.setDatabaseName(this->dbName);
    if (db.open())
    {
        QSqlQuery * qry =new QSqlQuery(db);
        //qry->prepare();
        qry->exec(this->selectQuery());
        model->setQuery(*qry);

        if (model->rowCount()>0)
        {

            ui->comboBox_8->clear();
            for (int ix =0 ;ix<model->rowCount();ix++)
            {
                QSqlRecord rec = model->record(ix);
                ui->comboBox_8->addItem(rec.value(0).toString());
            }
            // ui->comboBox_8->setModel(model);
            ui->pushButton_6->setEnabled(true);
            ui->pushButton_8->setEnabled(true);
        }
        else
        {
            ui->comboBox_8->clear();
            ui->pushButton_6->setEnabled(false);
            ui->pushButton_8->setEnabled(false);

        }
    }
    db.close();
    delete model;
}
void MainWindow::clearData()
{

    {

        ui->textEdit_5->setText("");
        ui->textEdit_5->setReadOnly(true);
        /* Veh Type */
        ui->comboBox->clear();
        ui->comboBox_2->clear();
        ui->comboBox_3->clear();
        ui->comboBox_4->clear();
        ui->comboBox_5->clear();
        ui->comboBox_6->clear();
        ui->comboBox_7->clear();
        ui->comboBox_9->clear();
        //ui->comboBox_8->clear();
        /* License plate number */
        ui->textEdit_4->setText("");
        ui->textEdit_9->setText("");

        /* ROI */
        ui->textEdit_25->setText("");
        ui->textEdit_26->setText("");
        ui->textEdit_27->setText("");
        ui->textEdit_28->setText("");
        ui->textEdit->setText("");
        ui->textEdit_6->setText("");
        ui->textEdit_7->setText("");
        ui->textEdit_8->setText("");


    }

}
int MainWindow::createUniqueVehID(int box)
{
    int flag =0;
    QSqlQueryModel *model = new  QSqlQueryModel();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");//not dbConnection
    db.setDatabaseName(this->dbName);
    if (db.open())
    {
        QSqlQuery * qry =new QSqlQuery(db);
        QString queryString;
        if (box)
        {
            queryString = "Select * from L_vehicle where  imageName LIKE'"+this->currentImageDir+"%' ORDER By vehicleID";
        }
        else
        {
            queryString = "Select * from L_vehicle where  imageName='"+this->fileDetails.fileName+"' ORDER By vehicleID";
        }
        //std::cout << queryString.toUtf8().constData() << std::endl;
        //qry->prepare();
        qry->exec(queryString);
        model->setQuery(*qry);
        bool ok;


        if (model->rowCount()>0)
        {
            if (box)
            {
                QSqlRecord rec = model->record(model->rowCount()-1);
                QString imageName = rec.value(0).toString();
                this->vechID = rec.value(1).toInt(&ok);
                this->fileDetails.index = 0;
                this->fileIdx =0;
                this->fileDetails.fileName = this->fileList[0];
                if (1)
                {
                    for (int ix =0 ;ix <this->fileDetails.numberofFiles;ix++)
                    {
                        if (imageName.compare(this->fileList[ix])==0)
                        {
                            this->fileDetails.index = ix+1;
                            this->fileIdx =ix+1;
                            this->fileDetails.fileName = this->fileList[this->fileIdx];
                            break;
                        }
                    }

                }
                else
                {
                    for (int ix =0 ;ix <this->fileDetails.numberofFiles;ix++)
                    {
                        if (imageName.compare(this->fileList[ix])==0)
                        {
                            this->fileDetails.index = ix;
                            this->fileIdx =ix;
                            this->fileDetails.fileName = this->fileList[this->fileIdx];
                            break;
                        }
                    }

                }
            }
            flag =1;
        }
        else
        {
            flag =0;
        }
    }
    db.close();
    delete model;

    return flag;
}

/*void MainWindow::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Return)
    {
        //LoadcurrentImage();
    }
    else
    {
       // QTextEdit::keyPressEvent(event);
    }
}*/

int MainWindow::readConfigXml()
{
    int fileFlag =1;
    /*QString filePath = QApplication::applicationDirPath();
    QDir d = QFileInfo(filePath).absoluteDir();
    QString fileName = d.absolutePath() +"/NPD_Config.xml" ;*/
    QString filepath = QDir::currentPath();
    QString fileName = filepath +"/NPD_Config.xml" ;
    //std::cout << fileName.toUtf8().data()<< std::endl;
    /*QString fileName ="D:\\VehImages\\NPD_Config.xml";*/
    QDomDocument doc(fileName);
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
        fileFlag = 0;
    if (!doc.setContent(&file)) {
        file.close();
        fileFlag =  0;
    }
    file.close();

    if (fileFlag == 1)
    {
        QDomElement docElem = doc.documentElement();
        for(QDomNode n1 = docElem.firstChild(); !n1.isNull(); n1 = n1.nextSibling())
        {
            if( !n1.isNull() ) {

                if ( n1.isElement() && n1.nodeName() == "VehicleType" )
                {
                    QDomElement Label = n1.toElement();
                    QStringList pieces = Label.text().split( "," );


                    for(int j=0;j<pieces.count();j++)
                    {
                        ui->comboBox->addItem(pieces.at(j));

                    }


                }
                else if ( n1.isElement() && n1.nodeName() == "VehicleView" )
                {
                    QDomElement Label = n1.toElement();
                    QStringList pieces = Label.text().split( "," );


                    for(int j=0;j<pieces.count();j++)
                    {
                        ui->comboBox_2->addItem(pieces.at(j));

                    }


                }
                else if ( n1.isElement() && n1.nodeName() == "VehicleOcclusion" )
                {
                    QDomElement Label = n1.toElement();
                    QStringList pieces = Label.text().split( "," );


                    for(int j=0;j<pieces.count();j++)
                    {
                        ui->comboBox_3->addItem(pieces.at(j));

                    }


                }
                else if ( n1.isElement() && n1.nodeName() == "PartiallyHiddenFrom" )
                {
                    QDomElement Label = n1.toElement();
                    QStringList pieces = Label.text().split( "," );


                    for(int j=0;j<pieces.count();j++)
                    {
                        ui->comboBox_4->addItem(pieces.at(j));

                    }


                }
                else if ( n1.isElement() && n1.nodeName() == "LightCondition" )
                {
                    QDomElement Label = n1.toElement();
                    QStringList pieces = Label.text().split( "," );


                    for(int j=0;j<pieces.count();j++)
                    {
                        ui->comboBox_9->addItem(pieces.at(j));

                    }


                }
                else if ( n1.isElement() && n1.nodeName() == "NumberPlateColor" )
                {
                    QDomElement Label = n1.toElement();
                    QStringList pieces = Label.text().split( "," );


                    for(int j=0;j<pieces.count();j++)
                    {
                        ui->comboBox_5->addItem(pieces.at(j));

                    }


                }
                else if ( n1.isElement() && n1.nodeName() == "NumberPlateView" )
                {
                    QDomElement Label = n1.toElement();
                    QStringList pieces = Label.text().split( "," );


                    for(int j=0;j<pieces.count();j++)
                    {
                        ui->comboBox_7->addItem(pieces.at(j));

                    }



                }
                else if ( n1.isElement() && n1.nodeName() == "NumberPlateOcclusion" )
                {
                    QDomElement Label = n1.toElement();
                    QStringList pieces = Label.text().split( "," );


                    for(int j=0;j<pieces.count();j++)
                    {
                        ui->comboBox_6->addItem(pieces.at(j));

                    }


                }
                else
                {
                }
            }
        }


    }
    else
    {
        /* Veh Type */
        ui->comboBox->addItem("Car_Sedan");
        ui->comboBox->addItem("Car_Hatchback");
        ui->comboBox->addItem("Motorcycle");
        ui->comboBox->addItem("Auto");
        ui->comboBox->addItem("LoadAuto");
        ui->comboBox->addItem("Tempotraveller");
        ui->comboBox->addItem("Bus");
        ui->comboBox->addItem("Smalltruck");
        ui->comboBox->addItem("Heavytruck");
        ui->comboBox->addItem("Othervechicles");
        ui->comboBox->addItem("Ignore"); /* Multiple vehicles */
        /* Veh view */
        ui->comboBox_2->addItem("Rear");
        ui->comboBox_2->addItem("Front");
        ui->comboBox_2->addItem("Left");
        ui->comboBox_2->addItem("Right");
        ui->comboBox_2->addItem("RearLeft");
        ui->comboBox_2->addItem("RearRight");
        ui->comboBox_2->addItem("FrontLeft");
        ui->comboBox_2->addItem("FrontRight");
        /* Covered Object , How much % is convered in ROI , check only front and rear */
        for (int step =0;step <=100;step =step +20)
        {
            ui->comboBox_3->addItem(QString::number(step));
        }
        /*Partially hidden from */
        ui->comboBox_4->addItem("None");
        ui->comboBox_4->addItem("Top");
        ui->comboBox_4->addItem("Bottom");
        ui->comboBox_4->addItem("Left");
        ui->comboBox_4->addItem("Right");
        /* Number plate color */
        ui->comboBox_5->addItem("Yellow");
        ui->comboBox_5->addItem("White");
        ui->comboBox_5->addItem("Black");
        /* Number plate Occlusion */
        for (int step =0;step <=100;step =step +25)
        {
            ui->comboBox_6->addItem(QString::number(step));
        }
        /* License plate number */
        ui->textEdit_4->setText("");
        ui->textEdit_9->setText("");
        /* NumberPlate view */
        ui->comboBox_7->addItem("Rear");
        ui->comboBox_7->addItem("Front");
        ui->comboBox_7->addItem("Left");
        ui->comboBox_7->addItem("Right");
        ui->comboBox_7->addItem("RearLeft");
        ui->comboBox_7->addItem("RearRight");
        ui->comboBox_7->addItem("FrontLeft");
        ui->comboBox_7->addItem("FrontRight");
        /* Light Conditions */
        ui->comboBox_9->addItem("Day");
        ui->comboBox_9->addItem("Night");
        ui->comboBox_9->addItem("Dusk");
        ui->comboBox_9->addItem("Dawn");

    }
    return fileFlag;

}


void MainWindow::on_pushButton_11_clicked()
{
    bool ok;
    QPixmap pixmap(this->fileDetails.fileName);
    QString vehOcc    =  ui->comboBox_10->currentText();
    //std::cout << vehOcc.toUtf8().data()<< std::endl;
    double degree = vehOcc.toDouble(&ok);
    QPixmap rotatedPixmap(pixmap.size());
    rotatedPixmap.fill(QColor::fromRgb(0, 0, 0, 0)); //the new pixmap must be transparent.
    QPainter* p = new QPainter(&rotatedPixmap);
    QSize size = pixmap.size();
    p->translate(size.height()/2,size.height()/2);
    p->rotate(degree);
    p->translate(-size.height()/2,-size.height()/2);
    p->drawPixmap(0, 0, pixmap);
    p->end();
    delete p;
    int w = ui->label_3->width();
    int h =  ui->label_3->height();
    ui->label_3->setPixmap(rotatedPixmap.scaled(w,h,Qt:: IgnoreAspectRatio));
    QFile file(this->fileDetails.fileName);
    QString extension = this->fileDetails.fileName;
    QStringList pieces = extension.split(".");
    file.open(QIODevice::WriteOnly);
    QString temp = pieces.at(1);
    temp =temp.toUpper();

    const char * ext ;

    if (temp.compare("JPG")==0)
    {
        ext = "JPG";
    }
    else if (temp.compare("BMP")==0)
    {
        ext = "BMP";
    }
    else if (temp.compare("PNG")==0)
    {
        ext = "PNG";
    }
    else
    {
        ext = "";
    }

    rotatedPixmap.save(&file,ext);
}

void MainWindow::drawROIs(struct objectROI R,struct objectROI R1)
{
    if(this->m_draw)
    {
        int w,h,imageH,imageW;

        w = ui->label_3->width();
        h =  ui->label_3->height();
        QPixmap myPix(this->fileDetails.fileName);
        imageH = myPix.height();
        imageW = myPix.width();

        if ((((R.x+R.w) <= imageW) && ((R.y+R.h) <= imageH)) && (((R1.x+R1.w) <= imageW) && ((R1.y+R1.h) <= imageH)))
        {

            QPainter painter(&myPix);
            QPen paintpen(Qt::red);
            paintpen.setWidth(10);
            painter.setPen(paintpen);
            painter.drawRect(R.x,R.y,R.w,R.h);
            painter.drawRect(R1.x,R1.y,R1.w,R1.h);
            ui->label_3->setPixmap(myPix.scaled(w,h,Qt:: IgnoreAspectRatio));
        }
    }

}

void MainWindow::on_pushButton_9_clicked()
{
    zoomDialog zg(this->fileDetails.fileName);
    zg.setModal(true);

    zg.exec();
}
