/*
 * abstractimperiongui.h
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
#ifndef ABSTRACTIMPERIONGUI_H
#define ABSTRACTIMPERIONGUI_H

#include "global_global.h"
#include <QString>
#include <functional>

namespace LibG {

class GLOBALSHARED_EXPORT AbstractImperionGUI
{
public:
    virtual ~AbstractImperionGUI();
    virtual void showSplashScreen() = 0;
    virtual void hideSplashScreen() = 0;
    virtual void showKeyInput() = 0;
    virtual void splashShowMessage(const QString &msg) = 0;
    virtual void showSetting() = 0;
    virtual void showMainWindow() = 0;
    virtual void showRestartError(const QString &title, const QString &msg) = 0;
    virtual void guiMessage(int id, const QString &str) = 0;
    virtual void setSettingSocketOpenClose(std::function<void(const QString&, int)> openCon, std::function<void()> closeCon) = 0;
};

}

#endif // ABSTRACTIMPERIONGUI_H
