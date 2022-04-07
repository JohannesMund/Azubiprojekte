#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QColor>
#include <QTextEdit>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->newColor->setPlaceholderText("Neuer Hexcode");
    ui->dateiPfad->setPlaceholderText("Dateipfad");
    ui->Change->setText("Change");
    ui->Search->setText("Search");
    ui->colorPicker->setText("Open Color Picker");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Search_clicked()
{
    uiClear();
    Suche a(ui->dateiPfad->text());
    a.list();
    a.isSVG();

        //durchsucht den angegebenen Dateipfad nach SVGFiles

    std::vector<QString> v = a.getError();
    if(v.size() != 0){
        QMessageBox box;
        for(unsigned int i = 0; i < v.size(); i++){
            box.setDetailedText(v[i]);
        }

            //gibt im Notfall felerhafte Datien an

    }
    fileList = a.getFileList();
    setNewListWidget(a.getFileList());
    setNewStartColor(a.getSpeicher());

        //überschreibt die Ui mit den neuen Informationen

}

void MainWindow::on_Change_clicked()
{
    Change a(fileList);

    if( a.isValid(ui->newColor->text()) == false)
    {
        QMessageBox::warning(this, "Warning", "Input is invalid!");
        return;
    }

    if(a.fileListValid() == false){
        QMessageBox::warning(this, "Warning", "File list is empty!");
        return;
    }

    if(a.colorChange(ui->startColor->currentText(), ui->newColor->text()) == false)
    {
        QMessageBox::warning(this, "Warning", "writing files failed" );
    }
}

void MainWindow::on_colorPicker_clicked(){
    QColorDialog a;
    auto color = a.getColor();
    ui->newColor->setText(color.name());

        //öffnet einen ColorPicker und setzt die zuletzt ausgesuuchte Farbe in die Zeile für die neue Farbe

}


void MainWindow::uiClear(){
    fileList.clear();
    ui->startColor->clear();
    ui->listWidget->clear();
    ui->newColor->clear();

        //löscht jegliche Informationen die abhängig vom Dateipfad sind

}

void MainWindow::setNewListWidget(QFileInfoList inf){   
    for (auto i : inf){
        ui->listWidget->addItem(i.filePath());
    }

}

void MainWindow::setNewStartColor(std::vector<QString> speicher)
{
    for(unsigned int i = 0; i < speicher.size(); i++){
        ui->startColor->addItem(speicher[i]);
    }
}
