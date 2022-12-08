#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    file_path = "";
    ui->textEdit->setText("");
}


void MainWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Open the file");
    QFile file(file_name);
    file_path = file_name;

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"..","File not open");
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();

}


void MainWindow::on_actionSave_triggered()
{
    QFile file(file_path);

            if(!file.open(QFile::WriteOnly | QFile::Text)){
                QMessageBox::warning(this,"..","File not open");
                return;
            }
            QTextStream out(&file);
            QString text = ui->textEdit->toPlainText();
            out << text;
            file.flush();
            file.close();

}


void MainWindow::on_actionSave_As_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this,"Save the file");
        QFile file(file_name);
        file_path = file_name;

                if(!file.open(QFile::WriteOnly | QFile::Text)){
                    QMessageBox::warning(this,"..","File not open");
                    return;
                }
                QTextStream out(&file);
                QString text = ui->textEdit->toPlainText();
                out << text;
                file.flush();
                file.close();

}


void MainWindow::on_actionCut_triggered()
{
        ui->textEdit->cut();
}


void MainWindow::on_actionCopy_triggered()
{
        ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionRedo_triggered()
{
        ui->textEdit->redo();
}


void MainWindow::on_actionUndo_triggered()
{
        ui->textEdit->undo();
}


void MainWindow::on_actionResume_triggered()
{
    QString about_text;
    about_text = "<b><u>Personal Details</u></b>";
    about_text += "<ul><li><b>Name:</b> Akshay Syal </li>";
    about_text += "<li><b>Email:</b> akshaysyal19@gmail.com</li>";
    about_text += "<li><b>Mobile Number:</b> 8823084428 </li></ul>";

    about_text += "<b><u>Education</u></b>";
    about_text += "<ul><li>BTech. in CSE spec. in Data Science from VIT, Vellore (07/2019 - 07/2023,)</li>";
    about_text += "<li>Delhi Public School, Bhopal (04/2010 - 03/2019,) </li></ul>";

    about_text += "<b><u>Work Experience</u></b>";
    about_text += "<ul><li>Research Intern at RBG Labs, IIT Chennai (05/2022 - 08/2022)</li>";
    about_text += "<li>Backend Developer, Kleiba (04/2022 - 07/2022) </li></ul>";

    about_text += "<b><u>Skills</u></b>";
    about_text += "<ul><li>C++</li>";
    about_text += "<li>C</li>";
    about_text += "<li>Python</li>";
    about_text += "<li>Tensorflow</li>";
    about_text += "<li>MongoDB</li>";
    about_text += "<li>Express</li>";
    about_text += "<li>React</li>";
    about_text += "<li>Jupyter Notebook</li>";
    about_text += "<li>Github</li></ul>";

    about_text += "<b><u>Personal Projects</u></b>";
    about_text += "<ul><li>Object Detection in Low Light Images (01/2022 - 04/2022)</li>";
    about_text += "<li>Github Finder (03/2021 - 05/2021)</li>";
    about_text += "<li>Intrusion Detection System using ML algorithms (08/2021 - 12/2021)</li></ul>";

    about_text += "<b><u>Languages</u></b>";
    about_text += "<ul><li>English</li><li>Hindi</li></ul>";
    QMessageBox::about(this,"Resume",about_text);

}


void MainWindow::on_actionBold_triggered()
{
    QTextCharFormat format;
    format.setFontWeight(QFont::Bold);

    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.mergeCharFormat(format);

}


void MainWindow::on_actionUnBold_triggered()
{
    QTextCharFormat format;
    format.setFontWeight(QFont::Normal);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.mergeCharFormat(format);

}


void MainWindow::on_actionSuperscript_triggered()
{
    QTextCharFormat format;
    format.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.mergeCharFormat(format);

}


void MainWindow::on_actionSubscript_triggered()
{
    QTextCharFormat format;
    format.setVerticalAlignment(QTextCharFormat::AlignSubScript);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.mergeCharFormat(format);

}


void MainWindow::on_actionNormal_triggered()
{
    QTextCharFormat format;
    format.setVerticalAlignment(QTextCharFormat::AlignNormal);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.mergeCharFormat(format);

}

