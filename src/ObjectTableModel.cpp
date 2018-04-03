#include "ObjectTableModel.h"
#include "Object.h"

int ObjectTableModel::rowCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	return objects.size();
}

int ObjectTableModel::columnCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);Q_UNUSED(parent);
	return 3;
}

QVariant ObjectTableModel::data(const QModelIndex &index, int role) const
{
	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (index.column())
		{
			//Object Name
			case 0:
				return "Object";
				break;
			//X
			case 1:
				return QString::number(objects[index.row()]->x);
				break;
			//Y
			case 2:
				return QString::number(objects[index.row()]->y);
				break;
			default:
				return {};
		}
	}
	else
	{
		return {};
	}
}

QVariant ObjectTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
	{
		switch (section)
		{
			//Name
			case 0:
				return "Object Name";
				break;
			//X
			case 1:
				return "X";
				break;
			//Y
			case 2:
				return "Y";
				break;
			default:
				return {};
		}
	}
	else
	{
		return {};
	}
}

void ObjectTableModel::beginInsertRows2(const QModelIndex &parent, int first, int last)
{
	beginInsertRows(parent, first, last);
}
void ObjectTableModel::endInsertRows2()
{
	endInsertRows();
}
void ObjectTableModel::beginRemoveRows2(const QModelIndex &parent, int first, int last)
{
	beginRemoveRows(parent, first, last);
}
void ObjectTableModel::endRemoveRows2()
{
	endRemoveRows();
}