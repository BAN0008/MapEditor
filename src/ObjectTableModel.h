#ifndef OBJECTTABLEMODEL_H
#define OBJECTTABLEMODEL_H

#include <QtCore/QAbstractTableModel>

class ObjectTableModel : public QAbstractTableModel
{
public:
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

	void beginInsertRows2(const QModelIndex &parent, int first, int last);
	void endInsertRows2();
	void beginRemoveRows2(const QModelIndex &parent, int first, int last);
	void endRemoveRows2();
};

#endif //OBJECTTABLEMODEL_H