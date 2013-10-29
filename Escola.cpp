#include "Escola.h"


Escola::Escola()
{

}


string Escola::escolherMarca()
{
	string marca;

	cout << "[*] Seleccione a marca do veiculo: " << endl;
	getline(cin, marca);	

	if(marca.size() == 0)
	{
		strutils.print_error_message("[!] O campo \"marca\" nao pode estar vazio!");
		escolherMarca();
	}

	for(size_t i = 0; i < marca.size(); i++)
	{
		if(!isalpha(marca[i]))
		{
			strutils.print_error_message("[!] O campo \"marca\" nao pode conter numeros!");
			escolherMarca();
		}
	}

	//Passed all the requesites?
	return marca;
}


string Escola::escolherMatricula()
{
	string matricula;

	cout << "[*] Seleccione a matricula do veiculo: " << endl;
	getline(cin, matricula);

	while(!strutils.check_matricula(matricula) || matricula_existe(matricula))
	{
		strutils.print_error_message("[!] Matricula invalida! Tentar novamente...");
		getline(cin, matricula);
	}

	return matricula;
}


bool Escola::matricula_existe(string matricula)
{
	for(size_t i = 0; i < veiculos.size(); i++)
		if(veiculos[i] -> getMatricula() == matricula)
			return true;

	return false;
}


bool Escola::adicionarVeiculo()
{
	string s;
	string marca;
	string matricula;
	unsigned int ano_fabrico;
	unsigned int ultima_inspecao;
	cout << "[*] Que veiculo quer adicionar? (L)igeiro, (P)esado, (M)otociclo" << endl;
	getline(cin, s);

	while(s.size() != 1 || (s != "L" && s != "P" && s != "M" && s != "l" && s != "p" && s != "m"))
	{
		strutils.print_error_message("[!] Veiculo invalido! Escolher novamente...");
		getline(cin, s);
	}

	marca = escolherMarca();

	matricula = escolherMatricula();

	cout << "[*] Seleccione o ano de fabrico do veiculo: " << endl;
	cin >> ano_fabrico;

	while(ano_fabrico > 2013)
	{
		cin.clear();
		strutils.print_error_message("[!] Ano de fabrico do veiculo errado. Escolha novamente...");
		cin >> ano_fabrico;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}

	cout << "[*] Se o veiculo ja foi inspeccionado seleccione a data, caso contrário escreva 0" << endl;
	cin >> ultima_inspecao;
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	if(ultima_inspecao > 2013)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		strutils.print_error_message("[!] Ano da ultima inspecao errado. Seleccione novamente...");
		cin >> ultima_inspecao;
	}




	if(s == "L" || s == "l")
	{
		Veiculo *v = new Veiculo(marca, matricula, ano_fabrico, ultima_inspecao);
		veiculos.push_back(v);
	} else if(s == "P" || s == "p") {
		VeiculoPesado *p = new VeiculoPesado(marca, matricula, ano_fabrico, ultima_inspecao);
		veiculos.push_back(p);
	} else if(s == "M" || s == "m") {
		Motociclo *m = new Motociclo(marca, matricula, ano_fabrico, ultima_inspecao);
		veiculos.push_back(m);
	}

	return true;
}


vector<Veiculo *> Escola::getTodosVeiculos()
{
	return veiculos;
}