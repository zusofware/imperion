/*
 * customerwidget.h
 * Copyright 2021 - ~, Shu Khi No <hernandessukino94@gmail.com>
 *
 * This file is part of Imperion.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef CUSTOMERWIDGET_H
#define CUSTOMERWIDGET_H

#include "messagehandler.h"
#include <QWidget>

namespace Ui {
class NormalWidget;
}

namespace LibGUI {

class TableWidget;
class CustomerAddDialog;
class TileWidget;

class CustomerWidget : public QWidget, public LibG::MessageHandler
{
    Q_OBJECT
public:
    CustomerWidget(LibG::MessageBus *bus, QWidget *parent = 0);

protected:
    void messageReceived(LibG::Message *msg) override;

private:
    Ui::NormalWidget *ui;
    TableWidget *mTableWidget;
    CustomerAddDialog *mAddDialog;
    TileWidget *mTileCredit;

private slots:
    void addClicked();
    void updateClicked(const QModelIndex &index);
    void deleteClicked(const QModelIndex &index);
    void customerAdded();
    void customerUpdated(int id);
    void creditClicked();
    void rewardClicked();
    void refreshSummary();

signals:
    void requestOpenCustomerCredit(int id, const QString &number);
    void requestOpenCustomerReward(int id, const QString &number);
};

}
#endif // CUSTOMERWIDGET_H
