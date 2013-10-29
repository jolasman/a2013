#ifndef FILEUTILS_H_
#define FILEUTILS_H_

#include "StringUtils.h"
#include "Veiculo.h"
#include "VeiculoPesado.h"
#include "Motociclo.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;
using std::ofstream;
using std::ifstream;
using std::vector;


extern "C" {
	#include <io.h>
	#include <sys/stat.h>
}



class FileUtils
{
private:
	StringUtils strutils;

public:
	FileUtils();
	bool ficheiro_existe(const char *nomeficheiro);
	bool criar_ficheiro(const char *nomeficheiro);
	void mostrar_erro_ficheiro(const char *nomeficheiro);
	Veiculo* veiculo_linha(string line);
	vector<Veiculo *> get_todos_veiculos_ficheiro(const char *nomeficheiro);
};

#endif