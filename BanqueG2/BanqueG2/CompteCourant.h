#pragma once
#include"Compte.h"
namespace Bank {
	class CompteCourant : public Compte
	{

	public: 
		CompteCourant(Client* prop, Devise*solde,Devise* decouvert); 
		bool retirerArgent(Devise* montant) override;
	private:
		Devise* decouvert; 
	};

};