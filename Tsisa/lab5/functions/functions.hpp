#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cstddef>

void                  matrix2 (std::vector <double> first, std::vector <double> second,
                               std::vector <double> third, std::vector <double> fouth,
                               std::vector <double> fifth);

void                  parettoMethod (std::vector <double> first, std::vector <double> second,
                                     std::vector <double> third, std::vector <double> fouth);

void                  displayHead (){
    std::cout<<" || A - Suzuki || B - Mitsubishi || C - Honda || D - Toyota || "<<std::endl;
    std::cout<<"                      Best variant                                  bad variant " <<
                                                                                                std::endl << std::endl;
    std::cout<<" 1) Cost              :  Suzuki     ->   Honda      ->  Mitsubishi  -> Toyota "<<std::endl;
    std::cout<<" 2) Maintenance       :  Mitsubishi ->        Toyota / Suzuki       -> Honda  "<<std::endl;
    std::cout<<" 3) Fuel consumption  :  Suzuki     ->   Honda      ->  Mitsubishi  -> Toyota "<<std::endl;
    std::cout<<" 4) Comfort           :  Toyota     ->   Mitsubishi ->     Honda    -> Suzuki "<<std::endl <<
    std::endl << std::endl;

}

void                  displayMatrix2 (std::vector <double> first, std::vector <double> second,
                                      std::vector <double> third, std::vector <double> fouth, double s){

    std::cout<<"         1        2        3         4 "<<std::endl;
    for(size_t i = 0; i <4 ; ++i){
        if(i==0) std::cout<<" A ";
        if(i==1) std::cout<<" B ";
        if(i==2) std::cout<<" C ";
        if(i==3) std::cout<<" D ";

        std::cout <<  std::fixed <<std::setprecision(4) <<std::setw(5)<<
                  " || "<< " - " <<
                  " || "<< second[i]/s <<
                  " || "<< third[i]/s <<
                  " || "<< " - " << " || " << std::endl;
    }
    std::cout  << std::endl;
}

void                  displayMatrix (std::vector <double> first, std::vector <double> second,
                                     std::vector <double> third, std::vector <double> fouth, double s){

    std::cout<<"         1           2         3        4 "<<std::endl;
        for(size_t i = 0; i <4 ; ++i){
            if(i==0) std::cout<<" A ";
            if(i==1) std::cout<<" B ";
            if(i==2) std::cout<<" C ";
            if(i==3) std::cout<<" D ";

            std::cout <<  std::fixed <<std::setprecision(4) <<std::setw(5)<<
            " || "<< first[i]/s <<
            " || "<< second[i]/s <<
            " || "<< third[i]/s <<
            " || "<< fouth[i]/s << " || " << std::endl;
        }
}

void                  displayMatrixIer( std::vector <double> first, std::vector <double> second,
                                        std::vector <double> third, std::vector <double> fouth,
                                        std::vector <double> sum, double sumOfSum ){
    std::cout <<  std::fixed <<std::setprecision(4) ;
    for(int i=0;i<4;++i){
        double sumH=first[i]+second[i]+third[i]+fouth[i];
        sum.push_back(sumH);
        sumOfSum+=sumH;
    }
    std::cout<<"               1          2         3         4       Sum     Norm Sum  "<<std::endl;
    for(size_t i = 0; i <4 ; ++i){
        std::cout <<  std::fixed <<std::setprecision(4) <<std::setw(7)<<
                  " || " << std::setw(2) << i+1 <<
                  " | "  << std::setw(7) << first[i] <<
                  " | "  << std::setw(7) << second[i] <<
                  " | "  << std::setw(7) << third[i] <<
                  " | "  << std::setw(7) << fouth[i] <<
                  " | "  << std::setw(7) << sum[i] <<
                  " | "  << std::setw(7) << sum[i]/sumOfSum <<
                  " || " << std::endl;

    }

}

void                  displayMatrixIerP( std::vector <double> first, std::vector <double> second,
                                         std::vector <double> third, std::vector <double> fouth,
                                         std::vector <double> sum, double sumOfSum ){
    std::cout <<  std::fixed <<std::setprecision(4) ;
    for(int i=0;i<4;++i){
        double sumH=first[i]+second[i]+third[i]+fouth[i];
        sum.push_back(sumH);
        sumOfSum+=sumH;
    }
    std::cout<<"             A          B         C         D       Sum     Norm Sum  "<<std::endl;
    for(size_t i = 0; i <4 ; ++i) {
        std::cout << std::fixed << std::setprecision(4) << std::setw(7);
        if (i == 0) std::cout << " A ";
        if (i == 1) std::cout << " B ";
        if (i == 2) std::cout << " C ";
        if (i == 3) std::cout << " D ";
        std::cout <<
                  " | " << std::setw(7) << first[i] <<
                  " | " << std::setw(7) << second[i] <<
                  " | " << std::setw(7) << third[i] <<
                  " | " << std::setw(7) << fouth[i] <<
                  " | " << std::setw(7) << sum[i] <<
                  " | " << std::setw(7) << sum[i] / sumOfSum <<
                  " || " << std::endl;
    }


}

