#ifndef USERINFO_H
#define USERINFO_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include "ui_signupui.h"

class UserInfo : public QDialog {
    Q_OBJECT


public:
    QString m_profilePicturePath; // Store the profile picture path
    QString m_fullName; // Store the user's full name

    UserInfo(QWidget *parent = nullptr);
    // Getter functions for user information
    QString getFirstName() const { return firstNameLineEdit->text(); }
    QString getLastName() const { return lastNameLineEdit->text(); }
    QString getProfilePicturePath() const;
    QString getFullName() const;


private slots:
    void startGame();
    void startGuestGame();
    void signUp();

private:
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QLineEdit *firstNameLineEdit;
    QLineEdit *lastNameLineEdit;
    QLineEdit *profilePicturePathLineEdit;
    Ui::SignUpUI *ui;


    // Function prototype for creating question mark button
    QPushButton* createQuestionMarkButton(const QString& tooltipText);

};

#endif // USERINFO_H

