#ifndef INPUTKEY_H
#define INPUTKEY_H

#include <QDialog>

namespace Ui {
class inputkey;
}

namespace LibGUI {

class inputkey : public QDialog
{
    Q_OBJECT

public:
    explicit inputkey(QWidget *parent = nullptr);
    ~inputkey();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::inputkey *ui;
};
}

#endif // INPUTKEY_H