void                  answer (int i){
    if(i==1){
        std::cout << std::endl << " Best : Suzuki " << std::endl;
    } else if(i==2){
        std::cout << std::endl << " Best : Mitsubishi " << std::endl;
    } else if(i==3){
        std::cout << std::endl << " Best : Honda " << std::endl;
    } else if(i==4){
        std::cout << std::endl << " Best : Toyota " << std::endl;
    }
}



// 1
void                  limitedCriterialMethod (std::vector <double> first, std::vector <double> second,
                                              std::vector <double> third, std::vector <double> fouth){

    std::cout << std::endl <<" 1) " << std::endl;
    displayHead ();
    std::vector <double> crit{4, 2, 6, 8};
    double sum_crit = 20;
    std::vector <double> norm_crit;
    for(size_t ni = 0 ; ni < 4 ; ++ni){
        norm_crit.push_back(crit[ni]/sum_crit);
    }
    std::cout << '\n' << '\n' << " Vector of weight" << '\n';
    std::cout<<" ||      Cost       ||    Maintenance  || Fuel consumption ||     Comfort     || " << std::endl;
    std::cout <<
              " || " << std::setw(15) << crit[0] <<
              " || " << std::setw(15) << crit[1] <<
              " || " << std::setw(16) << crit[2] <<
              " || " << std::setw(15) << crit[3] << " || " << '\n' << '\n' << '\n';
    std::cout<< " Normix matrix \n";
    std::cout<<" ||      Cost       ||    Maintenance  || Fuel consumption ||     Comfort     || " << std::endl;
    std::cout <<
              " || " << std::setw(15) << norm_crit[0] <<
              " || " << std::setw(15) << norm_crit[1] <<
              " || " << std::setw(16) << norm_crit[2] <<
              " || " << std::setw(15) << norm_crit[3] << " || " << '\n' << '\n' << '\n';


    std::cout <<" Mark of alternatives "<< std::endl << std::endl;
    displayMatrix(first, second, third, fouth, 1);
    std::cout << std::endl << std::endl;
    for(int i=0;i<4;++i){
        first[i]*=0.5;
    }

    for(int i=0;i<4;++i){
        second[i]*=0.3;
    }

    for(int i=0;i<4;++i){
        third[i]*=0.7;
    }

    for(int i=0;i<4;++i){
        fouth[i]*=1.;
    }

    std::cout<<" || Cost = 0.5|| Maintenance = 0.3 || Fuel consumption  = 0.7 || Comfort = 1 || "
    <<std::endl << std::endl << std::endl;

    displayMatrix(first, second, third, fouth, 1);

    std::cout << std::endl << std::endl <<" Norm matrix: "<< std::endl << std::endl;

    double minFi= *std::min_element(std::begin(first),std::end(first));
    double maxFi= *std::max_element(std::begin(first),std::end(first));

    for(int i=0;i<4;++i)
        first[i] = (first[i]-minFi)/(maxFi-minFi);

    double minS= *std::min_element(std::begin(second),std::end(second));
    double maxS=*std::max_element(std::begin(second),std::end(second));

    for(int i=0;i<4;++i)
        second[i] = (second[i]-minS)/(maxS-minS);

    double minT= *std::min_element(std::begin(third),std::end(third));
    double maxT=*std::max_element(std::begin(third),std::end(third));

    for(int i=0;i<4;++i)
        third[i] = (third[i]-minT)/(maxT-minT);


    displayMatrix(first, second, third, fouth, 1);
    double maxFo= *std::max_element(std::begin(fouth),std::end(fouth));
    for(int i=0;i<4;++i){
        if(fouth[i]==maxFo && first[i] >= norm_crit[0] && second[i]>=norm_crit[1] && third[i]>=norm_crit[2])
            answer(i+1);
    }
    std::cout<<std::endl<<std::endl<<std::endl;



}



