/*
 * moneylineedit.h
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
#ifndef MONEYLINEEDIT_H
#define MONEYLINEEDIT_H

#include "gui_global.h"
#include <QLineEdit>

namespace LibGUI {

class GUISHARED_EXPORT MoneyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    MoneyLineEdit(QWidget *parent = nullptr);
    ~MoneyLineEdit();
    double value();

private slots:
    void textHasChanged(const QString &value);
};

}
#endif // MONEYLINEEDIT_H
