#include "FileUtils.h"

FileUtils::FileUtils()
{

}


bool FileUtils::ficheiro_existe(const char *nomeficheiro)
{
	if((_access(nomeficheiro, 0)) != -1)
		return true;

	return false;
}


bool FileUtils::criar_ficheiro(const char *nomeficheiro)
{
	FILE *file;
	errno_t status;

	status = fopen_s(&file, nomeficheiro, "w");

	if(!status)
	{
		fclose(file);
		return true;
	}

	return false;
}


void FileUtils::mostrar_erro_ficheiro(const char *nomeficheiro)
{
	cerr << "[!] O ficheiro " << nomeficheiro << " contem dados invalidos!" << endl;
	cerr << "[!] Por favor verifique novamente os dados..." << endl;

	exit(EXIT_FAILURE);
}


vector<Veiculo *> FileUtils::get_todos_veiculos_ficheiro(const char *nomeficheiro)
{
	vector<Veiculo *> veiculos;
	ifstream fin;

	if(ficheiro_existe(nomeficheiro))
	{
		try {

			//Open the file
			fin.open(nomeficheiro);


			//Check if the file is opened
			if(fin.is_open())
			{
				//Read all lines till the end of the file(eof)
				while(!fin.eof())
				{
					string line;

					getline(fin, line);

					if(!line.empty())
					{
						Veiculo* v;
						v = veiculo_linha(line);

						if(v != NULL)
						{
							cout << "adicionar novo veiculo" << endl;
							veiculos.push_back(v);
						}
					}
				}
			}

			//Close the stream
			fin.close();
		}catch(ifstream::failure ex) {
			cerr << "[!] Ocorreu um erro durante a leitura do ficheiro " << nomeficheiro << endl;
		}
	}

	return veiculos;
}


Veiculo* FileUtils::veiculo_linha(string line)
{
	unsigned int pos;
	unsigned int lastpos;
	string marca;
	string matricula;
	string ano_fabrico;
	string ultima_inspecao;
	string tipo_veiculo;

	pos = line.find(',');
	
	marca = line.substr(0, pos);
	lastpos = pos;
	pos = line.find(',', pos + 1);
	
	matricula = line.substr(lastpos + 1, pos - lastpos - 1); 
	lastpos = pos;
	pos = line.find(',', pos + 1);
	

	ano_fabrico = line.substr(lastpos + 1, pos - lastpos - 1);
	lastpos = pos;
	pos = line.find(',', pos + 1);
	

	ultima_inspecao = line.substr(lastpos + 1, pos - lastpos - 1);
	lastpos = pos;
	pos = line.find(',', pos + 1);
	

	tipo_veiculo = line.substr(lastpos + 1, line.size() - lastpos - 1);
	if(tipo_veiculo == "0")
		return new Veiculo(marca, matricula, atoi(ano_fabrico.c_str()), atoi(ultima_inspecao.c_str()));
	else if(tipo_veiculo == "1")
		return new VeiculoPesado(marca, matricula, atoi(ano_fabrico.c_str()), atoi(ultima_inspecao.c_str()));
	else if(tipo_veiculo == "2")
		return new Motociclo(marca, matricula, atoi(ano_fabrico.c_str()), atoi(ultima_inspecao.c_str()));

	return NULL;
}