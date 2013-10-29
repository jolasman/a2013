#include "VeiculoPesado.h"


VeiculoPesado::VeiculoPesado(string marca, string matricula, unsigned int ano_fabrico, unsigned int ultima_inspecao) 
	:Veiculo(marca, matricula, ano_fabrico, ultima_inspecao)
{

}


int VeiculoPesado::getTipoVeiculo() const
{
	return 1;
}


void VeiculoPesado::setProximaInspecao()
{
	unsigned int i = getUltimaInspecao();

	this -> proxima_inspecao = i + 2;
}


unsigned int VeiculoPesado::getProximaInspecao() const
{
	return ultima_inspecao + 1;
}