#ifndef FILEEDITOR_H
#define FILEEDITOR_H

#include <QWidget>

namespace Ui {
class CFileEditor;
}

class CFileEditor : public QWidget
{
    Q_OBJECT

public:
    explicit CFileEditor(QWidget *parent = nullptr);
    ~CFileEditor();

public:
    QString getFileName();
    void setFileName(const QString& f);

#if 0
protected:
    void showEvent(QShowEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
#endif

private slots:
    void on_pushButton_clicked();

private:
    Ui::CFileEditor *ui;
};

#endif // FILEEDITOR_H
