/*
 * rewardwidget.h
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
#ifndef REWARDWIDGET_H
#define REWARDWIDGET_H

#include "messagehandler.h"
#include <QWidget>

namespace Ui {
class RewardSetting;
}

namespace LibGUI {

class TableWidget;

class RewardWidget : public QWidget, public LibG::MessageHandler
{
    Q_OBJECT
public:
    RewardWidget(LibG::MessageBus *bus, QWidget *parent = 0);

private:
    Ui::RewardSetting *ui;

protected:
    void messageReceived(LibG::Message *msg) override;

private slots:
    void addExchangeClicked();
    void updateExchangeClicked(const QModelIndex &index);
    void deleteExchangeClicked(const QModelIndex &index);
    void addPoinClicked();
    void updatePoinClicked(const QModelIndex &index);
    void deletePoinClicked(const QModelIndex &index);
};

}

#endif // REWARDWIDGET_H
