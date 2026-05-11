#include <iostream>
#include <string>
#include <vector>
using namespace std;
class astronauta{
    public:
        string CPF, nome;
        int idade;
        bool vivo, disponivel;

        astronauta(){
            this->vivo = true;
            this->disponivel = true;
        }
        void morrer(){
            this->vivo = false;
            this->disponivel = false;
        }
        void ficar_indisponivel(){
            this->disponivel = false;
        }
        void ficar_disponivel(){
            this->disponivel = true;
        }
        void cadastrar_CPF(string CPF){
            this->CPF = CPF;
        }
        void cadastrar_nome(string nome){
            this->nome = nome;
        }
        void cadastrar_idade(int idade){
            this->idade = idade;
        }
        void cadastrar_astronauta(string CPF, string nome, int idade){
            this->cadastrar_CPF(CPF);
            this->cadastrar_idade(idade);
            this->cadastrar_nome(nome);
        }
};
class voo{
    public:
        int codigo;
        vector<astronauta> tripulacao;
        string estado;
        voo(){
            this->estado = "planejado";
            this->tripulacao.clear();
        }
        void adicionar_codigo(int codigo){
            this->codigo = codigo;
        }
        void cadastrar_voo(int codigo){
            this->adicionar_codigo(codigo);
        }
        void adicionar_astronauta(astronauta a){
            if(a.vivo){
                this->tripulacao.push_back(a);
            }
        }
        void remover_astronauta(astronauta a){
            for(int i = 0; i < this->tripulacao.size(); i++){
                if(this->tripulacao[i].CPF == a.CPF){
                    this->tripulacao.erase(this->tripulacao.begin() + i);
                    a.ficar_disponivel();
                }
            }
        }
        void lancar_voo(){
            this->estado = "em_curso";
            for(int i = 0; i < this->tripulacao.size(); i++){
                this->tripulacao[i].ficar_indisponivel();
            }
        }
        void finalizar_voo(){
            this->estado = "finalizado_com_sucesso";
                for(int i = 0; i < this->tripulacao.size(); i++){
                this->tripulacao[i].ficar_disponivel();
                }
        }
        void explodir_voo(){
            this->estado = "finalizado_com_explosao";
            for(int i = 0; i < this->tripulacao.size(); i++){
                this->tripulacao[i].morrer();
            }
        }
};
void ajuda(){
    cout << endl;
    cout << "    ";
    cout << "COMANDOS DISPONÍVEIS:" << endl;
    cout << "    ";
    cout << "USE OS COMANDOS OU SEUS REFERENTES NÚMEROS" << endl;
    cout << endl;
    cout << "      ░▒████████████▒        ";
    cout << " 01. CADASTRAR_ASTRONAUTA cpf idade nome" << endl;
    cout << "    ░▒████████   █████▒      ";
    cout << " 02. CADASTRAR_VOO codigo" << endl;
    cout << "  ░▒     █████  ███████▒     ";
    cout << " 03. DEMITIR_ASTRONAUTA cpf" << endl;
    cout << " ░▒████     █████ ████   ▒   ";
    cout << " 04. CANCELAR_VOO codigo" << endl;
    cout << "░▒██         ████████  ██▒   ";
    cout << " 05. ADICIONAR_ASTRONAUTA cpf codigo" << endl;
    cout << "▒████      ████████████   ▒  ";
    cout << " 06. REMOVER_ASTRONAUTA cpf codigo" << endl;
    cout << "▒██████ █████████████     ▒  ";
    cout << " 07. LANCAR_VOO codigo" << endl;
    cout << "░▒█████     ██████████  █▒   ";
    cout << " 08. FINALIZAR_VOO codigo" << endl;
    cout << " ░▒███       ████████    ▒   ";
    cout << " 09. EXPLODIR_VOO codigo" << endl;
    cout << "  ░▒████    ████████    ▒    ";
    cout << " 10. LISTAR_ASTRONAUTAS" << endl;
    cout << "    ░▒███   █████████ ▒      ";
    cout << " 11. LISTAR_VOOS" << endl;
    cout << "       ░▒██ ████████▒        ";
    cout << " 12. LISTAR_MORTOS" << endl;
    cout << "                             ";
    cout << " 13. LISTAR_TRIPULACAO codigo" << endl;
    cout << "                             ";
    cout << " 14. AJUDA" << endl;
    cout << "                             ";
    cout << " 15. FIM" << endl;
    cout << endl;
}
void limpar_buffer(){
    while (cin.peek() != '\n' && cin.peek() != EOF){
        cin.ignore();
    }
}
int main(){
    vector<astronauta> astronautas;
    vector<voo> voos;
    string comando;
    ajuda();
    while (cin >> comando && comando != "FIM" && comando != "15." && comando != "15"){
        if (comando == "CADASTRAR_ASTRONAUTA" || comando == "01." || comando == "01" || comando == "1." || comando == "1"){
            string CPF, nome;
            int idade;
            bool cpf_cadastrado = false;
            cin >> CPF >> idade;
            cin.ignore();
            getline(cin, nome);
            for (int i = 0; i < astronautas.size(); i++){
                if(astronautas[i].CPF == CPF){
                    cpf_cadastrado = true;
                }
            }
            if(!cpf_cadastrado){
                astronauta a;
                a.cadastrar_astronauta(CPF, nome, idade);
                astronautas.push_back(a);
                cout << " -> ";
                cout << "Astronauta " << nome << " cadastrado(a) com sucesso!" << endl;
            }else{
                cout << " -x ";
                cout << "CPF já cadastrado..." << endl;
            }
        }
        else if (comando == "CADASTRAR_VOO" || comando == "02." || comando == "02" || comando == "2." || comando == "2"){
            int codigo;
            cin >> codigo;
            limpar_buffer();
            bool codigo_cadastrado = false;
            for (int i = 0; i < voos.size(); i++){
                if(voos[i].codigo == codigo){
                    codigo_cadastrado = true;
                }
            }
            if(!codigo_cadastrado){
                voo v;
                v.cadastrar_voo(codigo);
                voos.push_back(v);
                cout << " -> ";
                cout << "Voo " << codigo << " cadastrado com sucesso!" << endl;
            }else {
                cout << " -x ";
                cout << "Código já cadastrado..." << endl;
            }
        }
        else if (comando == "DEMITIR_ASTRONAUTA" || comando == "03." || comando == "03" || comando == "3." || comando == "3"){
            string CPF;
            cin >> CPF;
            limpar_buffer();
            bool astronauta_encontrado = false;
            for(int i = 0; i < astronautas.size(); i++){
                if(astronautas[i].CPF == CPF){
                    astronauta_encontrado = true;
                    if(astronautas[i].disponivel){
                        for (int j = 0; j < voos.size(); j++){
                            if (voos[j].estado == "planejado"){
                                voos[j].remover_astronauta(astronautas[i]);
                                    
                            }
                        }
                        astronautas.erase(astronautas.begin() + i);
                        cout << " -> ";
                        cout << "Astronauta de CPF " << CPF << " demitido com sucesso!" << endl;
                    }else {
                        cout << " -x ";
                        cout << "Não é possível demitir um astronauta que está disponível..." << endl;
                    }
                }
            }
            if (!astronauta_encontrado){
                cout << " -x ";
                cout << "Astronauta de CPF " << CPF << " não encontrado." << endl;
            }
        }
        else if (comando == "CANCELAR_VOO" || comando == "04." || comando == "04" || comando == "4." || comando == "4"){
            int codigo;
            cin >> codigo;
            limpar_buffer();
            bool voo_encontrado = false;
            for(int i = 0; i < voos.size(); i++){
                if(voos[i].codigo == codigo){
                    voo_encontrado = true;
                    if (voos[i].estado == "planejado"){
                        voos.erase(voos.begin() + i);
                        cout << " -> ";
                        cout << "Voo " << codigo << " cancelado com sucesso!" << endl;
                    }else {
                        cout << " -x ";
                        cout << "Não é possível cancelar um voo que já decolou..." << endl;
                    }
                }
            }
            if (!voo_encontrado){
                cout << " -x ";
                cout << "Voo " << codigo << " não encontrado." << endl;
            }
        }
        else if (comando == "ADICIONAR_ASTRONAUTA" || comando == "05." || comando == "05" || comando == "5." || comando == "5"){
            string CPF;
            int codigo;
            bool astronauta_encontrado = false;
            bool voo_encontrado = false;
            bool no_voo = false;
            cin >> CPF >> codigo;
            limpar_buffer();
            for(int i = 0; i < astronautas.size(); i++){
                if(astronautas[i].CPF == CPF){
                    astronauta_encontrado = true;
                    for(int j = 0; j < voos.size(); j++){
                        if(voos[j].codigo == codigo){
                            voo_encontrado = true;
                            if (voos[j].estado == "planejado"){
                                    if (astronautas[i].vivo){
                                        for (int k = 0; k < voos[j].tripulacao.size(); k++){
                                            if(voos[j].tripulacao[k].CPF == CPF){
                                                no_voo = true;
                                            }
                                        }
                                        if (!no_voo){
                                            voos[j].adicionar_astronauta(astronautas[i]);
                                            cout << " -> ";
                                            cout << "Astronauta " << astronautas[i].nome << " adicionado ao voo " << codigo << " com sucesso!" << endl;
                                        } else {
                                            cout << " -x ";
                                            cout << "Astronauta já está na tripulação desse voo..." << endl;
                                        }
                                    }else {
                                        cout << " -x ";
                                        cout << "Astronauta morto..." << endl;
                                    }
                            }else {
                                cout << " -x ";
                                cout << "Não é possível adicionar astronauta a um voo que já decolou..." << endl;
                            }
                        }
                    }
                    if (!voo_encontrado){
                        cout << " -x ";
                        cout << "Voo " << codigo << " não encontrado." << endl;
                    }
                }
            }
            if (!astronauta_encontrado){
                cout << " -x ";
                cout << "Astronauta de CPF " << CPF << " não encontrado." << endl;
            }
        }
        else if (comando == "REMOVER_ASTRONAUTA" || comando == "06." || comando == "06" || comando == "6." || comando == "6"){
            string CPF;
            int codigo;
            bool astronauta_encontrado = false;
            bool voo_encontrado = false;
            cin >> CPF >> codigo;
            limpar_buffer();
            for(int j = 0; j < voos.size(); j++){
                if(voos[j].codigo == codigo){
                    voo_encontrado = true;
                    if (voos[j].estado == "planejado"){
                        for (int i = 0; i < voos[j].tripulacao.size(); i++){
                            if (voos[j].tripulacao[i].CPF == CPF){
                                astronauta_encontrado = true;
                                voos[j].remover_astronauta(voos[j].tripulacao[i]);
                                cout << " -> ";
                                cout << "Astronauta " << voos[j].tripulacao[i].nome << " removido do voo " << codigo << " com sucesso!" << endl;
                            }
                        }
                        if (!astronauta_encontrado){
                            cout << " -x ";
                            cout << "Astronauta de CPF " << CPF << " não encontrado no voo " << codigo << "." << endl;
                        }
                    }else {
                        cout << " -x ";
                        cout << "Não é possível remover astronauta de um voo que não está planejado..." << endl;
                    }
                }
            }
            if (!voo_encontrado){
                cout << " -x ";
                cout << "Voo " << codigo << " não encontrado." << endl;
            }
        }
        else if (comando == "LANCAR_VOO" || comando == "07." || comando == "07" || comando == "7." || comando == "7"){
            int codigo;
            cin >> codigo;
            limpar_buffer();
            bool todos_disponiveis = true;
            bool voo_encontrado = false;
            for(int i = 0; i < voos.size(); i++){
                if(voos[i].codigo == codigo){
                    voo_encontrado = true;
                    if (voos[i].estado == "planejado"){
                        for (int j = 0; j < voos[i].tripulacao.size(); j++){
                            for (int k = 0; k < astronautas.size(); k++){
                                if (astronautas[k].CPF == voos[i].tripulacao[j].CPF){
                                    if (!astronautas[k].disponivel){
                                        todos_disponiveis = false;
                                    }
                                }
                            }
                        }
                        if (voos[i].tripulacao.size() > 0){
                            if (todos_disponiveis){
                                voos[i].lancar_voo();
                                for (int j = 0; j < voos[i].tripulacao.size(); j++){
                                    for (int k = 0; k < astronautas.size(); k++){
                                        if (astronautas[k].CPF == voos[i].tripulacao[j].CPF){
                                            astronautas[k].ficar_indisponivel();
                                        }
                                    }
                                }
                                cout << " -> ";
                                cout << "Voo " << codigo << " lançado com sucesso!" << endl;
                            }else {
                                cout << " -x ";
                                cout << "Não é possível lançar um voo com astronautas indisponíveis..." << endl;
                            }
                        } else {
                            cout << " -x ";
                            cout << "Não é possível lançar um voo sem tripulação..." << endl;
                        }
                    }else {
                    cout << " -x ";
                    cout << "Não é possível lançar um voo que não está planejado..." << endl;
                    }
                }
            }
            if (!voo_encontrado){
                cout << " -x ";
                cout << "Voo " << codigo << " não encontrado." << endl;
            }
        }
        else if (comando == "FINALIZAR_VOO" || comando == "08." || comando == "08" || comando == "8." || comando == "8"){
            int codigo;
            cin >> codigo;
            limpar_buffer();
            bool voo_encontrado = false;
            for(int i = 0; i < voos.size(); i++){
                if(voos[i].codigo == codigo){
                    voo_encontrado = true;
                    if (voos[i].estado == "em_curso"){
                        voos[i].finalizar_voo();
                        for (int j = 0; j < voos[i].tripulacao.size(); j++){
                            for (int k = 0; k < astronautas.size(); k++){
                                if (astronautas[k].CPF == voos[i].tripulacao[j].CPF){
                                    astronautas[k].ficar_disponivel();
                                }
                            }
                        }
                        cout << " -> ";
                        cout << "Voo " << codigo << " finalizado com sucesso!" << endl;
                    }else {
                        cout << " -x ";
                        cout << "Não é possível finalizar um voo que não está em curso..." << endl;
                    }
                }
            }
            if (!voo_encontrado){
                cout << " -x ";
                cout << "Voo " << codigo << " não encontrado." << endl;
            }
        }
        else if (comando == "EXPLODIR_VOO" || comando == "09." || comando == "09" || comando == "9." || comando == "9"){
            int codigo;
            cin >> codigo;
            limpar_buffer();
            bool voo_encontrado = false;
            for(int i = 0; i < voos.size(); i++){
                if(voos[i].codigo == codigo){
                    voo_encontrado = true;
                    if (voos[i].estado == "em_curso"){
                        voos[i].explodir_voo();
                        for (int j = 0; j < voos[i].tripulacao.size(); j++){
                            for (int k = 0; k < astronautas.size(); k++){
                                if (astronautas[k].CPF == voos[i].tripulacao[j].CPF){
                                    astronautas[k].morrer();
                                }
                            }
                        }
                        cout << " -> ";
                        cout << "Voo " << codigo << " explodiu com sucesso!" << endl;
                        cout << " -> ";
                        cout << "Você matou " << voos[i].tripulacao.size() << " astronautas..." << endl;
                        cout << " -> ";
                        cout << "Eles eram: " << endl;
                        for(int j = 0; j < voos[i].tripulacao.size(); j++){
                            cout << " -> ";
                            cout << voos[i].tripulacao[j].nome << " de " << voos[i].tripulacao[j].idade << " anos;" <<endl;
                    }
                        cout << " -> ";
                        cout << "Você é um monstro..." << endl;
                    }else {
                        cout << " -x ";
                        cout << "Não é possível explodir um voo que não está em curso..." << endl;
                    }
                }
            }
            if (!voo_encontrado){
                cout << " -x ";
                cout << "Voo " << codigo << " não encontrado." << endl;
            }
        }
        else if (comando == "LISTAR_ASTRONAUTAS" || comando == "10." || comando == "10"){
            limpar_buffer();
            for(int i = 0; i < astronautas.size(); i++){
                if (astronautas[i].vivo){
                    cout << " -> ";
                    cout << astronautas[i].CPF << " " << astronautas[i].idade << " " << astronautas[i].nome << " ";
                    if (astronautas[i].disponivel){
                        cout << "disponível" << endl;
                    } else {
                        cout << "indisponível" << endl;
                    }
                }else {
                    cout << " -> ";
                    cout << astronautas[i].CPF << " " << astronautas[i].idade << " " << astronautas[i].nome << " morto" << endl;
                }
            }
        }
        else if (comando == "LISTAR_VOOS" || comando == "11." || comando == "11"){
            limpar_buffer();
            for(int i = 0; i < voos.size(); i++){
                cout << " -> ";
                cout << voos[i].codigo << " " << voos[i].estado << endl;
                if (voos[i].tripulacao.size() > 0){
                        cout << "    Tripulação: " << endl;
                    for(int j = 0; j < voos[i].tripulacao.size(); j++){
                        cout << "    ";
                        cout << " -> ";
                        cout << voos[i].tripulacao[j].CPF << " " << voos[i].tripulacao[j].idade << " " << voos[i].tripulacao[j].nome << endl;
                    }
                } else{
                    cout << "    ";
                    cout << " -> ";
                    cout << "Voo sem tripulação." << endl;
                }
            }
        }
        else if (comando == "LISTAR_MORTOS" || comando == "12." || comando == "12"){
            for(int i = 0; i < astronautas.size(); i++){
                if(!astronautas[i].vivo){
                    cout << " -> ";
                    cout << astronautas[i].CPF << " " << astronautas[i].idade << " " << astronautas[i].nome << endl;
                    cout << "    Participou dos voos: " << endl;
                    cout << "    ";
                    cout << "     [ ";
                    for (int j = 0; j < voos.size(); j++){
                        if (voos[j].estado != "planejado"){
                            for (int k = 0; k < voos[j].tripulacao.size(); k++){
                                if (voos[j].tripulacao[k].CPF == astronautas[i].CPF){
                                    cout << voos[j].codigo << " ";
                                }
                            }
                        }
                    }
                    cout << "]" << endl;
                }
            }
        }
        else if (comando == "LISTAR_TRIPULACAO" || comando == "13." || comando == "13"){
            int codigo;
            cin >> codigo;
            limpar_buffer();
            bool voo_encontrado = false;
            for(int i = 0; i < voos.size(); i++){
                if(voos[i].codigo == codigo){
                    voo_encontrado = true;
                    if (voos[i].tripulacao.size() > 0){
                        for(int j = 0; j < voos[i].tripulacao.size(); j++){
                            cout << " -> ";
                            cout << voos[i].tripulacao[j].CPF << " " << voos[i].tripulacao[j].idade << " " << voos[i].tripulacao[j].nome << endl;
                        }
                    }
                }
            }
            if (!voo_encontrado){
                cout << " -x ";
                cout << "Voo " << codigo << " não encontrado." << endl;
            }
        }
        else if (comando == "AJUDA" || comando == "14." || comando == "14"){
            limpar_buffer();
            ajuda();
        }
        else {
            limpar_buffer();
            cout << "Comando inválido..." << endl;
        }
    }
    return 0;
}
