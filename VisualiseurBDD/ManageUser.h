#ifndef MANAGEUSER_H
#define MANAGEUSER_H

#include <QWidget>

//** Espace de nommage pour la classe ManageUser **//
namespace Ui {
class ManageUser;
}

//** Classe ManageUser héritant de QWidget représentant la fenêtre de gestion d'un utilisateur **//
class ManageUser : public QWidget
{
    //** Macro permettant de déclarer les slots et les signaux **//
    Q_OBJECT

public:
    //** Constructeur de la classe ManageUser **//
    explicit ManageUser(QWidget *parent = nullptr);
    //** Destructeur de la classe ManageUser **//
    ~ManageUser();
    //** Méthode permettant d'initialiser la page **//
    void load();

private:
    //** Interface graphique de la fenêtre de gestion d'un utilisateur **//
    Ui::ManageUser *ui;

private slots:
    //** Slot appelé lors du clic sur le bouton sélectionner un profil **//
    void on_selectionProfilPushButton_clicked();
    //** Slot appelé lors du clic sur le bouton se déconnecter **//
    void on_seDeconnecterPushButton_clicked();
    //** Slot appelé lors du clic sur le bouton créer un utilisateur
    void on_creerUtilisateurPushButton_clicked();

signals:
    //** Signal émis lors du clic sur le bouton sélectionner un profil **//
    void selectProfileButtonClicked();
    //** Signal émis lors du clic sur le bouton se déconnecter **//
    void disconnectButtonClicked();
    //** Signal émis lors du clic sur le bouton créer un utilisateur **//
    void createUserButtonClicked();
};

#endif // MANAGEUSER_H
