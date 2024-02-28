#ifndef CREATEPROFILE_H
#define CREATEPROFILE_H

#include <QWidget>

//** Espace de nommage pour la classe CreateProfile **//
namespace Ui {
class CreateProfile;
}

//** Classe CreateProfile héritant de QWidget représentant la fenêtre de création d'un profil **//
class CreateProfile : public QWidget
{
    //** Macro permettant de déclarer les slots et les signaux **//
    Q_OBJECT

public:
    //** Constructeur de la classe CreateProfile **//
    explicit CreateProfile(QWidget *parent = nullptr);
    //** Destructeur de la classe CreateProfile **//
    ~CreateProfile();

private:
    //** Interface graphique de la fenêtre de création d'un profil **//
    Ui::CreateProfile *ui;

private slots:
    //** Slot appelé lors du clic sur le bouton valider **//
    void on_validerPushButton_clicked();

signals:
    //** Signal émis lors du clic sur le bouton valider **//
    void validateButtonClicked();
};

#endif // CREATEPROFILE_H
