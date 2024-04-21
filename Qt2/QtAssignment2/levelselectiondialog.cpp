#include "levelselectiondialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>
#include "globals.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>
LevelSelectionDialog::LevelSelectionDialog(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Option Selection Window");
    resize(450, 300);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setAlignment(Qt::AlignCenter);

    // Create level buttons and question mark buttons for each level
    QHBoxLayout *level1Layout = new QHBoxLayout; // Create a horizontal layout for level 1
    level1Button = new QPushButton("Level 1", this);
    level1Button->setStyleSheet("QPushButton {"
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
    level1Button->setToolTip("This is the easy level");
    connect(level1Button, &QPushButton::clicked, this, &LevelSelectionDialog::startGameAtLevel1);
    QPushButton *level1QuestionMarkButton = createQuestionMarkButton("This level is the easiest!");
    level1Layout->addWidget(level1QuestionMarkButton); // Add the question mark button to the layout
    level1Layout->addWidget(level1Button); // Add the level button to the layout
    mainLayout->addLayout(level1Layout); // Add the horizontal layout to the main vertical layout

    // Repeat the same process for level 2
    QHBoxLayout *level2Layout = new QHBoxLayout; // Create a horizontal layout for level 2
    level2Button = new QPushButton("Level 2", this);
    level2Button->setStyleSheet("QPushButton {"
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
    level2Button->setToolTip("This is medium level");
    connect(level2Button, &QPushButton::clicked, this, &LevelSelectionDialog::startGameAtLevel2);
    QPushButton *level2QuestionMarkButton = createQuestionMarkButton("This level is medium!");
    level2Layout->addWidget(level2QuestionMarkButton);
    level2Layout->addWidget(level2Button);
    mainLayout->addLayout(level2Layout);

    // Repeat the same process for level 3
    QHBoxLayout *level3Layout = new QHBoxLayout; // Create a horizontal layout for level 3
    level3Button = new QPushButton("Level 3", this);
    level3Button->setStyleSheet("QPushButton {"
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
    level3Button->setToolTip("This is the hardest level");
    connect(level3Button, &QPushButton::clicked, this, &LevelSelectionDialog::startGameAtLevel3);
    QPushButton *level3QuestionMarkButton = createQuestionMarkButton("This level is the hardest!");
    level3Layout->addWidget(level3QuestionMarkButton);
    level3Layout->addWidget(level3Button);
    mainLayout->addLayout(level3Layout);



}

void LevelSelectionDialog::startGameAtLevel1() {
    // Start the game at Level 1
     level1Clicked = true;

    accept();
}

void LevelSelectionDialog::startGameAtLevel2() {
    // Start the game at Level 2
     level2Clicked = true;
    accept();
}

void LevelSelectionDialog::startGameAtLevel3() {
    // Start the game at Level 3
     level3Clicked = true;
    accept();
}

QPushButton* LevelSelectionDialog::createQuestionMarkButton(const QString& tooltipText) {
    QPushButton *questionMarkButton = new QPushButton(this);
    questionMarkButton->setFixedSize(20, 20);
    questionMarkButton->setIcon(QIcon(":/images/questionMark.png"));
    questionMarkButton->setIconSize(QSize(20, 20));
    questionMarkButton->setFlat(true);
    questionMarkButton->setToolTip(tooltipText);

    return questionMarkButton;
}
