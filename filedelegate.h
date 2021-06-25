#ifndef CFILEDELEGATE_H
#define CFILEDELEGATE_H

#include <QItemDelegate>

class CFileDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    CFileDelegate(QObject* parent=nullptr);

    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // CFILEDELEGATE_H
