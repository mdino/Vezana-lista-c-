# Vezana-lista-c-
1. Unos, 2. Ispis, 3. Brisanje vezanih lista
//
//  main.cpp
//  Vjezba2
//
//  Created by Dino Musliu on 17/12/2015.
//  Copyright © 2015 Dino Musliu. All rights reserved.
//

#include <iostream>

using namespace std;

struct sknjiga{
    int maticni;
    char prezime[20];
    char ime[20];
    int godina_upisa;
    int vrijeme_unosa;
    sknjiga*sljedeci;
};

sknjiga*glava;



void unos(sknjiga*glava){
    
    sknjiga*novi, *zadnji;
    zadnji=glava;
    while(zadnji->sljedeci) zadnji=zadnji->sljedeci;
    
    novi=new sknjiga;
    zadnji->sljedeci=novi;
    novi->sljedeci=NULL;
    
    cout<<"Maticni: ";
    cin>>novi->maticni;
    cout<<"Prezime: ";
    cin>>novi->prezime;
    cout<<"Ime: ";
    cin>>novi->ime;
}

void ispis(sknjiga*glava){
    
    sknjiga*tekuci = glava->sljedeci; //tekuci postaje sljedeci element
    
    while(tekuci!=NULL){
        cout<<"Maticni: "<<tekuci->maticni<<endl;
        cout<<"Prezime: "<<tekuci->prezime<<endl;
        cout<<"Ime: "<<tekuci->ime<<endl;
    
        tekuci = tekuci->sljedeci; // kretanje kroz listu
    }
    
}

void brisi(sknjiga*glava, int maticni){

    // pocetne vrijednosti pokazivaca
    sknjiga *brisi = glava -> sljedeci;
    sknjiga*prethodni = glava;
   
    
    while (brisi){
        if (brisi->maticni==maticni){
            prethodni -> sljedeci = brisi -> sljedeci;
            delete brisi; // delokacija elementa liste
            break; // izlaz iz petlje
        };
        
        prethodni = brisi;
        brisi = brisi->sljedeci;
    };
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    int izbor;
    int maticni;
    
    do{
   
        cout<<"0. Alokacija glave vezane liste"<<endl;
        cout<<"1. Unos novog elementa vezane liste studenta"<<endl;
        cout<<"2. Ispis sadraja cijele vezane liste"<<endl;
        cout<<"3. Brisanje elementa liste"<<endl;
        cout<<"9. Izlaz iz programa"<<endl;
        cout<<"Izbor?: ";
        cin>>izbor;
        
        switch(izbor)
        {
            case 0:
                glava=new sknjiga; //alociranje glave
                glava->sljedeci=NULL; //kraj liste
                cout<<"Alocirali ste glavu liste"<<endl;

                break;
            case 1:
                unos(glava);
                
                break;
            case 2:
                ispis(glava);
                break;
            case 3:
                cout<<"Unesi maticni: "<<endl;
                cin>>maticni;
                brisi(glava,maticni);
                break;
        }
        
    }while (izbor!=9);
    
    
    return 0;
}


