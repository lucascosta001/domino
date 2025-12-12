// Lucas Alan Costa Novais 252013404
// Trabalho CPE 12/12/25

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>
#include <stdlib.h>
using namespace std;

struct Peca {
    int a, b;
};

void mostrarPeca(const Peca &p) {
    cout << "[" << p.a << "|" << p.b << "]"; // mostra na tela a peca de domino
}

void mostrarVetor(const vector<Peca> &v) {
    for (auto &p : v) {
        mostrarPeca(p);
        cout << " ";
    }
    cout << "\n";
}

vector<Peca> criarMao() { // Cria pecas e manda para 
    vector<Peca> b;
    for (int i = 0; i <= 6; i++)
        for (int j = i; j <= 6; j++)
            b.push_back({i, j});
    return b;
}

void misturar(vector<Peca> &b) {
    shuffle(b.begin(), b.end(),  default_random_engine(time(0)));
    // pega todas as peças no vetor, usa o tempo atual para criar uma sequência aleatória e embaralha as peças como um baralho
}

bool podeJogar(const Peca &p, int ladoEsq, int ladoDir) {
    return (p.a == ladoEsq || p.b == ladoEsq || p.a == ladoDir || p.b == ladoDir); // testar se a peca pode ser jogada
}

Peca inverter(Peca p) {
    return {p.b, p.a}; // trocar lado da peca
}

