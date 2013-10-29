#ifndef VEICULO_H_
#define VEICULO_H_

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;


class Veiculo
{
protected:
	string matricula;
	unsigned int ano_fabrico;
	string marca;
	unsigned int ultima_inspecao;
	unsigned int proxima_inspecao;


public:
	Veiculo(string marca, string matricula, unsigned int ano_fabrico, unsigned int ultima_inspecao = 0);
	string getMatricula() const;
	unsigned int getAnoFabrico() const;
	string getMarca() const;
	unsigned int getUltimaInspecao() const;
	virtual unsigned int getProximaInspecao() const;
	bool setMatricula(string matricula);
	virtual void setProximaInspecao();
	void setUltimaInspecao(unsigned int ultima_inspecao);
	virtual int getTipoVeiculo() const;
	~Veiculo();
};

#endif