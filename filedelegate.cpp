#include "filedelegate.h"
#include <QDebug>
#include "fileeditor.h"

CFileDelegate::CFileDelegate(QObject* parent)
    :QItemDelegate(parent)
{
}

QWidget* CFileDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    CFileEditor* e = new CFileEditor(parent);
    e->setGeometry(option.rect);
    return e;
}

void CFileDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    CFileEditor* e = static_cast<CFileEditor*>(editor);
    e->setFileName(index.data(Qt::EditRole).toString());
}

void CFileDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    CFileEditor* e = static_cast<CFileEditor*>(editor);
    QString f = e->getFileName();
    if(f != "")
    {
        model->setData(index, f);
    }
    else
    {
        return QItemDelegate::setModelData(editor, model, index);
    }
}

void CFileDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    CFileEditor* e = static_cast<CFileEditor*>(editor);
    e->setGeometry(option.rect);
}
