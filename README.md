# 🎲 Dominó em C++

> Projeto acadêmico desenvolvido na **Universidade de Brasília (UnB)** para praticar C++ por meio da construção de um jogo de dominó funcional.

![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=cplusplus&logoColor=white)
![Build](https://img.shields.io/github/actions/workflow/status/lucascosta001/domino/build.yml?branch=main&label=build)
![License](https://img.shields.io/github/license/lucascosta001/domino)

## 🎯 Objetivo

Construir um jogo de dominó para quatro participantes — um jogador e três computadores — aplicando conceitos de lógica, estruturas de dados, aleatoriedade e regras de jogo.

O projeto está sendo usado também como base para evoluir dos fundamentos de C++ para **Programação Orientada a Objetos**.

## 🛠️ Tecnologias

- C++17
- STL
- Git e GitHub
- GitHub Actions

## 📚 Conceitos praticados

- `struct` e organização de dados
- `vector`
- Funções
- Laços e condicionais
- Embaralhamento aleatório
- Manipulação de coleções
- Validação de jogadas
- Controle de turnos
- Modelagem de regras de um jogo
- Primeiros passos em POO

## 🎮 Funcionalidades atuais

- [x] Geração do conjunto de peças de 0|0 a 6|6
- [x] Embaralhamento
- [x] Distribuição para 4 participantes
- [x] Identificação da peça 6|6
- [x] Jogada do jogador
- [x] Jogadas automáticas dos computadores
- [x] Validação básica das jogadas
- [x] Controle de turnos
- [x] Condição de vitória
- [x] Opção para passar a vez
- [x] Opção para sair da partida

## ▶️ Como executar

### Linux / macOS

```bash
g++ -std=c++17 -Wall -Wextra -pedantic domino.cpp -o domino
./domino
```

### Windows (MinGW)

```bash
g++ -std=c++17 -Wall -Wextra -pedantic domino.cpp -o domino.exe
./domino.exe
```

> O projeto possui uma verificação automática de compilação com GitHub Actions.

## 🗺️ Próximos passos

- [ ] Melhorar a lógica dos computadores
- [ ] Implementar compra de peças quando não houver jogada
- [ ] Detectar empate/bloqueio da partida
- [ ] Melhorar a interface do terminal
- [ ] Separar melhor as responsabilidades do código
- [ ] Evoluir a implementação para classes de POO
- [ ] Criar testes para as principais regras

## 🎓 Contexto acadêmico

Projeto desenvolvido como parte da evolução prática nos estudos de programação e C++.

---

**Autor:** Lucas Alan Costa Novais  
**GitHub:** [@lucascosta001](https://github.com/lucascosta001)
