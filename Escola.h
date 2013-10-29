#ifndef ESCOLA_H_
#define ESCOLA_H_

#include <iostream>
#include <vector>
#include "Veiculo.h"
#include "VeiculoPesado.h"
#include "Motociclo.h"
#include "StringUtils.h"
using std::cout;
using std::cin;
using std::endl;
using std::vector;


class Escola
{
private:
	vector<Veiculo *> veiculos;
	StringUtils strutils;

public:
	Escola();
	bool adicionarVeiculo();
	bool matricula_existe(string matricula);
	string escolherMarca();
	string escolherMatricula();
	vector<Veiculo *> getTodosVeiculos();
};

#endif