// 2
void                  parettoMethod (std::vector <double> first, std::vector <double> second,
                                     std::vector <double> third, std::vector <double> fouth){




    std::cout << std::endl <<" 2) " << std::endl;

    displayHead ();

    displayMatrix2(first, second, third, fouth, 1);
    std::cout << " Lets check 2 main parametrs: 2 - Maintenance and 3 - Fuel consumption " << std::endl;
    for(int i=0;i<4;i++){
        std::cout << "(" << second[i] << ";" << third[i] << ")";
    }

    auto maxX=0;
    auto maxY=0;
    for(int i=0;i<4;++i){
        std::vector <double> line;
        line.push_back(second[i]);
        line.push_back(third[i]);
        double maxXi= *std::max_element(std::begin(line),std::end(line));
        double maxYi= *std::max_element(std::begin(line),std::end(line));
        if( i==0 || maxXi > maxX) maxX=maxXi;
        if( i==0 || maxYi > maxY) maxY=maxYi;
    }
    if(maxX>maxY) maxY=maxX;
    else maxX = maxY;
    auto minL = -1;
    auto l = -1;
    auto iter = 0;

    for(int i=0; i<4;i++){
       if(second[i] == maxX ||third[i] == maxX) iter=i+1;
    }
    answer(iter);

}




// 3
void                  weightOfCriteris (std::vector <double> first, std::vector <double> second,
                                        std::vector <double> third, std::vector <double> fouth) {
    std::cout << std::endl << " 3) " << std::endl;
    displayHead ();
    displayMatrix(first, second, third, fouth, 1);

//----------------------------------------------------------------------------------------------------------------------
    auto sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += first[i];
    }
    for (int i = 0; i < 4; i++) {
        first[i] /= sum;
    }
    sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += second[i];
    }
    for (int i = 0; i < 4; i++) {
        second[i] /= sum;
    }
    sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += third[i];
    }
    for (int i = 0; i < 4; i++) {
        third[i] /= sum;
    }
    sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += fouth[i];
    }
    for (int i = 0; i < 4; i++) {
        fouth[i] /= sum;
    }

//----------------------------------------------------------------------------------------------------------------------

    std::cout <<std::endl << " Normalize matrix " << std::endl;
    displayMatrix(first, second, third, fouth, 1);

    std::vector<double> firstn{0, 0.5, 0, 1};
    std::vector<double> secondn{1, 0, 1, 1};
    std::vector<double> thirdn{0.5, 0.5, 1, 0};
    std::vector<double> fouthn{0, 0, 1, 0.5};

    std::vector<double> ownKrit;
    sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += firstn[i];
    }

    ownKrit.push_back(sum);
    sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += secondn[i];
    }

    ownKrit.push_back(sum);
    sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += thirdn[i];
    }

    ownKrit.push_back(sum);
    sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += fouthn[i];
    }

    ownKrit.push_back(sum);
    sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += ownKrit[i];
    }
    for (int i = 0; i < 4; i++) {
        ownKrit[i] /= sum;
    }

    matrix2(first,second, third, fouth, ownKrit);
    std::cout << std::endl << std::endl << std::endl;


}




// 4
void                 functionSogl (std::vector <std::vector <double>> one) {
    std::vector<double> oneSum;
    for (int i = 0; i < 4; ++i) {
        double psum = 1;
        for (int j = 0; j < 4; ++j) {
            psum *= one[i][j];
        }
        oneSum.push_back(psum);
    }
    for (int i = 0; i < 4; ++i) {
        oneSum[i] = pow(oneSum[i], 0.25);
    }
    double sumOfSum = 0;
    for (int i = 0; i < 4; ++i) {
        sumOfSum += oneSum[i];
    }
    for(int i=0;i<4;++i) {
        oneSum[i] /= sumOfSum;
    }

    double alpha =
            oneSum[0]*(one[0][0]+one[1][0]+one[2][0]+one[3][0])+
            oneSum[1]*(one[0][1]+one[1][1]+one[2][1]+one[3][1])+
            oneSum[2]*(one[0][2]+one[1][2]+one[2][2]+one[3][2])+
            oneSum[3]*(one[0][3]+one[1][3]+one[2][3]+one[3][3]);

    std::cout << " Onoshenie soglasovannosty: " << (alpha - 4.)/(3.*0.9)<<std::endl;
}

std::vector <double> functionSum (std::vector <std::vector <double>> one, int o){
    std::vector<double> oneSum;
    for(int i=0;i<4;++i){
        double sum=0;
        for(int j=0;j<4;++j){
            sum+=one[j][i];
        }
        oneSum.push_back(sum);
    }
    double sumOfSum=0;
    for(int i=0;i<4;++i) {
        sumOfSum += oneSum[i];
    }
    if(o==0)
        displayMatrixIerP( one[0], one[1],one[2],one[3],oneSum,sumOfSum);
    else displayMatrixIer( one[0], one[1],one[2],one[3],oneSum,sumOfSum);

    for(int i=0;i<4;++i) {
        oneSum[i] /= sumOfSum;
    }
    return oneSum;
}

