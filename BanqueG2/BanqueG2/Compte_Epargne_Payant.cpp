#include "Compte_Epargne_Payant.h"

Compte_Epargne_Payant::Compte_Epargne_Payant()
{
}

Compte_Epargne_Payant::Compte_Epargne_Payant(Client* prop, Devise* solde, double tauxIntert, double taux)
	:Compte_Epargne(prop, solde, tauxIntert),Compte_Payant(prop, solde,taux),Compte(prop, solde)
{
}

bool Compte_Epargne_Payant::retirerArgent(Devise* montant)
{
	if (Compte_Epargne::retirerArgent(montant)) {
		return Compte_Payant::retirerArgent(montant);
	}
	else
		return false;
}
