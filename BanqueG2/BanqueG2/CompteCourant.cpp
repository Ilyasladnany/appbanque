#include "CompteCourant.h"

Bank::CompteCourant::CompteCourant(Client* prop, 
	Devise* solde, Devise* decouvert) : Compte(prop,solde)
{
	this->decouvert = decouvert; 

}

bool Bank::CompteCourant::retirerArgent(Devise* montant)
{
	if (this->solde->operator-(*montant) >= *(this->decouvert)) {

		return this->Compte::retirerArgent(montant);
	}

	return false;
}
