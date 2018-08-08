/* 2_인형들
 * 2018 kakao code festival 예선
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int start_index = 0;
int end_index = 0;

double getMean(vector<int> &favor) {
    double sum = 0;
    for (int i = start_index; i <= end_index; i++)
        sum += favor[i];
    return sum / (end_index - start_index + 1);
}

double getVariance(vector<int> &favor, double mean) {
    double sum = 0;
    for (int i = start_index; i <= end_index; i++)
        sum += pow(favor[i] - mean, 2);
    return sum / (end_index - start_index + 1);
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(11);

    int inputN, inputK;
    cin >> inputN >> inputK;

    vector<int> favor(inputN, 0);
    for (int i = 0; i<inputN; i++)
        cin >> favor[i];

    double answer = 10000000000000;
    for (int k = inputK - 1; k < inputN; k++) {
        for (int i = 0; i<inputN; i++ ){
            if (i + k < inputN) {
                start_index = i;
                end_index = i + k;

                double mean = getMean(favor);
                double variance = getVariance(favor, mean);
                double sigma = sqrt(variance);
                answer = min(answer, sigma);
            }
        }
    }
    cout << answer << endl;
    return 0;
}