#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qvector.h"

#include <QImage>
#include <QDebug>

using namespace std;
QVector<QString> train;
QVector<QString> test;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    FSupdateButtonState();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDatabaseInfo()
{
    ui->FScomboBox->clear();
    for(unsigned int i=1; i<=database.getNoFeatures(); ++i)
        ui->FScomboBox->addItem(QString::number(i));

    ui->FStextBrowserDatabaseInfo->setText("noClass: " +  QString::number(database.getNoClass()));
    ui->FStextBrowserDatabaseInfo->append("noObjects: "  +  QString::number(database.getNoObjects()));
    ui->FStextBrowserDatabaseInfo->append("noFeatures: "  +  QString::number(database.getNoFeatures()));

}

void MainWindow::FSupdateButtonState(void)
{
    if(database.getNoObjects()==0)
    {
        FSsetButtonState(false);
    }
    else
        FSsetButtonState(true);

}


void MainWindow::FSsetButtonState(bool state)
{
   ui->FScomboBox->setEnabled(state);
   ui->FSpushButtonCompute->setEnabled(state);
   ui->FSpushButtonSaveFile->setEnabled(state);
   ui->FSradioButtonFisher->setEnabled(state);
   ui->FSradioButtonSFS->setEnabled(state);
}

void MainWindow::on_FSpushButtonOpenFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open TextFile"), "", tr("Texts Files (*.txt)"));

    if ( !database.load(fileName.toStdString()) )
        QMessageBox::warning(this, "Warning", "File corrupted !!!");
    else
        QMessageBox::information(this, fileName, "File loaded !!!");

    FSupdateButtonState();
    updateDatabaseInfo();
}

void MainWindow::on_FSpushButtonCompute_clicked()
{
    int dimension = ui->FScomboBox->currentText().toInt();


    if( ui->FSradioButtonFisher ->isChecked())
    {
    if (dimension == 1 && database.getNoClass() == 2)
        {
            float FLD = 0, tmp;
            int max_ind = -1;

            //std::map<std::string, int> classNames = database.getClassNames();
            for (uint i = 0; i < database.getNoFeatures(); ++i)
            {
                std::map<std::string, float> classAverages;
                std::map<std::string, float> classStds;

                for (auto const &ob : database.getObjects())
                {
                    classAverages[ob.getClassName()] += ob.getFeatures()[i];
                    classStds[ob.getClassName()] += ob.getFeatures()[i] * ob.getFeatures()[i];
                }

                std::for_each(database.getClassCounters().begin(), database.getClassCounters().end(), [&](const std::pair<std::string, int> &it)
                {
                    classAverages[it.first] /= it.second;
                    classStds[it.first] = std::sqrt(classStds[it.first] / it.second - classAverages[it.first] * classAverages[it.first]);
                }
                );

                tmp = std::abs(classAverages[ database.getClassNames()[0] ] - classAverages[database.getClassNames()[1]]) / (classStds[database.getClassNames()[0]] + classStds[database.getClassNames()[1]]);

                if (tmp > FLD)
                {
                    FLD = tmp;
                    max_ind = i;
                }

              }

            ui->FStextBrowserDatabaseInfo->append("max_ind: "  +  QString::number(max_ind) + " " + QString::number(FLD));
          }
     }
}



void MainWindow::on_FSpushButtonSaveFile_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
    tr("Open TextFile"), "D:\\Users\\Krzysiu\\Documents\\Visual Studio 2015\\Projects\\SMPD\\SMPD\\Debug\\", tr("Texts Files (*.txt)"));

        QMessageBox::information(this, "My File", fileName);
        database.save(fileName.toStdString());
}

void MainWindow::on_PpushButtonSelectFolder_clicked()
{
}

void MainWindow::on_CpushButtonOpenFile_clicked()
{

}

void MainWindow::on_CpushButtonSaveFile_clicked()
{

}

void MainWindow::on_CpushButtonTrain_clicked()
{
    QFile inputFile("D:\\Lodz 3 semestr\\SMPD\\SMPD\\SMPD\\Maple_Oak.txt");
    if (inputFile.open(QIODevice::ReadOnly))
    {
        QVector<QString> x;
        QVector<int> randomnumbersfortest;

        int fullVectorsize=0;

       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
            x.append(in.readLine());

       }
       fullVectorsize=x.size();
       int testcount=0;
       int trainpart=0;
       testcount = (x.size() * 0.3);
       trainpart=x.size()-testcount;
       ui->CplainTextEditTrainingPart->appendPlainText(QString::number(trainpart));
    }
}

void MainWindow::on_CpushButtonExecute_clicked()
{

}

