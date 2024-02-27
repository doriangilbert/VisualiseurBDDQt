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
};

#endif // CREATEPROFILE_H
