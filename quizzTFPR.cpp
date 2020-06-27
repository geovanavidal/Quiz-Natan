#include <iostream>
#include <string>
#include <stdlib.h>
#include <climits>
using namespace std;

void validacao_entr_dados (int &var, string str, string invalid);

int duvida;
int Total;

//Novidade CLASS, funciona como um struct s� que bem definido
class Questoes
{
//Aquilo que esta no back-end do programa, n�o imprime para o usu�rio
private:
    string Texto;
    string Resposta1;
    string Resposta2;
    int Resposta_correta;
    int Score_questoes;
    string Curiosidade;

//Aquilo que est� p�blico
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

cout << "Pressione Enter para come�ar o quiz..." << endl;
cin.get();

string nome;
int idade;
cout << "Qual seu nome? " << endl;
cin >> nome;
cout << "Qual sua idade? " << endl;
cin >> idade;
cout << endl;
string resposta;
cout << "Voc� est� pronto para o quiz do CORONINHA senhor(a) " << nome << " ?? " << "Sim/N�o." << endl;
cin >> resposta;
if (resposta == "sim" or resposta == "Sim" or resposta == "SIM"){
    cout << endl;
    cout << "Certo, boa sorte!" << endl;
    cout << endl;

} else {
    cout << "Certo, at� mais!!" << endl;
    return 0;
}
//Chamada dos class dentro da main
Questoes q1;
Questoes q2;
Questoes q3;
Questoes q4;
Questoes q5;

//Passa as strings, a primeira op��o, a segunda op��o, qual a correta, total de pontos
q1.valores("Uma pessoa sem sintomas pode transmitir o covid-19? ",
           "V",
           "F",
           "� importante lembrar que n�o s� os infectados podem transmitir a doen�a,\npor exemplo viajantes que tiveram contato com o v�rus e tamb�m tiveram contato com pessoas na �rea de risco.",
           1,
           20);
q2.valores("O v�rus pode ser transmitido por: got�culas de saliva, contato com superf�cies contaminadas, sangue, consumo de animais selvagens. ",
           "V",
           "F",
           "Al�m do cont�gio entre os humanos, existe tamb�m a possibilidade de cont�gio atrav�s de animais silvestres como morcegos e cobras.",
           1,
           20);
q3.valores("S�o sintomas mais comuns do COVID-19: tosse seca, febre e cansa�o. ",
           "V",
           "F",
           "Em caso de febre, tosse e dificuldade para respirar � preciso ficaralerta.\nEm alguns casos, H� tamb�m complica��es respirat�rias, podendo evoluirpara pneumonias.",
           1,
           20);
q4.valores("Correspond�ncias vindas da China correm o risco de transportar o v�rus para outros locais?",
           "V",
           "F",
           "O v�rus sobrevive no m�ximo 24 horas fora do corpo humano,\npor isso n�o h�possibilidade de que ele seja levado para outros locais do mundo atrav�s de objetose cartas.",
           2,
           20);
q5.valores("C�es e gatos podem transmitir a doen�a?",
            "V",
           "F",
           "N�o h� evid�ncias de que animais dom�sticos podem ser via de transmiss�o do Coronav�rus, mas se recomenda sempre lavar as m�os ap�s brincar com os pets.",
           2,
           20);


//Valida��o das afirmativas
q1.validacao();
q2.validacao();
q3.validacao();
q4.validacao();
q5.validacao();


cout << "O total de pontos �: " << Total << "/100" << endl;

if (Total >= 60)
{
    cout << "Boa, voc� ganhou o quiz!" << endl;
    cout << "&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
    cout << "&      Parab�ns!!      &" << endl;
    cout << "&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
}

else {

cout << "N�o foi dessa vez..." << endl;
cout << "Tente a sorte novamente!" << endl;
}
}

void Questoes::validacao(){
cout << endl;
cout << Texto << endl;
cout << "1. " << Resposta1 << endl;
cout << "2. " << Resposta2 << endl;

validacao_entr_dados (duvida, "Qual a sua resposta? (responda com n�meros, exemplo 1-V e 2-F):  ", "\nEntrada inv�lida, tente novamente. ");

if (duvida == Resposta_correta){
    system("cls");
    cout << "Parab�ns, voc� acertou";
    Total += Score_questoes;
    cout << "\nVoc� ganhou: " << Score_questoes << "!" << endl;
    cout << "\nCuriosidade: " << Curiosidade;
} else
{
    system("cls");
    cout << endl;
    cout << "Voc� errou..." << endl;
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
