#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

std::vector<std::vector<std::string>> lerCSV(const std::string& arquivo) {
    std::vector<std::vector<std::string>> dados;

    std::ifstream arquivoCSV(arquivo);
    if (!arquivoCSV.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << arquivo << std::endl;
        return dados;
    }

    std::string linha;
    while (std::getline(arquivoCSV, linha)) {
        std::vector<std::string> linhaDados;
        std::stringstream linhaStream(linha);
        std::string item;

        while (std::getline(linhaStream, item, ',')) {
            linhaDados.push_back(item);
        }

        dados.push_back(linhaDados);
    }
    arquivoCSV.close();
    return dados;
}

int main() {
    std::string arquivo = R"(C:\Users\mateu\CLionProjects\untitled\dados.csv)"; // Nome do arquivo CSV a ser lido

    std::vector<std::vector<std::string>> dados = lerCSV(arquivo);

    for (const auto& linha : dados) {
        for (const auto& item : linha) {
            std::cout << item << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}
