#include "signupui.h"
#include "ui_signupui.h"
#include <QFileDialog>
#include <QPixmap>
#include <QMessageBox>

SignUpUI::SignUpUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignUpUI)
{
    ui->setupUi(this);
}

SignUpUI::~SignUpUI()
{
    delete ui;
}

void SignUpUI::on_submitBtn_clicked()
{
    // Collect data from UI elements
    QString firstName = ui->FNEdit->text();
    QString lastName = ui->LNEdit->text();
    QDate dateOfBirth = ui->DOBEdit->date();
    QString gender = ui->genderBox->currentText();  // Assuming a QComboBox for gender
    QString username = ui->UNEdit->text();
    QString password = ui->PWEdit->text();

    // Open a file dialog to specify the file to save
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save User Info"), ":/", tr("Text Files (*.txt)"));
    if (fileName.isEmpty())
        return;

    // Open the file to write
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Could not open file for writing.");
        return;
    }

    // Write the collected data to the file
    QTextStream out(&file);
    out << "First Name: " << firstName << "\n";
    out << "Last Name: " << lastName << "\n";
    out << "Date of Birth: " << dateOfBirth.toString("yyyy-MM-dd") << "\n";
    out << "Gender: " << gender << "\n";
    out << "Username: " << username << "\n";
    out << "Password: " << password << "\n";  // Caution: saving passwords in plain text is insecure
    out << "Profile Picture Path: " << profilePicturePath << "\n";

    file.close();

    // Optionally notify the user that the data has been saved
    QMessageBox::information(this, "Information", "Profile data saved successfully.");

    emit signUpCompleted();
}


void SignUpUI::on_chooseBtn_clicked()
{
    // Open a file dialog to select an image
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open Image"), ":/profile_pictures",
                                                    tr("Images (*.jpg)"));

    if (!filePath.isEmpty()) {
        QPixmap image(filePath);

        // Optionally resize the image to fit the QLabel, preserving the aspect ratio
        QPixmap scaledImage = image.scaled(ui->PPLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

        // Set the pixmap of the QLabel to the selected image
        ui->PPLabel->setPixmap(scaledImage);

        // Save the file path
        profilePicturePath = filePath;
    }
}


