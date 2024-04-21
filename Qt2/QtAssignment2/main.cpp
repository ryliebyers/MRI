
#include <QApplication>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QLabel>
#include <QFile>
#include "game1scene.h"
#include "userinfo.h"
#include "historywindow.h"
#include <QDateTime>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Create and display the UserInfo dialog
    UserInfo userInfoDialog;
    if (userInfoDialog.exec() != QDialog::Accepted) {
        // If the user cancels or closes the dialog, exit the application
        return 0;
    }

    // Open the file for reading
    QFile file(":/images/somebody.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for reading.";
        return 0;
    }

    // Read the user information from the file
    QTextStream in(&file);

    QString firstName, lastName, dateOfBirth, gender, username, password, profilePicturePath;
    while (!in.atEnd()) {
        firstName = in.readLine().split(":").at(1).trimmed();
        lastName = in.readLine().split(":").at(1).trimmed();
        dateOfBirth = in.readLine().split(":").at(1).trimmed();
        gender = in.readLine().split(":").at(1).trimmed();
        username = in.readLine().split(":").at(1).trimmed();
        password = in.readLine().split(":").at(1).trimmed();
        profilePicturePath = in.readLine().split(":").at(1).trimmed();
    }

    // Close the file
    file.close();

    // Create the scene with user information
    Game1Scene *scene1 = new Game1Scene(firstName + " " + lastName, profilePicturePath);

    // Create view to visualize the scene
    QGraphicsView *view = new QGraphicsView(scene1);
    view->setFixedSize(910, 512);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Create a QWidget to hold the view and additional widgets
    QWidget *mainWidget = new QWidget();
    QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);

    // Add the view to the main layout
    mainLayout->addWidget(view);

    // Create a widget to hold the profile picture, user name, and score
    QWidget *bottomWidget = new QWidget();
    QHBoxLayout *bottomLayout = new QHBoxLayout(bottomWidget);

    // Create and add profile picture
    QPixmap profilePicture(profilePicturePath);
    QLabel *profilePictureLabel = new QLabel();
    profilePictureLabel->setPixmap(profilePicture.scaled(30, 30));
    bottomLayout->addWidget(profilePictureLabel);

    // Add user name label
    QLabel *userNameLabel = new QLabel(firstName + " " + lastName);
    bottomLayout->addWidget(userNameLabel);

    // Add date label
    QLabel *dateLabel = new QLabel();
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString formattedDate = currentDateTime.toString("ddd MMM d yyyy");
    dateLabel->setText(formattedDate);
    dateLabel->setStyleSheet("color: gray; font-size: 12px;"); // Style the date label
    bottomLayout->addWidget(dateLabel);


    // Create buttons
    // Create buttons
    QPushButton *quitButton = new QPushButton("Quit");
    quitButton->setStyleSheet("QPushButton {"
                              "background-color: blue;"
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
                              "background-color: darkblue;"
                              "}");
    QPushButton *viewHistoryButton = new QPushButton("View History");
    viewHistoryButton->setStyleSheet("QPushButton {"
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


    // Connect signals and slots for buttons
    QObject::connect(quitButton, &QPushButton::clicked, &a, &QApplication::quit);
    QObject::connect(viewHistoryButton, &QPushButton::clicked, [&]() {
        // Create and display the history window
        HistoryWindow *historyWindow = new HistoryWindow();
        historyWindow->show();
    });

    // Add buttons to the layout
    bottomLayout->addWidget(viewHistoryButton);
    bottomLayout->addWidget(quitButton);

    // Set the layout of the bottom widget
    bottomWidget->setLayout(bottomLayout);

    // Add the bottom widget to the main layout
    mainLayout->addWidget(bottomWidget);

    // Set the main layout to the main widget
    mainWidget->setLayout(mainLayout);

    // Set the main widget as the central widget of the application
    mainWidget->show();

    // Start the application event loop
    return a.exec();
}
