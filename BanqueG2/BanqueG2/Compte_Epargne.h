#pragma once
#include "Compte.h"
namespace Bank {
	class Compte_Epargne : public virtual Compte
	{

	public: 
		Compte_Epargne(Client* prop, Devise* solde,double tauxIntert);
		void calcul_interet(); 
		bool retirerArgent(Devise* montant) override;

	private: 
		 double tauxIntret; 


	};

};