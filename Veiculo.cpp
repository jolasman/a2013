#include "Veiculo.h"
#include "StringUtils.h"


Veiculo::Veiculo(string marca, string matricula, unsigned int ano_fabrico, unsigned int ultima_inspecao):
	marca(marca), matricula(matricula), ano_fabrico(ano_fabrico), ultima_inspecao(ultima_inspecao)
{

}


string Veiculo::getMatricula() const
{
	return matricula;
}


string Veiculo::getMarca() const
{
	return marca;
}


unsigned int Veiculo::getProximaInspecao() const
{
	return ultima_inspecao + 4;
}


unsigned int Veiculo::getUltimaInspecao() const
{
	return ultima_inspecao;
}


unsigned int Veiculo::getAnoFabrico() const
{
	return ano_fabrico;
}


bool Veiculo::setMatricula(string matricula)
{
	StringUtils str;

	if(str.check_matricula(matricula))
	{
		this -> matricula = matricula;
		return true;
	}

	str.print_error_message("[*] A matricula nao esta num formato valido!\n");
	return false;
}


void Veiculo::setProximaInspecao()
{
	unsigned int i = getUltimaInspecao();
	this -> proxima_inspecao = i + 4;
}


void Veiculo::setUltimaInspecao(unsigned int ultima_inspecao)
{
	this -> ultima_inspecao = ultima_inspecao;
}


int Veiculo::getTipoVeiculo() const 
{
	return 0;
}