int main() {
    system("cls");
    bool jogando = true;
    
    while (jogando) {
        cout << "\n========== DOMINÓ EM C++ ==========\n";
        cout << "1 - Jogar\n";
        cout << "2 - Sair\n";
        cout << "Escolha: ";
        int op;
        cin >> op;

        if (op == 2) break;
        if (op != 1) continue;

        // --- CRIAR BARALHO ---
        vector<Peca> baralho = criarMao();
        misturar(baralho);

        // --- DISTRIBUIR ---
        // --- 4 JOGADORES: Player + PC1 + PC2 + PC3 ---
        vector<Peca> jogador, pc1, pc2, pc3, mesa;

        // Distribui 7 peças para cada jogador
        for (int i = 0; i < 7; i++) {
            jogador.push_back(baralho.back()); baralho.pop_back();
            pc1.push_back(baralho.back()); baralho.pop_back();
            pc2.push_back(baralho.back()); baralho.pop_back();
            pc3.push_back(baralho.back()); baralho.pop_back();
        }

        // --- COMEÇAR JOGO ---
        // Turnos: 0 = player, 1 = pc1, 2 = pc2, 3 = pc3
        int turnoAtual = 0;

        // Verificar quem tem a peça 6|6 para começar
        int jogadorComeca = -1; // -1 = ninguém, 0 = player, 1 = pc1, 2 = pc2, 3 = pc3
        int idxComeca = -1;

        // Verificar no jogador
        for (int i = 0; i < (int)jogador.size(); i++) {
            if (jogador[i].a == 6 && jogador[i].b == 6) {
                jogadorComeca = 0;
                idxComeca = i;
                break;
            }
        }

        // Se não, verificar nos PCs
        if (jogadorComeca == -1) { // verifica qual pc esta com a buxa
            vector<vector<Peca>*> pcs = {&pc1, &pc2, &pc3};
            for (int p = 0; p < 3; p++) {
                for (int i = 0; i < (int)pcs[p]->size(); i++) {
                    if ((*pcs[p])[i].a == 6 && (*pcs[p])[i].b == 6) {
                        jogadorComeca = p + 1;
                        idxComeca = i;
                        break;
                    }
                }
                if (jogadorComeca != -1) break;
            }
        }

        if (jogadorComeca == 0) {
            mesa.push_back(jogador[idxComeca]); // coloca na mesa
            jogador.erase(jogador.begin() + idxComeca); // tira da mão para não duplicar
            cout << "\nVocê tem a peça 6|6! Você começa, automaticamente.\n";
            turnoAtual = (0 + 1) % 4; // Pula para PC1; foi usado desta maneira para não ter dar valores
        } else if (jogadorComeca >= 1 && jogadorComeca <= 3) {
            vector<vector<Peca>*> pcs = {&pc1, &pc2, &pc3};
            mesa.push_back((*pcs[jogadorComeca - 1])[idxComeca]);
            pcs[jogadorComeca - 1]->erase(pcs[jogadorComeca - 1]->begin() + idxComeca);
            cout << "\nO PC" << jogadorComeca << " tem a peça 6|6! O PC" << jogadorComeca << " começa, automaticamente.\n";
            turnoAtual = (jogadorComeca + 1) % 4; // Pula para o próximo
        } else {
            // Caso improvável
            mesa.push_back(baralho.back());
            baralho.pop_back();
            cout << "\nNinguém tem 6|6. Peça aleatória na mesa.\n";
        }

        cout << "Primeira peça na mesa: ";
        mostrarPeca(mesa[0]);
        cout << "\n";

        while (true) {
            // system("cls");
            int ladoEsq = mesa.front().a;
            int ladoDir = mesa.back().b;

            cout << "\n==========================================================================================\n";
            cout << "\nPeças restantes - Jogador: " << jogador.size() 
                 << " | PC1: " << pc1.size() 
                 << " | PC2: " << pc2.size() 
                 << " | PC3: " << pc3.size() << "\n\n";
            cout << "MESA: ";
            mostrarVetor(mesa);
            cout << "\n\n==========================================================================================\n";

            if (turnoAtual == 0) { // Vez do jogador
                cout << "\nSua vez!\n";
                cout << "Suas peças:\n";
                for (int i = 0; i < (int)jogador.size(); i++) {
                    cout << i + 1 << ": ";
                    mostrarPeca(jogador[i]);
                    cout << "  ";
                }
                cout << "\nEscolha o índice da peça para jogar (9 para passar e 8 para sair): ";
                int idx;
                cin >> idx;

                if (idx == 9) { // passar a vez
                    cout << "Você passou.\n";
                    turnoAtual = (turnoAtual + 1) % 4; // faz o turno e retorna a 0 quanto chegar a 3
                    continue;
                }
                if (idx == 8){
                    cout << "\nAté a próxima" << endl;
                    return 0;
                } 

                idx--; // Ajustar para índice baseado em 0

                if (idx < 0 || idx >= (int)jogador.size()) {
                    cout << "Índice inválido!\n";
                    continue;
                }

                Peca p = jogador[idx];
                if (!podeJogar(p, ladoEsq, ladoDir)) {
                    cout << "Essa peça não pode ser jogada!\n";
                    continue;
                }

                // Jogar no lado esquerdo
                if (p.b == ladoEsq) {
                    mesa.insert(mesa.begin(), p);
                }
                else if (p.a == ladoEsq) {
                    mesa.insert(mesa.begin(), inverter(p));
                }
                // Jogar no lado direito
                else if (p.a == ladoDir) {
                    mesa.push_back(p);
                }
                else if (p.b == ladoDir) {
                    mesa.push_back(inverter(p));
                }

                jogador.erase(jogador.begin() + idx);

                if (jogador.empty()) {
                    cout << "\nVOCÊ GANHOU!!!\n";
                    break;
                }

                turnoAtual = (turnoAtual + 1) % 4;
            }
            else { // Vez dos PCs
                int pcNum = turnoAtual;
                vector<Peca>* pcAtual = (turnoAtual == 1) ? &pc1 : (turnoAtual == 2) ? &pc2 : &pc3; // muda de mão de forma generica
                cout << "\nVez do PC" << pcNum << "...\n";

                bool jogou = false;
                for (int i = 0; i < (int)pcAtual->size(); i++) {
                    Peca p = (*pcAtual)[i];
                    if (podeJogar(p, ladoEsq, ladoDir)) {

                        // esquerda
                        if (p.b == ladoEsq)
                            mesa.insert(mesa.begin(), p);
                        else if (p.a == ladoEsq)
                            mesa.insert(mesa.begin(), inverter(p));
                        // direita
                        else if (p.a == ladoDir)
                            mesa.push_back(p);
                        else if (p.b == ladoDir)
                            mesa.push_back(inverter(p));

                        cout << "PC" << pcNum << " jogou: ";
                        mostrarPeca(p);
                        cout << "\n";

                        pcAtual->erase(pcAtual->begin() + i);
                        jogou = true;
                        break;
                    }
                }

                if (!jogou)
                    cout << "PC" << pcNum << " passou.\n";

                if (pcAtual->empty()) {
                    cout << "\nO PC" << pcNum << " GANHOU!\n";
                    break;
                }
                cout << endl << endl;

                turnoAtual = (turnoAtual + 1) % 4;
            }
        }
    }
    
    return 0;
}
