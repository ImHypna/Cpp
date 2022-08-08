#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int main()
{
    
    
    cout << "**************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhação! *" << endl;
    cout << "**************************************" << endl;

    cout<< "Escolha seu nível de dificuldade: "<<endl;
    cout<< "Fácil(F)  Médio(M) Difícil(D) "<<endl;
    cout<< "Caso a escolha de dificuldade seja diferente das apresentadas você sera automaticamente enviado para o modo difícil" << endl;

    char dificuldade;
    cin >> dificuldade;

    int numero_tentativas;

    if (dificuldade ==  'F')
    {
        numero_tentativas = 10;
    }
    else if(dificuldade == 'M')
    {
        numero_tentativas = 5;
    }
    else
    {
        numero_tentativas = 3; 
    }
    

    srand(time(NULL));
    const int NUMERO_SECRETO = rand()%100;
    //cout<< NUMERO_SECRETO <<endl;

    
    bool nao_acertou = true;
    int tentativas = 0;
    double ponto = 1000.0;

   for(tentativas =1;tentativas<=numero_tentativas;tentativas++){      
        int chute;
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual seu chute? ";
        cin >> chute;
        double pontosPerdidos = abs(chute-NUMERO_SECRETO)/2.0;
        ponto = ponto -  pontosPerdidos;

        cout << "O valor do seu chute é: " << chute << endl;
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou)
        {
            cout << "Parabéns! Você acertou o número secreto!" << endl;
            nao_acertou = false;
            cout<< "Seus pontos foram"<< ponto << endl;
            break;
        }
        else if (maior)
        {
            cout << "Seu chute foi maior que o número secreto!" << endl;
            

        }
        else
        {
            cout << "Seu chute foi menor que o número secreto!" << endl;
            
        }
    }
    cout << "Fim de jogo!" << endl;
    if (nao_acertou)
    {
        cout<< "Você perdeu tente novamente!" <<endl;
        cout<< "O numero secreto era" << NUMERO_SECRETO <<endl;
    }
    else
    {
    cout << "Você acertou o número secreto em " << tentativas  << " tentativas" << endl;
    cout.precision(2);
    cout << fixed;
    cout << "Seus Pontos foram de: " << ponto <<endl;
    }
    
    
}