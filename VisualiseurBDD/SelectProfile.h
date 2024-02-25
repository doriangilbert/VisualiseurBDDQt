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

private:
    //** Interface graphique de la fenêtre de sélection d'un profil **//
    Ui::SelectProfile *ui;

private slots:
    //** Slot appelé lors du clic sur le bouton valider **//
    void on_validerPushButton_clicked();

signals:
    //** Signal émis lors du clic sur le bouton valider **//
    void validateButtonClicked();
};

#endif // SELECTPROFILE_H
