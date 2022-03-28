#pragma once
#include"Compte_Epargne.h"
#include"payant.h"
using namespace Bank;

class Compte_Epargne_Payant : public Compte_Epargne, public Compte_Payant
{
public:
	Compte_Epargne_Payant();
	Compte_Epargne_Payant(Client* prop, Devise* solde, double tauxIntert,double taux);
	bool retirerArgent(Devise* montant) override;

};