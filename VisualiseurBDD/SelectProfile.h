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
};

#endif // SELECTPROFILE_H
