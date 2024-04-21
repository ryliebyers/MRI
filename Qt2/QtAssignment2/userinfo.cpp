#include "userinfo.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "levelselectiondialog.h"
#include "signupui.h"
#include "game1scene.h"
#include <QGraphicsView>

UserInfo::UserInfo(QWidget *parent) : QDialog(parent), ui(new Ui::SignUpUI) {
    //ui->setupUi(this);

    setWindowTitle("User Information");

    // Set the fixed size of the dialog window
    setFixedSize(400, 300);



    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setAlignment(Qt::AlignCenter); // Align main layout to center

    // Create a QHBoxLayout to hold the image and input fields
    QHBoxLayout *layout = new QHBoxLayout;
    layout->setAlignment(Qt::AlignCenter); // Align layout to center

    // Create a QVBoxLayout to hold the input fields
    QVBoxLayout *inputLayout = new QVBoxLayout;
    inputLayout->setAlignment(Qt::AlignCenter); // Align input layout to center

    // Username Label and Input Field
    QHBoxLayout *usernameLayout = new QHBoxLayout;
    usernameLayout->setAlignment(Qt::AlignLeft); // Align layout to the left
    QLabel *usernameLabel = new QLabel("Username:", this);
    usernameLabel->setAlignment(Qt::AlignLeft); // Align label to the left
    usernameLineEdit = new QLineEdit(this);
    usernameLineEdit->setPlaceholderText("Username");
    usernameLineEdit->setFixedWidth(250); // Set the width of the username input field
    usernameLayout->addWidget(usernameLabel);
    usernameLayout->addWidget(usernameLineEdit);
    usernameLayout->setSpacing(10);
    inputLayout->addLayout(usernameLayout);

    // Password Label and Input Field
    QHBoxLayout *passwordLayout = new QHBoxLayout;
    passwordLayout->setAlignment(Qt::AlignLeft); // Align layout to the left
    QLabel *passwordLabel = new QLabel("Password:", this);
    passwordLabel->setAlignment(Qt::AlignLeft); // Align label to the left
    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setPlaceholderText("Password");
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    passwordLineEdit->setFixedWidth(250); // Set the width of the password input field
    passwordLayout->addWidget(passwordLabel);
    passwordLayout->addWidget(passwordLineEdit);
    passwordLayout->setSpacing(10);
    inputLayout->addLayout(passwordLayout);



    layout->addLayout(inputLayout);
    mainLayout->addLayout(layout);

    // Create a QHBoxLayout to hold the "Guest login" button and question mark button
    QHBoxLayout *guestLoginLayout = new QHBoxLayout;

    QPushButton *guestLogin = new QPushButton("Guest login", this);
    guestLogin->setStyleSheet("QPushButton {"
                              "background-color: darkblue;"
                              "color: white;"
                              "border-style: outset;"
                              "border-width: 2px;"
                              "border-radius: 10px;"
                              "border-color: beige;"
                              "font: bold 14px;"
                              "min-width: 10em;"
                              "padding: 6px;"
                              "}"
                              "QPushButton:hover {"
                              "background-color: blue;"
                              "}");

    // Set tooltip for the guest login button
    guestLogin->setToolTip("The guest login does not require an account and wouldn't store your information such as account and your score");

    QPushButton *guestQuestionMarkButton = createQuestionMarkButton("By signing in, you can play games and see your history and everything");

    guestLoginLayout->addWidget(guestLogin);
    guestLoginLayout->addWidget(guestQuestionMarkButton);

    mainLayout->addLayout(guestLoginLayout);

    // Create a QHBoxLayout to hold the "Sign in" button and question mark button
    QHBoxLayout *signInLayout = new QHBoxLayout;

    QPushButton *signInButton = new QPushButton("Sign in", this);
    signInButton->setStyleSheet("QPushButton {"
                                "background-color: darkorange;"
                                "color: white;"
                                "border-style: outset;"
                                "border-width: 2px;"
                                "border-radius: 10px;"
                                "border-color: beige;"
                                "font: bold 14px;"
                                "min-width: 10em;"
                                "padding: 6px;"
                                "}"
                                "QPushButton:hover {"
                                "background-color: orange;"
                                "}");

    // Set tooltip for the sign in button
    signInButton->setToolTip("By signing in, you can play games and see your history and everything");

    QPushButton *signInQuestionMarkButton = createQuestionMarkButton("By signing in, you can play games and see your history and everything");

    signInLayout->addWidget(signInButton);
    signInLayout->addWidget(signInQuestionMarkButton);

    mainLayout->addLayout(signInLayout);

    // Create a QHBoxLayout to hold the "Sign Up" button and question mark button
    QHBoxLayout *signUpLayout = new QHBoxLayout;

    QPushButton *signUpButton = new QPushButton("Sign up", this);
    signUpButton->setStyleSheet("QPushButton {"
                                "background-color: darkgreen;"
                                "color: white;"
                                "border-style: outset;"
                                "border-width: 2px;"
                                "border-radius: 10px;"
                                "border-color: beige;"
                                "font: bold 14px;"
                                "min-width: 10em;"
                                "padding: 6px;"
                                "}"
                                "QPushButton:hover {"
                                "background-color: green;"
                                "}");

    // Set tooltip for the sign up button
    signUpButton->setToolTip("If you do not already have an account, click the Sign Up button and fill out the form.");

    QPushButton *signUpQuestionMarkButton = createQuestionMarkButton("If you do not already have an account, click the Sign Up button and fill out the form.");

    signUpLayout->addWidget(signUpButton);
    signUpLayout->addWidget(signUpQuestionMarkButton);

    mainLayout->addLayout(signUpLayout);


    connect(guestLogin, &QPushButton::clicked, this, &UserInfo::startGuestGame);
    connect(signInButton, &QPushButton::clicked, this, &UserInfo::startGame);
    connect(signUpButton, &QPushButton::clicked, this, &UserInfo::signUp);
}




