#ifndef CREATEPROFILE_H
#define CREATEPROFILE_H

#include <QWidget>

namespace Ui {
class CreateProfile;
}

class CreateProfile : public QWidget
{
    Q_OBJECT

public:
    explicit CreateProfile(QWidget *parent = nullptr);
    ~CreateProfile();

private:
    Ui::CreateProfile *ui;

private slots:
    void on_validerPushButton_clicked();

signals:
    void validateButtonClicked();
};

#endif // CREATEPROFILE_H
