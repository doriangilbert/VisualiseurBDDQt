#ifndef CREATEUSER_H
#define CREATEUSER_H

#include <QWidget>

//** Espace de nommage pour la classe CreateUser **//
namespace Ui {
class CreateUser;
}

//** Classe CreateUser héritant de QWidget représentant la fenêtre de création d'un utilisateur **//
class CreateUser : public QWidget
{
    //** Macro permettant de déclarer les slots et les signaux **//
    Q_OBJECT

public:
    //** Constructeur de la classe CreateUser **//
    explicit CreateUser(QWidget *parent = nullptr);
    //** Destructeur de la classe CreateUser **//
    ~CreateUser();

private:
    //** Interface graphique de la fenêtre de création d'un utilisateur **//
    Ui::CreateUser *ui;

private slots:
    //** Slot appelé lors du clic sur le bouton valider **//
    void on_validerPushButton_clicked();

signals:
    //** Signal émis lors du clic sur le bouton valider **//
    void validateButtonClicked();
};

#endif // CREATEUSER_H
