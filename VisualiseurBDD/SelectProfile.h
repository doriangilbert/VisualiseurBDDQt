#ifndef SELECTPROFILE_H
#define SELECTPROFILE_H

#include <QWidget>

namespace Ui {
class SelectProfile;
}

class SelectProfile : public QWidget
{
    Q_OBJECT

public:
    explicit SelectProfile(QWidget *parent = nullptr);
    ~SelectProfile();

private:
    Ui::SelectProfile *ui;

private slots:
    void on_validerPushButton_clicked();

signals:
    void validateButtonClicked();
};

#endif // SELECTPROFILE_H
