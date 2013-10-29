#include "Motociclo.h"


Motociclo::Motociclo(string marca, string matricula, unsigned int ano_fabrico, unsigned int ultima_inspecao)
	:Veiculo(marca, matricula, ano_fabrico, ultima_inspecao)
{

}


int Motociclo::getTipoVeiculo() const
{
	return 2;
}


void Motociclo::setProximaInspecao()
{
	unsigned int i = getProximaInspecao();

	this -> proxima_inspecao = i + 1;
}


unsigned int Motociclo::getProximaInspecao() const 
{
	return ultima_inspecao + 2;
}