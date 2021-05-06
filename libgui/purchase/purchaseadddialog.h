/*
 * purchaseadddialog.h
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
#ifndef PURCHASEADDDIALOG_H
#define PURCHASEADDDIALOG_H

#include "messagehandler.h"
#include <QDialog>

namespace Ui {
class PurchaseAddDialog;
}

namespace LibGUI {

class PurchaseAddDialog : public QDialog, public LibG::MessageHandler
{
    Q_OBJECT

public:
    explicit PurchaseAddDialog(LibG::MessageBus *bus, QWidget *parent = 0);
    ~PurchaseAddDialog();
    void reset();
    void fill(const QVariantMap &data);

protected:
    void messageReceived(LibG::Message *msg) override;
    void showEvent(QShowEvent *event) override;

private:
    Ui::PurchaseAddDialog *ui;
    int mCurrentSuplier = 0;
    int mId = 0;
    double mTotal = 0;
    int mBankId = 0;

    void populateSuplier(const QVariantList &list);

signals:
    void successAdd();
    void successUpdate(const QVariant &id);

private slots:
    void saveClicked();
    void typeChanged();
    void calculateTotal();
};

}
#endif // PURCHASEADDDIALOG_H
