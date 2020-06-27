#include <iostream>
#include <string>
#include <stdlib.h>
#include <climits>
using namespace std;

void validacao_entr_dados (int &var, string str, string invalid);

int duvida;
int Total;

//Novidade CLASS, funciona como um struct só que bem definido
class Questoes
{
//Aquilo que esta no back-end do programa, não imprime para o usuário
private:
    string Texto;
    string Resposta1;
    string Resposta2;
    int Resposta_correta;
    int Score_questoes;
    string Curiosidade;

//Aquilo que está público
public:
void valores(string, string, string, string, int, int);
void validacao();
};


int main()
{
setlocale (LC_ALL, "Portuguese");
cout << "* * * * * * * * * * * * * * * * * * * * * * *" << endl;
cout << "*                                           *" << endl;
cout << "*    BEM VINDO AO QUIZ DO CORONINHA         *" << endl;
cout << "*                                           *" << endl;
cout << "*                                           *" << endl;
cout << "* * * * * * * * * * * * * * * * * * * * * * *" << endl;
cout << endl;

cout << "Pressione Enter para começar o quiz..." << endl;
cin.get();

string nome;
int idade;
cout << "Qual seu nome? " << endl;
cin >> nome;
cout << "Qual sua idade? " << endl;
cin >> idade;
cout << endl;
string resposta;
cout << "Você está pronto para o quiz do CORONINHA senhor(a) " << nome << " ?? " << "Sim/Não." << endl;
cin >> resposta;
if (resposta == "sim" or resposta == "Sim" or resposta == "SIM"){
    cout << endl;
    cout << "Certo, boa sorte!" << endl;
    cout << endl;

} else {
    cout << "Certo, até mais!!" << endl;
    return 0;
}
//Chamada dos class dentro da main
Questoes q1;
Questoes q2;
Questoes q3;
Questoes q4;
Questoes q5;

//Passa as strings, a primeira opção, a segunda opção, qual a correta, total de pontos
q1.valores("Uma pessoa sem sintomas pode transmitir o covid-19? ",
           "V",
           "F",
           "É importante lembrar que não só os infectados podem transmitir a doença,\npor exemplo viajantes que tiveram contato com o vírus e também tiveram contato com pessoas na área de risco.",
           1,
           20);
q2.valores("O vírus pode ser transmitido por: gotículas de saliva, contato com superfícies contaminadas, sangue, consumo de animais selvagens. ",
           "V",
           "F",
           "Além do contágio entre os humanos, existe também a possibilidade de contágio através de animais silvestres como morcegos e cobras.",
           1,
           20);
q3.valores("São sintomas mais comuns do COVID-19: tosse seca, febre e cansaço. ",
           "V",
           "F",
           "Em caso de febre, tosse e dificuldade para respirar é preciso ficaralerta.\nEm alguns casos, Há também complicações respiratórias, podendo evoluirpara pneumonias.",
           1,
           20);
q4.valores("Correspondências vindas da China correm o risco de transportar o vírus para outros locais?",
           "V",
           "F",
           "O vírus sobrevive no máximo 24 horas fora do corpo humano,\npor isso não hápossibilidade de que ele seja levado para outros locais do mundo através de objetose cartas.",
           2,
           20);
q5.valores("Cães e gatos podem transmitir a doença?",
            "V",
           "F",
           "Não há evidências de que animais domésticos podem ser via de transmissão do Coronavírus, mas se recomenda sempre lavar as mãos após brincar com os pets.",
           2,
           20);


//Validação das afirmativas
q1.validacao();
q2.validacao();
q3.validacao();
q4.validacao();
q5.validacao();


cout << "O total de pontos é: " << Total << "/100" << endl;

if (Total >= 60)
{
    cout << "Boa, você ganhou o quiz!" << endl;
    cout << "&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
    cout << "&      Parabéns!!      &" << endl;
    cout << "&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
}

else {

cout << "Não foi dessa vez..." << endl;
cout << "Tente a sorte novamente!" << endl;
}
}

void Questoes::validacao(){
cout << endl;
cout << Texto << endl;
cout << "1. " << Resposta1 << endl;
cout << "2. " << Resposta2 << endl;

validacao_entr_dados (duvida, "Qual a sua resposta? (responda com números, exemplo 1-V e 2-F):  ", "\nEntrada inválida, tente novamente. ");

if (duvida == Resposta_correta){
    system("cls");
    cout << "Parabéns, você acertou";
    Total += Score_questoes;
    cout << "\nVocê ganhou: " << Score_questoes << "!" << endl;
    cout << "\nCuriosidade: " << Curiosidade;
} else
{
    system("cls");
    cout << endl;
    cout << "Você errou..." << endl;
    cout << "Score: " << Score_questoes << endl;
    cout << "A resposta correta era: " << Resposta_correta << endl;
    cout << "\nCuriosidade: " << Curiosidade;
}

cout << endl;
}

void Questoes::valores(string q, string r1, string r2, string cur, int min_, int max_)
{
    Texto=q;
    Resposta1=r1;
    Resposta2=r2;
    Curiosidade=cur;

    Resposta_correta=min_;
    Score_questoes=max_;
system("cls");
}

void validacao_entr_dados (int &var, string str, string invalid){
bool valid = false;
while(!valid){
    cout << str;
    cin >> var;
    if (cin.fail())
    {
        cout << invalid;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    } else
    valid = true;
}
}
