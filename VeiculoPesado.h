#ifndef VEICULOPESADO_H_
#define VEICULOPESADO_H_

#include <iostream>
#include "Veiculo.h"
using std::cout;
using std::endl;

class VeiculoPesado : public Veiculo
{
public:
	VeiculoPesado(string marca, string matricula, unsigned int ano_fabrico, unsigned int ultima_inspecao = 0);
	int getTipoVeiculo() const;
	void setProximaInspecao(unsigned int proxima_inspecao);
};
#endif