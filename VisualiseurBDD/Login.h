#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

//** Espace de nommage pour la classe Login **//
namespace Ui {
class Login;
}

//** Classe Login héritant de QWidget représentant la fenêtre de connexion **//
class Login : public QWidget
{
    //** Macro permettant de déclarer les slots et les signaux **//
    Q_OBJECT

public:
    //** Constructeur de la classe Login **//
    explicit Login(QWidget *parent = nullptr);
    //** Destructeur de la classe Login **//
    ~Login();

private:
    //** Interface graphique de la fenêtre de connexion **//
    Ui::Login *ui;

private slots:
    //** Slot appelé lors du clic sur le bouton se connecter **//
    void on_seConnecterPushButton_clicked();

signals:
    //** Signal émis lors du clic sur le bouton se connecter **//
    void loginButtonClicked();
};

#endif // LOGIN_H