QPushButton* UserInfo::createQuestionMarkButton(const QString& tooltipText) {
    QPushButton *questionMarkButton = new QPushButton(this);
    questionMarkButton->setFixedSize(20, 20);
    questionMarkButton->setIcon(QIcon(":/images/questionMark.png"));
    questionMarkButton->setIconSize(QSize(20, 20));
    questionMarkButton->setFlat(true);
    questionMarkButton->setToolTip(tooltipText);

    return questionMarkButton;
}
void UserInfo::signUp() {
    // Create a new instance of SignUpUI QDialog
    QDialog *signUpForm = new QDialog(this);

    // Create an instance of the UI class for the SignUpUI form
    Ui::SignUpUI signUpUI;
    signUpUI.setupUi(signUpForm);

    // Show the SignUpUI form
    signUpForm->exec(); // Use exec() instead of show() to display it as a modal dialog
}



void UserInfo::startGame() {
    // Open the file for reading
    QFile file(":/images/somebody.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for reading.";
        return;
    }

    // Read the file line by line
    QTextStream in(&file);
    while (!in.atEnd()) {
        // Read user information from the file
        QString firstName = in.readLine().split(":").at(1).trimmed();
        QString lastName = in.readLine().split(":").at(1).trimmed();
        QString dateOfBirth = in.readLine().split(":").at(1).trimmed();
        QString gender = in.readLine().split(":").at(1).trimmed();
        QString username = in.readLine().split(":").at(1).trimmed();
        QString password = in.readLine().split(":").at(1).trimmed();
        QString profilePicturePath = in.readLine().split(":").at(1).trimmed();

        // Check if entered username and password match
        if (username == usernameLineEdit->text() && password == passwordLineEdit->text()) {
            // Close the dialog if the credentials are correct
            accept();

            // Update member variables with user information
            m_fullName = firstName + " " + lastName;
            m_profilePicturePath = profilePicturePath;

            // Pass the username and profile picture path to the Game1Scene class
            Game1Scene *scene1 = new Game1Scene(m_fullName, m_profilePicturePath);

            // Create view to visualize the scene
            QGraphicsView view(scene1);
            view.setFixedSize(910, 512);
            view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            view.show();

            return;
        }
    }

    // Show error message if username is not found in the file
    QMessageBox::critical(this, "Invalid Credentials", "The username or password is invalid. Please sign up to create an account.");
}



void UserInfo::startGuestGame() {
    // Close the dialog if the credentials are correct
    accept();

    // Open the level selection dialog
    LevelSelectionDialog *levelDialog = new LevelSelectionDialog(this);
    levelDialog->exec();

    return;
}
