#include <iostream>
#include <math.h>

using namespace std;

float secante(float a, float fa, float b, float fb){
    return (((a*fb) - (b*fa)) / (fb - fa));
}

float calculo_fun(float z){
    return (pow(z,3) - z - 1);
}


int main()
{
    float limite1;
    float limite2;
    float ponto1;
    float ponto2;
    float tolerancia;

    float result;
    int cont = 0;
    float func_res;

    cout << "Digite o primeiro limite do intervalo em que o zero da funcao se encontra: ";
    cin >> limite1;
    cout << endl;

    cout << "Digite o segundo limite do intervalo em que o zero da funcao se encontra: ";
    cin >> limite2;
    cout << endl;

    cout << "Digite o primeiro ponto escolhido para o calculo dentro do intervalo limite: ";
    cin >> ponto1;
    cout << endl;

    if(ponto1 < limite1){
        cout << "O valor do ponto digitado e invalido.";
        cout << endl;
        return 0;
    }

    cout << "Digite o segundo ponto escolhido para o calculo dentro do intervalo limite: ";
    cin >> ponto2;
    cout << endl;

    if(ponto1 > limite2){
        cout << "O valor do ponto digitado e invalido.";
        cout << endl;
        return 0;
    }

    cout << "Digite a toleracia desejada para o resultado: ";
    cin >> tolerancia;
    cout << endl;

    do{
        cont++;

        float func_p1 = calculo_fun(ponto1);

        float func_p2 = calculo_fun(ponto2);

        result = secante(ponto1, func_p1, ponto2, func_p2);

        func_res = calculo_fun(result);

        ponto1 = ponto2;
        ponto2 = result;

    }while(abs(func_res) > tolerancia);

    cout << "O resultado aproximado do zero da funcao e " << result << " e foram necessarias " << cont << " iteracoes.";

    return 0;
}
