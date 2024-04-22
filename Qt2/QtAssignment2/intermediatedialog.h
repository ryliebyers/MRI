#ifndef INTERMEDIATEDIALOG_H
#define INTERMEDIATEDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class IntermediateDialog : public QDialog
{
    Q_OBJECT

public:
    IntermediateDialog(QWidget *parent = nullptr);

signals:
    void collectingDropletsClicked();

private slots:
    void onCollectingDropletsClicked();
};

#endif // INTERMEDIATEDIALOG_H
