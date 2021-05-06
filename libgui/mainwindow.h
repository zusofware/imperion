/*
 * mainwindow.h
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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "messagehandler.h"
#include "abstractimperiongui.h"
#include "gui_global.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QLabel;

namespace LibG {
class MessageBus;
}

namespace LibGUI {

class StatusBarWidget;
class Splash;
class LoginDialog;
class inputkey;

class GUISHARED_EXPORT MainWindow : public QMainWindow, public LibG::MessageHandler, public LibG::AbstractImperionGUI
{
    Q_OBJECT

public:
    MainWindow(LibG::MessageBus *bus, QWidget *parent = 0);
    ~MainWindow();
    void setup();
    void showSplashScreen() override;
    void hideSplashScreen() override;
    void showKeyInput() override;
    void splashShowMessage(const QString &msg) override;
    void showSetting() override;
    void showMainWindow() override;
    void showRestartError(const QString &title, const QString &msg) override;
    void guiMessage(int id, const QString &str) override;
    void setSettingSocketOpenClose(std::function<void(const QString&, int)> openCon, std::function<void()> closeCon) override;

protected:
    void closeEvent(QCloseEvent *event) override;
    void showEvent(QShowEvent *event) override;
    void messageReceived(LibG::Message *msg) override;

private:
    Ui::MainWindow *ui;
    int mLastIdLogin = 0;
    StatusBarWidget *mStatusBar;
    Splash *mSplashUi;
    inputkey *mInputKeyUI;
    LoginDialog *mLoginDialog;

    void setupConnection();

private slots:
    void loginSuccess();
    void logout();
    void showWindowFullScreen();
    void closeCurrentTab();
    void nextTab();
    void prevTab();
    void openSetting();
    void openUser();
    void openSuplier();
    void openCashier();
    void openAbout();
    void openCategory();
    void openItem();
    void openPurchase();
    void openPurchaseItem(const QVariantMap &data);
    void openSalesReport();
    void openItemReport();
    void openChangePassword();
    void openCustomer();
    void openCustomerCredit(int id, const QString &number);
    void openCustomerReward(int id, const QString &number);
    void openMachine();
    void openReward();
    void openBank();
    void openTransaction();
    void openMoney();
    void openAutoUpdate();
    void openPurchaseReturn();
    void openExportImport();
    void openCheckStock();
    void openInitialStock();
    void openUnit();
    void openDateSetting();
    void resetDatabase();
    void openStockCard();
    void openSoldReturn();
};

}
#endif // MAINWINDOW_H
