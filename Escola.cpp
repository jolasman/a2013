#include "Escola.h"


Escola::Escola()
{

}


string Escola::escolherMarca()
{
	string marca;

	cout << "[*] Seleccione a marca do veiculo: " << endl;
	getline(cin, marca);
	cin.clear();	

	if(marca.size() == 0)
	{
		strutils.print_error_message("[!] O campo \"marca\" nao pode estar vazio!");
		cin.clear();
		escolherMarca();
	}

	for(size_t i = 0; i < marca.size(); i++)
	{
		if(!isalpha(marca[i]))
		{
			strutils.print_error_message("[!] O campo \"marca\" nao pode conter numeros!");
			cin.clear();
			escolherMarca();
		}
	}

	//Passed all the requesites?
	return marca;
}


string Escola::escolherMatricula()
{
	string matricula;

	getline(cin, matricula);
	cin.clear();

	while(!strutils.check_matricula(matricula))
	{
		strutils.print_error_message("[!] Matricula invalida! Tentar novamente...");
		cin.clear();
		getline(cin, matricula);
	}

	return matricula;
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
	cin.clear();

	while(s.size() != 1 && s != "L" || s != "P" || s != "M" || s != "l" || s != "p" || s != "m")
	{
		strutils.print_error_message("[!] Veiculo invalido! Escolher novamente...");
		s = "";
		getline(cin, s);
		cin.clear();
	}

	cout << "[*] Escolha a marca do veiculo: " << endl;
	marca = escolherMarca();

	cout << "[*] Escolha a matricula do veiculo: " << endl;
	matricula = escolherMatricula();

	cout << "[*] Escolha o ano de fabrico do veiculo: " << endl;
	cin >> ano_fabrico;

	while(ano_fabrico > 2013)
	{
		cin.clear();
		strutils.print_error_message("[!] Ano de fabrico do veiculo errado. Escolha novamente...");
		cin >> ano_fabrico;
	}

	cout << "[*] Se o veiculo ja foi inspeccionado seleccione a data, caso contrário escreva 0" << endl;
	cin >> ultima_inspecao;

	if(ultima_inspecao != 0 && ultima_inspecao > 2013)
	{
		cin.clear();
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
}