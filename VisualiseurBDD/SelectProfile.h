#ifndef SELECTPROFILE_H
#define SELECTPROFILE_H

#include <QWidget>

//** Espace de nommage pour la classe SelectProfile **//
namespace Ui {
class SelectProfile;
}

//** Classe SelectProfile héritant de QWidget représentant la fenêtre de sélection d'un profil **//
class SelectProfile : public QWidget
{
    //** Macro permettant de déclarer les slots et les signaux **//
    Q_OBJECT

public:
    //** Constructeur de la classe SelectProfile **//
    explicit SelectProfile(QWidget *parent = nullptr);
    //** Destructeur de la classe SelectProfile **//
    ~SelectProfile();
    //** Méthode permettant d'initialiser la page **//
    void load();

private:
    //** Interface graphique de la fenêtre de sélection d'un profil **//
    Ui::SelectProfile *ui;

private slots:
    //** Slot appelé lors du clic sur le bouton valider **//
    void on_validerPushButton_clicked();
    //** Slot appelé lors du clic sur le bouton créer un profil **//
    void on_creerProfilPushButton_clicked();

signals:
    //** Signal émis lors du clic sur le bouton valider **//
    void validateButtonClicked();
    //** Signal émis lors du clic sur le bouton créer un profil **//
    void createProfileButtonClicked();
};

#endif // SELECTPROFILE_H
