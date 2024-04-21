#ifndef SIGNUPUI_H
#define SIGNUPUI_H
#include "userinfo.h"
#include <QWidget>

namespace Ui {
class SignUpUI;
}

class SignUpUI : public QWidget
{
    Q_OBJECT

public:
    explicit SignUpUI(QWidget *parent = nullptr);
    ~SignUpUI();

private slots:
    void on_submitBtn_clicked();

    void on_chooseBtn_clicked();

private:
    Ui::SignUpUI *ui;
    QString profilePicturePath;

signals:
    void signUpCompleted();
};

#endif // SIGNUPUI_H