void MainWindow::on_TrainTest_clicked()
{
//      dilenia na vektory Train i na Test

    qsrand(QTime::currentTime().msec());
    QFile inputFile("C:\\Users\\админ\\Desktop\\smpd\\Maple_Oak.txt");
    if (inputFile.open(QIODevice::ReadOnly))
    {
        QVector<QString> x;
        QVector<int> randomnumbersfortest;

        int fullVectorsize=0;

       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
            x.append(in.readLine());

       }
       fullVectorsize=x.size();
       int testcount=0;
       int trainpart=0;
       testcount = (x.size() * 0.3);
       trainpart=x.size()-testcount;
       ui->CplainTextEditTrainingPart->appendPlainText(QString::number(trainpart));
       for(int j=0; j<testcount;j++){
           int randomValue = qrand() % x.size();
           randomnumbersfortest.append(randomValue);
           ui->textBrowser->append(QString::number(randomValue));
       }
        ui->textBrowser->append(QString::number(fullVectorsize));
        for (uint i = 1; i < fullVectorsize; ++i){
           for(uint l = 0; l < testcount; ++l){
                   if(i!=randomnumbersfortest.value(l))
                   {
                       if(l==testcount-1){
                           train.append(x.value(i));
                       }
                       else
                       {
//                             test.append(x.value(i));
                       }

                   }
                   else
                   {
                         test.append(x.value(i));
                         break;
                   }
               }

           }

//for(int i = 0 ; i<fullVectorsize; i++){
//    ui->textBrowser->append(train.value(i)+"\n");
//}
        ui->textBrowser->append("Test count:"+(QString::number(test.size())));
        ui->textBrowser->append("Train count:"+(QString::number(train.size())));
       inputFile.close();

    }

}


   // int count=0;
  //  int tempRand=database.getNoObjects();
  //  int randnumber = rand() %99 + 1;
   // ui->FStextBrowserDatabaseInfo->append("test"+QString::number(tempRand));


void MainWindow::on_pushButton_clicked()
{
}

void MainWindow::on_NN_clicked()
{
    QVector<double> allsum;
double kwadratvalue =0;
 QVector<double> kwadrat;
    double classright=0;
    int alltrain = 0;
    alltrain = train.size();
    double alltest = 0;
    alltest = test.size();
ui->textBrowser->append(QString::number(alltrain));
for(uint i = 0 ; i<alltest; i++){
   kwadrat.clear();
    for(uint j = 0 ; j<alltrain; j++){
        allsum.clear();
        double sumallvalues=0;
        QString onelinetrain=train.value(j);
        QString onelinetest=test.value(i);
        //ui->textBrowser->append(train.value(2));
          QStringList piecestrain = onelinetrain.split( "," );
          QStringList piecestest = onelinetest.split( "," );
          for(int k=1 ; k < piecestrain.length() ; k++){
              double value1 = QString(piecestrain.at(k)).toDouble();
              double value2 = QString(piecestest.at(k)).toDouble();
              double sum = pow(value1-value2,2);
//              ui->textBrowser->append(QString::number(sum));
              allsum.append(sum);
          }

          for(int l=0 ; l < allsum.size() ; l++){
              sumallvalues+=allsum.value(l);
          }
          double kwadratvalue = sqrt(sumallvalues);
          kwadrat.append(kwadratvalue);


    }
    double min = *std::min_element(kwadrat.begin(), kwadrat.end());
    int rownumber = std::distance(kwadrat.begin(), std::min_element(kwadrat.begin(), kwadrat.end()));
    ui->textBrowser->append("Min value:" + (QString::number(min))+"row:"+(QString::number(rownumber)));
    QString finallinetrain = train.value(rownumber);
    QString finalline = test.value(i);
    QStringList piecestrain = finallinetrain.split( " " );
    QStringList piecestest = finalline.split( " " );
    QString classvaluetrain=piecestrain.at(0);
    QString classvaluetest=piecestest.at(0);
    ui->textBrowser->append(classvaluetrain+"="+classvaluetest);
    if(classvaluetrain==classvaluetest){
        classright++;
    }
    else{

    }
     ui->textBrowser->append("Class Right:"+(QString::number(classright)));
}
//-------------------------------------
double procright = (classright/alltest)*100;

//-------------------------------------

ui->textBrowser->append("Percent Right:"+(QString::number(procright))+" %");

}

