/*
 * datesettingdialog.h
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
#ifndef DATESETTINGDIALOG_H
#define DATESETTINGDIALOG_H

#include <QDialog>

namespace Ui {
class DateSettingDialog;
}

namespace LibGUI {

class DateSettingDialog : public QDialog
{
    Q_OBJECT

public:
    DateSettingDialog(QWidget *parent = 0);
    ~DateSettingDialog();
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::DateSettingDialog *ui;
    bool mIsOk = false;

private slots:
    void saveClicked();
};

}

#endif // DATESETTINGDIALOG_H
