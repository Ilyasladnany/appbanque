#pragma once
#include"Client.h"
#include<vector>
#include"Opertaion.h"
class Devise; //pre-declaration **

namespace Bank {
	class Compte
	{
	public: 
		Compte() ; // sans parametres
		Compte( Client* prop, Devise* solde);//avec parameteres
	virtual	bool retirerArgent(Devise *montant);
	virtual void deposerArgent(Devise* montant);
		void consulterSolde() const;
		
		bool transfererArgent(Compte &c, Devise* montant);//?
		void afficher() const;
		~Compte();
	private: 
		static int cpt;
		int numCompte;
		Client* Prop;
		vector <Operation*> historique;
	protected:	Devise* solde;
	};

};