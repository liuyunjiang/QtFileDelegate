#include "fileeditor.h"
#include "ui_fileeditor.h"
#include <QFileDialog>

CFileEditor::CFileEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CFileEditor)
{
    ui->setupUi(this);
}

CFileEditor::~CFileEditor()
{
    delete ui;
}

QString CFileEditor::getFileName()
{
    return ui->lineEdit->text().trimmed();
}

void CFileEditor::setFileName(const QString &f)
{
    ui->lineEdit->setText(f);
}

#if 0
void CFileEditor::showEvent(QShowEvent *event)
{
    ui->lineEdit->setGeometry(0, 0, width()-20, height());
    ui->pushButton->setGeometry(width()-20, 0, 20, height());
}

void CFileEditor::resizeEvent(QResizeEvent *event)
{
    ui->lineEdit->setGeometry(0, 0, width()-20, height());
    ui->pushButton->setGeometry(width()-20, 0, 20, height());
}
#endif

void CFileEditor::on_pushButton_clicked()
{
    QString f = QFileDialog::getOpenFileName(this);
    if(f == "")
    {
        return;
    }
    ui->lineEdit->setText(f);
}