void MainWindow::on_NM_clicked()
{
    QVector<QString> klasterTrainAcer;
    QVector<QString> klasterTrainQuercus;
    QVector<double> VectorForMeanAcer;
    QVector<double> VectorForMeanQuercus;
    QVector<double> allsumAcer;
    QVector<double> allsumQuercus;
    double kwadratvalue =0;
    QVector<double> kwadratAcer;
    QVector<double> kwadratQuercus;
    double counter=0;
    double classright=0;
    int alltrain = 0;
    alltrain = train.size();
    double alltest = 0;
    alltest = test.size();

    // DELIM TRAIN NA ACER I QUERCUS
    for(uint j = 0 ; j<alltrain; j++){
        QString onelinetrain=train.value(j);
        QStringList piecestrain = onelinetrain.split( " " );
        QString classvaluetrain=piecestrain.at(0);
        if(classvaluetrain == "Acer"){
            klasterTrainAcer.append(train.value(j));
        }
        if(classvaluetrain == "Quercus"){
            klasterTrainQuercus.append(train.value(j));
        }

    }
    QString onelinetrain=klasterTrainAcer.value(0);


    // SHITAEM SREDNEE KAJDOGO STOLBCA VECTORA GDE TOLKO ACER

    QStringList piecestrain = onelinetrain.split( "," );
        for(int i = 1;i<piecestrain.length();i++){
            double sredneecolumn = 0;
            for(int j =0;j<klasterTrainAcer.size();j++){
                QString onelinetrain=klasterTrainAcer.value(j);
                QStringList splitedtrain = onelinetrain.split( "," );
                double value1 = QString(splitedtrain.at(i)).toDouble();
                sredneecolumn +=value1;
            }
            double srednee;
            srednee = sredneecolumn/klasterTrainAcer.size();
            ui->textBrowser->append(QString::number(srednee));
            VectorForMeanAcer.append(srednee);
        }

        // SHITAEM SREDNEE KAJDOGO STOLBCA VECTORA GDE TOLKO QUERCUS

            for(int i = 1;i<piecestrain.length();i++){
                double sredneecolumn = 0;
                for(int j =0;j<klasterTrainQuercus.size();j++){
                    QString onelinetrain=klasterTrainQuercus.value(j);
                    QStringList splitedtrain = onelinetrain.split( "," );
                    double value1 = QString(splitedtrain.at(i)).toDouble();
                    sredneecolumn +=value1;
                }
                double srednee;
                srednee = sredneecolumn/klasterTrainQuercus.size();
                ui->textBrowser->append(QString::number(srednee));
                VectorForMeanQuercus.append(srednee);
            }
            //SHITAM RAZNICU MEZDU PROBKOI I SREDNEI
            for(int i = 0 ; i<alltest;i++){
                allsumAcer.clear();
                allsumQuercus.clear();
                double sumallvaluesAcer=0;
                double sumallvaluesQuercus=0;
                QString onelinetrain=test.value(i);
                QStringList splitedtest = onelinetrain.split( "," );
                for(int k=1 ; k < splitedtest.length(); k++){
                    double value1 = QString(splitedtest.at(k)).toDouble();

                    double sum1 = pow(value1-VectorForMeanAcer.value(k-1),2);
                    double sum2 = pow(value1-VectorForMeanQuercus.value(k-1),2);

                    allsumAcer.append(sum1);
                    allsumQuercus.append(sum2);
                }

                for(int l=0 ; l < allsumAcer.size() ; l++){
                    sumallvaluesAcer+=allsumAcer.value(l);
                    sumallvaluesQuercus+=allsumQuercus.value(l);
                }
                double kwadratvalueAcer = sqrt(sumallvaluesAcer);
                double kwadratvalueQuercus = sqrt(sumallvaluesQuercus);

                //CHECK ACER OR QUERCUS
                ui->textBrowser->append(QString::number(kwadratvalueAcer) + " - " + QString::number(kwadratvalueQuercus));
                if(kwadratvalueAcer>kwadratvalueQuercus){
                    ui->textBrowser->append("VECTOR NALEZY DO ACER");
                    QStringList splitedtest = onelinetrain.split( " " );
                    ui->textBrowser->append(splitedtest.at(0));
                    if(splitedtest.at(0)=="Acer"){
                        counter++;
                        ui->textBrowser->append(QString::number(counter));
                    }
                }
                if(kwadratvalueAcer<kwadratvalueQuercus){
                    ui->textBrowser->append("VECTOR NALEZY DO QUERCUS");
                    QStringList splitedtest = onelinetrain.split( " " );
                    ui->textBrowser->append(splitedtest.at(0));
                    if(splitedtest.at(0)=="Quercus"){
                        counter++;
                        ui->textBrowser->append(QString::number(counter));
                    }
                }

            }

            double procright = (counter/alltest)*100;

            //-------------------------------------

            ui->textBrowser->append("Percent Right:"+(QString::number(procright))+" %");




}

void MainWindow::on_bootstrap_clicked()
{
    qsrand(QTime::currentTime().msec());
    QVector<int> randomnumbersfortest;
    QFile inputFile("C:\\Users\\админ\\Desktop\\smpd\\Maple_Oak.txt");
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QVector<QString> x;

       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
            x.append(in.readLine());

       }
       int testcount = x.size();
       ui->textBrowser->append(QString::number(testcount));
       for(int j=0; j<testcount;j++){
           int randomValue = qrand() % x.size();
           randomnumbersfortest.append(randomValue);
           ui->textBrowser->append(QString::number(randomValue));
       }

       for (uint i = 1; i < testcount; ++i){
          for(uint l = 0; l < testcount; ++l){
                  if(i==randomnumbersfortest.value(l))
                  {
                      train.append(x.value(i));
                      break;

                  }
                  else
                  {
                      if(l==testcount-1){
                          test.append(x.value(i));
                      }
                      else
                      {
//                             test.append(x.value(i));
                      }
                  }
              }

          }
       ui->textBrowser->append("Test count:"+(QString::number(test.size())));
       ui->textBrowser->append("Train count:"+(QString::number(train.size())));
      inputFile.close();


      // DO THIS SOME MEthODS NN OR NM

      //


      train.clear();
      test.clear();


    }
}
