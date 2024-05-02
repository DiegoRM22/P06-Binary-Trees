#include <iostream>
#include <string>

#include "AB/AB.h"
#include "AB/ABE/ABE.h"
#include "AB/ABB/ABB.h"
#include "nodeB/nodeB.h"
#include "NIF/NIF.h"
#include "RPG-character/RPG-character.h"

void parseCommandLine(int argc, char* argv[], std::string& tree_type, std::string& init_type, int& num_elements, std::string& file_name) {
  if (argc < 5) {
    std::cerr << "Uso: " << argv[0] << " -ab <abe|abb> -init <manual|random [s]|file [s] [f]>" << std::endl;
    exit(1);
  }

  for (int i = 1; i < argc; ++i) {
    std::string arg(argv[i]);

    if (arg == "-ab") {
      if (i + 1 < argc) {
        tree_type = argv[i + 1];
        if (tree_type != "abe" && tree_type != "abb") {
          std::cerr << "Tipo de árbol no válido." << std::endl;
          exit(1);
        }
      } else {
        std::cerr << "Falta el tipo de árbol después de -ab." << std::endl;
        exit(1);
      }
    } else if (arg == "-init") {
      if (i + 1 < argc) {
        init_type = argv[i + 1];
        if (init_type != "manual" && init_type != "random" && init_type != "file") {
          std::cerr << "Tipo de inicialización no válido." << std::endl;
          exit(1);
        }

        if (init_type == "random" || init_type == "file") {
          if (i + 2 < argc) {
            num_elements = std::stoi(argv[i + 2]);
          } else {
            std::cerr << "Falta el número de elementos después de " << init_type << "." << std::endl;
            exit(1);
          }

          if (init_type == "file") {
            if (i + 3 < argc) {
              file_name = argv[i + 3];
            } else {
              std::cerr << "Falta el nombre del archivo después de file." << std::endl;
              exit(1);
            }
          }
        }
      } else {
        std::cerr << "Falta el tipo de inicialización después de -init." << std::endl;
        exit(1);
      }
    }
  }

  if (tree_type.empty() || init_type.empty()) {
    std::cerr << "Debe especificar el tipo de árbol y el tipo de inicialización." << std::endl;
    exit(1);
  }
}

void InitializesManual(AB<NIF>& ab) {
  std::string nif;
  std::cout << "Introduce un NIF (0 para terminar): ";
  std::cin >> nif;
  while (nif != "0") {
    NIF n(nif);
    ab.Insert(n);
    std::cout << "Introduce un NIF (0 para terminar): ";
    std::cin >> nif;
  }
}

void InitializesRandom(AB<NIF>& ab, int num_elements) {
  for (int i = 0; i < num_elements; ++i) {
    std::string nif_number = std::to_string(rand() % 10000000);
    char letter = 'A' + rand() % 26; // Genera una letra aleatoria entre A y Z
    nif_number.push_back(letter); // Añade la letra al final del número de NIF

    NIF n(nif_number);

    ab.Insert(n);
  }
}

void InitializesRandomCharacters(AB<RPGCharacter>& ab, int num_elements) {
  for (int i = 0; i < num_elements; ++i) {
    int strength = rand() % 100;
    int mind = rand() % 100;
    int stamina = rand() % 100;
    int skill = rand() % 100;
    int intelligence = rand() % 100;
    int faith = rand() % 100;
    int arcane = rand() % 100;

    RPGCharacter rpg(strength, mind, stamina, skill, intelligence, faith, arcane);

    ab.Insert(rpg);
  }
}

#include <fstream>
#include <sstream>

void ReadNIFsFromFile(const std::string& filename, AB<NIF>& ab) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "No se pudo abrir el archivo: " << filename << std::endl;
    exit(1);
  }

  std::string line;
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::string nif_number;
    if (!(iss >> nif_number)) {
      std::cerr << "Error al leer el número de NIF desde el archivo." << std::endl;
      continue;
    }
    NIF nif(nif_number);
    ab.Insert(nif);
  }
}



int main(int argc, char* argv[]) {
  std::string tree_type;
  std::string init_type;
  int num_elements = 0;
  std::string file_name;

  ABB<RPGCharacter> abb;

  InitializesRandomCharacters(abb, 10);

  std::cout << abb << std::endl;


  // parseCommandLine(argc, argv, tree_type, init_type, num_elements, file_name);

  // // Hacer algo con las opciones extraídas
  // std::cout << "Tipo de árbol: " << tree_type << std::endl;
  // std::cout << "Tipo de inicialización: " << init_type << std::endl;
  // std::cout << "Número de elementos: " << num_elements << std::endl;
  // std::cout << "Nombre del archivo: " << file_name << std::endl;

  // if (tree_type == "abe") {
  //   ABE<NIF> abe;
  //   if (init_type == "manual") {
  //     InitializesManual(abe);
  //   } else if (init_type == "random") {
  //     InitializesRandom(abe, num_elements);
  //   } else if (init_type == "file") {
  //     ReadNIFsFromFile(file_name, abe);
  //   }
  //   std::cout << abe << std::endl;

  // } else {
  //   ABB<NIF> abb;
  //   if (init_type == "manual") {
  //     InitializesManual(abb);
  //   } else if (init_type == "random") {
  //     InitializesRandom(abb, num_elements);
  //   } else if (init_type == "file") {
  //     ReadNIFsFromFile(file_name, abb);
  //   }
  //   std::cout << abb << std::endl;
  // }

  return 0;
}
