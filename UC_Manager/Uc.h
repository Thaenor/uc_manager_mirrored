//
//  Uc.h
//  UC_Manager
//
//  Created by Francisco Santos on 16/12/13.
//  Copyright (c) 2013 Grupo B6-5. All rights reserved.
//

#ifndef UC_Manager_Uc_h
#define UC_Manager_Uc_h

class Uc
{
private:
    int _ID;
    string _name;
    
public:
    Uc();                           /* Construtor por Defeito */
    Uc(int ID, string name);        /* Construtor com parametros */
    ~Uc();                          /* Destrutor */
    Uc(const Uc &other);            /* Construtor Copia */
    Uc* clone() const;              /* construtor Clone */
    void print(ostream out) const;
    void write();                   /*write UC name*/
    
    int getID();                    /*Gets & set*/
    void setID(int ID);
    string getName();
    void setID(string name);
    
                                    /*      Operator Overl0ad!    */
    //virtual Uc & operator = (const Uc &l);
	bool operator > ( const Uc &other) const;
	bool operator==(const Uc& other) const;
};

Uc::Uc()                            /* Construtor por Defeito */
{
    _ID = 0;
    _name = "default";
}

Uc::Uc(int ID, string name)         /* Construtor com parametros */
{
    _ID = ID;
    _name = name;
}

Uc::~Uc()         /* Destrutor */
{
}

Uc* Uc::clone()const  /* construtor Clone */
{
    return new Uc(*this);
}


Uc::Uc(const Uc &other){    /* Construtor Copia */
    _ID=other._ID;
    _name=other._name;
}

int Uc::getID(){return _ID;}            /*Gets & set*/
void Uc::setID(int ID){_ID = ID;}
string Uc::getName(){return _name;}
void Uc::setID(string name){_name = name;}

void Uc::print(ostream out) const
{
    out << "Uc ID = " << _ID << " name: " << _name << ". ";
}

void Uc::write()
{
    cout << "Curicular Unit name: " << _name;
}

/*******************************************************************************************/
/*      Operator Overl0ad!    */

/* Operator == overload - Comparison */
bool Uc::operator==(const Uc& other) const
{
	if (_ID == other._ID)
		return true;
	else
		return false;
}

/*
Uc & Uc::operator = (const Uc &other){
	if(&other!=this){
		_ID=other._ID;
	}
	return *this;
}*/

/* Operator > overload - greater than */
bool Uc::operator > ( const Uc &other) const{
	return (_ID > other._ID);
}


/****************************************...************************************************/

/*  Overl0ad print operator - NORMAL  */
/*ostream& operator<<(ostream& out, const Uc* uc){
    uc->print(out);
    return out;
}*/

#endif
