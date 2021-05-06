#include "inputkey.h"
#include "ui_inputkey.h"
#include <QDesktopServices>
#include <QUrl>

using namespace LibGUI;

inputkey::inputkey(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inputkey)
{
    ui->setupUi(this);
    setWindowTitle("");
    setWindowFlags(Qt::CustomizeWindowHint | Qt::Dialog);
}

inputkey::~inputkey()
{
    delete ui;
}

void LibGUI::inputkey::on_buttonBox_accepted()
{
    QString link = "https://www.facebook.com/sukinocandra";

    QDesktopServices::openUrl(QUrl(link));
}
