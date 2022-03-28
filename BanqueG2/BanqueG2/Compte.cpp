#include "Compte.h"
#include <iostream>
#include <cstring>   
#include"Devise.h"
using namespace std;
using  namespace Bank;

int Compte::cpt = 0;

Bank::Compte::Compte()
{
    cpt++;
    this->numCompte =cpt ;
    this->solde =0;
    this->Prop = 0;
    this->historique = vector<Operation*>();
}


Bank::Compte::Compte(Client* prop, Devise* solde)
{
    cpt++;
    this->numCompte = cpt;
    this->solde = solde; 
    this->Prop = prop;
    this->historique = vector<Operation*>();
  
}

bool Bank::Compte::retirerArgent(Devise* montant )
{
    if (*(this->solde)>=(*montant)) {
       
        *(this->solde) =(this->solde)->operator-(*montant) ;
     
        Operation* Op = new Operation("-", montant);
        this->historique.push_back(Op);
        return true;
    }

    else
    return false;
}

void Bank::Compte::deposerArgent(Devise* montant)
{
   *(this->solde) = this->solde->operator+(*montant);
   Operation* Op = new Operation("+", montant);
   this->historique.push_back(Op);
   
}

void Bank::Compte::consulterSolde()const
{
    cout << "le num est : " << this->numCompte<< endl;
   // cout << "le solde est : " << this->solde->afficher() << endl;
    this->solde->afficher();
}
bool Bank::Compte::transfererArgent(Compte &c, Devise* montant)
{
    if(this->retirerArgent(montant) == true)
    {
        c.deposerArgent(montant);
        return true;
    }
    else
    return false;
}

void Bank::Compte::afficher() const
{
    for (int i = 0; i < this->historique.size(); i++) {
        this->historique[i]->afficher();
    }
}

Bank::Compte::~Compte()
{ 
    cout << "destructeur";
    for (int i = 0; i < this->historique.size(); i++) {
        delete this->historique[i];
        this->historique[i] = 0;
    }
    this->historique.clear();












    

}
