#include "ConjGrad.h"
#include <iostream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;


class ConjugateGradient {
public:
    //dot product of 2 vectors
    double mul(const vector<float> &a, const vector<float> &b) {
        float result = 0;
        for (int i = 0; i < a.size(); i++)
            result += a[i] * b[i];
        return result;
    }

    //product of matrix and vector
    double mul(SparseMatrix &a, const vector<float> &b) {
        float result = 0;
        for (int i = 0; i < b.size(); i++)
            result += a.at(i, 0) * b[i];
        return result;
    }

    //sovle the result
    vector<float> calculate(SparseMatrix A, vector<float> B) {
        double delta = 0.0000001;
        double diff = 1;
        vector<float> r(B);
        vector<float> p(r);
        vector<float> x(B.size(), 0);
        while (true) {
            vector<float> r1(r);

            vector<float> tmp = A.dot(p);

            double a = mul(r, r) / mul(p, tmp);

            for (int i = 0; i < B.size(); i++) {
                x[i] = x[i] + a * p[i];
            }

            tmp = A.dot(x);
            for (int i = 0; i < B.size(); i++) {
                r[i] = B[i] - tmp[i];
            }
            double m = 0;
            for (int i = 0; i < B.size(); i++) {
                m += B[i] * B[i];
            }
            m = sqrt(m);
            double sum = 0;
            for (int i = 0; i < B.size(); i++) {
                sum += pow(tmp[i] - B[i], 2);

            }
            sum = sqrt(sum);
            diff = sum / m;
            if (diff < delta) {
                break;
            } else {
                m = 0;
                for (int i = 0; i < r1.size(); i++) {
                    m += r1[i] * r1[i];
                }
                sum = 0;
                for (int i = 0; i < r.size(); i++) {
                    sum += r[i] * r[i];
                }
                for (int i = 0; i < p.size(); i++) {
                    p[i] = r[i] + sum / m * p[i];
                }
            }


        }
        return x;
    }

};