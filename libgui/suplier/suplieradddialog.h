/*
 * suplieradddialog.h
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
#ifndef SUPLIERADDDIALOG_H
#define SUPLIERADDDIALOG_H

#include <QDialog>

namespace Ui {
class SuplierAddDialog;
}

namespace LibGUI {

class SuplierAddDialog : public QDialog
{
    Q_OBJECT

public:
    SuplierAddDialog(QWidget *parent = 0);
    ~SuplierAddDialog();
    void reset();
    void fill(const QVariantMap &data);
    void enableSave();

private:
    Ui::SuplierAddDialog *ui;
    int mId = -1;

private slots:
    void saveClicked();

signals:
    void saveData(const QVariantMap &data, int id);
};

}
#endif // SUPLIERADDDIALOG_H
