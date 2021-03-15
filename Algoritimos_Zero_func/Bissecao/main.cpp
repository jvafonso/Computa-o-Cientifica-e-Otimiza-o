#include <iostream>
#include <math.h>

using namespace std;

float media(float x, float y){
    return ((x+y)/2);
}

float calculo_fun(float z){
    return ((pow(z,3)) - 25);
}


int main()
{
    float limite1;
    float limite2;
    float tolerancia;

    float result;
    int cont = ;
    float func_res;

    cout << "Digite o primeiro limite do intervalo em que o zero da funcao se encontra: ";
    cin >> limite1;
    cout << endl;

    cout << "Digite o segundo limite do intervalo em que o zero da funcao se encontra: ";
    cin >> limite2;
    cout << endl;

    cout << "Digite a toleracia desejada para o resultado: ";
    cin >> tolerancia;
    cout << endl;

    do{
        cont++;
        result = media(limite1, limite2);

        float func_l1 = calculo_fun(limite1);

        float func_l2 = calculo_fun(limite2);

        func_res = calculo_fun(result);

        if((func_l1*func_res) < 0){
            limite2 = result;
        }else{
            limite1 = result;
        }
    }while(abs(func_res) > tolerancia);

    cout << "O resultado aproximado do zero da funcao e " << result << " e foram necessarias " << cont << " iteracoes.";

    return 0;
}