void                 matrix2 (std::vector <double> first, std::vector <double> second,
                              std::vector <double> third, std::vector <double> fouth, std::vector <double> fifth){
    std::vector <double> result;
    std::cout << std::endl << std::endl;
    for(size_t i = 0; i <4 ; ++i){
        double sum =
                first[i] * fifth[0] +
                second[i] * fifth[1] +
                third[i] * fifth[2] +
                fouth[i] * fifth[3];
        result.push_back(sum);
    }
    for(size_t i = 0; i <4 ; ++i){


        std::cout <<  std::fixed <<std::setprecision(4) <<std::setw(5)<<
                  " | "<< first[i] <<
                  "  "<< second[i] <<
                  "  "<< third[i] <<
                  "  "<< fouth[i] <<
                  " | ";
        if(i==1) std::cout<<" * ";
        else std::cout<<"   ";
        std::cout <<  std::fixed <<std::setprecision(4) <<std::setw(5)<<
                  " | "<< fifth[i] << " | ";
        if(i==1) std::cout<<" = ";
        else std::cout<<"   ";
        std::cout <<  std::fixed <<std::setprecision(4) <<std::setw(5)<<
                  " | "<< result[i] << " | "<< std::endl;
    }
    double maxFo = *std::max_element(std::begin(result), std::end(result));
    for (int i = 0; i < 4; ++i) {
        if (result[i] == maxFo)
            answer(i + 1);
    }
}

void                 analizIerarhij (){
    std::cout << std::endl << " 4) " << std::endl;
    displayHead ();
    std::vector<std::vector<double>> normalize;

//----------------------------------------------------------------------------------------------------------------------
    /// Cost
    std::vector<std::vector<double>> cost{{ 1., 3., 5., 7.},
                                          { 1./3, 1, 5., 7.},
                                          { 1./5, 1./5, 1, 3},
                                          { 1./7, 1./7, 1./3, 1}};
    std::cout <<std::endl <<std::endl << " Cost: " << std::endl << std::endl;

    std::vector<double> costSum = functionSum(cost,0);

    functionSogl(cost);

//----------------------------------------------------------------------------------------------------------------------
    /// Maintenance
    std::vector<std::vector<double>> maintenance{{ 1., 1./7., 1./3., 1.},
                                                 { 7., 1, 5., 3.},
                                                 { 3, 1./5, 1, 1./3},
                                                 { 1., 1./3, 3., 1}};
    std::cout <<std::endl <<std::endl << " Maintenance: " << std::endl << std::endl;
    std::vector<double> maintenanceSum = functionSum(maintenance,0);
    functionSogl(maintenance);
//----------------------------------------------------------------------------------------------------------------------
    /// Fuel consuption
    std::vector<std::vector<double>> fuelConsumption{{ 1., 3., 5., 7.},
                                                     { 1./3, 1, 5., 7.},
                                                     { 1./5, 1./5, 1, 3},
                                                     { 1./7, 1./7, 1./3, 1}};
    std::cout <<std::endl <<std::endl << " Fuel consuption: " << std::endl << std::endl;
    std::vector<double> fuelSum = functionSum(fuelConsumption,0);
    functionSogl(fuelConsumption);

//----------------------------------------------------------------------------------------------------------------------
    /// comfort
    std::vector<std::vector<double>> comfort{{ 1   , 3.   , 1./3., 1./5.},
                                             { 1./3., 1   , 1./7, 1./7.},
                                             { 3.   , 7.   , 1   , 1./3.},
                                             { 5.   , 7.   ,   3., 1   }};
    std::cout <<std::endl <<std::endl << " Comfort: " << std::endl << std::endl;
    std::vector<double> comfortSum = functionSum(comfort,0);
    functionSogl(comfort);
//----------------------------------------------------------------------------------------------------------------------

    /// pioritets
    std::vector<std::vector<double>> priorites{{ 1   , 1./3   , 3., 5.},
                                               { 3., 1   , 5., 7.},
                                               { 1./3   , 1./5   , 1   , 3.},
                                               { 1./5   , 1./7   ,   1./3., 1   }};

    std::cout <<std::endl <<std::endl << " Priorites: " << std::endl << std::endl;
    std::vector<double> prioritestSum = functionSum(priorites,1);
    functionSogl(priorites);

//----------------------------------------------------------------------------------------------------------------------
    matrix2(costSum, maintenanceSum, fuelSum, comfortSum, prioritestSum);
}


