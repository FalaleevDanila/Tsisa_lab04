#include <iostream>
#include <vector>
#include <random>

#include "function.h"



double srArf(std::vector <double> fun1, std::vector <double> fun2){
    double sum = 0;
    for(int i = 0; i < fun1.size(); ++i){
        sum+=fun1[i]*fun2[i];
    }
    return sum/fun1.size();
}

double cheb1(std::vector <double> fun){
    double max = fun[1]-fun[0];
    for(int i = 2; i < fun.size(); ++i)
        if(fun[i]-fun[i-1] > max)
            max = fun[i]-fun[i-1];
    return max;
}

double cheb2(std::vector <double> fun1, std::vector <double> fun2){
    double max = fun1[0]-fun2[0];
    for(int i = 1; i < fun1.size(); ++i){
        if(fun1[i]-fun2[i] > max){
            max = fun1[i]-fun2[i];
        }
    }
    return max;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    double xMin = 0;
    double xMax = 3.14;
    double ample = 0.25;
    double P = 0.95;
    double eps = 0.01;

    std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution <double> dis(-ample,ample);

    double K = 100; // количество отсчетов

    std::vector <double> xk;
    for(int i = 0; i <= K; ++i){
        double one = xMin + i*(xMax - xMin)/K;
        xk.push_back(one);
    }
    std::vector <double> fxk;
    std::vector <double> fxk_noised;
    for(int i = 0; i <= K; ++i){
        double one = function(xk[i]);
        fxk.push_back(one);
        fxk_noised.push_back(one+dis(gen));
    }


    std::vector <double> r { 3.0 , 5.0 };
    double r_f = 3;
    double r_s = 5;

    double L = 10;
    std::vector <double> lambda;

    for(double i = 0.0; i <= L; ++i){
        double one = i / L;
        lambda.push_back(one);
    }

    double N = log(1. - P)/log(1. - eps/(xMax - xMin));

    std::vector <double> alpha;



    std::vector <double> sredneeArf;
    std::uniform_real_distribution<double> dis2(0.0,1.0);
    for(size_t i = 0; i < r.size(); ++i){
        double m = (r[i]-1.0)/2.0;
        for(size_t j = 0; j < lambda.size(); ++j){
            for(size_t z = 0; z < N; ++z){

                double one = dis2(gen);
                if(m >= 2.){
                    for(size_t a = 0; a < N; ++a){

                    }
                }
            }
        }
    }
    /*
    for (size_t jump = 0u; jump < data.radius_.size(); ++jump)
    {
        double r = data.radius_[jump];
        double M = data.M_[jump];

        temp_save.r = data.radius_[jump];
        for (size_t l = 0u; l < data.lambda.size(); ++l) // для различных значений весов
        {
            temp_save.h = data.lambda[l];
            for (size_t index = 0u; index < N_; ++index) // Число испытаний N
            {
                temp_alpha.reserve(M+1u);
                temp_alpha.resize(M+1u);
                temp_alpha.back() = dis(gen);
                if (data.M_[jump] >= 2u)
                {
                    for (size_t count = 1u; count < data.M_[jump] ; ++count)
                    {
                        std::uniform_real_distribution <double> temp_dis(0.0,1.0 - data.sum(temp_alpha,M, r-M-1));
                        temp_alpha.at(count) = 0.5 * temp_dis(gen);
                    }
                }
                temp_alpha.front() = 0.5*(1.0 - data.sum(temp_alpha,1u,r-2u));
                // Уже сгенерирован набор альфа
                data.init_Fx_filtered(temp_alpha,M); // Находим отфильтрованную функцию
                // Находим критерий зашумленности (по Евклиду)
                double summ = 0.0;
                for (size_t kol = 1u; kol <= data.K_; ++kol)
                {
                    summ += pow((data.F_xk_filtered[kol] - data.F_xk_filtered[kol - 1u]) , 2);
                }
                temp_omega_delta.first = sqrt(summ); summ=0.0;
                // Находим критерий отличия (по Евклиду)
                for (size_t kol = 0u; kol <= data.K_; ++kol)
                {
                    summ += pow((data.F_xk_filtered[kol] - data.F_xk_noised[kol]) , 2);
                }
                temp_omega_delta.second = sqrt(summ/data.K_);

                temp_J = ( data.lambda[l] * temp_omega_delta.first) + (1 - data.lambda[l])*temp_omega_delta.second;

                if (temp_J < data.J)
                {
                    data.J = temp_J;
                    data.omega_delta = temp_omega_delta;
                    temp_save.alpha = temp_alpha;
                    temp_save.metrics.delta = temp_omega_delta.second;
                    temp_save.metrics.omega = temp_omega_delta.first;
                    temp_save.metrics.J = temp_J;
                    temp_save.graphic.Function_filtered = data.F_xk_filtered;
                    temp_save.distance = sqrt(pow(temp_save.metrics.delta,2) + pow(temp_save.metrics.omega,2));
                }
            }
            data.J = 90000000.0;
            data.omega_delta = {90000000.0,90000000.0};
            save.push_back(temp_save);
        }

        if (jump == 0u)
        {
            v10.resut1.saves = save ;
            save.clear();
        }
        else
        {
            v10.resut2.saves = save ;
            save.clear();
        }
    }
    */
    return 0;
}