#include <iostream>
#include <math.h>

using namespace std;

float calculo_fun(float z){
    return (pow(z,3) - z - 1);
}

float calculo_deriv(float a){
    return (3*pow(a,2) - 1);
}


int main()
{
    float limite1;
    float limite2;
    float ponto;
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

    cout << "Digite o ponto escolhido para o calculo dentro do intervalo limite: ";
    cin >> ponto;
    cout << endl;

    if(ponto < limite1 || ponto > limite2){
        cout << "O valor do ponto digitado e invalido.";
        cout << endl;
        return 0;
    }


    cout << "Digite a toleracia desejada para o resultado: ";
    cin >> tolerancia;
    cout << endl;

    do{
        cont++;

        float func_p = calculo_fun(ponto);

        float derivada = calculo_deriv(ponto);

        result =  ponto - (func_p/derivada);

        func_res = calculo_fun(result);

        ponto = result;

    }while(abs(func_res) > tolerancia);

    cout << "O resultado aproximado do zero da funcao e " << result << " e foram necessarias " << cont << " iteracoes.";

    return 0;
}
